int motorAPin_A = 8; //Arduino digital 8 is connected to HG7881's A-1A terminal
int motorAPin_B = 9; //Arduino digital 9 is connected to HG7881's A-1B terminal


void setup(){
  /**
   * When program starts set Arduino pinmode for 8 and 9 digital to be OUTPUT
   * so we can use analogWrite to output values from 0 to 255 (0-5V) (PWM) 
   */
  pinMode(motorAPin_A, OUTPUT); //direction
  pinMode(motorAPin_B, OUTPUT); //speed
}

void loop() {
  //set motor direction to "X"
  analogWrite(motorAPin_A, LOW);
  
  //start motor and increase speed while spinnning to direction "X"
  for(int i=0; i<=255; i++){
    //motor speed increases while we loop trough 
    //values from 0 to 255 (0V to power supply max voltage)
    analogWrite(motorAPin_B, i);
    delay(40);
  }
   
  //wait 3 seconds while motor is running full speed
  delay( 3000 );
  
  //take 1 second pause, cutting power from motor ( speed pint to 0V )
  //so motor can stop (maybe your motor needs more time to spin down)
  analogWrite(motorAPin_A, LOW);
  analogWrite(motorAPin_B, LOW);
  delay(1000);
  
  
  //now we switch direction to "Y" by setting 5V to 
  //direction pin A-1A
  analogWrite(motorAPin_A, 255);
  

  //start motor and increase speed while spinnning to direction "Y"
  for(int i=0; i<=255; i++){
    //To speed up like we did in direction "X" this module needs 
    //inverting of value we set on speed pin. 
    //So we go trough loop like before, but this time speed value 
    //decreases from 255 to 0 (via inverting value)
    analogWrite(motorAPin_B, invertOurValue( i ) );
    delay(40);
  }
  
  //wait 3 seconds while motor is running full speed
  delay( 3000 );
  
  //take 1 second pause, cutting power from motor ( speed pint to 0V )
  analogWrite(motorAPin_A, LOW);
  analogWrite(motorAPin_B, LOW);
  delay(1000);
  
  //and now back to top
}
int invertOurValue(int input) {
  return 255 - input;
}
