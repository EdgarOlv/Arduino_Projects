#include <IRremote.h> 

int RECV_PIN = 6; // Pino responsável por receber o código do IR.
int armazenavalor = 0; // Iniciando com valor igual a zero.
int pino_rele = 13; // Pino onde o rele foi conectado no arduino. 

int estado_rele = LOW; // Inicia com o rele desligado. 

IRrecv irrecv(RECV_PIN); 
decode_results results; 
 
void setup() 
{ 
  pinMode(pino_rele, OUTPUT);  // Define todos os pino como de saída. 
  
 
  digitalWrite(pino_rele, estado_rele); // Coloca os pinos todos os pino em...
 
     Serial.begin(9600); // Inicializa a serial monitor. 
  irrecv.enableIRIn(); // Inicializa o receptor IR. 
} 
  
void loop() 
{ 
  // Verifica se o sensor IR recebeu algum sinal.
  if (irrecv.decode(&results))  
  { 
    // Mostra na serial o valor lido pelo sensor IR.
    Serial.print("Valor lido : ");
    Serial.println(results.value, HEX);
   
    // Armazena o sinal recebido pelo sensor IR. 
    armazenavalor = (results.value);  
    switch (armazenavalor) 
    { 
  
  // Verifica se o botão número 1 do controle remoto foi prescionada.IRremote.h
     case 0xB4B4DC23: 
     // Se prescionado aciona o rele.
     estado_rele = !estado_rele; 
      digitalWrite(pino_rele, estado_rele);
      break; 
     
       }
    irrecv.resume(); //Le o próximo valor 
  } 
}
