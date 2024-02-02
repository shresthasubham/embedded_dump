ORG 00H
    MOV TMOD, #00   ; Timer 1 in mode 0

HERE: 
    SETB P2.0       ; Set P2.0 high
    ACALL DELAY     ; Call delay subroutine
    CLR P2.0        ; Set P2.0 low
    MOV R4, #04     ; Initialize R4 with 4 (20% duty cycle)

L1: 
    ACALL DELAY     ; Call delay subroutine
    DJNZ R4, L1     ; Decrement R4, jump to L1 if not zero
    SJMP HERE       ; Jump to HERE (loop)

DELAY: 
    MOV TL1, #0F5H  ; Load low byte for 15 ms delay
    MOV TH1, #0A0H  ; Load high byte for 15 ms delay
    SETB TR1        ; Start Timer 1

AGAIN: 
    JNB TF1, AGAIN  ; Wait for Timer 1 overflow
    CLR TR1         ; Stop Timer 1
    CLR TF1         ; Clear Timer 1 overflow flag
    RET            ; Return from the subroutine
