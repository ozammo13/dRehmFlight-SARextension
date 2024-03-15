#include "src/GpsData.h"

int RxPin = 0;
int TxPin = 1;

GpsData gps(RxPin, TxPin); // Define GPS pins

void setup()
{
  Serial.begin(9600);
  Serial.println("noooooo");
  gps.Setup(9600); // Setup GPS
}

void loop()
{
  Serial.println(gps.GpsDataCollection());
}
