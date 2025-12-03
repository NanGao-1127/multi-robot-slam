// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from multi_robot_slam:msg/PoseGraphEdge.idl
// generated code does not contain a copyright notice
#include "multi_robot_slam/msg/detail/pose_graph_edge__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "multi_robot_slam/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "multi_robot_slam/msg/detail/pose_graph_edge__struct.h"
#include "multi_robot_slam/msg/detail/pose_graph_edge__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/pose__functions.h"  // relative_pose
#include "rosidl_runtime_c/string.h"  // source_robot_id, target_robot_id
#include "rosidl_runtime_c/string_functions.h"  // source_robot_id, target_robot_id
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_multi_robot_slam
size_t get_serialized_size_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_multi_robot_slam
size_t max_serialized_size_geometry_msgs__msg__Pose(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_multi_robot_slam
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_multi_robot_slam
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_multi_robot_slam
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_multi_robot_slam
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _PoseGraphEdge__ros_msg_type = multi_robot_slam__msg__PoseGraphEdge;

static bool _PoseGraphEdge__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PoseGraphEdge__ros_msg_type * ros_message = static_cast<const _PoseGraphEdge__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: edge_type
  {
    cdr << ros_message->edge_type;
  }

  // Field name: source_node_id
  {
    cdr << ros_message->source_node_id;
  }

  // Field name: target_node_id
  {
    cdr << ros_message->target_node_id;
  }

  // Field name: source_robot_id
  {
    const rosidl_runtime_c__String * str = &ros_message->source_robot_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: target_robot_id
  {
    const rosidl_runtime_c__String * str = &ros_message->target_robot_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: relative_pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->relative_pose, cdr))
    {
      return false;
    }
  }

  // Field name: range_measurement
  {
    cdr << ros_message->range_measurement;
  }

  // Field name: information_matrix
  {
    size_t size = 36;
    auto array_ptr = ros_message->information_matrix;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: switch_variable
  {
    cdr << ros_message->switch_variable;
  }

  // Field name: is_active
  {
    cdr << (ros_message->is_active ? true : false);
  }

  return true;
}

static bool _PoseGraphEdge__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PoseGraphEdge__ros_msg_type * ros_message = static_cast<_PoseGraphEdge__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: edge_type
  {
    cdr >> ros_message->edge_type;
  }

  // Field name: source_node_id
  {
    cdr >> ros_message->source_node_id;
  }

  // Field name: target_node_id
  {
    cdr >> ros_message->target_node_id;
  }

  // Field name: source_robot_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->source_robot_id.data) {
      rosidl_runtime_c__String__init(&ros_message->source_robot_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->source_robot_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'source_robot_id'\n");
      return false;
    }
  }

  // Field name: target_robot_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->target_robot_id.data) {
      rosidl_runtime_c__String__init(&ros_message->target_robot_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->target_robot_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'target_robot_id'\n");
      return false;
    }
  }

  // Field name: relative_pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->relative_pose))
    {
      return false;
    }
  }

  // Field name: range_measurement
  {
    cdr >> ros_message->range_measurement;
  }

  // Field name: information_matrix
  {
    size_t size = 36;
    auto array_ptr = ros_message->information_matrix;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: switch_variable
  {
    cdr >> ros_message->switch_variable;
  }

  // Field name: is_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_active = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_robot_slam
size_t get_serialized_size_multi_robot_slam__msg__PoseGraphEdge(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PoseGraphEdge__ros_msg_type * ros_message = static_cast<const _PoseGraphEdge__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name edge_type
  {
    size_t item_size = sizeof(ros_message->edge_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name source_node_id
  {
    size_t item_size = sizeof(ros_message->source_node_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_node_id
  {
    size_t item_size = sizeof(ros_message->target_node_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name source_robot_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->source_robot_id.size + 1);
  // field.name target_robot_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->target_robot_id.size + 1);
  // field.name relative_pose

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->relative_pose), current_alignment);
  // field.name range_measurement
  {
    size_t item_size = sizeof(ros_message->range_measurement);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name information_matrix
  {
    size_t array_size = 36;
    auto array_ptr = ros_message->information_matrix;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name switch_variable
  {
    size_t item_size = sizeof(ros_message->switch_variable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_active
  {
    size_t item_size = sizeof(ros_message->is_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PoseGraphEdge__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_multi_robot_slam__msg__PoseGraphEdge(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_robot_slam
size_t max_serialized_size_multi_robot_slam__msg__PoseGraphEdge(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: edge_type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: source_node_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_node_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: source_robot_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: target_robot_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: relative_pose
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: range_measurement
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: information_matrix
  {
    size_t array_size = 36;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: switch_variable
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: is_active
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = multi_robot_slam__msg__PoseGraphEdge;
    is_plain =
      (
      offsetof(DataType, is_active) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PoseGraphEdge__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_multi_robot_slam__msg__PoseGraphEdge(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PoseGraphEdge = {
  "multi_robot_slam::msg",
  "PoseGraphEdge",
  _PoseGraphEdge__cdr_serialize,
  _PoseGraphEdge__cdr_deserialize,
  _PoseGraphEdge__get_serialized_size,
  _PoseGraphEdge__max_serialized_size
};

static rosidl_message_type_support_t _PoseGraphEdge__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PoseGraphEdge,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, multi_robot_slam, msg, PoseGraphEdge)() {
  return &_PoseGraphEdge__type_support;
}

#if defined(__cplusplus)
}
#endif
