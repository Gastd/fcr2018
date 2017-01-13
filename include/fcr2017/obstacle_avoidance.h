#include <vector>
#include <string>
#include <ros/ros.h>
#include <ros/console.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <p2os_msgs/SonarArray.h>



class ObstacleAvoidance
{
public:
    ObstacleAvoidance(ros::NodeHandle nh);
    void spin();
    ~ObstacleAvoidance();

private:
    ros::NodeHandle nh_;
    ros::Publisher vel_pub_;
    ros::Subscriber laser_sub_, sonar_sub_, dsr_sub_;

    geometry_msgs::Twist command_vel_, desired_vel_;
    sensor_msgs::LaserScan scan_msg_;
    p2os_msgs::SonarArray sonar_msg_;

    void laserCallback(const sensor_msgs::LaserScan::ConstPtr& laser_msg);
    void sonarCallback(const p2os_msgs::SonarArray::ConstPtr& sonar_msg);
    void dsrCallback(const geometry_msgs::Twist::ConstPtr& desired_vel);

    void algorithm();
};
