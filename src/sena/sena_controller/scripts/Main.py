#!/usr/bin/env python3
from re import X
import rospy
import math
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64
from geometry_msgs.msg import Pose2D

tick_m1 = 0.0
tick_m2 = 0.0
tick_m3 = 0.0

x_rev = 0
y_rev = 0
theta_rev = 0

Kp_ox = 0.8
Kp_oy = 0.8
Kp_ot = 0.8

def target_pos(input):
    global x_rev
    global y_rev
    global theta_rev
    x_rev = input.x
    y_rev = input.y
    theta_rev = input.z

def callback(ambil):
    global x_rev
    global y_rev
    global theta_rev

    x_odom = ambil.pose.pose.position.x
    y_odom = ambil.pose.pose.position.y
    theta_odom = ambil.pose.pose.position.z

    pos_odom = (x_odom, y_odom, theta_odom)

    rospy.loginfo("x_odom : %s y_odom : %s theta_odom : %s" %(x_odom,y_odom,theta_odom))

    # tick_m1 = (0.555556*x_odom)+(11.1939*y_odom)+(0.881481*theta_odom)
    # tick_m2 = (-5.55556*x_odom)+(-11.1939*y_odom)+(-8.81581*theta_odom)
    # tick_m3 = (5*x_odom)+(0.00000000000000444089*y_odom)+(-3.96667*theta_odom)

    pos_rev = (x_rev, y_rev, theta_rev)
    rospy.loginfo("odom tuple : %s rev tuple : %s" %(pos_odom, pos_rev))

    y_error = ((0.00002*y_rev*y_rev)+(0.212*y_rev)+2.9394)
    x_error = ((0.00004*x_rev*x_rev)+(0.32*x_rev)+2.9394)
    
    x_odom = x_odom - x_error
    y_odom = y_odom - y_error

# kotib    
    try:
        error_x = ((x_rev-x_odom)/abs(x_rev))*400
    except ZeroDivisionError:
        error_x = 0

    try:
        error_y = ((y_rev-y_odom)/abs(y_rev))*400
    except ZeroDivisionError:
        error_y = 0

    try:
        error_theta = ((theta_rev-theta_odom)/abs(theta_rev))*400
    except ZeroDivisionError:
        error_theta = 0

    
    # if(error_x >= 200):
    #     Vx = 200
    #     if(x_odom >= x_rev+5):
    #         Vx = 0
    # elif(error_x < -200):
    #     Vx = -200
    #     if(x_odom >= x_rev+5):
    #         Vx = 0
    # else:
    #     Vx = error_x*5
    #     if(x_odom >= x_rev+5):
    #         Vx = 0

    
    
    # if(error_y >= 200):
    #     Vy = 200
    #     if(y_odom >= y_rev):
    #         Vy = 0
    # elif(error_y < -200):
    #     Vy = -200
    #     if(y_odom >= y_rev):
    #         Vy = 0
    # else:
    #     Vy = error_y*5
    #     rospy.loginfo('masuk sini anjing')
    #     if(y_odom >= y_rev):
    #         Vy = 0
    #         rospy.loginfo('diem')

    
    # if(error_theta >= 200):
    #     Vtheta = 200
    #     if(theta_odom >= theta_rev+5):
    #         Vtheta = 0
    # elif(error_theta < -200):
    #     Vtheta = -200
    #     if(theta_odom >= theta_rev+5):
    #         Vtheta = 0
    # else:
    #     Vtheta = error_theta*5
    #     if(theta_odom >= theta_rev+5):
    #         Vtheta = 0

    # error_x = x_rev - x_odom
    p_x = Kp_ox*error_x
    if p_x > 200:
        p_x = 200
    elif p_x < -200:
        p_x = -200

    # error_y = y_rev - y_odom
    p_y = Kp_oy*error_y
    if p_y > 200:
        p_y = 200
    elif p_y < -200:
        p_y = -200

    # error_theta = theta_rev - theta_odom
    p_theta = Kp_ot*error_theta
    if p_theta > 200:
        p_theta = 200
    elif p_theta < -200:
        p_theta = -200

    # if(error_x <= 2 and error_x >= -2 or error_y <= 2 and error_y >= -2 or error_theta <= 2 and error_theta >= -2) :
    #     Vx = 0
    #     Vy = 0
    #     Vtheta = 0
    
    # else :
    Vx = p_x
    Vy = p_y
    Vtheta = p_theta

    v1 = (-0.333 * Vx) +(0.5774 * Vy) + (0.045*Vtheta)
    v2 = (-0.333 * Vx) +(-0.5774 * Vy) + (0.045*Vtheta)
    v3 = (0.667 * Vx) + (0.045 * Vtheta)

    rospy.loginfo('roda kiri x : %s' %v2)

    pubr = rospy.Publisher('/sena/right_joint_velocity_controller/command', Float64, queue_size=1)
    publ = rospy.Publisher('/sena/left_joint_velocity_controller/command', Float64, queue_size=1)
    pubb = rospy.Publisher('/sena/back_joint_velocity_controller/command', Float64, queue_size=1)

    pubr.publish(v1)
    publ.publish(v2)
    pubb.publish(v3)      

def sub():
    rospy.init_node('Input_Posisi', anonymous = False)
    rospy.Subscriber('odom', Odometry, callback)
    rospy.Subscriber('pose', Pose2D, target_pos)
    rospy.spin()

if __name__ == '__main__':
    try:
        sub()

    except rospy.ROSInterruptException:
        pass