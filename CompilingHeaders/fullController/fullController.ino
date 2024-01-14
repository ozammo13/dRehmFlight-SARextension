#include "src\GpsData.h"

int run = 1;
GpsData = GpsData();

void setup() 
{
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