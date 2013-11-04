#include "gametools.h"


void getRandom(void)
{
 bottom = 0;
 collision = 0;
 clearblockFall(); 
 switch(randomShape)
 {
  case 1: 
  blockFall[2][0] = 0B11111111;
  blockFall[2][1] = 0B11111111;
  blockFall[2][2] = 0B11000000;
  blockFall[2][3] = 0B11000000;
  blockFall[2][4] = 0B11000000;
  blockFall[2][5] = 0B11000000;
  blockFall[2][6] = 0B11111111;
  blockFall[2][7] = 0B11111111;
  x1pos = 0;
  x2pos = 7;
  y1pos = 2;
  y2pos = 2;
  y1point = 0;
  y2point = 7;
  randomShape =2;
  break;
  
  case 2:
  blockFall[2][0] = 0B00000000;
  blockFall[2][1] = 0B00000000;
  blockFall[2][2] = 0B11111111;
  blockFall[2][3] = 0B11111111;
  blockFall[2][4] = 0B11111111;
  blockFall[2][5] = 0B11111111;
  blockFall[2][6] = 0B00000000;
  blockFall[2][7] = 0B00000000;
  x1pos = 0;
  x2pos = 7;
  y1pos = 2;
  y2pos = 2;
  y1point = 0;
  y2point = 7;
  randomShape =3;
  break;
  
  case 3:
  blockFall[2][0] = 0B11111111;
  blockFall[2][1] = 0B11111111;
  blockFall[2][2] = 0B11111111;
  blockFall[2][3] = 0B11111111;
  blockFall[2][4] = 0B11111111;
  blockFall[2][5] = 0B11111111;
  blockFall[2][6] = 0B11111111;
  blockFall[2][7] = 0B11111111;
  x1pos = 0;
  x2pos = 7;
  y1pos = 2;
  y2pos = 2;
  y1point = 0;
  y2point = 7;
  randomShape =4;
  break;
  
  case 4:
  blockFall[2][0] = 0B00111100;
  blockFall[2][1] = 0B00111100;
  blockFall[2][2] = 0B00111100;
  blockFall[2][3] = 0B00111100;
  blockFall[2][4] = 0B11111111;
  blockFall[2][5] = 0B11111111;
  blockFall[2][6] = 0B11111111;
  blockFall[2][7] = 0B11111111;
  x1pos = 0;
  x2pos = 7;
  y1pos = 2;
  y2pos = 2;
  y1point = 0;
  y2point = 7;
  randomShape =6;
  break;
  
  case 5: 
  blockFall[2][0] = 0B11000000;
  blockFall[2][1] = 0B11000000;
  blockFall[2][2] = 0B11000000;
  blockFall[2][3] = 0B11000000;
  blockFall[2][4] = 0B11000000;
  blockFall[2][5] = 0B11000000;
  blockFall[2][6] = 0B11111111;
  blockFall[2][7] = 0B11111111;
  x1pos = 0;
  x2pos = 7;
  y1pos = 2;
  y2pos = 2;
  y1point = 0;
  y2point = 7;
  randomShape =6;
  break;
  
  case 6: 
  blockFall[2][0] = 0B00000011;
  blockFall[2][1] = 0B00000011;
  blockFall[2][2] = 0B00000011;
  blockFall[2][3] = 0B00000011;
  blockFall[2][4] = 0B00000011;
  blockFall[2][5] = 0B00000011;
  blockFall[2][6] = 0B00000011;
  blockFall[2][7] = 0B00000011;
  x1pos = 0;
  x2pos = 7;
  y1pos = 2;
  y2pos = 2;
  y1point = 0;
  y2point = 1;
  randomShape =7;
  break;
  
  case 7: 
  blockFall[2][0] = 0B00000000;
  blockFall[2][1] = 0B00000000;
  blockFall[2][2] = 0B00000000;
  blockFall[2][3] = 0B00011000;
  blockFall[2][4] = 0B00011000;
  blockFall[2][5] = 0B00000000;
  blockFall[2][6] = 0B00000000;
  blockFall[2][7] = 0B00000000;
  x1pos = 3;
  x2pos = 4;
  y1pos = 2;
  y2pos = 2;
  y1point = 3;
  y2point = 4;
  randomShape =1;
  break;
 }
}


void clearblockFall (void)
{
 unsigned char i,j;
 for (j=0; j<60; j++)
 {
  for (i=0; i<5; i++)
  {
   blockFall[i][j] = 0;
  }
 }
}


