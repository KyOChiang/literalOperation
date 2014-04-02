#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "XORLW.h"

void setUp(){}
void tearDown(){}

void test_xorlw_with_invalid_operand1_negative1_should_throw_exception(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and XOR with -1
	Bytecode code = {.instruction = {.mnemonic = XORLW, .name = "xorlw"},
					 .operand1 = -1,
					 .operand2 = -1,
					 .operand3 = -1
					 };
	
	FSR[WREG] = 0xB5;
	Try{
		xorlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xB5,FSR[WREG]);

}

void test_xorlw_with_invalid_operand1_256_should_throw_exception(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and XOR with 256
	Bytecode code = {.instruction = {.mnemonic = XORLW, .name = "xorlw"},
					 .operand1 = 256,
					 .operand2 = -1,
					 .operand3 = -1
					 };
	
	FSR[WREG] = 0xB5;
	Try{
		xorlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xB5,FSR[WREG]);

}

void test_xorlw_with_valid_operand1_0x0A_should_xor_to_WREG_return_0xBF(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and XOR with 0x0A
	Bytecode code = {.instruction = {.mnemonic = XORLW, .name = "xorlw"},
					 .operand1 = 0x0A,
					 .operand2 = -1,
					 .operand3 = -1
					 };
	
	FSR[WREG] = 0xB5;
	//00001010 -> 0A
	//10110101 -> B5
	//10111111 -> BF
	
	Try{
		xorlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xBF,FSR[WREG]);

}

void test_xorlw_with_non_empty_operand2_0x0A_should_throw_exception(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and XOR with 0x0A
	//-1 represent empty
	Bytecode code = {.instruction = {.mnemonic = XORLW, .name = "xorlw"},
					 .operand1 = 0x0A,
					 .operand2 = 0,
					 .operand3 = -1
					 };
	
	FSR[WREG] = 0xB5;
	//00001010 -> 0A
	//10110101 -> B5
	//10111111 -> BF
	
	Try{
		xorlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND2,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xB5,FSR[WREG]);

}

void test_xorlw_with_non_empty_operand2_F_0x0A_should_throw_exception(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and XOR with 0x0A
	//-1 represent empty
	Bytecode code = {.instruction = {.mnemonic = XORLW, .name = "xorlw"},
					 .operand1 = 0x0A,
					 .operand2 = F,
					 .operand3 = -1
					 };
	
	FSR[WREG] = 0xB5;
	//00001010 -> 0A
	//10110101 -> B5
	//10111111 -> BF
	
	Try{
		xorlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND2,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xB5,FSR[WREG]);

}

void test_xorlw_with_non_empty_operand2_W_0x0A_should_throw_exception(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and XOR with 0x0A
	//-1 represent empty
	Bytecode code = {.instruction = {.mnemonic = XORLW, .name = "xorlw"},
					 .operand1 = 0x0A,
					 .operand2 = W,
					 .operand3 = -1
					 };
	
	FSR[WREG] = 0xB5;
	//00001010 -> 0A
	//10110101 -> B5
	//10111111 -> BF
	
	Try{
		xorlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND2,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xB5,FSR[WREG]);

}

void test_xorlw_with_non_empty_operand3_BANKED_0x0A_should_throw_exception(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and XOR with 0x0A
	Bytecode code = {.instruction = {.mnemonic = XORLW, .name = "xorlw"},
					 .operand1 = 0x0A,
					 .operand2 = -1,
					 .operand3 = BANKED
					 };
	
	FSR[WREG] = 0xB5;
	//00001010 -> 0A
	//10110101 -> B5
	//10111111 -> BF
	
	Try{
		xorlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND3,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xB5,FSR[WREG]);

}

void test_xorlw_with_non_empty_operand3_ACCESS_0x0A_should_throw_exception(){
	CEXCEPTION_T operandERR;
	
	//Test fixture
	//Initialize WREG with B5h and XOR with 0x0A
	Bytecode code = {.instruction = {.mnemonic = XORLW, .name = "xorlw"},
					 .operand1 = 0x0A,
					 .operand2 = -1,
					 .operand3 = ACCESS
					 };
	
	FSR[WREG] = 0xB5;
	//00001010 -> 0A
	//10110101 -> B5
	//10111111 -> BF
	
	Try{
		xorlw(&code);
	} Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND3,operandERR);
	}
	
	TEST_ASSERT_EQUAL_HEX8(0xB5,FSR[WREG]);

}
