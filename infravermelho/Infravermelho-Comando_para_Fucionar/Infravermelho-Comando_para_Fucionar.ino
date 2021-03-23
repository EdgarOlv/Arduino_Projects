//liga led vermelho    
   if ((codigo_recebido.value == 0x39C6D02F) || (codigo_recebido.value == 0xFF7A85)){// verifica se foi pressionado o numero 3 dos controles    
   digitalWrite(ledvermelho, HIGH);   
   delay(500);    
