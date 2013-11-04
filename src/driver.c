#include "driver.h"


void initlcd(unsigned char contrast)
{
  DDRB = 0B11111111;
  SPCR = 0B01010000; // initialize SPI in master mode 
  reset();          // resetting LCD before start
  PORTB = 0B00000010; // sending data in command mode
  write(0B00100001);  // choosing vertical or horizontal write
  write(contrast);  // setting contrast
  write(0B00100000);  //some random other two things.
  write(0B00001100);
  PORTB |= 0B00000001;  // shifting from command to data mode
  clear();
  DDRC = 0B00000000;
  PORTC = 0B00001111;
}


void write(unsigned char byte)
{
		
SPDR = byte;	// assigning the value to be wridden to Serial Pheriferal data register.
while(!(SPSR & (1<<SPIF))); 
}


void reset(void)
{
  PORTB = 0B00000111;  // clock inactive and command mode on
  PORTB &= 0B11111101;  // bit 1 is controlling reset which is active low. here reset is activated.
  _delay_ms(100);
  PORTB |= 0b00000010;  // reset is deactivated.
  _delay_ms(100);
  PORTB = 0b00000011;  // clock active and data mode on
}


void clear (void)
{
  for ( int i =0; i <698; i++)
  {
    //setPosition (0,0);
    write(0x00);    // writing all zeros to the data display ram. lcd should be set in data mode before call.
  }
 }
 
 
 
  void setPosition( unsigned char x, unsigned char y)
 {
   if ( x <84 && y <6)
   {
   PORTB &= 0B11111110;
   y |= 0B01000000;
   x |= 0B10000000;
   write(0B00100000);
   write(y);
   write(x);
   PORTB |= 0B00000001;
   }
 }
 
void writeChar (unsigned char ch)
{
   switch (ch)
   {
    case 'G' :
	write(0x3C);  write(0x3C);  write(0xC3);  write(0xC0);  write(0xCE); write(0XC2);  write(0X3E); write(0X3E);
	break;
	
	case 'A' :
	write(0x3C);  write(0x3C);  write(0xC3);  write(0xC3);  write(0xFF); write(0xFF);  write(0xC3);  write(0xC3); 
	break; 
	
	case 'M' :
	write(0xC3);  write(0xE7);  write(0xE7);  write(0xDB);  write(0xDB); write(0xC3);  write(0xC3);  write(0xC3); 
	break;
	
	case 'E' :
	write(0xFF);  write(0xFF);  write(0xC0);  write(0xFF);  write(0xFF); write(0xC0);  write(0xFF);  write(0xFF); 
	break;
	
	case 'O' :
	write(0x3C);  write(0x3C);  write(0xC3);  write(0xC3);  write(0xC3); write(0xC3);  write(0x3C);  write(0x3C); 
	break;
	
	case 'V' :
    write(0xC3);  write(0xC3);  write(0xC3);  write(0xC3);  write(0xC3); write(0xC3);  write(0x66);  write(0x18); 
	break;
	
	case 'R' :
    write(0x7C);  write(0xC2);  write(0xC2);  write(0xFE);  write(0xD0); write(0xC8);  write(0xC4);  write(0xC2); 
	break;
	
	case 'P' :
	write(0x00);  write(0x00);  write(0xf7);  write(0x94);  write(0x94); write(0Xf4);  write(0X84); write(0X87);
	break;
	
	case 'N' :
	write(0x30);  write(0x00);  write(0xb4);  write(0xb6);  write(0xb5); write(0Xb4);  write(0Xb4); write(0Xb4);
	break;
	
	case 'T' :
	write(0x00);  write(0x00);  write(0x7e);  write(0x49);  write(0x48); write(0Xc9);  write(0Xc8); write(0X48);
	break;
	
	case 0 :
	write(0x00);  write(0x3c);  write(0x24);  write(0x24);  write(0x24); write(0X24);  write(0X3c); write(0X00);
	break;
	
	case 1 :
	write(0x00);  write(0x00);  write(0x10);  write(0x30);  write(0x10); write(0X10);  write(0X10); write(0X38);
	break;
	
	case 2 :
	write(0x00);  write(0x00);  write(0x18);  write(0x24);  write(0x04); write(0X08);  write(0X10); write(0X3c);
	break;
	
	case 3 :
	write(0x00);  write(0x00);  write(0x1f);  write(0x02);  write(0x06); write(0X01);  write(0X01); write(0X1e);
	break;
	
	case 4 :
	write(0x00);  write(0x02);  write(0x04);  write(0x08);  write(0x14); write(0X3f);  write(0X04); write(0X04);
	break;
	
	case 5 :
	write(0x00);  write(0x3f);  write(0x20);  write(0x20);  write(0x1e); write(0X01);  write(0X01); write(0X1e);
	break;
	
	case 'L' :
	write(0x00);  write(0x80);  write(0x90);  write(0x90);  write(0x88); write(0X85);  write(0Xf2); write(0X00);
	break;
	
	case 'X' :
	write(0x00);  write(0x10);  write(0x51);  write(0x50);  write(0x91); write(0X10);  write(0X1e); write(0X00);
	break;
	
	case 'w' :
	write(0x82);  write(0x82);  write(0x92);  write(0x92);  write(0x54); write(0X54);  write(0X38); write(0X00);
	break;
	
	case 'i' :
	write(0x50);  write(0x58);  write(0x54);  write(0x52);  write(0x51); write(0X50);  write(0X50); write(0X00);
	break;
	
	case 'n' :
	write(0x55);  write(0x55);  write(0x55);  write(0x55);  write(0x55); write(0xd5);  write(0x40); write(0x15);  
	break;
	
	case ' ' :
    write(0x00);  write(0x00);  write(0x00);  write(0x00);  write(0x00); write(0x00);  write(0x00);  write(0x00);
	break;
   }
}

void writeString( const unsigned char *string )
{
    while ( *string )
    writeChar( *string++ );
}
