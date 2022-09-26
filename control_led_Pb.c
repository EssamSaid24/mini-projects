// Button pressed or released
#include <avr/io.h>
#include <util/delay.h>


int main(){
	DDRC|=(1<<PC5);
	DDRA &= ~(1<<PA3);
	PORTC &= ~(1<<PC5);

while(1){
	if((  PINA & (1<<PA3) )){
		PORTC |= (1<<PC5);
	}
	else{
		PORTC &= ~(1<<PC5);
	}
	}
}
