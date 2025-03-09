; ALP to check a given number is odd or even
DATA SEGMENT
NUM DB 05H;
ODD DB 00H; NUM is moved here in case ODD
EVE DB 00H; NUM is moved here in case EVEN
DATA ENDS;

CODE SEGMENT
ASSUME CS:CODE, DS:DATA;
START:
MOV AX, DATA;
MOV DS, AX;

MOV AL, NUM;
ROR AL, 01H; LSB goes to carry, 1 = odd, 0 = even

JNC EVENUM; Jump If Not Carry: carry = 0 = odd
MOV BL, NUM;
MOV ODD, BL;
JMP ENDCODE;

EVENUM: MOV BL, NUM;
        MOV EVE, BL;

ENDCODE: MOV AH, 4CH;
         INT 21H;
         CODE ENDS;
         END START;
