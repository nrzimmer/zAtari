/* 
 * File:   M6507_Sub_Jump_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 30 de Março de 2014, 13:24
 */

#ifndef M6507_SUB_JUMP_OPCODES_H
#define	M6507_SUB_JUMP_OPCODES_H

#include "M6507.h"


//Subroutine and Jump OPCODE
//JMP

void M6507::JMP(unsigned short int addr) {
    this->PC(addr);
}

void M6507::JMP_indirect(unsigned short int addr) {
    unsigned short int destaddr = this->MemoryRead(addr) + (256 * this->MemoryRead(addr + 1));
    this->PC(destaddr);
}
//JSR

void M6507::JSR(unsigned short int addr) {
    this->MemoryWrite(256 + this->S(), this->PC_H());
    if (this->S() == 0)
        this->S(255);
    else
        this->S(this->S() - 1);
    this->MemoryWrite(256 + this->S(), this->PC_L());
    if (this->S() == 0)
        this->S(255);
    else
        this->S(this->S() - 1);
    this->PC(addr);
}
//RTS

void M6507::RTS() {
    unsigned char lo;
    if (this->S() == 255)
        this->S(0);
    else
        this->S(this->S() + 1);
    lo = this->MemoryRead(256 + this->S());
    if (this->S() == 255)
        this->S(0);
    else
        this->S(this->S() + 1);
    this->PC(lo,this->MemoryRead(256 + this->S()));
    this->PC(this->PC() + 1);
}
//RTI
void M6507::RTI(){
    if (this->S() == 255)
        this->S(0);
    else
        this->S(this->S() + 1);
    this->P(this->MemoryRead(256 + this->S()));
    unsigned char lo;
    if (this->S() == 255)
        this->S(0);
    else
        this->S(this->S() + 1);
    lo = this->MemoryRead(256 + this->S());
    if (this->S() == 255)
        this->S(0);
    else
        this->S(this->S() + 1);
    this->PC(lo,this->MemoryRead(256 + this->S()));
}


#endif	/* M6507_SUB_JUMP_OPCODES_H */

