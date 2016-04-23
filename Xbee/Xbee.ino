//By NAYjY 160312
// XBee Wireless
//Formula student racing car CAN protocol data logger
// 160313 Wirless sucessed.
// 160313 Recive from CAN bus succesed
// 160317 Use FCANLOG.h
// 160409 Timing 0
// Upload status 0


// We'll use SoftwareSerial to communicate with the XBee:
#include <SoftwareSerial.h>
#include <mcp_can.h>
#include <SPI.h>
#include "FCANLOG.h"

// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(XBee_RX_PIN, XBee_TX_PIN); // RX, TX


MCP_CAN CAN(CAN_SPI_CS_UNOR3_PIN);                                    // Set CS pin

unsigned char flagRecv = 0;
unsigned char len = 0;
unsigned char buf[8];
unsigned char u[2];
void setup()
{
  
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  XBee.begin(Buadrate);
  Serial.begin(Buadrate);
    
    //CAN init
    START_INIT:

    if(CAN_OK == CAN.begin(CAN_500KBPS))                   // init can bus : baudrate = 500k
    {
        Serial.println("000011110000");
    }
    else
    {
        Serial.println("111111111111");
        Serial.println("000000000000");
        delay(100);
        goto START_INIT;
    }

  //Set CAN Mask&Filter
   /*
     * set mask, set both the mask to 0x3ff
     */
//    CAN.init_Mask(0, 0, 0x000);                         // there are 2 mask in mcp2515, you need to set both of them
//    CAN.init_Mask(1, 0, 0x000);
//
//
//    /*
//     * 
//     */
//    CAN.init_Filt(0, 0, 0x800);                          // there are 6 filter in mcp2515
//    CAN.init_Filt(1, 0, 0x800);                          // there are 6 filter in mcp2515
//
//    CAN.init_Filt(2, 0, 0x800);                          // there are 6 filter in mcp2515
//    CAN.init_Filt(3, 0, 0x800);                          // there are 6 filter in mcp2515
//    CAN.init_Filt(4, 0, 0x800);                          // there are 6 filter in mcp2515
//    CAN.init_Filt(5, 0, 0x800);                          // there are 6 filter in mcp2515
   
}
void MCP2515_ISR()
{
    flagRecv = 1;
}
void loop()
{
                                   
//while(CheckECUTime());


        // iterate over all pending messages
        // If either the bus is saturated or the MCU is busy,
        // both RX buffers may be in use and reading a single
        // message does not clear the IRQ conditon.
        while (CAN_MSGAVAIL == CAN.checkReceive()) 
        {
            // read data,  len: data length, buf: data buf
            CAN.readMsgBuf(&len, buf);

            Serial.print(CAN.getCanId(),HEX); //print ID
            
            for(int i = 0; i<len; i++)    // print the data
            {   Serial.print('\t');
                Serial.print(buf[i],HEX);
                
            }
            Serial.println();
            Serial.print(0xD0,HEX); Serial.print('\t'); Serial.println(millis());
        }
    


}

bool CheckECUTime(){
//unsigned char u[2];
   if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
        if (CAN.getCanId() == TIME_ECU_ID) 
        {
          CAN.sendMsgBuf(TIME_ID, 1, 2,u);
          return Flase;
        }
        else return True;
    }    

}
