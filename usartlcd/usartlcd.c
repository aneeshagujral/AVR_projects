/*
 * usartlcd.c
 *
 * Created: 6/15/2016 1:08:48 PM
 *  Author: Aneesha
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000
#define baud_rate 1200
#define ubrr_value ((F_CPU/(16*baud_rate))-1)
#define lcd PORTD
#define rs 0
#define rw 1
#define en 2
void lcd_init();
void lcd_data(char);
void lcd_cmd(char);
void lcd_str(char *p);
void usart_init();
void usart_send(char i);
char usart_rec();

int main(void)
{
    DDRB=0xff;
	DDRD=0xff;
	lcd_init();
	usart_init();
	
	lcd_cmd(0x80);
	int q=0x80;
	
	while(1)
	{
		
		
		char x;
		x=usart_rec();
		char c=c;
		_delay_ms(10);
		lcd_data(x);
		q++;
	
		if(q==0x8f)
		{
			lcd_cmd(0xc0);
		}
		else if(q==0xcf)
		{
			lcd_cmd(0x80);
		}
	
		/*if(x=='a')
		{
			
			PORTB=0x01;
			lcd_data('a');
			
			
			
		}
		else if(x=='b')
		{
			
			PORTB=0x02;
		
			lcd_data('b');
			
		}
		else if(x=='c')
		{
			
			PORTB=0x03;
			lcd_data('c');
			i++;
		}		
		else if (x=='d')
		{
			lcd_cmd(i);
			_delay_ms(10);
			PORTB=0x04;
			lcd_data('d');
			i++;
		}
		else if(x=='e')
		{
			PORTB=0x01;
			lcd_data('e');
			
			
		}
		else if(x=='f')
		{
			PORTB=0x02;
			lcd_data('f');
		}
		else if(x=='g')
		{
			PORTB=0x03;
			lcd_data('g');
		}		
		else if (x=='h')
		{
			PORTB=0x04;
			lcd_data('h');
		}
		else if(x=='i')
		{
			PORTB=0x01;
			lcd_data('i');
			
			
		}
		else if(x=='j')
		{
			PORTB=0x02;
			lcd_data('j');
		}
		else if(x=='k')
		{
			PORTB=0x03;
			lcd_data('k');
		}		
		else if (x=='l')
		{
			PORTB=0x04;
			lcd_data('l');
		}
		else if(x=='m')
		{
			PORTB=0x01;
			lcd_data('m');
			
			
		}
		else if(x=='n')
		{
			PORTB=0x02;
			lcd_data('n');
		}
		else if(x=='o')
		{
			PORTB=0x03;
			lcd_data('o');
		}		
		else if (x=='p')
		{
			PORTB=0x04;
			lcd_data('p');
		}*/
	}
	return 0;
}
void usart_init()
{
	UBRRL=ubrr_value;
	UBRRH=(ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	
	UCSRB=(1<<TXEN)|(1<<RXEN);
}
char usart_rec()
{
	while(!(UCSRA&(1<<RXC)))
	{
		
	}
	return UDR;
}

void lcd_init()
{
//	lcd_cmd(0x01);
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