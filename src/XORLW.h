#ifndef _XORLW_H_
#define _XORLW_H_

#define WREG 0xFE8
#define STATUS 0xFDB

extern char FSR[];

int xorlw(Bytecode *code);

#endif