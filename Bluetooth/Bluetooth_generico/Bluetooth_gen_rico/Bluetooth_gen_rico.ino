
//SoftSerial bluetooth(10, 11)   Biblioteca serve 
//10 vira RX e 11 vira TX
SoftwareSerial bluetooth(1, 2)

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

}

void loop() {
  if(bluetooth.avaliabre())
    Serial.write(bluetooth.read());
  if(Serial.avaliable())
    bluetooth.write(Serial.read());
}
