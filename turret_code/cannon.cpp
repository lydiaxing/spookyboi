#include "cannon.h"

void Cannon::SetSpeed(int speed) {
    speed_ = speed;
    dc_motor1_.setSpeed(speed);
    dc_motor2_.setSpeed(speed);
    dc_motor1_.run(BACKWARD);
    dc_motor2_.run(BACKWARD);
}

void Cannon::Stop() {
    dc_motor1_.run(RELEASE);
    dc_motor2_.run(RELEASE);
}