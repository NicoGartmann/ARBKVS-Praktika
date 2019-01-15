

#include <avr/io.h>
#define F_CPU  16000000
#include <util/delay.h>



int state = 0;

void abfrage()
{
	if(!(PIND & (1<< PIND2)))
	{
		if(state == 0 || state == 2)
		{
			state = 1;
		}
		else
		{
			state = 0;
		}
	}
	else if(!(PIND & (1<< PIND3)))
	{
		if(state == 0 || state == 1)
		{
			state = 2;
		}
		else
		{
			state = 0;
		}
	}
}
int main(void)
{
	DDRD  = 0b00000000;
	PORTD = 0b00001100;
	DDRB  = 0b00000011;

    while (1)
    {
		abfrage();
		PORTB = 0b00000000;
		_delay_ms(200);
		if(state == 1)
		{
			PORTB = 0b00000001;
		}
		else if (state == 2)
		{
			PORTB = 0b00000010;
		}
		_delay_ms(200);
}
}