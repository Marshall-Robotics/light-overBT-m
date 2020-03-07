#include <ArduinoBLE.h>
#include <data.h>
#include <light.h>

BLEService posRservice("180F");

BLEUnsignedCharCharacteristic sPosChar00("EE00",  // standard 16-bit characteristic UUID
BLERead | BLENotify);
BLEUnsignedCharCharacteristic sPosChar01("EE01",  // standard 16-bit characteristic UUID
BLERead | BLENotify);
BLEUnsignedCharCharacteristic sPosChar02("EE02",  // standard 16-bit characteristic UUID
BLERead | BLENotify);
BLEUnsignedCharCharacteristic sPosChar03("EE03",  // standard 16-bit characteristic UUID
BLERead | BLENotify);
BLEUnsignedCharCharacteristic sPosChar04("EE04",  // standard 16-bit characteristic UUID
BLERead | BLENotify);
BLEUnsignedCharCharacteristic sPosChar05("EE05",  // standard 16-bit characteristic UUID
BLERead | BLENotify);

BLEDevice central;

void BTLEsetup(){
    serRGBA(YELLOW);
    delay(500);
    serRGBA(BLUE);
    delay(500);
    serRGBA(OFF);
    if(!BLE.begin()){
        Serial.println("fail to start BT LE");
        while (1)
        {
            serRGBA(RED); //show error color code 
            delay(500);
            serRGBA(BLUE);
            delay(500);
            serRGBA(OFF);
            delay(500);

        }
    }
    BLE.setLocalName("glove-kinesis");
    BLE.setAdvertisedService(posRservice); // add the service UUID

    posRservice.addCharacteristic(sPosChar00); // add the battery level characteristic
    posRservice.addCharacteristic(sPosChar01);
    posRservice.addCharacteristic(sPosChar02);
    posRservice.addCharacteristic(sPosChar03);
    posRservice.addCharacteristic(sPosChar04);
    posRservice.addCharacteristic(sPosChar05);

    BLE.addService(posRservice); // Add the battery service
    sPosChar00.writeValue(50); // set initial value for this characteristic

    /* Start advertising BLE.  It will start continuously transmitting BLE
     advertising packets and will be visible to remote BLE central devices
     until it receives a new connection */

    // start advertising
    BLE.advertise();

    serRGBA(GREEN);
    delay(500);
    serRGBA(BLUE);
    delay(500);
    serRGBA(OFF);
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
    
    sPosChar00.writeValue(sPos.pinkyF);
    sPosChar01.writeValue(sPos.ringF);
    sPosChar02.writeValue(sPos.middleF);
    sPosChar03.writeValue(sPos.indexF);  // and update the battery level characteristic
    sPosChar04.writeValue(sPos.thumbF);
    sPosChar05.writeValue(sPos.wrist);
    
}
    
