/*********************************
Autor: Fernando Krein Pinheiro
Data: 25/01/2012
Linguagem: C (Wiring)
========= IMPORTANTE ===========
O código esta livre para usar,
citar e compartilhar desde que
mantida sua fonte e seu autor.
Obrigado.
********************************/
 
int ledPin = 13;
int inPin = 10;
int valor = 0;
 
void setup()
{
   Serial.begin(9600);
   pinMode(ledPin, OUTPUT);
   pinMode(inPin, INPUT);
}
 
void loop()
{
    valor = digitalRead(inPin);
 
    if (valor == HIGH)
    {
           digitalWrite(ledPin, HIGH);
       Serial.write("Preto");
    } else
         {
               digitalWrite(ledPin, LOW);
           Serial.write("Branco");
        }
}
