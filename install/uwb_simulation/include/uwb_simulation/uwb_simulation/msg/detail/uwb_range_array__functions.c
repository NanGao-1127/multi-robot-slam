// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uwb_simulation:msg/UwbRangeArray.idl
// generated code does not contain a copyright notice
#include "uwb_simulation/msg/detail/uwb_range_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `ranges`
#include "uwb_simulation/msg/detail/uwb_range__functions.h"

bool
uwb_simulation__msg__UwbRangeArray__init(uwb_simulation__msg__UwbRangeArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    uwb_simulation__msg__UwbRangeArray__fini(msg);
    return false;
  }
  // ranges
  if (!uwb_simulation__msg__UwbRange__Sequence__init(&msg->ranges, 0)) {
    uwb_simulation__msg__UwbRangeArray__fini(msg);
    return false;
  }
  return true;
}

void
uwb_simulation__msg__UwbRangeArray__fini(uwb_simulation__msg__UwbRangeArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // ranges
  uwb_simulation__msg__UwbRange__Sequence__fini(&msg->ranges);
}

bool
uwb_simulation__msg__UwbRangeArray__are_equal(const uwb_simulation__msg__UwbRangeArray * lhs, const uwb_simulation__msg__UwbRangeArray * rhs)
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
  // ranges
  if (!uwb_simulation__msg__UwbRange__Sequence__are_equal(
      &(lhs->ranges), &(rhs->ranges)))
  {
    return false;
  }
  return true;
}

bool
uwb_simulation__msg__UwbRangeArray__copy(
  const uwb_simulation__msg__UwbRangeArray * input,
  uwb_simulation__msg__UwbRangeArray * output)
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
  // ranges
  if (!uwb_simulation__msg__UwbRange__Sequence__copy(
      &(input->ranges), &(output->ranges)))
  {
    return false;
  }
  return true;
}

uwb_simulation__msg__UwbRangeArray *
uwb_simulation__msg__UwbRangeArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uwb_simulation__msg__UwbRangeArray * msg = (uwb_simulation__msg__UwbRangeArray *)allocator.allocate(sizeof(uwb_simulation__msg__UwbRangeArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uwb_simulation__msg__UwbRangeArray));
  bool success = uwb_simulation__msg__UwbRangeArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uwb_simulation__msg__UwbRangeArray__destroy(uwb_simulation__msg__UwbRangeArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uwb_simulation__msg__UwbRangeArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uwb_simulation__msg__UwbRangeArray__Sequence__init(uwb_simulation__msg__UwbRangeArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uwb_simulation__msg__UwbRangeArray * data = NULL;

  if (size) {
    data = (uwb_simulation__msg__UwbRangeArray *)allocator.zero_allocate(size, sizeof(uwb_simulation__msg__UwbRangeArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uwb_simulation__msg__UwbRangeArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uwb_simulation__msg__UwbRangeArray__fini(&data[i - 1]);
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
uwb_simulation__msg__UwbRangeArray__Sequence__fini(uwb_simulation__msg__UwbRangeArray__Sequence * array)
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
      uwb_simulation__msg__UwbRangeArray__fini(&array->data[i]);
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

uwb_simulation__msg__UwbRangeArray__Sequence *
uwb_simulation__msg__UwbRangeArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uwb_simulation__msg__UwbRangeArray__Sequence * array = (uwb_simulation__msg__UwbRangeArray__Sequence *)allocator.allocate(sizeof(uwb_simulation__msg__UwbRangeArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uwb_simulation__msg__UwbRangeArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uwb_simulation__msg__UwbRangeArray__Sequence__destroy(uwb_simulation__msg__UwbRangeArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uwb_simulation__msg__UwbRangeArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uwb_simulation__msg__UwbRangeArray__Sequence__are_equal(const uwb_simulation__msg__UwbRangeArray__Sequence * lhs, const uwb_simulation__msg__UwbRangeArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uwb_simulation__msg__UwbRangeArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uwb_simulation__msg__UwbRangeArray__Sequence__copy(
  const uwb_simulation__msg__UwbRangeArray__Sequence * input,
  uwb_simulation__msg__UwbRangeArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uwb_simulation__msg__UwbRangeArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    uwb_simulation__msg__UwbRangeArray * data =
      (uwb_simulation__msg__UwbRangeArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uwb_simulation__msg__UwbRangeArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          uwb_simulation__msg__UwbRangeArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!uwb_simulation__msg__UwbRangeArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
