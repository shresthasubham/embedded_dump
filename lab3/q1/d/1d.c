#include<reg51.h>

sbit out = P2^0;

unsigned int multiple = 0, delay = 3000/1.085, quotient = 0, remainder = 0;

void delay3ms() {
	unsigned int i =0;
	TMOD = 0x03;
	TL0 = 0xFF-remainder;
	TR0 = 1;
	for(i=0; i<quotient+1; ++i){
		while(TF0 == 0);
		TF0 = 0;
		TL0=0xFF-multiple+10;
	}
		TF0 = 0;
		TR0 = 0;
}

void calculate_the_register_values(void) {
	unsigned int i ;
	for(i = 0xFF; i>0; --i)
	{
		quotient = delay / i;
		if( quotient < 0xFF)
		{
			multiple = i;
			remainder = delay % i;
			break;
		}	
	}
}	
			
void main() {
	calculate_the_register_values();
	while(1) {
		out = 1; 
		delay3ms();
		out = 0;
		delay3ms();
		delay3ms();
		delay3ms();
		delay3ms();
	}
}