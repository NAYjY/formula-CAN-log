//By NAYjY 160325
//GPS
//Formula student racing car CAN protocol data logger
//160317 Use FCANLOG.h
//160409 Timing 1
// Upload Staus 1


#include <mcp_can.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include "FCANLOG.h"


//c++ class
MCP_CAN CAN(CAN_SPI_CS_NAYjY_PIN);                                    // Set CS pin
TinyGPS gps;
SoftwareSerial ss(GPS_NAYjY_RX_PIN,GPS_NAYjY_TX_PIN);

//Variable Definition
byte  *ByteLat,*ByteLon; //IEE754
uint8_t Buf[lenGPS];
float flat, flon;
unsigned long age;

void setup() {
    Serial.begin(Buadrate);
    ss.begin(Buadrate);

    pinMode(LED_Y, OUTPUT);
    pinMode(LED_W, OUTPUT);
        
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

//while(CheckTime());
//delay(delayGPS);

//  bool newData = false;
//
//  for (unsigned long start = millis(); millis() - start < 1000;)
//  {
//    //Serial.println(ss.available());
//    while (ss.available())
//    {
//      char c = ss.read();
//       Serial.println(c); // uncomment this line if you want to see the GPS data flowing
//      if (gps.encode(c)) // Did a new valid sentence come in?
//        newData = true;
//    }
//  }
//  digitalWrite(LED_Y, newData);
  digitalWrite(LED_W, ss.available());

//   if (newData)
//  {

    gps.f_get_position(&flat, &flon, &age);
//    Serial.print("LAT=");
//    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
//    Serial.print(" LON=");
//    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    
    Buf[0]=((flat,6)>>8); Buf[1] = (flat,6) & 0xFF; //(Buf[0]<<8)+Buf[1]);
    Buf[2]=((flon,6)>>8); Buf[3] = (flon,6) & 0xFF; //(Buf[0]<<8)+Buf[1]);
//    Serial.print('\t');
//    Serial.print(Buf[0],HEX);Serial.print(Buf[0],HEX);
//    Serial.print('\t');
//    Serial.print(Buf[0],HEX);Serial.println(Buf[0],HEX);.
    ByteLat = (byte*) & flat;
    //Serial.println(*ByteLat);
    CAN.sendMsgBuf(GPS_LAT_ID, 0, lenGPS, ByteLat);

    ByteLon = (byte*) & flon;
    CAN.sendMsgBuf(GPS_LON_ID, 0, lenGPS, ByteLon);
    
//  }
delay(33);
}

bool CheckTime(){

   if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
        if (CAN.getCanId() == TIME_ID) return Flase;
        else return True;
    }    

}

