#ifndef _XORLW_H_
#define _XORLW_H_

#define WREG 0xFE8
#define STATUS 0xFDB

extern char FSR[];

void xorlw(Bytecode *code);

#endif