// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uwb_simulation:msg/UwbRangeArray.idl
// generated code does not contain a copyright notice

#ifndef UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__TRAITS_HPP_
#define UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "uwb_simulation/msg/detail/uwb_range_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'ranges'
#include "uwb_simulation/msg/detail/uwb_range__traits.hpp"

namespace uwb_simulation
{

namespace msg
{

inline void to_flow_style_yaml(
  const UwbRangeArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: ranges
  {
    if (msg.ranges.size() == 0) {
      out << "ranges: []";
    } else {
      out << "ranges: [";
      size_t pending_items = msg.ranges.size();
      for (auto item : msg.ranges) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UwbRangeArray & msg,
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

  // member: ranges
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ranges.size() == 0) {
      out << "ranges: []\n";
    } else {
      out << "ranges:\n";
      for (auto item : msg.ranges) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UwbRangeArray & msg, bool use_flow_style = false)
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
  const uwb_simulation::msg::UwbRangeArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  uwb_simulation::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use uwb_simulation::msg::to_yaml() instead")]]
inline std::string to_yaml(const uwb_simulation::msg::UwbRangeArray & msg)
{
  return uwb_simulation::msg::to_yaml(msg);
}

template<>
inline const char * data_type<uwb_simulation::msg::UwbRangeArray>()
{
  return "uwb_simulation::msg::UwbRangeArray";
}

template<>
inline const char * name<uwb_simulation::msg::UwbRangeArray>()
{
  return "uwb_simulation/msg/UwbRangeArray";
}

template<>
struct has_fixed_size<uwb_simulation::msg::UwbRangeArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<uwb_simulation::msg::UwbRangeArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<uwb_simulation::msg::UwbRangeArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__TRAITS_HPP_
