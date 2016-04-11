//By NAYjY 160317
//Analog Front-Left
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

  //while(CheckTime());
  delay(delayFrontLeft);
              // read Analog 10-bits from device 
              // Then send to CAN
              
              FL = analogRead(FrontLeft);
              //Serial.println(FL);
              Buf[0]=(FL>>8); Buf[1] = FL & 0xFF; //(Buf[0]<<8)+Buf[1]);
              CAN.sendMsgBuf(FL_FL_ID, 0, lenAnalog, Buf);
              
              
              delay(24);


}

bool CheckTime(){

   if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
        if (CAN.getCanId() == TIME_ID) return Flase;
        else return True;
    }    

}
