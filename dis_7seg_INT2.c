#include<avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char num = 0;
int main(){
	DDRC = 0x0F;
	PORTC &= 0x00;
	DDRB &= ~(1<<PB2);
	SREG |= (1<<7);
	GICR |= (1<<INT2);
	MCUCR |= (1<<ISC2);
	while(1){

	}

}
ISR(INT2_vect){
	if(num==9){
		PORTC=0x09;

	}else{
		num++;
		PORTC = (PORTC & 0xF0) | (num & 0x0F);
	}
}
