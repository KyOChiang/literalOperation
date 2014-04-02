#ifndef __BYTECODE_H__
#define __BYTECODE_H__

typedef enum {
				ACCESS = -5,
				BANKED,
				F,
				W
			 }Operand;
			 
typedef enum {
				ANDLW,
				XORLW,
} Mnemonic;
//TBLRD**

typedef enum {
				NO_ERROR,
				ERR_INVALID_OPERAND1,
				ERR_INVALID_OPERAND2,
				ERR_INVALID_OPERAND3,
} ExceptionError;

typedef struct {
	Mnemonic mnemonic;
	char *name;
} Instruction;

typedef struct {
	Instruction instruction;
	int operand1;
	int operand2;
	int operand3;
} Bytecode;

#endif // __BYTECODE_H__