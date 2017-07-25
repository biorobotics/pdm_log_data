#ifndef LOG_CLASSES_H_
#define LOG_CLASSES_H_

#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_msgs/TFMessage.h>
#include <sensor_msgs/Imu.h>

#include <fstream>
#include <iostream>
#include <list>

using namespace std;

/// Class 1		geometry_msgs/TransformStamped
class LogPoseTransformStamped {
public: 
	int id_;
	ofstream* ofile_; 

	void poseCb(const geometry_msgs::TransformStamped::ConstPtr& msg);

	LogPoseTransformStamped(ofstream* file_ptr, int id);
	~LogPoseTransformStamped();
};

/// Class 2		geometry_msgs/PoseWithCovarianceStamped
class LogPoseWCovStamped {
public: 
	int id_;
	ofstream* ofile_; 
	
	void poseCb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);

	LogPoseWCovStamped(ofstream* file_ptr, int id);
	~LogPoseWCovStamped();
};

/// Class 3		tf2_msgs/TFMessage
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

/// Class 4		sensor_msgs/Imu
class LogImu {
public: 
	int id_;
	ofstream* ofile_; 
	
	/// Callback function in ros to read msg from a topic 
	void imuCb(const sensor_msgs::Imu::ConstPtr& msg);

	LogImu(ofstream* file_ptr, int id);
	~LogImu();
};


#endif // LOG_CLASSES_H_