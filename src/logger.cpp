#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <pdm_log_data/log_pose.h>

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	// Specify the full path and the name of your log file!
	string log_file1("/home/pea/Desktop/Log_results/log1.csv"); 
	string log_file2("/home/pea/Desktop/Log_results/log2.csv"); 
	// Specify the name of the node you want to save the pose from!
	string chatter_name1("pose_chatter1"); 
	string chatter_name2("pose_chatter2");

	ofstream myfile1; 
	ofstream myfile2; 
	//myfile1.open(log_file1.c_str(), ofstream::out | ofstream::app);
	//myfile2.open(log_file2.c_str(), ofstream::out | ofstream::app);
	myfile1.open(log_file1.c_str());
	myfile2.open(log_file2.c_str());
	
	myfile1 << " , Opened log_file:," << log_file1 << endl;
	myfile2 << " , Opened log_file:," << log_file2 << endl;

	LogPose log_object1(&myfile1, 1);
	LogPose log_object2(&myfile2, 2); 

	ros::init(argc, argv, "listener");
	ros::NodeHandle n1;
	ros::NodeHandle n2; 
	ros::Subscriber sub1 = n1.subscribe(chatter_name1, 1000, &LogPose::poseCb, &log_object1);
	ros::Subscriber sub2 = n2.subscribe(chatter_name2, 1000, &LogPose::poseCb, &log_object2);
	
	while(ros::ok())
	{
		ros::spinOnce();
	}


	myfile1<<endl;
	myfile2<<endl; 
	myfile1.close(); 
	myfile2.close();
	
	return 0; 
}