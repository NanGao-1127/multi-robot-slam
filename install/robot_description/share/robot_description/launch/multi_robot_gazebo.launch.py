#!/usr/bin/env python3
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import xacro

def generate_launch_description():
    pkg_robot_description = get_package_share_directory('robot_description')
    
    world_file = os.path.join(pkg_robot_description, 'world', 'exploration_world.world')
    xacro_file = os.path.join(pkg_robot_description, 'urdf', 'explorer_robot.urdf.xacro')
    
    # Process xacro for robot1
    robot1_doc = xacro.process_file(xacro_file, mappings={'robot_name': 'robot1', 'robot_namespace': 'robot1'})
    robot1_desc = robot1_doc.toxml()
    
    # Process xacro for robot2
    robot2_doc = xacro.process_file(xacro_file, mappings={'robot_name': 'robot2', 'robot_namespace': 'robot2'})
    robot2_desc = robot2_doc.toxml()
    
    # Gazebo
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')
        ),
        launch_arguments={'world': world_file, 'verbose': 'true'}.items()
    )
    
    # Robot 1
    robot_state_pub_1 = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        namespace='robot1',
        parameters=[{
            'robot_description': robot1_desc,
            'use_sim_time': True
        }],
        output='screen'
    )
    
    spawn_robot_1 = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_robot1',
        arguments=[
            '-topic', '/robot1/robot_description',
            '-entity', 'robot1',
            '-x', '-3.0', '-y', '0.0', '-z', '0.1', '-Y', '0.0'
        ],
        output='screen'
    )
    
    # Robot 2
    robot_state_pub_2 = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        namespace='robot2',
        parameters=[{
            'robot_description': robot2_desc,
            'use_sim_time': True
        }],
        output='screen'
    )
    
    spawn_robot_2 = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_robot2',
        arguments=[
            '-topic', '/robot2/robot_description',
            '-entity', 'robot2',
            '-x', '3.0', '-y', '0.0', '-z', '0.1', '-Y', '3.14159'
        ],
        output='screen'
    )
    
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        gazebo,
        robot_state_pub_1,
        spawn_robot_1,
        robot_state_pub_2,
        spawn_robot_2,
    ])