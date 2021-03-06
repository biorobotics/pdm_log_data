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
		(*ofile_)<< " , sec, nsec, pos.x, pos.y, pos.z, q.w, q.x, q.y, q.z,";
		(*ofile_)<< "time_logmsg_in.sec, time_logmsg_in.nsec" << endl;			 
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
		ros::Time timestamp_in = ros::Time::now(); 
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

		(*ofile_) << timestamp_in.sec << "," << timestamp_in.nsec << endl;
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

		(*ofile_)<< "time_logmsg_in.sec, time_logmsg_in.nsec" << endl;			 
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
		ros::Time timestamp_in = ros::Time::now(); 
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

		(*ofile_) << timestamp_in.sec << "," << timestamp_in.nsec << endl;
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

		(*ofile_)<< " , sec, nsec, pos.x, pos.y, pos.z, q.w, q.x, q.y, q.z,";
		(*ofile_)<< "time_logmsg_in.sec, time_logmsg_in.nsec" << endl;			 
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
	{
		ros::Time timestamp_in = ros::Time::now(); 
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

				(*ofile_) << timestamp_in.sec << "," << timestamp_in.nsec << endl;
			}
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
		
		(*ofile_)<< "time_logmsg_in.sec, time_logmsg_in.nsec" << endl;			 
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
		ros::Time timestamp_in = ros::Time::now(); 
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

		(*ofile_) << timestamp_in.sec << "," << timestamp_in.nsec << endl;
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
			(*ofile_)<< i << " position [deg], "; 
		}	
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< i << " velocity [krpm], ";
		}
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< i << " effort [Nm], ";
		}
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<< i << " name, ";
		}				

		(*ofile_)<< "time_logmsg_in.sec, time_logmsg_in.nsec" << endl;			 
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
		ros::Time timestamp_in = ros::Time::now(); 
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
			(*ofile_)<< setprecision(12) << msg->effort[i]		<< ","; 
		}
		for (int i = 0; i < nb_joints_; i++)
		{
			(*ofile_)<<msg->name[i]								<< ","; 
		}

		(*ofile_) << timestamp_in.sec << "," << timestamp_in.nsec << endl;
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. JointState not logged." << endl;
		// TODO: implement proper error management!
}



/// Class 6		std_msgs/Header
// -----------------------------------------------------------------------------------------------
/// Constructor
LogSimTime::LogSimTime(ofstream* file_ptr, int id)
{
	id_ = id; 
	ofile_ = file_ptr; 

	if(ofile_->is_open())
	{
		cout << "{INFO} \tFile ready (id " << id_ << ")" << endl;

		(*ofile_)<< " , sec, nsec,"; 
		
		(*ofile_)<< "time_logmsg_in.sec, time_logmsg_in.nsec" << endl;		 
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. Description not created." << endl; 
		// TODO: implement proper error management!
}

/// Destructor 
LogSimTime::~LogSimTime(void)
{
	cout << "{INFO} \tClosing file (id " << id_ << ")" << endl;
	(*ofile_).close();  
	
	// TODO: delete ofile?
}

/// Member Function(s)
void LogSimTime::simTimeCb(const std_msgs::Header::ConstPtr& msg)
{
	
	if (ofile_->is_open())
	{
		ros::Time timestamp_in = ros::Time::now(); 
		(*ofile_)<<msg->seq 			<< ",";
		(*ofile_)<<msg->stamp.sec 		<< ",";
		(*ofile_)<<msg->stamp.nsec 		<< ",";

		(*ofile_) << timestamp_in.sec << "," << timestamp_in.nsec << endl;
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. SimTime not logged." << endl;
		// TODO: implement proper error management!
}


/// Class 7		std_msgs/Float32MultiArray
// -----------------------------------------------------------------------------------------------
/// Constructor
LogCustom::LogCustom(ofstream* file_ptr, int id, int nb_elements, string custom_name, bool reverse_order)
{
	id_ = id; 
	ofile_ = file_ptr; 
	nb_elements_ = nb_elements; 
	custom_name_ = custom_name; 
	reverse_order_ = reverse_order; 

	if(ofile_->is_open())
	{
		cout << "{INFO} \tFile ready (id " << id_ << ")" << endl;

		if(nb_elements_ == 6 && custom_name_.compare("params") == 0)
		{
			(*ofile_)<< "state [1:air 2:ground], kpRadialVirtual [N/inch], inAirRadius [inch], thrust [N], kpJump [N/inch], atBottomRadius [inch], ";	
		}

		else if (nb_elements_ == 13 && custom_name_.compare("pose") == 0)
		{
			(*ofile_)<< "r [inch], theta [rad], phi [rad], pose.x [inch], pose.y [inch], pose.z [inch], q.x, q.y, q.z, q.w, roll [deg], pitch [deg], yaw [deg], "; 
		}

		else if (nb_elements_ == 16 && custom_name_.compare(0, 6, "kfinfo") == 0)
		{
			(*ofile_)<< "z_seq, z_sec, z_nsec, x(0), x(1), P(0 0), P(0 1), P(1 0), P(1 1), K(0), K(1), y_pre, y_post, z_dt, lag_dt, processing_dt, "; 
		} 
		else	
		{
			for(int i = 0; i < nb_elements_; i++)
			{
				(*ofile_)<< "[" << i << "], "; 
			}
		}

		(*ofile_)<< "time_logmsg_in.sec, time_logmsg_in.nsec" << endl;		 
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. Description not created." << endl; 
		// TODO: implement proper error management!
}

/// Destructor 
LogCustom::~LogCustom(void)
{
	cout << "{INFO} \tClosing file (id " << id_ << ")" << endl;
	(*ofile_).close();  
	
	// TODO: delete ofile?
}

/// Member Function(s)
void LogCustom::customCb(const std_msgs::Float32MultiArray::ConstPtr& msg)
{
	
	if (ofile_->is_open())
	{
		ros::Time timestamp_in = ros::Time::now(); 
		for (int i = 0; i < nb_elements_; i++)
		{
			if(reverse_order_ == false)
			{
				(*ofile_)<< setprecision(12) << msg->data[i] << ",";	
			}
			else
			{
				(*ofile_)<< setprecision(12) << msg->data[nb_elements_ - i - 1] << ",";
			}
		}
		(*ofile_) << timestamp_in.sec << "," << timestamp_in.nsec << endl;
	}
	else 
		cout << "{Warning} \tFile (id " << id_ << ") not open. Custom message not logged." << endl;
		// TODO: implement proper error management!
}
