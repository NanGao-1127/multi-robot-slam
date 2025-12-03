// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_robot_slam:msg/MapMergeStatus.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__BUILDER_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_robot_slam/msg/detail/map_merge_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_robot_slam
{

namespace msg
{

namespace builder
{

class Init_MapMergeStatus_overlap_ratio
{
public:
  explicit Init_MapMergeStatus_overlap_ratio(::multi_robot_slam::msg::MapMergeStatus & msg)
  : msg_(msg)
  {}
  ::multi_robot_slam::msg::MapMergeStatus overlap_ratio(::multi_robot_slam::msg::MapMergeStatus::_overlap_ratio_type arg)
  {
    msg_.overlap_ratio = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_robot_slam::msg::MapMergeStatus msg_;
};

class Init_MapMergeStatus_alignment_score
{
public:
  explicit Init_MapMergeStatus_alignment_score(::multi_robot_slam::msg::MapMergeStatus & msg)
  : msg_(msg)
  {}
  Init_MapMergeStatus_overlap_ratio alignment_score(::multi_robot_slam::msg::MapMergeStatus::_alignment_score_type arg)
  {
    msg_.alignment_score = std::move(arg);
    return Init_MapMergeStatus_overlap_ratio(msg_);
  }

private:
  ::multi_robot_slam::msg::MapMergeStatus msg_;
};

class Init_MapMergeStatus_transforms
{
public:
  explicit Init_MapMergeStatus_transforms(::multi_robot_slam::msg::MapMergeStatus & msg)
  : msg_(msg)
  {}
  Init_MapMergeStatus_alignment_score transforms(::multi_robot_slam::msg::MapMergeStatus::_transforms_type arg)
  {
    msg_.transforms = std::move(arg);
    return Init_MapMergeStatus_alignment_score(msg_);
  }

private:
  ::multi_robot_slam::msg::MapMergeStatus msg_;
};

class Init_MapMergeStatus_robot_ids
{
public:
  explicit Init_MapMergeStatus_robot_ids(::multi_robot_slam::msg::MapMergeStatus & msg)
  : msg_(msg)
  {}
  Init_MapMergeStatus_transforms robot_ids(::multi_robot_slam::msg::MapMergeStatus::_robot_ids_type arg)
  {
    msg_.robot_ids = std::move(arg);
    return Init_MapMergeStatus_transforms(msg_);
  }

private:
  ::multi_robot_slam::msg::MapMergeStatus msg_;
};

class Init_MapMergeStatus_num_robots
{
public:
  explicit Init_MapMergeStatus_num_robots(::multi_robot_slam::msg::MapMergeStatus & msg)
  : msg_(msg)
  {}
  Init_MapMergeStatus_robot_ids num_robots(::multi_robot_slam::msg::MapMergeStatus::_num_robots_type arg)
  {
    msg_.num_robots = std::move(arg);
    return Init_MapMergeStatus_robot_ids(msg_);
  }

private:
  ::multi_robot_slam::msg::MapMergeStatus msg_;
};

class Init_MapMergeStatus_merge_successful
{
public:
  explicit Init_MapMergeStatus_merge_successful(::multi_robot_slam::msg::MapMergeStatus & msg)
  : msg_(msg)
  {}
  Init_MapMergeStatus_num_robots merge_successful(::multi_robot_slam::msg::MapMergeStatus::_merge_successful_type arg)
  {
    msg_.merge_successful = std::move(arg);
    return Init_MapMergeStatus_num_robots(msg_);
  }

private:
  ::multi_robot_slam::msg::MapMergeStatus msg_;
};

class Init_MapMergeStatus_maps_aligned
{
public:
  explicit Init_MapMergeStatus_maps_aligned(::multi_robot_slam::msg::MapMergeStatus & msg)
  : msg_(msg)
  {}
  Init_MapMergeStatus_merge_successful maps_aligned(::multi_robot_slam::msg::MapMergeStatus::_maps_aligned_type arg)
  {
    msg_.maps_aligned = std::move(arg);
    return Init_MapMergeStatus_merge_successful(msg_);
  }

private:
  ::multi_robot_slam::msg::MapMergeStatus msg_;
};

class Init_MapMergeStatus_header
{
public:
  Init_MapMergeStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapMergeStatus_maps_aligned header(::multi_robot_slam::msg::MapMergeStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MapMergeStatus_maps_aligned(msg_);
  }

private:
  ::multi_robot_slam::msg::MapMergeStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_robot_slam::msg::MapMergeStatus>()
{
  return multi_robot_slam::msg::builder::Init_MapMergeStatus_header();
}

}  // namespace multi_robot_slam

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__BUILDER_HPP_
