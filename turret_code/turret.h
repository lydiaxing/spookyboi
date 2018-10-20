#ifndef TURRET_H_
#define TURRET_H_

#include "aiming.h"
#include "cannon.h"
#include "turret_comms.h"
#include <HardwareSerial.h>

extern HardwareSerial Serial;

enum class Mode {
    BLUETOOTH, AUTONOMOUS
};

class Turret {
public:
    Turret(int bluetooth_baud, int slave_addr, int turret_pin, int vertical_pin,
           int motor1_num, int motor2_num) :
    comm_(bluetooth_baud, slave_addr), cannon_(motor1_num, motor2_num),
    aimer_(turret_pin, vertical_pin)
    {
        operation_mode_ = Mode::BLUETOOTH;
    }
    void SetOpMode(Mode new_mode);
    void Run();
private:
    Mode operation_mode_;
    Cannon cannon_;
    TurretAiming aimer_;
    TurretComms comm_;
    char bluetooth_data_;
    char i2c_data_;
};

#endif TURRET_H_