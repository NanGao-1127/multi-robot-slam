cmake_minimum_required(VERSION 3.8)
project(multi_robot_slam)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

# Generate custom messages
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/PoseGraphNode.msg"
  "msg/PoseGraphEdge.msg"
  "msg/PoseGraph.msg"
  "msg/MapMergeStatus.msg"
  DEPENDENCIES std_msgs geometry_msgs nav_msgs
)

# Install Python nodes
install(PROGRAMS
  src/pose_graph_optimizer.py
  src/map_merger.py
  src/tf_publisher.py
  src/slam_coordinator.py
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch and config
install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
