// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from uwb_simulation:msg/UwbRange.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "uwb_simulation/msg/detail/uwb_range__rosidl_typesupport_introspection_c.h"
#include "uwb_simulation/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "uwb_simulation/msg/detail/uwb_range__functions.h"
#include "uwb_simulation/msg/detail/uwb_range__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `source_robot_id`
// Member `target_robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `measurement_time`
#include "builtin_interfaces/msg/time.h"
// Member `measurement_time`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uwb_simulation__msg__UwbRange__init(message_memory);
}

void uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_fini_function(void * message_memory)
{
  uwb_simulation__msg__UwbRange__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRange, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "source_robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRange, source_robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRange, target_robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRange, range),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range_std",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRange, range_std),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "measurement_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRange, measurement_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "quality",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRange, quality),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation__msg__UwbRange, is_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_members = {
  "uwb_simulation__msg",  // message namespace
  "UwbRange",  // message name
  8,  // number of fields
  sizeof(uwb_simulation__msg__UwbRange),
  uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_member_array,  // message members
  uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_init_function,  // function to initialize message memory (memory has to be allocated)
  uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_type_support_handle = {
  0,
  &uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uwb_simulation
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uwb_simulation, msg, UwbRange)() {
  uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_type_support_handle.typesupport_identifier) {
    uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &uwb_simulation__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
