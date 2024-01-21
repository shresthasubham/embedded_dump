#include <reg51.h>

SCROLL_Patterns: DB 0x39, 0x6D, 0x06, 0xCF, 0x39, 0x6D, 0x06, 0xE6, 0x39, 0x6D, 0x06, 0xED, 0x39, 0x6D, 0x06, 0xFD, 0x39, 0x6D, 0x06

DELAY_COUNT: EQU 10

DELAY:
    MOV R2, #DELAY_COUNT
DELAY_LOOP:
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    DJNZ R2, DELAY_LOOP
    RET

DISPLAY:
    MOV A, R1          ; Copy value of R1 to accumulator
    MOV B, #4          ; Load B with 4
    ADD A, B          ; Add 4 to A
    MOV R2, A          ; Copy result to R2

    MOV P2, #0x01      ; Select the first digit
    MOV A, SCROLL_Patterns[R2] ; Load pattern for current digit
    MOV P0, A          ; Output to P0
    CALL DELAY        ; Call delay subroutine

    MOV P2, #0x02      ; Select the second digit
    MOV A, SCROLL_Patterns[R1] ; Load pattern for next digit
    MOV P0, A          ; Output to P0
    CALL DELAY        ; Call delay subroutine

    MOV P2, #0x04      ; Select the third digit
    MOV A, SCROLL_Patterns[R1+1] ; Load pattern for next digit
    MOV P0, A          ; Output to P0
    CALL DELAY        ; Call delay subroutine

    MOV P2, #0x08      ; Select the fourth digit
    MOV A, SCROLL_Patterns[R1+2] ; Load pattern for next digit
    MOV P0, A          ; Output to P0
    CALL DELAY        ; Call delay subroutine

    RET

MAIN:
    MOV R0, #4         ; Initialize loop counter

MAIN_LOOP:
    MOV R1, R0         ; Copy loop counter to R1
    CALL DISPLAY      ; Call display subroutine
    INC R0            ; Increment loop counter
    CJNE R0, #20, MAIN_LOOP ; Continue loop until R0 reaches 20

    JMP MAIN_LOOP      ; Repeat the main loop

END
