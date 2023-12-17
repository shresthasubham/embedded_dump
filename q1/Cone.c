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
        A = 0x9A;
        A += 0x48;
        P0 = A;
        delay();
        
        A = 0x7F;
        A += 0xBC;
        P0 = A;
        delay();
        
        A = 0x89;
        A += 0x34;
        P0 = A;
        delay();
        
        A = 0x00;
        A = (A << 1) | (A >> 7);
        P0 = A;
    }
}
