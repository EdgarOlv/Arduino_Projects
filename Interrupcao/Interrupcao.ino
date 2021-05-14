//Créditos: diwo.bq.com

int interrupcao = 1;

// Interrupt.0 encontra-se no pino digital 2 
// Interrupt.1 encontra-se no pino digital 3
 
/*  Criamos a variável do tipo <em>volatile</em> 
  para assegurar que a variável estará acessível a partir
  do fluxo normal do programa e a partir da interrupção.
*/
 
volatile int numInterrupt = 0;
 
void setup() {
 
  Serial.begin(9600);
  
  // Sintaxe das interrupções:
  // attachInterrupt(numero_interrupt,funcao_a_executar,modo);
  // Modos LOW,CHANGE,RISING,FALLING
  /*
  LOW: executa-se sempre que o valor no pino seja 0.
  CHANGE: executa-se sempre que se produza uma alteração.
  RISING: executa-se enquanto o valor vá de 0 até 1 (ou de 0 até 5 Volts).
  FALLING: executa-se enquanto o valor vá de 1 a 0 (ou de 5 até 0 Volts).
 */
  
  attachInterrupt(interrupcao, funcionInterrupcao, CHANGE);
  //delay() e millis() não funciona dentro da interrupção
}
 
void loop() {
  
  /*Simulamos uma tarefa que necessite de algum tempo.
  Utilizamos <em>while(true)</em> porque assim vai-se cumprir sempre a
  condição e nunca deixará de executar o código incluído.
  */
  while(true){
      Serial.print(".");
      delay(300);
  }  
}
 
void funcionInterrupcao() {
  Serial.print("Interrupção número ");
  Serial.println(numInterrupt);
  numInterrupt++; // Aumentamos o número armazenado em <em>numInterrupt</em> em uma unidade.
}
