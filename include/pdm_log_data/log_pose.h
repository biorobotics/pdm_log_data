#ifndef LOG_POSE_H_
#define LOG_POSE_H_

#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_msgs/TFMessage.h>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

/// Class 1
class LogPoseTransformStamped {
public: 
	int id_;
	ofstream* ofile_; 

	void poseCb(const geometry_msgs::TransformStamped::ConstPtr& msg);

	LogPoseTransformStamped(ofstream* file_ptr, int id);
	~LogPoseTransformStamped();
};

/// Class 2
class LogPosePoseWCovStamped {
public: 
	int id_;
	ofstream* ofile_; 
	
	void poseCb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);

	LogPosePoseWCovStamped(ofstream* file_ptr, int id);
	~LogPosePoseWCovStamped();
};

/// Class 3
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

/// Class 4
/*
class LogImu {
public: 
	int id_; 
	ofstream* ofile_; 

	/// Callback function in ros to read msg from a topic
	voic imuCb(const )

};

*/


#endif // LOG_POSE_H_