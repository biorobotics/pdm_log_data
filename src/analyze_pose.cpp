#include <pdm_log_data/analyze_pose.h>

using namespace std;

AnalyzePose::AnalyzePose(void) {}

AnalyzePose::~AnalyzePose(void) {}

void AnalyzePose::setPaths(poselist_type ref, poselist_type comp)
{
	if (ref.size() > 1 && comp.size() > 0)
	{
		path_ref_ = ref; 
		path_comp_ = comp;	
	}
	else
		cout << "[Warning:] Not enough elements in one or both pose lists." << endl; 
}

double AnalyzePose::getRMSE(double scale_comp)
{
	if (path_ref_.size() <= 1 && path_comp_.size() == 0)
	{
		cout << "[Warning:] Not enough points in the list(s) to compute RMSE" << endl; 
		return -1.0; 
	}

	/*
	int i = 0;
	cout << "size of list" << path_ref_.size()<<endl; 
	for(poselist_type::const_iterator ite = path_ref_.begin(), end = path_ref_.end(); ite !=end; ++ite)
	{
		cout << i << " timestamp \t" << ite->header.stamp.sec << "." << ite->header.stamp.nsec << endl; 
		i++;	
	}*/

	cout << "\n Front Ref \t" << (path_ref_.front()).header.stamp.sec << "." << (path_ref_.front()).header.stamp.nsec << endl; 	
	cout << " Back Ref \t" << (path_ref_.back()).header.stamp.sec << "." << (path_ref_.back()).header.stamp.nsec << endl; 

	cout << " Front \t \t" << (path_comp_.front()).header.stamp.sec << "." << (path_comp_.front()).header.stamp.nsec << endl; 	
	cout << " Back \t\t" << (path_comp_.back()).header.stamp.sec << "." << (path_comp_.back()).header.stamp.nsec << endl << endl; 



	int j = 0; 
	while((path_comp_.front().header.stamp.sec  - (path_ref_.front()).header.stamp.sec < 0) || 
		 ((path_comp_.front().header.stamp.sec  - (path_ref_.front()).header.stamp.sec == 0) && 
		  (path_comp_.front().header.stamp.nsec - (path_ref_.front()).header.stamp.nsec < 0) ))
	{
		j++;  
		path_comp_.pop_front(); 
	}
	cout << "number front elements deleted: " << j << endl; 

	return 0.0; 

}

