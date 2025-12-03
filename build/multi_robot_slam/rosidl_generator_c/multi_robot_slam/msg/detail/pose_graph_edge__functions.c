// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_robot_slam:msg/PoseGraphEdge.idl
// generated code does not contain a copyright notice
#include "multi_robot_slam/msg/detail/pose_graph_edge__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `source_robot_id`
// Member `target_robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `relative_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
multi_robot_slam__msg__PoseGraphEdge__init(multi_robot_slam__msg__PoseGraphEdge * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    multi_robot_slam__msg__PoseGraphEdge__fini(msg);
    return false;
  }
  // edge_type
  // source_node_id
  // target_node_id
  // source_robot_id
  if (!rosidl_runtime_c__String__init(&msg->source_robot_id)) {
    multi_robot_slam__msg__PoseGraphEdge__fini(msg);
    return false;
  }
  // target_robot_id
  if (!rosidl_runtime_c__String__init(&msg->target_robot_id)) {
    multi_robot_slam__msg__PoseGraphEdge__fini(msg);
    return false;
  }
  // relative_pose
  if (!geometry_msgs__msg__Pose__init(&msg->relative_pose)) {
    multi_robot_slam__msg__PoseGraphEdge__fini(msg);
    return false;
  }
  // range_measurement
  // information_matrix
  // switch_variable
  // is_active
  return true;
}

void
multi_robot_slam__msg__PoseGraphEdge__fini(multi_robot_slam__msg__PoseGraphEdge * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // edge_type
  // source_node_id
  // target_node_id
  // source_robot_id
  rosidl_runtime_c__String__fini(&msg->source_robot_id);
  // target_robot_id
  rosidl_runtime_c__String__fini(&msg->target_robot_id);
  // relative_pose
  geometry_msgs__msg__Pose__fini(&msg->relative_pose);
  // range_measurement
  // information_matrix
  // switch_variable
  // is_active
}

bool
multi_robot_slam__msg__PoseGraphEdge__are_equal(const multi_robot_slam__msg__PoseGraphEdge * lhs, const multi_robot_slam__msg__PoseGraphEdge * rhs)
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
  // edge_type
  if (lhs->edge_type != rhs->edge_type) {
    return false;
  }
  // source_node_id
  if (lhs->source_node_id != rhs->source_node_id) {
    return false;
  }
  // target_node_id
  if (lhs->target_node_id != rhs->target_node_id) {
    return false;
  }
  // source_robot_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->source_robot_id), &(rhs->source_robot_id)))
  {
    return false;
  }
  // target_robot_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target_robot_id), &(rhs->target_robot_id)))
  {
    return false;
  }
  // relative_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->relative_pose), &(rhs->relative_pose)))
  {
    return false;
  }
  // range_measurement
  if (lhs->range_measurement != rhs->range_measurement) {
    return false;
  }
  // information_matrix
  for (size_t i = 0; i < 36; ++i) {
    if (lhs->information_matrix[i] != rhs->information_matrix[i]) {
      return false;
    }
  }
  // switch_variable
  if (lhs->switch_variable != rhs->switch_variable) {
    return false;
  }
  // is_active
  if (lhs->is_active != rhs->is_active) {
    return false;
  }
  return true;
}

bool
multi_robot_slam__msg__PoseGraphEdge__copy(
  const multi_robot_slam__msg__PoseGraphEdge * input,
  multi_robot_slam__msg__PoseGraphEdge * output)
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
  // edge_type
  output->edge_type = input->edge_type;
  // source_node_id
  output->source_node_id = input->source_node_id;
  // target_node_id
  output->target_node_id = input->target_node_id;
  // source_robot_id
  if (!rosidl_runtime_c__String__copy(
      &(input->source_robot_id), &(output->source_robot_id)))
  {
    return false;
  }
  // target_robot_id
  if (!rosidl_runtime_c__String__copy(
      &(input->target_robot_id), &(output->target_robot_id)))
  {
    return false;
  }
  // relative_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->relative_pose), &(output->relative_pose)))
  {
    return false;
  }
  // range_measurement
  output->range_measurement = input->range_measurement;
  // information_matrix
  for (size_t i = 0; i < 36; ++i) {
    output->information_matrix[i] = input->information_matrix[i];
  }
  // switch_variable
  output->switch_variable = input->switch_variable;
  // is_active
  output->is_active = input->is_active;
  return true;
}

multi_robot_slam__msg__PoseGraphEdge *
multi_robot_slam__msg__PoseGraphEdge__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_robot_slam__msg__PoseGraphEdge * msg = (multi_robot_slam__msg__PoseGraphEdge *)allocator.allocate(sizeof(multi_robot_slam__msg__PoseGraphEdge), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_robot_slam__msg__PoseGraphEdge));
  bool success = multi_robot_slam__msg__PoseGraphEdge__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_robot_slam__msg__PoseGraphEdge__destroy(multi_robot_slam__msg__PoseGraphEdge * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_robot_slam__msg__PoseGraphEdge__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_robot_slam__msg__PoseGraphEdge__Sequence__init(multi_robot_slam__msg__PoseGraphEdge__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_robot_slam__msg__PoseGraphEdge * data = NULL;

  if (size) {
    data = (multi_robot_slam__msg__PoseGraphEdge *)allocator.zero_allocate(size, sizeof(multi_robot_slam__msg__PoseGraphEdge), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_robot_slam__msg__PoseGraphEdge__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_robot_slam__msg__PoseGraphEdge__fini(&data[i - 1]);
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
multi_robot_slam__msg__PoseGraphEdge__Sequence__fini(multi_robot_slam__msg__PoseGraphEdge__Sequence * array)
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
      multi_robot_slam__msg__PoseGraphEdge__fini(&array->data[i]);
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

multi_robot_slam__msg__PoseGraphEdge__Sequence *
multi_robot_slam__msg__PoseGraphEdge__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_robot_slam__msg__PoseGraphEdge__Sequence * array = (multi_robot_slam__msg__PoseGraphEdge__Sequence *)allocator.allocate(sizeof(multi_robot_slam__msg__PoseGraphEdge__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_robot_slam__msg__PoseGraphEdge__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_robot_slam__msg__PoseGraphEdge__Sequence__destroy(multi_robot_slam__msg__PoseGraphEdge__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_robot_slam__msg__PoseGraphEdge__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_robot_slam__msg__PoseGraphEdge__Sequence__are_equal(const multi_robot_slam__msg__PoseGraphEdge__Sequence * lhs, const multi_robot_slam__msg__PoseGraphEdge__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_robot_slam__msg__PoseGraphEdge__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_robot_slam__msg__PoseGraphEdge__Sequence__copy(
  const multi_robot_slam__msg__PoseGraphEdge__Sequence * input,
  multi_robot_slam__msg__PoseGraphEdge__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(multi_robot_slam__msg__PoseGraphEdge);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_robot_slam__msg__PoseGraphEdge * data =
      (multi_robot_slam__msg__PoseGraphEdge *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_robot_slam__msg__PoseGraphEdge__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_robot_slam__msg__PoseGraphEdge__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_robot_slam__msg__PoseGraphEdge__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
