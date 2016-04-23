//By NAYjY 160415
//Formula student racing car CAN protocol data logger project

#ifndef _COMPAIR_H_
#define _COMPAIR_H_

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

#define FR_FR_ID 0xF0 //**FR
#define FL_FL_ID 0xF5 //**FL
#define BR_BR_ID 0xFA //**BR
#define BL_BL_ID 0xFF //**BL

#define Analog_ID 0x01 //**FR

//Define Analog Pin
#define FrontRight A0
#define FrontLeft  A1
#define BackRight  A2
#define BackLeft   A3

uint16_t FR, FL, BR, BL;

#endif /* _COMPAIR_H_ */