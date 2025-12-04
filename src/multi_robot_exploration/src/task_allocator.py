#!/usr/bin/env python3
"""
Task Allocator for Multi-Robot Exploration
Assigns frontiers to robots to minimize overlap and maximize coverage
Uses Hungarian algorithm for optimal assignment
"""

import math
import numpy as np
from typing import Dict, List, Optional, Tuple
from dataclasses import dataclass
import threading

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

from nav_msgs.msg import Odometry, OccupancyGrid
from geometry_msgs.msg import PoseStamped, Point
from std_msgs.msg import String

try:
    from scipy.optimize import linear_sum_assignment
    SCIPY_AVAILABLE = True
except ImportError:
    SCIPY_AVAILABLE = False


@dataclass
class RobotState:
    x: float
    y: float
    yaw: float
    assigned_goal: Optional[Tuple[float, float]] = None
    is_busy: bool = False


@dataclass
class FrontierGoal:
    x: float
    y: float
    size: int
    assigned_robot: Optional[str] = None


class TaskAllocator(Node):
    def __init__(self):
        super().__init__('task_allocator')
        
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('allocation_rate', 0.5)
        self.declare_parameter('min_inter_robot_dist', 1.5)
        self.declare_parameter('goal_reached_threshold', 0.5)
        # 不再声明 use_sim_time
        
        self.robot_names = self.get_parameter('robot_names').value
        self.allocation_rate = self.get_parameter('allocation_rate').value
        self.min_inter_robot_dist = self.get_parameter('min_inter_robot_dist').value
        self.goal_threshold = self.get_parameter('goal_reached_threshold').value
        
        self.robot_states: Dict[str, RobotState] = {
            name: RobotState(0.0, 0.0, 0.0) for name in self.robot_names}
        
        self.frontier_goals: Dict[str, FrontierGoal] = {}
        self.assigned_goals: Dict[str, Optional[FrontierGoal]] = {
            name: None for name in self.robot_names}
        
        self.lock = threading.Lock()
        
        odom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            depth=10)
        
        # Subscribe to robot odometry
        for robot_name in self.robot_names:
            self.create_subscription(
                Odometry, f'/{robot_name}/odom',
                lambda msg, name=robot_name: self.odom_callback(msg, name), odom_qos)
            
            self.create_subscription(
                PoseStamped, f'/{robot_name}/frontiers',
                lambda msg, name=robot_name: self.frontier_callback(msg, name), 10)
        
        # Publishers for goal commands
        self.goal_pubs = {}
        for robot_name in self.robot_names:
            self.goal_pubs[robot_name] = self.create_publisher(
                PoseStamped, f'/{robot_name}/goal_pose', 10)
        
        self.status_pub = self.create_publisher(String, '/exploration/status', 10)
        
        self.allocation_timer = self.create_timer(
            1.0 / self.allocation_rate, self.allocate_tasks)
        
        self.get_logger().info(f'TaskAllocator initialized for {self.robot_names}')

    def odom_callback(self, msg: Odometry, robot_name: str):
        with self.lock:
            pos = msg.pose.pose.position
            q = msg.pose.pose.orientation
            yaw = math.atan2(2*(q.w*q.z + q.x*q.y), 1 - 2*(q.y*q.y + q.z*q.z))
            
            self.robot_states[robot_name].x = pos.x
            self.robot_states[robot_name].y = pos.y
            self.robot_states[robot_name].yaw = yaw
            
            # Check if goal reached
            goal = self.assigned_goals.get(robot_name)
            if goal:
                dist = math.sqrt((pos.x - goal.x)**2 + (pos.y - goal.y)**2)
                if dist < self.goal_threshold:
                    self.assigned_goals[robot_name] = None
                    self.robot_states[robot_name].is_busy = False

    def frontier_callback(self, msg: PoseStamped, robot_name: str):
        with self.lock:
            key = f"{robot_name}_{msg.pose.position.x:.1f}_{msg.pose.position.y:.1f}"
            self.frontier_goals[key] = FrontierGoal(
                x=msg.pose.position.x,
                y=msg.pose.position.y,
                size=10)  # Default size

    def allocate_tasks(self):
        with self.lock:
            # Get available robots (not busy)
            available_robots = [
                name for name, state in self.robot_states.items()
                if not state.is_busy and self.assigned_goals.get(name) is None]
            
            if not available_robots:
                return
            
            # Get unassigned frontiers
            unassigned_frontiers = [
                f for f in self.frontier_goals.values()
                if f.assigned_robot is None]
            
            if not unassigned_frontiers:
                # Clear old frontiers and wait for new ones
                self.frontier_goals.clear()
                return
            
            # Build cost matrix
            n_robots = len(available_robots)
            n_frontiers = len(unassigned_frontiers)
            
            if n_robots == 0 or n_frontiers == 0:
                return
            
            cost_matrix = np.zeros((n_robots, n_frontiers))
            
            for i, robot_name in enumerate(available_robots):
                state = self.robot_states[robot_name]
                for j, frontier in enumerate(unassigned_frontiers):
                    # Distance cost
                    dist = math.sqrt((state.x - frontier.x)**2 + 
                                    (state.y - frontier.y)**2)
                    
                    # Penalty for going too close to other robots' goals
                    other_robot_penalty = 0
                    for other_name, other_goal in self.assigned_goals.items():
                        if other_name != robot_name and other_goal:
                            goal_dist = math.sqrt(
                                (frontier.x - other_goal.x)**2 +
                                (frontier.y - other_goal.y)**2)
                            if goal_dist < self.min_inter_robot_dist:
                                other_robot_penalty += 100
                    
                    cost_matrix[i, j] = dist + other_robot_penalty
            
            # Solve assignment problem
            if SCIPY_AVAILABLE and n_robots > 0 and n_frontiers > 0:
                try:
                    row_ind, col_ind = linear_sum_assignment(cost_matrix)
                    
                    for i, j in zip(row_ind, col_ind):
                        if cost_matrix[i, j] < 1000:  # Valid assignment
                            robot_name = available_robots[i]
                            frontier = unassigned_frontiers[j]
                            
                            self._assign_goal(robot_name, frontier)
                except Exception as e:
                    self.get_logger().warn(f'Assignment failed: {e}')
            else:
                # Greedy assignment
                for robot_name in available_robots:
                    if not unassigned_frontiers:
                        break
                    
                    state = self.robot_states[robot_name]
                    best_frontier = min(unassigned_frontiers,
                        key=lambda f: math.sqrt((state.x-f.x)**2 + (state.y-f.y)**2))
                    
                    self._assign_goal(robot_name, best_frontier)
                    unassigned_frontiers.remove(best_frontier)
            
            self._publish_status()

    def _assign_goal(self, robot_name: str, frontier: FrontierGoal):
        frontier.assigned_robot = robot_name
        self.assigned_goals[robot_name] = frontier
        self.robot_states[robot_name].is_busy = True
        
        # Publish goal
        goal_msg = PoseStamped()
        goal_msg.header.stamp = self.get_clock().now().to_msg()
        goal_msg.header.frame_id = f'{robot_name}/map'
        goal_msg.pose.position.x = frontier.x
        goal_msg.pose.position.y = frontier.y
        goal_msg.pose.orientation.w = 1.0
        
        self.goal_pubs[robot_name].publish(goal_msg)
        self.get_logger().info(
            f'Assigned {robot_name} to ({frontier.x:.2f}, {frontier.y:.2f})')

    def _publish_status(self):
        status = "Task Allocation: "
        for name in self.robot_names:
            goal = self.assigned_goals.get(name)
            if goal:
                status += f"{name}->({goal.x:.1f},{goal.y:.1f}) "
            else:
                status += f"{name}->idle "
        
        msg = String()
        msg.data = status
        self.status_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = TaskAllocator()
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