#include span style="color: #cc6600;">Servo.h>


Servo motor;                           



 void setup()

{

   motor.attach(3); 

}

void loop () 

{ 

  motor.write(45); 

  delay(1000); 

  motor.write(125); 

  delay(1000); 

}
