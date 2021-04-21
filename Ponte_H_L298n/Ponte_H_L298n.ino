
//Autor : FILIPEFLOP
 
//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 2;
int IN2 = 4;
int IN3 = 6;
int IN4 = 7;
 
void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
}
 
void loop()
{
 
 //Gira o Motor A no sentido anti-horario
 digitalWrite(IN1, 100);
 digitalWrite(IN2, LOW);
 //Gira o Motor B no sentido anti-horario
 digitalWrite(IN3, 100);
 digitalWrite(IN4, LOW);
 delay(2000);
 //Para o motor A
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 //Para o motor B
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
 delay(500);
}
