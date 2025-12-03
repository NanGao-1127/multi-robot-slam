// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_robot_slam:msg/PoseGraphNode.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__TRAITS_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_robot_slam/msg/detail/pose_graph_node__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace multi_robot_slam
{

namespace msg
{

inline void to_flow_style_yaml(
  const PoseGraphNode & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: node_id
  {
    out << "node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.node_id, out);
    out << ", ";
  }

  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: covariance
  {
    if (msg.covariance.size() == 0) {
      out << "covariance: []";
    } else {
      out << "covariance: [";
      size_t pending_items = msg.covariance.size();
      for (auto item : msg.covariance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    to_flow_style_yaml(msg.timestamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGraphNode & msg,
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

  // member: node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.node_id, out);
    out << "\n";
  }

  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: covariance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.covariance.size() == 0) {
      out << "covariance: []\n";
    } else {
      out << "covariance:\n";
      for (auto item : msg.covariance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp:\n";
    to_block_style_yaml(msg.timestamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGraphNode & msg, bool use_flow_style = false)
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
  const multi_robot_slam::msg::PoseGraphNode & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_robot_slam::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_robot_slam::msg::to_yaml() instead")]]
inline std::string to_yaml(const multi_robot_slam::msg::PoseGraphNode & msg)
{
  return multi_robot_slam::msg::to_yaml(msg);
}

template<>
inline const char * data_type<multi_robot_slam::msg::PoseGraphNode>()
{
  return "multi_robot_slam::msg::PoseGraphNode";
}

template<>
inline const char * name<multi_robot_slam::msg::PoseGraphNode>()
{
  return "multi_robot_slam/msg/PoseGraphNode";
}

template<>
struct has_fixed_size<multi_robot_slam::msg::PoseGraphNode>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_robot_slam::msg::PoseGraphNode>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_robot_slam::msg::PoseGraphNode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__TRAITS_HPP_
