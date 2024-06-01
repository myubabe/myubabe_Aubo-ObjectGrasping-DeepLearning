/* Author: Ioan Sucan, Ridhwan Luthra*/

// ROS
#include <ros/ros.h>

// MoveIt
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <gpd_ros/grasp_detection_node.h>

// TF2
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

/*
 
void cloud_cb(const visualization_msgs::MarkerArrayConstPtr& grasp_pose_msg)
{
  std::cout << "This is the grasp pose:::::::