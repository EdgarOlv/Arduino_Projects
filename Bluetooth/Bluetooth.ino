
int led1 =2;
char buf;


void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);

}

void loop() {
  
 while(Serial.available() >0)
 {
   buf = Serial.read ();
   if (buf == 'A')
   {
     digitalWrite(13, HIGH);
     Serial.println("Porta 2 Ligado/Desligada!");
     delay(1000);
     digitalWrite(13,LOW);
     delay(1000);
    }
    
 }


}
