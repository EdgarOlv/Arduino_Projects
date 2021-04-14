// Programa : Controle de servo com Motor Shield L293D
// Autor : Arduino e Cia

// Carrega a biblioteca Servo
#include <Servo.h> 
 
// Cria um objeto chamado servo1
Servo servo1;

int val = 0;
 
void setup() 
{ 
  // Indica que o servo1 esta ligado ao pino 10
  servo1.attach(10);  
  Serial.begin(9600);
} 
 
void loop() 
{ 
  // Movimenta o servo
  servo1.write(val);  
  delay(100);
  val = val+5;
  // Envia as informacoes de val para a serial
  Serial.println(val);
  
  // Verifica se o valor de val chegou a 180
  if (val == 180)
  {
    // Caso val chegue a 180, volta a 0
    val = 0;
  }
  
  // Aguarda 15 ms e reinicia o processo
  delay(15);
} 
