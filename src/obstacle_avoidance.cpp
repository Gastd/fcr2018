#include "fcr2017/obsavoidance.h"


ObstacleAvoidance::ObstacleAvoidance(ros::NodeHandle nh) : nh_(nh)
{
    vel_pub_ = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 1);
    laser_sub_ = nh_.subscribe("scan", 1, &ObstacleAvoidance::laserCallback, this);
    sonar_sub_ = nh_.subscribe("sonar", 1, &ObstacleAvoidance::sonarallback, this);
}

void ObstacleAvoidance::laserCallback(const sensor_msgs::LaserScan::ConstPtr& laser_msg)
{
    scan_msg_ = *laser_msg;
}

void ObstacleAvoidance::sonarCallback(const p2os_msgs::SonarArray::ConstPtr& sonar_msg)
{
    sonar_msg_ = *sonar_msg;
}

void ObstacleAvoidance::algorithm()
{
    // Escreva aqui seu codigo
}

void ObstacleAvoidance::spin()
{
    ros::Rate loop_rate(50);
    while(ros::ok())
    {
        ros::spinOnce();
        algorithm();
        vel_pub_.publish(command_vel_);
        loop_rate.sleep();
    }
}

ObstacleAvoidance::~ObstacleAvoidance()
{
}
