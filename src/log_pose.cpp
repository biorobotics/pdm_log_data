#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include <sstream>
#include <iostream>
#include <fstream>

#include <pdm_log_data/log_pose.h>

using namespace std;

/// Constructor
log_mypose::log_mypose(ofstream* file_ptr)
{
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

	// Specify the full path and the name of your log file!
	string log_file("/home/pea/Desktop/Log_results/log1.csv");

	ofstream myfile; 
	myfile.open(log_file.c_str(), ofstream::out | ofstream::app);
	//myfile.open(log_file.c_str()); // if you don't want the new data to be appended to an existing file but overwriting it.
	myfile << " , Opened log_file:," << log_file << endl;

	log_mypose log_object(&myfile); 

	ros::init(argc, argv, "listener");
	ros::NodeHandle n; 
	ros::Subscriber sub = n.subscribe("pose_chatter", 1000, &log_mypose::poseChatterCb, &log_object);

	while(ros::ok())
	{
		ros::spinOnce();
	}

	myfile<<endl; 
	myfile.close(); // TODO: when the pose_chatter node is shut down, the file should close too. Otherwise there is overwriting. 
	return 0; 
}