#include <ras_group8_transform/LidarTransform.hpp>

// STD
#include <string>

namespace ras_group8_transform {

LidarTransform::LidarTransform(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }

  ROS_INFO("Successfully launched node.");
}

LidarTransform::~LidarTransform()
{
}

bool LidarTransform::readParameters()
{
  return true;
}


} /* namespace */