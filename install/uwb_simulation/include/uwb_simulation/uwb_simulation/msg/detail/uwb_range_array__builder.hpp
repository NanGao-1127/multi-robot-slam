// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uwb_simulation:msg/UwbRangeArray.idl
// generated code does not contain a copyright notice

#ifndef UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__BUILDER_HPP_
#define UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "uwb_simulation/msg/detail/uwb_range_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace uwb_simulation
{

namespace msg
{

namespace builder
{

class Init_UwbRangeArray_ranges
{
public:
  explicit Init_UwbRangeArray_ranges(::uwb_simulation::msg::UwbRangeArray & msg)
  : msg_(msg)
  {}
  ::uwb_simulation::msg::UwbRangeArray ranges(::uwb_simulation::msg::UwbRangeArray::_ranges_type arg)
  {
    msg_.ranges = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRangeArray msg_;
};

class Init_UwbRangeArray_header
{
public:
  Init_UwbRangeArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UwbRangeArray_ranges header(::uwb_simulation::msg::UwbRangeArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UwbRangeArray_ranges(msg_);
  }

private:
  ::uwb_simulation::msg::UwbRangeArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uwb_simulation::msg::UwbRangeArray>()
{
  return uwb_simulation::msg::builder::Init_UwbRangeArray_header();
}

}  // namespace uwb_simulation

#endif  // UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__BUILDER_HPP_
