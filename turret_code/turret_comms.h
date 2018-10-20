#ifndef TURRET_COMMS_H_
#define TURRET_COMMS_H_
#include <HardwareSerial.h>

extern HardwareSerial Serial;

class TurretComms {
public:
    TurretComms(int bluetooth_baud, int slave_addr) :
        bluetooth_baud_(bluetooth_baud), slave_addr_(slave_addr)
        {}
    static void SendI2C();
    static void ReceiveI2C();
    bool ReadI2C(char& data);
    void PutI2CBuff(char data);
    void SendBluetooth(char data);
    bool ReceiveBluetooth(char& data);
    void StartComms();
    
private:
    int bluetooth_baud_;
    int slave_addr_;
};

#endif // TURRET_COMMS_H_