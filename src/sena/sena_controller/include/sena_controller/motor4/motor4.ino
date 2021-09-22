#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <ArduinoHardware.h>

//MOTOR1
#define RPWM1 7
#define LPWM1 6

//MOTOR2
#define RPWM2 10
#define LPWM2 9

//MOTOR3
#define RPWM3 12
#define LPWM3 11

float Vm_x, Vm_y, Vm_z;
float V1, V2, V3;
float Vmx, Vmy, Wp;

int L = 13.5;

ros::NodeHandle nh;

//publish to each motor motor1_Cb, motor2_Cb, motor3_Cb
void motor_Cb(const geometry_msgs::Twist& msg) {
  Vm_x = msg.linear.x;
  Vm_y = msg.linear.y;
  Vm_z = msg.angular.z;

  V1 = (-Vm_x / 2) - (sqrt(3) * Vm_y / 2) + Vm_z;
  V2 = Vm_x + Vm_z;
  V3 = (-Vm_x / 2) + (sqrt(3) * Vm_y / 2) + Vm_z;

  Vmx = (2 * V2 - V1 - V3) / 3;
  Vmy = (sqrt(3) * V3 - sqrt(3) * V1);
  Wp = ((V1 + V2 + V3) / 3) * L;

}

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &motor_Cb);
//ros::Subscriber<geometry_msgs::Twist> sub_ball("/sena/control/cmd_vel", &motorCb)

void setup() {
  pinMode (RPWM1, OUTPUT);
  pinMode (LPWM1, OUTPUT);
  pinMode (RPWM2, OUTPUT);
  pinMode (LPWM2, OUTPUT);
  pinMode (RPWM3, OUTPUT);
  pinMode (LPWM3, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
  //  nh.subscribe(sub_ball);
}

void loop() {
  if (Vm_x >= 0) {
    analogWrite(RPWM1, Vm_x);
    analogWrite(LPWM1, 0);
  }
  else {
    analogWrite(RPWM1, 0);
    analogWrite(LPWM1, -Vm_x);
  }

  if (Vm_y >= 0) {
    analogWrite(RPWM2, Vm_y);
    analogWrite(LPWM2, 0);
  }
  else {
    analogWrite(RPWM2, 0);
    analogWrite(LPWM2, -Vm_y);
  }

  if (Vm_z >= 0) {
    analogWrite(RPWM3, Vm_z);
    analogWrite(LPWM3, 0);
  }
  else {
    analogWrite(RPWM3, 0);
    analogWrite(LPWM3, -Vm_z);
  }

//  if (V1 >= 0) {
//    analogWrite(RPWM1, V1);
//    analogWrite(LPWM1, 0);
//  }
//  else {
//    analogWrite(RPWM1, 0);
//    analogWrite(LPWM1, -V1);
//  }
//
//  if (V2 >= 0) {
//    analogWrite(RPWM2, V3);
//    analogWrite(LPWM2, 0);
//  }
//  else {
//    analogWrite(RPWM2, 0);
//    analogWrite(LPWM2, -V2);
//  }
//
//  if (V3 >= 0) {
//    analogWrite(RPWM3, V3);
//    analogWrite(LPWM3, 0);
//  }
//  else {
//    analogWrite(RPWM3, 0);
//    analogWrite(LPWM3, -V3);
//  }

  nh.spinOnce();
  delay(1);
}
