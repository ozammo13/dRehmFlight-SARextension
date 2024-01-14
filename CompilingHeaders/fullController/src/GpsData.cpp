#ifdef GpsData_h
#include "GpsData.h"


void GpsClass::Setup()
{
  GpsSerial.begin(9600);
  Serial.begin(9600);
}

void GpsClass::GpsSerial()
{
  RxPin = 0;
  TxPin = 1;
  GpsSerial = SoftwareSerial(RxPin,TxPin);
  return GpsSerial;
}

void GpsClass::GpsDataCollection()
{
  if (GpsSerial.available() > 0)
  {
    if (gps.encode(GPSSerial.read()))
    {
      if(gps.location.isValid())
      {
        Latt = gps.location.lat();
        Serial.print(F("lattitude - "));
        Serial.println(gps.location.lat());

        Long = gps.location.lng();
        Serial.print(F("longitude - "));
        Serial.println(gps.location.lng());

        if(gps.altitude.isValid())
        {
          Alt = gps.altitude.meters();
          Serial.print(F("altitude - "));
          Serial.println(gps.altitude.meters());
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
  return Latt, Long, Alt;
}
#endif