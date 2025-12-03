// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_robot_slam:msg/PoseGraph.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__TRAITS_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_robot_slam/msg/detail/pose_graph__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'nodes'
#include "multi_robot_slam/msg/detail/pose_graph_node__traits.hpp"
// Member 'edges'
#include "multi_robot_slam/msg/detail/pose_graph_edge__traits.hpp"

namespace multi_robot_slam
{

namespace msg
{

inline void to_flow_style_yaml(
  const PoseGraph & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: nodes
  {
    if (msg.nodes.size() == 0) {
      out << "nodes: []";
    } else {
      out << "nodes: [";
      size_t pending_items = msg.nodes.size();
      for (auto item : msg.nodes) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: edges
  {
    if (msg.edges.size() == 0) {
      out << "edges: []";
    } else {
      out << "edges: [";
      size_t pending_items = msg.edges.size();
      for (auto item : msg.edges) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: is_optimized
  {
    out << "is_optimized: ";
    rosidl_generator_traits::value_to_yaml(msg.is_optimized, out);
    out << ", ";
  }

  // member: optimization_cost
  {
    out << "optimization_cost: ";
    rosidl_generator_traits::value_to_yaml(msg.optimization_cost, out);
    out << ", ";
  }

  // member: num_iterations
  {
    out << "num_iterations: ";
    rosidl_generator_traits::value_to_yaml(msg.num_iterations, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGraph & msg,
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

  // member: nodes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.nodes.size() == 0) {
      out << "nodes: []\n";
    } else {
      out << "nodes:\n";
      for (auto item : msg.nodes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: edges
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.edges.size() == 0) {
      out << "edges: []\n";
    } else {
      out << "edges:\n";
      for (auto item : msg.edges) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: is_optimized
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_optimized: ";
    rosidl_generator_traits::value_to_yaml(msg.is_optimized, out);
    out << "\n";
  }

  // member: optimization_cost
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "optimization_cost: ";
    rosidl_generator_traits::value_to_yaml(msg.optimization_cost, out);
    out << "\n";
  }

  // member: num_iterations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_iterations: ";
    rosidl_generator_traits::value_to_yaml(msg.num_iterations, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGraph & msg, bool use_flow_style = false)
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
  const multi_robot_slam::msg::PoseGraph & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_robot_slam::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_robot_slam::msg::to_yaml() instead")]]
inline std::string to_yaml(const multi_robot_slam::msg::PoseGraph & msg)
{
  return multi_robot_slam::msg::to_yaml(msg);
}

template<>
inline const char * data_type<multi_robot_slam::msg::PoseGraph>()
{
  return "multi_robot_slam::msg::PoseGraph";
}

template<>
inline const char * name<multi_robot_slam::msg::PoseGraph>()
{
  return "multi_robot_slam/msg/PoseGraph";
}

template<>
struct has_fixed_size<multi_robot_slam::msg::PoseGraph>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_robot_slam::msg::PoseGraph>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_robot_slam::msg::PoseGraph>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__TRAITS_HPP_
