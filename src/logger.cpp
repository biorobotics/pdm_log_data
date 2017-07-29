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
	
	string log_file0("/home/pea/Desktop/Log_results/log0_posechatter.csv");
	string log_file0p11("/home/pea/Desktop/Log_results/log0_kfpose_m1_1.csv");
	string log_file0p21("/home/pea/Desktop/Log_results/log0_kfpose_m2_1.csv");
	string log_file0p31("/home/pea/Desktop/Log_results/log0_kfpose_m3_1.csv");
	string log_file0i11("/home/pea/Desktop/Log_results/log0_kfinfo_m1_1.csv");
	string log_file0i21("/home/pea/Desktop/Log_results/log0_kfinfo_m2_1.csv");
	string log_file0i31("/home/pea/Desktop/Log_results/log0_kfinfo_m3_1.csv");

	//string log_file1("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/vicon_1.csv"); 
	//string log_file2("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/svo_2.csv"); 
	//string log_file3("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/tfsvo_2.csv"); 
	//string log_file4("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/imu.csv"); 
	//string log_file5("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/jointState.csv"); 
	//string log_file6("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/simTime.csv"); 
	//string log_file7("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/goatPose.csv"); 
	//string log_file8("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/goatParam.csv"); 
	 
	/// Specify the name of the node you want to save the pose from!
	
	string chatter_name0("/pose_chatter2");
	string chatter_name0p11("/kfpose_m1_1");
	string chatter_name0p21("/kfpose_m2_1");
	string chatter_name0p31("/kfpose_m3_1");
	string chatter_name0i11("/kfinfo_m1_1");
	string chatter_name0i21("/kfinfo_m2_1");
	string chatter_name0i31("/kfinfo_m3_1");

	//string chatter_name1("/vicon/Goat2/Goat2");
	//string chatter_name2("/svo/pose"); 
	//string chatter_name3("/tf");
	//string chatter_name4("/imu");
	//string chatter_name5("/jointState");
	//string chatter_name6("/time");
	//string chatter_name7("/pose");
	//string chatter_name8("/params");
	
	ofstream myfile0;
	ofstream myfile0p11;
	ofstream myfile0p21;
	ofstream myfile0p31;	
	ofstream myfile0i11;	
	ofstream myfile0i21;
	ofstream myfile0i31;
	//ofstream myfile1; 
	//ofstream myfile2; 
	//ofstream myfile3; 
	//ofstream myfile4; 
	//ofstream myfile5; 
	//ofstream myfile6;
	//ofstream myfile7; 
	//ofstream myfile8;  
	
	/*
	/// to append to an existing file instead of overwriting
	myfile0.open(log_file0.c_str(), ofstream::out | ofstream::app);
	*/

	myfile0.open(log_file0.c_str());
	myfile0p11.open(log_file0p11.c_str());
	myfile0p21.open(log_file0p21.c_str());
	myfile0p31.open(log_file0p31.c_str());
	myfile0i11.open(log_file0i11.c_str());
	myfile0i21.open(log_file0i21.c_str());
	myfile0i31.open(log_file0i31.c_str());
	//myfile1.open(log_file1.c_str());
	//myfile2.open(log_file2.c_str());
	//myfile3.open(log_file3.c_str());
	//myfile4.open(log_file4.c_str());
	//myfile5.open(log_file5.c_str());
	//myfile6.open(log_file6.c_str());
	//myfile7.open(log_file7.c_str());
	//myfile8.open(log_file8.c_str());

	myfile0 << " , Opened log_file:," << log_file0 << endl;
	myfile0p11 << " , Opened log_file:," << log_file0p11 << endl;
	myfile0p21 << " , Opened log_file:," << log_file0p21 << endl;
	myfile0p31 << " , Opened log_file:," << log_file0p31 << endl;
	myfile0i11 << " , Opened log_file:," << log_file0i11 << endl;
	myfile0i21 << " , Opened log_file:," << log_file0i21 << endl;
	myfile0i31 << " , Opened log_file:," << log_file0i31 << endl;
	//myfile1 << " , Opened log_file:," << log_file1 << endl;
	//myfile2 << " , Opened log_file:," << log_file2 << endl;
	//myfile3 << " , Opened log_file:," << log_file3 << endl;
	//myfile4 << " , Opened log_file:," << log_file4 << endl;
	//myfile5 << " , Opened log_file:," << log_file5 << endl;
	//myfile6 << " , Opened log_file:," << log_file6 << endl;
	//myfile7 << " , Opened log_file:," << log_file7 << endl;
	//myfile8 << " , Opened log_file:," << log_file8 << endl;
	
	LogPoseWCovStamped log_object0(&myfile0, 0); 				// myfile0 -> PoseWithCovarianceStamped from pose_talker.cpp
	LogPoseWCovStamped log_object0p11(&myfile0p11, 11);
	LogPoseWCovStamped log_object0p21(&myfile0p21, 21);
	LogPoseWCovStamped log_object0p31(&myfile0p31, 31);
	LogCustom log_object0i11(&myfile0i11, 11, 16, "kfinfo_m1_1", false);
	LogCustom log_object0i21(&myfile0i21, 11, 16, "kfinfo_m2_1", false);
	LogCustom log_object0i31(&myfile0i31, 11, 16, "kfinfo_m3_1", false);
	//LogPoseTransformStamped log_object1(&myfile1, 1); 		// myfile1 -> TransformStamped
	//LogPoseWCovStamped log_object2(&myfile2, 2); 				// myfile2 -> PoseWithCovarianceStamped 
	//LogPoseTf log_object3(&myfile3, 3, "world", "cam_pos"); 	// myfile3 -> tf pose (give the different frame-ids)
	//LogImu log_object4(&myfile4,4); 							// myfile4 -> imu
	//LogJointState log_object5(&myfile5, 5, 3); 					// myfile5 -> JointState (give the number of joints)
	//LogSimTime log_object6(&myfile6, 6); 						// myfile6 -> Header (Simulated time) 	
	//LogCustom log_object7(&myfile7, 7, 13, "pose", true); 		// myfile7 -> Custom Array message 
	//LogCustom log_object8(&myfile8, 8, 6, "params", true);		// myfile8 -> Custom Array message
	
	ros::init(argc, argv, "logger");

	ros::NodeHandle nh; 
	 
	ros::Subscriber sub0 = nh.subscribe(chatter_name0, 1000, &LogPoseWCovStamped::poseCb, &log_object0);
	ros::Subscriber sub0p11 = nh.subscribe(chatter_name0p11, 1000, &LogPoseWCovStamped::poseCb, &log_object0p11);
	ros::Subscriber sub0p21 = nh.subscribe(chatter_name0p21, 1000, &LogPoseWCovStamped::poseCb, &log_object0p21);
	ros::Subscriber sub0p31 = nh.subscribe(chatter_name0p31, 1000, &LogPoseWCovStamped::poseCb, &log_object0p31);
	ros::Subscriber sub0i11 = nh.subscribe(chatter_name0i11, 1000, &LogCustom::customCb, &log_object0i11);
	ros::Subscriber sub0i21 = nh.subscribe(chatter_name0i21, 1000, &LogCustom::customCb, &log_object0i21);
	ros::Subscriber sub0i31 = nh.subscribe(chatter_name0i31, 1000, &LogCustom::customCb, &log_object0i31);
	//ros::Subscriber sub1 = nh.subscribe(chatter_name1, 1000, &LogPoseTransformStamped::poseCb, &log_object1);
	//ros::Subscriber sub2 = nh.subscribe(chatter_name2, 1000, &LogPoseWCovStamped::poseCb, &log_object2);
	//ros::Subscriber sub3 = nh.subscribe(chatter_name3, 1000, &LogPoseTf::poseCb, &log_object3);
	//ros::Subscriber sub4 = nh.subscribe(chatter_name4, 1000, &LogImu::imuCb, &log_object4); 
	//ros::Subscriber sub5 = nh.subscribe(chatter_name5, 1000, &LogJointState::jointStateCb, &log_object5); 
	//ros::Subscriber sub6 = nh.subscribe(chatter_name6, 1000, &LogSimTime::simTimeCb, &log_object6);
	//ros::Subscriber sub7 = nh.subscribe(chatter_name7, 1000, &LogCustom::customCb, &log_object7);
	//ros::Subscriber sub8 = nh.subscribe(chatter_name8, 1000, &LogCustom::customCb, &log_object8);
	
	while(ros::ok())
	{
		ros::spinOnce();
	}

	return 0; 
}