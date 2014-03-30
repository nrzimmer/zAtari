/* 
 * File:   M6507_Transfer_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 30 de Março de 2014, 12:36
 */

#ifndef M6507_TRANSFER_OPCODES_H
#define	M6507_TRANSFER_OPCODES_H

//Transfer OPCODES
//TAX

void M6507::TAX() {
    this->X(this->A());
    this->update_negative_flag(this->X());
    this->update_zero_flag(this->X());
}
//TXA

void M6507::TXA() {
    this->A(this->X());
    this->update_negative_flag(this->A());
    this->update_zero_flag(this->A());
}
//TAY

void M6507::TAY() {
    this->Y(this->A());
    this->update_negative_flag(this->Y());
    this->update_zero_flag(this->Y());
}
//TYA

void M6507::TYA() {
    this->Y(this->A());
    this->update_negative_flag(this->A());
    this->update_zero_flag(this->A());
}
//TSX

void M6507::TSX() {
    this->X(this->S());
    this->update_negative_flag(this->X());
    this->update_zero_flag(this->X());
}
//TXS

void M6507::TXS() {
    this->S(this->X());
    this->update_negative_flag(this->S());
    this->update_zero_flag(this->S());
}


#endif	/* M6507_TRANSFER_OPCODES_H */

