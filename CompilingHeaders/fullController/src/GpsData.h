#ifndef GpsData_h
#define GpsData_h
#include <TinyGPS++.h>
#include <TinyGPSPlus.h>
#include "Arduino.h"
#include "SoftwareSerial.h"

class GpsClass
{
  public:
    GpsClass();
    void Setup();
    void GpsDataCollection();
    //SoftwareSerial GpsSerial();

  private:
    TinyGPSPlus gps;
};

extern GpsClass GpsData;

#endif