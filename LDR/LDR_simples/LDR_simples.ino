
int ldr = 0; 
int ldrValor = 0; //Valor lido do LDR

void setup() 
{
 Serial.begin(9600);
}

void loop() 
{
   ///ler o valor do LDR
   ldrValor = analogRead(ldr); //O valor lido será entre 0 e 1023
   Serial.println(ldrValor);
   delay(100);

}
