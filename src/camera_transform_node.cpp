#include <ros/ros.h>
#include <ras_group8_transform/LidarTransform.hpp>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ras_group8_camera_transform");
  ros::NodeHandle nodeHandle("~");

  ras_group8_transform::LidarTransform mainObject(nodeHandle);



  tf::TransformBroadcaster br;
  tf::Transform transform;
   
 ros::Rate rate(10.0);
 while (nodeHandle.ok()){
   transform.setOrigin( tf::Vector3(0.03, 0.0, 0.08) );//need to measure the true distance
   transform.setRotation( tf::createQuaternionFromRPY(0,0.5236,0));

   br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "robot", "camera_link"));
   rate.sleep();
 }
 return 0;



  // ros::spin();
  // return 0;
}