# UWB Range measurement message
# Based on the paper: Inter-Robot Range Measurements in Pose Graph Optimization

std_msgs/Header header

# Source robot ID (the robot making the measurement)
string source_robot_id

# Target robot ID (the robot being measured to)
string target_robot_id

# Measured range in meters
float64 range

# Standard deviation of the measurement (typically ~0.02m for DWM1001)
float64 range_std

# Measurement timestamp (when the ranging was performed)
builtin_interfaces/Time measurement_time

# Quality indicator (0-100, higher is better)
uint8 quality

# Whether this measurement is valid
bool is_valid
