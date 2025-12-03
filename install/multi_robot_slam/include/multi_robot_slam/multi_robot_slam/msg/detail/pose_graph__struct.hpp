// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_robot_slam:msg/PoseGraph.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__STRUCT_HPP_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__STRUCT_HPP_

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
// Member 'nodes'
#include "multi_robot_slam/msg/detail/pose_graph_node__struct.hpp"
// Member 'edges'
#include "multi_robot_slam/msg/detail/pose_graph_edge__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__multi_robot_slam__msg__PoseGraph __attribute__((deprecated))
#else
# define DEPRECATED__multi_robot_slam__msg__PoseGraph __declspec(deprecated)
#endif

namespace multi_robot_slam
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PoseGraph_
{
  using Type = PoseGraph_<ContainerAllocator>;

  explicit PoseGraph_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_optimized = false;
      this->optimization_cost = 0.0;
      this->num_iterations = 0ul;
    }
  }

  explicit PoseGraph_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_optimized = false;
      this->optimization_cost = 0.0;
      this->num_iterations = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _nodes_type =
    std::vector<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>>>;
  _nodes_type nodes;
  using _edges_type =
    std::vector<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>>>;
  _edges_type edges;
  using _is_optimized_type =
    bool;
  _is_optimized_type is_optimized;
  using _optimization_cost_type =
    double;
  _optimization_cost_type optimization_cost;
  using _num_iterations_type =
    uint32_t;
  _num_iterations_type num_iterations;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__nodes(
    const std::vector<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_robot_slam::msg::PoseGraphNode_<ContainerAllocator>>> & _arg)
  {
    this->nodes = _arg;
    return *this;
  }
  Type & set__edges(
    const std::vector<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_robot_slam::msg::PoseGraphEdge_<ContainerAllocator>>> & _arg)
  {
    this->edges = _arg;
    return *this;
  }
  Type & set__is_optimized(
    const bool & _arg)
  {
    this->is_optimized = _arg;
    return *this;
  }
  Type & set__optimization_cost(
    const double & _arg)
  {
    this->optimization_cost = _arg;
    return *this;
  }
  Type & set__num_iterations(
    const uint32_t & _arg)
  {
    this->num_iterations = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_robot_slam::msg::PoseGraph_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_robot_slam::msg::PoseGraph_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_robot_slam::msg::PoseGraph_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_robot_slam::msg::PoseGraph_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_robot_slam::msg::PoseGraph_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_robot_slam::msg::PoseGraph_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_robot_slam::msg::PoseGraph_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_robot_slam::msg::PoseGraph_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_robot_slam::msg::PoseGraph_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_robot_slam::msg::PoseGraph_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_robot_slam__msg__PoseGraph
    std::shared_ptr<multi_robot_slam::msg::PoseGraph_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_robot_slam__msg__PoseGraph
    std::shared_ptr<multi_robot_slam::msg::PoseGraph_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGraph_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->nodes != other.nodes) {
      return false;
    }
    if (this->edges != other.edges) {
      return false;
    }
    if (this->is_optimized != other.is_optimized) {
      return false;
    }
    if (this->optimization_cost != other.optimization_cost) {
      return false;
    }
    if (this->num_iterations != other.num_iterations) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGraph_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGraph_

// alias to use template instance with default allocator
using PoseGraph =
  multi_robot_slam::msg::PoseGraph_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace multi_robot_slam

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH__STRUCT_HPP_
