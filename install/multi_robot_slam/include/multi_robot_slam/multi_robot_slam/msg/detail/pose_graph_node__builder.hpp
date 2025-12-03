// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_robot_slam:msg/PoseGraphNode.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__BUILDER_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_robot_slam/msg/detail/pose_graph_node__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_robot_slam
{

namespace msg
{

namespace builder
{

class Init_PoseGraphNode_timestamp
{
public:
  explicit Init_PoseGraphNode_timestamp(::multi_robot_slam::msg::PoseGraphNode & msg)
  : msg_(msg)
  {}
  ::multi_robot_slam::msg::PoseGraphNode timestamp(::multi_robot_slam::msg::PoseGraphNode::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphNode msg_;
};

class Init_PoseGraphNode_covariance
{
public:
  explicit Init_PoseGraphNode_covariance(::multi_robot_slam::msg::PoseGraphNode & msg)
  : msg_(msg)
  {}
  Init_PoseGraphNode_timestamp covariance(::multi_robot_slam::msg::PoseGraphNode::_covariance_type arg)
  {
    msg_.covariance = std::move(arg);
    return Init_PoseGraphNode_timestamp(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphNode msg_;
};

class Init_PoseGraphNode_pose
{
public:
  explicit Init_PoseGraphNode_pose(::multi_robot_slam::msg::PoseGraphNode & msg)
  : msg_(msg)
  {}
  Init_PoseGraphNode_covariance pose(::multi_robot_slam::msg::PoseGraphNode::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_PoseGraphNode_covariance(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphNode msg_;
};

class Init_PoseGraphNode_robot_id
{
public:
  explicit Init_PoseGraphNode_robot_id(::multi_robot_slam::msg::PoseGraphNode & msg)
  : msg_(msg)
  {}
  Init_PoseGraphNode_pose robot_id(::multi_robot_slam::msg::PoseGraphNode::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_PoseGraphNode_pose(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphNode msg_;
};

class Init_PoseGraphNode_node_id
{
public:
  explicit Init_PoseGraphNode_node_id(::multi_robot_slam::msg::PoseGraphNode & msg)
  : msg_(msg)
  {}
  Init_PoseGraphNode_robot_id node_id(::multi_robot_slam::msg::PoseGraphNode::_node_id_type arg)
  {
    msg_.node_id = std::move(arg);
    return Init_PoseGraphNode_robot_id(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphNode msg_;
};

class Init_PoseGraphNode_header
{
public:
  Init_PoseGraphNode_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGraphNode_node_id header(::multi_robot_slam::msg::PoseGraphNode::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PoseGraphNode_node_id(msg_);
  }

private:
  ::multi_robot_slam::msg::PoseGraphNode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_robot_slam::msg::PoseGraphNode>()
{
  return multi_robot_slam::msg::builder::Init_PoseGraphNode_header();
}

}  // namespace multi_robot_slam

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__BUILDER_HPP_
