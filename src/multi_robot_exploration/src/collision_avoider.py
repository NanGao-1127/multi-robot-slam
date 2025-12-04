#!/usr/bin/env python3
"""
Collision Avoider for Multi-Robot System
Monitors robot positions and modifies velocities to avoid collisions
"""

import math
from typing import Dict, Optional
import threading

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist, Point


class CollisionAvoider(Node):
    def __init__(self):
        super().__init__('collision_avoider')
        
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('safety_distance', 0.5)
        self.declare_parameter('slowdown_distance', 1.0)
        self.declare_parameter('check_rate', 20.0)
        # 不再声明 use_sim_time
        
        self.robot_names = self.get_parameter('robot_names').value
        self.safety_distance = self.get_parameter('safety_distance').value
        self.slowdown_distance = self.get_parameter('slowdown_distance').value
        self.check_rate = self.get_parameter('check_rate').value
        
        self.robot_positions: Dict[str, Point] = {}
        self.robot_velocities: Dict[str, Twist] = {}
        self.velocity_scales: Dict[str, float] = {name: 1.0 for name in self.robot_names}
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
        
        # Subscribe to commanded velocities and republish modified ones
        self.cmd_vel_subs = {}
        self.cmd_vel_pubs = {}
        for robot_name in self.robot_names:
            # Subscribe to original cmd_vel
            self.cmd_vel_subs[robot_name] = self.create_subscription(
                Twist, f'/{robot_name}/cmd_vel_nav',
                lambda msg, name=robot_name: self.cmd_vel_callback(msg, name), 10)
            
            # Publish modified cmd_vel
            self.cmd_vel_pubs[robot_name] = self.create_publisher(
                Twist, f'/{robot_name}/cmd_vel', 10)
        
        self.check_timer = self.create_timer(1.0 / self.check_rate, self.check_collisions)
        
        self.get_logger().info(f'CollisionAvoider initialized for {self.robot_names}')

    def odom_callback(self, msg: Odometry, robot_name: str):
        with self.lock:
            self.robot_positions[robot_name] = msg.pose.pose.position

    def cmd_vel_callback(self, msg: Twist, robot_name: str):
        with self.lock:
            self.robot_velocities[robot_name] = msg
            
            # Apply velocity scaling
            scale = self.velocity_scales.get(robot_name, 1.0)
            
            modified_vel = Twist()
            modified_vel.linear.x = msg.linear.x * scale
            modified_vel.linear.y = msg.linear.y * scale
            modified_vel.angular.z = msg.angular.z * scale
            
            self.cmd_vel_pubs[robot_name].publish(modified_vel)

    def check_collisions(self):
        with self.lock:
            if len(self.robot_positions) < 2:
                return
            
            # Reset scales
            for name in self.robot_names:
                self.velocity_scales[name] = 1.0
            
            # Check distances between all robot pairs
            for i, robot1 in enumerate(self.robot_names):
                if robot1 not in self.robot_positions:
                    continue
                
                pos1 = self.robot_positions[robot1]
                
                for robot2 in self.robot_names[i+1:]:
                    if robot2 not in self.robot_positions:
                        continue
                    
                    pos2 = self.robot_positions[robot2]
                    dist = math.sqrt(
                        (pos1.x - pos2.x)**2 + 
                        (pos1.y - pos2.y)**2)
                    
                    # Apply slowdown for both robots
                    if dist < self.safety_distance:
                        self.velocity_scales[robot1] = 0.0
                        self.velocity_scales[robot2] = 0.0
                        self.get_logger().warn(
                            f'STOP: {robot1} and {robot2} too close ({dist:.2f}m)')
                    elif dist < self.slowdown_distance:
                        scale = (dist - self.safety_distance) / \
                                (self.slowdown_distance - self.safety_distance)
                        scale = max(0.1, min(1.0, scale))
                        self.velocity_scales[robot1] = min(
                            self.velocity_scales.get(robot1, 1.0), scale)
                        self.velocity_scales[robot2] = min(
                            self.velocity_scales.get(robot2, 1.0), scale)


def main(args=None):
    rclpy.init(args=args)
    node = CollisionAvoider()
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