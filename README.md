# pdm_log_data

Logs incoming messages (different types can be declared in the main: src/logger.cpp) to .csv file format. Examples are provided in main (TODO: cleaner way?). Go to src/log_data.cpp to find class implementation, i.e. if you want add new types of messages that this csv-logger logs.

This repo is a catkin package and should be placed in <my_catkin_workspace>/src/pdm_log_data

Usage (after sourcing devel/setup.bash): rosrun pdm_log_data logger
