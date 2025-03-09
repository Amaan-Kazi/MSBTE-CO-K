; ALP to check a given number is positive or negative
DATA SEGMENT
NUM DB 05H;
POSITIVE DB 00H; NUM is moved here if positive
NEGATIVE DB 00H; NUM is moved here if negative
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA;
START:
MOV AX, DATA;
MOV DS, AX;

MOV AL, NUM;
ROL AL, 01H; MSB (Sign Bit) is moved to carry

JNC POSNUM; Jump If Not Carry, if sign bit is 0 then positive
MOV BL, NUM;
MOV NEGATIVE, BL;
JMP ENDCODE;

POSNUM: MOV BL, NUM;
        MOV POSITIVE, BL;

ENDCODE: MOV AH, 4CH;
         INT 21H;
         CODE ENDS;
         END START;
