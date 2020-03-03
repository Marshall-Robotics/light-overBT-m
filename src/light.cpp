#include <Arduino.h>
#include <utility/wifi_drv.h>
#include <config.h>


void setupRGB() {
WiFiDrv::pinMode(RED_PIN, OUTPUT);
WiFiDrv::pinMode(GREEN_PIN, OUTPUT);
WiFiDrv::pinMode(BLUE_PIN, OUTPUT);
}

// void setRGB(byte R, byte G, byte B) {
// WiFiDrv::digitalWrite(RED_PIN,255);
// WiFiDrv::digitalWrite(GREEN_PIN,255); 
// WiFiDrv::digitalWrite(BLUE_PIN,50);
// }

void setRGB(byte R, byte G, byte B) {
WiFiDrv::analogWrite(RED_PIN,R);
delay(1000);
WiFiDrv::analogWrite(GREEN_PIN,G); 
delay(1000);
WiFiDrv::analogWrite(BLUE_PIN,B);
}

void setwhite(byte R, byte G, byte B) {
WiFiDrv::digitalWrite(RED_PIN,HIGH);
WiFiDrv::digitalWrite(GREEN_PIN,HIGH); 
WiFiDrv::digitalWrite(BLUE_PIN,HIGH);
}