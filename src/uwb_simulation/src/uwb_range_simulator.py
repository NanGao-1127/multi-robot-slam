#!/usr/bin/env python3
"""
UWB Range Simulator Node

Simulates Ultra-Wideband ranging measurements between multiple robots.
Based on the error model described in the paper:
- Standard deviation of ~0.02m
- Occasional spurious measurements (truncation to integer below true range)

This node subscribes to odometry from all robots and publishes simulated
range measurements between them.
"""

import math
import random
from typing import Dict, Optional, Tuple

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

from nav_msgs.msg import Odometry
from geometry_msgs.msg import Point
from std_msgs.msg import Header
from uwb_simulation.msg import UwbRange, UwbRangeArray


class UwbRangeSimulator(Node):
    """
    Simulates UWB ranging between multiple robots.
    
    Error model based on Decawave DWM1001:
    - Gaussian noise with sigma = 0.02m
    - Occasional spurious measurements (integer truncation)
    - Maximum range limit
    """
    
    def __init__(self):
        super().__init__('uwb_range_simulator')
        
        # Parameters
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('range_std', 0.02)  # Standard deviation in meters
        self.declare_parameter('max_range', 20.0)  # Maximum range in meters
        self.declare_parameter('update_rate', 10.0)  # Hz
        self.declare_parameter('spurious_prob', 0.05)  # Probability of spurious measurement
        self.declare_parameter('use_sim_time', True)
        
        self.robot_names = self.get_parameter('robot_names').get_parameter_value().string_array_value
        self.range_std = self.get_parameter('range_std').get_parameter_value().double_value
        self.max_range = self.get_parameter('max_range').get_parameter_value().double_value
        self.update_rate = self.get_parameter('update_rate').get_parameter_value().double_value
        self.spurious_prob = self.get_parameter('spurious_prob').get_parameter_value().double_value
        
        self.get_logger().info(f'Initializing UWB simulator for robots: {self.robot_names}')
        self.get_logger().info(f'Range std: {self.range_std}m, Max range: {self.max_range}m')
        
        # Store robot positions
        self.robot_positions: Dict[str, Optional[Point]] = {name: None for name in self.robot_names}
        self.robot_orientations: Dict[str, float] = {name: 0.0 for name in self.robot_names}
        
        # QoS for odometry
        odom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            depth=10
        )
        
        # Subscribe to each robot's odometry
        self.odom_subs = {}
        for robot_name in self.robot_names:
            topic = f'/{robot_name}/odom'
            self.odom_subs[robot_name] = self.create_subscription(
                Odometry,
                topic,
                lambda msg, name=robot_name: self.odom_callback(msg, name),
                odom_qos
            )
            self.get_logger().info(f'Subscribed to {topic}')
        
        # Publisher for range measurements
        self.range_pub = self.create_publisher(UwbRangeArray, '/uwb/ranges', 10)
        
        # Individual range publishers for each robot pair
        self.pair_pubs = {}
        for i, robot1 in enumerate(self.robot_names):
            for robot2 in self.robot_names[i+1:]:
                topic = f'/uwb/range_{robot1}_{robot2}'
                self.pair_pubs[(robot1, robot2)] = self.create_publisher(UwbRange, topic, 10)
        
        # Timer for publishing range measurements
        self.timer = self.create_timer(1.0 / self.update_rate, self.publish_ranges)
        
        self.get_logger().info('UWB Range Simulator initialized')
    
    def odom_callback(self, msg: Odometry, robot_name: str):
        """Store robot position from odometry."""
        self.robot_positions[robot_name] = msg.pose.pose.position
        
        # Extract yaw from quaternion
        q = msg.pose.pose.orientation
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        self.robot_orientations[robot_name] = math.atan2(siny_cosp, cosy_cosp)
    
    def compute_range(self, pos1: Point, pos2: Point) -> Tuple[float, bool]:
        """
        Compute the range between two positions with simulated noise.
        
        Returns:
            Tuple of (measured_range, is_valid)
        """
        # True range
        dx = pos2.x - pos1.x
        dy = pos2.y - pos1.y
        dz = pos2.z - pos1.z
        true_range = math.sqrt(dx*dx + dy*dy + dz*dz)
        
        # Check if within max range
        if true_range > self.max_range:
            return 0.0, False
        
        # Add Gaussian noise
        measured_range = true_range + random.gauss(0, self.range_std)
        
        # Simulate spurious measurements (integer truncation)
        # As described in the paper, occasionally the decimal part is truncated
        if random.random() < self.spurious_prob:
            measured_range = math.floor(measured_range)
        
        # Ensure non-negative
        measured_range = max(0.0, measured_range)
        
        return measured_range, True
    
    def publish_ranges(self):
        """Publish range measurements between all robot pairs."""
        now = self.get_clock().now()
        
        range_array = UwbRangeArray()
        range_array.header.stamp = now.to_msg()
        range_array.header.frame_id = 'world'
        
        for i, robot1 in enumerate(self.robot_names):
            pos1 = self.robot_positions.get(robot1)
            if pos1 is None:
                continue
                
            for robot2 in self.robot_names[i+1:]:
                pos2 = self.robot_positions.get(robot2)
                if pos2 is None:
                    continue
                
                # Compute range measurement
                measured_range, is_valid = self.compute_range(pos1, pos2)
                
                # Create range message
                range_msg = UwbRange()
                range_msg.header.stamp = now.to_msg()
                range_msg.header.frame_id = 'world'
                range_msg.source_robot_id = robot1
                range_msg.target_robot_id = robot2
                range_msg.range = measured_range
                range_msg.range_std = self.range_std
                range_msg.measurement_time = now.to_msg()
                range_msg.quality = 90 if is_valid else 0
                range_msg.is_valid = is_valid
                
                if is_valid:
                    range_array.ranges.append(range_msg)
                    
                    # Publish individual pair measurement
                    if (robot1, robot2) in self.pair_pubs:
                        self.pair_pubs[(robot1, robot2)].publish(range_msg)
                    
                    # Also publish reverse direction (measurements are bidirectional)
                    range_msg_reverse = UwbRange()
                    range_msg_reverse.header = range_msg.header
                    range_msg_reverse.source_robot_id = robot2
                    range_msg_reverse.target_robot_id = robot1
                    range_msg_reverse.range = measured_range + random.gauss(0, self.range_std * 0.5)  # Slight variation
                    range_msg_reverse.range_std = self.range_std
                    range_msg_reverse.measurement_time = now.to_msg()
                    range_msg_reverse.quality = 90
                    range_msg_reverse.is_valid = True
                    range_array.ranges.append(range_msg_reverse)
        
        # Publish combined array
        if range_array.ranges:
            self.range_pub.publish(range_array)


def main(args=None):
    rclpy.init(args=args)
    node = UwbRangeSimulator()
    
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
