// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_robot_slam:msg/MapMergeStatus.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__STRUCT_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__STRUCT_HPP_

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
// Member 'transforms'
#include "geometry_msgs/msg/detail/transform__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__multi_robot_slam__msg__MapMergeStatus __attribute__((deprecated))
#else
# define DEPRECATED__multi_robot_slam__msg__MapMergeStatus __declspec(deprecated)
#endif

namespace multi_robot_slam
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MapMergeStatus_
{
  using Type = MapMergeStatus_<ContainerAllocator>;

  explicit MapMergeStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->maps_aligned = false;
      this->merge_successful = false;
      this->num_robots = 0;
      this->alignment_score = 0.0;
      this->overlap_ratio = 0.0;
    }
  }

  explicit MapMergeStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->maps_aligned = false;
      this->merge_successful = false;
      this->num_robots = 0;
      this->alignment_score = 0.0;
      this->overlap_ratio = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _maps_aligned_type =
    bool;
  _maps_aligned_type maps_aligned;
  using _merge_successful_type =
    bool;
  _merge_successful_type merge_successful;
  using _num_robots_type =
    uint8_t;
  _num_robots_type num_robots;
  using _robot_ids_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _robot_ids_type robot_ids;
  using _transforms_type =
    std::vector<geometry_msgs::msg::Transform_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Transform_<ContainerAllocator>>>;
  _transforms_type transforms;
  using _alignment_score_type =
    double;
  _alignment_score_type alignment_score;
  using _overlap_ratio_type =
    double;
  _overlap_ratio_type overlap_ratio;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__maps_aligned(
    const bool & _arg)
  {
    this->maps_aligned = _arg;
    return *this;
  }
  Type & set__merge_successful(
    const bool & _arg)
  {
    this->merge_successful = _arg;
    return *this;
  }
  Type & set__num_robots(
    const uint8_t & _arg)
  {
    this->num_robots = _arg;
    return *this;
  }
  Type & set__robot_ids(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->robot_ids = _arg;
    return *this;
  }
  Type & set__transforms(
    const std::vector<geometry_msgs::msg::Transform_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Transform_<ContainerAllocator>>> & _arg)
  {
    this->transforms = _arg;
    return *this;
  }
  Type & set__alignment_score(
    const double & _arg)
  {
    this->alignment_score = _arg;
    return *this;
  }
  Type & set__overlap_ratio(
    const double & _arg)
  {
    this->overlap_ratio = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_robot_slam__msg__MapMergeStatus
    std::shared_ptr<multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_robot_slam__msg__MapMergeStatus
    std::shared_ptr<multi_robot_slam::msg::MapMergeStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MapMergeStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->maps_aligned != other.maps_aligned) {
      return false;
    }
    if (this->merge_successful != other.merge_successful) {
      return false;
    }
    if (this->num_robots != other.num_robots) {
      return false;
    }
    if (this->robot_ids != other.robot_ids) {
      return false;
    }
    if (this->transforms != other.transforms) {
      return false;
    }
    if (this->alignment_score != other.alignment_score) {
      return false;
    }
    if (this->overlap_ratio != other.overlap_ratio) {
      return false;
    }
    return true;
  }
  bool operator!=(const MapMergeStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MapMergeStatus_

// alias to use template instance with default allocator
using MapMergeStatus =
  multi_robot_slam::msg::MapMergeStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace multi_robot_slam

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__MAP_MERGE_STATUS__STRUCT_HPP_
