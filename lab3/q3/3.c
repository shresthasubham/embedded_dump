#include <reg51.h>

static unsigned char decimal_to_7seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
static unsigned char display_control_bits[4] = {0x01, 0x02, 0x04, 0x08};

static unsigned int seconds = 0;
static unsigned int minutes = 0;
static unsigned int time[4] = {0x3f, 0x3f, 0x3f, 0x3f};
static unsigned int overflow = 0;

void delay(unsigned int amount) {
	unsigned int i;
	for(i = 0; i < amount; ++i);	
}

change_time_to_bcd(){
	unsigned int set_min=1, set_sec=3;
		time[set_min] = decimal_to_7seg[minutes%10];
		time[set_min-1] = decimal_to_7seg[minutes/10];
		time[set_min] |= 0x80;
		
		time[set_sec] = decimal_to_7seg[seconds%10];
		time[set_sec-1] = decimal_to_7seg[seconds/10];
}

set_time() {
	change_time_to_bcd();
}

void display_time(unsigned int *time) {
	unsigned char i, j, k;
	for(i = 0; i < 4; ++i) {
		for(j = 0; j < 200; ++j) {
			for(k = 0; k < 4; ++k) {
				P2 = 0;
				P0 = time[k];
				P2 = display_control_bits[k];
				delay(10);
			}
		}
	}
}

void handle_interrupt() interrupt 3 {
	overflow++;
	overflow = (overflow == 14) ? (seconds++, (seconds == 60) ? (minutes++, (minutes == 60) ? (0) : minutes, seconds = 0) : seconds, overflow = 0) : overflow;
	set_time();
}

void main() {
	TH1 = 0;
	TL1 = 0;
	TMOD = 0x10;
	IE = 0x88;
	TR1 = 1;
	while(1) {
		display_time(time);
	}
}