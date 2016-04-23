//By NAYjY 160312
// MPU6050 for  GY-521
//Formula student racing car CAN protocol data logger
// 160313 Send to CAN bus succesed


#include "I2Cdev.h" 
#include "MPU6050.h"
#include <mcp_can.h>
#include <SPI.h>

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif


const int SPI_CS_PIN = 10; //myBorad-10 UNO-9
//c++ class
MPU6050 accelgyro;
MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin
//Variable Definition
uint8_t ID[6] = {0xA0,0xA1,0xA2,0xB0,0xB1,0xB2};
uint8_t Buf[2];

int16_t ax, ay, az; 
int16_t gx, gy, gz;




void setup() {

  
   // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

     Serial.begin(57600);
     accelgyro.initialize();
     // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    //CAN init
    START_INIT:

    if(CAN_OK == CAN.begin(CAN_500KBPS))                   // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS GY Shield init ok!");
    }
    else
    {
        Serial.println("CAN BUS GY Shield init fail");
        Serial.println("Init CAN BUS GY Shield again");
        delay(100);
        goto START_INIT;
    }
    

}

void loop() {
              // read raw accel/gyro measurements from device 
              // Then send to CAN
              
              accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); //This's slower one.
              Serial.println(ax);
              //ax = accelgyro.getAccelerationX();
              Buf[0]=(ax>>8); Buf[1] = ax & 0xFF; //(Buf[0]<<8)+Buf[1]);
              CAN.sendMsgBuf(ID[0], 0, 2, Buf);
              Serial.print(Buf[0]); Serial.println(Buf[1]);
              ay = accelgyro.getAccelerationY();
              Buf[0]=(ay>>8); Buf[1] = ay & 0xFF; //(Buf[0]<<8)+Buf[1]);
              CAN.sendMsgBuf(ID[1], 0, 2, Buf);

              az = accelgyro.getAccelerationZ();
              Buf[0]=(az>>8); Buf[1] = az & 0xFF; //(Buf[0]<<8)+Buf[1]);
              CAN.sendMsgBuf(ID[2], 0, 2, Buf);
              
              gx = accelgyro.getRotationX();
              Buf[0]=(gx>>8); Buf[1] = gx & 0xFF; //(Buf[0]<<8)+Buf[1]);
              CAN.sendMsgBuf(ID[3], 0, 2, Buf);
                            
              gy = accelgyro.getRotationY();
              Buf[0]=(gy>>8); Buf[1] = gy & 0xFF; //(Buf[0]<<8)+Buf[1]);
              CAN.sendMsgBuf(ID[4], 0, 2, Buf);
                            
              gz = accelgyro.getRotationZ();
              Buf[0]=(gz>>8); Buf[1] = gz & 0xFF; //(Buf[0]<<8)+Buf[1]);
              CAN.sendMsgBuf(ID[5], 0, 2, Buf);
              
////For Debuging
////          int i;
////              for(i=0;i<2;i++){
////              Serial.print(Buf[i]);Serial.print("\t");
////              }Serial.println("");
//
////CANsendMessage
//             CAN.sendMsgBuf(ID, 0, 5, B);

}
