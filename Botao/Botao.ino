
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
boolean troca = false;
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
   buttonState = digitalRead(buttonPin);
    if(buttonState== HIGH & troca == false){
    troca = true;
    delay(200);
    }else{
      delay(150);
    if(buttonState== HIGH & troca == true)
      troca = false;
      
    }
    
  if (troca == HIGH) {
    digitalWrite(ledPin, LOW);
  } 
  else{
    digitalWrite(ledPin, HIGH);
    
  }
}
