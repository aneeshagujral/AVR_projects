/*
 * lcd_move.c
 *
 * Created: 6/1/2016 1:43:59 PM
 *  Author: Aneesha
 */ 
/*
 * lcd_string.c
 *
 * Created: 6/1/2016 12:44:27 PM
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
void calc();
void lcd_num(int x);
void lcd_final();

int main()
{
	DDRD=0xff;
	DDRB=0xff;
   DDRC=0xff;
   DDRA=0x00;
   PORTA=0xff;
   lcd_init();
   calc();

   int q;
	int a;
	int b;
	int c;
	here: while(1) // Taking input from keypad as single digit number
	{
		lcd_cmd(0x82);
		PORTC=0b00000111;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   a=0;
		   lcd_data('0');
		   _delay_ms(10000);
		   goto there;
		   
	   }
	   if((PINA&0b00000010)==0)
	   {
		   a=1;
		   lcd_data('1');
		   _delay_ms(10000);
		   goto there;;
		   
		   
	   }
	   if((PINA&0b00000100)==0)
	   {
		   a=2;
		   lcd_data('2');
		   _delay_ms(10000);
		   goto there;
		   
		   
	   }
	   if((PINA&0b00001000)==0)
	   {
		   a=3;
		  lcd_data('3');
		   _delay_ms(10000);
		   goto there;
		  
		   
	   }
	   PORTC=0b00001011;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   a=4;
		   lcd_data('4');
		   _delay_ms(10000);
		   goto there;
		  
		   
	   }
	   if((PINA&0b00000010)==0)
	   {
		   a=5;
		  lcd_data('5');
		   _delay_ms(10000);
		   goto there;
		  
		   	
	   }
	   if((PINA&0b00000100)==0)
	   {
		   a=6;
		   lcd_data('6');
		   _delay_ms(10000);
		   goto there;
		   
		   
	   }
	   if((PINA&0b00001000)==0)
	   {
		   a=7;
		   lcd_data('7');
		   _delay_ms(10000);
		   goto there;
		  
		   
	   }		
	   PORTC=0b00001101;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   a=8;
		   lcd_data('8');
		   _delay_ms(10000);
		   goto there;
		   
		   
	   }
	   if((PINA&0b00000010)==0)
	   {
		   a=9;
		   lcd_data('9');
		   _delay_ms(10000);
		   goto there;
		   
		   
	   }
	   if((PINA&0b00000100)==0)
	   {
		   goto there;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   goto ok;
	   }	
	   
	    
 
	}	
	
	there: while(1)
	{
		lcd_cmd(0xc2);
		PORTC=0b00000111;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   b=0;
		   lcd_data('0');
		   _delay_ms(10000);
		   goto ok;
		   
		   
	   }
	   if((PINA&0b00000010)==0)
	   {
		   b=1;
		   lcd_data('1');
		   _delay_ms(10000);
		   goto ok;
		  
		   
	   }
	   if((PINA&0b00000100)==0)
	   {
		   b=2;
		   lcd_data('2');
		   _delay_ms(10000);
		   goto ok;
		   
		   
	   }
	   if((PINA&0b00001000)==0)
	   {
		   b=3;
		   lcd_data('3');
		   _delay_ms(10000);
		   goto ok;
		   
		   
	   }
	   PORTC=0b00001011;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   b=4;
		   lcd_data('4');
		   _delay_ms(10000);
		   goto ok;
		  
	   }
	   if((PINA&0b00000010)==0)
	   {
		   b=5;
		   lcd_data('5');
		   _delay_ms(10000);
		   goto ok;
		   
	   }
	   if((PINA&0b00000100)==0)
	   {
		   b=6;
		   lcd_data('6');
		   _delay_ms(10000);
		   goto ok;
		  
	   }
	   if((PINA&0b00001000)==0)
	   {
		   b=7;
		   lcd_data('7');
		   _delay_ms(10000);
		   goto ok;
		  
	   }		
	   PORTC=0b00001101;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   b=8;
		   lcd_data('8');
		   _delay_ms(10000);
		   goto ok;
		  
	   }
	   if((PINA&0b00000010)==0)
	   {
		   b=9;
		   lcd_data('9');
		   _delay_ms(10000);
		   goto ok;
		 
	   }
	   if((PINA&0b00000100)==0)
	   {
		   goto ok;
		   
		   
	   }
	   if((PINA&0b00001000)==0)
	   {
		   goto ok;
	   }	
	   }	
	   ok:
	   while(1)
	   {
		   
	   
	   {
		    PORTC=0b00001110;
	   _delay_ms(100);
	 
	 lcd_cmd(0x89);			// performing basic addition, multiplication, division, and subtraction operation as per input from keypas.
	   if((PINA&0b00000001)==0)
	   {
		   int q;
		   PORTB=0x0f;
		   q=a+b;
		   lcd_num(q);
		   goto here;
		   
	   }
	   if((PINA&0b00000010)==0)
	   {
		   int q;
		   q=a-b;
		   lcd_num(q);
		   goto here;
		   
	   }
	   if((PINA&0b00000100)==0)
	   {
		   int q;
			q=a*b;
			lcd_num(q);
			goto here;
			
	   }
	   if((PINA&0b00001000)==0)
	   {
		   int q;
		   q=a/b;
		   lcd_num(q);
		   goto here;
		   
	   } 	
	  
	   }		     
			
	   }   
	
	return 0;
}
void lcd_num(int x)
{
	

	int a=x/10;
	lcd_data(a+48);

	_delay_ms(100);
	lcd_cmd(0x06);
	int o=x%10;
	lcd_data(o+48);

	_delay_ms(100);
}
void lcd_final(int q)
{
	lcd_cmd(0xc8);
	
	lcd_data(0x04);
	int a=q/10;
	lcd_data(a+48);
	lcd_cmd(0x06);
	
	_delay_ms(100);
	
	int o=q%10;
	lcd_data(o+48);
	lcd_cmd(0x06);
	
	_delay_ms(100);
}

void calc()
{
	
	char *p;
	char *g;
	char *r;
	lcd_cmd(0x80);
	p="a=";
	lcd_str(p);
	lcd_cmd(0x06);
	
	lcd_cmd(0xc0);
	g="b=";
	lcd_str(g);
	lcd_cmd(0x06);
	
	lcd_cmd(0x87);
	r="q=";
	lcd_str(r);
	lcd_cmd(0x06);
	
	
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
