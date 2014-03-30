/* 
 * File:   M6507_Shit_Rotate_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 29 de Março de 2014, 18:41
 */

#ifndef M6507_SHIT_ROTATE_OPCODES_H
#define	M6507_SHIT_ROTATE_OPCODES_H

//Shit and Rotate OPCODES
//ASL

void M6507::ASL() {
    char valor = this->A();
    this->P_carry(valor & 7);
    valor = valor << 1;
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ASL_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr);
    this->P_carry(valor & 7);
    valor = valor << 1;
    this->MemoryWrite(addr, valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ASL_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X());
    this->P_carry(valor & 7);
    valor = valor << 1;
    this->MemoryWrite(addr + this->X(), valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ASL_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr);
    this->P_carry(valor & 7);
    valor = valor << 1;
    this->MemoryWrite(addr, valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ASL_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead(addr + this->X());
    this->P_carry(valor & 7);
    valor = valor << 1;
    this->MemoryWrite(addr + this->X(), valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//LSR

void M6507::LSR() {
    char valor = this->A();
    this->P_carry(valor & 1);
    valor = valor >> 1;
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LSR_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr);
    this->P_carry(valor & 1);
    valor = valor >> 1;
    this->MemoryWrite(addr, valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LSR_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X());
    this->P_carry(valor & 1);
    valor = valor >> 1;
    this->MemoryWrite(addr + this->X(), valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LSR_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr);
    this->P_carry(valor & 1);
    valor = valor >> 1;
    this->MemoryWrite(addr, valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LSR_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead(addr + this->X());
    this->P_carry(valor & 1);
    valor = valor >> 1;
    this->MemoryWrite(addr + this->X(), valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//ROL

void M6507::ROL() {
    char valor = this->A();
    bool c = valor & 7;
    valor = valor << 1;
    if (this->P_carry())
        valor |= (1 << 0);
    else
        valor &= ~(1 << 0);
    this->A(valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ROL_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr);
    bool c = valor & 7;
    valor = valor << 1;
    if (this->P_carry())
        valor |= (1 << 0);
    else
        valor &= ~(1 << 0);
    this->MemoryWrite(addr, valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ROL_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X());
    bool c = valor & 7;
    valor = valor << 1;
    if (this->P_carry())
        valor |= (1 << 0);
    else
        valor &= ~(1 << 0);
    this->MemoryWrite(addr + this->X(), valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ROL_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr);
    bool c = valor & 7;
    valor = valor << 1;
    if (this->P_carry())
        valor |= (1 << 0);
    else
        valor &= ~(1 << 0);
    this->MemoryWrite(addr, valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ROL_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead(addr + this->X());
    bool c = valor & 7;
    valor = valor << 1;
    if (this->P_carry())
        valor |= (1 << 0);
    else
        valor &= ~(1 << 0);
    this->MemoryWrite(addr + this->X(), valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//ROR

void M6507::ROR() {
    char valor = this->A();
    bool c = valor & 1;
    valor = valor >> 1;
    if (this->P_carry())
        valor |= (1 << 7);
    else
        valor &= ~(1 << 7);
    this->A(valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ROR_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr);
    bool c = valor & 1;
    valor = valor >> 1;
    if (this->P_carry())
        valor |= (1 << 7);
    else
        valor &= ~(1 << 7);
    this->MemoryWrite(addr, valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ROR_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X());
    bool c = valor & 1;
    valor = valor >> 1;
    if (this->P_carry())
        valor |= (1 << 7);
    else
        valor &= ~(1 << 7);
    this->MemoryWrite(addr + this->X(), valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ROR_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr);
    bool c = valor & 1;
    valor = valor >> 1;
    if (this->P_carry())
        valor |= (1 << 7);
    else
        valor &= ~(1 << 7);
    this->MemoryWrite(addr, valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ROR_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead(addr + this->X());
    bool c = valor & 1;
    valor = valor >> 1;
    if (this->P_carry())
        valor |= (1 << 7);
    else
        valor &= ~(1 << 7);
    this->MemoryWrite(addr + this->X(), valor);
    this->P_carry(c);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}


#endif	/* M6507_SHIT_ROTATE_OPCODES_H */

