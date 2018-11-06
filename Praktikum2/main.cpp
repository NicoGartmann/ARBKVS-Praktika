/*
 * Praktikum2.cpp
 *
 * Created: 06.11.2018 15:52:34
 * Author : nicog
 */ 
#include <avr/io.h>  /*AVR Bibliothek*/
#define F_CPU 16000000UL /*CPU Takt*/
#include "util/delay.h" /*Bibliothek für Delayfunktion*/




int main(void) /*Hauptprogramm*/
{
	DDRB |= 0x7; /*DDR setzten*/
	while (1) /*Endlos Schleife*/
	{
		PORTB = 0x4;  /*LED rot an*/
		_delay_ms(1000);     /*warten*/

		PORTB = 0x2;  /*LED gelb an*/
		_delay_ms(1000);	 /*warten*/
		
		PORTB = 0x1;	/*LED grün an*/
		_delay_ms(1000);	/*warten*/
		
		PORTB = 0x2;	/*LED gelb an*/
		_delay_ms(1000);	/*warten*/
	}
	
	return 0; /*Programm endet mit 0*/
}
