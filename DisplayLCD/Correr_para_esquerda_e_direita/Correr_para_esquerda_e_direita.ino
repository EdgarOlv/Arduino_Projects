 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Escolhe onde posicionar->  lcd.setCursor(0, 0);

LiquidCrystal_I2C lcd(0x3f,16,2);  // Criando um LCD de 16x2 no endereço 0x20

void setup()
{
  lcd.init();                 // Inicializando o LCD
  lcd.backlight();            // Ligando o BackLight do LCD

  lcd.print(" Funcionando!!!");
    for (int i = 0; i < 14; i++) {
    lcd.scrollDisplayLeft();
    delay(600);
  }
  for (int i = 0; i < 20; i++) {
    lcd.scrollDisplayRight();
    delay(600);
  }
}

void loop()
{
 
}
