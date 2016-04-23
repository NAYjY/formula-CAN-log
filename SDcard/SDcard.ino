//
//https://www.arduino.cc/en/Reference/SPISettings
//SPI.beginTransaction()
//SPI.endTransaction()
//SPI.usingInterrupt()




/*
  SD card datalogger

 This example shows how to log data from three analog sensors
 to an SD card using the SD library.

 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */
#include <mcp_can.h>
#include "FCANLOG.h"
#include <SPI.h>
#include <SD.h>

MCP_CAN CAN(CAN_SPI_CS_UNOR3_PIN); 
const int chipSelect = 4;
unsigned char flagRecv = 0;
unsigned char len = 0;
unsigned char buf[8];
void setup()
{
  // Open serial communications and wait for port to open:


Serial.begin(57600);

//    pinMode(chipSelect,OUTPUT);
//    pinMode(CAN_SPI_CS_UNOR3_PIN,OUTPUT);
//    digitalWrite(chipSelect,HIGH);
//    digitalWrite(CAN_SPI_CS_UNOR3_PIN,LOW);
START_SDINIT :
    Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    delay(100);
        goto START_SDINIT;
  }
  Serial.println("card initialized.");
  
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
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    delay(100);
        goto START_SDINIT;
  }
  Serial.println("card initialized.");
  
    

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


  
}

void MCP2515_ISR()
{
    flagRecv = 1;
}
void loop()
{
  // make a string for assembling the data to log:
  String dataString = "";

if(flagRecv) 
    {                                   // check if get data

        flagRecv = 0;                   // clear flag

        // iterate over all pending messages
        // If either the bus is saturated or the MCU is busy,
        // both RX buffers may be in use and reading a single
        // message does not clear the IRQ conditon.
        while (CAN_MSGAVAIL == CAN.checkReceive()) 
        {
            // read data,  len: data length, buf: data buf
            CAN.readMsgBuf(&len, buf);

            dataString+= (CAN.getCanId(),HEX);Serial.print("\t"); //print ID

            for(int i = 0; i<len; i++)    // print the data
            {
                 dataString+=(buf[i],HEX);
                 dataString+=("\t");
            }
            //Serial.println();
        }
    }
    
    digitalWrite(chipSelect,LOW); // Use any pin except 10,11,12 or 13
    SPI.transfer('1');
    digitalWrite(chipSelect,HIGH);
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {Serial.println("AAA");
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    //Serial.println("error opening datalog.txt");
  }
}









