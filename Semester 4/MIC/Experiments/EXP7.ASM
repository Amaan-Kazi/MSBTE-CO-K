; EXP7: Block Transfer without string instruction

DATA SEGMENT
BLOCK1 DB 10 DUP(10); Array of 10 bytes containing value 10
BLOCK2 DB 10 DUP(0);  Array of 10 bytes containing value 0
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
MOV AX, DATA
MOV DS, AX

; Load Effective Addresses of Block 1 and Block 2
LEA SI, BLOCK1; Source Index -> BLOCK1
LEA DI, BLOCK2; Destination Index -> BLOCK2
MOV AL, 00H;    Initialize AL to 0
MOV CX, 000AH;  Counter = 10

MOVLOOP: MOV AL, [SI]; Move Value in Source Index to AL
         MOV [DI], AL; Move value in AL to Destination Index

         INC SI; Increment Source Index
         INC DI; Increment Destination Index

         LOOP MOVLOOP; Decrements Counter (CX) and jumps to label if != 0

MOV AH, 4CH
INT 21H
CODE ENDS
END START
