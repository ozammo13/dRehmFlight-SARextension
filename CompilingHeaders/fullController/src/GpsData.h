/*
GpsData.h - Library for easy GPS data.
Created by Caleb Hamlet 2023
Partially maintained by Tom Brothers 2023
Released into the public domain.
*/
#include "Arduino.h"
#ifndef GpsData_h
#define GpsData_h
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

class GpsData
{
  public:
    GpsData(int RxPin, int TxPin);
    void Setup(unsigned long SerialSpeed);
    int GpsDataCollection();
    TinyGPSPlus gps;
    SoftwareSerial GpsSerial = SoftwareSerial(0,1);
    //Variables
    float Latt;
    float Long;
    float Alt;
    int ValidOrNot; // valid 1 = data being read, valid 2 = data not being read eg. invalid.
  private:
    int RxPin;
    int TxPin;
};
  
#endif