// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_robot_slam:msg/PoseGraphEdge.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__STRUCT_H_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'EDGE_ODOMETRY'.
/**
  * Edge type
 */
enum
{
  multi_robot_slam__msg__PoseGraphEdge__EDGE_ODOMETRY = 0
};

/// Constant 'EDGE_LOOP_CLOSURE'.
enum
{
  multi_robot_slam__msg__PoseGraphEdge__EDGE_LOOP_CLOSURE = 1
};

/// Constant 'EDGE_UWB_RANGE'.
enum
{
  multi_robot_slam__msg__PoseGraphEdge__EDGE_UWB_RANGE = 2
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'source_robot_id'
// Member 'target_robot_id'
#include "rosidl_runtime_c/string.h"
// Member 'relative_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/PoseGraphEdge in the package multi_robot_slam.
/**
  * Pose graph edge (constraint) message
 */
typedef struct multi_robot_slam__msg__PoseGraphEdge
{
  std_msgs__msg__Header header;
  uint8_t edge_type;
  /// Source and target node IDs
  uint32_t source_node_id;
  uint32_t target_node_id;
  /// Source and target robot IDs (for inter-robot edges)
  rosidl_runtime_c__String source_robot_id;
  rosidl_runtime_c__String target_robot_id;
  /// For odometry/loop closure edges: relative transform
  geometry_msgs__msg__Pose relative_pose;
  /// For range edges: measured range
  double range_measurement;
  /// Measurement uncertainty
  double information_matrix[36];
  /// Switch variable for robust optimization (1.0 = on, 0.0 = off)
  double switch_variable;
  /// Whether this edge is active in optimization
  bool is_active;
} multi_robot_slam__msg__PoseGraphEdge;

// Struct for a sequence of multi_robot_slam__msg__PoseGraphEdge.
typedef struct multi_robot_slam__msg__PoseGraphEdge__Sequence
{
  multi_robot_slam__msg__PoseGraphEdge * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_robot_slam__msg__PoseGraphEdge__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__STRUCT_H_
