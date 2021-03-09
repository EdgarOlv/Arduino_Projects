 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Escolhe onde posicionar->  lcd.setCursor(0, 0);

LiquidCrystal_I2C lcd(0x3f,16,2);  // Criando um LCD de 16x2 no endereço 0x20

void setup()
{
  lcd.init();                 // Inicializando o LCD
  lcd.backlight();            // Ligando o BackLight do LCD

}

void loop()
{
 int temp=1;

lcd.setCursor(7, 0); //Posiciona o cursor na décima quarta coluna(13) e na segunda linha(1) do LCD

for(int a=0;a<20;a++){
   lcd.setCursor(7, 0);
  lcd.print(a);
  delay(400);
  lcd.clear();
  temp=a;
 
  lcd.setCursor(7, 1);
  lcd.print(temp); //...zera a variável de contagem
  
}



}
