/*
 * keypad.c
 *
 * Created: 6/8/2016 12:17:58 PM
 *  Author: Aneesha
 */ 

ATM Prototype: Interfacing LCD and Keybads, and buzzers

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   DDRB=0xff;
   DDRC=0xff;
   DDRA=0x00;
   PORTA=0xff;
   int p,q,r,s;
   int a[2]={0,2};
	int b[2]={p,q};  
	
  okay: while(1)
   {
	   PORTC=0b00000111;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   p=0;
		  // PORTB=0x00;
		   goto there;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   p=1;
		   //PORTB=0x01;	
		   goto there;
	   }
	   if((PINA&0b00000100)==0)
	   {
		   p=2;
		  // PORTB=0x01;	
		   goto there;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   p=3;
		  // PORTB=0x01;	
		   goto there;
	   }
	   PORTC=0b00001011;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   p=4;
		  // PORTB=0x01;	
		   goto there;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   p=5;
		 //  PORTB=0x01;	
		   goto there;
	   }
	   if((PINA&0b00000100)==0)
	   {
		   p=6;
		 //  PORTB=0x01;	
		   goto there;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   p=7;
		 //  PORTB=0x01;	
		   goto there;
	   }		
	   PORTC=0b00001101;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   p=8;
		 //  PORTB=0x01;	
		   goto there;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   p=9;
		 //  PORTB=0x01;	
		   goto there;	
	   }
	   if((PINA&0b00000100)==0)
	   {
		   p=0x0a;
		 //  PORTB=0x01;	
		   goto there;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   p=0x0b;
		 //  PORTB=0x01;	
		   goto there;
	   }			  
	   PORTC=0b00001110;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   p=0x0c;
		 //  PORTB=0x01;	
		   goto there;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   p=0x0d;
		 //  PORTB=0x01;	
		   goto there;	
	   }
	   if((PINA&0b00000100)==0)
	   {
		   p=0x0e;
		 //  PORTB=0x01;	
		   goto there;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   p=0x0f;
		 //  PORTB=0x01;	
		   goto there;
	   } 	   
   }
   there: while(1)
   {
	   PORTC=0b00000111;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   q=0;
		  // PORTB=0x00;
		   goto here;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   q=1;
		   //PORTB=0x01;	
		   goto here;
	   }
	   if((PINA&0b00000100)==0)
	   {
		   q=2;
		  // PORTB=0x01;	
		   goto here;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   q=3;
		  // PORTB=0x01;	
		   goto here;
	   }
	   PORTC=0b00001011;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   q=4;
		  // PORTB=0x01;	
		   goto here;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   q=5;
		 //  PORTB=0x01;	
		   goto here;
	   }
	   if((PINA&0b00000100)==0)
	   {
		   q=6;
		 //  PORTB=0x01;	
		   goto here;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   q=7;
		 //  PORTB=0x01;	
		   goto here;
	   }		
	   PORTC=0b00001101;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   q=8;
		 //  PORTB=0x01;	
		   goto here;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   q=9;
		 //  PORTB=0x01;	
		   goto here;	
	   }
	   if((PINA&0b00000100)==0)
	   {
		   q=0x0a;
		 //  PORTB=0x01;	
		   goto here;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   q=0x0b;
		 //  PORTB=0x01;	
		   goto here;
	   }			  
	   PORTC=0b00001110;
	   _delay_ms(100);
	   if((PINA&0b00000001)==0)
	   {
		   q=0x0c;
		 //  PORTB=0x01;	
		   goto here;
	   }
	   if((PINA&0b00000010)==0)
	   {
		   q=0x0d;
		 //  PORTB=0x01;	
		   goto here;	
	   }
	   if((PINA&0b00000100)==0)
	   {
		   q=0x0e;
		 //  PORTB=0x01;	
		   goto here;
	   }
	   if((PINA&0b00001000)==0)
	   {
		   q=0x0f;
		 //  PORTB=0x01;	
		   goto here;
	   } 	   
   }
   
   
   here: 
   while(1)
		
   {
	   if(p==0&&q==2)
	   {
		   PORTB=0x01;
	   }
	   else
	   {
		   PORTB=0x02;
	   }		   		   
   }
}   