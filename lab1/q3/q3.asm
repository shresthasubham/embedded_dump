		ORG 00H
START: 	MOV A, #00H
		MOV R3, #00H
		MOV 22H, #0FFH
		MOV 15H, #0DEH
		MOV R1, 22H
		MOV R0, 15H
READD:	ADD A, R1
		JNC SKIP
		INC R3
SKIP:	DJNZ R0, READD
		MOV 19H, A
		MOV P0, A
		ACALL DELAY
		MOV P0, R3
		MOV 1AH, R3
		ACALL DELAY
		SJMP START
		
DELAY: 	MOV R7, #7
HERE1: 	MOV R6, #255
HERE2: 	MOV R5, #255
HERE3: 	DJNZ R5, HERE3
		DJNZ R6, HERE3
		DJNZ R7, HERE3
		RET

		END 