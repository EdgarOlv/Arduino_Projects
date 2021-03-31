#define A 8

void setup () {

  pinMode (A, OUTPUT);
}

void loop () {
  Serial.begin(9600);
  digitalWrite A, HIGH);
  delay (1000);
  digitalWrite (A, LOW);
  delay (1000);
}
