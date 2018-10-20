#include "turret_comms.h"
#include <Wire.h>

static const int BUFF_SIZE = 16;

char in_buf[BUFF_SIZE];
uint32_t in_buf_count = 0;
uint32_t in_buf_read = 0;
char out_buf[BUFF_SIZE];
uint32_t out_buf_count = 0;

static void TurretComms::SendI2C() {
    while (out_buf_count > 0)
        Wire.write(out_buf, out_buf_count);
}

static void TurretComms::ReceiveI2C() {
    in_buf_count = 0;
    in_buf_read = 0;
    while (Wire.available() && in_buf_count < BUFF_SIZE) {
        in_buf[in_buf_count] = Wire.read();
        in_buf_count++;
    }
}

void TurretComms::SendBluetooth(char data) {
    Serial.write(data);
}

bool TurretComms::ReceiveBluetooth(char& data) {
    if (!Serial.available())
        return false;
    data = Serial.read();
    return true;
}

bool TurretComms::ReadI2C(char& data) {
    if (in_buf_count <= in_buf_read)
        return false;
    data = in_buf[in_buf_read];
    in_buf_read++;
    return true;
}

void TurretComms::PutI2CBuff(char data) {
    out_buf[out_buf_count] = data;
    out_buf_count++;
}

void TurretComms::StartComms() {
    Serial.begin(bluetooth_baud_);
    Wire.begin(slave_addr_);
    Wire.onReceive(ReceiveI2C);
    Wire.onRequest(SendI2C);
}

