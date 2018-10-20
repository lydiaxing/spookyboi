#ifndef BODY_H_
#define BODY_H_

class Body {
public:
    Body(int slave_addr, int motor1_num, int motor2_num) : 
    slave_addr_(slave_addr), motor1_num_(motor1_num), motor2_num_(motor2_num) {
        forward_ = false;
    }
    void StartComms();
    void Turn(int angle);
    void InvertDirection();
    void StartMotor();
    static void I2CRead();
private:
    BodyComms comm_;
    AF_DCMotor motor1_;
    AF_DCMotor motor2_;
    bool forward_;
    bool motor_on_;
    int slave_addr_;
};

#endif // BODY_H_