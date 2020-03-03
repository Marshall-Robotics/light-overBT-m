#include <Arduino.h>
#include <light.h>



void setup() {
setupRGB();
analogReadResolution(8);
pinMode(21, INPUT);
}

void loop() {
    setRGB(analogRead(21),analogRead(20),analogRead(16));
}


