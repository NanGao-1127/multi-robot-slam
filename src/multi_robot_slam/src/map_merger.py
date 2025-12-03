#!/usr/bin/env python3
"""
Map Merger Node - Merges maps from multiple robots into a global map
Uses UWB-optimized poses for alignment
"""

import math
import numpy as np
from typing import Dict, List, Optional, Tuple
import threading

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

from nav_msgs.msg import OccupancyGrid, MapMetaData
from geometry_msgs.msg import Pose, TransformStamped
from std_msgs.msg import Header


class MapMerger(Node):
    def __init__(self):
        super().__init__('map_merger')
        
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('global_frame', 'world')
        self.declare_parameter('resolution', 0.05)
        self.declare_parameter('merge_rate', 0.5)
        self.declare_parameter('use_sim_time', True)
        
        self.robot_names = self.get_parameter('robot_names').value
        self.global_frame = self.get_parameter('global_frame').value
        self.resolution = self.get_parameter('resolution').value
        self.merge_rate = self.get_parameter('merge_rate').value
        
        self.robot_maps: Dict[str, OccupancyGrid] = {}
        self.robot_transforms: Dict[str, np.ndarray] = {name: np.eye(3) for name in self.robot_names}
        self.lock = threading.Lock()
        
        map_qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            depth=1)
        
        self.map_subs = {}
        for robot_name in self.robot_names:
            self.map_subs[robot_name] = self.create_subscription(
                OccupancyGrid, f'/{robot_name}/map',
                lambda msg, name=robot_name: self.map_callback(msg, name), map_qos)
        
        self.global_map_pub = self.create_publisher(OccupancyGrid, '/global_map', map_qos)
        self.merge_timer = self.create_timer(1.0 / self.merge_rate, self.merge_maps)
        
        self.get_logger().info(f'MapMerger initialized for {self.robot_names}')

    def map_callback(self, msg: OccupancyGrid, robot_name: str):
        with self.lock:
            self.robot_maps[robot_name] = msg

    def set_robot_transform(self, robot_name: str, x: float, y: float, yaw: float):
        with self.lock:
            c, s = math.cos(yaw), math.sin(yaw)
            self.robot_transforms[robot_name] = np.array([
                [c, -s, x], [s, c, y], [0, 0, 1]])

    def merge_maps(self):
        with self.lock:
            if len(self.robot_maps) < 1:
                return
            
            all_maps = list(self.robot_maps.values())
            if not all_maps:
                return
            
            # Compute global map bounds
            min_x, min_y = float('inf'), float('inf')
            max_x, max_y = float('-inf'), float('-inf')
            
            for robot_name, grid in self.robot_maps.items():
                info = grid.info
                T = self.robot_transforms.get(robot_name, np.eye(3))
                
                corners = [
                    [info.origin.position.x, info.origin.position.y],
                    [info.origin.position.x + info.width * info.resolution, info.origin.position.y],
                    [info.origin.position.x, info.origin.position.y + info.height * info.resolution],
                    [info.origin.position.x + info.width * info.resolution, 
                     info.origin.position.y + info.height * info.resolution]]
                
                for cx, cy in corners:
                    pt = T @ np.array([cx, cy, 1])
                    min_x, min_y = min(min_x, pt[0]), min(min_y, pt[1])
                    max_x, max_y = max(max_x, pt[0]), max(max_y, pt[1])
            
            if min_x == float('inf'):
                return
            
            # Add margin
            margin = 1.0
            min_x, min_y = min_x - margin, min_y - margin
            max_x, max_y = max_x + margin, max_y + margin
            
            # Create global map
            width = int(math.ceil((max_x - min_x) / self.resolution))
            height = int(math.ceil((max_y - min_y) / self.resolution))
            width = max(10, min(width, 2000))
            height = max(10, min(height, 2000))
            
            global_data = np.full((height, width), -1, dtype=np.int8)
            count_map = np.zeros((height, width), dtype=np.int32)
            sum_map = np.zeros((height, width), dtype=np.float32)
            
            for robot_name, grid in self.robot_maps.items():
                T = self.robot_transforms.get(robot_name, np.eye(3))
                T_inv = np.linalg.inv(T)
                info = grid.info
                data = np.array(grid.data, dtype=np.int8).reshape((info.height, info.width))
                
                for gy in range(height):
                    for gx in range(width):
                        world_x = min_x + (gx + 0.5) * self.resolution
                        world_y = min_y + (gy + 0.5) * self.resolution
                        
                        local = T_inv @ np.array([world_x, world_y, 1])
                        lx = int((local[0] - info.origin.position.x) / info.resolution)
                        ly = int((local[1] - info.origin.position.y) / info.resolution)
                        
                        if 0 <= lx < info.width and 0 <= ly < info.height:
                            val = data[ly, lx]
                            if val >= 0:
                                sum_map[gy, gx] += val
                                count_map[gy, gx] += 1
            
            # Average overlapping cells
            mask = count_map > 0
            global_data[mask] = (sum_map[mask] / count_map[mask]).astype(np.int8)
            
            # Publish global map
            global_map = OccupancyGrid()
            global_map.header.stamp = self.get_clock().now().to_msg()
            global_map.header.frame_id = self.global_frame
            global_map.info.resolution = self.resolution
            global_map.info.width = width
            global_map.info.height = height
            global_map.info.origin.position.x = min_x
            global_map.info.origin.position.y = min_y
            global_map.info.origin.orientation.w = 1.0
            global_map.data = global_data.flatten().tolist()
            
            self.global_map_pub.publish(global_map)


def main(args=None):
    rclpy.init(args=args)
    node = MapMerger()
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
