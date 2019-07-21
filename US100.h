#ifndef US100_H
#define US100_H

#include <HardwareSerial.h>

class US100 {
    public:
        US100();
        void init(HardwareSerial* serial);
        int readDistance();
        int readTemperature();
    private:
        HardwareSerial* _serialPort;
};

#endif
