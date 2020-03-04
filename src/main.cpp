#include <Arduino.h>
#include <light.h>
#include <sensor.h>
#include <BTLE.h>
#include <serial.h>
void setup() {
    serialSetup();
    sensorSetup();
    RGBsetup();
    BTLEsetup();
}

void loop() {
    sPosition sPos = readPotValPositions();
    setRGBsPos(sPos);
    reportPosition(sPos);
    delay(100);
}


