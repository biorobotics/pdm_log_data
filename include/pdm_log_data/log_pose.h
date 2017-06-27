#ifndef LOG_POSE_H_
#define LOG_POSE_H_

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

/// Class
class log_mypose{
public: 
	// Members
	geometry_msgs::PoseWithCovarianceStamped mypose_;
	ofstream* ofile_; 

	// Member Function
	void poseChatterCb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);

	// Constructor & Destructor
	log_mypose(ofstream* file_ptr);
	~log_mypose();
};


#endif // LOG_POSE_H_