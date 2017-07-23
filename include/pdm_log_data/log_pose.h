#ifndef LOG_POSE_H_
#define LOG_POSE_H_

#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_msgs/TFMessage.h>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;
typedef list<geometry_msgs::TransformStamped> poselistTS_type;
typedef list<geometry_msgs::PoseWithCovarianceStamped> poselistPWCS_type; 
typedef list<tf2_msgs::TFMessage> poselistTf_type; 

/// Class
class LogPoseTransformStamped {
public: 
	int id_;
	ofstream* ofile_; 
	poselistTS_type poseList_; 
	
	/// Callback function in ros to read msg from a topic 
	void poseCb(const geometry_msgs::TransformStamped::ConstPtr& msg);

	/// Access the list with the accumulated poses
	poselistTS_type copyPoseList(void); 

	LogPoseTransformStamped(ofstream* file_ptr, int id);
	~LogPoseTransformStamped();
};

class LogPosePoseWCovStamped {
public: 
	int id_;
	ofstream* ofile_; 
	poselistPWCS_type poseList_; 
	
	/// Callback function in ros to read msg from a topic 
	void poseCb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);

	/// Access the list with the accumulated poses
	poselistPWCS_type copyPoseList(void); 

	LogPosePoseWCovStamped(ofstream* file_ptr, int id);
	~LogPosePoseWCovStamped();
};

class LogPoseTf {
public: 
	int id_;
	ofstream* ofile_; 
	poselistTf_type poseList_; 
	string child_frame_id_name_; 
	string frame_id_name_; 
	
	/// Callback function in ros to read msg from a topic 
	void poseCb(const tf2_msgs::TFMessage::ConstPtr& msg);

	/// Access the list with the accumulated poses
	poselistTf_type copyPoseList(void); 

	LogPoseTf(ofstream* file_ptr, int id, string child_id_name, string id_name);
	~LogPoseTf();
};





#endif // LOG_POSE_H_