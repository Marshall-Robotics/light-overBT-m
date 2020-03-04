#include <Arduino.h>
#include <data.h>

potData readerProfile[6] {
  {1, 20, 256, 50, 50}, //g "pinky"
  {2, 20, 256, 50, 50},  //g "ring finger"
  {3, 20, 256, 50, 50},  //g "middle finger"
  {4, 20, 256, 50, 50},  //g "index"
  {5, 20, 256, 50, 50},
  {6, 20, 256, 50, 50}
};

servoData handProfile[6] {
  {"Pinky",         3,  100, 1000},
  {"ring Finger",   5,  100, 1000},
  {"middle Finger", 6,  -100, 900},
  {"index",         10,100, 900},
  {"thumb",         11,  0, 1100},
  {"DISABLED",      9, 100, 900}
};

sPosition NUMBERONE {100, 100,  100, 100, 100};
sPosition PEACE     {100, 100, 0, 0, 100};