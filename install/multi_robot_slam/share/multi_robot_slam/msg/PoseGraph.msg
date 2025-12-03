# Complete pose graph message

std_msgs/Header header

# All nodes in the graph
multi_robot_slam/PoseGraphNode[] nodes

# All edges in the graph
multi_robot_slam/PoseGraphEdge[] edges

# Optimization status
bool is_optimized
float64 optimization_cost
uint32 num_iterations
