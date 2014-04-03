#ifndef _ANDLW_H_
#define _ANDLW_H_

#define WREG 0xFE8
#define STATUS 0xFDB

extern char FSR[];

void andlw(Bytecode *code);

#endif