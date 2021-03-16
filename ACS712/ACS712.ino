#include "ACS712.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Estou usando ACS de 30A. Mude para o modelo que está usando. Valores possíveis: 5,20 e 30
// Sensor ligado na porta analópgica A0
ACS712 sensor(ACS712_20A, A0);

//Porta SDA - A4
//Porta SCL - A5
//Escolhe onde posicionar->  lcd.setCursor(0, 0);

LiquidCrystal_I2C lcd(0x3f, 16, 2); 

void setup() {
  // É necessário calibrar o sensor antes de usar a primeira vez com o método abaixo
  Serial.begin(9600);
  lcd.init();                
  lcd.backlight();           

  Serial.println("Aguarde. Calibrando..."); 
  lcd.print("Aguarde.");
  lcd.setCursor(0,1);
  lcd.print("Calibrando...");
  delay(1000);
  sensor.calibrate();
  
  lcd.clear();
  Serial.println("Fim da calibração");
  lcd.print("Calibrado");
  delay(500);
  lcd.clear();
}
 
void loop() {
  // A frequência da corrente alternada no Brasil é 60 Hz. Mude caso necessário
  // A voltagem, no meu caso é 127
  
  
  float V = 220;
  float I = sensor.getCurrentAC(60);
  float P = V * I;
 
  Serial.println(String("Tensão = ") + V + " V");
  Serial.println(String("Corrente = ") + I + " A");
  Serial.println(String("Potência  = ") + P + " Watts");
  
  lcd.print(String("Corrente = ") + I + " A");
  lcd.setCursor(0,1);
  lcd.print(String("Potencia = ") + P + " Watts");
  delay(5000);
  lcd.clear();
  V=0;
  I=0;
  P=0;
  
}
