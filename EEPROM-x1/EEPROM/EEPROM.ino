#include <EEPROM.h>
void setup()
{
   Serial.begin(9600);//Inicia a comunicação Serial.
   Serial.println();//-
   Serial.println();//-Apenas para "limpar" a tela.
   EEPROM.begin(4);//Inicia a EEPROM com tamanho de 4 Bytes (minimo).
   Serial.println(EEPROM.read(0));//Mostra no Monitor oque há antes de efetuar a gravação
   if (EEPROM.read(0) != 18)//Se não existir o numero escolhido (18), irá gravar. Isto é necessário para evitar regravações desnecessárias.
   {
      EEPROM.write(0, 18);//Escreve no endereço "0", o valor "18".
      EEPROM.commit();//Salva o dado na EEPROM.
      Serial.println(EEPROM.read(0));//Mostra o valor no endereço 0 novamente.
   }
   else//Se já existir o valor, irá avisar.
   {
      Serial.println("Dado ja cadastrado");
   }
   EEPROM.end();//Fecha a EEPROM.
}
void loop()
{
}
