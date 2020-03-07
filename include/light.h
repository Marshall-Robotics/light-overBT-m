#include <Arduino.h>
#include <data.h>
/** This file contains the declarations for the global variables used
 *  in the rest of the program as flags and data. It also contains the 
 *  custom data structures and preset defaults. 
**/
#ifndef light
#define light
#define WHITE 110, 110, 110
#define BLACK 0, 0, 0
#define BLUE 0, 0, 110
#define RED 110, 0, 0
#define OFF 0, 0, 0
#define GREEN 0, 110, 0
#define YELLOW 110, 110, 0
#define CALIBLED 255
extern void serRGBA(byte r, byte g, byte b);
extern void serRGBB(byte r, byte g, byte b);
extern void setRGBsPos(sPosition sPos);

#endif