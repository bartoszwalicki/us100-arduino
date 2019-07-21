#include "./US100.h"
#define GET_DISTANCE 0x55
#define GET_TEMPERATRUE 0x50

US100::US100() {}

void US100::init(HardwareSerial* serial) {
    _serialPort = serial;
}

int US100::readDistance()
{
    unsigned int highByte = 0;
    unsigned int lowByte = 0;
    unsigned int distance = 0;
    _serialPort -> flush();
    _serialPort -> write(GET_DISTANCE);
    delay(100);
    if (_serialPort -> available() >= 2)
    {
        highByte = _serialPort -> read();
        lowByte = _serialPort -> read();
        distance = highByte * 256 + lowByte;
        if ((distance > 1) && (distance < 10000))
        {
            return distance;
        }
    }
    return 0;
}

int US100::readTemperature() {
    unsigned int temperature = 0;
    _serialPort -> write(GET_TEMPERATRUE);
    delay(100);
    if (_serialPort -> available() >= 1)
    {
        temperature = _serialPort -> read() - 45;
        _serialPort -> flush();
        return temperature;
    }
}
