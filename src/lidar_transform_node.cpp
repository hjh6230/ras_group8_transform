#include <ros/ros.h>
#include <ras_group8_transform/LidarTransform.hpp>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ras_group8_lidar_transform");
  ros::NodeHandle nodeHandle("~");

  ras_group8_template::LidarTransform mainObject(nodeHandle);

  ros::spin();
  return 0;
}