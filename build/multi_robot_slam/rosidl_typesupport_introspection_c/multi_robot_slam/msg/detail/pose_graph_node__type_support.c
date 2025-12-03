// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from multi_robot_slam:msg/PoseGraphNode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "multi_robot_slam/msg/detail/pose_graph_node__rosidl_typesupport_introspection_c.h"
#include "multi_robot_slam/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "multi_robot_slam/msg/detail/pose_graph_node__functions.h"
#include "multi_robot_slam/msg/detail/pose_graph_node__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `timestamp`
#include "builtin_interfaces/msg/time.h"
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  multi_robot_slam__msg__PoseGraphNode__init(message_memory);
}

void multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_fini_function(void * message_memory)
{
  multi_robot_slam__msg__PoseGraphNode__fini(message_memory);
}

size_t multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__size_function__PoseGraphNode__covariance(
  const void * untyped_member)
{
  (void)untyped_member;
  return 36;
}

const void * multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__get_const_function__PoseGraphNode__covariance(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__get_function__PoseGraphNode__covariance(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__fetch_function__PoseGraphNode__covariance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__get_const_function__PoseGraphNode__covariance(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__assign_function__PoseGraphNode__covariance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__get_function__PoseGraphNode__covariance(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphNode, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphNode, node_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphNode, robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphNode, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "covariance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    36,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphNode, covariance),  // bytes offset in struct
    NULL,  // default value
    multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__size_function__PoseGraphNode__covariance,  // size() function pointer
    multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__get_const_function__PoseGraphNode__covariance,  // get_const(index) function pointer
    multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__get_function__PoseGraphNode__covariance,  // get(index) function pointer
    multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__fetch_function__PoseGraphNode__covariance,  // fetch(index, &value) function pointer
    multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__assign_function__PoseGraphNode__covariance,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam__msg__PoseGraphNode, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_members = {
  "multi_robot_slam__msg",  // message namespace
  "PoseGraphNode",  // message name
  6,  // number of fields
  sizeof(multi_robot_slam__msg__PoseGraphNode),
  multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_member_array,  // message members
  multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_init_function,  // function to initialize message memory (memory has to be allocated)
  multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_type_support_handle = {
  0,
  &multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_multi_robot_slam
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_robot_slam, msg, PoseGraphNode)() {
  multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_type_support_handle.typesupport_identifier) {
    multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &multi_robot_slam__msg__PoseGraphNode__rosidl_typesupport_introspection_c__PoseGraphNode_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
