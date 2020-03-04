#include <Arduino.h>
#include <data.h>
/** This file contains the declarations for the global variables used
 *  in the rest of the program as flags and data. It also contains the 
 *  custom data structures and preset defaults. 
**/
#ifndef BTLE
#define BTLE

extern void BTLEsetup();
extern void reportPosition(sPosition sPos);

#endif