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
	
	//string log_file0("/home/pea/Desktop/Log_results/log0.csv");
	//string log_file1("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/vicon_1.csv"); 
	//string log_file2("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/svo_2.csv"); 
	//string log_file3("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/tfsvo_2.csv"); 
	string log_file4("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/imu.csv"); 
	string log_file5("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/jointState.csv"); 
	string log_file6("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/simTime.csv"); 
	string log_file7("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/effPose.csv"); 
	string log_file8("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/goatParam.csv"); 
	 
	/// Specify the name of the node you want to save the pose from!
	
	//string chatter_name0("pose_chatter2");
	//string chatter_name1("/vicon/Goat2/Goat2");
	//string chatter_name2("/svo/pose"); 
	//string chatter_name3("/tf");
	string chatter_name4("/imu");
	string chatter_name5("/jointState");
	string chatter_name6("/time");
	string chatter_name7("/pose");
	string chatter_name8("/params");
	
	//ofstream myfile0; 
	//ofstream myfile1; 
	//ofstream myfile2; 
	//ofstream myfile3; 
	ofstream myfile4; 
	ofstream myfile5; 
	ofstream myfile6;
	ofstream myfile7; 
	ofstream myfile8;  
	
	/*
	myfile1.open(log_file1.c_str(), ofstream::out | ofstream::app);
	myfile2.open(log_file2.c_str(), ofstream::out | ofstream::app);
	*/

	//myfile0.open(log_file0.c_str());
	//myfile1.open(log_file1.c_str());
	//myfile2.open(log_file2.c_str());
	//myfile3.open(log_file3.c_str());
	myfile4.open(log_file4.c_str());
	myfile5.open(log_file5.c_str());
	myfile6.open(log_file6.c_str());
	myfile7.open(log_file7.c_str());
	myfile8.open(log_file8.c_str());

	//myfile0 << " , Opened log_file:," << log_file0 << endl;
	//myfile1 << " , Opened log_file:," << log_file1 << endl;
	//myfile2 << " , Opened log_file:," << log_file2 << endl;
	//myfile3 << " , Opened log_file:," << log_file3 << endl;
	myfile4 << " , Opened log_file:," << log_file4 << endl;
	myfile5 << " , Opened log_file:," << log_file5 << endl;
	myfile6 << " , Opened log_file:," << log_file6 << endl;
	myfile7 << " , Opened log_file:," << log_file7 << endl;
	myfile8 << " , Opened log_file:," << log_file8 << endl;
	
	//LogPoseWCovStamped log_object0(&myfile0, 0); 				// myfile0 -> PoseWithCovarianceStamped from pose_talker.cpp
	//LogPoseTransformStamped log_object1(&myfile1, 1); 		// myfile1 -> TransformStamped
	//LogPoseWCovStamped log_object2(&myfile2, 2); 				// myfile2 -> PoseWithCovarianceStamped 
	//LogPoseTf log_object3(&myfile3, 3, "world", "cam_pos"); 	// myfile3 -> tf pose (give the different frame-ids)
	LogImu log_object4(&myfile4,4); 							// myfile4 -> imu
	LogJointState log_object5(&myfile5, 5, 3); 					// myfile5 -> JointState (give the number of joints)
	LogSimTime log_object6(&myfile6, 6); 						// myfile6 -> Header (Simulated time) 	
	LogCustom log_object7(&myfile7, 7, 13, "pose", true); 		// myfile7 -> Custom Array message 
	LogCustom log_object8(&myfile8, 8, 6, "params", true);		// myfile8 -> Custom Array message
	

	ros::init(argc, argv, "listener");

	//ros::NodeHandle n0;
	//ros::NodeHandle n1;
	//ros::NodeHandle n2; 
	//ros::NodeHandle n3; 
	ros::NodeHandle n4; 
	ros::NodeHandle n5; 
	ros::NodeHandle n6; 
	ros::NodeHandle n7; 
	ros::NodeHandle n8; 
	 
	//ros::Subscriber sub0 = n0.subscribe(chatter_name0, 1000, &LogPoseWCovStamped::poseCb, &log_object0);
	//ros::Subscriber sub1 = n1.subscribe(chatter_name1, 1000, &LogPoseTransformStamped::poseCb, &log_object1);
	//ros::Subscriber sub2 = n2.subscribe(chatter_name2, 1000, &LogPoseWCovStamped::poseCb, &log_object2);
	//ros::Subscriber sub3 = n3.subscribe(chatter_name3, 1000, &LogPoseTf::poseCb, &log_object3);
	ros::Subscriber sub4 = n4.subscribe(chatter_name4, 1000, &LogImu::imuCb, &log_object4); 
	ros::Subscriber sub5 = n5.subscribe(chatter_name5, 1000, &LogJointState::jointStateCb, &log_object5); 
	ros::Subscriber sub6 = n6.subscribe(chatter_name6, 1000, &LogSimTime::simTimeCb, &log_object6);
	ros::Subscriber sub7 = n7.subscribe(chatter_name7, 1000, &LogCustom::customCb, &log_object7);
	ros::Subscriber sub8 = n8.subscribe(chatter_name8, 1000, &LogCustom::customCb, &log_object8);
	
	while(ros::ok())
	{
		ros::spinOnce();
	}

	return 0; 
}