// publish motor value and encoder value
#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Int16.h>

//MOTOR1
#define RPWM1 7
#define LPWM1 6

//ENCO MOTOR1
#define ENCO1A 2
#define ENCO1B 3

volatile int64_t encoderPos = 0;

ros::NodeHandle nh;
std_msgs::Int64 encoder;
ros::Publisher encoderValue("encoderValue", &encoder);

void pwm_input(const std_msgs::Int16 &pwm_value) {
  int pwm = 0;
  pwm = pwm_value.data;

  if (pwm > 0) {
    motorGo(RPWM1, pwm);
  }
  else {
    motorGo(LPWM1, pwm);
  }
}

ros::Subscriber<std_msgs::Int16> pwm("pwm_values", &pwm_input);

void setup() {
  nh.initNode();
  nh.advertise(encoderValue);
  nh.subscribe(pwm);

  pinMode (ENCO1A, INPUT_PULLUP);
  pinMode (ENCO1B, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (ENCO1A), readEncoder, RISING);

  TCCR1B = TCCR1B & 0b11111000 | 1;
}

void motorGo(int16_t direct, uint16_t pwm) {
  if (pwm > 0) {
    analogWrite(RPWM1, pwm);
    analogWrite(LPWM1, 0);
  }
  if (pwm < 0) {
    pwm = pwm * -1;
    analogWrite(RPWM1, 0);
    analogWrite(LPWM1, pwm);
  }
  return pwm;
}

void loop() {
  nh.loginfo("rosserial connection succesfully");
  encoder.data = encoderPos;
  encoderValue.publish(&encoder);

  nh.spinOnce();
  delay(100);
}

void readEncoder() {
  int b = digitalRead(ENCO1B);
  if (b > 0) {
    encoderPos++;
  }
  else {
    encoderPos--;
  }
}
