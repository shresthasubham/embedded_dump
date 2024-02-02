#include<reg51.h>

sbit out = P2^0;

void delay3ms() {
	TMOD = 0x00;
	TH0 = 0xB0;
	TL0 = 0x58;
	TR0 = 1;
	while(TF0 == 0);
	TF0 = 0;
	TR0 = 0;
}

void main() {
	unsigned int i;
	while(1) {
		out = 1; 
		delay3ms();
		out = 0;
		for(i =0 ; i<4; ++i){
		delay3ms();
		}
	}
}