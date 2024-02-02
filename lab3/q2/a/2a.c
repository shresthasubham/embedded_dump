#include<reg51.h>

sbit out = P0^0;

//since the max value can be calculated for
//13 bit timer is for 8.8 ms 
//5ms delay was used

void delay5ms(){ 
	TMOD = 0x00;
	TH0 = 0x72;
	TL0 = 0xD1;
	TR0 = 1;
	while (TF0 == 0);
	TF0 = 0;
	TR0 = 0;
}

void delay10ms() {
	delay5ms();
	delay5ms();
}

void delay50ms() {
	delay10ms();
	delay10ms();
	delay10ms();
	delay10ms();
	delay10ms();
}

void main() {
	unsigned int i =0;
	while(1) {
		out = 0x01;
		delay50ms();
		out = 0x00;
		delay50ms();
		for(i =0 ; i< 10; ++i){
		out = 0x01;
		delay10ms();
		out = 0x00;
		delay10ms();
		}
	}
} 