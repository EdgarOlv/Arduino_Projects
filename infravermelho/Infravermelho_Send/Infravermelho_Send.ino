/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

IRsend irsend;

int botaoLiga = 4;
int botaoAumentaVolume = 5;
int botaoDiminueVolume = 6;

void setup()
{
  Serial.begin(9600);
  digitalWrite(botaoLiga, INPUT_PULLUP);
  digitalWrite(botaoAumentaVolume, INPUT_PULLUP);
  digitalWrite(botaoDiminueVolume , INPUT_PULLUP);
  
  Serial.begin(9600);
  
}
  
void loop() {


    if(digitalRead(botaoLiga) == LOW){
       irsend.sendNEC(0x20DF10EF, 32); 
       Serial.println("Ligar / Desligar");
    
    }
    
      if(digitalRead(botaoAumentaVolume) == LOW){
       irsend.sendNEC(0xC1AA09F6, 32); 
       Serial.println("Aumenta Volume");
    
    }
    
     if(digitalRead(botaoDiminueVolume) == LOW){
       irsend.sendNEC(0x20DF40BF, 32); 
       Serial.println("Diminue Volume");
    
    }
      
  
}

