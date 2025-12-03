// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_robot_slam:msg/MapMergeStatus.idl
// generated code does not contain a copyright notice
#include "multi_robot_slam/msg/detail/map_merge_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `robot_ids`
#include "rosidl_runtime_c/string_functions.h"
// Member `transforms`
#include "geometry_msgs/msg/detail/transform__functions.h"

bool
multi_robot_slam__msg__MapMergeStatus__init(multi_robot_slam__msg__MapMergeStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    multi_robot_slam__msg__MapMergeStatus__fini(msg);
    return false;
  }
  // maps_aligned
  // merge_successful
  // num_robots
  // robot_ids
  if (!rosidl_runtime_c__String__Sequence__init(&msg->robot_ids, 0)) {
    multi_robot_slam__msg__MapMergeStatus__fini(msg);
    return false;
  }
  // transforms
  if (!geometry_msgs__msg__Transform__Sequence__init(&msg->transforms, 0)) {
    multi_robot_slam__msg__MapMergeStatus__fini(msg);
    return false;
  }
  // alignment_score
  // overlap_ratio
  return true;
}

void
multi_robot_slam__msg__MapMergeStatus__fini(multi_robot_slam__msg__MapMergeStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // maps_aligned
  // merge_successful
  // num_robots
  // robot_ids
  rosidl_runtime_c__String__Sequence__fini(&msg->robot_ids);
  // transforms
  geometry_msgs__msg__Transform__Sequence__fini(&msg->transforms);
  // alignment_score
  // overlap_ratio
}

bool
multi_robot_slam__msg__MapMergeStatus__are_equal(const multi_robot_slam__msg__MapMergeStatus * lhs, const multi_robot_slam__msg__MapMergeStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // maps_aligned
  if (lhs->maps_aligned != rhs->maps_aligned) {
    return false;
  }
  // merge_successful
  if (lhs->merge_successful != rhs->merge_successful) {
    return false;
  }
  // num_robots
  if (lhs->num_robots != rhs->num_robots) {
    return false;
  }
  // robot_ids
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->robot_ids), &(rhs->robot_ids)))
  {
    return false;
  }
  // transforms
  if (!geometry_msgs__msg__Transform__Sequence__are_equal(
      &(lhs->transforms), &(rhs->transforms)))
  {
    return false;
  }
  // alignment_score
  if (lhs->alignment_score != rhs->alignment_score) {
    return false;
  }
  // overlap_ratio
  if (lhs->overlap_ratio != rhs->overlap_ratio) {
    return false;
  }
  return true;
}

bool
multi_robot_slam__msg__MapMergeStatus__copy(
  const multi_robot_slam__msg__MapMergeStatus * input,
  multi_robot_slam__msg__MapMergeStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // maps_aligned
  output->maps_aligned = input->maps_aligned;
  // merge_successful
  output->merge_successful = input->merge_successful;
  // num_robots
  output->num_robots = input->num_robots;
  // robot_ids
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->robot_ids), &(output->robot_ids)))
  {
    return false;
  }
  // transforms
  if (!geometry_msgs__msg__Transform__Sequence__copy(
      &(input->transforms), &(output->transforms)))
  {
    return false;
  }
  // alignment_score
  output->alignment_score = input->alignment_score;
  // overlap_ratio
  output->overlap_ratio = input->overlap_ratio;
  return true;
}

multi_robot_slam__msg__MapMergeStatus *
multi_robot_slam__msg__MapMergeStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_robot_slam__msg__MapMergeStatus * msg = (multi_robot_slam__msg__MapMergeStatus *)allocator.allocate(sizeof(multi_robot_slam__msg__MapMergeStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_robot_slam__msg__MapMergeStatus));
  bool success = multi_robot_slam__msg__MapMergeStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_robot_slam__msg__MapMergeStatus__destroy(multi_robot_slam__msg__MapMergeStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_robot_slam__msg__MapMergeStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_robot_slam__msg__MapMergeStatus__Sequence__init(multi_robot_slam__msg__MapMergeStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_robot_slam__msg__MapMergeStatus * data = NULL;

  if (size) {
    data = (multi_robot_slam__msg__MapMergeStatus *)allocator.zero_allocate(size, sizeof(multi_robot_slam__msg__MapMergeStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_robot_slam__msg__MapMergeStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_robot_slam__msg__MapMergeStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
multi_robot_slam__msg__MapMergeStatus__Sequence__fini(multi_robot_slam__msg__MapMergeStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      multi_robot_slam__msg__MapMergeStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

multi_robot_slam__msg__MapMergeStatus__Sequence *
multi_robot_slam__msg__MapMergeStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_robot_slam__msg__MapMergeStatus__Sequence * array = (multi_robot_slam__msg__MapMergeStatus__Sequence *)allocator.allocate(sizeof(multi_robot_slam__msg__MapMergeStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_robot_slam__msg__MapMergeStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_robot_slam__msg__MapMergeStatus__Sequence__destroy(multi_robot_slam__msg__MapMergeStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_robot_slam__msg__MapMergeStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_robot_slam__msg__MapMergeStatus__Sequence__are_equal(const multi_robot_slam__msg__MapMergeStatus__Sequence * lhs, const multi_robot_slam__msg__MapMergeStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_robot_slam__msg__MapMergeStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_robot_slam__msg__MapMergeStatus__Sequence__copy(
  const multi_robot_slam__msg__MapMergeStatus__Sequence * input,
  multi_robot_slam__msg__MapMergeStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(multi_robot_slam__msg__MapMergeStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_robot_slam__msg__MapMergeStatus * data =
      (multi_robot_slam__msg__MapMergeStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_robot_slam__msg__MapMergeStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_robot_slam__msg__MapMergeStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_robot_slam__msg__MapMergeStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
