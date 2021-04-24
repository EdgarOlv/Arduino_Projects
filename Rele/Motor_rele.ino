//Programa : Teste Modulo Rele Arduino 2 canais - Lampadas
//Autor : FILIPEFLOP

//Porta ligada ao pino IN1 do modulo
int motor_rele1 = 7;
//Porta ligada ao pino IN2 do modulo
int motor_rele2 = 8;
 
void setup()
{
  //Define pinos para o rele como saida
  pinMode(motor_rele1, OUTPUT); 
  pinMode(motor_rele2, OUTPUT);
}
  
void loop()
{
  digitalWrite(motor_rele1, LOW);  //Liga rele 1   (frente)
  digitalWrite(motor_rele2, LOW);  //Liga rele 2
  delay(2000);
  digitalWrite(motor_rele1, HIGH);  //desliga rele 1  (desliga)
  digitalWrite(motor_rele2, HIGH);  //desliga rele 2
  delay(1000);
  digitalWrite(motor_rele1, HIGH); //Desliga rele 1  (esquerda)
  digitalWrite(motor_rele2, LOW);  //Liga rele 2
  delay(500);
  digitalWrite(motor_rele1, LOW);  //Liga rele 1   (frente)
  digitalWrite(motor_rele2, LOW);  //Liga rele 2
  delay(1000);
  digitalWrite(motor_rele1, HIGH);  //desliga rele 1  (desliga)
  digitalWrite(motor_rele2, HIGH);  //desliga rele 2
  delay(1000);
  digitalWrite(motor_rele1, LOW);  //Liga rele 1   (Direita)
  digitalWrite(motor_rele2, HIGH); //Desiga rele 2
  delay(500);
  digitalWrite(motor_rele1, LOW);  //Liga rele 1   (frente)
  digitalWrite(motor_rele2, LOW);  //Liga rele 2
  delay(1000);
  digitalWrite(motor_rele1, HIGH);  //desliga rele 1  (desliga)
  digitalWrite(motor_rele2, HIGH);  //desliga rele 2
  delay(1000);
  digitalWrite(motor_rele1, LOW);  //Liga rele 1   (Direita)
  digitalWrite(motor_rele2, HIGH); //Desiga rele 2
  delay(2000);
}
