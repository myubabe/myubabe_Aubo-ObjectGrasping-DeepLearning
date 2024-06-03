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
  posture.points[0].positions[0] = 0.04;
  posture.points[0].positions[1] = 0.04;
  posture.points[0].time_from_start = ros::Duration(0.5);
  // END_SUB_TUTORIAL
}

void closedGripper(trajectory_msgs::JointTrajectory& posture)
{
  // BEGIN_SUB_TUTORIAL closed_gripper
  /* Add both finger joints of aubo robot. */
  posture.joint_names.resize(2);
  posture.joint_names[0] = "gripper_finger1_joint";
  posture.joint_names[1] = "gripper_finger2_joint";

  /* Set them as closed. */
  posture.points.resize(1);
  posture.points[0].positions.resize(2);
  posture.points[0].positions[0] = 0.00;
  posture.points[0].positions[1] = 0.00;
  posture.points[0].time_from_start = ros::Duration(0.5);
  // END_SUB_TUTORIAL
}

void pick(moveit::planning_interface::MoveGroupInterface& move_group)
{
  // BEGIN_SUB_TUTORIAL pick1
  // Create a vector of grasps to be attempted, currently only creating single grasp.
  // This is essentially useful when using a grasp generator to generate and test multiple grasps.
  std::vector<moveit_msgs::Grasp> grasps;
  grasps.resize(1);

  // Setting grasp pose
  // ++++++++++++++++++++++
  
  grasps[0].grasp_pose.header.frame_id = "base_link";
  //tf2::Quaternion orientation;
  tf2::Quaternion orientation;
  orientation.setRPY(1.489, -0.059, -0.637);
  
  grasps[0].grasp_pose.pose.orientation = tf2::toMsg(orientation);
  grasps[0].grasp_pose.pose.position.x = -0.750;
  grasps[0].grasp_pose.pose.position.y = 0.041;
  grasps[0].grasp_pose.pose.position.z =  0.062;

 
  // Setting pre-grasp approach
  // ++++++++++++++++++++++++++
  /* Defined with respect to frame_id */
  grasps[0].pre_grasp_approach.direction.header.frame_id = "base_link";
  /* Direction is set as positive x axis */
  grasps[0].pre_grasp_approach.direction.vector.z = -1.0;
  grasps[0].pre_grasp_approach.direction.vector.y = -1.0;
  grasps[0].pre_grasp_approach.direction.vector.x = -1.0;

  //grasps[0].pre_grasp_approach.min_distance = 0.20;
  grasps[0].pre_grasp_approach.desired_distance = 0.10;



  // Set support surface as table1.
  move_group.setSupportSurfaceName("table1");
  // Call pick to pick up the object using the grasps given