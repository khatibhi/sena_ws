#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <iostream>

void vel1(const std_msgs::Float64::ConstPtr &msg_motor){
    ROS_INFO("Vel1 : [%f]", msg_motor->data);
}

void vel2(const std_msgs::Float64::ConstPtr &msg_motor){
    ROS_INFO("Vel2 : [%f]", msg_motor->data);
}

void vel3(const std_msgs::Float64::ConstPtr &msg_motor){
    ROS_INFO("Vel3 : [%f]", msg_motor->data);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "sena_controller");
    ros::NodeHandle nh;
    ros::Subscriber m1;
    ros::Subscriber m2;
    ros::Subscriber m3;
    ros::Rate r(5);
    while (ros::ok()){
        m1 = nh.subscribe("/sena/right_joint_velocity_controller/command", 10, vel1);
        m2 = nh.subscribe("/sena/left_joint_velocity_controller/command", 10, vel2);
        m3 = nh.subscribe("/sena/back_joint_velocity_controller/command", 10, vel3);
        r.sleep();
        ros::spin();    
    }
    return 0;
}

