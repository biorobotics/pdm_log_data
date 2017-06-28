#include <pdm_log_data/log_pose.h>

using namespace std;

/// Constructor
LogPose::LogPose(ofstream* file_ptr, int id)
{
	// TODO: Control that inputs are given, default constructor?
	id_ = id; 
	ofile_ = file_ptr;

	// TODO: implement proper error management!
	if(ofile_->is_open())
	{
		cout << "[INFO:] File ready (id " << id_ << ")" << endl;

		(*ofile_)<< " , sec, nsec, pos_x, pos_y, pos_z, qw, qx, qy, qz,";
		(*ofile_)<< "Cov11, Cov12, Cov13, Cov14, Cov15, Cov16,";
		(*ofile_)<< "Cov21, Cov22, Cov23, Cov24, Cov25, Cov26,";
		(*ofile_)<< "Cov31, Cov32, Cov33, Cov34, Cov35, Cov36,";
		(*ofile_)<< "Cov41, Cov42, Cov43, Cov44, Cov45, Cov46,";
		(*ofile_)<< "Cov51, Cov52, Cov53, Cov54, Cov55, Cov56,";
		(*ofile_)<< "Cov61, Cov62, Cov63, Cov64, Cov65, Cov66,";
		(*ofile_)<< endl;		 
	}
	else 
		cout << "[Warning:] File (id " << id_ << ") not open. Description not created." << endl; 
}

/// Destructor 
LogPose::~LogPose(void)
{
	cout << "[INFO:] Closing file (id " << id_ << ")" << endl;
	(*ofile_).close();  
}

/// Member Function(s)
void LogPose::poseCb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
	// TODO: implement proper error management!
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
		(*ofile_)<<msg->pose.pose.orientation.z << ",";
		for(int i = 0; i < 36; i++)
		{
			(*ofile_)<<msg->pose.covariance[i] << ",";	
		}
		(*ofile_)<< "\n";
	}
	else 
		cout << "[Warning:] File (id " << id_ << ") not open. Pose not logged." << endl;
}
