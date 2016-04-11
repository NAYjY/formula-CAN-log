//By NAYjY 160313
//Formula student racing car CAN protocol data logger project

#ifndef _FCANLOG_H_
#define _FCANLOG_H_

#define True 1
#define Flase 0
#define Buadrate 57600
#define CAN_SPI_CS_NAYjY_PIN 10
#define CAN_SPI_CS_UNOR3_PIN 9
#define SDcard_SPI_CS_UNOR3_PIN 10
#define XBee_RX_PIN 2
#define XBee_TX_PIN 3
#define GPS_NAYjY_RX_PIN 4
#define GPS_NAYjY_TX_PIN 5
#define LED_W 8
#define LED_G 7
#define LED_Y 6
#define StandardID 0
#define ExtendID 1

#define lenAcc 6
#define lenGyr 4
#define lenGPS 4
#define lenECU 6
#define lenTimeECU 2
#define lenAnalog 2


#define XAccelOffset -4300
#define YAccelOffset -951
#define ZAccelOffset 4015
#define XGyroOffset 52
#define YGyroOffset 11
#define ZGyroOffset -18

//Define Identify bit
#define TIME_ID 0x800
#define Acc_ID 0xA0
//#define Acc_Y_ID 0xA1
//#define Acc_Z_ID 0xA2
#define Gyr_Y_ID 0xB0
#define Gyr_P_ID 0xB1
#define Gyr_R_ID 0xB2
//#define GPS_ID 0xC0
#define GPS_LAT_ID 0xC0
#define GPS_LON_ID 0xC1
#define ECU_ID 0xE0
#define TIME_ECU_ID 0xE1
#define FR_FR_ID 0xF0 //**FR
#define FL_FR_ID 0xF1
#define BR_FR_ID 0xF2
#define BL_FR_ID 0xF3
#define FR_FL_ID 0xF4
#define FL_FL_ID 0xF5 //**FL
#define BR_FL_ID 0xF6
#define BL_FL_ID 0xF7
#define FR_BR_ID 0xF8
#define FL_BR_ID 0xF9
#define BR_BR_ID 0xFA //**BR
#define BL_BR_ID 0xFB
#define FR_BL_ID 0xFC
#define FL_BL_ID 0xFD
#define BR_BL_ID 0xFE
#define BL_BL_ID 0xFF //**BL

//Define Analog Pin
#define FrontRight A0
#define FrontLeft  A1
#define BackRight  A2
#define BackLeft   A3

#define delayAcc 5
#define delayYaw 2
#define delayPitch 0
#define delayRoll 0
#define delayGPS 0
#define delayFrontRight 12
#define delayFrontLeft 9
#define delayBackRight 16
#define delayBackLeft 2

int16_t ax, ay, az; 
int16_t gx, gy, gz;
int Yaw,Pitch,Roll;
uint16_t FR, FL, BR, BL;
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector



#endif /* _FCANL_H_ */