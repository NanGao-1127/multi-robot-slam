// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from multi_robot_slam:msg/PoseGraph.idl
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
#include "multi_robot_slam/msg/detail/pose_graph__struct.h"
#include "multi_robot_slam/msg/detail/pose_graph__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "multi_robot_slam/msg/detail/pose_graph_edge__functions.h"
#include "multi_robot_slam/msg/detail/pose_graph_node__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool multi_robot_slam__msg__pose_graph_node__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * multi_robot_slam__msg__pose_graph_node__convert_to_py(void * raw_ros_message);
bool multi_robot_slam__msg__pose_graph_edge__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * multi_robot_slam__msg__pose_graph_edge__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool multi_robot_slam__msg__pose_graph__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
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
    assert(strncmp("multi_robot_slam.msg._pose_graph.PoseGraph", full_classname_dest, 42) == 0);
  }
  multi_robot_slam__msg__PoseGraph * ros_message = _ros_message;
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
  {  // nodes
    PyObject * field = PyObject_GetAttrString(_pymsg, "nodes");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'nodes'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!multi_robot_slam__msg__PoseGraphNode__Sequence__init(&(ros_message->nodes), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create multi_robot_slam__msg__PoseGraphNode__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    multi_robot_slam__msg__PoseGraphNode * dest = ros_message->nodes.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!multi_robot_slam__msg__pose_graph_node__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // edges
    PyObject * field = PyObject_GetAttrString(_pymsg, "edges");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'edges'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!multi_robot_slam__msg__PoseGraphEdge__Sequence__init(&(ros_message->edges), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create multi_robot_slam__msg__PoseGraphEdge__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    multi_robot_slam__msg__PoseGraphEdge * dest = ros_message->edges.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!multi_robot_slam__msg__pose_graph_edge__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // is_optimized
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_optimized");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_optimized = (Py_True == field);
    Py_DECREF(field);
  }
  {  // optimization_cost
    PyObject * field = PyObject_GetAttrString(_pymsg, "optimization_cost");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->optimization_cost = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // num_iterations
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_iterations");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_iterations = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * multi_robot_slam__msg__pose_graph__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PoseGraph */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("multi_robot_slam.msg._pose_graph");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PoseGraph");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  multi_robot_slam__msg__PoseGraph * ros_message = (multi_robot_slam__msg__PoseGraph *)raw_ros_message;
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
  {  // nodes
    PyObject * field = NULL;
    size_t size = ros_message->nodes.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    multi_robot_slam__msg__PoseGraphNode * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->nodes.data[i]);
      PyObject * pyitem = multi_robot_slam__msg__pose_graph_node__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "nodes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // edges
    PyObject * field = NULL;
    size_t size = ros_message->edges.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    multi_robot_slam__msg__PoseGraphEdge * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->edges.data[i]);
      PyObject * pyitem = multi_robot_slam__msg__pose_graph_edge__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "edges", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_optimized
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_optimized ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_optimized", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // optimization_cost
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->optimization_cost);
    {
      int rc = PyObject_SetAttrString(_pymessage, "optimization_cost", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_iterations
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num_iterations);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_iterations", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
