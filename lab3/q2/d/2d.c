#include<reg51.h>

sbit out = P0^0;

unsigned int multiple = 0, quotient = 0, remainder = 0;

void calculate_the_register_values(unsigned int delay_value) {
	unsigned int i ;
	for(i = 0xFF; i>0; --i)
	{
		quotient = delay_value / i;
		if( quotient < 0xFF) //manual adjusment required due to certain factors
		{
			multiple = i;
			remainder = delay_value % i;
			break;
		}	
	}
}	

void delay(unsigned int delay_value) {
	unsigned int i =0, tuning_value;
	calculate_the_register_values(delay_value*1000/1.085);	
	TMOD = 0x03;
	tuning_value = delay_value == 10 ? 45:9; // fine tuning
	TH0 = 0xFF-remainder;
	TR0 = 1;
	for(i=0; i<quotient-5; ++i){
		while(TF0 == 0);
		TF0 = 0;
		TH0 = 0xFF-multiple+ tuning_value; //manual adjustment 
	}
		TF0 = 0;
		TR0 = 0;
}
			
void main() {
	unsigned int i = 0;
	while(1) {
		out = 1; 
		delay(50);
		out = 0;
		delay(50);
		for(i =0; i<10; ++i)
		{
			out = 1; 
			delay(10);
			out = 0;
			delay(10);
		}
	}
}