// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_robot_slam:msg/PoseGraphEdge.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__TRAITS_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_robot_slam/msg/detail/pose_graph_edge__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'relative_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace multi_robot_slam
{

namespace msg
{

inline void to_flow_style_yaml(
  const PoseGraphEdge & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: edge_type
  {
    out << "edge_type: ";
    rosidl_generator_traits::value_to_yaml(msg.edge_type, out);
    out << ", ";
  }

  // member: source_node_id
  {
    out << "source_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.source_node_id, out);
    out << ", ";
  }

  // member: target_node_id
  {
    out << "target_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_node_id, out);
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

  // member: relative_pose
  {
    out << "relative_pose: ";
    to_flow_style_yaml(msg.relative_pose, out);
    out << ", ";
  }

  // member: range_measurement
  {
    out << "range_measurement: ";
    rosidl_generator_traits::value_to_yaml(msg.range_measurement, out);
    out << ", ";
  }

  // member: information_matrix
  {
    if (msg.information_matrix.size() == 0) {
      out << "information_matrix: []";
    } else {
      out << "information_matrix: [";
      size_t pending_items = msg.information_matrix.size();
      for (auto item : msg.information_matrix) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: switch_variable
  {
    out << "switch_variable: ";
    rosidl_generator_traits::value_to_yaml(msg.switch_variable, out);
    out << ", ";
  }

  // member: is_active
  {
    out << "is_active: ";
    rosidl_generator_traits::value_to_yaml(msg.is_active, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGraphEdge & msg,
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

  // member: edge_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "edge_type: ";
    rosidl_generator_traits::value_to_yaml(msg.edge_type, out);
    out << "\n";
  }

  // member: source_node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.source_node_id, out);
    out << "\n";
  }

  // member: target_node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_node_id, out);
    out << "\n";
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

  // member: relative_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative_pose:\n";
    to_block_style_yaml(msg.relative_pose, out, indentation + 2);
  }

  // member: range_measurement
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_measurement: ";
    rosidl_generator_traits::value_to_yaml(msg.range_measurement, out);
    out << "\n";
  }

  // member: information_matrix
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.information_matrix.size() == 0) {
      out << "information_matrix: []\n";
    } else {
      out << "information_matrix:\n";
      for (auto item : msg.information_matrix) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: switch_variable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "switch_variable: ";
    rosidl_generator_traits::value_to_yaml(msg.switch_variable, out);
    out << "\n";
  }

  // member: is_active
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_active: ";
    rosidl_generator_traits::value_to_yaml(msg.is_active, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGraphEdge & msg, bool use_flow_style = false)
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
  const multi_robot_slam::msg::PoseGraphEdge & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_robot_slam::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_robot_slam::msg::to_yaml() instead")]]
inline std::string to_yaml(const multi_robot_slam::msg::PoseGraphEdge & msg)
{
  return multi_robot_slam::msg::to_yaml(msg);
}

template<>
inline const char * data_type<multi_robot_slam::msg::PoseGraphEdge>()
{
  return "multi_robot_slam::msg::PoseGraphEdge";
}

template<>
inline const char * name<multi_robot_slam::msg::PoseGraphEdge>()
{
  return "multi_robot_slam/msg/PoseGraphEdge";
}

template<>
struct has_fixed_size<multi_robot_slam::msg::PoseGraphEdge>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_robot_slam::msg::PoseGraphEdge>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_robot_slam::msg::PoseGraphEdge>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__TRAITS_HPP_
