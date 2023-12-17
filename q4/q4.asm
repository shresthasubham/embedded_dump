	ORG 00H
START: 	MOV R5, #00H
	MOV 3EH, #0AFH
	MOV R1, #12H
	MOV A, 3EH
RESUB:	CLR C
	SUBB A, R1
	JC SK     
	INC R5
	AJMP RESUB
SK:   	ADD A, R1
        ;; R5 quotient
        ;; R4 remainder
        MOV R4, A
        MOV A, R5
	MOV P0, A
	ACALL DELAY
	MOV P0, R4
	ACALL DELAY
	SJMP START
        
DELAY: 	MOV R7, #7
HERE1: 	MOV R6, #1
HERE2: 	MOV R1, #2
HERE3: 	DJNZ R1, HERE3
	DJNZ R6, HERE3
	DJNZ R7, HERE3
	RET
	
	END