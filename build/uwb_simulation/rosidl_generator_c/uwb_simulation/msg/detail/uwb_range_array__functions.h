// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from uwb_simulation:msg/UwbRangeArray.idl
// generated code does not contain a copyright notice

#ifndef UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__FUNCTIONS_H_
#define UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "uwb_simulation/msg/rosidl_generator_c__visibility_control.h"

#include "uwb_simulation/msg/detail/uwb_range_array__struct.h"

/// Initialize msg/UwbRangeArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uwb_simulation__msg__UwbRangeArray
 * )) before or use
 * uwb_simulation__msg__UwbRangeArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
bool
uwb_simulation__msg__UwbRangeArray__init(uwb_simulation__msg__UwbRangeArray * msg);

/// Finalize msg/UwbRangeArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
void
uwb_simulation__msg__UwbRangeArray__fini(uwb_simulation__msg__UwbRangeArray * msg);

/// Create msg/UwbRangeArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uwb_simulation__msg__UwbRangeArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
uwb_simulation__msg__UwbRangeArray *
uwb_simulation__msg__UwbRangeArray__create();

/// Destroy msg/UwbRangeArray message.
/**
 * It calls
 * uwb_simulation__msg__UwbRangeArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
void
uwb_simulation__msg__UwbRangeArray__destroy(uwb_simulation__msg__UwbRangeArray * msg);

/// Check for msg/UwbRangeArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
bool
uwb_simulation__msg__UwbRangeArray__are_equal(const uwb_simulation__msg__UwbRangeArray * lhs, const uwb_simulation__msg__UwbRangeArray * rhs);

/// Copy a msg/UwbRangeArray message.
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
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
bool
uwb_simulation__msg__UwbRangeArray__copy(
  const uwb_simulation__msg__UwbRangeArray * input,
  uwb_simulation__msg__UwbRangeArray * output);

/// Initialize array of msg/UwbRangeArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * uwb_simulation__msg__UwbRangeArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
bool
uwb_simulation__msg__UwbRangeArray__Sequence__init(uwb_simulation__msg__UwbRangeArray__Sequence * array, size_t size);

/// Finalize array of msg/UwbRangeArray messages.
/**
 * It calls
 * uwb_simulation__msg__UwbRangeArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
void
uwb_simulation__msg__UwbRangeArray__Sequence__fini(uwb_simulation__msg__UwbRangeArray__Sequence * array);

/// Create array of msg/UwbRangeArray messages.
/**
 * It allocates the memory for the array and calls
 * uwb_simulation__msg__UwbRangeArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
uwb_simulation__msg__UwbRangeArray__Sequence *
uwb_simulation__msg__UwbRangeArray__Sequence__create(size_t size);

/// Destroy array of msg/UwbRangeArray messages.
/**
 * It calls
 * uwb_simulation__msg__UwbRangeArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
void
uwb_simulation__msg__UwbRangeArray__Sequence__destroy(uwb_simulation__msg__UwbRangeArray__Sequence * array);

/// Check for msg/UwbRangeArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
bool
uwb_simulation__msg__UwbRangeArray__Sequence__are_equal(const uwb_simulation__msg__UwbRangeArray__Sequence * lhs, const uwb_simulation__msg__UwbRangeArray__Sequence * rhs);

/// Copy an array of msg/UwbRangeArray messages.
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
ROSIDL_GENERATOR_C_PUBLIC_uwb_simulation
bool
uwb_simulation__msg__UwbRangeArray__Sequence__copy(
  const uwb_simulation__msg__UwbRangeArray__Sequence * input,
  uwb_simulation__msg__UwbRangeArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UWB_SIMULATION__MSG__DETAIL__UWB_RANGE_ARRAY__FUNCTIONS_H_
