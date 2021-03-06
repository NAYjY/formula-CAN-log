//By NAYjY 160317
//Analog Back-Right
//Formula student racing car CAN protocol data logger
// 160317 Use FCANLOG.h
// 160409 Timing 1
// Upload status 1

#include <mcp_can.h>
#include <SPI.h>
#include "FCANLOG.h"

//c++ class
MCP_CAN CAN(CAN_SPI_CS_NAYjY_PIN);                                    // Set CS pin

//Variable Definition
uint8_t Buf[lenAnalog];


unsigned long previousMillis = 0;        // will store last time was updated
// constants won't change :
const long interval = 100; // 10 mes/s (1000/10)


void setup() {


     Serial.begin(Buadrate);

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

              unsigned long currentMillis = millis();
                 if(currentMillis - previousMillis >= interval) {
                 // save the last time 
                 previousMillis = currentMillis;
              // read Analog 10-bits from device 
              // Then send to CAN
              
              BR = analogRead(BackRight);
              //Serial.println(BR);
              Buf[0]=(BR>>8); Buf[1] = BR & 0xFF; //(Buf[0]<<8)+Buf[1]);
              CAN.sendMsgBuf(BR_BR_ID, 0, lenAnalog, Buf);
              
                 }
              


}


