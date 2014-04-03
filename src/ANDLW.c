#include <stdio.h>
#include "Bytecode.h"
#include "ANDLW.h"

char FSR[0x1000];

void andlw(Bytecode *code){

	if((code->operand1<=255)&&(code->operand1>=0)){
		FSR[WREG] = FSR[WREG] & code->operand1;
	}
	else
		Throw(ERR_INVALID_OPERAND1);
	
}