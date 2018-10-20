#include "body.h"
#include <Wire.h>

void Body::StartComms() {
    Wire.begin(slave_addr_);
    Wire.onReceive(I2CRead);
}

void Body::StartMotor() {
    motor_on_ = true;
    motor1_.setSpeed(255);
    motor2_.setSpeed(255);
    if (foward) {
        motor1_.run(FORWARD);
        motor2_.run(FORWARD);
    } else {
        motor1_.run(BACKWARD);
        motor2_.run(BACKWARD);
    }
}

void Body::StopMotor() {
    motor_on_ = false;
    motor1_.run(RELEASE);
    motor2_.run(RELEASE);
}

void Turn(int angle) {

}

void InvertDirection() {
    if (foward) {
        motor1_.run(BACKWARD);
        motor2_.run(BACKWARD);
    } else {
        motor1_.run(FORWARD);
        motor2_.run(FORWWARD);
    }
    foward = !foward;
}
