
#include <IRremote.h>

// Pino utilizado para fazer a leitura dos valores dos botÃµes...
//do controle remoto.
int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;  // Decodifica os dados do controle remoto.

void setup()

{

  Serial.begin(9600);  // Inicia o Serial Monitor.

  irrecv.enableIRIn(); // Inicia o infrared receptor.

}

void loop() {

  if (irrecv.decode(&results)) {

    // Imprime na tela do Serial Monitor o valor dos botÃµes do controle...
    //remoto em hexatecimal.
    Serial.println(results.value, HEX);

    // Aguarda para receber o novo valor quando for pressionado um...
    //outro botÃ£o.
    irrecv.resume();

  }

  delay(500);  // DÃ¡ um tempo de 100 ms entre um valor e outro.

}
