// Programa : Teste Controle Remoto IR  
// Autor : Arduino e Cia  
  
#include <IRremote.h>  
  
int RECV_PIN = 4;  
float armazenavalor;  
int pinoledvermelho = 5;  
int pinoledverde = 7;  
  
IRrecv irrecv(RECV_PIN);  
decode_results results;  
  
void setup()  
{  
  pinMode(pinoledvermelho, OUTPUT);   
  pinMode(pinoledverde, OUTPUT);  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR  
}  
   
void loop()  
{  
  if (irrecv.decode(&results))  
  {  
    Serial.print("Valor lido : ");  
    Serial.println(results.value, HEX);  
    armazenavalor = (results.value);  
    if (armazenavalor == 0xFF30CF) //Verifica se a tecla 1 foi acionada  
    {  
      digitalWrite(pinoledvermelho, HIGH);  //Acende o led vermelho  
    }  
    if (armazenavalor == 0xFF18E7) //Verifica se a tecla 2 foi acionada  
    {  
      digitalWrite(pinoledvermelho, LOW); //Apaga o led vermelho  
    }  
    if (armazenavalor == 0xFF10EF) //Verifica se a tecla 4 foi acionada  
    {  
      digitalWrite(pinoledverde, HIGH); //Acende o led verde  
    }  
    if (armazenavalor == 0xFF38C7) //Verifica se a tecla 5 foi acionada  
    {  
      digitalWrite(pinoledverde, LOW); //Apaga o led verde  
    }  
    if (armazenavalor == 0xFF52AD) //Verifica se a tecla 9 foi acionada  
    {  
      digitalWrite(pinoledvermelho, LOW); //Apaga todos os leds  
      digitalWrite(pinoledverde, LOW);  
    }  
  irrecv.resume(); //Le o próximo valor  
  }  
}  
