/*
 * techtronix.c
 *
 * Created: 26-12-2018 12:54:37
 *  Author: yash
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

// common anode config, row's common terminal is -ve
// and col's common terminal is +ve

int main(void)
{
	DDRA=DDRB=0xff;
	char name[4][5]={{0xb0,0xb7,0xb7,0xb7,0x80},     //Y
                         {0x83,0xf5,0xf6,0xf5,0x83},     //A
		         {0xd1,0xb6,0xb6,0xb6,0xc5},     //S
			 {0x00,0xf7,0xf7,0xf7,0x00}};    //H
			 
    const char cols[]={0x01,0x02,0x04,0x08,0x10};
		
	for(int j=0;j<100;j++)
	{
		for(int k=0;k<4;k++)
		{
			for(int i=0;i<5;i++)
			{
				PORTA=cols[i];
				PORTB=name[k][i];
				_delay_ms(1);
			}
			PORTB=0xff;
			_delay_ms(1000);
		}
	}
	
	while(1);
}