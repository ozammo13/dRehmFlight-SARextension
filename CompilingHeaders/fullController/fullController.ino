#include "src\GpsData.h"

GpsData gps(0, 1); // Define GPS pins

void setup()
{
  gps.Setup(9600); // Setup GPS
}
void loop()
{
  gps.GpsDataCollection();
}
