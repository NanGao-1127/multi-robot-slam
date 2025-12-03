// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uwb_simulation:msg/UwbRange.idl
// generated code does not contain a copyright notice

#ifndef UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__STRUCT_HPP_
#define UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__STRUCT_HPP_

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
// Member 'measurement_time'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uwb_simulation__msg__UwbRange __attribute__((deprecated))
#else
# define DEPRECATED__uwb_simulation__msg__UwbRange __declspec(deprecated)
#endif

namespace uwb_simulation
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UwbRange_
{
  using Type = UwbRange_<ContainerAllocator>;

  explicit UwbRange_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    measurement_time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->source_robot_id = "";
      this->target_robot_id = "";
      this->range = 0.0;
      this->range_std = 0.0;
      this->quality = 0;
      this->is_valid = false;
    }
  }

  explicit UwbRange_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    source_robot_id(_alloc),
    target_robot_id(_alloc),
    measurement_time(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->source_robot_id = "";
      this->target_robot_id = "";
      this->range = 0.0;
      this->range_std = 0.0;
      this->quality = 0;
      this->is_valid = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _source_robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_robot_id_type source_robot_id;
  using _target_robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_robot_id_type target_robot_id;
  using _range_type =
    double;
  _range_type range;
  using _range_std_type =
    double;
  _range_std_type range_std;
  using _measurement_time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _measurement_time_type measurement_time;
  using _quality_type =
    uint8_t;
  _quality_type quality;
  using _is_valid_type =
    bool;
  _is_valid_type is_valid;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
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
  Type & set__range(
    const double & _arg)
  {
    this->range = _arg;
    return *this;
  }
  Type & set__range_std(
    const double & _arg)
  {
    this->range_std = _arg;
    return *this;
  }
  Type & set__measurement_time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->measurement_time = _arg;
    return *this;
  }
  Type & set__quality(
    const uint8_t & _arg)
  {
    this->quality = _arg;
    return *this;
  }
  Type & set__is_valid(
    const bool & _arg)
  {
    this->is_valid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uwb_simulation::msg::UwbRange_<ContainerAllocator> *;
  using ConstRawPtr =
    const uwb_simulation::msg::UwbRange_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uwb_simulation::msg::UwbRange_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uwb_simulation::msg::UwbRange_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uwb_simulation::msg::UwbRange_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uwb_simulation::msg::UwbRange_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uwb_simulation::msg::UwbRange_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uwb_simulation::msg::UwbRange_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uwb_simulation::msg::UwbRange_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uwb_simulation::msg::UwbRange_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uwb_simulation__msg__UwbRange
    std::shared_ptr<uwb_simulation::msg::UwbRange_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uwb_simulation__msg__UwbRange
    std::shared_ptr<uwb_simulation::msg::UwbRange_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UwbRange_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->source_robot_id != other.source_robot_id) {
      return false;
    }
    if (this->target_robot_id != other.target_robot_id) {
      return false;
    }
    if (this->range != other.range) {
      return false;
    }
    if (this->range_std != other.range_std) {
      return false;
    }
    if (this->measurement_time != other.measurement_time) {
      return false;
    }
    if (this->quality != other.quality) {
      return false;
    }
    if (this->is_valid != other.is_valid) {
      return false;
    }
    return true;
  }
  bool operator!=(const UwbRange_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UwbRange_

// alias to use template instance with default allocator
using UwbRange =
  uwb_simulation::msg::UwbRange_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uwb_simulation

#endif  // UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__STRUCT_HPP_
