/* 
 * File:   M6507_Stack_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 30 de Março de 2014, 13:04
 */

#ifndef M6507_STACK_OPCODES_H
#define	M6507_STACK_OPCODES_H

//Stack OPCODES
//PHA

void M6507::PHA() {
    this->MemoryWrite(256 + this->S(), this->A());
    if (this->S() == 0)
        this->S(255);
    else
        this->S(this->S() - 1);
}
//PLA

void M6507::PLA() {
    if (this->S() == 255)
        this->S(0);
    else
        this->S(this->S() + 1);
    this->A(this->MemoryRead(256 + this->S()));
}
//PHP

void M6507::PHP() {
    this->MemoryWrite(256 + this->S(), this->P());
    if (this->S() == 0)
        this->S(255);
    else
        this->S(this->S() - 1);
}
//PLP

void M6507::PLP() {
    if (this->S() == 255)
        this->S(0);
    else
        this->S(this->S() + 1);
    this->P(this->MemoryRead(256 + this->S()));
}


#endif	/* M6507_STACK_OPCODES_H */

