// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_robot_slam:msg/PoseGraph.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__STRUCT_H_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__STRUCT_H_

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
// Member 'nodes'
#include "multi_robot_slam/msg/detail/pose_graph_node__struct.h"
// Member 'edges'
#include "multi_robot_slam/msg/detail/pose_graph_edge__struct.h"

/// Struct defined in msg/PoseGraph in the package multi_robot_slam.
/**
  * Complete pose graph message
 */
typedef struct multi_robot_slam__msg__PoseGraph
{
  std_msgs__msg__Header header;
  /// All nodes in the graph
  multi_robot_slam__msg__PoseGraphNode__Sequence nodes;
  /// All edges in the graph
  multi_robot_slam__msg__PoseGraphEdge__Sequence edges;
  /// Optimization status
  bool is_optimized;
  double optimization_cost;
  uint32_t num_iterations;
} multi_robot_slam__msg__PoseGraph;

// Struct for a sequence of multi_robot_slam__msg__PoseGraph.
typedef struct multi_robot_slam__msg__PoseGraph__Sequence
{
  multi_robot_slam__msg__PoseGraph * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_robot_slam__msg__PoseGraph__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__STRUCT_H_
