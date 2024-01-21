#include <reg51.h>

static unsigned char letter_hex_code[] = {0x79, 0x7c};
static unsigned char decimal_to_7seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
static unsigned char display_control_bits[4] = {0x08, 0x04, 0x02, 0x01};

#define DELAY 10
#define DELAY_DOUBLE 50

void delay(unsigned long amount) {
	unsigned long i, j;
	for(i = 0; i < amount; ++i) {
		for(j = 0; j < 500; ++j);
	}	
}

void convert_to_bcd2(unsigned int n, unsigned char digits[2]) {
	unsigned char i;
	for(i = 0; i < 2; ++i) {
		digits[i] = n % 10;
		n /= 10;
	}
}

void display_number(unsigned int n) {
	unsigned int i, j, k;
	unsigned char roll_num[4];
	roll_num[2] = letter_hex_code[0];
	roll_num[3] = letter_hex_code[1];
	
	convert_to_bcd2(n, roll_num);
	
	for(i = 0; i < DELAY; ++i) {
		for(j = 0; j < 200; ++j) {
			for(k = 0; k < 2; ++k) {
				P2 = 0;
				P0 = decimal_to_7seg[roll_num[k]];
				P2 = display_control_bits[k];
			}
			for(; k < 4; ++k) {
				P2 = 0;
				P0 = roll_num[k];
				P2 = display_control_bits[k];
			}
		}
	}
}

void main() {
	char counter = 0;
	
	P0 = 0x00;
	P2 = 0x00;
	while(1) {
		for(counter = 1;counter < 25; ++counter) {
			display_number(counter);
		}
	}
}