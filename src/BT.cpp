#include <ArduinoBLE.h>
#include <data.h>

BLEService posRservice("180F");

BLEUnsignedCharCharacteristic batteryLevelChar("2A19",  // standard 16-bit characteristic UUID
BLERead | BLENotify);
int oldBatteryLevel = 0;  // last battery level reading from analog input
long previousMillis = 0;  // last time the battery level was checked, in ms