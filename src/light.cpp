#include <Arduino.h>
#include <utility/wifi_drv.h>
#include <config.h>
#include <data.h>
#include <light.h>


void setRGB(byte R, byte G, byte B) {
    analogWrite(RED_PIN_A,R);
    analogWrite(GREEN_PIN_A,G); 
    analogWrite(BLUE_PIN_A,B);
}

void setRGBsPos(sPosition sPos){
    setRGB(255-sPos.indexF, 255-sPos.pinkyF, 255-sPos.ringF);
}
/*IMPORTANT: do not set the pins as output as that will fuck with the NINA
BT LE module and make execution halt whenever you do anything related to BT LE
*/



