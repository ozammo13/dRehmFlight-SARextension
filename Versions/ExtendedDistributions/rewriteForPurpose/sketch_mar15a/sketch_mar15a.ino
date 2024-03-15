// This is a re-write of the existing Dhrem flight controller to suit our specific needs for the teensy based flight controller.
// As we only need limited capabilities removing many of the functions will improve debugging and allow easier understanding of ammendments.

// ====================================================================
#define USE_PWM_RX // Transmitter type defined
static const uint8_t num_DSM_channels = 6; //If using DSM RX, change this to match the number of transmitter channels you have

#define USE_MPU6050_I2C //Default IMU definition

#define GYRO_250DPS //Default GYRO Range def

#define ACCEL_2G //Default Accelerometer Range def

// ====================================================================

//REQUIRED LIBRARIES (included with download in main sketch folder)

#include <Wire.h>     //I2c communication
#include <SD.h>       //SD card writing
#include <SPI.h>      //SPI communication
#include <PWMServo.h> //Commanding any extra actuators, installed with teensyduino installer

#if defined USE_SBUS_RX
  #include "src/SBUS/SBUS.h"   //sBus interface
#endif

#if defined USE_DSM_RX
  #include "src/DSMRX/DSMRX.h"  
#endif

#if defined USE_MPU6050_I2C
  #include "src/MPU6050/MPU6050.h"
  MPU6050 mpu6050;
#elif defined USE_MPU9250_SPI
  #include "src/MPU9250/MPU9250.h"
  MPU9250 mpu9250(SPI2,36);
#else
  #error No MPU defined... 
#endif

// ====================================================================

//Radio failsafe values for every channel in the event that bad reciever data is detected. Recommended defaults:
unsigned long channel_1_fs = 1000; //thro
unsigned long channel_2_fs = 1500; //ail
unsigned long channel_3_fs = 1500; //elev
unsigned long channel_4_fs = 1500; //rudd
unsigned long channel_5_fs = 2000; //gear, greater than 1500 = throttle cut
unsigned long channel_6_fs = 2000; //aux1

const int ChipSelect = BUILTIN_SDCARD; //directs to the on board sd card

//Filter parameters - Defaults tuned for 2kHz loop rate; Do not touch unless you know what you are doing:
float B_madgwick = 0.04;  //Madgwick filter parameter
float B_accel = 0.14;     //Accelerometer LP filter paramter, (MPU6050 default: 0.14. MPU9250 default: 0.2)
float B_gyro = 0.1;       //Gyro LP filter paramter, (MPU6050 default: 0.1. MPU9250 default: 0.17)
float B_mag = 1.0;        //Magnetometer LP filter parameter

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
