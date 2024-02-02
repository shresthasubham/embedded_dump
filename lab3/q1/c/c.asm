ORG 00H

MAIN:
SETB P2.0 
LCALL DELAY
CLR P2.0
LCALL DELAY
LCALL DELAY
LCALL DELAY
LCALL DELAY
SJMP MAIN

;C code has detailed implementation

DELAY:
MOV TMOD, #20H
MOV TH1, #03CH 
MOV TL1, #0F8H
SETB TR1
MOV R3, #0FH
AGAIN: JNB TF1, AGAIN
	CLR TF1
DJNZ R3, AGAIN
CLR TR1
CLR Tf1
RET

END