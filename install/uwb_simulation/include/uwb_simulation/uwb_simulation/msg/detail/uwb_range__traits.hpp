// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uwb_simulation:msg/UwbRange.idl
// generated code does not contain a copyright notice

#ifndef UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__TRAITS_HPP_
#define UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "uwb_simulation/msg/detail/uwb_range__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'measurement_time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace uwb_simulation
{

namespace msg
{

inline void to_flow_style_yaml(
  const UwbRange & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: source_robot_id
  {
    out << "source_robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.source_robot_id, out);
    out << ", ";
  }

  // member: target_robot_id
  {
    out << "target_robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_robot_id, out);
    out << ", ";
  }

  // member: range
  {
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << ", ";
  }

  // member: range_std
  {
    out << "range_std: ";
    rosidl_generator_traits::value_to_yaml(msg.range_std, out);
    out << ", ";
  }

  // member: measurement_time
  {
    out << "measurement_time: ";
    to_flow_style_yaml(msg.measurement_time, out);
    out << ", ";
  }

  // member: quality
  {
    out << "quality: ";
    rosidl_generator_traits::value_to_yaml(msg.quality, out);
    out << ", ";
  }

  // member: is_valid
  {
    out << "is_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.is_valid, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UwbRange & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: source_robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source_robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.source_robot_id, out);
    out << "\n";
  }

  // member: target_robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_robot_id, out);
    out << "\n";
  }

  // member: range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << "\n";
  }

  // member: range_std
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_std: ";
    rosidl_generator_traits::value_to_yaml(msg.range_std, out);
    out << "\n";
  }

  // member: measurement_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "measurement_time:\n";
    to_block_style_yaml(msg.measurement_time, out, indentation + 2);
  }

  // member: quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quality: ";
    rosidl_generator_traits::value_to_yaml(msg.quality, out);
    out << "\n";
  }

  // member: is_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.is_valid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UwbRange & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace uwb_simulation

namespace rosidl_generator_traits
{

[[deprecated("use uwb_simulation::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const uwb_simulation::msg::UwbRange & msg,
  std::ostream & out, size_t indentation = 0)
{
  uwb_simulation::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use uwb_simulation::msg::to_yaml() instead")]]
inline std::string to_yaml(const uwb_simulation::msg::UwbRange & msg)
{
  return uwb_simulation::msg::to_yaml(msg);
}

template<>
inline const char * data_type<uwb_simulation::msg::UwbRange>()
{
  return "uwb_simulation::msg::UwbRange";
}

template<>
inline const char * name<uwb_simulation::msg::UwbRange>()
{
  return "uwb_simulation/msg/UwbRange";
}

template<>
struct has_fixed_size<uwb_simulation::msg::UwbRange>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<uwb_simulation::msg::UwbRange>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<uwb_simulation::msg::UwbRange>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__TRAITS_HPP_
