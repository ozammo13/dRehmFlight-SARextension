#include <TinyGPS++.h>
#include "GpsData.h"

#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>

Servo EscSig;
Servo FlapLeft;
Servo FlapRight;

SoftwareSerial GpsSerial(0, 1);
String FlapInput;

const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void setup() {

  EscSig.attach(9);
  EscSig.write(30);

  FlapLeft.attach(17);
  FlapRight.attach(16);
  

  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);

  GpsSerial.begin(9600);

  delay(3000);
}

void loop() {
  // GpsData();
  // GyroMain();
  BLDCMotor();
  // FlapControl();
}

void BLDCMotor()
{
  EscSig.write(55);
  delay(30);
}

void FlapsControl()
{
  FlapInput = "up";
  if(FlapInput == "down")
  { 
    FlapLeft.write(90);
    delay(1000);
    FlapInput == "down";
  }  
  else
  {
    FlapLeft.write(0);
  }
}