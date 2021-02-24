//Projeto: Como usar o buzzer (som) no arduíno    
//  ---------------------------------------------------------------------------------------------------  
    
  int BUZZER = 6; // Ligar o buzzer (Som) no pino 10   
  // Executado na inicialização do Arduino   
  void setup(){   
  pinMode(BUZZER,OUTPUT); // define o pino do buzzer como saída.   
  }   
  // Loop pincipal do Arduino   
  void loop(){   
  tone(6,200,300); //aqui sai o som   
  /*   
   o número 10 indica que o pino positivo do buzzer está na porta 10   
   o número 300 é a frequência que será tocado   
   o número 300 é a duração do som   
  */    
  delay(500);    
  tone(6,200,300); //aqui sai o som   
  delay(500);   
  tone(6,500,300); //aqui sai o som   
  delay(500);   
  }   
