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
        
        self.robot_names = self.get_parameter('robot_names').value
        
        self.tf_broadcaster = TransformBroadcaster(self)
        self.static_tf_broadcaster = StaticTransformBroadcaster(self)
        
        # Publish static world frame connections
        self.publish_static_transforms()
        
        # Timer to republish static transforms periodically (for late subscribers)
        self.static_timer = self.create_timer(1.0, self.publish_static_transforms)
        
        self.get_logger().info(f'MultiRobotTFPublisher initialized for {self.robot_names}')

    def publish_static_transforms(self):
        transforms = []
        now = self.get_clock().now().to_msg()
        
        # World -> robot1/map (identity transform)
        t1 = TransformStamped()
        t1.header.stamp = now
        t1.header.frame_id = 'world'
        t1.child_frame_id = 'robot1/map'
        t1.transform.rotation.w = 1.0
        transforms.append(t1)
        
        # World -> robot2/map (identity transform)
        t2 = TransformStamped()
        t2.header.stamp = now
        t2.header.frame_id = 'world'
        t2.child_frame_id = 'robot2/map'
        t2.transform.rotation.w = 1.0
        transforms.append(t2)
        
        # World -> map (for global map compatibility)
        t3 = TransformStamped()
        t3.header.stamp = now
        t3.header.frame_id = 'world'
        t3.child_frame_id = 'map'
        t3.transform.rotation.w = 1.0
        transforms.append(t3)
        
        self.static_tf_broadcaster.sendTransform(transforms)


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