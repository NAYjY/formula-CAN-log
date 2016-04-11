//By NAYjY 160312
// MPU6050 for  GY-521
//Formula student racing car CAN protocol data logger
// 160313 Send to CAN bus succesed
// 160317 To the RollPitchYaw
// 160317 Use FCANLOG.h
// 160409 Timing 1
// Upload status 1


//http://playground.arduino.cc/Main/MPU-6050

#include "I2Cdev.h" 
#include "MPU6050_6Axis_MotionApps20.h"
#include <mcp_can.h>
#include <SPI.h>
#include "FCANLOG.h"


// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif


//c++ class
MPU6050 accelgyro;
MCP_CAN CAN(CAN_SPI_CS_NAYjY_PIN);                                    // Set CS pin

//Variable Definition
byte  *ByteYaw,*BytePitch,*ByteRoll; //IEE754
uint8_t BufAcc[lenAcc];


// MPU control/status vars
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

unsigned long previousMillis = 0;        // will store last time was updated
// constants won't change :
const long interval = 37; // 27 mes/s (1000/27)

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector

void setup() {

   // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

     Serial.begin(Buadrate);
     accelgyro.initialize();

            // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
     // load and configure the DMP
    Serial.println(F("Initializing DMP..."));
    devStatus = accelgyro.dmpInitialize(); //***********************************************************************************

//    accelgyro.setXGyroOffset(53);
//    accelgyro.setYGyroOffset(15);
//    accelgyro.setZGyroOffset(-22);
//    accelgyro.setXAccelOffset(-4077);
//    accelgyro.setYAccelOffset(-995);
//    accelgyro.setZAccelOffset(407); // 1688 factory default for my test chip


    accelgyro.setXGyroOffset(53);
    accelgyro.setYGyroOffset(15);
    accelgyro.setZGyroOffset(-22);
    accelgyro.setXAccelOffset(-4110);
    accelgyro.setYAccelOffset(-1097);
    accelgyro.setZAccelOffset(409); 

    // turn on the DMP, now that it's ready
    Serial.println(F("Enabling DMP..."));
    accelgyro.setDMPEnabled(true);

    // get expected DMP packet size for later comparison
    packetSize = accelgyro.dmpGetFIFOPacketSize();

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

                
//while(CheckTime());

//Accelerator part




              accelgyro.getAcceleration(&ax, &ay, &az);
              

//                 Serial.print(ax);
//                 Serial.print("\t");
//                 Serial.print(ay);
//                 Serial.print("\t");
//                 Serial.print(az);
//                 Serial.print("\t");
              
//Gyro YawPithRoll part

                // get current FIFO count
                fifoCount = accelgyro.getFIFOCount();

   
                // wait for correct available data length, should be a VERY short wait
                 while (fifoCount < packetSize) fifoCount = accelgyro.getFIFOCount();

                // read a packet from FIFO
                accelgyro.getFIFOBytes(fifoBuffer, packetSize);
        
                // track FIFO count here in case there is > 1 packet available
                // (this lets us immediately read more without waiting for an interrupt)
                fifoCount -= packetSize;
        
                // display Euler angles in degrees
                accelgyro.dmpGetQuaternion(&q, fifoBuffer);
                accelgyro.dmpGetGravity(&gravity, &q);
                accelgyro.dmpGetYawPitchRoll(ypr, &q, &gravity);
                
//                Serial.print("ypr\t");
//                
//                Serial.print(ypr[0] * 180/M_PI);
//                Serial.print("\t");
//                
//                Serial.print(ypr[1] * 180/M_PI);
//                Serial.print("\t");
                
                //Serial.println(ypr[2] * 180/M_PI);

               


                 unsigned long currentMillis = millis();
                 if(currentMillis - previousMillis >= interval) {
                 // save the last time 
                 previousMillis = currentMillis;   

              BufAcc[0]=(ax>>8); BufAcc[1] = ax & 0xFF; //(BufAcc[0]<<8)+BufAcc[1]);
              BufAcc[2]=(ay>>8); BufAcc[3] = ay & 0xFF; //(BufAcc[2]<<8)+BufAcc[3]);
              BufAcc[4]=(az>>8); BufAcc[5] = az & 0xFF; //(BufAcc[4]<<8)+BufAcc[5]);
              CAN.sendMsgBuf(Acc_ID, StandardID, lenAcc, BufAcc);
                 
                 ByteYaw = (byte*) & ypr[0];
                CAN.sendMsgBuf(Gyr_Y_ID, StandardID, lenGyr, ByteYaw);      //int intbits = (inData[3] << 24) | ((inData[2] & 0xff) << 16) | ((inData[1] & 0xff) << 8) | (inData[0] & 0xff);


                BytePitch = (byte*) & ypr[1];
                CAN.sendMsgBuf(Gyr_P_ID, StandardID, lenGyr, BytePitch);    //int intbits = (inData[3] << 24) | ((inData[2] & 0xff) << 16) | ((inData[1] & 0xff) << 8) | (inData[0] & 0xff);

                ByteRoll = (byte*) & ypr[2];
                CAN.sendMsgBuf(Gyr_R_ID, StandardID, lenGyr, ByteRoll);     //int intbits = (inData[3] << 24) | ((inData[2] & 0xff) << 16) | ((inData[1] & 0xff) << 8) | (inData[0] & 0xff);
          
                 }
}
bool CheckTime(){

   if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
        if (CAN.getCanId() == TIME_ID) return Flase;
        else return True;
    }    

}

