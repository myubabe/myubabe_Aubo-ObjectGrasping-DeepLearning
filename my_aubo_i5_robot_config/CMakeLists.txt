cmake_minimum_required(VERSION 2.8.3)
project(my_aubo_i5_robot_config)
add_compile_options(-std=c++11)

find_package(Eigen3 REQUIRED)

# Eigen 3.2 (Wily) only provides EIGEN3_INCLUDE_DIR, not EIGEN3_INCLUDE_DIRS
if(NOT EIGEN3_INCLUDE_DIRS)
  set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
endif()
find_package(PCL 1.9 REQUIRED)


find_package(catkin REQUIRED COMPONENTS 
  interactive_markers
  moveit_core
  moveit_visual_tools
  moveit_ros_planning
  moveit_ros_planning_interface
  pluginlib
  geometric_shapes
  pcl_ros
  gpd_ros
  pcl_conversions
  rosbag
  tf2_ros
  tf2_eigen
  darknet_ros_msgs
  tf2_geometry_msgs
  roscpp
  rospy
  std_msgs
  message_filters
  geometry_msgs
  