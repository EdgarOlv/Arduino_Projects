  
//Programa : Comunicacao com Modulo RF 433 - Receptor
//Autor : Arduino e Cia

#include <VirtualWire.h>

//Define pino led
int ledPin = 13;

int valor_recebido_RF;
char recebido_RF_char[4]; 

void setup() 
{
  Serial.begin(9600);
  vw_set_rx_pin(7);     //Pino ligado ao pino DATA do receptor RF
  vw_setup(5000);       //Velocidade de comunicacao (bits por segundo)
  //Inicia a recepcao  
  vw_rx_start();
  Serial.println("Recepcao modulo RF - Aguardando...");
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    if (vw_get_message(buf, &buflen)) 
    {
    int i;
        for (i = 0; i < buflen; i++)
       {            
          //Armazena os caracteres recebidos  
          recebido_RF_char[i] = char(buf[i]);
       }
       recebido_RF_char[buflen] = '\0';
       
       //recebido_RF_char  Variavel recebida
         
       Serial.print("Recebido: ");
       Serial.println(recebido_RF_char);
    }
}
