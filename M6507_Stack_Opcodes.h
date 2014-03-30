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
    this->push_stack(this->A());
}
//PLA

void M6507::PLA() {
    this->A(this->pop_stack());
}
//PHP

void M6507::PHP() {
    this->push_stack(this->P());
}
//PLP

void M6507::PLP() {
    this->P(this->pop_stack());
}


#endif	/* M6507_STACK_OPCODES_H */

