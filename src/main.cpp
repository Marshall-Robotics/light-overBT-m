#include <Arduino.h>
#include <light.h>
#include <sensor.h>
#include <BTLE.h>
#include <serial.h>
#include <config.h>
void setup() {
    pinMode(LED_BUILTIN,OUTPUT);
    serialSetup();
    sensorSetup();
    BTLEsetup();

    setRGB(WHITE);
    delay(500);
    setRGB(GREEN);
    delay(5000);
    setRGB(OFF);
    delay(500);
}

void loop() {
    digitalWrite(LED_BUILTIN,LOW);
    sPosition sPos = readPotValPositions();
    setRGBsPos(sPos);
    digitalWrite(LED_BUILTIN,HIGH);
    reportPosition(sPos);
}


