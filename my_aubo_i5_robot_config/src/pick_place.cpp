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
  std::cout << "This is the grasp pose:::::::::::::::::::::::::::::::::::::::::::            ";
  std::cout << grasp_pose_msg->pose.position.x << std::endl;
}
*/

void openGripper(trajectory_msgs::JointTrajectory& posture)
{
  // BEGIN_SUB_TUTORIAL open_gripper
  /* Add both finger joints of panda robot. */
  posture.joint_names.resize(2);
  posture.joint_names[0] = "gripper_finger1_joint";
  posture.joint_names[1] = "gripper_finger2_joint";

  /* Set them as open, wide enough for the object to fit. */
  posture.points.resize(1);
  posture.points[0].positions.resize(2);
  posture.points[0].po