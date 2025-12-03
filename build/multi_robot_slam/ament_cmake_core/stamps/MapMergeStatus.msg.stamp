# Map merge status message

std_msgs/Header header

# Status flags
bool maps_aligned
bool merge_successful

# Number of robots contributing to the merged map
uint8 num_robots

# Transform from each robot's map frame to global frame
string[] robot_ids
geometry_msgs/Transform[] transforms

# Quality metrics
float64 alignment_score
float64 overlap_ratio
