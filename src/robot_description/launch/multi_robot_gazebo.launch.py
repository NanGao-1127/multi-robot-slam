#!/usr/bin/env python3
"""
Multi-robot Gazebo simulation launch file.
Spawns two robots with UWB sensors for collaborative SLAM.
"""

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution
from launch_ros.actions import Node, PushRosNamespace
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # Package paths
    pkg_robot_description = get_package_share_directory('robot_description')
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')
    
    # Paths
    world_file = os.path.join(pkg_robot_description, 'world', 'exploration_world.world')
    urdf_file = os.path.join(pkg_robot_description, 'urdf', 'explorer_robot.urdf.xacro')
    
    # Launch arguments
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    
    # Robot 1 configuration
    robot1_name = 'robot1'
    robot1_namespace = '/robot1'
    robot1_x = '-3.0'
    robot1_y = '0.0'
    robot1_z = '0.0'
    robot1_yaw = '0.0'
    
    # Robot 2 configuration
    robot2_name = 'robot2'
    robot2_namespace = '/robot2'
    robot2_x = '3.0'
    robot2_y = '0.0'
    robot2_z = '0.0'
    robot2_yaw = '3.14159'
    
    # Generate robot descriptions
    robot1_description = Command([
        'xacro ', urdf_file,
        ' robot_name:=', robot1_name,
        ' robot_namespace:=', robot1_namespace
    ])
    
    robot2_description = Command([
        'xacro ', urdf_file,
        ' robot_name:=', robot2_name,
        ' robot_namespace:=', robot2_namespace
    ])
    
    # Launch Gazebo
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gazebo.launch.py')
        ),
        launch_arguments={
            'world': world_file,
            'verbose': 'true'
        }.items()
    )
    
    # Robot 1 nodes
    robot1_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        namespace=robot1_namespace,
        parameters=[{
            'robot_description': robot1_description,
            'use_sim_time': use_sim_time,
            'frame_prefix': f'{robot1_name}/'
        }],
        output='screen'
    )
    
    robot1_spawner = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_robot1',
        arguments=[
            '-topic', f'{robot1_namespace}/robot_description',
            '-entity', robot1_name,
            '-x', robot1_x,
            '-y', robot1_y,
            '-z', robot1_z,
            '-Y', robot1_yaw,
        ],
        output='screen'
    )
    
    # Robot 2 nodes
    robot2_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        namespace=robot2_namespace,
        parameters=[{
            'robot_description': robot2_description,
            'use_sim_time': use_sim_time,
            'frame_prefix': f'{robot2_name}/'
        }],
        output='screen'
    )
    
    robot2_spawner = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_robot2',
        arguments=[
            '-topic', f'{robot2_namespace}/robot_description',
            '-entity', robot2_name,
            '-x', robot2_x,
            '-y', robot2_y,
            '-z', robot2_z,
            '-Y', robot2_yaw,
        ],
        output='screen'
    )
    
    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use simulation time'
        ),
        gazebo,
        robot1_state_publisher,
        robot1_spawner,
        robot2_state_publisher,
        robot2_spawner,
    ])
