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

void GpsData::GpsDataCollection()
{
  if (GpsSerial.available() > 0)
  {
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