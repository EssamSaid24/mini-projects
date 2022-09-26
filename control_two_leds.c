// A key for real led
#include<avr/io.h>
#include <util/delay.h>

int main(){
	DDRB &= ~(1<<PB0);
	DDRB &= ~(1<<PB1);
	DDRC = 0x03;
	PORTC &= ~(1<<PC0);
	PORTC &= ~(1<<PC1);
	int pressed_1 = 0;
	int pressed_2 = 0;
	while(1){
		if((PINB&(1<<PB0))){
			if(pressed_1 == 0){
				PORTC ^= (1<<PC0);
				pressed_1 = 1;
			}
		}else{
			pressed_1 = 0;
		}
		if((PINB&(1<<PB1))){
			if(pressed_2 == 0){
				PORTC ^= (1<<PC1);
				pressed_2 = 1;
			}
		}else{
			pressed_2 = 0;
		}

	}
}
