#include <ArduinoBLE.h>
#include <data.h>
#include <light.h>

BLEService posRservice("180F");

BLEUnsignedCharCharacteristic batteryLevelChar("EE01",  // standard 16-bit characteristic UUID
BLERead | BLENotify);

int oldBatteryLevel = 0;  // last battery level reading from analog input
long previousMillis = 0;  // last time the battery level was checked, in ms
BLEDevice central;

void BTLEsetup(){
    setRGB(YELLOW);
    delay(500);
    setRGB(BLUE);
    delay(500);
    setRGB(OFF);
    if(!BLE.begin()){
        Serial.println("fail to start BT LE");
        while (1)
        {
            setRGB(RED); //show error color code 
            delay(500);
            setRGB(BLUE);
            delay(500);
            setRGB(OFF);
            delay(500);

        }
    }
    BLE.setLocalName("BatteryMonitor");
    BLE.setAdvertisedService(posRservice); // add the service UUID
    posRservice.addCharacteristic(batteryLevelChar); // add the battery level characteristic
    BLE.addService(posRservice); // Add the battery service
    batteryLevelChar.writeValue(oldBatteryLevel); // set initial value for this characteristic

    /* Start advertising BLE.  It will start continuously transmitting BLE
     advertising packets and will be visible to remote BLE central devices
     until it receives a new connection */

    // start advertising
    BLE.advertise();

    setRGB(GREEN);
    delay(500);
    setRGB(BLUE);
    delay(500);
    setRGB(OFF);
    Serial.println("Bluetooth device active, waiting for connections...");
}

void connectBTLE(){
    central = BLE.central();
    if (central) {
    Serial.print("Connected to central: ");
    // print the central's BT address:
    Serial.println(central.address());
    // turn on the LED to indicate the connection:
    }else{
        Serial.print("connection failed @ connectBTLE");
    }
}
    
void reportPosition(sPosition sPos){
    if(!central.connected()){
        connectBTLE();
    }
    int battery = sPos.indexF;
    int batteryLevel = battery;

    if (batteryLevel != oldBatteryLevel) {      // if the battery level has changed
    Serial.print("Battery Level % is now: "); // print it
    Serial.println(batteryLevel);
    batteryLevelChar.writeValue(batteryLevel);  // and update the battery level characteristic
    oldBatteryLevel = batteryLevel;           // save the level for next comparison
    }





}
    
