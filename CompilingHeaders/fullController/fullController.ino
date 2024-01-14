#include "src\GpsData.h"

int run = 1;

void setup() 
{
  GpsData.GpsSerial();
  GpsData.Setup();
}

void loop() 
{
  while (run == 1)
  {
    //Serial.print("poop");
    GpsData.GpsDataCollection();
  }
}