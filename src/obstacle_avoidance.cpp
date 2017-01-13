#include "fcr2017/obstacle_avoidance.h"


ObstacleAvoidance::ObstacleAvoidance(ros::NodeHandle nh) : nh_(nh)
{
    vel_pub_ = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 10);
    laser_sub_ = nh_.subscribe("hokuyo_scan", 10, &ObstacleAvoidance::laserCallback, this);
    dsr_sub_ = nh_.subscribe("desired_vel", 10, &ObstacleAvoidance::dsrCallback, this);
    sonar_sub_ = nh_.subscribe("sonar", 10, &ObstacleAvoidance::sonarCallback, this);
}

void ObstacleAvoidance::laserCallback(const sensor_msgs::LaserScan::ConstPtr& laser_msg)
{
    this->scan_msg_ = *laser_msg;
}

void ObstacleAvoidance::dsrCallback(const geometry_msgs::Twist::ConstPtr& desired_vel)
{
    this->desired_vel_ = *desired_vel;
}

void ObstacleAvoidance::sonarCallback(const p2os_msgs::SonarArray::ConstPtr& sonar_msg)
{
    this->sonar_msg_ = *sonar_msg;
}

void ObstacleAvoidance::algorithm()
{
    // Escreva aqui seu codigo

    command_vel_.linear.x = 0.0;
    command_vel_.angular.z = 0.0;
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
