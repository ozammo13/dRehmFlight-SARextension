#include "src\GpsData.h"

 int run = 1;

void setup() 
{
  Serial.begin(9600);
}

void loop() {
  while (run == 1)
  {
    //Serial.print("poop");
    GpsData.GpsDataCollection();
  }
}