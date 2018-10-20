#include "turret.h"

const int turret_pin = 10;
const int vertical_pin = 9;
const int bluetooth_baud = 9600;
const int slave_addr = 0x8;
const int motor1_num = 1;
const int motor2_num = 2;

Turret turret(bluetooth_baud, slave_addr, turret_pin, vertical_pin, motor1_num, motor2_num);

void setup() {
   turret.Run();
}

void loop() {
}
