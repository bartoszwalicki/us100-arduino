#include <HardwareSerial.h>
#include "./US100.h"

HardwareSerial sensor1Serial(1);
HardwareSerial sensor2Serial(2);
US100 sensor1;
US100 sensor2;

unsigned int distance1 = 0;
unsigned int distance2 = 0;
unsigned int temperature = 0;

void setup()
{
    Serial.begin(9600);
    sensor1Serial.begin(9600, SERIAL_8N1, 4, 5);
    sensor2Serial.begin(9600, SERIAL_8N1, 23, 22);
    sensor1.init(&sensor1Serial);
    sensor2.init(&sensor2Serial);
}

void loop()
{
    distance1 = sensor1.readDistance();
    distance2 = sensor2.readDistance();
    temperature = sensor1.readTemperature();
    Serial.printf("[2] Present Length is: %i mm\r", distance1);
    Serial.printf("[2] Present Length is: %i mm\r", distance2);
    Serial.printf("Temperature is: %i \r", temperature);
    delay(1000);
}


