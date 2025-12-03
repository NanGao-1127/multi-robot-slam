# Pose graph node (vertex) message

std_msgs/Header header

# Unique node ID
uint32 node_id

# Robot that created this node
string robot_id

# Pose of the node
geometry_msgs/Pose pose

# Covariance (6x6 flattened to 36 elements)
float64[36] covariance

# Timestamp when this pose was recorded
builtin_interfaces/Time timestamp
