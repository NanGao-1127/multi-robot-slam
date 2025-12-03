// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_robot_slam:msg/MapMergeStatus.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__STRUCT_H_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__STRUCT_H_

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
// Member 'robot_ids'
#include "rosidl_runtime_c/string.h"
// Member 'transforms'
#include "geometry_msgs/msg/detail/transform__struct.h"

/// Struct defined in msg/MapMergeStatus in the package multi_robot_slam.
/**
  * Map merge status message
 */
typedef struct multi_robot_slam__msg__MapMergeStatus
{
  std_msgs__msg__Header header;
  /// Status flags
  bool maps_aligned;
  bool merge_successful;
  /// Number of robots contributing to the merged map
  uint8_t num_robots;
  /// Transform from each robot's map frame to global frame
  rosidl_runtime_c__String__Sequence robot_ids;
  geometry_msgs__msg__Transform__Sequence transforms;
  /// Quality metrics
  double alignment_score;
  double overlap_ratio;
} multi_robot_slam__msg__MapMergeStatus;

// Struct for a sequence of multi_robot_slam__msg__MapMergeStatus.
typedef struct multi_robot_slam__msg__MapMergeStatus__Sequence
{
  multi_robot_slam__msg__MapMergeStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_robot_slam__msg__MapMergeStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__STRUCT_H_
