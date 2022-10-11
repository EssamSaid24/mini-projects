#include<avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int main(){
	DDRC = 0xFF;
	PORTC = 0x00;
	DDRD &=~(1<<PD3);
	SREG |= (1<<7);
	GICR |= (1<<INT1);
	MCUCR |= (1<<ISC11);
	while(1){

	}

}
ISR(INT1_vect){
	int i;
	for(i=0;i<8;i++){
		PORTC^=(1<<i);
		_delay_ms(400);
	}


}
