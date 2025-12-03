# generated from rosidl_generator_py/resource/_idl.py.em
# with input from multi_robot_slam:msg/MapMergeStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MapMergeStatus(type):
    """Metaclass of message 'MapMergeStatus'."""

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
                'multi_robot_slam.msg.MapMergeStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__map_merge_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__map_merge_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__map_merge_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__map_merge_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__map_merge_status

            from geometry_msgs.msg import Transform
            if Transform.__class__._TYPE_SUPPORT is None:
                Transform.__class__.__import_type_support__()

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


class MapMergeStatus(metaclass=Metaclass_MapMergeStatus):
    """Message class 'MapMergeStatus'."""

    __slots__ = [
        '_header',
        '_maps_aligned',
        '_merge_successful',
        '_num_robots',
        '_robot_ids',
        '_transforms',
        '_alignment_score',
        '_overlap_ratio',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'maps_aligned': 'boolean',
        'merge_successful': 'boolean',
        'num_robots': 'uint8',
        'robot_ids': 'sequence<string>',
        'transforms': 'sequence<geometry_msgs/Transform>',
        'alignment_score': 'double',
        'overlap_ratio': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Transform')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.maps_aligned = kwargs.get('maps_aligned', bool())
        self.merge_successful = kwargs.get('merge_successful', bool())
        self.num_robots = kwargs.get('num_robots', int())
        self.robot_ids = kwargs.get('robot_ids', [])
        self.transforms = kwargs.get('transforms', [])
        self.alignment_score = kwargs.get('alignment_score', float())
        self.overlap_ratio = kwargs.get('overlap_ratio', float())

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
        if self.maps_aligned != other.maps_aligned:
            return False
        if self.merge_successful != other.merge_successful:
            return False
        if self.num_robots != other.num_robots:
            return False
        if self.robot_ids != other.robot_ids:
            return False
        if self.transforms != other.transforms:
            return False
        if self.alignment_score != other.alignment_score:
            return False
        if self.overlap_ratio != other.overlap_ratio:
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
    def maps_aligned(self):
        """Message field 'maps_aligned'."""
        return self._maps_aligned

    @maps_aligned.setter
    def maps_aligned(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'maps_aligned' field must be of type 'bool'"
        self._maps_aligned = value

    @builtins.property
    def merge_successful(self):
        """Message field 'merge_successful'."""
        return self._merge_successful

    @merge_successful.setter
    def merge_successful(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'merge_successful' field must be of type 'bool'"
        self._merge_successful = value

    @builtins.property
    def num_robots(self):
        """Message field 'num_robots'."""
        return self._num_robots

    @num_robots.setter
    def num_robots(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_robots' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_robots' field must be an unsigned integer in [0, 255]"
        self._num_robots = value

    @builtins.property
    def robot_ids(self):
        """Message field 'robot_ids'."""
        return self._robot_ids

    @robot_ids.setter
    def robot_ids(self, value):
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'robot_ids' field must be a set or sequence and each value of type 'str'"
        self._robot_ids = value

    @builtins.property
    def transforms(self):
        """Message field 'transforms'."""
        return self._transforms

    @transforms.setter
    def transforms(self, value):
        if __debug__:
            from geometry_msgs.msg import Transform
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
                 all(isinstance(v, Transform) for v in value) and
                 True), \
                "The 'transforms' field must be a set or sequence and each value of type 'Transform'"
        self._transforms = value

    @builtins.property
    def alignment_score(self):
        """Message field 'alignment_score'."""
        return self._alignment_score

    @alignment_score.setter
    def alignment_score(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'alignment_score' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'alignment_score' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._alignment_score = value

    @builtins.property
    def overlap_ratio(self):
        """Message field 'overlap_ratio'."""
        return self._overlap_ratio

    @overlap_ratio.setter
    def overlap_ratio(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'overlap_ratio' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'overlap_ratio' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._overlap_ratio = value
