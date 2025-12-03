// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from multi_robot_slam:msg/PoseGraphEdge.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "multi_robot_slam/msg/detail/pose_graph_edge__struct.h"
#include "multi_robot_slam/msg/detail/pose_graph_edge__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool multi_robot_slam__msg__pose_graph_edge__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("multi_robot_slam.msg._pose_graph_edge.PoseGraphEdge", full_classname_dest, 51) == 0);
  }
  multi_robot_slam__msg__PoseGraphEdge * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // edge_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "edge_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->edge_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // source_node_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "source_node_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->source_node_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // target_node_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_node_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->target_node_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // source_robot_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "source_robot_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->source_robot_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // target_robot_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_robot_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->target_robot_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // relative_pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "relative_pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->relative_pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // range_measurement
    PyObject * field = PyObject_GetAttrString(_pymsg, "range_measurement");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->range_measurement = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // information_matrix
    PyObject * field = PyObject_GetAttrString(_pymsg, "information_matrix");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
      Py_ssize_t size = 36;
      double * dest = ros_message->information_matrix;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // switch_variable
    PyObject * field = PyObject_GetAttrString(_pymsg, "switch_variable");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->switch_variable = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // is_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_active = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * multi_robot_slam__msg__pose_graph_edge__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PoseGraphEdge */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("multi_robot_slam.msg._pose_graph_edge");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PoseGraphEdge");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  multi_robot_slam__msg__PoseGraphEdge * ros_message = (multi_robot_slam__msg__PoseGraphEdge *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // edge_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->edge_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "edge_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // source_node_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->source_node_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "source_node_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_node_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->target_node_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_node_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // source_robot_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->source_robot_id.data,
      strlen(ros_message->source_robot_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "source_robot_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_robot_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->target_robot_id.data,
      strlen(ros_message->target_robot_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_robot_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // relative_pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->relative_pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "relative_pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range_measurement
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->range_measurement);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range_measurement", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // information_matrix
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "information_matrix");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
    assert(sizeof(npy_float64) == sizeof(double));
    npy_float64 * dst = (npy_float64 *)PyArray_GETPTR1(seq_field, 0);
    double * src = &(ros_message->information_matrix[0]);
    memcpy(dst, src, 36 * sizeof(double));
    Py_DECREF(field);
  }
  {  // switch_variable
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->switch_variable);
    {
      int rc = PyObject_SetAttrString(_pymessage, "switch_variable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
