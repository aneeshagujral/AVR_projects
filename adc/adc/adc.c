#include<avr/io.h>
#include<util/delay.h>

#define RS PC0 //added new port
#define RW PD1
#define EN PD2
#define LCD PORTD

void lcd_init();
void lcd_command(char);
void lcd_data(char);
void digicount(unsigned int);
void adc_init();
int adc_read(unsigned char);
void lcd_string(char *str);
void parameter1(int,int);



int main()
{
DDRB=0xFF;
DDRD=0xFF;
 
 int a,b;
 lcd_init();
 adc_init();
 
 while(1)
 {
 //// value of x
	DDRA=0b00000101;
	PORTA=0b00000011;
  	a=adc_read(1);
	lcd_command(0x80);
	lcd_string("x-axis              ");
  	lcd_command(0x8F);
  	digicount(a);
	_delay_ms(50);
	
 //// value of y
 
  	DDRA=0b00001010;
	PORTA=0b00000110;
  	int b=adc_read(2);
	lcd_command(0xC0);
	lcd_string("y-axis              ");
  	lcd_command(0xCF);
  	digicount(b);
	_delay_ms(50);
	
	parameter1(a,b);	
	}


	return 0;

}
void lcd_init()
{
lcd_command(0x02);
lcd_command(0x28);
lcd_command(0x0C);
lcd_command(0x01);
lcd_command(0x84);
}

void lcd_string(char *str)
{
int i=0;
while (str[i]!='\0')
{
lcd_data(str[i]);
i++;
}
}

void digicount(unsigned int x)
{
lcd_command(0x04);
unsigned int i;
while(x!=0)
{
i=x%10;
lcd_data(i+48);
x=x/10;
}
lcd_command(0x06);
 
 }

void adc_init()
{

ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
int adc_read(unsigned char ch)
{

 ADMUX=0x40|ch;
 ADCSRA|=(1<<ADSC);
 while(!(ADCSRA&(1<<ADIF)));
ADCSRA|=(1<<ADIF);

 return(ADC);
 }

void lcd_command(char A)
{
LCD=A&0xF0;
LCD&=~(1<<RS);
LCD&=~(1<<RW);
LCD|=(1<<EN);
_delay_ms(1);
LCD&=~(1<<EN);
_delay_ms(1);

LCD=(A<<4)&0xF0;

LCD&=~(1<<RS);
LCD&=~(1<<RW);
LCD|=(1<<EN);
_delay_ms(1);
LCD&=~(1<<EN);
_delay_ms(1);

}

void lcd_data(char A)
{
LCD=A&0xF0;
LCD|=(1<<RS);
LCD&=~(1<<RW);
LCD|=(1<<EN);
_delay_ms(1);
LCD&=~(1<<EN);
_delay_ms(1);

LCD=(A<<4)&0xF0;

LCD|=(1<<RS);
LCD&=~(1<<RW);
LCD|=(1<<EN);
_delay_ms(1);
LCD&=~(1<<EN);
}


void parameter1(int x,int y)
    {

 if((x>400)&&(x<=570)&&(y>340)&&(y<=500))
 {
 PORTB=0b00000101;
 }

 else if((x>570)&&(x<=600)&&(y>250)&&(y<=340))
 {     
 PORTB=0b00001001;
 }

 else if((x>600)&&(x<=680)&&(y>250)&&(y<=320))
 {
 PORTB=0b00000000;
 }

 else if((x>600)&&(x<=660)&&(y>320)&&(y<=360))
 {
 PORTB=0b00001010;
 }
 else
 {
 PORTB=0b00000110;
 }
}
