#include <reg51.h>

static unsigned char decimal_to_7seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
static unsigned char display_control_bits[4] = {0x01, 0x02, 0x04, 0x08};

#define DELAY 4
#define DELAY_DOUBLE 50

void delay(unsigned int amount) {
	unsigned int i;
	for(i = 0; i < amount; ++i);	
}

void convert_to_bcd3(unsigned int n, unsigned char digits[3]) {
	unsigned char i;
	for(i = 0; i < 3; ++i) {
		digits[2-i] = decimal_to_7seg[n%10];
		n /= 10;
	}
	digits[2] |= 0x80;
}


void display_char4(unsigned char arr[4]) {
	unsigned char i, j, k;
	for(i = 0; i < DELAY; ++i) {
		for(j = 0; j < 200; ++j) {
			for(k = 0; k < 4; ++k) {
				P2 = 0;
				P0 = arr[k];
				P2 = display_control_bits[k];
				delay(10);
			}
		}
	}
}

void shift_roll_num_array_left(unsigned char arr[9]) {
	unsigned char tmp, i;
	tmp = arr[0];
	for(i = 0; i < 8; ++i) {
		arr[i] = arr[i+1];
	}
	arr[8] = tmp;
}

void main() {
	char counter = 0, i;
	unsigned char roll_num_hex_code[9] = {0x3f, 0x07, 0x07, 0x7c, 0x79, 0x30, 0, 0, 0};  // 077bEiXXX
	
	P0 = 0x00;
	P2 = 0x00;
	while(1) {
		for(counter = 1; counter < 25; counter += 1) {
			convert_to_bcd3(counter, roll_num_hex_code + 6);
			for(i = 0; i < 9; ++i) {
				display_char4(roll_num_hex_code);
				shift_roll_num_array_left(roll_num_hex_code);
			}
		}
	}
}