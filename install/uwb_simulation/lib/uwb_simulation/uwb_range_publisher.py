#!/usr/bin/env python3
"""
UWB Range Publisher Node

This node aggregates UWB range measurements and robot poses,
publishing them in a format suitable for pose graph optimization.
"""

import math
from typing import Dict, List, Optional, Tuple
from dataclasses import dataclass
from collections import deque

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
from std_msgs.msg import Header
from uwb_simulation.msg import UwbRange, UwbRangeArray


@dataclass
class RobotPose:
    """Robot pose with timestamp."""
    x: float
    y: float
    z: float
    yaw: float
    timestamp: float


@dataclass
class RangeEdge:
    """Range edge for pose graph optimization."""
    source_robot: str
    target_robot: str
    source_pose: RobotPose
    target_pose: RobotPose
    range_measurement: float
    range_std: float
    timestamp: float


class UwbRangePublisher(Node):
    """
    Publishes UWB range measurements with associated pose information
    for use in pose graph optimization.
    """
    
    def __init__(self):
        super().__init__('uwb_range_publisher')
        
        # Parameters
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('pose_buffer_size', 100)
        self.declare_parameter('max_time_diff', 0.1)  # Max time difference for pose matching
        
        self.robot_names = self.get_parameter('robot_names').get_parameter_value().string_array_value
        self.pose_buffer_size = self.get_parameter('pose_buffer_size').get_parameter_value().integer_value
        self.max_time_diff = self.get_parameter('max_time_diff').get_parameter_value().double_value
        
        # Pose buffers for each robot
        self.pose_buffers: Dict[str, deque] = {
            name: deque(maxlen=self.pose_buffer_size) for name in self.robot_names
        }
        
        # Range edge buffer
        self.range_edges: List[RangeEdge] = []
        
        # QoS profiles
        odom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            depth=10
        )
        
        # Subscribe to robot odometry
        self.odom_subs = {}
        for robot_name in self.robot_names:
            topic = f'/{robot_name}/odom'
            self.odom_subs[robot_name] = self.create_subscription(
                Odometry,
                topic,
                lambda msg, name=robot_name: self.odom_callback(msg, name),
                odom_qos
            )
        
        # Subscribe to UWB ranges
        self.range_sub = self.create_subscription(
            UwbRangeArray,
            '/uwb/ranges',
            self.range_callback,
            10
        )
        
        # Publisher for range edges (for SLAM node)
        self.edge_pub = self.create_publisher(
            UwbRangeArray,
            '/uwb/range_edges',
            10
        )
        
        self.get_logger().info('UWB Range Publisher initialized')
    
    def odom_callback(self, msg: Odometry, robot_name: str):
        """Store robot pose from odometry."""
        # Extract position
        pos = msg.pose.pose.position
        
        # Extract yaw from quaternion
        q = msg.pose.pose.orientation
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        yaw = math.atan2(siny_cosp, cosy_cosp)
        
        # Get timestamp
        timestamp = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        
        # Store pose
        pose = RobotPose(
            x=pos.x,
            y=pos.y,
            z=pos.z,
            yaw=yaw,
            timestamp=timestamp
        )
        self.pose_buffers[robot_name].append(pose)
    
    def find_closest_pose(self, robot_name: str, timestamp: float) -> Optional[RobotPose]:
        """Find the pose closest to the given timestamp."""
        if robot_name not in self.pose_buffers:
            return None
        
        buffer = self.pose_buffers[robot_name]
        if not buffer:
            return None
        
        closest_pose = None
        min_diff = float('inf')
        
        for pose in buffer:
            diff = abs(pose.timestamp - timestamp)
            if diff < min_diff:
                min_diff = diff
                closest_pose = pose
        
        if min_diff > self.max_time_diff:
            return None
        
        return closest_pose
    
    def range_callback(self, msg: UwbRangeArray):
        """Process range measurements and associate with poses."""
        for range_msg in msg.ranges:
            if not range_msg.is_valid:
                continue
            
            # Get timestamp
            timestamp = range_msg.measurement_time.sec + range_msg.measurement_time.nanosec * 1e-9
            
            # Find poses for both robots at measurement time
            source_pose = self.find_closest_pose(range_msg.source_robot_id, timestamp)
            target_pose = self.find_closest_pose(range_msg.target_robot_id, timestamp)
            
            if source_pose is None or target_pose is None:
                continue
            
            # Create range edge
            edge = RangeEdge(
                source_robot=range_msg.source_robot_id,
                target_robot=range_msg.target_robot_id,
                source_pose=source_pose,
                target_pose=target_pose,
                range_measurement=range_msg.range,
                range_std=range_msg.range_std,
                timestamp=timestamp
            )
            self.range_edges.append(edge)
            
            # Keep only recent edges (last 1000)
            if len(self.range_edges) > 1000:
                self.range_edges = self.range_edges[-1000:]
    
    def get_range_edges(self) -> List[RangeEdge]:
        """Get all stored range edges."""
        return self.range_edges.copy()


def main(args=None):
    rclpy.init(args=args)
    node = UwbRangePublisher()
    
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
