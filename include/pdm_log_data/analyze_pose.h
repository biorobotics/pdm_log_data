#ifndef ANALYZE_POSE_H_
#define ANALYZE_POSE_H_

#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <fstream>
#include <iostream>
#include <list>

#include <pdm_log_data/log_pose.h>

using namespace std;
typedef list<geometry_msgs::TransformStamped> poselist_type;

class AnalyzePose{
public:
	
	poselist_type path_ref_; 
	poselist_type path_comp_; 

	void setPaths(poselist_type ref, poselist_type comp); 
	double getRMSE(double scale_comp = 1.0); 


	AnalyzePose(void);
	~AnalyzePose(void);
};

#endif // ANALYZE_POSE_H_