void playBlock(void)
{
 unsigned char a=0;
 collisionDetect();
 if(collision > 0)
 {
  arrayOr();
  lcdWrite();
  gameOver();
 }
 else
 {
 goDown();
 arrayOr();
 collisionDetect();
 bottomReachDetect();
 if( (collision+bottom) == 0)
 {
 a = (PINC&0B00001111);
 if (a == 0B00001110) 
 {
  goLeft();
 }
 if (a == 0B00001101) 
 {
  goRight();
 }
 if (a == 0B00000111) 
 {
  blockTurn();
 }
  if (a== 0B00001011)
 {
  _delay_ms(50);
 }
 else
 {
  switch(level)
  {
  case 1:
  _delay_ms(500);
  break;
  
  case 2:
  _delay_ms(350);
  break;
  
  case 3:
  _delay_ms(250);
  break;
  
  case 4:
  _delay_ms(125);
  break;
  
  case 5:
  _delay_ms(75);
  break;
  }
 }
 }
 if (collision==0)
 {
  lcdWrite();
 }
 }
}


void goLeft (void)
{ 
 unsigned char t;
 for (t=0; t<2; t++)
 {
 if ((y2pos==4) && (y2point==7))
 {}
 else
 {
 unsigned char i,j;
 char m, n;
 for (j=0; j<60; j++)
 { 
 for (i=0; i<5; i++)
 {
  if (i==0) 
  {
   m = (0B10000000)&(blockFall[4][j]); 
   m = m>>7;
  }
   n = (0B10000000)&(blockFall[i][j]); 
   n = n>>7;
   blockFall[i][j] = (blockFall[i][j])<<1;
   blockFall[i][j] |= m;
   m = n;
   }
  }
  collisionDetect();
  if(collision)
  {
   collision =0;
   slideRight();
  }
  else
  {
   y1point +=1;
   y2point +=1;
   if (y1point >7)
   {
    y1pos +=1;
    y1point =0;
   }
  if (y2point >7)
    {
    y2pos +=1;
    y2point =0;
   } 
  }
 }
}
}


void goRight (void)                          
{ unsigned char t;
  for(t=0; t<2; t++)
 {
 if ((y1pos==0) && (y1point==0))
 {
 }
 else
 {
 unsigned char i,j, m, t, fb;
 for (j=0; j<60; j++)
 { 
  fb = (0B000000001)&(blockFall[0][j]); 
  fb = fb<<7;
  for (i=0; i<4; i++)
  {
   m = (0B00000001)&(blockFall[i+1][j]); 
   m = m<<7;
   blockFall[i][j] = (blockFall[i][j])>>1;
   blockFall[i][j] |= m;
  }
  blockFall[4][j] = (blockFall[4][j])>>1;
  blockFall[4][j] |= fb;
 }
 collisionDetect();
 if(collision)
 {
  collision =0;
  slideLeft();
 }
 else
 {
  if (y1point <1)
  {
   y1pos -=1;
   y1point =7;
  }
  else
  {
   y1point -=1;
  }
  if (y2point <1)
  {
   y2pos -=1;
   y2point =7;
  } 
  else
  {
   y2point -=1;
  }
 }
}
}
}


void slideLeft (void)
{ 
 unsigned char i,j;
 char m, n;
 for (j=0; j<60; j++)
 { 
 for (i=0; i<5; i++)
 {
  if (i==0) 
  {
   m = (0B10000000)&(blockFall[4][j]); 
   m = m>>7;
  }
   n = (0B10000000)&(blockFall[i][j]); 
   n = n>>7;
  blockFall[i][j] = (blockFall[i][j])<<1;
  blockFall[i][j] |= m;
  m = n;
  }
 }
}


void slideRight (void)                          
{ 
 unsigned char i,j, m, fb;
 for (j=0; j<60; j++)
 { 
  fb = (0B000000001)&(blockFall[0][j]); 
  fb = fb<<7;
  for (i=0; i<4; i++)
  {
   m = (0B00000001)&(blockFall[i+1][j]); 
   m = m<<7;
   blockFall[i][j] = (blockFall[i][j])>>1;
   blockFall[i][j] |= m;
  }
  blockFall[4][j] = (blockFall[4][j])>>1;
  blockFall[4][j] |= fb;
 }
}


void goDown(void)
 { 
 unsigned char i,j;
 for(j=59; j>0; j--)
 {
  for(i=0; i<5; i++)
  {
   blockFall[i][j] = blockFall[i][j-1];
  if (j==1)
   {
    blockFall[i][0] = 0;
   }
   }
  }
  x1pos +=1;
 x2pos +=1;
 }



