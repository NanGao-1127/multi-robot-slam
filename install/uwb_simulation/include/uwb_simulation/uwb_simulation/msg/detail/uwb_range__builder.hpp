// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uwb_simulation:msg/UwbRange.idl
// generated code does not contain a copyright notice

#ifndef UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__BUILDER_HPP_
#define UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "uwb_simulation/msg/detail/uwb_range__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace uwb_simulation
{

namespace msg
{

namespace builder
{

class Init_UwbRange_is_valid
{
public:
  explicit Init_UwbRange_is_valid(::uwb_simulation::msg::UwbRange & msg)
  : msg_(msg)
  {}
  ::uwb_simulation::msg::UwbRange is_valid(::uwb_simulation::msg::UwbRange::_is_valid_type arg)
  {
    msg_.is_valid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRange msg_;
};

class Init_UwbRange_quality
{
public:
  explicit Init_UwbRange_quality(::uwb_simulation::msg::UwbRange & msg)
  : msg_(msg)
  {}
  Init_UwbRange_is_valid quality(::uwb_simulation::msg::UwbRange::_quality_type arg)
  {
    msg_.quality = std::move(arg);
    return Init_UwbRange_is_valid(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRange msg_;
};

class Init_UwbRange_measurement_time
{
public:
  explicit Init_UwbRange_measurement_time(::uwb_simulation::msg::UwbRange & msg)
  : msg_(msg)
  {}
  Init_UwbRange_quality measurement_time(::uwb_simulation::msg::UwbRange::_measurement_time_type arg)
  {
    msg_.measurement_time = std::move(arg);
    return Init_UwbRange_quality(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRange msg_;
};

class Init_UwbRange_range_std
{
public:
  explicit Init_UwbRange_range_std(::uwb_simulation::msg::UwbRange & msg)
  : msg_(msg)
  {}
  Init_UwbRange_measurement_time range_std(::uwb_simulation::msg::UwbRange::_range_std_type arg)
  {
    msg_.range_std = std::move(arg);
    return Init_UwbRange_measurement_time(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRange msg_;
};

class Init_UwbRange_range
{
public:
  explicit Init_UwbRange_range(::uwb_simulation::msg::UwbRange & msg)
  : msg_(msg)
  {}
  Init_UwbRange_range_std range(::uwb_simulation::msg::UwbRange::_range_type arg)
  {
    msg_.range = std::move(arg);
    return Init_UwbRange_range_std(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRange msg_;
};

class Init_UwbRange_target_robot_id
{
public:
  explicit Init_UwbRange_target_robot_id(::uwb_simulation::msg::UwbRange & msg)
  : msg_(msg)
  {}
  Init_UwbRange_range target_robot_id(::uwb_simulation::msg::UwbRange::_target_robot_id_type arg)
  {
    msg_.target_robot_id = std::move(arg);
    return Init_UwbRange_range(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRange msg_;
};

class Init_UwbRange_source_robot_id
{
public:
  explicit Init_UwbRange_source_robot_id(::uwb_simulation::msg::UwbRange & msg)
  : msg_(msg)
  {}
  Init_UwbRange_target_robot_id source_robot_id(::uwb_simulation::msg::UwbRange::_source_robot_id_type arg)
  {
    msg_.source_robot_id = std::move(arg);
    return Init_UwbRange_target_robot_id(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRange msg_;
};

class Init_UwbRange_header
{
public:
  Init_UwbRange_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UwbRange_source_robot_id header(::uwb_simulation::msg::UwbRange::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UwbRange_source_robot_id(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRange msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uwb_simulation::msg::UwbRange>()
{
  return uwb_simulation::msg::builder::Init_UwbRange_header();
}

}  // namespace uwb_simulation

#endif  // UWB_SIMULATION__MSG__DETAIL__UWB_RANGE__BUILDER_HPP_
