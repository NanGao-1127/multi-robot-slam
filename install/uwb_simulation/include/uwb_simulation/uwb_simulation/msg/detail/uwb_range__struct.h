// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uwb_simulation:msg/UwbRange.idl
// generated code does not contain a copyright notice

#ifndef UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__STRUCT_H_
#define UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__STRUCT_H_

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
// Member 'source_robot_id'
// Member 'target_robot_id'
#include "rosidl_runtime_c/string.h"
// Member 'measurement_time'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/UwbRange in the package uwb_simulation.
/**
  * UWB Range measurement message
  * Based on the paper: Inter-Robot Range Measurements in Pose Graph Optimization
 */
typedef struct uwb_simulation__msg__UwbRange
{
  std_msgs__msg__Header header;
  /// Source robot ID (the robot making the measurement)
  rosidl_runtime_c__String source_robot_id;
  /// Target robot ID (the robot being measured to)
  rosidl_runtime_c__String target_robot_id;
  /// Measured range in meters
  double range;
  /// Standard deviation of the measurement (typically ~0.02m for DWM1001)
  double range_std;
  /// Measurement timestamp (when the ranging was performed)
  builtin_interfaces__msg__Time measurement_time;
  /// Quality indicator (0-100, higher is better)
  uint8_t quality;
  /// Whether this measurement is valid
  bool is_valid;
} uwb_simulation__msg__UwbRange;

// Struct for a sequence of uwb_simulation__msg__UwbRange.
typedef struct uwb_simulation__msg__UwbRange__Sequence
{
  uwb_simulation__msg__UwbRange * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uwb_simulation__msg__UwbRange__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__STRUCT_H_
