#include <ros/ros.h>
#include <tf/transform_listener.h>
#include "message_filters/subscriber.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/PointStamped.h"
#include "tf/message_filter.h"
#include "message_filters/subscriber.h"


class TransformPoint{
public:

  ros::NodeHandle n_;
  tf::TransformListener listener_;
  message_filters::Subscriber<geometry_msgs::PointStamped> point_sub_;
  tf::MessageFilter<geometry_msgs::PointStamped> point_notifier_;
  ros::Publisher point_pub_;

  TransformPoint(ros::NodeHandle n) : 
    n_(n),
    point_sub_(n_, "target/camera_frame", 10),
    point_notifier_(point_sub_,listener_, "camera_link", 10)
  {
    point_notifier_.registerCallback(
      boost::bind(&TransformPoint::ptCallback, this, _1));
    point_notifier_.setTolerance(ros::Duration(0.01));
    point_pub_ = n_.advertise<geometry_msgs::Vector3>("/arm/target",10);
  }

  void ptCallback (const geometry_msgs::PointStamped::ConstPtr& msg)
  {
    geometry_msgs::PointStamped ptinarm;
    try
    {
      listener_.transformPoint("arm", *msg, ptinarm);
        //ROS_INFO("try get cloud.");
    }
    catch (tf::TransformException& e)
    {
        std::cout << e.what();
        return;
    }

// Do something with cloud.
    geometry_msgs::Vector3 v3;
    v3.x=ptinarm.point.x;
    v3.y=ptinarm.point.y;
    v3.z=ptinarm.point.z;


    point_pub_.publish(v3);

  }
};

int main(int argc, char** argv)
{
  
  ros::init(argc, argv, "point_to_arm");
  ros::NodeHandle n;
  TransformPoint lstopc(n);
  
  ros::spin();
  
  return 0;
}
