		ORG 00H
START: MOV A, #9AH
	   ADD A, #48H
	   MOV P0, A
	   ACALL DELAY
	   MOV A, #7FH
	   ADDC A, #0BCH
	   MOV P0, A
	   ACALL DELAY
	   MOV A, #89H
	   ADDC A, #34H
	   MOV P0, A
	   ACALL DELAY
	   MOV A, #00H
	   RLC A
	   MOV P0, A
	   AJMP START
	

DELAY: 	MOV R7, #7
HERE1: 	MOV R6, #255
HERE2: 	MOV R5, #255
HERE3: 	DJNZ R5, HERE3
		DJNZ R6, HERE3
		DJNZ R7, HERE3
		RET
		
		END
		