void goUp (void)
 { 
 unsigned char i, j;
  for(j=0; j<59; j++)
   {
    for(i=0; i<5; i++)
    {
     blockFall[i][j] = blockFall[i][j+1];
     if (j==58)
     {
      blockFall[i][59] = 0;
     }
    }
  }
  x1pos = x1pos-1;
 x2pos = x2pos-1;
 }



void collisionDetect(void)
{  
 unsigned char i, j, a;
 for(j=0; j<60; j++)
 {
  for(i=0; i<5; i++)
  {
   a = (gameSetup[i][j])&(blockFall[i][j]);
   if (a > 0)
   {
    collision = 1;
   }
  }
 }
}


void bottomReachDetect (void)
{
 unsigned char a,i;
 a = 0; 
 for(i=0; i<5; i++)  
 {
  a |= blockFall[i][59];
 }
 if(a>0)
 {
  bottom = 1;
 }
}


void blockTurn (void)
{
 unsigned char k, b, i, j, shift, array[8];
 for(i=0;i<8; i++) array[i]=0;
 
 for (j=0; j<8; j++)
{
 k = shift =0;
 b = blockFall[y1pos][x1pos+j];
 for (i=0; i<8; i++) 
 {
  if (i < (8-y1point)) 
  { 
   if(b&(1<<(i+y1point)))
   {
    array[k] |= 1;
   }
   if (j != 7) array[k] <<= 1;
  k++;
  }
  else 
  {
   b = blockFall[y2pos][x1pos+j];
   if (b& (1<<shift))
   {
    array[k] |=1;
   }
   if (j != 7) array[k] <<= 1;
   shift++;
   k++;
  }
 }
}                                  
  
 for (j=0; j<60; j++)
 {
  for (i=0; i<5; i++)
  {
   blockFall[i][j] = 0;
  }
 } 
 
 for(j=0; j<8; j++)
 {
  blockFall[y1pos][x1pos+j]= array[j];
 }
 
 for(i=0; i<y1point; i++)
 {
  slideLeft();
 }
 collisionDetect();
 if (collision)
 { 
  collision = 0;
  blockTurn();
 }
} 


void arrayOr(void)
{
 unsigned char i, j;
 for(j=0; j<60; j++)
 {
  for(i=0; i<5; i++)
  {
   mainArray[i][j] = (gameSetup[i][j])|(blockFall[i][j]);
  }
 }
}
 

void lcdWrite (void)
{ 
 unsigned char i,j;      
 for (j=0; j<60; j++)
 {
  for (i=0; i <5; i++)
  {
   char val1 = mainArray[i][j];
   setPosition(j,i+1);
   write(val1);
  }
 }
}



void arrayEquate(void)
{
 unsigned char i, j;
 for(j=0; j<60; j++)
 {
  for(i=0; i<5; i++)
  {
   gameSetup[i][j] = mainArray[i][j];
  }
 }
}


void gameOver (void)
{ 
 clear();
 setPosition (10 , 4);
 writeChar('G');  
 setPosition (10 , 3);
 writeChar('A'); 
 setPosition (10 , 2);
 writeChar('M');
 setPosition (10 , 1);
 writeChar('E');
 setPosition (20 , 4);
 writeChar('O');  
 setPosition (20 , 3);
 writeChar('V');  
 setPosition (20 , 2);
 writeChar('E'); 
 setPosition (20 , 1);
 writeChar('R');
 while (1);
} 

 
 void lineCompleteDetect(void)
{
 unsigned char a, i, j;
  for(j=59; j>1; j--)
  {
   a = 0B11111111;
   for (i=0; i<5; i++)
   {
    a &= gameSetup[i][j]; //[i][59]
   }
   if ( a == 0B11111111)
   {
    lineDelete(j);
    j++;
   }
  } 
}
 
void lineDelete(unsigned char k)
{
 unsigned char i,j;
 for(j=k; j>0; j--)   
 {
  for(i=0; i<5; i++)
  {
   gameSetup[i][j] = gameSetup[i][j-1];
   if (j==1)
   {
    gameSetup[i][0] = 0;
   } 
  }
 }
 score +=1;
 if(score>5)
 {
 level += 1;
 score = 0;
 }
 setPosition(62, 2);
 writeChar(score);
 setPosition(72, 3);
 writeChar(level);
 if (level==5 && score==5)
 {
  youWin();
 }
}


void youWin(void)
{
 
 setPosition (30 , 4);
 writeChar('w');  
 setPosition (30 , 3);
 writeChar('i'); 
 setPosition (30 , 2);
 writeChar('n');
 while(1);
 
}
