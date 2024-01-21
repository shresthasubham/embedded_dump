#include <reg51.h>

LED_Patterns: DB 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F

DELAY_COUNT: EQU 40

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
    MOV B, #10         ; Load B with 10
    DIV AB            ; Divide A by B, result in A, remainder in B
    MOV R2, A          ; Copy quotient to R2 (tens digit)
    MOV A, B          ; Copy remainder to A (ones digit)

    MOV P2, #0x01      ; Select the first digit
    MOV A, LED_Patterns[R2] ; Load pattern for tens digit
    MOV P0, A          ; Output to P0
    CALL DELAY        ; Call delay subroutine

    MOV P2, #0x02      ; Select the second digit
    MOV A, LED_Patterns[R1] ; Load pattern for ones digit
    MOV P0, A          ; Output to P0
    CALL DELAY        ; Call delay subroutine

    RET

MAIN:
    MOV R0, #0         ; Initialize loop counter

MAIN_LOOP:
    MOV R1, R0         ; Copy loop counter to R1
    CALL DISPLAY      ; Call display subroutine
    INC R0            ; Increment loop counter
    CJNE R0, #20, MAIN_LOOP ; Continue loop until R0 reaches 20

REVERSE_LOOP:
    DEC R0            ; Decrement loop counter
    MOV R1, R0         ; Copy loop counter to R1
    CALL DISPLAY      ; Call display subroutine
    JZ MAIN_LOOP      ; Jump back to the main loop if R0 becomes zero

    JMP REVERSE_LOOP  ; Continue the reverse loop

END
