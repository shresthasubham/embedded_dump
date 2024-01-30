	ORG 00H
START:	
	MOV 50H, #0D6H
	MOV 51H, #0F2H
    MOV 52H, #0E4H
	MOV 53H, #0A8H
	MOV 54H, #0CEH
	MOV 55H, #0B9H
	MOV 56H, #0FAH
	MOV 57H, #0AEH
	MOV 58H, #0BAH
	MOV 59H, #0CCH
	MOV R1, #050H
	MOV R2, #00H	;largest value
	MOV R3, #0FFH	;smallest value
	MOV R4, #10
CHECK:	MOV A, @R1
	CLR C
	SUBB A, R2
	JC NOTLARGE
	MOV A, @R1
	MOV R2, A
NOTLARGE:	MOV A, @R1
	CLR C
	SUBB A, R3
	JNC NOTSMALL
	MOV A, @R1
	MOV R3, A
NOTSMALL:	INC R1
	DJNZ R4, CHECK
	MOV A, R2
	MOV P0, A
	ACALL DELAY
	MOV A, R3
	MOV P0, A
	ACALL DELAY
	SJMP START
	
DELAY: 	MOV R7, #7
HERE1: 	MOV R6, #25
HERE2: 	MOV R1, #25
HERE3: 	DJNZ R1, HERE3
	DJNZ R6, HERE3
	DJNZ R7, HERE3
	RET
	
	END