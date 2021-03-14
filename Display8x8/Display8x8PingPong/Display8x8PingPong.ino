/* =============================================================================================================
    
   
   WR Kits Channel & Usina Info número 040


   Jogo de Ping Pong com Arduino e Matriz de LED

   Baseado em projeto do livre "Arduino Básico", do Michael McRoberts
    
   Autor: Eng. Wagner Rambo  Data: Junho de 2017
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits


   Hardware

   DIN  -> Arduino Digital 2
   CS   -> Arduino Digital 3
   CLK  -> Arduino Digital 4
   
   
============================================================================================================= */


// =============================================================================================================
// --- Bibliotecas Auxiliares ---
#include "LedControl.h"                          //inclui biblioteca para controle da matriz com MAX7219


LedControl myMatrix = LedControl(12, 11, 10, 1);    //cria uma instância de uma matriz


// =============================================================================================================
// --- Variáveis Globais ---
int column = 1, row = random(8)+1;               //decide em que ponto a bola deve começar
int directionX = 1, directionY = 1;              //certifica-se de que ela vai primeiro da esquerda para a direita
int paddle1 = 5, paddle1Val;                     //pino e valor do potenciômetro
int velocidade = 300;
int counter = 0, mult = 10;


// =============================================================================================================
// --- Configurações Iniciais ---
void setup()
{

    myMatrix.shutdown(0, false);                 //habilita o display
    myMatrix.setIntensity(0, 8);                 //define o brilho como médio
    myMatrix.clearDisplay(0);                    //limpa o display
    randomSeed(analogRead(0));                   //cria uma semente genuinamente aleatória
  
  
} //end setup


// =============================================================================================================
// --- Loop Infinito ---
void loop()
{

    paddle1Val = analogRead(paddle1);
    paddle1Val = map(paddle1Val, 200, 1024, 1, 6);
    column += directionX;
    row += directionY;

    if(column == 6 && directionX == 1 && (paddle1Val == row || paddle1Val+1 == row || paddle1Val+2 == row)) directionX = -1;

    if(column == 0 && directionX == -1) directionX = 1;

    if(row == 7 && directionY == 1 ) directionY = -1;

    if(row == 0 && directionY == -1) directionY = 1;

    if(column == 7) oops();

//|||||||||||||||||||||||||||||||||||||||||||||||
    myMatrix.clearDisplay(0);                    //limpa tela para próxima quadro de animação
    myMatrix.setLed(0, column, row, HIGH);
    myMatrix.setLed(0, 7, paddle1Val, HIGH);
    myMatrix.setLed(0, 7, paddle1Val+1, HIGH);
    myMatrix.setLed(0, 7, paddle1Val+2, HIGH);

    if(!(counter % mult)) {velocidade -= 5; mult*mult;}
    delay(velocidade);

    counter++;
  
  
} //end loop


void oops()
{
  for(int x=0; x<3; x++)
  {
    myMatrix.clearDisplay(0);
    delay(250);
       for(int y=0; y<8; y++)
       {
          myMatrix.setRow(0, y, 255); 
        
       }

       delay(250);
    
  } //end for

  counter = 0;  //reinicia todos os valores
  velocidade = 300;
  column = 1;
  row = random(8)+1;
  
  
} //end oops

