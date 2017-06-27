#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include <sstream>
#include <iostream>


int main(int argc, char **argv)
{
	ros::init(argc,argv,"pose_talker");
	ros::NodeHandle n; 
	ros::Publisher chatter_pub = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("pose_chatter", 1000);
	ros::Rate loop_rate(10); 

	int count = 0; 
	while(ros::ok())
	{
		geometry_msgs::PoseWithCovarianceStamped pose_msg; 
		ros::Time time_now = ros::Time::now(); 
		pose_msg.header.seq = count; 
		pose_msg.header.stamp.sec = time_now.sec; 
		pose_msg.header.stamp.nsec = time_now.nsec;
		pose_msg.pose.pose.position.x = 1.0; 
		pose_msg.pose.pose.position.y = 2.0; 
		pose_msg.pose.pose.position.z = 3.0;
		pose_msg.pose.pose.orientation.x = 0.1; 
		pose_msg.pose.pose.orientation.y = 0.2; 
		pose_msg.pose.pose.orientation.z = 0.3;
		pose_msg.pose.pose.orientation.w = 1.0; 

		ROS_INFO("Sent pose number %d", pose_msg.header.seq); 

		chatter_pub.publish(pose_msg); 

		ros::spinOnce(); 
		loop_rate.sleep(); 
		++count; 
	}

	return 0; 
}