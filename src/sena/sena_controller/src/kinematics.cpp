#include <math.h>
#include <string>

#include <ros/ros.h>
#include <geometry_msgs/Pose2D.h>

#include <sena_msgs/KinematicsForward.h>
#include <sena_msgs/KinematicsInverse.h>

long double L = 0.135;

long double theta = 0;

bool forwardMobile(sena_msgs::KinematicsForward::Request &request, sena_msgs::KinematicsForward::Response &response){
    response.output.x = ((2.0L * request.input.v_back) - request.input.v_right - request.input.v_left)/3.0L;
    response.output.y = ((sqrt(3) * request.input.v_right) - (sqrt(3) * request.input.v_left) / 3.0L);
    response.output.theta = (request.input.v_left + request.input.v_right + request.input.v_back);
    return true;
}

bool inverseMobile(sena_msgs::KinematicsInverse::Request &request, sena_msgs::KinematicsInverse::Response &response){
    long double Vmx = -request.input.x/ 2.0L;
    long double Vmy = (sqrt(3) * request.input.y) / 2.0L;
    long double Lwp = L * request.input.theta;

    response.output.v_right = Vmx + Vmy + Lwp;
    response.output.v_left = Vmx - Vmy + Lwp;
    response.output.v_back = request.input.x + Lwp;
    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "sena_kinematics");
    ros::NodeHandle nh;

    ros::ServiceServer forwardMobileService;
    forwardMobileService = nh.advertiseService("/sena_kinematics_forwardMobile", forwardMobile);
    ros::ServiceServer inverseMobileService;
    inverseMobileService = nh.advertiseService("/sena_kinematics_inverseMobile", inverseMobile);
    ros::spin();
    return 0;
}