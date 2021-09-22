cmake_minimum_required(VERSION 3.0.2)
project(sena_msgs)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
  geometry_msgs
  std_srvs
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  Angle.msg
  MotorInfo.msg
  PPoint.msg
  VelCmd.msg
  Velocity.msg
  OmniVisionInfo.msg
  BallInfo.msg
  OdomInfo.msg
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  Shoot.srv
  BallHandle.srv
  KinematicsForward.srv
  KinematicsInverse.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES sena_msgs
  CATKIN_DEPENDS message_generation message_runtime std_msgs std_srvs geometry_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

