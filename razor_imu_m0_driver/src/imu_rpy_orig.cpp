#include "ros/ros.h"
#include <sensor_msgs/Imu.h>
#include <tf/transform_datatypes.h>
#include <tf2_ros/transform_listener.h>
#include "tf2_ros/buffer.h"
#include <iostream>
using namespace std;
#define PI 3.14159265358979323846264338327950288

void imuCallback(const sensor_msgs::Imu msg){
  
  tf::Quaternion q(msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w);
  tf::Matrix3x3 m(q);
  double roll, pitch, yaw;

  m.getRPY(roll, pitch, yaw);
  cout<<"Roll: "<<(roll*180)/PI<<endl;
  cout<<"Pitch: "<<(pitch*180)/PI<<endl;
  cout<<"Yaw: "<<(yaw*180)/PI<<endl<<endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "imu_rpy");
	ros::NodeHandle nh;
  ros::Subscriber att_sub;
	att_sub = nh.subscribe("imu/data", 1000, imuCallback);
	while(ros::ok()){
		ros::spinOnce();
	}
	return 0;
}
