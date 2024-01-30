#include <8051.h>

void delay() {
    unsigned char R7 = 7;
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
    unsigned char A, R3, R1, R0;
    A = 0x00;
    R3 = 0x00;
    P2 = 0xFF;
    P1 = 0xDE;
    R1 = P2;
    R0 = P1;
    while (R0 != 0) {
        A += R1;
        if (CY == 0) {
            R3++;
        }
        R0--;
    }
    P3 = A;
    P0 = A;
    delay();
    P0 = R3;
    P4 = R3;
    delay();
    while (1) {
        // infinite loop
    }
}

