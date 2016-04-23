//By NAYjY 160312
// XBee Wireless
//Formula student racing car CAN protocol data logger
// 160313 Wirless sucessed.
// 160313 Recive from CAN bus succesed
// For Hed's project


// We'll use SoftwareSerial to communicate with the XBee:
#include <SoftwareSerial.h>
#include <mcp_can.h>
#include <SPI.h>

// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(2, 3); // RX, TX

const int SPI_CS_PIN = 9;
MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

unsigned char flagRecv = 0;
unsigned char len = 0;
unsigned char buf[8];

void setup()
{
  
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  XBee.begin(57600);
  Serial.begin(57600);
    
    //CAN init
    START_INIT:

    if(CAN_OK == CAN.begin(CAN_500KBPS))                   // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init ok!");
    }
    else
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(100);
        goto START_INIT;
    }
  attachInterrupt(0, MCP2515_ISR, FALLING); // start interrupt

  //Set CAN Mask&Filter
   /*
     * set mask, set both the mask to 0xA0 recieve only acc
     */
   CAN.init_Mask(0, 0, 0xA0);                         // there are 2 mask in mcp2515, you need to set both of them
   CAN.init_Mask(1, 0, 0xA0);
//
//
//    /*
//     * 
//     */
    CAN.init_Filt(0, 0, 0xF0);                          // there are 6 filter in mcp2515
    CAN.init_Filt(1, 0, 0xF0);                          // there are 6 filter in mcp2515
//
    CAN.init_Filt(2, 0, 0xF0);                          // there are 6 filter in mcp2515
    CAN.init_Filt(3, 0, 0xF0);                          // there are 6 filter in mcp2515
    CAN.init_Filt(4, 0, 0xF0);                          // there are 6 filter in mcp2515
    CAN.init_Filt(5, 0, 0xF0);                          // there are 6 filter in mcp2515
   
}
void MCP2515_ISR()
{
    flagRecv = 1;
}
void loop()
{
   if(flagRecv) 
    {                                   // check if get data

        flagRecv = 0;                   // clear flag

      
        // iterate over all pending messages
        // If either the bus is saturated or the MCU is busy,
        // both RX buffers may be in use and reading a single
        // message does not clear the IRQ conditon.
        while (CAN_MSGAVAIL == CAN.checkReceive()) 
        { // read four sensors
           for (int analogPin = 0; analogPin < 4; analogPin++) {
              int sensor = analogRead(analogPin);
              Serial.print(sensor);Serial.print("\t");
              }
            // read data,  len: data length, buf: data buf
            CAN.readMsgBuf(&len, buf);

                Serial.print(int((buf[0]<<8)+buf[1]));
                Serial.print("\t");
                Serial.print(int((buf[2]<<8)+buf[3]));
                Serial.print("\t");
                Serial.print(int((buf[4]<<8)+buf[5]));
                Serial.print("\t");
                Serial.println(micros());
        }
    }

}
