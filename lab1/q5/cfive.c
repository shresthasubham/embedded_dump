#include <reg51.h>

void delay() {
    unsigned char r7 = 7;
    unsigned char r6 = 1;
    unsigned char r1 = 2;
    
    while (r7 != 0) {
        r6 = 1;
        while (r6 != 0) {
            r1 = 2;
            while (r1 != 0) {
                r1--;
            }
            r6--;
        }
        r7--;
    }
}

void main() {
    unsigned char r5 = 0;
    unsigned char r1 = 0x12;
    unsigned char a = 0x3E;
    unsigned char r4;
    
    while (1) {
        a -= r1;
        if (a < 0) {
            break;
        }
        r5++;
    }
    
    a += r1;
    r4 = a;
    
    P0 = r5;
    delay();
    
    P0 = r4;
    delay();
    
    while (1) {
        // Infinite loop
    }
}

