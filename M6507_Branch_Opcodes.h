/* 
 * File:   M6507_Branch_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 30 de Março de 2014, 12:27
 */

#ifndef M6507_BRANCH_OPCODES_H
#define	M6507_BRANCH_OPCODES_H

//Branch OPCODES
//BCC

void M6507::BCC(char valor) {
    if (!this->P_carry())
        this->PC(this->PC() + valor);
}
//BCS

void M6507::BCS(char valor) {
    if (this->P_carry())
        this->PC(this->PC() + valor);
}
//BEQ

void M6507::BEQ(char valor) {
    if (this->P_zero())
        this->PC(this->PC() + valor);
}
//BMI

void M6507::BMI(char valor) {
    if (this->P_negative())
        this->PC(this->PC() + valor);
}
//BNE

void M6507::BNE(char valor) {
    if (!this->P_zero())
        this->PC(this->PC() + valor);
}
//BPL

void M6507::BPL(char valor) {
    if (!this->P_negative())
        this->PC(this->PC() + valor);
}
//BVC

void M6507::BVC(char valor) {
    if (!this->P_overflow())
        this->PC(this->PC() + valor);
}
//BVS

void M6507::BVS(char valor) {
    if (this->P_overflow())
        this->PC(this->PC() + valor);
}


#endif	/* M6507_BRANCH_OPCODES_H */

