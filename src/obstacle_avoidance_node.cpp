#include "fcr2017/obstacle_avoidance.h"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "obsavoidance");
    ros::NodeHandle n;
    ObstacleAvoidance obsavoidance(n);
    obsavoidance.spin();
}
