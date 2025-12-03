// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from multi_robot_slam:msg/PoseGraph.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "multi_robot_slam/msg/detail/pose_graph__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace multi_robot_slam
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PoseGraph_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) multi_robot_slam::msg::PoseGraph(_init);
}

void PoseGraph_fini_function(void * message_memory)
{
  auto typed_message = static_cast<multi_robot_slam::msg::PoseGraph *>(message_memory);
  typed_message->~PoseGraph();
}

size_t size_function__PoseGraph__nodes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<multi_robot_slam::msg::PoseGraphNode> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PoseGraph__nodes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<multi_robot_slam::msg::PoseGraphNode> *>(untyped_member);
  return &member[index];
}

void * get_function__PoseGraph__nodes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<multi_robot_slam::msg::PoseGraphNode> *>(untyped_member);
  return &member[index];
}

void fetch_function__PoseGraph__nodes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const multi_robot_slam::msg::PoseGraphNode *>(
    get_const_function__PoseGraph__nodes(untyped_member, index));
  auto & value = *reinterpret_cast<multi_robot_slam::msg::PoseGraphNode *>(untyped_value);
  value = item;
}

void assign_function__PoseGraph__nodes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<multi_robot_slam::msg::PoseGraphNode *>(
    get_function__PoseGraph__nodes(untyped_member, index));
  const auto & value = *reinterpret_cast<const multi_robot_slam::msg::PoseGraphNode *>(untyped_value);
  item = value;
}

void resize_function__PoseGraph__nodes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<multi_robot_slam::msg::PoseGraphNode> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PoseGraph__edges(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<multi_robot_slam::msg::PoseGraphEdge> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PoseGraph__edges(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<multi_robot_slam::msg::PoseGraphEdge> *>(untyped_member);
  return &member[index];
}

void * get_function__PoseGraph__edges(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<multi_robot_slam::msg::PoseGraphEdge> *>(untyped_member);
  return &member[index];
}

void fetch_function__PoseGraph__edges(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const multi_robot_slam::msg::PoseGraphEdge *>(
    get_const_function__PoseGraph__edges(untyped_member, index));
  auto & value = *reinterpret_cast<multi_robot_slam::msg::PoseGraphEdge *>(untyped_value);
  value = item;
}

void assign_function__PoseGraph__edges(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<multi_robot_slam::msg::PoseGraphEdge *>(
    get_function__PoseGraph__edges(untyped_member, index));
  const auto & value = *reinterpret_cast<const multi_robot_slam::msg::PoseGraphEdge *>(untyped_value);
  item = value;
}

void resize_function__PoseGraph__edges(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<multi_robot_slam::msg::PoseGraphEdge> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PoseGraph_message_member_array[6] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam::msg::PoseGraph, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "nodes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<multi_robot_slam::msg::PoseGraphNode>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam::msg::PoseGraph, nodes),  // bytes offset in struct
    nullptr,  // default value
    size_function__PoseGraph__nodes,  // size() function pointer
    get_const_function__PoseGraph__nodes,  // get_const(index) function pointer
    get_function__PoseGraph__nodes,  // get(index) function pointer
    fetch_function__PoseGraph__nodes,  // fetch(index, &value) function pointer
    assign_function__PoseGraph__nodes,  // assign(index, value) function pointer
    resize_function__PoseGraph__nodes  // resize(index) function pointer
  },
  {
    "edges",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<multi_robot_slam::msg::PoseGraphEdge>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam::msg::PoseGraph, edges),  // bytes offset in struct
    nullptr,  // default value
    size_function__PoseGraph__edges,  // size() function pointer
    get_const_function__PoseGraph__edges,  // get_const(index) function pointer
    get_function__PoseGraph__edges,  // get(index) function pointer
    fetch_function__PoseGraph__edges,  // fetch(index, &value) function pointer
    assign_function__PoseGraph__edges,  // assign(index, value) function pointer
    resize_function__PoseGraph__edges  // resize(index) function pointer
  },
  {
    "is_optimized",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam::msg::PoseGraph, is_optimized),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "optimization_cost",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam::msg::PoseGraph, optimization_cost),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_iterations",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_robot_slam::msg::PoseGraph, num_iterations),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PoseGraph_message_members = {
  "multi_robot_slam::msg",  // message namespace
  "PoseGraph",  // message name
  6,  // number of fields
  sizeof(multi_robot_slam::msg::PoseGraph),
  PoseGraph_message_member_array,  // message members
  PoseGraph_init_function,  // function to initialize message memory (memory has to be allocated)
  PoseGraph_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PoseGraph_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PoseGraph_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace multi_robot_slam


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_robot_slam::msg::PoseGraph>()
{
  return &::multi_robot_slam::msg::rosidl_typesupport_introspection_cpp::PoseGraph_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_robot_slam, msg, PoseGraph)() {
  return &::multi_robot_slam::msg::rosidl_typesupport_introspection_cpp::PoseGraph_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
