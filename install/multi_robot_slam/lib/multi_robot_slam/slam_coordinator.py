#!/usr/bin/env python3
"""
SLAM Coordinator - Coordinates multi-robot SLAM with UWB ranging
Main entry point for the multi-robot SLAM system
"""

import math
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup

from nav_msgs.msg import Odometry, OccupancyGrid
from geometry_msgs.msg import PoseStamped, Twist
from std_msgs.msg import Bool, String

try:
    from uwb_simulation.msg import UwbRangeArray
    UWB_AVAILABLE = True
except ImportError:
    UWB_AVAILABLE = False


class SLAMCoordinator(Node):
    def __init__(self):
        super().__init__('slam_coordinator')
        
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('status_rate', 1.0)
        
        self.robot_names = self.get_parameter('robot_names').value
        self.status_rate = self.get_parameter('status_rate').value
        
        self.robot_status = {name: {'active': False, 'last_odom_time': 0.0, 
                                    'nodes': 0, 'has_map': False} 
                            for name in self.robot_names}
        self.uwb_measurements_count = 0
        self.range_edges_count = 0
        
        odom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            depth=10)
        
        map_qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            depth=1)
        
        for robot_name in self.robot_names:
            self.create_subscription(
                Odometry, f'/{robot_name}/odom',
                lambda msg, name=robot_name: self.odom_callback(msg, name), odom_qos)
            self.create_subscription(
                OccupancyGrid, f'/{robot_name}/map',
                lambda msg, name=robot_name: self.map_callback(msg, name), map_qos)
        
        if UWB_AVAILABLE:
            self.create_subscription(UwbRangeArray, '/uwb/ranges', self.uwb_callback, 10)
        
        self.status_pub = self.create_publisher(String, '/slam/status', 10)
        self.status_timer = self.create_timer(1.0 / self.status_rate, self.publish_status)
        
        self.get_logger().info(f'SLAMCoordinator initialized for {self.robot_names}')

    def odom_callback(self, msg: Odometry, robot_name: str):
        self.robot_status[robot_name]['active'] = True
        self.robot_status[robot_name]['last_odom_time'] = \
            msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9

    def map_callback(self, msg: OccupancyGrid, robot_name: str):
        self.robot_status[robot_name]['has_map'] = True

    def uwb_callback(self, msg: UwbRangeArray):
        self.uwb_measurements_count += len(msg.ranges)

    def publish_status(self):
        active_robots = sum(1 for s in self.robot_status.values() if s['active'])
        robots_with_maps = sum(1 for s in self.robot_status.values() if s['has_map'])
        
        status = f"SLAM Status: {active_robots}/{len(self.robot_names)} robots active, "
        status += f"{robots_with_maps} maps, {self.uwb_measurements_count} UWB measurements"
        
        msg = String()
        msg.data = status
        self.status_pub.publish(msg)
        
        self.get_logger().info(status)


def main(args=None):
    rclpy.init(args=args)
    node = SLAMCoordinator()
    
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
