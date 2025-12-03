#!/usr/bin/env python3
"""
Multi-Robot SLAM Bringup Launch File
Launches everything needed for multi-robot exploration with UWB SLAM
"""

import os
from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, IncludeLaunchDescription, 
                          TimerAction, GroupAction)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_robot_description = get_package_share_directory('robot_description')
    pkg_uwb_simulation = get_package_share_directory('uwb_simulation')
    pkg_multi_robot_slam = get_package_share_directory('multi_robot_slam')
    pkg_exploration = get_package_share_directory('multi_robot_exploration')
    
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    
    # 1. Launch Gazebo with robots
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_robot_description, 'launch', 'multi_robot_gazebo.launch.py')),
        launch_arguments={'use_sim_time': 'true'}.items()
    )
    
    # 2. Launch UWB simulation (delayed to ensure robots are spawned)
    uwb_launch = TimerAction(
        period=5.0,
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(pkg_uwb_simulation, 'launch', 'uwb_simulation.launch.py')),
                launch_arguments={'use_sim_time': 'true'}.items()
            )
        ]
    )
    
    # 3. Launch SLAM system (delayed)
    slam_launch = TimerAction(
        period=8.0,
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(pkg_multi_robot_slam, 'launch', 'multi_robot_slam.launch.py')),
                launch_arguments={'use_sim_time': 'true'}.items()
            )
        ]
    )
    
    # 4. Launch exploration (delayed further)
    exploration_launch = TimerAction(
        period=15.0,
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(pkg_exploration, 'launch', 'exploration.launch.py')),
                launch_arguments={'use_sim_time': 'true'}.items()
            )
        ]
    )
    
    # RViz for visualization
    rviz_config = os.path.join(pkg_robot_description, 'config', 'multi_robot.rviz')
    rviz_node = TimerAction(
        period=10.0,
        actions=[
            Node(
                package='rviz2',
                executable='rviz2',
                name='rviz2',
                arguments=['-d', rviz_config] if os.path.exists(rviz_config) else [],
                parameters=[{'use_sim_time': True}],
                output='screen'
            )
        ]
    )
    
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        gazebo_launch,
        uwb_launch,
        slam_launch,
        # exploration_launch,  # Uncomment when Nav2 is configured
        # rviz_node,
    ])
