# Multi-Robot SLAM with UWB Ranging

This project implements a multi-robot SLAM system using UWB (Ultra-Wideband) range measurements for pose graph optimization, based on the paper:

**"Inter-Robot Range Measurements in Pose Graph Optimization"** - Boroson et al., IROS 2020

## Overview

The system enables multiple robots to collaboratively build a map even when visual loop closures are not available. Key features:

- **UWB Range Measurements**: Simulated UWB sensors provide inter-robot distance measurements
- **Pose Graph Optimization**: Range edges are added to the pose graph with switchable constraints
- **Task Allocation**: Robots are assigned different frontiers to avoid overlap
- **Collision Avoidance**: Inter-robot collision prevention
- **Map Merging**: Individual robot maps are merged into a global map

## Packages

### 1. robot_description
Robot URDF with UWB sensors, Gazebo simulation files, and launch files.

### 2. uwb_simulation  
Simulates UWB ranging between robots:
- `uwb_range_simulator.py`: Generates range measurements with realistic noise model
- `uwb_range_publisher.py`: Associates ranges with robot poses

### 3. multi_robot_slam
Core SLAM components:
- `pose_graph_optimizer.py`: Optimizes poses using odometry and range edges
- `map_merger.py`: Merges robot maps into global map
- `tf_publisher.py`: Publishes coordinate frame transforms
- `slam_coordinator.py`: Manages overall SLAM process

### 4. multi_robot_exploration
Exploration and navigation:
- `frontier_explorer.py`: Detects exploration frontiers
- `task_allocator.py`: Assigns frontiers to robots (Hungarian algorithm)
- `collision_avoider.py`: Prevents inter-robot collisions
- `exploration_coordinator.py`: Coordinates exploration with Nav2

## Installation

```bash
# Create workspace
mkdir -p ~/multi_robot_ws/src
cd ~/multi_robot_ws/src

# Copy packages
cp -r <this_project>/* .

# Install dependencies
cd ~/multi_robot_ws
rosdep install --from-paths src --ignore-src -r -y

# Build
colcon build --symlink-install

# Source
source install/setup.bash
```

## Usage

### Launch full system:
```bash
ros2 launch robot_description bringup.launch.py
```

### Launch components separately:

1. **Gazebo with robots:**
```bash
ros2 launch robot_description multi_robot_gazebo.launch.py
```

2. **UWB simulation:**
```bash
ros2 launch uwb_simulation uwb_simulation.launch.py
```

3. **SLAM:**
```bash
ros2 launch multi_robot_slam multi_robot_slam.launch.py
```

4. **Exploration:**
```bash
ros2 launch multi_robot_exploration exploration.launch.py
```

## Topics

### UWB Topics
- `/uwb/ranges` - Array of range measurements
- `/uwb/range_robot1_robot2` - Individual pair measurements

### Robot Topics (per robot)
- `/<robot>/odom` - Odometry
- `/<robot>/scan` - LiDAR scan
- `/<robot>/map` - Local map
- `/<robot>/cmd_vel` - Velocity commands

### Global Topics
- `/global_map` - Merged global map
- `/slam/status` - SLAM status
- `/exploration/status` - Exploration status

## Configuration

### UWB Parameters (uwb_simulation)
- `range_std`: Measurement noise (default: 0.02m)
- `max_range`: Maximum range (default: 20m)
- `spurious_prob`: Probability of spurious measurements (default: 0.05)

### SLAM Parameters (multi_robot_slam)
- `range_edge_weight`: Weight for range edges in optimization
- `switch_prior_weight`: Weight for switchable constraints
- `optimization_rate`: Optimization frequency

### Exploration Parameters (multi_robot_exploration)
- `min_frontier_size`: Minimum frontier cluster size
- `min_inter_robot_dist`: Minimum distance between robot goals
- `safety_distance`: Collision avoidance distance

## Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                     Global Coordinator                       │
│  ┌─────────────┐  ┌─────────────┐  ┌─────────────────────┐  │
│  │ Map Merger  │  │ Task Alloc  │  │ Pose Graph Optimizer│  │
│  └─────────────┘  └─────────────┘  └─────────────────────┘  │
│         ▲               ▲                    ▲               │
│         │               │                    │               │
│  ┌──────┴───────────────┴────────────────────┴──────┐       │
│  │              UWB Range Measurements               │       │
│  └───────────────────────────────────────────────────┘       │
└─────────────────────────────────────────────────────────────┘
         ▲                                      ▲
         │                                      │
┌────────┴────────┐                  ┌──────────┴────────┐
│     Robot 1     │                  │      Robot 2      │
│  ┌───────────┐  │                  │  ┌───────────┐    │
│  │   SLAM    │  │    UWB Range     │  │   SLAM    │    │
│  │  Toolbox  │  │◄────────────────►│  │  Toolbox  │    │
│  └───────────┘  │                  │  └───────────┘    │
│  ┌───────────┐  │                  │  ┌───────────┐    │
│  │  Nav2     │  │                  │  │   Nav2    │    │
│  └───────────┘  │                  │  └───────────┘    │
│  ┌───────────┐  │                  │  ┌───────────┐    │
│  │  LiDAR    │  │                  │  │  LiDAR    │    │
│  └───────────┘  │                  │  └───────────┘    │
└─────────────────┘                  └───────────────────┘
```

## Algorithm Details

### Pose Graph Optimization with Range Edges

The optimization minimizes:
```
X* = argmin Σ ||f_ij(x_i) - x_j||²_Λ
```

For range edges, we use switchable constraints:
```
cost = (1/σ²_r) * (Ψ(s_ij) * (f(x_i, x_j) - r_ij))² + (1/σ²_s) * (γ_ij - s_ij)²
```

Where Ψ is a sigmoid function that can "switch off" bad measurements.

### Task Allocation

Uses the Hungarian algorithm to optimally assign frontiers to robots, minimizing:
- Distance to frontier
- Overlap with other robots' goals

## Dependencies

- ROS 2 Humble
- Gazebo
- SLAM Toolbox
- Nav2
- Python packages: numpy, scipy

## License

Apache 2.0
