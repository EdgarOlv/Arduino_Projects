//Programa : Teste de motor DC12V com motor shield ponte H
//Autor : Equipe FILIPEFLOP

#include <AFMotor.h>

AF_DCMotor motor(1); //Seleciona o motor 1

void setup()
{}

void loop()
{
motor.setSpeed(255); //Define a velocidade maxima
motor.run(FORWARD); //Gira o motor sentido horario

delay(5000);
motor.setSpeed(0);
motor.run(RELEASE); //Desliga o motor

delay(5000);
motor.setSpeed(100); //Define velocidade baixa
motor.run(BACKWARD); //Gira o motor sentido anti-horario

delay(5000);
motor.setSpeed(0);
motor.run(RELEASE); //Desliga o motor

delay(5000); //Aguarda 5 segundos e repete o processo
}
