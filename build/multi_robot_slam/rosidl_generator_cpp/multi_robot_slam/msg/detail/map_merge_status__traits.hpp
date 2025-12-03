// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_robot_slam:msg/MapMergeStatus.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__TRAITS_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_robot_slam/msg/detail/map_merge_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'transforms'
#include "geometry_msgs/msg/detail/transform__traits.hpp"

namespace multi_robot_slam
{

namespace msg
{

inline void to_flow_style_yaml(
  const MapMergeStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: maps_aligned
  {
    out << "maps_aligned: ";
    rosidl_generator_traits::value_to_yaml(msg.maps_aligned, out);
    out << ", ";
  }

  // member: merge_successful
  {
    out << "merge_successful: ";
    rosidl_generator_traits::value_to_yaml(msg.merge_successful, out);
    out << ", ";
  }

  // member: num_robots
  {
    out << "num_robots: ";
    rosidl_generator_traits::value_to_yaml(msg.num_robots, out);
    out << ", ";
  }

  // member: robot_ids
  {
    if (msg.robot_ids.size() == 0) {
      out << "robot_ids: []";
    } else {
      out << "robot_ids: [";
      size_t pending_items = msg.robot_ids.size();
      for (auto item : msg.robot_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: transforms
  {
    if (msg.transforms.size() == 0) {
      out << "transforms: []";
    } else {
      out << "transforms: [";
      size_t pending_items = msg.transforms.size();
      for (auto item : msg.transforms) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: alignment_score
  {
    out << "alignment_score: ";
    rosidl_generator_traits::value_to_yaml(msg.alignment_score, out);
    out << ", ";
  }

  // member: overlap_ratio
  {
    out << "overlap_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.overlap_ratio, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MapMergeStatus & msg,
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

  // member: maps_aligned
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "maps_aligned: ";
    rosidl_generator_traits::value_to_yaml(msg.maps_aligned, out);
    out << "\n";
  }

  // member: merge_successful
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "merge_successful: ";
    rosidl_generator_traits::value_to_yaml(msg.merge_successful, out);
    out << "\n";
  }

  // member: num_robots
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_robots: ";
    rosidl_generator_traits::value_to_yaml(msg.num_robots, out);
    out << "\n";
  }

  // member: robot_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_ids.size() == 0) {
      out << "robot_ids: []\n";
    } else {
      out << "robot_ids:\n";
      for (auto item : msg.robot_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: transforms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.transforms.size() == 0) {
      out << "transforms: []\n";
    } else {
      out << "transforms:\n";
      for (auto item : msg.transforms) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: alignment_score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alignment_score: ";
    rosidl_generator_traits::value_to_yaml(msg.alignment_score, out);
    out << "\n";
  }

  // member: overlap_ratio
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "overlap_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.overlap_ratio, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MapMergeStatus & msg, bool use_flow_style = false)
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

}  // namespace multi_robot_slam

namespace rosidl_generator_traits
{

[[deprecated("use multi_robot_slam::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const multi_robot_slam::msg::MapMergeStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_robot_slam::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_robot_slam::msg::to_yaml() instead")]]
inline std::string to_yaml(const multi_robot_slam::msg::MapMergeStatus & msg)
{
  return multi_robot_slam::msg::to_yaml(msg);
}

template<>
inline const char * data_type<multi_robot_slam::msg::MapMergeStatus>()
{
  return "multi_robot_slam::msg::MapMergeStatus";
}

template<>
inline const char * name<multi_robot_slam::msg::MapMergeStatus>()
{
  return "multi_robot_slam/msg/MapMergeStatus";
}

template<>
struct has_fixed_size<multi_robot_slam::msg::MapMergeStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_robot_slam::msg::MapMergeStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_robot_slam::msg::MapMergeStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__TRAITS_HPP_
