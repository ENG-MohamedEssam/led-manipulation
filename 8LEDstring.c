#include <avr/io.h>
#define F_CPU 8000000UL //Tell the processor about the oscillator
#include <avr/delay.h>

void flashing(void);
void shiftLeft(void);
void shiftRight(void);
void converging(void);
void diverging(void);
void pingPong(void);
void snakeEffect(void);
void ConvergeDiverge(void);

#define zero	0b00000000
#define one 	0b00000001
#define two		0b00000010
#define three	0b00000011
#define four	0b00000100
#define five	0b00000101
#define six		0b00000110
#define seven	0b00000111

int main (void)
{
	DDRC = 0xff;
	DDRD = 0x00;
	PORTD = 0b0000111;
	while(1)
	{
		if (PIND == zero )
		{
			flashing();
		}
		else if (PIND == one)
		{
			shiftLeft();
		}
		else if (PIND == two)
		{
			shiftRight();
		}
		else if (PIND == three)
		{
			converging();
		}
		else if (PIND == four)
		{
			diverging();
		}
		else if (PIND == five)
		{
			pingPong();
		}
		else if (PIND == six)
		{
			snakeEffect();
		}
		else if (PIND == seven)
		{
			ConvergeDiverge();
		}
		else
		{
			PORTC = 0x00;
		}
	}
	return 0;

}

void flashing(void)
{
	PORTC = 0xff;
	_delay_ms(250);
	PORTC = 0x00;
	_delay_ms(250);
}

void shiftLeft(void)
{
	PORTC = 0x00;
	for (int i = 0; i <8; i++)
	{
		PORTC |= 1<<i;
		_delay_ms(125);
		PORTC &= 0<<i;
		_delay_ms(125);
	}
}

void shiftRight(void)
{
	PORTC = 0x00;
	for (int i = 0; i <8; i++)
	{
		PORTC |= 1<<(7-i);
		_delay_ms(125);
		PORTC &= 0<<(7-i);
		_delay_ms(125);
	}
}

void converging(void)
{
	PORTC = 0x00;
	for (int i = 0; i < 4; i++)
	{
		_delay_ms(150);
		PORTC |= 1<<i;
		PORTC |= 1<<(7-i);
		_delay_ms(150);
	}
}

void diverging(void)
{
	PORTC =0x00;
	for (int i = 4; i >= 0; i--)
	{
		_delay_ms(150);
		PORTC |= 1<<i;
		PORTC |= 1<<(7-i);
		_delay_ms(150);
	}
}

void pingPong(void)
{
	shiftLeft();
	shiftRight();
}

void snakeEffect(void)
{
	PORTC = 0x00;
	for (int i = 0; i <8; i++)
	{
		PORTC |= 1<<i;
		_delay_ms(150);
	}
	PORTC = 0x00;
	for (int i = 0; i <8; i++)
	{
		PORTC |= 1<<(7-i);
		_delay_ms(150);
	}

}

void ConvergeDiverge(void)
{
	converging();
	diverging();
}
