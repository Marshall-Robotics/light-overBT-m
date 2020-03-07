#include <Arduino.h>
#include <utility/wifi_drv.h>
#include <config.h>
#include <data.h>
#include <light.h>


void serRGBA(byte R, byte G, byte B) {
    analogWrite(RED_PIN_A,R);
    analogWrite(GREEN_PIN_A,G); 
    analogWrite(BLUE_PIN_A,B);
}

void serRGBB(byte R, byte G, byte B) {
    analogWrite(RED_PIN_B,R);
    analogWrite(GREEN_PIN_B,G); 
    analogWrite(BLUE_PIN_B,B);
}

void setRGBsPos(sPosition sPos){

    serRGBA(
        CALIBLED-map(sPos.pinkyF, 0, 100, handProfile[HpinkyF].minS,handProfile[HpinkyF].maxS),
        CALIBLED-map(sPos.middleF, 0, 100, handProfile[HmiddleF].minS,handProfile[HmiddleF].maxS),
        CALIBLED-map(sPos.thumbF, 0, 100, handProfile[HthumbF].minS,handProfile[HthumbF].maxS)
    );
    serRGBB(
        map(sPos.ringF, 0, 100, handProfile[HringF].minS,handProfile[HringF].maxS),
        map(sPos.indexF, 0, 100, handProfile[HindexF].minS,handProfile[HindexF].maxS),
        map(sPos.wrist, 0, 100, handProfile[Hwrist].minS,handProfile[Hwrist].maxS)
        
    );
}   
/*IMPORTANT: do not set the pins as output as that will fuck with the NINA
BT LE module and make execution halt whenever you do anything related to BT LE
*/



