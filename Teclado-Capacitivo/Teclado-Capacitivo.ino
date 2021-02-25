#include <CapacitiveSensor.h>
 
//Resistor ligando os pinos 4 e 2 (sender=2, receiver=3)
CapacitiveSensor   sensor = CapacitiveSensor(2,7); 
CapacitiveSensor   sensor2 = CapacitiveSensor(2,4); 

int buzzer = 11;

int SENSIBILIDADE = 900; //Frontreira que defini entre tocar ou nao
bool ligado = 0; //Indica se a lampada esta ligada ou nao
int total = 0; //Valor colhido pelo pino receptor

void setup()  
{
    pinMode(buzzer,OUTPUT);
    Serial.begin(9600); //Saida serial 
}

void loop()                   
{

    long total =  sensor.capacitiveSensor(30); //Le valor no pino receptor
    long total2 =  sensor2.capacitiveSensor(30); //Le valor no pino receptor
    
    
    //Verifica se valor lido eh maior ou nao que a fronteira definida
    /*if (total > SENSIBILIDADE) { 
         ligado = !ligado;
         if (ligado) 
             Serial.println("LAMPADA LIGADA");
         else
             Serial.println("LAMPADA DESLIGADA");

          //Delay que simula o tempo de mudar intensidade do led no interruptor         
         for (int i=255; i>1; i--) { 
             delay(5);
          }
    } 
   
    if(total>30)
      tone(8,200,50);
    if(total2>1000)
      tone(8,600,50);
//    if(total3>1000)
//tone(8,900,50);
     */
   
    Serial.println();
    Serial.print(total);   
    Serial.print(" - ");  
    Serial.print(total2);

    delay(100);                 
}
