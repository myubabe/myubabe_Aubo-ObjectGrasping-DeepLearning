#include <ros/ros.h>
#include <iostream>

// PCL specific includes
#include <boost/bind.hpp>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_ros/transforms.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/filters/passthrough.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/octree/octree_search.h>
#include <darknet_ros_msgs/BoundingBoxes.h>
#include <darknet_ros_msgs/BoundingBox.h>
#include <Eigen/Dense>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/time_synchronizer.h>
#include <string>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/sync_policies/exact_time.h>

#include <pcl/filters/voxel_grid.h>
//using namespace message_filters;

ros::Publisher pub;

int minX;
int minY;
int maxX;
int maxY;
int YoloCenterPointX;
int YoloCenterPointY;
int endCallback2 = 0;
int endCallback1 = 0;


void cloud_cb_2(const darknet_ros_msgs::BoundingBoxesConstPtr& msg)
{

    if(endCallback2 == 0){
        std::string my_choice = "";
        std::cout << "Choose what object you want to grasp: ";
        std::cin >> my_choice;
        std::cout << std::endl;
    

    for(int i = 0; i < 5; i++){
        
            if(msg->bounding_boxes[i].Class == my_choice)
            {
                
                minX = msg->bounding_boxes[i].xmin;
                minY = msg->bounding_boxes[i].ymin;
                maxX = msg->bounding_boxes[i].xmax;
                maxY = msg->bounding_boxes[i].ymax;

                std::cout << "bounding box_boxes: " << msg->bounding_boxes[i].Class << std::endl;
                std::cout << "bounding box minX" << minX << std::endl;
                std::cout << "bounding box minY" << minY << std::endl;
                std::cout << "bounding box maxX" << maxX << std::endl;
                std::cout << "bounding box maxY" << maxY << std::endl;

                YoloCenterPointX = (maxX + minX)/2;
                YoloCenterPointY = (maxY + minY)/2;
               

            }
        
    }
    endCallback2 = 1;
    }
    

}

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& cloud_msg){
if(endCallback1 == 0){
    
 // Container for original & filtered data
  pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;
  pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
  pcl::PCLPointCloud2* cloud_filtered = new pcl::PCLPointCloud