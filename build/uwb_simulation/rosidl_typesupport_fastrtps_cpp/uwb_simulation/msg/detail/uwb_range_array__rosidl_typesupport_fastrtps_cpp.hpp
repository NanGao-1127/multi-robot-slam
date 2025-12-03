// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from uwb_simulation:msg/UwbRangeArray.idl
// generated code does not contain a copyright notice

#ifndef UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "uwb_simulation/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "uwb_simulation/msg/detail/uwb_range_array__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace uwb_simulation
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uwb_simulation
cdr_serialize(
  const uwb_simulation::msg::UwbRangeArray & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uwb_simulation
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  uwb_simulation::msg::UwbRangeArray & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uwb_simulation
get_serialized_size(
  const uwb_simulation::msg::UwbRangeArray & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uwb_simulation
max_serialized_size_UwbRangeArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace uwb_simulation

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uwb_simulation
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uwb_simulation, msg, UwbRangeArray)();

#ifdef __cplusplus
}
#endif

#endif  // UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
