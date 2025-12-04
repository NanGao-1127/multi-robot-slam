#!/usr/bin/env python3
"""
Frontier Explorer for Multi-Robot System
Detects frontiers and sends them to task allocator
"""

import math
import numpy as np
from typing import List, Optional, Tuple, Set
from dataclasses import dataclass
import threading

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy

from nav_msgs.msg import OccupancyGrid, Odometry
from geometry_msgs.msg import PoseStamped, Point
from std_msgs.msg import Header


@dataclass
class Frontier:
    """Represents an exploration frontier."""
    centroid_x: float
    centroid_y: float
    size: int  # Number of frontier cells
    points: List[Tuple[int, int]]  # Pixel coordinates
    
    def distance_to(self, x: float, y: float) -> float:
        return math.sqrt((self.centroid_x - x)**2 + (self.centroid_y - y)**2)


class FrontierExplorer(Node):
    def __init__(self):
        super().__init__('frontier_explorer')
        
        self.declare_parameter('robot_name', 'robot1')
        self.declare_parameter('min_frontier_size', 5)
        self.declare_parameter('frontier_detection_rate', 2.0)
        # 不再声明 use_sim_time，由 launch 文件处理
        
        self.robot_name = self.get_parameter('robot_name').value
        self.min_frontier_size = self.get_parameter('min_frontier_size').value
        self.detection_rate = self.get_parameter('frontier_detection_rate').value
        
        self.map: Optional[OccupancyGrid] = None
        self.robot_x: float = 0.0
        self.robot_y: float = 0.0
        self.frontiers: List[Frontier] = []
        self.lock = threading.Lock()
        
        map_qos = QoSProfile(
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=1)
        
        odom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            depth=10)
        
        # Use robot's local map or global map
        self.map_sub = self.create_subscription(
            OccupancyGrid, f'/{self.robot_name}/map', self.map_callback, map_qos)
        
        self.odom_sub = self.create_subscription(
            Odometry, f'/{self.robot_name}/odom', self.odom_callback, odom_qos)
        
        # Publish detected frontiers
        self.frontier_pub = self.create_publisher(
            PoseStamped, f'/{self.robot_name}/frontiers', 10)
        
        self.detection_timer = self.create_timer(
            1.0 / self.detection_rate, self.detect_frontiers)
        
        self.get_logger().info(f'FrontierExplorer initialized for {self.robot_name}')

    def map_callback(self, msg: OccupancyGrid):
        with self.lock:
            self.map = msg

    def odom_callback(self, msg: Odometry):
        self.robot_x = msg.pose.pose.position.x
        self.robot_y = msg.pose.pose.position.y

    def detect_frontiers(self):
        with self.lock:
            if self.map is None:
                return
            
            info = self.map.info
            h, w = info.height, info.width
            res = info.resolution
            origin_x = info.origin.position.x
            origin_y = info.origin.position.y
            
            grid = np.array(self.map.data, dtype=np.int8).reshape((h, w))
            
            # Find frontier cells (free cells adjacent to unknown)
            FREE_THRESH = 50
            UNKNOWN = -1
            
            free_mask = (grid >= 0) & (grid < FREE_THRESH)
            unknown_mask = grid == UNKNOWN
            
            # Check adjacency to unknown
            adj_unknown = (
                np.roll(unknown_mask, 1, axis=0) |
                np.roll(unknown_mask, -1, axis=0) |
                np.roll(unknown_mask, 1, axis=1) |
                np.roll(unknown_mask, -1, axis=1))
            
            frontier_mask = free_mask & adj_unknown
            
            # Cluster frontier cells
            frontier_cells = list(zip(*np.where(frontier_mask)))
            if not frontier_cells:
                self.frontiers = []
                return
            
            # Simple clustering: group nearby cells
            clusters = self._cluster_frontiers(frontier_cells, cluster_dist=3)
            
            # Convert to Frontier objects
            self.frontiers = []
            for cluster in clusters:
                if len(cluster) < self.min_frontier_size:
                    continue
                
                # Compute centroid
                cy = sum(p[0] for p in cluster) / len(cluster)
                cx = sum(p[1] for p in cluster) / len(cluster)
                
                world_x = origin_x + (cx + 0.5) * res
                world_y = origin_y + (cy + 0.5) * res
                
                frontier = Frontier(
                    centroid_x=world_x,
                    centroid_y=world_y,
                    size=len(cluster),
                    points=[(p[1], p[0]) for p in cluster])
                
                self.frontiers.append(frontier)
            
            # Sort by size (larger frontiers first)
            self.frontiers.sort(key=lambda f: f.size, reverse=True)
            
            # Publish best frontier
            if self.frontiers:
                self._publish_best_frontier()
                self.get_logger().info(f'Found {len(self.frontiers)} frontiers')

    def _cluster_frontiers(self, cells: List[Tuple[int, int]], 
                          cluster_dist: int) -> List[List[Tuple[int, int]]]:
        """Cluster frontier cells using simple connected components."""
        if not cells:
            return []
        
        cells_set = set(cells)
        visited = set()
        clusters = []
        
        for cell in cells:
            if cell in visited:
                continue
            
            cluster = []
            stack = [cell]
            
            while stack:
                c = stack.pop()
                if c in visited:
                    continue
                visited.add(c)
                cluster.append(c)
                
                # Check neighbors
                for dy in range(-cluster_dist, cluster_dist + 1):
                    for dx in range(-cluster_dist, cluster_dist + 1):
                        neighbor = (c[0] + dy, c[1] + dx)
                        if neighbor in cells_set and neighbor not in visited:
                            stack.append(neighbor)
            
            if cluster:
                clusters.append(cluster)
        
        return clusters

    def _publish_best_frontier(self):
        """Publish the best frontier to explore."""
        if not self.frontiers:
            return
        
        # Score frontiers: prefer large, nearby frontiers
        best_score = float('-inf')
        best_frontier = None
        
        for f in self.frontiers:
            dist = f.distance_to(self.robot_x, self.robot_y)
            if dist < 0.5:  # Too close
                continue
            
            # Score = size / distance
            score = f.size / (dist + 1)
            if score > best_score:
                best_score = score
                best_frontier = f
        
        if best_frontier:
            msg = PoseStamped()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = f'{self.robot_name}/map'
            msg.pose.position.x = best_frontier.centroid_x
            msg.pose.position.y = best_frontier.centroid_y
            msg.pose.orientation.w = 1.0
            self.frontier_pub.publish(msg)

    def get_frontiers(self) -> List[Frontier]:
        with self.lock:
            return self.frontiers.copy()


def main(args=None):
    rclpy.init(args=args)
    node = FrontierExplorer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()