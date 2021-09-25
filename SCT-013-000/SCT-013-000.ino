//Projeto: Sensor de Corrente SCT-013 com Arduino
//Autor Baú da Eletrônica (www.baudaeletronica.com.br)

#include "EmonLib.h"
 
EnergyMonitor sensor;
 
int pin = A0;   
 
int tensao = 127;
int potencia;
 
void setup()
{
    sensor.current(pin, 60.606);
 
    Serial.begin(9600);
}
 
void loop()
{
    double Irms = sensor.calcIrms(1500);  
    
    potencia = Irms * tensao;             
 
    Serial.print("Corrente = ");
    Serial.print(Irms);
    Serial.println(" A");
    
    Serial.print("Potencia = ");
    Serial.print(potencia);
    Serial.println(" W");
    Serial.println("********************");
   
    delay(3000);
 
   
}
