#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include <sstream>
#include <iostream>
#include <cmath>
#include <random>

using namespace std; 


const double PI = 3.1415926535897;


int main(int argc, char **argv)
{
	ros::init(argc,argv,"pose_talker");

	ros::NodeHandle n1;
	ros::NodeHandle n2; 
	ros::Publisher chatter_pub1 = n1.advertise<geometry_msgs::PoseWithCovarianceStamped>("pose_chatter1", 1000);
	ros::Publisher chatter_pub2 = n2.advertise<geometry_msgs::PoseWithCovarianceStamped>("pose_chatter2", 1000);
	ros::Rate loop_rate(1); 

	 
	double sin_amp = 10.0; 			// [m]
	double sin_amp_offset = 20.0; 	// [m]
	double sin_freq = 0.3; 			// [s⁻¹]
	double noise_var = 2.0; 
 

	ros::Time time_now = ros::Time::now();
	ros::Time time_previous = ros::Time::now();
	
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::normal_distribution<double> nd1(0.0,noise_var); 		// data noise
	std::normal_distribution<double> nd2(0.0,1000.0);			// data time delay
	std::normal_distribution<double> nd3(0.0,sin_amp*0.01); 	// data scale uncertainty (1%)
	int count = 0;

	while(ros::ok())
	{
		time_now = ros::Time::now(); 
		if (count == 0)
		{
			time_previous = time_now; 
			cout << "{INFO} \tPose talker talking" << endl;  
		}
		cout << count << " " << time_now << endl;
		cout << endl; 

		geometry_msgs::PoseWithCovarianceStamped pose_msg;  
		pose_msg.header.seq = count; 
		pose_msg.header.stamp.sec = time_now.sec; 
		pose_msg.header.stamp.nsec = time_now.nsec;
		pose_msg.pose.pose.position.x = 0.0; 
		pose_msg.pose.pose.position.y = 0.0; 
		pose_msg.pose.pose.position.z = sin_amp_offset + sin_amp * sin(sin_freq*2.0*PI*time_now.toSec());
		pose_msg.pose.pose.orientation.x = 0.0; 
		pose_msg.pose.pose.orientation.y = 0.0; 
		pose_msg.pose.pose.orientation.z = 0.0;
		pose_msg.pose.pose.orientation.w = 1.0; 


		chatter_pub1.publish(pose_msg);
		
		// simulates additive noise and scale uncertainty
		pose_msg.pose.pose.position.z = nd3(gen)*(pose_msg.pose.pose.position.z + nd1(gen)); 
		// simulates that the data might not be coming at regular intervals
		int lag = (int)abs(nd2(gen)); 
		if (lag > 10^(9))
			lag = 10^(9) -100; 
		pose_msg.header.stamp.nsec = time_now.nsec + lag; 


		chatter_pub2.publish(pose_msg); 

		cout << time_now - time_previous << endl; 
		time_previous = time_now; 

		ros::spinOnce(); 
		loop_rate.sleep(); 
		++count; 

	}
	cout << "{INFO} \tPose talker not talking anymore" << endl; 

	return 0; 
}