// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from multi_robot_slam:msg/MapMergeStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "multi_robot_slam/msg/detail/map_merge_status__rosidl_typesupport_introspection_c.h"
#include "multi_robot_slam/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "multi_robot_slam/msg/detail/map_merge_status__functions.h"
#include "multi_robot_slam/msg/detail/map_merge_status__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `robot_ids`
#include "rosidl_runtime_c/string_functions.h"
// Member `transforms`
#include "geometry_msgs/msg/transform.h"
// Member `transforms`
#include "geometry_msgs/msg/detail/transform__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  multi_robot_slam__msg__MapMergeStatus__init(message_memory);
}

void multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_fini_function(void * message_memory)
{
  multi_robot_slam__msg__MapMergeStatus__fini(message_memory);
}

size_t multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__size_function__MapMergeStatus__robot_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_const_function__MapMergeStatus__robot_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_function__MapMergeStatus__robot_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__fetch_function__MapMergeStatus__robot_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_const_function__MapMergeStatus__robot_ids(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__assign_function__MapMergeStatus__robot_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_function__MapMergeStatus__robot_ids(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__resize_function__MapMergeStatus__robot_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__size_function__MapMergeStatus__transforms(
  const void * untyped_member)
{
  const geometry_msgs__msg__Transform__Sequence * member =
    (const geometry_msgs__msg__Transform__Sequence *)(untyped_member);
  return member->size;
}

const void * multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_const_function__MapMergeStatus__transforms(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Transform__Sequence * member =
    (const geometry_msgs__msg__Transform__Sequence *)(untyped_member);
  return &member->data[index];
}

void * multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_function__MapMergeStatus__transforms(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Transform__Sequence * member =
    (geometry_msgs__msg__Transform__Sequence *)(untyped_member);
  return &member->data[index];
}

void multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__fetch_function__MapMergeStatus__transforms(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Transform * item =
    ((const geometry_msgs__msg__Transform *)
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_const_function__MapMergeStatus__transforms(untyped_member, index));
  geometry_msgs__msg__Transform * value =
    (geometry_msgs__msg__Transform *)(untyped_value);
  *value = *item;
}

void multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__assign_function__MapMergeStatus__transforms(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Transform * item =
    ((geometry_msgs__msg__Transform *)
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_function__MapMergeStatus__transforms(untyped_member, index));
  const geometry_msgs__msg__Transform * value =
    (const geometry_msgs__msg__Transform *)(untyped_value);
  *item = *value;
}

bool multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__resize_function__MapMergeStatus__transforms(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Transform__Sequence * member =
    (geometry_msgs__msg__Transform__Sequence *)(untyped_member);
  geometry_msgs__msg__Transform__Sequence__fini(member);
  return geometry_msgs__msg__Transform__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__MapMergeStatus, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "maps_aligned",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__MapMergeStatus, maps_aligned),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "merge_successful",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__MapMergeStatus, merge_successful),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_robots",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__MapMergeStatus, num_robots),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__MapMergeStatus, robot_ids),  // bytes offset in struct
    NULL,  // default value
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__size_function__MapMergeStatus__robot_ids,  // size() function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_const_function__MapMergeStatus__robot_ids,  // get_const(index) function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_function__MapMergeStatus__robot_ids,  // get(index) function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__fetch_function__MapMergeStatus__robot_ids,  // fetch(index, &value) function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__assign_function__MapMergeStatus__robot_ids,  // assign(index, value) function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__resize_function__MapMergeStatus__robot_ids  // resize(index) function pointer
  },
  {
    "transforms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__MapMergeStatus, transforms),  // bytes offset in struct
    NULL,  // default value
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__size_function__MapMergeStatus__transforms,  // size() function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_const_function__MapMergeStatus__transforms,  // get_const(index) function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__get_function__MapMergeStatus__transforms,  // get(index) function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__fetch_function__MapMergeStatus__transforms,  // fetch(index, &value) function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__assign_function__MapMergeStatus__transforms,  // assign(index, value) function pointer
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__resize_function__MapMergeStatus__transforms  // resize(index) function pointer
  },
  {
    "alignment_score",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__MapMergeStatus, alignment_score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "overlap_ratio",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__MapMergeStatus, overlap_ratio),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_members = {
  "multi_robot_slam__msg",  // message namespace
  "MapMergeStatus",  // message name
  8,  // number of fields
  sizeof(multi_robot_slam__msg__MapMergeStatus),
  multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_member_array,  // message members
  multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_type_support_handle = {
  0,
  &multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_multi_robot_slam
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_robot_slam, msg, MapMergeStatus)() {
  multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Transform)();
  if (!multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_type_support_handle.typesupport_identifier) {
    multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &multi_robot_slam__msg__MapMergeStatus__rosidl_typesupport_introspection_c__MapMergeStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
