/* 
 * File:   M6507_Inc_Dec_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 29 de Março de 2014, 13:21
 */

#ifndef M6507_INC_DEC_OPCODES_H
#define	M6507_INC_DEC_OPCODES_H

//Increment and Decrement OPCODES
//INC

void M6507::INC_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr);
    valor++;
    this->MemoryWrite(addr, valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::INC_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X());
    valor++;
    this->MemoryWrite(addr + this->X(), valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::INC_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr);
    valor++;
    this->MemoryWrite(addr, valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::INC_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead(addr + this->X());
    valor++;
    this->MemoryWrite(addr + this->X(), valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//INX

void M6507::INX() {
    char valor = this->X();
    valor++;
    this->X(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//INY

void M6507::INY() {
    char valor = this->Y();
    valor++;
    this->Y(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//DEC

void M6507::DEC_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr);
    valor--;
    this->MemoryWrite(addr, valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::DEC_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X());
    valor--;
    this->MemoryWrite(addr + this->X(), valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::DEC_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr);
    valor--;
    this->MemoryWrite(addr, valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::DEC_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead(addr + this->X());
    valor--;
    this->MemoryWrite(addr + this->X(), valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//DEX

void M6507::DEX() {
    char valor = this->X();
    valor--;
    this->X(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//DEY

void M6507::DEY() {
    char valor = this->Y();
    valor--;
    this->Y(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}


#endif	/* M6507_INC_DEC_OPCODES_H */

