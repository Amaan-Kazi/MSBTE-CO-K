DATA SEGMENT
ARRAY DB 09H, 18H, 02H, 04H, 36H
LARGEST DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
MOV AX, DATA
MOV DS, AX

MOV CL, 04H;   Counter
LEA SI, ARRAY; Load Effective Address
MOV AL, [SI];  AL will store the largest number

CMPLOOP: INC SI;       Increment SI to go the next index of array
         CMP AL, [SI]; AL-[SI] Result not stored anywhere, only flags affected
         JNC NEXT;     Jump if carry != 0. ie. AL < SI
         MOV AL, [SI]; Only executes if AL > SI

   NEXT: DEC CL;      Decrement Counter
         JNZ CMPLOOP; Jump if counter (zero flag from prev instruction) != 0

MOV LARGEST, AL; At the end AL has the smallest number

MOV AH, 4CH
INT 21H
CODE ENDS
END START
