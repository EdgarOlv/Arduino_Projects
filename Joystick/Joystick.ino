
 int x_key = A0;
 int y_key = A1;
 int x_pos;
 int y_pos;

void setup() {
  Serial.begin(9600);
  pinMode(x_key, INPUT);
  pinMode(y_key, INPUT);

}

void loop() {
  x_pos = analogRead ( x_key);
  y_pos = analogRead ( y_key);
  Serial.print("X: ");
  Serial.println(x_pos);
  Serial.print("Y: ");
  Serial.println(y_pos);
  Serial.println(" ");
  delay(100);

}
