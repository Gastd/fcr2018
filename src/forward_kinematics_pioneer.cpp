#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "geometry_msgs/Twist.h"

std_msgs::Float32 vright, vleft;

void rightVelocityCallback(const std_msgs::Float32::ConstPtr& msg)
{
    vright.data = msg->data;
}

void leftVelocityCallback(const std_msgs::Float32::ConstPtr& msg)
{
    vleft.data = msg->data;
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "forward_kinematic_pioneer");
    ros::NodeHandle n;
    string right = "/v_right";
    string left = "/v_left";
    ros::Subscriber right_sub = n.subscribe(right, 10, rightVelocityCallback);
    ros::Subscriber left_sub = n.subscribe(left, 10, leftVelocityCallback);
    ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

    ros::Rate loop_rate(50);
    loop_rate.sleep();

    float vel_lin, vel_ang;

    while(ros::ok())
    {
        // forward kinematics
        vel_lin = vright.data/2 + vleft.data/2;
        vel_ang = (vright - vleft)/0.4;

        geometry_msgs::Twist vel;
        vel.linear.x = vel_lin;
        vel.angular.z = vel_ang;

        vel_pub.publish(vel);

        loop_rate.sleep();
        ros::spinOnce();
    }
}
