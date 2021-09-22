#!/usr/bin/env python3

from __future__ import print_function

import rospy

from std_msgs.msg import Float64
from sena_msgs.msg import Velocity

import sys, select, termios, tty

msg = """
Reading from the keyboard !
---------------------------
Moving around:
   u    i    o
   j    k    l
   m    ,    .

For Holonomic mode (strafing), hold down the shift key:
---------------------------
   U    I    O
   J    K    L
   M    <    >


anything else : stop

q/z : increase/decrease max speeds by 10%

CTRL-C to quit
"""

moveBindings = {
        'i':(-1,0,1),
        ',':(1,0,-1),
        'j':(1,1,1),
        'l':(-1,-1,-1),
        'u':(0,-1,1),
        '.':(0,1,-1),
        'o':(-1,1,0),
        'm':(1,-1,0),  
        'O':(-1,1,0),
        'I':(-1,0,1),
        'J':(1,-2,1),
        'L':(-1,2,-1),
        'U':(0,-1,1),
        '<':(1,0,-1),
        '>':(0,1,-1),
        'M':(1,-1,0),  
    }

speedBindings={
        'q':(1.1,1.1),
        'z':(.9,.9),
    }

def getKey():
    tty.setraw(sys.stdin.fileno())
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


def vels(speed):
    return "currently:\tspeed %s " % (speed)

if __name__=="__main__":
    settings = termios.tcgetattr(sys.stdin)

    rospy.init_node('sena_control_node')
    pubr = rospy.Publisher('/sena/right_joint_velocity_controller/command', Float64, queue_size=1)
    publ = rospy.Publisher('/sena/left_joint_velocity_controller/command', Float64, queue_size=1)
    pubb = rospy.Publisher('/sena/back_joint_velocity_controller/command', Float64, queue_size=1)

    speed = 1.0
    x = 0
    y = 0
    z = 0
    status = 0

    try:
        print(msg)
        print(vels(speed))
        while(1):
            key = getKey()
            if key in moveBindings.keys():
                x = moveBindings[key][0] # L
                y = moveBindings[key][1] # B
                z = moveBindings[key][2] # R
            elif key in speedBindings.keys():
                speed = speed * speedBindings[key][0]
       
                print(vels(speed))
                if (status == 14):
                    print(msg)
                status = (status + 1) % 15
            else:
                # stop control    
                # ---  robot maju ----
                if velr > 0 and vell < 0:
                    x = -0.0001 # motor L
                    z = 0.0001 # motor R
                    th = 0
                    if (key == '\x03'):
                        break
                #---- robot mundur ----
                elif velr < 0 and vell > 0:
                    x = 0.0001 # motor L
                    z = -0.0001 # motor R
                    th = 0
                    if (key == '\x03'):
                        break
                #---- robot rotasi kanan ----
                elif velb < 0 and vell < 0 and velr < 0:
                    z = -0.0001 # motor R
                    y = -0.0001 # motor B
                    x = -0.0001 # motor L
                    th = 0
                    if (key == '\x03'):
                        break
                #---- robot rotasi kiri ----
                elif velb > 0 and velr > 0 and vell > 0:
                    z = 0.0001 # motor R
                    y = 0.0001 # motor B
                    x = 0.0001 # motor L        
                    th = 0
                    if (key == '\x03'):
                        break
                #---- robot serong kanan (maju)----
                elif velb > 0 and vell < 0:
                    y = 0.0001 # motor B
                    x = -0.0001 # motor L        
                    th = 0
                    if (key == '\x03'):
                        break
                #---- robot serong kanan (mundur)----
                elif velb < 0 and vell > 0:
                    y = -0.0001 # motor B
                    x = 0.0001 # motor L        
                    th = 0
                    if (key == '\x03'):
                        break
                #---- robot serong kiri (maju)----
                elif velb < 0 and velr > 0:
                    y = -0.0001 # motor B
                    z = 0.0001 # motor R        
                    th = 0
                    if (key == '\x03'):
                        break
                #---- robot serong kiri (mundur)----
                elif velb > 0 and velr < 0:
                    y = 0.0001 # motor B
                    z = -0.0001 # motor R        
                    th = 0
                    if (key == '\x03'):
                        break
                

            velr = Float64()
            vell = Float64()
            velb = Float64()

            velr = z*speed
            vell = x*speed
            velb = y*speed

            pubr.publish(velr)
            publ.publish(vell)
            pubb.publish(velb)
            

    except Exception as e:
        print(e)

    finally:
        vell = Float64()
        velb = Float64()
        velr = Float64()

        vell = 0
        velb = 0
        velr = 0

        pubb.publish(vell)
        publ.publish(velb)
        pubr.publish(velr)

        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
