//motor A
int IN1 = 2;
int IN2 = 4;
int velocidadeA = 3;

//motor B
int IN3 = 6;
int IN4 = 7;

int velocidadeB = 5;

void setup(){
  //Define os pinos como saída, os pinos de velocidade devem ser PWM
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(velocidadeA, OUTPUT);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(velocidadeB, OUTPUT);
}


void loop()
{
  //Gira o Motor A no sentido HORÁRIO com velocidade 155
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(velocidadeA, 155); // valor PWM de 0 a 255

  delay(2000); // importante: a função delay não para o motor

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  delay(2000);

  //Gira o Motor A no sentido ANTI-HORÁRIO
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); 
  analogWrite(velocidadeA, 155); // valor PWM de 0 a 255

  delay(2000);

  analogWrite(IN1, HIGH); 
  analogWrite(IN2, HIGH); 
  delay(2000); 
}
