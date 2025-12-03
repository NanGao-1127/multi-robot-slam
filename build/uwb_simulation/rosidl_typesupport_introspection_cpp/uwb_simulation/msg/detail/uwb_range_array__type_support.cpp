// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from uwb_simulation:msg/UwbRangeArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "uwb_simulation/msg/detail/uwb_range_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace uwb_simulation
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void UwbRangeArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) uwb_simulation::msg::UwbRangeArray(_init);
}

void UwbRangeArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<uwb_simulation::msg::UwbRangeArray *>(message_memory);
  typed_message->~UwbRangeArray();
}

size_t size_function__UwbRangeArray__ranges(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uwb_simulation::msg::UwbRange> *>(untyped_member);
  return member->size();
}

const void * get_const_function__UwbRangeArray__ranges(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uwb_simulation::msg::UwbRange> *>(untyped_member);
  return &member[index];
}

void * get_function__UwbRangeArray__ranges(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uwb_simulation::msg::UwbRange> *>(untyped_member);
  return &member[index];
}

void fetch_function__UwbRangeArray__ranges(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uwb_simulation::msg::UwbRange *>(
    get_const_function__UwbRangeArray__ranges(untyped_member, index));
  auto & value = *reinterpret_cast<uwb_simulation::msg::UwbRange *>(untyped_value);
  value = item;
}

void assign_function__UwbRangeArray__ranges(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uwb_simulation::msg::UwbRange *>(
    get_function__UwbRangeArray__ranges(untyped_member, index));
  const auto & value = *reinterpret_cast<const uwb_simulation::msg::UwbRange *>(untyped_value);
  item = value;
}

void resize_function__UwbRangeArray__ranges(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uwb_simulation::msg::UwbRange> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember UwbRangeArray_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation::msg::UwbRangeArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ranges",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<uwb_simulation::msg::UwbRange>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uwb_simulation::msg::UwbRangeArray, ranges),  // bytes offset in struct
    nullptr,  // default value
    size_function__UwbRangeArray__ranges,  // size() function pointer
    get_const_function__UwbRangeArray__ranges,  // get_const(index) function pointer
    get_function__UwbRangeArray__ranges,  // get(index) function pointer
    fetch_function__UwbRangeArray__ranges,  // fetch(index, &value) function pointer
    assign_function__UwbRangeArray__ranges,  // assign(index, value) function pointer
    resize_function__UwbRangeArray__ranges  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers UwbRangeArray_message_members = {
  "uwb_simulation::msg",  // message namespace
  "UwbRangeArray",  // message name
  2,  // number of fields
  sizeof(uwb_simulation::msg::UwbRangeArray),
  UwbRangeArray_message_member_array,  // message members
  UwbRangeArray_init_function,  // function to initialize message memory (memory has to be allocated)
  UwbRangeArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t UwbRangeArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &UwbRangeArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace uwb_simulation


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uwb_simulation::msg::UwbRangeArray>()
{
  return &::uwb_simulation::msg::rosidl_typesupport_introspection_cpp::UwbRangeArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uwb_simulation, msg, UwbRangeArray)() {
  return &::uwb_simulation::msg::rosidl_typesupport_introspection_cpp::UwbRangeArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
