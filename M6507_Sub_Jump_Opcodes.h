/* 
 * File:   M6507_Sub_Jump_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 30 de Março de 2014, 13:24
 */

#ifndef M6507_SUB_JUMP_OPCODES_H
#define	M6507_SUB_JUMP_OPCODES_H

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
    unsigned char lo,hi;
    hi = this->PC_H();
    lo = this->PC_L();
    this->push_stack(hi);
    this->push_stack(lo);
    this->PC(addr);
}
//RTS

void M6507::RTS() {
    unsigned char lo,hi;
    unsigned short int destaddr;
    lo = this->pop_stack();
    hi = this->pop_stack();
    destaddr = make_word(lo,hi);
    this->PC(destaddr);
}
//RTI
void M6507::RTI(){
    unsigned char lo,hi;
    unsigned short int destaddr;
    lo = this->pop_stack();
    hi = this->pop_stack();
    destaddr = make_word(lo,hi);
    this->PC(destaddr);
}


#endif	/* M6507_SUB_JUMP_OPCODES_H */

