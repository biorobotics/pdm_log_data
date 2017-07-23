#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <pdm_log_data/log_pose.h>
//#include <pdm_log_data/analyze_pose.h>

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	/// Specify the full path and the name of your log file!
	//string log_file1("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/vicon_1.csv"); 
	//string log_file2("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/svo_2.csv"); 
	string log_file3("/media/pea/Windows7_OS/Users/Astrid/Desktop/dataset2/data_extraction/tfsvo_2.csv"); 
	//string log_file2("/home/pea/Desktop/Log_results/log2.csv"); 

	/// Specify the name of the node you want to save the pose from!
	//string chatter_name1("/vicon/Goat2/Goat2");
	//string chatter_name2("/svo/pose"); 
	string chatter_name3("/tf");
	//string chatter_name2("pose_chatter2");

	//ofstream myfile1; 
	//ofstream myfile2; 
	ofstream myfile3; 

	//myfile1.open(log_file1.c_str(), ofstream::out | ofstream::app);
	//myfile2.open(log_file2.c_str(), ofstream::out | ofstream::app);

	//myfile1.open(log_file1.c_str());
	//myfile2.open(log_file2.c_str());
	myfile3.open(log_file3.c_str());
	

	//myfile1 << " , Opened log_file:," << log_file1 << endl;
	//myfile2 << " , Opened log_file:," << log_file2 << endl;
	myfile3 << " , Opened log_file:," << log_file3 << endl;


	//LogPoseTransformStamped log_object1(&myfile1, 1); // myfile1 = TransformStamped
	//LogPosePoseWCovStamped log_object2(&myfile2, 2); 
	LogPoseTf log_object3(&myfile3, 3, "world", "cam_pos"); 	
	
	//AnalyzePose analyze_object; 


	ros::init(argc, argv, "listener");

	//ros::NodeHandle n1;
	//ros::NodeHandle n2; 
	ros::NodeHandle n3; 


	//ros::Subscriber sub1 = n1.subscribe(chatter_name1, 1000, &LogPoseTransformStamped::poseCb, &log_object1);
	//ros::Subscriber sub2 = n2.subscribe(chatter_name2, 1000, &LogPosePoseWCovStamped::poseCb, &log_object2);
	ros::Subscriber sub3 = n3.subscribe(chatter_name3, 1000, &LogPoseTf::poseCb, &log_object3);

	
	while(ros::ok())
	{
		ros::spinOnce();
	}

	//analyze_object.setPaths(log_object1.copyPoseList(), log_object2.copyPoseList());
	//double rmse = analyze_object.getRMSE(1.0);
	//cout << rmse << endl; 

	return 0; 
}