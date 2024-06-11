
# myubabe_Aubo-ObjectGrasping-DeepLearning
A program for pick and place operations with deep learning algorithms GPD and YOLO, utilizing the Aubo Robotic Manipulator.

## Required Installations

Use these links to install each necessary program.

- Ubuntu 16.04
- [ROS Kinetic](http://wiki.ros.org/kinetic/Installation/Ubuntu)
- Python 2.7
- [Darknet_ros](https://github.com/leggedrobotics/darknet_ros) -V: YOLOv4
- [OpenCV](https://www.pyimagesearch.com/2016/10/24/ubuntu-16-04-how-to-install-opencv/) >= 3.4
- [GPD](https://github.com/atenpas/gpd)
- [gpd_ros](https://github.com/atenpas/gpd_ros)
- [Moveit](https://moveit.ros.org/install/)
- [PCL](https://www.programmersought.com/article/52981999118/) >= 1.7
- [Aruco_Ros](https://github.com/pal-robotics/aruco_ros)
- [Aubo_I5_Driver](https://github.com/AuboRobot/aubo_robot)
- [Aubo I5 Model](https://github.com/hai-h-nguyen/aubo-i5-full)
## Hardware
- Asus Xtion Pro RGB-D Camera
- Aubo I5 Robot
- Robotiq 85 Gripper
## Running the Programs to Pick Up Object

1. Run the camera calibrated launch files in seperate terminals

```
   roslaunch jsk_pcl_ros openni2_local.launch
   roslaunch jsk_pcl_ros openni2_remote.launch
```

2. In a new terminal run object detection through darknet_ros by command:

```
   roslaunch darknet_ros darknet_ros.launch
```

3. In a new terminal run the program to filter out all point cloud data except the object that was chosen:

```
   rosrun my_aubo_i5_robot_config pass_through
```

4. To find the transformation of the Aubo Robot base link with respect to the camera frame run:

```
   roslaunch static_frame.launch
```

5. Launch the Aubo Driver in a new terminal:

```
   roslaunch aubo_i5_moveit_config moveit_planning_execution.launch sim:=false robot_ip:=your-robot-ip 
```

6. Grasp the object by running in a new terminal:

```
   rosrun my_aubo_i5_robot_config pick_place
```

![pick2](https://user-images.githubusercontent.com/78880630/125694867-f153927d-6672-42a0-9591-4ce820e527cf.gif)
![place](https://user-images.githubusercontent.com/78880630/125694890-14baef22-255f-42cc-8c95-e2435596bff6.gif)
