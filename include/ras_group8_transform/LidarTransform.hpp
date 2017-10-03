#pragma once

#include <ros/ros.h>

namespace ras_group8_transform {

class LidarTransform
{
public:
  LidarTransform(ros::NodeHandle& nodeHandle);
  virtual ~LidarTransform();

private:
  bool readParameters();

  /* ROS Objects
   */
  ros::NodeHandle& nodeHandle_;
  
  /* Parameters
   */
};

} /* namespace */