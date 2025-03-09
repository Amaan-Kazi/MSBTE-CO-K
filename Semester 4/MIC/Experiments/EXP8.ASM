DATA SEGMENT
ARRAY DB 0AH, 14H, 1EH, 28H, 32H; 10, 20, 30, 40, 50
SUM   DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
MOV AX, DATA
MOV DS, AX

MOV AL, 00H;   Initializing AL to 0
MOV CX, 0005H; Counter always on CX for LOOP instruction, run loop 5 times
LEA SI, ARRAY; Load Effective (Starting) Address of ARRAY

ADDLOOP: MOV BL, [SI]; Load value from address SI into BL
         ADD AL, BL;   Add AL and BL, store in AL
         INC SI;       Increment SI (address of index in array)
         LOOP ADDLOOP; Decrement CX and if != 0, then go to ADDLOOP

MOV SUM, AL
MOV AH,  4CH
INT 21H
CODE ENDS
END START


