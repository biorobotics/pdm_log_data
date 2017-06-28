#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include <sstream>
#include <iostream>
#include <fstream>

#include <pdm_log_data/log_pose.h>

using namespace std;

/// Constructor
log_mypose::log_mypose(ofstream* file_ptr, int id)
{
	id_ = id; 
	ofile_ = file_ptr;
	if(ofile_->is_open())
	{
		cout << "INFO: Ready to write to the specified file." << endl;
		(*ofile_)<< " , sec, nsec, pos_x, pos_y, pos_z, qw, qx, qy, qz" << endl; 
	}
	else // TODO: proper error function!
		cout << "ofile_ is not open!" << endl; 
}

/// Destructor 
log_mypose::~log_mypose(void)
{
	cout << "Destructor Invoked (log_mypose)" << endl;
}

/// Member Function(s)
void log_mypose::poseChatterCb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
	mypose_ = *msg;
	if (ofile_->is_open())
	{
		(*ofile_)<<msg->header.seq 				<< ",";
		(*ofile_)<<msg->header.stamp.sec 		<< ",";
		(*ofile_)<<msg->header.stamp.nsec 		<< ",";
		(*ofile_)<<msg->pose.pose.position.x 	<< ",";
		(*ofile_)<<msg->pose.pose.position.y 	<< ",";
		(*ofile_)<<msg->pose.pose.position.z 	<< ",";
		(*ofile_)<<msg->pose.pose.orientation.w << ",";
		(*ofile_)<<msg->pose.pose.orientation.x << ",";
		(*ofile_)<<msg->pose.pose.orientation.y << ",";
		(*ofile_)<<msg->pose.pose.orientation.z << "\n";

		// TODO: Also log the covariance matrix
	}
	else // TODO: implement proper error management!
		cout << "ofile_ is not open." << endl; 
}

// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------


int main(int argc, char **argv)
{
	string log_file1("/home/pea/Desktop/Log_results/log1.csv"); // Specify the full path and the name of your log file!
	string log_file2("/home/pea/Desktop/Log_results/log2.csv"); 
	string chatter_name1("pose_chatter1"); // Specify the name of the node you want to save the pose from!
	string chatter_name2("pose_chatter2");

	ofstream myfile1; 
	ofstream myfile2; 
	//myfile1.open(log_file1.c_str(), ofstream::out | ofstream::app);
	//myfile2.open(log_file2.c_str(), ofstream::out | ofstream::app);
	myfile1.open(log_file1.c_str());
	myfile2.open(log_file2.c_str());
	
	myfile1 << " , Opened log_file:," << log_file1 << endl;
	myfile2 << " , Opened log_file:," << log_file2 << endl;

	log_mypose log_object1(&myfile1, 1);
	log_mypose log_object2(&myfile2, 2); 

	ros::init(argc, argv, "listener");
	ros::NodeHandle n1;
	ros::NodeHandle n2; 
	ros::Subscriber sub1 = n1.subscribe(chatter_name1, 1000, &log_mypose::poseChatterCb, &log_object1);
	ros::Subscriber sub2 = n2.subscribe(chatter_name2, 1000, &log_mypose::poseChatterCb, &log_object2);
	
	while(ros::ok())
	{
		ros::spinOnce();
	}


	myfile1<<endl;
	myfile2<<endl; 

	myfile1.close(); // Never forget to close file!
	myfile2.close();
	return 0; 
}