//Programa: Sensor de velocidade Arduino LM393
//Autor: Arduino e Cia

//Pino ligado ao pino D0 do sensor
int pino_D0 = 2;
int rpm;
volatile byte pulsos;
unsigned long timeold;

//Altere o numero abaixo de acordo com o seu disco encoder
unsigned int pulsos_por_volta = 20;

void contador()
{
  //Incrementa contador
  pulsos++;
}

void setup()
{
  Serial.begin(9600);
  //Pino do sensor como entrada
  pinMode(pino_D0, INPUT);
  //Interrupcao 0 - pino digital 2
  //Aciona o contador a cada pulso
  attachInterrupt(0, contador, FALLING);
  pulsos = 0;
  rpm = 0;
  timeold = 0;
}

void loop()
{
  //Atualiza contador a cada segundo
  if (millis() - timeold >= 300)
  {
    //Desabilita interrupcao durante o calculo
    detachInterrupt(0);
    rpm = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;

    //Mostra o valor de RPM no serial monitor
    Serial.print("RPM = ");
    Serial.println(rpm, DEC);
    //Habilita interrupcao
    attachInterrupt(0, contador, FALLING);
  }
}
