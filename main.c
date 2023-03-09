/*  __   __   ______   __    __    ________   __   __   ______   _____ 
 * |  \_/  | |  __  | |  |  |  |  |   __   | |  \_/  | |  ____| |  __ \
 * |       | | |  | | |  |__|  |  |  |__|  | |       | | |__    | |  | |
 * |  |_|  | | |  | | |   __   |  |   __   | |  |_|  | |  __|   | |  | |
 * |  | |  | | |__| | |  |  |  |  |  |  |  | |  | |  | | |____  | |__| |
 * |__| |__| |______| |__|  |__|  |__|  |__| |__| |__| |______| |_____/
 *  Mohamed Abdelrehem Ali
 */

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "avr/interrupt.h"

int main(void)
{
	
	DDRD = 0x00;
	DDRC = 0xFF;
	MCUCR =0x02;		
	GICR = (1<<INT0);
	sei();

	
    while (1) 
    {	
		
		PORTC = 0b00000001;
		_delay_ms(250);
		PORTC = 0b00000010;
		_delay_ms(250);
		PORTC = 0b00000100;
		_delay_ms(250);
		PORTC = 0b00001000;
		_delay_ms(250);
		PORTC = 0b00010000;
		_delay_ms(250);
		PORTC = 0b00100000;
		_delay_ms(250);
		PORTC = 0b01000000;
		_delay_ms(250);
		PORTC = 0b10000000;
		_delay_ms(250);
    }
return 0;
}
ISR(INT0_vect){
	int x = PORTC;
	PORTC = 0xFF;
	_delay_ms(1000);
	PORTC = x;
	_delay_ms(250);
	
}
