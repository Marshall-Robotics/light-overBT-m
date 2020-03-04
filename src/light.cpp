#include <Arduino.h>
#include <utility/wifi_drv.h>
#include <config.h>
#include <data.h>
#include <light.h>


void setRGB(byte R, byte G, byte B) {
    WiFiDrv::analogWrite(RED_PIN,R);
    WiFiDrv::analogWrite(GREEN_PIN,G); 
    WiFiDrv::analogWrite(BLUE_PIN,B);
}

void setRGBsPos(sPosition sPos){
    setRGB(sPos.indexF, sPos.pinkyF, sPos.ringF);
}

void RGBsetup() {
    WiFiDrv::pinMode(RED_PIN, OUTPUT);
    WiFiDrv::pinMode(GREEN_PIN, OUTPUT);
    WiFiDrv::pinMode(BLUE_PIN, OUTPUT);
}