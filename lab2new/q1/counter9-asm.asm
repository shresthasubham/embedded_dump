#include <REG51.H>

ORG 0x0000	; Start address
MOV P2, #0xFE	; Initialize P2

DELAY:		; Delay subroutine
	MOV R2, #0	; Initialize outer loop counter
OUTER_LOOP:
	MOV R1, #0	; Initialize inner loop counter
INNER_LOOP:
	DJNZ R1, INNER_LOOP ; Decrement inner loop counter and jump if not zero
	DJNZ R2, OUTER_LOOP ; Decrement outer loop counter and jump if not zero
	RET			; Return from subroutine

MAIN:
	MOV DPTR, #d	; Load data pointer with the address of array 'd'
	MOV R0, #0	; Initialize loop counter

LOOP_FORWARD:
	MOV A, R0	; Move loop counter to accumulator
	ADD A, #0xC0	; Add base address of 'd' to accumulator
	MOVX A, @DPTR	; Move the value at the calculated address to accumulator
	MOV P0, A	; Move the value to P0
	CALL DELAY	; Call delay subroutine
	INC R0		; Increment loop counter
	CMP R0, #10	; Compare loop counter with 10
	JNZ LOOP_FORWARD ; Jump if not equal

LOOP_BACKWARD:
	DEC R0		; Decrement loop counter
	MOV A, R0	; Move loop counter to accumulator
	ADD A, #0xC0	; Add base address of 'd' to accumulator
	MOVX A, @DPTR	; Move the value at the calculated address to accumulator
	MOV P0, A	; Move the value to P0
	CALL DELAY	; Call delay subroutine
	JNZ LOOP_BACKWARD ; Jump if not zero

	JMP MAIN	; Jump to MAIN (infinite loop)

d:			; Data array
	DB 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x7F, 0x6F
