# generated from rosidl_generator_py/resource/_idl.py.em
# with input from multi_robot_slam:msg/PoseGraph.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PoseGraph(type):
    """Metaclass of message 'PoseGraph'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('multi_robot_slam')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'multi_robot_slam.msg.PoseGraph')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__pose_graph
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__pose_graph
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__pose_graph
            cls._TYPE_SUPPORT = module.type_support_msg__msg__pose_graph
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__pose_graph

            from multi_robot_slam.msg import PoseGraphEdge
            if PoseGraphEdge.__class__._TYPE_SUPPORT is None:
                PoseGraphEdge.__class__.__import_type_support__()

            from multi_robot_slam.msg import PoseGraphNode
            if PoseGraphNode.__class__._TYPE_SUPPORT is None:
                PoseGraphNode.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PoseGraph(metaclass=Metaclass_PoseGraph):
    """Message class 'PoseGraph'."""

    __slots__ = [
        '_header',
        '_nodes',
        '_edges',
        '_is_optimized',
        '_optimization_cost',
        '_num_iterations',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'nodes': 'sequence<multi_robot_slam/PoseGraphNode>',
        'edges': 'sequence<multi_robot_slam/PoseGraphEdge>',
        'is_optimized': 'boolean',
        'optimization_cost': 'double',
        'num_iterations': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['multi_robot_slam', 'msg'], 'PoseGraphNode')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['multi_robot_slam', 'msg'], 'PoseGraphEdge')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.nodes = kwargs.get('nodes', [])
        self.edges = kwargs.get('edges', [])
        self.is_optimized = kwargs.get('is_optimized', bool())
        self.optimization_cost = kwargs.get('optimization_cost', float())
        self.num_iterations = kwargs.get('num_iterations', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.nodes != other.nodes:
            return False
        if self.edges != other.edges:
            return False
        if self.is_optimized != other.is_optimized:
            return False
        if self.optimization_cost != other.optimization_cost:
            return False
        if self.num_iterations != other.num_iterations:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def nodes(self):
        """Message field 'nodes'."""
        return self._nodes

    @nodes.setter
    def nodes(self, value):
        if __debug__:
            from multi_robot_slam.msg import PoseGraphNode
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, PoseGraphNode) for v in value) and
                 True), \
                "The 'nodes' field must be a set or sequence and each value of type 'PoseGraphNode'"
        self._nodes = value

    @builtins.property
    def edges(self):
        """Message field 'edges'."""
        return self._edges

    @edges.setter
    def edges(self, value):
        if __debug__:
            from multi_robot_slam.msg import PoseGraphEdge
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, PoseGraphEdge) for v in value) and
                 True), \
                "The 'edges' field must be a set or sequence and each value of type 'PoseGraphEdge'"
        self._edges = value

    @builtins.property
    def is_optimized(self):
        """Message field 'is_optimized'."""
        return self._is_optimized

    @is_optimized.setter
    def is_optimized(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_optimized' field must be of type 'bool'"
        self._is_optimized = value

    @builtins.property
    def optimization_cost(self):
        """Message field 'optimization_cost'."""
        return self._optimization_cost

    @optimization_cost.setter
    def optimization_cost(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'optimization_cost' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'optimization_cost' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._optimization_cost = value

    @builtins.property
    def num_iterations(self):
        """Message field 'num_iterations'."""
        return self._num_iterations

    @num_iterations.setter
    def num_iterations(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_iterations' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'num_iterations' field must be an unsigned integer in [0, 4294967295]"
        self._num_iterations = value
