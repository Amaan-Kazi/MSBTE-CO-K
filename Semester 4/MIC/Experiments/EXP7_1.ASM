; EXP7_1: Block Transfer using string instruction

DATA SEGMENT
BLOCK1 DB 10 DUP(10); Array of 10 bytes containing value 10
BLOCK2 DB 10 DUP(0);  Array of 10 bytes containing value 0
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
MOV AX, DATA
MOV DS, AX
MOV ES, AX

; Load Effective Address of Block 1 and Block 2
LEA SI, BLOCK1; Source Index -> BLOCK1
LEA DI, BLOCK2; Destination Index -> BLOCK2
MOV AL, 00H;    Initialize AL to 0
MOV CX, 000AH;  Counter = 10

CLD; Clear Direction Flag (DF)
REP MOVSB; REP (Repeat) decrements CX and repeats as long as != 0
         ; MOVSB = Move String Byte
         ; WHEN DF is 0, SI and DI are incremented automatically

MOV AH, 4CH
INT 21H
CODE ENDS
END START
