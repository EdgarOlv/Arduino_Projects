int seg=0, min=0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  static unsigned long ult_tempo = 0;
  unsigned tempo = millis();
  if((tempo - ult_tempo) >= 1000){
    ult_tempo = tempo;
    seg++;
  }
  if(seg >= 60){
    seg =0;
    min++;
  };
Serial.print("Tempo: ");
Serial.print(min);
Serial.print(" : ");
Serial.print(seg);
//Serial.print(" : ");
//Serial.println(millis());

}
