#include <dht.h>

dht DHT;

#define DHT11_PIN 4

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  if(DHT.temperature<500 and DHT.temperature>-20){
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  }
  delay(500);
}
