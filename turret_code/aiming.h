#ifndef AIMING_H_
#define AIMING_H_

#include <Servo.h>

class TurretAiming {
public:
    TurretAiming (int turret_pin, int vertical_pin);
    void AttachServos();
    void AimVertical (int pos);
    void AimTurret (int pos);

private:
    Servo turret_servo_;
    Servo vertical_servo_;
    int turret_pin_;
    int vertical_pin_;
};

#endif // AIMING_H_
