#ifndef LOG_POSE_H_
#define LOG_POSE_H_

#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <fstream>
#include <iostream>

using namespace std;

/// Class
class LogPose {
public: 
	int id_;
	ofstream* ofile_; 
	 
	void poseCb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);

	LogPose(ofstream* file_ptr, int id);
	~LogPose();
};

class Analyze2PosePaths {
public: 
};

#endif // LOG_POSE_H_