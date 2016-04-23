//By NAYjY 160325
//GPS
//Formula student racing car CAN protocol data logger
//160317 Use FCANLOG.h
//160409 Timing 1
// Upload Staus 1


#include <mcp_can.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include "FCANLOG.h"

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

//c++ class
MCP_CAN CAN(CAN_SPI_CS_UNOR3_PIN);                                    // Set CS pin
TinyGPSPlus gps;
SoftwareSerial ss(RXPin,TXPin);



//Variable Definition
byte  *ByteLat,*ByteLon; //IEE754
uint8_t Buf[lenGPS];
float flat, flon;


unsigned long previousMillis = 0;        // will store last time was updated
// constants won't change :
const long interval = 100; // 10 mes/s (1000/10)

void setup() {
    Serial.begin(Buadrate);
    ss.begin(GPSBaud);

    //pinMode(LED_Y, OUTPUT);
    //pinMode(LED_W, OUTPUT);
        
    //CAN init
    START_INIT:

    if(CAN_OK == CAN.begin(CAN_500KBPS))                   // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS AFR Shield init ok!");
    }
    else
    {
        Serial.println("CAN BUS AFR Shield init fail");
        Serial.println("Init CAN BUS AFR Shield again");
        delay(100);
        goto START_INIT;
    }
}

void loop() {



  while (ss.available()) {
   //Serial.println("ss good");
      gps.encode(ss.read());
      flat = (gps.location.lat());
      flon = (gps.location.lng());
    }
//    flat = (gps.location.lat());
//    flon = (gps.location.lng());
    Serial.print(flat,6);Serial.print('\t'); Serial.println(flon,6);
   
                 unsigned long currentMillis = millis();
                 if(currentMillis - previousMillis >= interval) {
                 // save the last time 
                 previousMillis = currentMillis;    
    ByteLat = (byte*) & flat;
    //Serial.println(*ByteLat);
    CAN.sendMsgBuf(GPS_LAT_ID, 0, lenGPS, ByteLat);

    ByteLon = (byte*) & flon;
    CAN.sendMsgBuf(GPS_LON_ID, 0, lenGPS, ByteLon);

    uint32_t tGPS = millis();
    uint8_t tBuf[4] = {(tGPS>>24)& 0xFF,(tGPS>>16)& 0xFF,(tGPS>>8)& 0xFF,tGPS& 0xFF};
    CAN.sendMsgBuf(0xD1, StandardID, 4, tBuf);
                 }
}



