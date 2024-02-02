ORG 00H
LJMP MAIN

ORG 0BH

INC OVERFLOW
MOV A, OVERFLOW
CJNE A, #0EH, last

INC SECONDS
MOV A, SECONDS
CJNE A, #3CH, clear_overflow
MOV SECONDS, #00H

INC MINUTES
MOV A, OVERFLOW
CJNE A, #3CH, clear_overflow
MOV MINUTES, #00H

clear_overflow:
MOV OVERFLOW, #00H

last:
RETI

MAIN: 
	ORG 30H
		
	SECONDS EQU 60H
	MINUTES EQU 61H
	OVERFLOW EQU 62H
		
	MOV SECONDS, #00H
	MOV MINUTES, #00H
	MOV OVERFLOW, #00H

	MOV TMOD, #01H
	MOV TL0, #00H
	MOV TL0, #00H
	MOV IE, #82H
	SETB TR0
	
	MOV DPTR, #BCD_CODE

DISPLAY:
	MOV R6, #05H
OUTER:
	MOV R7, #010H
INNER:
	MOV A, MINUTES
	LCALL SET_DISP
	
	MOVC A, @A+DPTR
	MOV P0, A
	MOV P2, #01H
	LCALL SDELAY
	MOV P2, #00H
	
	MOV A, B
	MOVC A, @A+DPTR
	ORL A, #80h
	MOV P0, A
	MOV P2, #02H
	LCALL SDELAY
	MOV P2, #00H
	
	MOV A, SECONDS
	LCALL SET_DISP
	
	MOVC A, @A+DPTR
	MOV P0, A
	MOV P2, #04H
	LCALL SDELAY
	MOV P2, #00H

	MOV A, B
	MOVC A, @A+DPTR
	MOV P0, A
	MOV P2, #08H
	LCALL SDELAY
	MOV P2, #00H

	DJNZ R7, INNER
	DJNZ R6, OUTER

SJMP DISPLAY

SET_DISP:
	MOV B, #0AH	
	DIV AB
RET
	
SDELAY:
	MOV R5, #018H
	SOUTER:
	MOV R4, #018H
	SINNER:
	DJNZ R4, SINNER
	DJNZ R5, SOUTER
RET

BCD_CODE: db 3FH, 06H, 5BH, 4FH, 66H, 6DH, 7DH, 07H, 7FH, 6FH
	
END