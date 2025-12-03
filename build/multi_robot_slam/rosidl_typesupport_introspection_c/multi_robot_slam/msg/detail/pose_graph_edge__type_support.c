// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from multi_robot_slam:msg/PoseGraphEdge.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "multi_robot_slam/msg/detail/pose_graph_edge__rosidl_typesupport_introspection_c.h"
#include "multi_robot_slam/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "multi_robot_slam/msg/detail/pose_graph_edge__functions.h"
#include "multi_robot_slam/msg/detail/pose_graph_edge__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `source_robot_id`
// Member `target_robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `relative_pose`
#include "geometry_msgs/msg/pose.h"
// Member `relative_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  multi_robot_slam__msg__PoseGraphEdge__init(message_memory);
}

void multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_fini_function(void * message_memory)
{
  multi_robot_slam__msg__PoseGraphEdge__fini(message_memory);
}

size_t multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__size_function__PoseGraphEdge__information_matrix(
  const void * untyped_member)
{
  (void)untyped_member;
  return 36;
}

const void * multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__get_const_function__PoseGraphEdge__information_matrix(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__get_function__PoseGraphEdge__information_matrix(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__fetch_function__PoseGraphEdge__information_matrix(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__get_const_function__PoseGraphEdge__information_matrix(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__assign_function__PoseGraphEdge__information_matrix(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__get_function__PoseGraphEdge__information_matrix(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_member_array[11] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphEdge, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "edge_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphEdge, edge_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "source_node_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphEdge, source_node_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_node_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphEdge, target_node_id),  // bytes offset in struct
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
    offsetof(multi_robot_slam__msg__PoseGraphEdge, source_robot_id),  // bytes offset in struct
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
    offsetof(multi_robot_slam__msg__PoseGraphEdge, target_robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "relative_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphEdge, relative_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range_measurement",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphEdge, range_measurement),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "information_matrix",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    36,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphEdge, information_matrix),  // bytes offset in struct
    NULL,  // default value
    multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__size_function__PoseGraphEdge__information_matrix,  // size() function pointer
    multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__get_const_function__PoseGraphEdge__information_matrix,  // get_const(index) function pointer
    multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__get_function__PoseGraphEdge__information_matrix,  // get(index) function pointer
    multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__fetch_function__PoseGraphEdge__information_matrix,  // fetch(index, &value) function pointer
    multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__assign_function__PoseGraphEdge__information_matrix,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "switch_variable",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphEdge, switch_variable),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_active",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphEdge, is_active),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_members = {
  "multi_robot_slam__msg",  // message namespace
  "PoseGraphEdge",  // message name
  11,  // number of fields
  sizeof(multi_robot_slam__msg__PoseGraphEdge),
  multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_member_array,  // message members
  multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_init_function,  // function to initialize message memory (memory has to be allocated)
  multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_type_support_handle = {
  0,
  &multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_multi_robot_slam
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_robot_slam, msg, PoseGraphEdge)() {
  multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_type_support_handle.typesupport_identifier) {
    multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &multi_robot_slam__msg__PoseGraphEdge__rosidl_typesupport_introspection_c__PoseGraphEdge_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
