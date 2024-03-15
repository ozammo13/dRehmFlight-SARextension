#include "Arduino.h"
#include "GpsData.h"
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>


GpsData::GpsData(int RxPin, int TxPin)
{
 SoftwareSerial GpsSerial(RxPin,TxPin);

}
void GpsData::Setup(unsigned long SerialSpeed)
{
  GpsSerial.begin(SerialSpeed);
}

int GpsData::GpsDataCollection(int ValidOrNot, float Latt, float Long, float Alt)
{
  if (GpsSerial.available() > 0)
  {
    ValidOrNot = 1;
    if (gps.encode(GpsSerial.read()))
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
          ValidOrNot = 2;
          Serial.println(F("INVALID"));
        }
      }
      else
      {
        ValidOrNot = 2;
        Serial.println(F("INVALID"));
      }
    }
  }
  return ValidOrNot;

}