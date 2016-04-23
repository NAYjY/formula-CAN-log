//By NAYjY 160323
// XBee Wireless
//Formula student racing car CAN protocol data logger
// 160313 Wirless sucessed.
// 160313 Recive from CAN bus succesed


// We'll use SoftwareSerial to communicate with the XBee:
#include <SoftwareSerial.h>


// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(2, 3); // RX, TX

 int i=0,j;
String Y = "FF\tFF\tFF\tFF\tFF\tFF\tFF" ;

void setup()
{
  
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  XBee.begin(57600);
  Serial.begin(57600);
}
   
void loop()
{
            while(i<1000){
             //int8_t Y = 0xFF;
             //String Y = "FF";
             //for(j=0;j<8;j++){Y+="FF";}
             
             Serial.println(Y);
              i=millis();
             // Serial.println(i);
            }
              
 

}
