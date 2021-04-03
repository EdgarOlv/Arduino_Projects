//Programa: Sensor de luz BH1750 e LCD 16x2 I2C
//Autor: Arduino e Cia
#include <Wire.h>

#include <BH1750.h>

//Define o sensor BH1750
BH1750 lightMeter;
void setup()
{
  Serial.begin(9600);

  //Inicializa o BH1750
  lightMeter.begin();
}
void loop()
{
  //Le os valores do sensor de lux
  uint16_t lux = lightMeter.readLightLevel();
  
  //Mostra as informacoes na serial
  Serial.print("Luminosidade: ");
  Serial.print(lux);
  Serial.println(" lux");

  
  delay(1000);
}
