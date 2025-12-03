#!/usr/bin/env python3
"""
Multi-Robot Exploration Launch File
Launches Nav2 and exploration nodes for multiple robots
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
    pkg_exploration = get_package_share_directory('multi_robot_exploration')
    pkg_nav2 = get_package_share_directory('nav2_bringup')
    
    nav2_params = os.path.join(pkg_exploration, 'config', 'nav2_params.yaml')
    
    robot_names = ['robot1', 'robot2']
    nodes = []
    
    # Nav2 for each robot
    for robot_name in robot_names:
        nav2_group = GroupAction([
            PushRosNamespace(robot_name),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(pkg_nav2, 'launch', 'navigation_launch.py')),
                launch_arguments={
                    'namespace': robot_name,
                    'use_sim_time': 'true',
                    'params_file': nav2_params,
                    'use_composition': 'False',
                    'use_respawn': 'False',
                }.items()
            )
        ])
        nodes.append(nav2_group)
        
        # Frontier explorer for each robot
        frontier_node = Node(
            package='multi_robot_exploration',
            executable='frontier_explorer.py',
            name='frontier_explorer',
            namespace=robot_name,
            parameters=[{
                'robot_name': robot_name,
                'min_frontier_size': 5,
                'use_sim_time': True
            }],
            output='screen'
        )
        nodes.append(frontier_node)
    
    # Task allocator (centralized)
    task_allocator = Node(
        package='multi_robot_exploration',
        executable='task_allocator.py',
        name='task_allocator',
        parameters=[{
            'robot_names': robot_names,
            'min_inter_robot_dist': 1.5,
            'use_sim_time': True
        }],
        output='screen'
    )
    nodes.append(task_allocator)
    
    # Collision avoider
    collision_avoider = Node(
        package='multi_robot_exploration',
        executable='collision_avoider.py',
        name='collision_avoider',
        parameters=[{
            'robot_names': robot_names,
            'safety_distance': 0.5,
            'slowdown_distance': 1.0,
            'use_sim_time': True
        }],
        output='screen'
    )
    nodes.append(collision_avoider)
    
    # Exploration coordinator
    exploration_coordinator = Node(
        package='multi_robot_exploration',
        executable='exploration_coordinator.py',
        name='exploration_coordinator',
        parameters=[{
            'robot_names': robot_names,
            'use_sim_time': True
        }],
        output='screen'
    )
    nodes.append(exploration_coordinator)
    
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        *nodes
    ])
