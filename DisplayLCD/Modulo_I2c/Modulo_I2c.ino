
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Porta SDA - A4
//Porta SCL - A5
//Escolhe onde posicionar->  lcd.setCursor(0, 0);

LiquidCrystal_I2C lcda(0x3f, 16, 2); // Criando um LCD de 16x2 no endereço 0x20
LiquidCrystal_I2C lcdb(0x3B, 16, 4);

void setup()
{
  lcda.init();                 // Inicializando o LCD
  lcda.backlight();            // Ligando o BackLight do LCD
  lcda.print("Funcionando!!!");

  
  lcdb.init();                 // Inicializando o LCD
  lcdb.backlight();            // Ligando o BackLight do LCD
  lcdb.print("Funcionando!!!");
  
}

void loop()
{

}
