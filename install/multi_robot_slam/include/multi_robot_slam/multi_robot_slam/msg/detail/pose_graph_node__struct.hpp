// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_robot_slam:msg/PoseGraphNode.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__STRUCT_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__multi_robot_slam__msg__PoseGraphNode __attribute__((deprecated))
#else
# define DEPRECATED__multi_robot_slam__msg__PoseGraphNode __declspec(deprecated)
#endif

namespace multi_robot_slam
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PoseGraphNode_
{
  using Type = PoseGraphNode_<ContainerAllocator>;

  explicit PoseGraphNode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose(_init),
    timestamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_id = 0ul;
      this->robot_id = "";
      std::fill<typename std::array<double, 36>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
    }
  }

  explicit PoseGraphNode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    robot_id(_alloc),
    pose(_alloc, _init),
    covariance(_alloc),
    timestamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_id = 0ul;
      this->robot_id = "";
      std::fill<typename std::array<double, 36>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _node_id_type =
    uint32_t;
  _node_id_type node_id;
  using _robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_id_type robot_id;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _covariance_type =
    std::array<double, 36>;
  _covariance_type covariance;
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__node_id(
    const uint32_t & _arg)
  {
    this->node_id = _arg;
    return *this;
  }
  Type & set__robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__covariance(
    const std::array<double, 36> & _arg)
  {
    this->covariance = _arg;
    return *this;
  }
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_robot_slam__msg__PoseGraphNode
    std::shared_ptr<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_robot_slam__msg__PoseGraphNode
    std::shared_ptr<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGraphNode_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->node_id != other.node_id) {
      return false;
    }
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->covariance != other.covariance) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGraphNode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGraphNode_

// alias to use template instance with default allocator
using PoseGraphNode =
  multi_robot_slam::msg::PoseGraphNode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace multi_robot_slam

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_NODE__STRUCT_HPP_
