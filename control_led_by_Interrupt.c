#include<avr/io.h>
#include <avr/interrupt.h>
int main(){
	GICR |= (1<<INT0);
	MCUCR |= (1<<ISC01);
	SREG |= (1<<7);
	DDRD &= ~(1<<PD2);
	DDRC |= (1<<PC0);
	PORTC |= (1<<PC0);
	while(1){

	}

}
ISR(INT0_vect){
	PORTC ^= (1<<PC0);

}
