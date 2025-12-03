#!/usr/bin/env python3
"""
Multi-Robot SLAM Launch File
Launches SLAM for multiple robots with UWB-based pose graph optimization
"""

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node, PushRosNamespace
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_multi_robot_slam = get_package_share_directory('multi_robot_slam')
    
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    robot_names = ['robot1', 'robot2']
    
    slam_params_file = os.path.join(pkg_multi_robot_slam, 'config', 'slam_params.yaml')
    
    nodes = []
    
    # SLAM Toolbox for each robot
    for robot_name in robot_names:
        slam_node = Node(
            package='slam_toolbox',
            executable='async_slam_toolbox_node',
            name='slam_toolbox',
            namespace=robot_name,
            parameters=[
                slam_params_file,
                {'use_sim_time': use_sim_time,
                 'odom_frame': f'{robot_name}/odom',
                 'map_frame': f'{robot_name}/map',
                 'base_frame': f'{robot_name}/base_footprint',
                 'scan_topic': f'/{robot_name}/scan'}
            ],
            remappings=[
                ('scan', f'/{robot_name}/scan'),
                ('map', f'/{robot_name}/map'),
                ('map_metadata', f'/{robot_name}/map_metadata'),
            ],
            output='screen'
        )
        nodes.append(slam_node)
    
    # Pose Graph Optimizer (UWB-based)
    pose_graph_optimizer = Node(
        package='multi_robot_slam',
        executable='pose_graph_optimizer.py',
        name='pose_graph_optimizer',
        parameters=[{
            'robot_names': robot_names,
            'optimization_rate': 1.0,
            'range_edge_weight': 50.0,
            'use_sim_time': True
        }],
        output='screen'
    )
    nodes.append(pose_graph_optimizer)
    
    # Map Merger
    map_merger = Node(
        package='multi_robot_slam',
        executable='map_merger.py',
        name='map_merger',
        parameters=[{
            'robot_names': robot_names,
            'global_frame': 'world',
            'resolution': 0.05,
            'use_sim_time': True
        }],
        output='screen'
    )
    nodes.append(map_merger)
    
    # TF Publisher
    tf_publisher = Node(
        package='multi_robot_slam',
        executable='tf_publisher.py',
        name='multi_robot_tf_publisher',
        parameters=[{
            'robot_names': robot_names,
            'use_sim_time': True
        }],
        output='screen'
    )
    nodes.append(tf_publisher)
    
    # SLAM Coordinator
    slam_coordinator = Node(
        package='multi_robot_slam',
        executable='slam_coordinator.py',
        name='slam_coordinator',
        parameters=[{
            'robot_names': robot_names,
            'use_sim_time': True
        }],
        output='screen'
    )
    nodes.append(slam_coordinator)
    
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        *nodes
    ])
