// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_robot_slam:msg/PoseGraphEdge.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__BUILDER_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_robot_slam/msg/detail/pose_graph_edge__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_robot_slam
{

namespace msg
{

namespace builder
{

class Init_PoseGraphEdge_is_active
{
public:
  explicit Init_PoseGraphEdge_is_active(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  ::multi_robot_slam::msg::PoseGraphEdge is_active(::multi_robot_slam::msg::PoseGraphEdge::_is_active_type arg)
  {
    msg_.is_active = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_switch_variable
{
public:
  explicit Init_PoseGraphEdge_switch_variable(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  Init_PoseGraphEdge_is_active switch_variable(::multi_robot_slam::msg::PoseGraphEdge::_switch_variable_type arg)
  {
    msg_.switch_variable = std::move(arg);
    return Init_PoseGraphEdge_is_active(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_information_matrix
{
public:
  explicit Init_PoseGraphEdge_information_matrix(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  Init_PoseGraphEdge_switch_variable information_matrix(::multi_robot_slam::msg::PoseGraphEdge::_information_matrix_type arg)
  {
    msg_.information_matrix = std::move(arg);
    return Init_PoseGraphEdge_switch_variable(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_range_measurement
{
public:
  explicit Init_PoseGraphEdge_range_measurement(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  Init_PoseGraphEdge_information_matrix range_measurement(::multi_robot_slam::msg::PoseGraphEdge::_range_measurement_type arg)
  {
    msg_.range_measurement = std::move(arg);
    return Init_PoseGraphEdge_information_matrix(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_relative_pose
{
public:
  explicit Init_PoseGraphEdge_relative_pose(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  Init_PoseGraphEdge_range_measurement relative_pose(::multi_robot_slam::msg::PoseGraphEdge::_relative_pose_type arg)
  {
    msg_.relative_pose = std::move(arg);
    return Init_PoseGraphEdge_range_measurement(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_target_robot_id
{
public:
  explicit Init_PoseGraphEdge_target_robot_id(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  Init_PoseGraphEdge_relative_pose target_robot_id(::multi_robot_slam::msg::PoseGraphEdge::_target_robot_id_type arg)
  {
    msg_.target_robot_id = std::move(arg);
    return Init_PoseGraphEdge_relative_pose(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_source_robot_id
{
public:
  explicit Init_PoseGraphEdge_source_robot_id(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  Init_PoseGraphEdge_target_robot_id source_robot_id(::multi_robot_slam::msg::PoseGraphEdge::_source_robot_id_type arg)
  {
    msg_.source_robot_id = std::move(arg);
    return Init_PoseGraphEdge_target_robot_id(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_target_node_id
{
public:
  explicit Init_PoseGraphEdge_target_node_id(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  Init_PoseGraphEdge_source_robot_id target_node_id(::multi_robot_slam::msg::PoseGraphEdge::_target_node_id_type arg)
  {
    msg_.target_node_id = std::move(arg);
    return Init_PoseGraphEdge_source_robot_id(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_source_node_id
{
public:
  explicit Init_PoseGraphEdge_source_node_id(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  Init_PoseGraphEdge_target_node_id source_node_id(::multi_robot_slam::msg::PoseGraphEdge::_source_node_id_type arg)
  {
    msg_.source_node_id = std::move(arg);
    return Init_PoseGraphEdge_target_node_id(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_edge_type
{
public:
  explicit Init_PoseGraphEdge_edge_type(::multi_robot_slam::msg::PoseGraphEdge & msg)
  : msg_(msg)
  {}
  Init_PoseGraphEdge_source_node_id edge_type(::multi_robot_slam::msg::PoseGraphEdge::_edge_type_type arg)
  {
    msg_.edge_type = std::move(arg);
    return Init_PoseGraphEdge_source_node_id(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

class Init_PoseGraphEdge_header
{
public:
  Init_PoseGraphEdge_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGraphEdge_edge_type header(::multi_robot_slam::msg::PoseGraphEdge::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PoseGraphEdge_edge_type(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphEdge msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_robot_slam::msg::PoseGraphEdge>()
{
  return multi_robot_slam::msg::builder::Init_PoseGraphEdge_header();
}

}  // namespace multi_robot_slam

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__BUILDER_HPP_
