#include "turret.h"


void Turret::SetOpMode(Mode new_mode) {
    operation_mode_ = new_mode;
}

void Turret::Run() {
    aimer_.AttachServos();
    comm_.StartComms();
    int vertical_pos = 90;
    int turret_pos = 90;
    bool motor_on = false;
    bool change_motor = false;
    aimer_.AimVertical(vertical_pos);
    aimer_.AimTurret(turret_pos);
    while(true) {
        if (operation_mode_ == Mode::BLUETOOTH){
            if (comm_.ReceiveBluetooth(bluetooth_data_)) {
                switch (bluetooth_data_) {
                    case 'g':
                        motor_on = !motor_on;
                        change_motor = true;
                        break;
                    case 'l': 
                        if (turret_pos > 0)
                            turret_pos -=5;
                        break;
                    case 'r':
                        if (turret_pos < 180)
                            turret_pos += 5;
                        break;
                    case 'u':
                        if (vertical_pos < 180)
                            vertical_pos += 5;
                        break; // Move turret up
                    case 'd': 
                        if (vertical_pos > 0) 
                            vertical_pos -=5;
                        break; // Move turret down
                    case 'a':
                        operation_mode_ = Mode::AUTONOMOUS;
                    default: break;
                }
            }
        }
        else if (operation_mode_ == Mode::AUTONOMOUS) {
            if (comm_.ReadI2C(i2c_data_)) {
                if (i2c_data_ == '\n' || i2c_data_ == '\r')
                    continue;
                switch (i2c_data_) {
                    case 't':
                        Serial.println(i2c_data_);
                        comm_.ReadI2C(i2c_data_);
                        turret_pos = i2c_data_;
                        break;
                    case 'v':
                        comm_.ReadI2C(i2c_data_);
                        vertical_pos = i2c_data_;
                        break;
                    case 'm':
                        motor_on = !motor_on;
                        change_motor = true;
                        break;
                    case 'b':
                        comm_.ReadI2C(i2c_data_);
                        operation_mode_ = Mode::BLUETOOTH;
                        break;
                    default:
                        break;
                }
            }
        }
        if (change_motor) {
            if (motor_on)
                cannon_.SetSpeed(255);
            else
                cannon_.Stop();
            change_motor = false;
        }
        aimer_.AimTurret(turret_pos);
        aimer_.AimVertical(vertical_pos);
    }
}
