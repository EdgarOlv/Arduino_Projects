/*
Projeto Arduino controla led RGB.
Por Jota
----------------------------------------
--=<| www.ComoFazerAsCoisas.com.br |>=--
----------------------------------------
*/
 
//Declaração das constantes
const int ledAzul = 8;      //refere-se ao pino digital 8.
const int ledVerde = 9;     //refere-se ao pino digital 9.
const int ledVermelho = 10; //refere-se ao pino digital 10.
 
//Método setup, executado uma vez ao ligar o Arduino.
void setup() {
  //Definindo os pinos digitais (8, 9, 10) como de saída.
  pinMode(ledAzul,OUTPUT);   
  pinMode(ledVerde,OUTPUT);   
  pinMode(ledVermelho,OUTPUT);    
}
 
//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {   
  //Acendendo cada cor individualmente.  
  digitalWrite(ledAzul,HIGH);
  delay(500);
  digitalWrite(ledAzul,LOW);
   
  digitalWrite(ledVerde,HIGH);
  delay(500);
  digitalWrite(ledVerde,LOW);
   
  digitalWrite(ledVermelho,HIGH);
  delay(500);
  digitalWrite(ledVermelho,LOW);    
   
  //Misturando as cores do led para obter cores diferentes.
  digitalWrite(ledAzul,HIGH);     
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,HIGH);
  delay(1500);    
  digitalWrite(ledAzul,HIGH);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,LOW);  
  delay(1500);      
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,HIGH);
  delay(1500);      
  digitalWrite(ledAzul,HIGH);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledVermelho,HIGH);
  delay(1500);
}
