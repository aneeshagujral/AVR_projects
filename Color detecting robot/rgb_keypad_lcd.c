/*
 * keypad.c
 *
 * Created: 6/8/2016 12:17:58 PM
 *  Author: Aneesha
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define lcd PORTD
#define rs 0
#define rw 1
#define en 2
void lcd_init();
void lcd_data(char);
void lcd_cmd(char);
void lcd_str(char *p);

int main(void)
{
   DDRB=0xff;
   DDRC=0xff;
   DDRA=0x00;
   PORTA=0xff;
   DDRD=0xff;
	char *p;
	
	int i;
	lcd_init();
	lcd_cmd(0xc0);
   while(1)
   {	char *p;
	   PORTC=0b00000111;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   lcd_cmd(0x80);
		   p="green";
		   PORTB=0x01;
		   lcd_str(p);
	   }
	   if((PINA&0b00000010)==0)
	   {
		   lcd_cmd(0x80);
		   p="blue";
		   PORTB=0x02;	
		   lcd_str(p);
	   }
	   if((PINA&0b00000100)==0)
	   {
		   lcd_cmd(0x80);
		   p="light blue";
		   PORTB=0x03;
		   lcd_str(p);
	   }
	   if((PINA&0b00001000)==0)
	   {
		   lcd_cmd(0x80);
		   p="red";
		   PORTB=0x08;
		   lcd_str(p);
	   }
	   PORTC=0b00001011;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   lcd_cmd(0x80);
		   p="orange";
		   PORTB=0x09;
		   lcd_str(p);
	   }
	   if((PINA&0b00000010)==0)
	   {
		   lcd_cmd(0x80);
		   p="pink";
		   PORTB=0x0A;	
		   lcd_str(p);
	   }
	   if((PINA&0b00000100)==0)
	   {
		   lcd_cmd(0x80);
		   p="white";
		   PORTB=0x0B;
		   lcd_str(p);
	   }
	   if((PINA&0b00001000)==0)
	   {
		   lcd_cmd(0x01);
		   PORTB=0x07;
	   }		
	   PORTC=0b00001101;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   PORTB=0x08;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   PORTB=0x09;	
	   }
	   if((PINA&0b00000100)==0)
	   {
		   PORTB=0x0A;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   PORTB=0x0B;
	   }			  
	  /* PORTC=0b00001110;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   PORTB=0x0C;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   PORTB=0x0D;	
	   }
	   if((PINA&0b00000100)==0)
	   {
		   PORTB=0x0E;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   PORTB=0x0F;
	   } */	   
   }
}

void lcd_init()
{
	lcd_cmd(0x01);
	lcd_cmd(0x02);
	lcd_cmd(0x06);
	lcd_cmd(0x0c);
	lcd_cmd(0x28);
}
void lcd_cmd(char z)
{
	lcd=z&(0xf0);
	lcd&=~(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<en);
	_delay_ms(1);
	lcd&=~(1<<en);
	
	lcd=(z<<4)&(0xf0);
	lcd&=~(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<en);
	_delay_ms(1);
	lcd&=~(1<<en);
}
void lcd_data(char z)
{
	lcd=z&(0xf0);
	lcd|=(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<en);
	_delay_ms(1);
	lcd&=~(1<<en);
	
	lcd=(z<<4)&(0xf0);
	lcd|=(1<<rs);
	lcd&=~(1<<rw);
	lcd|=(1<<en);
	_delay_ms(1);
	lcd&=~(1<<en);
}
void lcd_str(char *str)
{
	int i;
	while(str[i]!=0)
	{
		
		lcd_data(str[i]);
		i++;
	}
}