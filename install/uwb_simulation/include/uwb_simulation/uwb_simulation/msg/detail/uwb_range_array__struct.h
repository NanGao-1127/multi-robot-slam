// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uwb_simulation:msg/UwbRangeArray.idl
// generated code does not contain a copyright notice

#ifndef UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__STRUCT_H_
#define UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__STRUCT_H_

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
// Member 'ranges'
#include "uwb_simulation/msg/detail/uwb_range__struct.h"

/// Struct defined in msg/UwbRangeArray in the package uwb_simulation.
/**
  * Array of UWB Range measurements
 */
typedef struct uwb_simulation__msg__UwbRangeArray
{
  std_msgs__msg__Header header;
  /// Array of range measurements
  uwb_simulation__msg__UwbRange__Sequence ranges;
} uwb_simulation__msg__UwbRangeArray;

// Struct for a sequence of uwb_simulation__msg__UwbRangeArray.
typedef struct uwb_simulation__msg__UwbRangeArray__Sequence
{
  uwb_simulation__msg__UwbRangeArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uwb_simulation__msg__UwbRangeArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__STRUCT_H_
