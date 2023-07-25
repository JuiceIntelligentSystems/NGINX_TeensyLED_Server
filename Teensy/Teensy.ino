#include <Arduino.h>
#include <Wire.h>

#define I2C_ADDRESS 0x4b

int brightness = 0;

void receiveEvent(int);

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    Wire.begin(I2C_ADDRESS);
    Wire.onReceive(receiveEvent);

    Serial.begin(9600);
    Serial.println("Ready");
}

void receiveEvent(int byte_count)
{
    if (byte_count >= 1)
    {
        brightness = Wire.read();

        Serial.println(brightness);
    }
}

void loop()
{
    analogWrite(LED_BUILTIN, brightness);
}
