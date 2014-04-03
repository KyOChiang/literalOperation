#include <stdio.h>
#include "Bytecode.h"
#include "ANDLW.h"

char FSR[0x1000];

void andlw(Bytecode *code){

	if(code->operand2 != -1)
		Throw(ERR_INVALID_OPERAND2);
	if(code->operand3 != -1)
		Throw(ERR_INVALID_OPERAND3);

	if((code->operand1<=255)&&(code->operand1>=0)){
		FSR[WREG] = FSR[WREG] & code->operand1;
		if(FSR[WREG] < 0)
			FSR[STATUS] = 0x10;	// - - - N OV Z DC C
		else if(FSR[WREG] == 0x00)
			FSR[STATUS] = 0x04;
		else
			FSR[STATUS] = 0x00;
		
	}
	else
		Throw(ERR_INVALID_OPERAND1);
	
}