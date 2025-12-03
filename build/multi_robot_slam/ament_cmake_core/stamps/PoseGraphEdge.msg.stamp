# Pose graph edge (constraint) message

std_msgs/Header header

# Edge type
uint8 EDGE_ODOMETRY = 0
uint8 EDGE_LOOP_CLOSURE = 1
uint8 EDGE_UWB_RANGE = 2
uint8 edge_type

# Source and target node IDs
uint32 source_node_id
uint32 target_node_id

# Source and target robot IDs (for inter-robot edges)
string source_robot_id
string target_robot_id

# For odometry/loop closure edges: relative transform
geometry_msgs/Pose relative_pose

# For range edges: measured range
float64 range_measurement

# Measurement uncertainty
float64[36] information_matrix

# Switch variable for robust optimization (1.0 = on, 0.0 = off)
float64 switch_variable

# Whether this edge is active in optimization
bool is_active
