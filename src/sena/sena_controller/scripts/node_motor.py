#!/usr/bin/env python3
import rospy
from std_msgs.msg import Float64
from pyfirmata import ArduinoMega, util 
import time
import math
import numpy as np

# board = pyfirmata.Arduino('dev/ttyUSB0') #port 'dev/tty/...', baudrate()
board = ArduinoMega('/dev/ttyACM0')
print("Connection Successfully!")
it = util.Iterator(board)
it.start()

motor1r = board.get_pin("d:7:p") 
motor1l = board.get_pin("d:6:p") 

def motor_Cb(msg):
    global V1 
    V1 = msg.data
    V1 = float(V1)
    print("kecepatan V1 : ", V1)
    
    if (V1 >= 0.0):
        motor1r.write(V1)
        motor1l.write(0)
    else:
        motor1r.write(0)

        motor1l.write(-V1) 

def motor():
    rospy.init_node('motorsub', anonymous=False)
    pub1 = rospy.Publisher('/anjing', Float64, queue_size=1)
    rospy.Subscriber('/pid_m1', Float64, motor_Cb)
    
    rospy.spin()
    while rospy.is_shutdown():
        m1 = rospy.loginfo(V1)
        pub1.publish(m1)
        rospy.sleep(1)


if __name__ == '__main__':
    motor()