#include<reg51.h>
#include<math.h>

sbit out = P0^0;

void delay(unsigned long timer_value){
	TMOD = 0x10;
	TH1 = ((timer_value + 137) >> 8) & 0xFF; //for higher value
	TL1 = (timer_value +137) & 0xFF; //for lower value
	TR1 = 1;
	while (TF1 == 0);
	TF1 = 0;
	TR1 = 0;
}

void main() {
	unsigned int i =0;
	while(1) {
		out = 0x01;
		delay(0x4BFD); //manual calculation for 50ms
		out = 0x00;
		delay(0x4BFD);
		for(i =0 ; i< 10; ++i){
		out = 0x01;
		delay(0xDBFF); //manually calculated for 10ms
		out = 0x00;
		delay(0xDBFF);
		}
	}
}