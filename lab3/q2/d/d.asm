ORG 00H
;to make the signal correct no loops are used
MAIN:
SETB P0.0 
LCALL DELAY_10MS
LCALL DELAY_10MS
LCALL DELAY_10MS
LCALL DELAY_10MS
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
LCALL DELAY_10MS
LCALL DELAY_10MS
LCALL DELAY_10MS
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
CPL P0.0
LCALL DELAY_10MS
SJMP MAIN

DELAY_10MS:
MOV TMOD, #03H 
MOV TH0, #064H
SETB TR0
MOV R3, #24H
AGAIN: JNB TF0, AGAIN
	CLR TF0
	MOV TH0, #039H 
DJNZ R3, AGAIN
CLR TR0
CLR TF0
RET

END