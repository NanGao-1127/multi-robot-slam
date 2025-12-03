# generated from rosidl_generator_py/resource/_idl.py.em
# with input from multi_robot_slam:msg/PoseGraphEdge.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'information_matrix'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PoseGraphEdge(type):
    """Metaclass of message 'PoseGraphEdge'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'EDGE_ODOMETRY': 0,
        'EDGE_LOOP_CLOSURE': 1,
        'EDGE_UWB_RANGE': 2,
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
                'multi_robot_slam.msg.PoseGraphEdge')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__pose_graph_edge
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__pose_graph_edge
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__pose_graph_edge
            cls._TYPE_SUPPORT = module.type_support_msg__msg__pose_graph_edge
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__pose_graph_edge

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'EDGE_ODOMETRY': cls.__constants['EDGE_ODOMETRY'],
            'EDGE_LOOP_CLOSURE': cls.__constants['EDGE_LOOP_CLOSURE'],
            'EDGE_UWB_RANGE': cls.__constants['EDGE_UWB_RANGE'],
        }

    @property
    def EDGE_ODOMETRY(self):
        """Message constant 'EDGE_ODOMETRY'."""
        return Metaclass_PoseGraphEdge.__constants['EDGE_ODOMETRY']

    @property
    def EDGE_LOOP_CLOSURE(self):
        """Message constant 'EDGE_LOOP_CLOSURE'."""
        return Metaclass_PoseGraphEdge.__constants['EDGE_LOOP_CLOSURE']

    @property
    def EDGE_UWB_RANGE(self):
        """Message constant 'EDGE_UWB_RANGE'."""
        return Metaclass_PoseGraphEdge.__constants['EDGE_UWB_RANGE']


class PoseGraphEdge(metaclass=Metaclass_PoseGraphEdge):
    """
    Message class 'PoseGraphEdge'.

    Constants:
      EDGE_ODOMETRY
      EDGE_LOOP_CLOSURE
      EDGE_UWB_RANGE
    """

    __slots__ = [
        '_header',
        '_edge_type',
        '_source_node_id',
        '_target_node_id',
        '_source_robot_id',
        '_target_robot_id',
        '_relative_pose',
        '_range_measurement',
        '_information_matrix',
        '_switch_variable',
        '_is_active',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'edge_type': 'uint8',
        'source_node_id': 'uint32',
        'target_node_id': 'uint32',
        'source_robot_id': 'string',
        'target_robot_id': 'string',
        'relative_pose': 'geometry_msgs/Pose',
        'range_measurement': 'double',
        'information_matrix': 'double[36]',
        'switch_variable': 'double',
        'is_active': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 36),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.edge_type = kwargs.get('edge_type', int())
        self.source_node_id = kwargs.get('source_node_id', int())
        self.target_node_id = kwargs.get('target_node_id', int())
        self.source_robot_id = kwargs.get('source_robot_id', str())
        self.target_robot_id = kwargs.get('target_robot_id', str())
        from geometry_msgs.msg import Pose
        self.relative_pose = kwargs.get('relative_pose', Pose())
        self.range_measurement = kwargs.get('range_measurement', float())
        if 'information_matrix' not in kwargs:
            self.information_matrix = numpy.zeros(36, dtype=numpy.float64)
        else:
            self.information_matrix = kwargs.get('information_matrix')
        self.switch_variable = kwargs.get('switch_variable', float())
        self.is_active = kwargs.get('is_active', bool())

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
        if self.edge_type != other.edge_type:
            return False
        if self.source_node_id != other.source_node_id:
            return False
        if self.target_node_id != other.target_node_id:
            return False
        if self.source_robot_id != other.source_robot_id:
            return False
        if self.target_robot_id != other.target_robot_id:
            return False
        if self.relative_pose != other.relative_pose:
            return False
        if self.range_measurement != other.range_measurement:
            return False
        if any(self.information_matrix != other.information_matrix):
            return False
        if self.switch_variable != other.switch_variable:
            return False
        if self.is_active != other.is_active:
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
    def edge_type(self):
        """Message field 'edge_type'."""
        return self._edge_type

    @edge_type.setter
    def edge_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'edge_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'edge_type' field must be an unsigned integer in [0, 255]"
        self._edge_type = value

    @builtins.property
    def source_node_id(self):
        """Message field 'source_node_id'."""
        return self._source_node_id

    @source_node_id.setter
    def source_node_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'source_node_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'source_node_id' field must be an unsigned integer in [0, 4294967295]"
        self._source_node_id = value

    @builtins.property
    def target_node_id(self):
        """Message field 'target_node_id'."""
        return self._target_node_id

    @target_node_id.setter
    def target_node_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_node_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'target_node_id' field must be an unsigned integer in [0, 4294967295]"
        self._target_node_id = value

    @builtins.property
    def source_robot_id(self):
        """Message field 'source_robot_id'."""
        return self._source_robot_id

    @source_robot_id.setter
    def source_robot_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'source_robot_id' field must be of type 'str'"
        self._source_robot_id = value

    @builtins.property
    def target_robot_id(self):
        """Message field 'target_robot_id'."""
        return self._target_robot_id

    @target_robot_id.setter
    def target_robot_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'target_robot_id' field must be of type 'str'"
        self._target_robot_id = value

    @builtins.property
    def relative_pose(self):
        """Message field 'relative_pose'."""
        return self._relative_pose

    @relative_pose.setter
    def relative_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'relative_pose' field must be a sub message of type 'Pose'"
        self._relative_pose = value

    @builtins.property
    def range_measurement(self):
        """Message field 'range_measurement'."""
        return self._range_measurement

    @range_measurement.setter
    def range_measurement(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'range_measurement' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'range_measurement' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._range_measurement = value

    @builtins.property
    def information_matrix(self):
        """Message field 'information_matrix'."""
        return self._information_matrix

    @information_matrix.setter
    def information_matrix(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'information_matrix' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 36, \
                "The 'information_matrix' numpy.ndarray() must have a size of 36"
            self._information_matrix = value
            return
        if __debug__:
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
                 len(value) == 36 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'information_matrix' field must be a set or sequence with length 36 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._information_matrix = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def switch_variable(self):
        """Message field 'switch_variable'."""
        return self._switch_variable

    @switch_variable.setter
    def switch_variable(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'switch_variable' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'switch_variable' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._switch_variable = value

    @builtins.property
    def is_active(self):
        """Message field 'is_active'."""
        return self._is_active

    @is_active.setter
    def is_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_active' field must be of type 'bool'"
        self._is_active = value
