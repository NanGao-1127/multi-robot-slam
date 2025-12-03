// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_robot_slam:msg/PoseGraphNode.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__STRUCT_H_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'robot_id'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/PoseGraphNode in the package multi_robot_slam.
/**
  * Pose graph node (vertex) message
 */
typedef struct multi_robot_slam__msg__PoseGraphNode
{
  std_msgs__msg__Header header;
  /// Unique node ID
  uint32_t node_id;
  /// Robot that created this node
  rosidl_runtime_c__String robot_id;
  /// Pose of the node
  geometry_msgs__msg__Pose pose;
  /// Covariance (6x6 flattened to 36 elements)
  double covariance[36];
  /// Timestamp when this pose was recorded
  builtin_interfaces__msg__Time timestamp;
} multi_robot_slam__msg__PoseGraphNode;

// Struct for a sequence of multi_robot_slam__msg__PoseGraphNode.
typedef struct multi_robot_slam__msg__PoseGraphNode__Sequence
{
  multi_robot_slam__msg__PoseGraphNode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_robot_slam__msg__PoseGraphNode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__STRUCT_H_
