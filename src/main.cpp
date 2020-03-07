#include <Arduino.h>
#include <light.h>
#include <sensor.h>
#include <BTLE.h>
#include <serial.h>
#include <config.h>
void setup() {
    analogReadResolution(8);
    
    pinMode(LED_BUILTIN,OUTPUT);
    serialSetup();
    sensorSetup();
    BTLEsetup();

    serRGBA(WHITE);
    delay(500);
    serRGBA(GREEN);
    delay(5000);
    serRGBA(OFF);
    delay(500);
}

void loop() {
    digitalWrite(LED_BUILTIN,LOW);
    sPosition sPos = readPotValPositions();
    setRGBsPos(sPos);
    digitalWrite(LED_BUILTIN,HIGH);
    reportPosition(sPos);
}


