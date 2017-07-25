#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/TransformStamped.h>

#include <pdm_log_data/log_classes.h>

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	/// Specify the full path and the name of your log file!
	//string log_file1("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/vicon_1.csv"); 
	//string log_file2("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/svo_2.csv"); 
	//string log_file3("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/tfsvo_2.csv"); 
	string log_file4("/home/pea/Desktop/Log_results/logimu0.csv"); 
	string log_file0("/home/pea/Desktop/Log_results/log0.csv"); 

	/// Specify the name of the node you want to save the pose from!
	//string chatter_name1("/vicon/Goat2/Goat2");
	//string chatter_name2("/svo/pose"); 
	//string chatter_name3("/tf");
	string chatter_name4("/imu");
	string chatter_name0("pose_chatter2");
	

	//ofstream myfile1; 
	//ofstream myfile2; 
	//ofstream myfile3; 
	ofstream myfile4; 
	ofstream myfile0; 

	//myfile1.open(log_file1.c_str(), ofstream::out | ofstream::app);
	//myfile2.open(log_file2.c_str(), ofstream::out | ofstream::app);

	//myfile1.open(log_file1.c_str());
	//myfile2.open(log_file2.c_str());
	//myfile3.open(log_file3.c_str());
	myfile4.open(log_file4.c_str());
	myfile0.open(log_file0.c_str());
	

	//myfile1 << " , Opened log_file:," << log_file1 << endl;
	//myfile2 << " , Opened log_file:," << log_file2 << endl;
	//myfile3 << " , Opened log_file:," << log_file3 << endl;
	myfile4 << " , Opened log_file:," << log_file4 << endl;
	myfile0 << " , Opened log_file:," << log_file0 << endl;


	//LogPoseTransformStamped log_object1(&myfile1, 1); 		// myfile1 -> TransformStamped
	//LogPoseWCovStamped log_object2(&myfile2, 2); 				// myfile2 -> PoseWithCovarianceStamped 
	//LogPoseTf log_object3(&myfile3, 3, "world", "cam_pos"); 	// myfile3 -> tf pose
	LogImu log_object4(&myfile4,4); 							// myfile4 -> imu
	
	LogPoseWCovStamped log_object0(&myfile0, 0); 				// myfile0 -> PoseWithCovarianceStamped from pose_talker.cpp



	ros::init(argc, argv, "listener");

	//ros::NodeHandle n1;
	//ros::NodeHandle n2; 
	//ros::NodeHandle n3; 
	ros::NodeHandle n4; 
	ros::NodeHandle n0; 

	//ros::Subscriber sub1 = n1.subscribe(chatter_name1, 1000, &LogPoseTransformStamped::poseCb, &log_object1);
	//ros::Subscriber sub2 = n2.subscribe(chatter_name2, 1000, &LogPoseWCovStamped::poseCb, &log_object2);
	//ros::Subscriber sub3 = n3.subscribe(chatter_name3, 1000, &LogPoseTf::poseCb, &log_object3);
	ros::Subscriber sub4 = n4.subscribe(chatter_name4, 1000, &LogImu::imuCb, &log_object4); 
	ros::Subscriber sub0 = n0.subscribe(chatter_name0, 1000, &LogPoseWCovStamped::poseCb, &log_object0);
	
	while(ros::ok())
	{
		ros::spinOnce();
	}

	return 0; 
}