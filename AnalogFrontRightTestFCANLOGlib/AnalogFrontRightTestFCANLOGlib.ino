//By NAYjY 160313
//Analog Front-Right
//Formula student racing car CAN protocol data logger
// 160313 Send to CAN bus succesed
// 160317 Use FCANLOG.h


#include <mcp_can.h>
#include <SPI.h>
#include "FCANLOG.h"

//Even-Right Odd-Left
//Analog Pin
//#define FrontRight A0
//#define FrontLeft A1
//#define BackRight A2
//#define BackLeft A3
//
//const int SPI_CS_PIN = 10; //myBorad-10 UNO-9

//// Identify Bit
//const uint8_t FR_FR_ID = 0xF0;
//const uint8_t FL_FR_ID = 0xF1;
//const uint8_t BR_FR_ID = 0xF2;
//const uint8_t BL_FR_ID = 0xF3;

//c++ class
MCP_CAN CAN(CAN_SPI_CS_NAYjY_PIN);                                    // Set CS pin

//Variable Definition
//uint8_t ID[2] = {FR_FR_ID,FL_FR_ID}; //Even-Right Odd-Left
uint8_t Buf[2];

uint16_t FR;


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
              // read Analog 10-bits from device 
              // Then send to CAN
              
              FR = analogRead(FrontRight);
              Serial.println(FR);
              Buf[0]=(FR>>8); Buf[1] = FR & 0xFF; //(Buf[0]<<8)+Buf[1]);
              CAN.sendMsgBuf(FR_FR_ID, 0, 2, Buf);
              
              
              


}
