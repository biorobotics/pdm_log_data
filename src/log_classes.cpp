#include <pdm_log_data/log_classes.h>

using namespace std;


/// Class 1		geometry_msgs/TransformStamped
// -----------------------------------------------------------------------------------------------
/// Constructor
LogPoseTransformStamped::LogPoseTransformStamped(ofstream* file_ptr, int id)
{
	id_ = id; 
	ofile_ = file_ptr; 


	if(ofile_->is_open())
	{
		cout << "{INFO} \tFile ready (id " << id_ << ")" << endl;
		(*ofile_)<< " , sec, nsec, pos_x, pos_y, pos_z, qw, qx, qy, qz,";
		(*ofile_)<< endl;		 
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. Description not created." << endl; 
		// TODO: implement proper error management!

}

/// Destructor 
LogPoseTransformStamped::~LogPoseTransformStamped(void)
{
	cout << "{INFO} \tClosing file (id " << id_ << ")" << endl;
	(*ofile_).close(); 
	// TODO: delet ofile pointer?
}

/// Member Function(s)
void LogPoseTransformStamped::poseCb(const geometry_msgs::TransformStamped::ConstPtr& msg)
{
	if (ofile_->is_open())
	{
		(*ofile_)<<msg->header.seq 					<< ",";
		(*ofile_)<<msg->header.stamp.sec 			<< ",";
		(*ofile_)<<msg->header.stamp.nsec 			<< ",";

		(*ofile_)<<msg->transform.translation.x 	<< ",";
		(*ofile_)<<msg->transform.translation.y 	<< ",";
		(*ofile_)<<msg->transform.translation.z 	<< ",";
		(*ofile_)<<msg->transform.rotation.w 		<< ",";
	
	(*ofile_)<<msg->transform.rotation.x 		<< ",";
		(*ofile_)<<msg->transform.rotation.y 		<< ",";
		(*ofile_)<<msg->transform.rotation.z 		<< ",";

		(*ofile_)<< "\n";
	}
	else 
		cout << "{Warning} \nFile (id " << id_ << ") not open. Pose not logged." << endl;
		// TODO: implement proper error management!
}



/// Class 2		geometry_msgs/PoseWithCovarianceStamped
// -----------------------------------------------------------------------------------------------
/// Constructor
LogPoseWCovStamped::LogPoseWCovStamped(ofstream* file_ptr, int id)
{
	id_ = id; 
	ofile_ = file_ptr; 

	
	if(ofile_->is_open())
	{
		cout << "{INFO} \tFile ready (id " << id_ << ")" << endl;

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
		cout << "{Warning} \tFile (id " << id_ << ") not open. Description not created." << endl; 
		// TODO: implement proper error management!
}

/// Destructor 
LogPoseWCovStamped::~LogPoseWCovStamped(void)
{
	cout << "{INFO} \tClosing file (id " << id_ << ")" << endl;
	(*ofile_).close();  
	// TODO: delete ofile pointer?
}

/// Member Function(s)
void LogPoseWCovStamped::poseCb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
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
		cout << "{Warning} \tFile (id " << id_ << ") not open. Pose not logged." << endl;
		// TODO: implement proper error management!
}



/// Class 3		tf2_msgs/TFMessage
// -----------------------------------------------------------------------------------------------
/// Constructor
LogPoseTf::LogPoseTf(ofstream* file_ptr, int id, string child_id_name, string id_name)
{
	child_frame_id_name_ = child_id_name; 
	frame_id_name_ = id_name; 
	id_ = id; 
	ofile_ = file_ptr; 

	if(ofile_->is_open())
	{
		cout << "{INFO} \tFile ready (id " << id_ << ")" << endl;

		(*ofile_)<< " , sec, nsec, pos_x, pos_y, pos_z, qw, qx, qy, qz,";
		(*ofile_)<< endl;		 
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. Description not created." << endl; 
		// TODO: implement proper error management!
}

/// Destructor 
LogPoseTf::~LogPoseTf(void)
{
	cout << "{INFO} \tClosing file (id " << id_ << ")" << endl;
	(*ofile_).close();  
	
	// TODO: delete ofile?
}

/// Member Function(s)
void LogPoseTf::poseCb(const tf2_msgs::TFMessage::ConstPtr& msg)
{
	if (ofile_->is_open())
		for(int i=0; i < msg->transforms.size(); i++)
		{
			if((child_frame_id_name_.compare(msg->transforms[i].child_frame_id) == 0) && 
				frame_id_name_.compare(msg->transforms[i].header.frame_id) == 0)
			{
				(*ofile_)<<msg->transforms[i].header.seq 				<< ",";
				(*ofile_)<<msg->transforms[i].header.stamp.sec 			<< ",";
				(*ofile_)<<msg->transforms[i].header.stamp.nsec 		<< ",";

				(*ofile_)<<msg->transforms[i].transform.translation.x 	<< ",";	
				(*ofile_)<<msg->transforms[i].transform.translation.y 	<< ",";
				(*ofile_)<<msg->transforms[i].transform.translation.z 	<< ",";
				(*ofile_)<<msg->transforms[i].transform.rotation.w 		<< ",";
				(*ofile_)<<msg->transforms[i].transform.rotation.x 		<< ",";
				(*ofile_)<<msg->transforms[i].transform.rotation.y 		<< ",";
				(*ofile_)<<msg->transforms[i].transform.rotation.z 		<< ",";

				(*ofile_)<< "\n";
			}
		}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. Pose not logged." << endl;
		// TODO: implement proper error management!
}



/// Class 4		sensor_msgs/Imu
// -----------------------------------------------------------------------------------------------
/// Constructor
LogImu::LogImu(ofstream* file_ptr, int id)
{
	id_ = id; 
	ofile_ = file_ptr; 

	if(ofile_->is_open())
	{
		cout << "{INFO} \tFile ready (id " << id_ << ")" << endl;

		(*ofile_)<< " , sec, nsec, linacc_x, linacc_y, linacc_z, qw, qx, qy, qz,"; 
		
		(*ofile_)<< endl;		 
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. Description not created." << endl; 
		// TODO: implement proper error management!
}

/// Destructor 
LogImu::~LogImu(void)
{
	cout << "{INFO} \tClosing file (id " << id_ << ")" << endl;
	(*ofile_).close();  
	
	// TODO: delete ofile?
}

/// Member Function(s)
void LogImu::imuCb(const sensor_msgs::Imu::ConstPtr& msg)
{
	
	if (ofile_->is_open())
	{
		(*ofile_)<<msg->header.seq 				<< ",";
		(*ofile_)<<msg->header.stamp.sec 		<< ",";
		(*ofile_)<<msg->header.stamp.nsec 		<< ",";

		(*ofile_)<<msg->linear_acceleration.x 	<< ",";
		(*ofile_)<<msg->linear_acceleration.y	<< ",";
		(*ofile_)<<msg->linear_acceleration.z	<< ",";

		(*ofile_)<<msg->orientation.w 			<< ",";
		(*ofile_)<<msg->orientation.x 			<< ",";
		(*ofile_)<<msg->orientation.y 			<< ",";
		(*ofile_)<<msg->orientation.z 			<< ",";

		(*ofile_)<< "\n";
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. Imu not logged." << endl;
		// TODO: implement proper error management!
}



/// Class 5		sensor_msgs/JointState
// -----------------------------------------------------------------------------------------------
/// Constructor
LogJointState::LogJointState(ofstream* file_ptr, int id, int nb_joints)
{
	id_ = id; 
	ofile_ = file_ptr; 
	nb_joints_ = nb_joints;

	if(ofile_->is_open())
	{
		cout << "{INFO} \tFile ready (id " << id_ << ")" << endl;

		(*ofile_)<< " , sec, nsec, "; 

		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< i << " position, "; 
		}	
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< i << " velocity, ";
		}
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< i << " effort, ";
		}
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< i << " name, ";
		}				

		(*ofile_)<< endl;		 
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. Description not created." << endl; 
		// TODO: implement proper error management!
}

/// Destructor 
LogJointState::~LogJointState(void)
{
	cout << "{INFO} \tClosing file (id " << id_ << ")" << endl;
	(*ofile_).close();  
	
	// TODO: delete ofile?
}

/// Member Function(s)
void LogJointState::jointStateCb(const sensor_msgs::JointState::ConstPtr& msg)
{
	if (ofile_->is_open())
	{
		(*ofile_)<<msg->header.seq 				<< ",";
		(*ofile_)<<msg->header.stamp.sec 		<< ",";
		(*ofile_)<<msg->header.stamp.nsec 		<< ",";

		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< setprecision(12) << msg->position[i]	<< ","; 
		}
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< setprecision(12) << msg->velocity[i]	<< ","; 
		}
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< setprecision(12) << msg->effort[i]	<< ","; 
		}
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<<msg->name[i]				<< ","; 
		}

		(*ofile_)<< "\n";
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. JointState not logged." << endl;
		// TODO: implement proper error management!
}