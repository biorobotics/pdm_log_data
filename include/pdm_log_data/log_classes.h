#ifndef LOG_CLASSES_H_
#define LOG_CLASSES_H_

#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_msgs/TFMessage.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/JointState.h>

#include <fstream>
#include <iostream>
#include <list>

using namespace std;

/// Class 1			geometry_msgs/TransformStamped
/// Topic name(s):	/vicon/Goat2/Goat2
///					/pose_chatterX (testing)					
class LogPoseTransformStamped {
public: 
	int id_;
	ofstream* ofile_; 

	void poseCb(const geometry_msgs::TransformStamped::ConstPtr& msg);

	LogPoseTransformStamped(ofstream* file_ptr, int id);
	~LogPoseTransformStamped();
};

/// Class 2			geometry_msgs/PoseWithCovarianceStamped
/// Topic name:		/svo/pose
class LogPoseWCovStamped {
public: 
	int id_;
	ofstream* ofile_; 
	
	void poseCb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);

	LogPoseWCovStamped(ofstream* file_ptr, int id);
	~LogPoseWCovStamped();
};

/// Class 3			tf2_msgs/TFMessage
/// Topic name: 	/tf
class LogPoseTf {
public: 
	int id_;
	ofstream* ofile_; 

	string child_frame_id_name_; 
	string frame_id_name_; 
	
	/// Callback function in ros to read msg from a topic 
	void poseCb(const tf2_msgs::TFMessage::ConstPtr& msg);

	LogPoseTf(ofstream* file_ptr, int id, string child_id_name, string id_name);
	~LogPoseTf();
};

/// Class 4			sensor_msgs/Imu
/// Topic name:		/imu
class LogImu {
public: 
	int id_;
	ofstream* ofile_; 
	
	/// Callback function in ros to read msg from a topic 
	void imuCb(const sensor_msgs::Imu::ConstPtr& msg);

	LogImu(ofstream* file_ptr, int id);
	~LogImu();
};

/// Class 5			sensor_msgs/JointSpace
/// Topic name: 	/jointState
class LogJointState {
public: 
	int id_;
	ofstream* ofile_; 
	int nb_joints_; 
	
	/// Callback function in ros to read msg from a topic 
	void jointStateCb(const sensor_msgs::JointState::ConstPtr& msg);

	LogJointState(ofstream* file_ptr, int id, int nb_joints);
	~LogJointState();
};


/// Class 6			std_msgs/Header
/// Topic name: 	/time
class LogSimTime {
public: 
	int id_;
	ofstream* ofile_; 
	
	/// Callback function in ros to read msg from a topic 
	void simTimeCb(const std_msgs::Header::ConstPtr& msg);

	LogSimTime(ofstream* file_ptr, int id);
	~LogSimTime();
};



#endif // LOG_CLASSES_H_