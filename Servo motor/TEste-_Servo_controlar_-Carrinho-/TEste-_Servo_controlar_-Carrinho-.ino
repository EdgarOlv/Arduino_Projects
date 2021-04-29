#include <Servo.h>
Servo servomotorD;
Servo servomotorE

void setup() {
  ServomotorD.attach(5);
  delay(100);
  servomotorE.attach(6);
}

void loop() {
  giraRodaDireitaFrente();
  servomotorE.write(0);
  delay(2000);
  }
  void giraRodaDireitaFrente(){
    servomotorD.write(180);
  }
  void giraRodaEsquerdaFrente(){
    servomotorE.write(0);
  }

