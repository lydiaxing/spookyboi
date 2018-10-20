#include "body.h"

static const int slave_addr = 0x7;
static const int motor_num1 = 1;
static const int motor_num2 = 2;

Body body(slave_addr, motor_num1, motor_num2);

void setup() {
  // put your setup code here, to run once:
  body.StartComms();
}

void I2CRead() {
  char data;
  while (Wire.available()) {
    data = Wire.read();
    switch (data) {
      case 's':
        body.InvertDirection();
        break;
      case 'm':
        body.StartMotor();
        break;
      case 'b':
        body.StopMotor();
        break;
      case 't':
        body.Turn(Wire.read());
        break;
      default:
        break;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}
