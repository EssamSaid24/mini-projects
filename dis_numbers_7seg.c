#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char num = 0;
	DDRD  &= ~(1<<PD4);
	DDRC |= 0x0F;
	PORTC &= ~( (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3) );

    while(1)
    {
			if( PIND & (1<<PD4) )
			{
				if(num == 9)
				{
					num = 0;
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}
				else
				{
					num++;
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}

			while(PIND &(1<<PD4));
		}
    }
}

