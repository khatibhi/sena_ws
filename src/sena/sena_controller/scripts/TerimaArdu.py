#!/usr/bin/env python3
import rospy
import math
from geometry_msgs.msg import Vector3
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64

global enc1, enc2, enc3
a = 0
b = 0
c = 0

Vx = 0.0
Vy = 0.0
Vtheta = 0.0

x = 0.0
y = 0.0
theta = 0.0

interval = 100

def callback(enc):
    enc1 = enc.x
    enc2 = enc.y
    enc3 = enc.z
    # a = enc1
    # b = enc2
    # c = enc3

    # angle_enco_1 = a * 3.2142
    # angle_enco_2 = b * 3.2142
    # angle_enco_3 = c * 3.2142

    # ppm1 = (enc1 / 112)*2*3.14*2.9
    # ppm2 = (enc2 / 112)* 2*3.14*2.9
    # ppm3 = (enc3 / 112)* 2*3.14*2.9

    # Vy = (ppm1*math.cos(30))-(ppm2*math.cos(30))
    # Vx = ppm3-ppm1*math.sin(30)-ppm2*math.sin(30)
    # Vtheta = 1/14.195*(ppm1+ppm2+ppm3)

    # y = math.cos(Vtheta)*Vy-math.sin(Vtheta)*Vx
    # x = math.sin(Vtheta)*Vy+math.cos(Vtheta)*Vx
    # theta = Vtheta

    # x = enc3-(math.cos(60)*enc1)-(math.cos(300)*enc2)
    # y = (math.sin(60)*enc1)-(math.cos(300)*enc2)
    # theta = -(enc1+enc2+enc3)/3
    x = ((enc3 - 0.5*enc1-0.5*enc2) /75)*10
    y = ((enc1*0.87 - enc2*0.87)/260)*30
    theta = (1/3*(enc1+enc2+enc3)/-119)*90

    odom_pub = rospy.Publisher('odom', Odometry, queue_size=10)
    y_robot = rospy.Publisher('ypos', Float64, queue_size=10)
    t_robot = rospy.Publisher('tpos', Float64, queue_size=10)
    x_robot = rospy.Publisher('xpos', Float64, queue_size=10)
    
    odom = Odometry() 

    odom.pose.pose.position.x = x
    odom.pose.pose.position.y = y
    odom.pose.pose.position.z = theta

    odom_pub.publish(odom)

    x_robot.publish(x)
    y_robot.publish(y)
    t_robot.publish(theta)
    rospy.loginfo('x : %s y : %s theta : %s' %(x, y, theta))
        
    # x = 0.024*(((2/3)*angle_enco_3)-((1/3)*angle_enco_1)-((1/3)*angle_enco_2))
    # y = 0.024*(((1/math.sqrt(3))*angle_enco_1)-((1/math.sqrt(3))*angle_enco_2))
    # theta = (0.024/3*0.14195)*(angle_enco_1+angle_enco_2+angle_enco_3)
    # rospy.loginfo('x : %f y : %f theta : %f' %(x, y, theta))
    # rospy.loginfo('enc1 : %s \tenc2 : %s \tenc3 : %s' %(enc1, enc2, enc3))
    # rospy.loginfo('vy : %s vx : %s vtheta : %s' %(Vy, Vx, Vtheta))

def Sub():
    rospy.init_node('Odometri', anonymous=False)
    rospy.Subscriber('encoder', Vector3, callback)
    rospy.spin()
	

if __name__ == '__main__':
    Sub()