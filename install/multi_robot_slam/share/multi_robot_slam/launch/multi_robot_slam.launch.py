#!/usr/bin/env python3
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    
    # SLAM Toolbox for robot1
    slam_robot1 = Node(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        namespace='robot1',
        parameters=[{
            'use_sim_time': True,
            'odom_frame': 'robot1/odom',
            'base_frame': 'robot1/base_footprint',
            'map_frame': 'robot1/map',
            'scan_topic': '/robot1/scan',
            'mode': 'mapping',
            'resolution': 0.05,
            'max_laser_range': 10.0,
            'minimum_travel_distance': 0.2,
            'minimum_travel_heading': 0.15,
            'map_update_interval': 2.0,
            'transform_timeout': 0.5,
            'tf_buffer_duration': 30.0,
        }],
        remappings=[
            ('scan', '/robot1/scan'),
        ],
        output='screen'
    )
    
    # SLAM Toolbox for robot2
    slam_robot2 = Node(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        namespace='robot2',
        parameters=[{
            'use_sim_time': True,
            'odom_frame': 'robot2/odom',
            'base_frame': 'robot2/base_footprint',
            'map_frame': 'robot2/map',
            'scan_topic': '/robot2/scan',
            'mode': 'mapping',
            'resolution': 0.05,
            'max_laser_range': 10.0,
            'minimum_travel_distance': 0.2,
            'minimum_travel_heading': 0.15,
            'map_update_interval': 2.0,
            'transform_timeout': 0.5,
            'tf_buffer_duration': 30.0,
        }],
        remappings=[
            ('scan', '/robot2/scan'),
        ],
        output='screen'
    )
    
    # Pose graph optimizer
    pose_graph = TimerAction(
        period=3.0,
        actions=[
            Node(
                package='multi_robot_slam',
                executable='pose_graph_optimizer.py',
                name='pose_graph_optimizer',
                parameters=[{'use_sim_time': True}],
                output='screen'
            )
        ]
    )
    
    # Map merger
    map_merger = TimerAction(
        period=3.0,
        actions=[
            Node(
                package='multi_robot_slam',
                executable='map_merger.py',
                name='map_merger',
                parameters=[{'use_sim_time': True}],
                output='screen'
            )
        ]
    )
    
    # TF publisher
    tf_pub = TimerAction(
        period=3.0,
        actions=[
            Node(
                package='multi_robot_slam',
                executable='tf_publisher.py',
                name='multi_robot_tf_publisher',
                parameters=[{'use_sim_time': True}],
                output='screen'
            )
        ]
    )
    
    # SLAM coordinator
    coordinator = TimerAction(
        period=3.0,
        actions=[
            Node(
                package='multi_robot_slam',
                executable='slam_coordinator.py',
                name='slam_coordinator',
                parameters=[{'use_sim_time': True}],
                output='screen'
            )
        ]
    )
    
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        slam_robot1,
        slam_robot2,
        pose_graph,
        map_merger,
        tf_pub,
        coordinator,
    ])