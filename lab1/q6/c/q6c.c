#include <reg51.h>

#define NUMS 10
#define BASE 0x60

void delay() {
    unsigned char R7 = 7;
    unsigned char R6 = 1;
    unsigned char R1 = 2;
    
    do {
        do {
            do {
                R1--;
            } while (R1 != 0);
            R6--;
        } while (R6 != 0);
        R7--;
    } while (R7 != 0);
}

void main() {
    unsigned char R1, R2, R4;
    unsigned char A;
    unsigned char array[NUMS] = {0xA5, 0xFD, 0x67, 0x42, 0xDF, 0x9A, 0x84, 0x1B, 0xC7, 0x31};
    
    while (1) {
        for (R2 = NUMS - 1; R2 != 0xFF; R2--) {
            A = R2;
            R4 = A;
            R1 = BASE;
            
            do {
                A = array[R1 - BASE];
                R1++;
                A -= array[R1 - BASE];
                
                if (A >= 0x80) {
                    unsigned char temp = array[R1 - BASE];
                    array[R1 - BASE] = array[R1 - BASE - 1];
                    array[R1 - BASE - 1] = temp;
                    R1--;
                }
            } while (R4 != 0);
        }
        
        for (R1 = BASE; R1 < BASE + NUMS; R1++) {
            P0 = R1;
            delay();
        }
    }
}
