ORG 0000H

DELAY EQU 3

MOV 20H, #03FH
MOV 21H, #006H
MOV 22H, #05BH
MOV 23H, #04FH
MOV 24H, #066H
MOV 25H, #06DH
MOV 26H, #07DH
MOV 27H, #007H
MOV 28H, #07FH
MOV 29H, #06FH

MOV 32H, #079H
MOV 33H, #07CH

LOOP:
MOV A, #0H
INCREASING:
INC A
LCALL DISPLAY_NUMBER
CJNE A, #018H, INCREASING

JMP LOOP


DISPLAY_NUMBER:
MOV R3, A
MOV R1, #30H
LCALL EXTRACT_DIGITS

MOV R6, DELAY
OUTER:
MOV R7, #0FFH
INNER:
MOV R1, #30H
MOV R2, #08H

MOV R4, #04H
NEXT_DIGIT:
MOV P2, #0H
MOV P0, @R1
MOV P2, R2

XCH A, R2
RR A
XCH A, R2
INC R1
DJNZ R4, NEXT_DIGIT

DJNZ R7, INNER
DJNZ R6, OUTER

MOV A, R3
RET


EXTRACT_DIGITS:
MOV R4, #02H

EXTRACT_NEXT_DIGIT:
MOV B, #0AH
DIV AB
XCH A, R6

MOV A, #020H
ADD A, B
MOV R0, A
MOV A, @R0
MOV @R1, A
INC R1

XCH A, R6
DJNZ R4, EXTRACT_NEXT_DIGIT
RET

END