// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_robot_slam:msg/PoseGraphEdge.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__STRUCT_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__STRUCT_HPP_

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
// Member 'relative_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__multi_robot_slam__msg__PoseGraphEdge __attribute__((deprecated))
#else
# define DEPRECATED__multi_robot_slam__msg__PoseGraphEdge __declspec(deprecated)
#endif

namespace multi_robot_slam
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PoseGraphEdge_
{
  using Type = PoseGraphEdge_<ContainerAllocator>;

  explicit PoseGraphEdge_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    relative_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->edge_type = 0;
      this->source_node_id = 0ul;
      this->target_node_id = 0ul;
      this->source_robot_id = "";
      this->target_robot_id = "";
      this->range_measurement = 0.0;
      std::fill<typename std::array<double, 36>::iterator, double>(this->information_matrix.begin(), this->information_matrix.end(), 0.0);
      this->switch_variable = 0.0;
      this->is_active = false;
    }
  }

  explicit PoseGraphEdge_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    source_robot_id(_alloc),
    target_robot_id(_alloc),
    relative_pose(_alloc, _init),
    information_matrix(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->edge_type = 0;
      this->source_node_id = 0ul;
      this->target_node_id = 0ul;
      this->source_robot_id = "";
      this->target_robot_id = "";
      this->range_measurement = 0.0;
      std::fill<typename std::array<double, 36>::iterator, double>(this->information_matrix.begin(), this->information_matrix.end(), 0.0);
      this->switch_variable = 0.0;
      this->is_active = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _edge_type_type =
    uint8_t;
  _edge_type_type edge_type;
  using _source_node_id_type =
    uint32_t;
  _source_node_id_type source_node_id;
  using _target_node_id_type =
    uint32_t;
  _target_node_id_type target_node_id;
  using _source_robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_robot_id_type source_robot_id;
  using _target_robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_robot_id_type target_robot_id;
  using _relative_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _relative_pose_type relative_pose;
  using _range_measurement_type =
    double;
  _range_measurement_type range_measurement;
  using _information_matrix_type =
    std::array<double, 36>;
  _information_matrix_type information_matrix;
  using _switch_variable_type =
    double;
  _switch_variable_type switch_variable;
  using _is_active_type =
    bool;
  _is_active_type is_active;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__edge_type(
    const uint8_t & _arg)
  {
    this->edge_type = _arg;
    return *this;
  }
  Type & set__source_node_id(
    const uint32_t & _arg)
  {
    this->source_node_id = _arg;
    return *this;
  }
  Type & set__target_node_id(
    const uint32_t & _arg)
  {
    this->target_node_id = _arg;
    return *this;
  }
  Type & set__source_robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->source_robot_id = _arg;
    return *this;
  }
  Type & set__target_robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target_robot_id = _arg;
    return *this;
  }
  Type & set__relative_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->relative_pose = _arg;
    return *this;
  }
  Type & set__range_measurement(
    const double & _arg)
  {
    this->range_measurement = _arg;
    return *this;
  }
  Type & set__information_matrix(
    const std::array<double, 36> & _arg)
  {
    this->information_matrix = _arg;
    return *this;
  }
  Type & set__switch_variable(
    const double & _arg)
  {
    this->switch_variable = _arg;
    return *this;
  }
  Type & set__is_active(
    const bool & _arg)
  {
    this->is_active = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t EDGE_ODOMETRY =
    0u;
  static constexpr uint8_t EDGE_LOOP_CLOSURE =
    1u;
  static constexpr uint8_t EDGE_UWB_RANGE =
    2u;

  // pointer types
  using RawPtr =
    multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_robot_slam__msg__PoseGraphEdge
    std::shared_ptr<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_robot_slam__msg__PoseGraphEdge
    std::shared_ptr<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGraphEdge_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->edge_type != other.edge_type) {
      return false;
    }
    if (this->source_node_id != other.source_node_id) {
      return false;
    }
    if (this->target_node_id != other.target_node_id) {
      return false;
    }
    if (this->source_robot_id != other.source_robot_id) {
      return false;
    }
    if (this->target_robot_id != other.target_robot_id) {
      return false;
    }
    if (this->relative_pose != other.relative_pose) {
      return false;
    }
    if (this->range_measurement != other.range_measurement) {
      return false;
    }
    if (this->information_matrix != other.information_matrix) {
      return false;
    }
    if (this->switch_variable != other.switch_variable) {
      return false;
    }
    if (this->is_active != other.is_active) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGraphEdge_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGraphEdge_

// alias to use template instance with default allocator
using PoseGraphEdge =
  multi_robot_slam::msg::PoseGraphEdge_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PoseGraphEdge_<ContainerAllocator>::EDGE_ODOMETRY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PoseGraphEdge_<ContainerAllocator>::EDGE_LOOP_CLOSURE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PoseGraphEdge_<ContainerAllocator>::EDGE_UWB_RANGE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace multi_robot_slam

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__STRUCT_HPP_
