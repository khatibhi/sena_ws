#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "rospy_tutorials/Floats.h"
#include <iostream>

void enc1_Cb(const std_msgs::Float32::ConstPtr& msg){
    ROS_INFO("data enc1 : [%f]", msg->data);
}

void enc2_Cb(const std_msgs::Float32::ConstPtr& msg){
    ROS_INFO("data enc2 : [%f]", msg->data);
}

void enc3_Cb(const std_msgs::Float32::ConstPtr& msg){
    ROS_INFO("data enc3 : [%f]", msg->data);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "encoder");
    ros::NodeHandle nh;
    ros::Subscriber enc_m1;
    ros::Subscriber enc_m2;
    ros::Subscriber enc_m3;
    enc_m1 = nh.subscribe("/data_enc1", 10, enc1_Cb);
    enc_m2 = nh.subscribe("/data_enc2", 10, enc2_Cb);
    enc_m3 = nh.subscribe("/data_enc3", 10, enc3_Cb);
    ros::spin();
    return 0;
}   