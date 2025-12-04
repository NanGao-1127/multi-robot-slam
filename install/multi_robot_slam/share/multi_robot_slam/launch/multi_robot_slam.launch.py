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
    # 关键：使用 /map:=map 将绝对路径 /map 重映射到相对路径 map
    # 这样在 namespace robot1 下就会变成 /robot1/map
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
            'scan_topic': 'scan',
            'mode': 'mapping',
            'resolution': 0.05,
            'max_laser_range': 10.0,
            'minimum_travel_distance': 0.1,
            'minimum_travel_heading': 0.1,
            'map_update_interval': 1.0,
            'transform_timeout': 0.5,
            'tf_buffer_duration': 30.0,
            'stack_size_to_use': 40000000,
            'enable_interactive_mode': False,
        }],
        remappings=[
            ('/map', 'map'),  # 关键！将绝对路径/map重映射到相对路径map -> /robot1/map
            ('/map_metadata', 'map_metadata'),
            ('/slam_toolbox/scan_visualization', 'slam_toolbox/scan_visualization'),
            ('/slam_toolbox/graph_visualization', 'slam_toolbox/graph_visualization'),
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
            'scan_topic': 'scan',
            'mode': 'mapping',
            'resolution': 0.05,
            'max_laser_range': 10.0,
            'minimum_travel_distance': 0.1,
            'minimum_travel_heading': 0.1,
            'map_update_interval': 1.0,
            'transform_timeout': 0.5,
            'tf_buffer_duration': 30.0,
            'stack_size_to_use': 40000000,
            'enable_interactive_mode': False,
        }],
        remappings=[
            ('/map', 'map'),  # 关键！-> /robot2/map
            ('/map_metadata', 'map_metadata'),
            ('/slam_toolbox/scan_visualization', 'slam_toolbox/scan_visualization'),
            ('/slam_toolbox/graph_visualization', 'slam_toolbox/graph_visualization'),
        ],
        output='screen'
    )
    
    # Pose graph optimizer
    pose_graph = TimerAction(
        period=5.0,
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
        period=5.0,
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
        period=5.0,
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
        period=5.0,
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