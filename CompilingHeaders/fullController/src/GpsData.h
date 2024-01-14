#ifndef GpsData_h
#define GpsData_h

#include <TinyGPS++.h> //Is this the right library? You declare TinyGPSPlus later on but i cant see TinyGPS++ anywhere
#include "Arduino.h"
#include "SoftwareSerial.h"

class GpsClass
{
  public:
    void Setup();
    void GpsDataCollection();
    SoftwareSerial GpsSerial();

  private:
    TinyGPSPlus gps;
};

extern GpsClass GpsData;

#endif