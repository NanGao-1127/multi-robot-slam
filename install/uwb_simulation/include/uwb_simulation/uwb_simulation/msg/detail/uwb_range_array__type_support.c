// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from uwb_simulation:msg/UwbRangeArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "uwb_simulation/msg/detail/uwb_range_array__rosidl_typesupport_introspection_c.h"
#include "uwb_simulation/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "uwb_simulation/msg/detail/uwb_range_array__functions.h"
#include "uwb_simulation/msg/detail/uwb_range_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `ranges`
#include "uwb_simulation/msg/uwb_range.h"
// Member `ranges`
#include "uwb_simulation/msg/detail/uwb_range__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uwb_simulation__msg__UwbRangeArray__init(message_memory);
}

void uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_fini_function(void * message_memory)
{
  uwb_simulation__msg__UwbRangeArray__fini(message_memory);
}

size_t uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__size_function__UwbRangeArray__ranges(
  const void * untyped_member)
{
  const uwb_simulation__msg__UwbRange__Sequence * member =
    (const uwb_simulation__msg__UwbRange__Sequence *)(untyped_member);
  return member->size;
}

const void * uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__get_const_function__UwbRangeArray__ranges(
  const void * untyped_member, size_t index)
{
  const uwb_simulation__msg__UwbRange__Sequence * member =
    (const uwb_simulation__msg__UwbRange__Sequence *)(untyped_member);
  return &member->data[index];
}

void * uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__get_function__UwbRangeArray__ranges(
  void * untyped_member, size_t index)
{
  uwb_simulation__msg__UwbRange__Sequence * member =
    (uwb_simulation__msg__UwbRange__Sequence *)(untyped_member);
  return &member->data[index];
}

void uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__fetch_function__UwbRangeArray__ranges(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uwb_simulation__msg__UwbRange * item =
    ((const uwb_simulation__msg__UwbRange *)
    uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__get_const_function__UwbRangeArray__ranges(untyped_member, index));
  uwb_simulation__msg__UwbRange * value =
    (uwb_simulation__msg__UwbRange *)(untyped_value);
  *value = *item;
}

void uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__assign_function__UwbRangeArray__ranges(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uwb_simulation__msg__UwbRange * item =
    ((uwb_simulation__msg__UwbRange *)
    uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__get_function__UwbRangeArray__ranges(untyped_member, index));
  const uwb_simulation__msg__UwbRange * value =
    (const uwb_simulation__msg__UwbRange *)(untyped_value);
  *item = *value;
}

bool uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__resize_function__UwbRangeArray__ranges(
  void * untyped_member, size_t size)
{
  uwb_simulation__msg__UwbRange__Sequence * member =
    (uwb_simulation__msg__UwbRange__Sequence *)(untyped_member);
  uwb_simulation__msg__UwbRange__Sequence__fini(member);
  return uwb_simulation__msg__UwbRange__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRangeArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ranges",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRangeArray, ranges),  // bytes offset in struct
    NULL,  // default value
    uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__size_function__UwbRangeArray__ranges,  // size() function pointer
    uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__get_const_function__UwbRangeArray__ranges,  // get_const(index) function pointer
    uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__get_function__UwbRangeArray__ranges,  // get(index) function pointer
    uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__fetch_function__UwbRangeArray__ranges,  // fetch(index, &value) function pointer
    uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__assign_function__UwbRangeArray__ranges,  // assign(index, value) function pointer
    uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__resize_function__UwbRangeArray__ranges  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_members = {
  "uwb_simulation__msg",  // message namespace
  "UwbRangeArray",  // message name
  2,  // number of fields
  sizeof(uwb_simulation__msg__UwbRangeArray),
  uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_member_array,  // message members
  uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_init_function,  // function to initialize message memory (memory has to be allocated)
  uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_type_support_handle = {
  0,
  &uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uwb_simulation
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uwb_simulation, msg, UwbRangeArray)() {
  uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uwb_simulation, msg, UwbRange)();
  if (!uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_type_support_handle.typesupport_identifier) {
    uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &uwb_simulation__msg__UwbRangeArray__rosidl_typesupport_introspection_c__UwbRangeArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
