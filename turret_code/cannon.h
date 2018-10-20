#ifndef CANNON_H_
#define CANNON_H_

#include <AFMotor.h>

class Cannon {
public:
    Cannon(int motor1_num, int motor2_num) :
        dc_motor1_(motor1_num, MOTOR12_64KHZ), dc_motor2_(motor2_num, MOTOR12_64KHZ)
        {}
    void SetSpeed(int speed);
    void StartUp();
    void Stop();
    // Implement this after tests probably
    void SetDistance();

private:
    AF_DCMotor dc_motor1_;
    AF_DCMotor dc_motor2_;
    int speed_;
};

#endif // CANNON_H_
