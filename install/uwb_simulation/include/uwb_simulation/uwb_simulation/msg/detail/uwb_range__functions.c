// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uwb_simulation:msg/UwbRange.idl
// generated code does not contain a copyright notice
#include "uwb_simulation/msg/detail/uwb_range__functions.h"

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
// Member `measurement_time`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
uwb_simulation__msg__UwbRange__init(uwb_simulation__msg__UwbRange * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    uwb_simulation__msg__UwbRange__fini(msg);
    return false;
  }
  // source_robot_id
  if (!rosidl_runtime_c__String__init(&msg->source_robot_id)) {
    uwb_simulation__msg__UwbRange__fini(msg);
    return false;
  }
  // target_robot_id
  if (!rosidl_runtime_c__String__init(&msg->target_robot_id)) {
    uwb_simulation__msg__UwbRange__fini(msg);
    return false;
  }
  // range
  // range_std
  // measurement_time
  if (!builtin_interfaces__msg__Time__init(&msg->measurement_time)) {
    uwb_simulation__msg__UwbRange__fini(msg);
    return false;
  }
  // quality
  // is_valid
  return true;
}

void
uwb_simulation__msg__UwbRange__fini(uwb_simulation__msg__UwbRange * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // source_robot_id
  rosidl_runtime_c__String__fini(&msg->source_robot_id);
  // target_robot_id
  rosidl_runtime_c__String__fini(&msg->target_robot_id);
  // range
  // range_std
  // measurement_time
  builtin_interfaces__msg__Time__fini(&msg->measurement_time);
  // quality
  // is_valid
}

bool
uwb_simulation__msg__UwbRange__are_equal(const uwb_simulation__msg__UwbRange * lhs, const uwb_simulation__msg__UwbRange * rhs)
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
  // range
  if (lhs->range != rhs->range) {
    return false;
  }
  // range_std
  if (lhs->range_std != rhs->range_std) {
    return false;
  }
  // measurement_time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->measurement_time), &(rhs->measurement_time)))
  {
    return false;
  }
  // quality
  if (lhs->quality != rhs->quality) {
    return false;
  }
  // is_valid
  if (lhs->is_valid != rhs->is_valid) {
    return false;
  }
  return true;
}

bool
uwb_simulation__msg__UwbRange__copy(
  const uwb_simulation__msg__UwbRange * input,
  uwb_simulation__msg__UwbRange * output)
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
  // range
  output->range = input->range;
  // range_std
  output->range_std = input->range_std;
  // measurement_time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->measurement_time), &(output->measurement_time)))
  {
    return false;
  }
  // quality
  output->quality = input->quality;
  // is_valid
  output->is_valid = input->is_valid;
  return true;
}

uwb_simulation__msg__UwbRange *
uwb_simulation__msg__UwbRange__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uwb_simulation__msg__UwbRange * msg = (uwb_simulation__msg__UwbRange *)allocator.allocate(sizeof(uwb_simulation__msg__UwbRange), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uwb_simulation__msg__UwbRange));
  bool success = uwb_simulation__msg__UwbRange__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uwb_simulation__msg__UwbRange__destroy(uwb_simulation__msg__UwbRange * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uwb_simulation__msg__UwbRange__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uwb_simulation__msg__UwbRange__Sequence__init(uwb_simulation__msg__UwbRange__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uwb_simulation__msg__UwbRange * data = NULL;

  if (size) {
    data = (uwb_simulation__msg__UwbRange *)allocator.zero_allocate(size, sizeof(uwb_simulation__msg__UwbRange), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uwb_simulation__msg__UwbRange__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uwb_simulation__msg__UwbRange__fini(&data[i - 1]);
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
uwb_simulation__msg__UwbRange__Sequence__fini(uwb_simulation__msg__UwbRange__Sequence * array)
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
      uwb_simulation__msg__UwbRange__fini(&array->data[i]);
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

uwb_simulation__msg__UwbRange__Sequence *
uwb_simulation__msg__UwbRange__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uwb_simulation__msg__UwbRange__Sequence * array = (uwb_simulation__msg__UwbRange__Sequence *)allocator.allocate(sizeof(uwb_simulation__msg__UwbRange__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uwb_simulation__msg__UwbRange__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uwb_simulation__msg__UwbRange__Sequence__destroy(uwb_simulation__msg__UwbRange__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uwb_simulation__msg__UwbRange__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uwb_simulation__msg__UwbRange__Sequence__are_equal(const uwb_simulation__msg__UwbRange__Sequence * lhs, const uwb_simulation__msg__UwbRange__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uwb_simulation__msg__UwbRange__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uwb_simulation__msg__UwbRange__Sequence__copy(
  const uwb_simulation__msg__UwbRange__Sequence * input,
  uwb_simulation__msg__UwbRange__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uwb_simulation__msg__UwbRange);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    uwb_simulation__msg__UwbRange * data =
      (uwb_simulation__msg__UwbRange *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uwb_simulation__msg__UwbRange__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          uwb_simulation__msg__UwbRange__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!uwb_simulation__msg__UwbRange__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
