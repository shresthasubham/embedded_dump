#include <reg51.h>
#include <absacc.h>

static unsigned char decimal_to_7seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
static unsigned char display_control_bits[4] = {0x08, 0x04, 0x02, 0x01};

#define DELAY 30
#define DELAY_DOUBLE 50

#define TABLE_AT 0x40

void delay(unsigned long amount) {
	unsigned long i, j;
	for(i = 0; i < amount; ++i) {
		for(j = 0; j < 500; ++j);
	}	
}

unsigned char convert_to_bcd4(unsigned int n, unsigned char digits[4]) {
	unsigned char n_digits = 0;
	do {
		digits[n_digits++] = n % 10;
		n /= 10;
	} while (n > 0);
	
	return n_digits;
}

void display_number(unsigned int n) {
	unsigned int i, j, k;
	unsigned char digits[4], n_digits;
	
	n_digits = convert_to_bcd4(n, digits);
	
	for(j = 0; j < 200; ++j) {
		for(k = 0; k < n_digits; ++k) {
			P2 = 0;
			P0 = decimal_to_7seg[digits[k]];
			delay(7);
			P2 = display_control_bits[k];
			
			for(i = 0; i < 100; ++i);
		}
	}
}

void generate_mul_table(unsigned char n) {
	unsigned char i;
	for(i = 1; i <= 10; ++i) {
		DBYTE[TABLE_AT + i - 1] = n * i;
	}
}

void main() {
	unsigned char i;
	
	DBYTE[0x30] = 9;
	generate_mul_table(DBYTE[0x30]);
	
	P0 = 0x00;
	P2 = 0x00;
	while(1) {
		for(i = 0; i < 10; ++i) {
			display_number(DBYTE[TABLE_AT + i]);
		}
 	}
}