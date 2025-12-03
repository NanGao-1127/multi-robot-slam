#!/usr/bin/env python3
"""
TF Publisher for Multi-Robot SLAM
Publishes transforms between robot frames and world frame
"""

import math
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster, StaticTransformBroadcaster


class MultiRobotTFPublisher(Node):
    def __init__(self):
        super().__init__('multi_robot_tf_publisher')
        
        self.declare_parameter('robot_names', ['robot1', 'robot2'])
        self.declare_parameter('use_sim_time', True)
        
        self.robot_names = self.get_parameter('robot_names').value
        
        self.tf_broadcaster = TransformBroadcaster(self)
        self.static_tf_broadcaster = StaticTransformBroadcaster(self)
        
        # Publish static world frame
        self.publish_static_transforms()
        
        odom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            depth=10)
        
        self.odom_subs = {}
        for robot_name in self.robot_names:
            self.odom_subs[robot_name] = self.create_subscription(
                Odometry, f'/{robot_name}/odom',
                lambda msg, name=robot_name: self.odom_callback(msg, name), odom_qos)
        
        self.get_logger().info(f'MultiRobotTFPublisher initialized for {self.robot_names}')

    def publish_static_transforms(self):
        transforms = []
        
        # World to map (identity for now)
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'world'
        t.child_frame_id = 'map'
        t.transform.rotation.w = 1.0
        transforms.append(t)
        
        # Initial robot odom frames (will be updated by SLAM)
        for i, robot_name in enumerate(self.robot_names):
            t = TransformStamped()
            t.header.stamp = self.get_clock().now().to_msg()
            t.header.frame_id = 'world'
            t.child_frame_id = f'{robot_name}/odom'
            t.transform.rotation.w = 1.0
            transforms.append(t)
        
        self.static_tf_broadcaster.sendTransform(transforms)

    def odom_callback(self, msg: Odometry, robot_name: str):
        # The diff_drive plugin already publishes odom->base_footprint
        # We just need to ensure world->odom is published
        pass


def main(args=None):
    rclpy.init(args=args)
    node = MultiRobotTFPublisher()
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
