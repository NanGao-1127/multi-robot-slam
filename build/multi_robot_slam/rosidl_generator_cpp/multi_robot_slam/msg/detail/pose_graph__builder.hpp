// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_robot_slam:msg/PoseGraph.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__BUILDER_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_robot_slam/msg/detail/pose_graph__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_robot_slam
{

namespace msg
{

namespace builder
{

class Init_PoseGraph_num_iterations
{
public:
  explicit Init_PoseGraph_num_iterations(::multi_robot_slam::msg::PoseGraph & msg)
  : msg_(msg)
  {}
  ::multi_robot_slam::msg::PoseGraph num_iterations(::multi_robot_slam::msg::PoseGraph::_num_iterations_type arg)
  {
    msg_.num_iterations = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraph msg_;
};

class Init_PoseGraph_optimization_cost
{
public:
  explicit Init_PoseGraph_optimization_cost(::multi_robot_slam::msg::PoseGraph & msg)
  : msg_(msg)
  {}
  Init_PoseGraph_num_iterations optimization_cost(::multi_robot_slam::msg::PoseGraph::_optimization_cost_type arg)
  {
    msg_.optimization_cost = std::move(arg);
    return Init_PoseGraph_num_iterations(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraph msg_;
};

class Init_PoseGraph_is_optimized
{
public:
  explicit Init_PoseGraph_is_optimized(::multi_robot_slam::msg::PoseGraph & msg)
  : msg_(msg)
  {}
  Init_PoseGraph_optimization_cost is_optimized(::multi_robot_slam::msg::PoseGraph::_is_optimized_type arg)
  {
    msg_.is_optimized = std::move(arg);
    return Init_PoseGraph_optimization_cost(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraph msg_;
};

class Init_PoseGraph_edges
{
public:
  explicit Init_PoseGraph_edges(::multi_robot_slam::msg::PoseGraph & msg)
  : msg_(msg)
  {}
  Init_PoseGraph_is_optimized edges(::multi_robot_slam::msg::PoseGraph::_edges_type arg)
  {
    msg_.edges = std::move(arg);
    return Init_PoseGraph_is_optimized(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraph msg_;
};

class Init_PoseGraph_nodes
{
public:
  explicit Init_PoseGraph_nodes(::multi_robot_slam::msg::PoseGraph & msg)
  : msg_(msg)
  {}
  Init_PoseGraph_edges nodes(::multi_robot_slam::msg::PoseGraph::_nodes_type arg)
  {
    msg_.nodes = std::move(arg);
    return Init_PoseGraph_edges(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraph msg_;
};

class Init_PoseGraph_header
{
public:
  Init_PoseGraph_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGraph_nodes header(::multi_robot_slam::msg::PoseGraph::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PoseGraph_nodes(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraph msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_robot_slam::msg::PoseGraph>()
{
  return multi_robot_slam::msg::builder::Init_PoseGraph_header();
}

}  // namespace multi_robot_slam

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__BUILDER_HPP_
