#!/usr/bin/env python3
"""
UWB Simulation Launch File
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # Launch arguments
    robot_names_arg = DeclareLaunchArgument(
        'robot_names',
        default_value="['robot1', 'robot2']",
        description='List of robot names'
    )
    
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation time'
    )
    
    # UWB Range Simulator
    uwb_simulator = Node(
        package='uwb_simulation',
        executable='uwb_range_simulator.py',
        name='uwb_range_simulator',
        parameters=[{
            'robot_names': ['robot1', 'robot2'],
            'range_std': 0.02,
            'max_range': 20.0,
            'update_rate': 10.0,
            'spurious_prob': 0.05,
            'use_sim_time': True
        }],
        output='screen'
    )
    
    # UWB Range Publisher
    uwb_publisher = Node(
        package='uwb_simulation',
        executable='uwb_range_publisher.py',
        name='uwb_range_publisher',
        parameters=[{
            'robot_names': ['robot1', 'robot2'],
            'pose_buffer_size': 100,
            'max_time_diff': 0.1,
            'use_sim_time': True
        }],
        output='screen'
    )
    
    return LaunchDescription([
        robot_names_arg,
        use_sim_time_arg,
        uwb_simulator,
        uwb_publisher,
    ])
