#ifndef _GTOOL_H_
#define _GTOOL_H_

#include <avr/io.h>
#include <util/delay.h>

void getRandom(void);
void playBlock(void);
void goLeft (void);
void goRight (void);
void slideLeft (void);
void slideRight (void);
void goDown(void);
void goUp (void);
void collisionDetect(void);
void bottomReachDetect (void);
void blockTurn (void);
void arrayOr(void);
void lcdWrite (void);
void arrayEquate(void);
void gameOver (void);
void lineCompleteDetect(void);
void lineDelete(unsigned char k);
void youWin(void);

#endif
