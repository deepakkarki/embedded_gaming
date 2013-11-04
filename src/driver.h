
#ifndef _DRIVER_H_
#define _DRIVER_H_


#include <avr/io.h>
#include <util/delay.h>


void initlcd(unsigned char contrast);
//initialize the lcd screen
//includes SPI settings and lcd mode settings too (cmd mode and data mode)
void write(unsigned char byte);
//writing one byte to the spi port of the microcontroller
void reset(void);
//reset the lcd screen, clear all data held in it
void clear (void);
//blank the lcd screen in cmd mode
void setPosition( unsigned char x, unsigned char y);
//set the cursor to the given x and y position 
void writeChar (unsigned char ch);
//write a char to the screen. eg writeChar('g') will print 'g' on the screen 
void writeString( const unsigned char *string );
//write a complete string to the screen from the cursors starting point. 
 
 
 #endif
 
