#include <reg51.h>

void delay() {
    unsigned char R7 = 255;
    unsigned char R6, R5;
    while (R7 != 0) {
        R6 = 255;
        while (R6 != 0) {
            R5 = 255;
            while (R5 != 0) {
                R5--;
            }
            R6--;
        }
        R7--;
    }
}

void main() {
    unsigned char A;
    while (1) {
        A = 0x6B;
        P0 = A;
        delay();
     A = (A >> 1) | (A << 7);
    A = (A >> 1) | (A << 7);
    A = (A >> 1) | (A << 7);
    A = (A >> 1) | (A << 7);
        P0 = A;
        delay();
    }
}

