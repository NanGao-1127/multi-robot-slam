#!/usr/bin/env python3
"""
Exploration Coordinator
Main node that coordinates frontier exploration for multiple robots
Uses Nav2 for navigation
"""

import math
from typing import Dict, List, Optional, Tuple, Set
from dataclasses import dataclass
import threading

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy

from nav_msgs.msg import OccupancyGrid, Odometry
from geometry_msgs.msg import PoseStamped, Twist
from std_msgs.msg import String
from action_msgs.msg import GoalStatus

try:
    from nav2_msgs.action import NavigateToPose
    NAV2_AVAILABLE = True
except ImportError:
    NAV2_AVAILABLE = False

import numpy as np


@dataclass
class RobotExplorer:
    name: str
    x: float = 0.0
    y: float = 0.0
    yaw: float = 0.0
    current_goal: Optional[Tuple[float, float]] = None
    is_navigating: bool = False
    goals_completed: int = 0
    goals_failed: int = 0


class ExplorationCoordinator(Node):
    def __init__(self):
        super().__init__('exploration_coordinator')
        
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('exploration_rate', 1.0)
        self.declare_parameter('min_frontier_size', 8)
        self.declare_parameter('min_goal_distance', 0.8)
        self.declare_parameter('goal_timeout', 60.0)
        # 不再声明 use_sim_time
        
        self.robot_names = self.get_parameter('robot_names').value
        self.exploration_rate = self.get_parameter('exploration_rate').value
        self.min_frontier_size = self.get_parameter('min_frontier_size').value
        self.min_goal_distance = self.get_parameter('min_goal_distance').value
        self.goal_timeout = self.get_parameter('goal_timeout').value
        
        self.robots: Dict[str, RobotExplorer] = {
            name: RobotExplorer(name=name) for name in self.robot_names}
        
        self.global_map: Optional[OccupancyGrid] = None
        self.blocked_goals: Set[Tuple[int, int]] = set()
        self.lock = threading.Lock()
        
        map_qos = QoSProfile(
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST, depth=1)
        
        odom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE, depth=10)
        
        # Subscribe to global map or individual maps
        self.map_sub = self.create_subscription(
            OccupancyGrid, '/global_map', self.map_callback, map_qos)
        
        # Subscribe to robot odometry
        for robot_name in self.robot_names:
            self.create_subscription(
                Odometry, f'/{robot_name}/odom',
                lambda msg, name=robot_name: self.odom_callback(msg, name), odom_qos)
        
        # Navigation action clients
        if NAV2_AVAILABLE:
            self.nav_clients: Dict[str, ActionClient] = {}
            for robot_name in self.robot_names:
                self.nav_clients[robot_name] = ActionClient(
                    self, NavigateToPose, f'/{robot_name}/navigate_to_pose')
        
        # Velocity publishers for direct control
        self.vel_pubs = {}
        for robot_name in self.robot_names:
            self.vel_pubs[robot_name] = self.create_publisher(
                Twist, f'/{robot_name}/cmd_vel', 10)
        
        self.status_pub = self.create_publisher(String, '/exploration/status', 10)
        
        self.exploration_timer = self.create_timer(
            1.0 / self.exploration_rate, self.exploration_step)
        
        self.get_logger().info(f'ExplorationCoordinator initialized for {self.robot_names}')

    def map_callback(self, msg: OccupancyGrid):
        with self.lock:
            self.global_map = msg

    def odom_callback(self, msg: Odometry, robot_name: str):
        if robot_name not in self.robots:
            return
        
        robot = self.robots[robot_name]
        robot.x = msg.pose.pose.position.x
        robot.y = msg.pose.pose.position.y
        
        q = msg.pose.pose.orientation
        robot.yaw = math.atan2(2*(q.w*q.z + q.x*q.y), 1 - 2*(q.y*q.y + q.z*q.z))
        
        # Check if goal reached
        if robot.current_goal:
            dist = math.sqrt((robot.x - robot.current_goal[0])**2 + 
                           (robot.y - robot.current_goal[1])**2)
            if dist < 0.5:
                robot.current_goal = None
                robot.is_navigating = False
                robot.goals_completed += 1

    def exploration_step(self):
        with self.lock:
            if self.global_map is None:
                self._publish_status("Waiting for global map...")
                return
            
            # Find frontiers
            frontiers = self._detect_frontiers()
            
            if not frontiers:
                self._publish_status("Exploration complete - no frontiers found")
                return
            
            # Assign frontiers to available robots
            for robot_name, robot in self.robots.items():
                if not robot.is_navigating:
                    goal = self._select_best_goal(robot, frontiers)
                    if goal:
                        self._send_goal(robot_name, goal)
            
            self._publish_status(f"Exploring: {len(frontiers)} frontiers")

    def _detect_frontiers(self) -> List[Tuple[float, float, int]]:
        """Detect frontier clusters and return (x, y, size) tuples."""
        if self.global_map is None:
            return []
        
        info = self.global_map.info
        h, w = info.height, info.width
        grid = np.array(self.global_map.data, dtype=np.int8).reshape((h, w))
        
        FREE_THRESH = 50
        free_mask = (grid >= 0) & (grid < FREE_THRESH)
        unknown_mask = grid == -1
        
        adj_unknown = (
            np.roll(unknown_mask, 1, axis=0) |
            np.roll(unknown_mask, -1, axis=0) |
            np.roll(unknown_mask, 1, axis=1) |
            np.roll(unknown_mask, -1, axis=1))
        
        frontier_mask = free_mask & adj_unknown
        fy, fx = np.where(frontier_mask)
        
        if len(fx) == 0:
            return []
        
        # Cluster frontiers
        from collections import defaultdict
        clusters = defaultdict(list)
        grid_size = 10  # Grid cells for clustering
        
        for x, y in zip(fx, fy):
            key = (x // grid_size, y // grid_size)
            clusters[key].append((x, y))
        
        frontiers = []
        for key, points in clusters.items():
            if len(points) < self.min_frontier_size:
                continue
            
            cx = sum(p[0] for p in points) / len(points)
            cy = sum(p[1] for p in points) / len(points)
            
            world_x = info.origin.position.x + (cx + 0.5) * info.resolution
            world_y = info.origin.position.y + (cy + 0.5) * info.resolution
            
            # Skip blocked goals
            if (int(cx), int(cy)) in self.blocked_goals:
                continue
            
            frontiers.append((world_x, world_y, len(points)))
        
        return frontiers

    def _select_best_goal(self, robot: RobotExplorer, 
                         frontiers: List[Tuple[float, float, int]]) -> Optional[Tuple[float, float]]:
        """Select best frontier for robot."""
        best_score = float('-inf')
        best_goal = None
        
        for fx, fy, size in frontiers:
            dist = math.sqrt((robot.x - fx)**2 + (robot.y - fy)**2)
            
            if dist < self.min_goal_distance:
                continue
            
            # Check distance to other robots' goals
            min_other_dist = float('inf')
            for other_name, other_robot in self.robots.items():
                if other_name != robot.name and other_robot.current_goal:
                    other_dist = math.sqrt(
                        (fx - other_robot.current_goal[0])**2 +
                        (fy - other_robot.current_goal[1])**2)
                    min_other_dist = min(min_other_dist, other_dist)
            
            # Prefer goals away from other robots
            separation_bonus = min(min_other_dist * 2, 10)
            
            # Score: larger frontiers, closer, separated from others
            score = size * 0.5 - dist + separation_bonus
            
            if score > best_score:
                best_score = score
                best_goal = (fx, fy)
        
        return best_goal

    def _send_goal(self, robot_name: str, goal: Tuple[float, float]):
        """Send navigation goal to robot."""
        robot = self.robots[robot_name]
        robot.current_goal = goal
        robot.is_navigating = True
        
        if NAV2_AVAILABLE and robot_name in self.nav_clients:
            goal_msg = NavigateToPose.Goal()
            goal_msg.pose.header.frame_id = f'{robot_name}/map'
            goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
            goal_msg.pose.pose.position.x = goal[0]
            goal_msg.pose.pose.position.y = goal[1]
            goal_msg.pose.pose.orientation.w = 1.0
            
            if self.nav_clients[robot_name].wait_for_server(timeout_sec=1.0):
                future = self.nav_clients[robot_name].send_goal_async(
                    goal_msg, 
                    feedback_callback=lambda fb, name=robot_name: self._nav_feedback(fb, name))
                future.add_done_callback(
                    lambda f, name=robot_name: self._goal_response(f, name))
                self.get_logger().info(f'{robot_name} -> ({goal[0]:.2f}, {goal[1]:.2f})')
            else:
                self.get_logger().warn(f'Nav2 not available for {robot_name}')
                robot.is_navigating = False
        else:
            self.get_logger().warn(f'Nav2 not available')
            robot.is_navigating = False

    def _goal_response(self, future, robot_name: str):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.robots[robot_name].is_navigating = False
            self.robots[robot_name].goals_failed += 1

    def _nav_feedback(self, feedback, robot_name: str):
        pass  # Could track navigation progress

    def _publish_status(self, msg: str):
        status = String()
        status.data = msg
        self.status_pub.publish(status)


def main(args=None):
    rclpy.init(args=args)
    node = ExplorationCoordinator()
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