#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "ANDLW.h"

void setUp(){}
void tearDown(){}

void test_andlw_with_invalid_operand1_negative1_should_throw_exception(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and AND with -1
	Bytecode code = {.instruction = {.mnemonic = ANDLW, .name = "andlw"},
					 .operand1 = -1,
					 .operand2 = -1,
					 .operand3 = -1
					 };
	
	FSR[WREG] = 0xB5;
	Try{
		andlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xB5,FSR[WREG]);

}

void test_andlw_with_invalid_operand1_256_should_throw_exception(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and AND with 256
	Bytecode code = {.instruction = {.mnemonic = ANDLW, .name = "andlw"},
					 .operand1 = 256,
					 .operand2 = -1,
					 .operand3 = -1
					 };
	
	FSR[WREG] = 0xB5;
	Try{
		andlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xB5,FSR[WREG]);

}

void test_andlw_with_valid_operand1_0x5A_should_xor_to_WREG_return_0x10(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and AND with 0x0A
	Bytecode code = {.instruction = {.mnemonic = ANDLW, .name = "andlw"},
					 .operand1 = 0x5A,
					 .operand2 = -1,
					 .operand3 = -1
					 };
	
	FSR[WREG] = 0xB5;
	//01011010 -> 5A
	//10110101 -> B5
	//00010000 -> 10
	
	Try{
		andlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0x10,FSR[WREG]);

}

