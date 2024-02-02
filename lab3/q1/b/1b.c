#include<reg51.h>

sbit out = P2^0;

void delay(unsigned long timer_value){
	TMOD = 0x10;
	TH1 = ((timer_value + 187 )>> 8) & 0xFF; //for higher value
	TL1 = (timer_value + 187) & 0xFF; //for lower value
	TR1 = 1;
	while (TF1 == 0);
	TF1 = 0;
	TR1 = 0;
}

void main() {
	unsigned int i =0;
	while(1) {
		out = 0x01;
		delay(0xF533); //manually calculated for 3ms
		out = 0x00;
		//12 ms can be done by calling 3ms function 4 times
		delay(0xD4CC); //for 12 ms 
	}
}