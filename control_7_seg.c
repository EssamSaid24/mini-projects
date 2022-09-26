#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRD &=~(1<<PD4);
	DDRD &=~(1<<PD3);
	DDRC |= 0x0F;
	PORTC &= ~( (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3));
	unsigned char num = 0;
	while(1){
		if((PIND &= (1<<PD4))){

			if(num==9){
				PORTC = 0x09;
			}
			else{
				num ++;
				PORTC = (PORTC & 0xF0) | (num & 0x0F);
			}
		}
		if((PIND &= (1<<PD3))){
			if(num==0){
				PORTC = 0x00;
			}
			else{
				num --;
				PORTC = (PORTC & 0xF0) | (num & 0x0F);
			}
		}

	}
}
