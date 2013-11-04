# include <avr/io.h>                                            
# include <util/delay.h>
#include "driver.h"
# include "gametools.h"   
                                 // plastic cap to the right side. (instead of the top)
char bottom=0;                   // modGraphic == goLeft
char collision=0;                // pullUp == goRight
char lineDeleteComplete=0;       // rightShift == goDown
char x1pos = 0;                  // leftShift == goUp
char x2pos = 0;                  // pullDown == slideLeft
char y1pos = 0;
char y2pos = 0;
char y1point = 0;
char y2point = 0;
char score = 0;
char level = 1;
char randomShape = 1;
unsigned char mainArray[5][60];
unsigned char gameSetup[5][60];
unsigned char blockFall[5][60];

main ()
{
 initGame();
 while(1)
 {
  playGame();
 }
}

void initGame (void)
{
 initlcd(0XC0);
 initArray();
}

void initArray (void)
{
 setPosition (20,5);
 writeChar('G');
 setPosition (20,4);
 writeChar('A');
 setPosition (20,3);
 writeChar('M');
 setPosition (20,2);
 writeChar('E');
 setPosition (62,5);
 writeChar('P');
 setPosition (62,4);
 writeChar('N');
 setPosition (62,3);
 writeChar('T');
 setPosition(62, 2);
 writeChar(score);
 setPosition (72,5);
 writeChar('L');
 setPosition (72,4);
 writeChar('X');
 setPosition(72, 3);
 writeChar(level);
 _delay_ms(2000);
 unsigned char i,j;
 for (j=0; j<60; j++)
 {
  for (i=0; i<5; i++)
  {
   mainArray[i][j] = 0;
   gameSetup[i][j] = 0;
   blockFall[i][j] = 0;
  }
 }
 for(i=1; i<6; i++) 
 {
  setPosition(60, i);
  write(0xff);
 }
}

void playGame(void)
{
 lineCompleteDetect();
 getRandom();
 while(1)
 {
  playBlock();
  if (bottom>0)
  {
   arrayEquate();
   break;
  }
  if (collision>0)
  {
   goUp();
   arrayOr();
   arrayEquate();
   break;
  }
 }
}



 
 
