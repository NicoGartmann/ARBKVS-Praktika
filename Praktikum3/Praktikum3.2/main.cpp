#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int state = 0;



ISR(INT0_vect)
{

	if(state == 0 || state == 2)
	{
		state = 1;
	}
	else if(state == 1)
	{
		state = 0;
	}
}

ISR(INT1_vect)
{
	if(state == 0 || state == 1)
	{
		state = 2;
	}
	else if(state == 2)
	{
		state = 0;
	}
}

int main(void)
{
	EICRA |= (1<< ISC11); //Interrupts auf Hochflanke getriggert
	EIMSK |= (1<<INT0); // Interrupt 0 an
	EIMSK |= (1<<INT1);  // Interrupt 1 an 

	DDRB  = 0b00000011;
	DDRD  = 0b00000000;
	PORTD = 0b00001100;

	sei();  // aktiviert Interrupts 

	while (1)
	{
		//beide LED aus 
		PORTB = 0b00000000;
		_delay_ms(200);

		//LED je nach state an 
		if(state == 1)
		{
			//gelbe LED 
			PORTB = 0b00000001;
		}
		if(state == 2)
		{
			//rote LED 
			PORTB = 0b00000010;
		}
		_delay_ms(200);
	}
}