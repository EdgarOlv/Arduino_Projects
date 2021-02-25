#include<CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(6,7);

void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  long lectura = sensor.capacitiveSensor(30);
  Serial.println(lectura);
  if(lectura>1)
    digitalWrite(13,HIGH);
  else
  digitalWrite(13,LOW);

    delay(10);
}

