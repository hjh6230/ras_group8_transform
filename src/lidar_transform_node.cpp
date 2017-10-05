#include <ros/ros.h>
#include <ras_group8_transform/LidarTransform.hpp>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ras_group8_lidar_transform");
  ros::NodeHandle nodeHandle("~");

  ras_group8_transform::LidarTransform mainObject(nodeHandle);



  tf::TransformBroadcaster br;
  tf::Transform transform;
   
 ros::Rate rate(10.0);
 while (nodeHandle.ok()){
   transform.setOrigin( tf::Vector3(5.0, 0.0, 0.0) );//need to measure the true distance
   transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
   br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "robot", "laser"));
   rate.sleep();
 }
 return 0;



  // ros::spin();
  // return 0;
}