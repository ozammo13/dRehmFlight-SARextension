#ifdef GpsData_h
#include "GpsData.h"

void GpsClass::Setup()
{
  GpsSerial = SoftwareSerial(0,1)
  GpsSerial.begin(9600);
  Serial.begin(9600);
}

void GpsClass::GpsDataCollection()
{
  while (GpsSerial.available() > 0){
    if (gps.encode(GPSSerial.read()))
    {
      if(gps.location.isValid())
      {
        Serial.println("lattitude - ", gps.location.lat());

        Serial.println("longitude - ", gps.location.lng());

        if(gps.altitude.isValid())
        {
          Serial.println("altitude - ", gps.location.)
        }
        else
        {
          Serial.println(F("INVALID"));
        }
      }
      else
      {
        Serial.println(F("INVALID"));
      }
    }
  }
}
#endif