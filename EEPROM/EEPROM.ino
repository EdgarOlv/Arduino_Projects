
#include <EEPROM.h> // Biblioteca para acesso e manipulação da EEPROM
void setup()   
{
  Serial.begin(9600); // Inicialização da comunicação serial
 
  Serial.print("Espaco Disponivel em Bytes: "); // Mostra a quantidade  de memória da EEPROM do seu microcontrolador
  Serial.println(EEPROM.length()); // Mostra a quantidade de memória da EEPROM do seu microcontrolador
  escreveByte(0,254); // Escreve o valor 255 na posição 0 da memória  
  byte valor = leByte(0); // Lê o endereço 0 da memória ( onde escrevemos 255 )
  Serial.print("Byte Armazenado: "); // Mostra o Byte Armazenado
  Serial.println(valor); // Mostra o Byte Armazenado
  escreveInt(1,2,1200); // Escreve o valor 1200 na EEPROM ( por ser um int de 2 bytes precisamos utilizar 2 endereços para armazenar)
  Serial.print ("Inteiro Armazenado: "); // Mostra o inteiro Armazenado
  Serial.println(lerInt(1,2)); // Mostra o inteiro Armazenado
  escreveString(3,"Edgar Oliveira"); // Escreve a String Vida de Silício na EEPROM, começando no  endereço 3
  Serial.println("String Armazenada: "+leString(3)); // Mostra a String armazenada
}
 
void loop(){
  
}
 
byte leByte (int endereco1){
  return EEPROM.read(endereco1); // Realizamosa leitura de 1 byte  e retornamos
}
 
void escreveByte (int endereco1, byte valor){ // Escreve um byte na EEPROM no endereço especificado
  byte valorAtual = leByte(endereco1); // Lemos o byte que desejamos escrever
  if (valorAtual == valor){ // Se os valores forem iguais não  precisamos escrever ( economia de ciclos de escrita )
    return;
  }
  else { // Senão escrevemos o byte no endereço especificado na função
    EEPROM.write(endereco1,valor); // Escreve o byte no endereço especificado na função
  }
  
}
 
 
 
void escreveInt(int endereco1, int endereco2, int valor){ // Escreve um inteiro de 2 bytes na EEPROM
  int valorAtual = lerInt(endereco1,endereco2); // Lemos o valor inteiro da memória
  if (valorAtual == valor){ // Se o valor lido for igual ao que queremos escrever não é necessário escrever novamente
    return;
  }
  else{ // Caso contrário "quebramos nosso inteiro em 2 bytes e escrevemos cada byte em uma posição da memória
      byte primeiroByte = valor&0xff; //Executamos a operação AND de 255 com todo o valor, o que mantém apenas o primeiro byte
      byte segundoByte = (valor >> 8) &0xff; // Realizamos um deslocamento de 8 bits para a direita e novamente executamos um AND com o valor 255, o que retorna apenas o byte desejado
      EEPROM.write(endereco1,primeiroByte); // Copiamos o primeiro byte para o endereço 1
      EEPROM.write(endereco2,segundoByte); // Copiamos o segundo byte para o endereço 2
  }
}
 
int lerInt(int endereco1, int endereco2){ // Le o int armazenado em dois endereços de memória
  int valor = 0; // Inicializamos nosso retorno
  byte primeiroByte = EEPROM.read(endereco1); // Leitura do primeiro byte armazenado no endereço 1
  byte segundoByte = EEPROM.read(endereco2); // Leitura do segundo byte armazenado no endereço 2
  valor = (segundoByte << 8) + primeiroByte; // Deslocamos o segundo byte 8 vezes para a esquerda ( formando o byte mais significativo ) e realizamos a soma com o primeiro byte ( menos significativo )
  return valor; // Retornamos o valor da leitura
 
}
 
void escreveString(int enderecoBase, String mensagem){ // Salva a string nos endereços de forma sequencial
  if (mensagem.length()>EEPROM.length() || (enderecoBase+mensagem.length()) >EEPROM.length() ){ // verificamos se a string cabe na memória a partir do endereço desejado
    Serial.println ("A sua String não cabe na EEPROM"); // Caso não caiba mensagem de erro é mostrada
  }
  else{ // Caso seja possível armazenar 
    for (int i = 0; i<mensagem.length(); i++){ 
       EEPROM.write(enderecoBase,mensagem[i]); // Escrevemos cada byte da string de forma sequencial na memória
       enderecoBase++; // Deslocamos endereço base em uma posição a cada byte salvo
    }
    EEPROM.write(enderecoBase,'\0'); // Salvamos marcador de fim da string 
  }
}
 
String leString(int enderecoBase){
  String mensagem="";
  if (enderecoBase>EEPROM.length()){ // Se o endereço base for maior que o espaço de endereçamento da EEPROM retornamos uma string vazia
    return mensagem;
  }
  else { // Caso contrário, lemos byte a byte de cada endereço e montamos uma nova String
    char pos;
    do{
      pos = EEPROM.read(enderecoBase); // Leitura do byte com base na posição atual
      enderecoBase++; // A cada leitura incrementamos a posição a ser lida
      mensagem = mensagem + pos; // Montamos string de saídaa
    }
    while (pos != '\0'); // Fazemos isso até encontrar o marcador de fim de string
  }
  return mensagem; // Retorno da mensagem
}
 
