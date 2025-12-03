// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from multi_robot_slam:msg/PoseGraphEdge.idl
// generated code does not contain a copyright notice

#ifndef MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__FUNCTIONS_H_
#define MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "multi_robot_slam/msg/rosidl_generator_c__visibility_control.h"

#include "multi_robot_slam/msg/detail/pose_graph_edge__struct.h"

/// Initialize msg/PoseGraphEdge message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * multi_robot_slam__msg__PoseGraphEdge
 * )) before or use
 * multi_robot_slam__msg__PoseGraphEdge__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
bool
multi_robot_slam__msg__PoseGraphEdge__init(multi_robot_slam__msg__PoseGraphEdge * msg);

/// Finalize msg/PoseGraphEdge message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
void
multi_robot_slam__msg__PoseGraphEdge__fini(multi_robot_slam__msg__PoseGraphEdge * msg);

/// Create msg/PoseGraphEdge message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * multi_robot_slam__msg__PoseGraphEdge__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
multi_robot_slam__msg__PoseGraphEdge *
multi_robot_slam__msg__PoseGraphEdge__create();

/// Destroy msg/PoseGraphEdge message.
/**
 * It calls
 * multi_robot_slam__msg__PoseGraphEdge__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
void
multi_robot_slam__msg__PoseGraphEdge__destroy(multi_robot_slam__msg__PoseGraphEdge * msg);

/// Check for msg/PoseGraphEdge message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
bool
multi_robot_slam__msg__PoseGraphEdge__are_equal(const multi_robot_slam__msg__PoseGraphEdge * lhs, const multi_robot_slam__msg__PoseGraphEdge * rhs);

/// Copy a msg/PoseGraphEdge message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
bool
multi_robot_slam__msg__PoseGraphEdge__copy(
  const multi_robot_slam__msg__PoseGraphEdge * input,
  multi_robot_slam__msg__PoseGraphEdge * output);

/// Initialize array of msg/PoseGraphEdge messages.
/**
 * It allocates the memory for the number of elements and calls
 * multi_robot_slam__msg__PoseGraphEdge__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
bool
multi_robot_slam__msg__PoseGraphEdge__Sequence__init(multi_robot_slam__msg__PoseGraphEdge__Sequence * array, size_t size);

/// Finalize array of msg/PoseGraphEdge messages.
/**
 * It calls
 * multi_robot_slam__msg__PoseGraphEdge__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
void
multi_robot_slam__msg__PoseGraphEdge__Sequence__fini(multi_robot_slam__msg__PoseGraphEdge__Sequence * array);

/// Create array of msg/PoseGraphEdge messages.
/**
 * It allocates the memory for the array and calls
 * multi_robot_slam__msg__PoseGraphEdge__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
multi_robot_slam__msg__PoseGraphEdge__Sequence *
multi_robot_slam__msg__PoseGraphEdge__Sequence__create(size_t size);

/// Destroy array of msg/PoseGraphEdge messages.
/**
 * It calls
 * multi_robot_slam__msg__PoseGraphEdge__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
void
multi_robot_slam__msg__PoseGraphEdge__Sequence__destroy(multi_robot_slam__msg__PoseGraphEdge__Sequence * array);

/// Check for msg/PoseGraphEdge message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
bool
multi_robot_slam__msg__PoseGraphEdge__Sequence__are_equal(const multi_robot_slam__msg__PoseGraphEdge__Sequence * lhs, const multi_robot_slam__msg__PoseGraphEdge__Sequence * rhs);

/// Copy an array of msg/PoseGraphEdge messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_multi_robot_slam
bool
multi_robot_slam__msg__PoseGraphEdge__Sequence__copy(
  const multi_robot_slam__msg__PoseGraphEdge__Sequence * input,
  multi_robot_slam__msg__PoseGraphEdge__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MULTI_ROBOT_SLAM__MSG__DETAIL__POSE_GRAPH_EDGE__FUNCTIONS_H_
