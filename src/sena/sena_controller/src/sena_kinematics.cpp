#include "ros/ros.h"
#include "sena_msgs/Velocity.h"
#include "geometry_msgs/Twist.h"
#include <iostream>

ros::Publisher v_leftCommand;
ros::Publisher v_rightCommand;
ros::Publisher v_backCommand;

long double L = 0.135;

void vel(const geometry_msgs::Twist &msg){
    float Vx = msg.linear.x;
    float Vy = msg.linear.y;
    float Vz = msg.angular.z;

    ROS_INFO("Vel Vmx = [%f]", Vx);
    ROS_INFO("Vel Vmy = [%f]", Vy);
    ROS_INFO("Vel Vmz = [%f]", Vz);
}

// void vel2(const std_msgs::Float64::ConstPtr &msg_motor){
    
// }

// void vel3(const std_msgs::Float64::ConstPtr &msg_motor){
    
// }

int main(int argc, char** argv){
    ros::init(argc, argv, "sena_kinematics");
    ros::NodeHandle nh;
    ros::Subscriber m;
    // ros::Subscriber m1;
    // ros::Subscriber m2;
    // ros::Subscriber m3;
    ros::Rate r(5);
    while (ros::ok()){
        m = nh.subscribe("/cmd_vel", 10, vel);
        // m1 = nh.subscribe("/sena/right_joint_velocity_controller/command", 10, vel1);
        // m2 = nh.subscribe("/sena/left_joint_velocity_controller/command", 10, vel2);
        // m3 = nh.subscribe("/sena/back_joint_velocity_controller/command", 10, vel3);
        r.sleep();
        ros::spin();    
    }
    return 0;
}