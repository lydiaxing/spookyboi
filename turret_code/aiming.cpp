#include "aiming.h"

TurretAiming::TurretAiming(int turret_pin, int vertical_pin) {
    turret_pin_ = turret_pin;
    vertical_pin_ = vertical_pin;
}

void TurretAiming::AttachServos() {
    vertical_servo_.attach(vertical_pin_);
    turret_servo_.attach(turret_pin_);
}

void TurretAiming::AimVertical(int pos) {
    vertical_servo_.write(pos);
}

void TurretAiming::AimTurret(int pos) {
    turret_servo_.write(pos);
}
