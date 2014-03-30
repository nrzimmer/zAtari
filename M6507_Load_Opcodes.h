/* 
 * File:   M6507_Load_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 28 de Março de 2014, 13:25
 */
#ifndef M6507_LOAD_OPCODES_H
#define	M6507_LOAD_OPCODES_H

//Load OPCODES
//LDA

void M6507::LDA_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr);
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDA_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X());
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDA_absolute_Y(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->Y());
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDA_imediate(char valor) {
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDA_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr);
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDA_zeropage_indirect_X(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->X()) + (this->MemoryRead(addr + 1 + this->X())*256);
    char valor = this->MemoryRead(destaddr);
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDA_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead((short int) addr + (short int) this->X());
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDA_zeropage_indirect_Y(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->Y()) + (this->MemoryRead(addr + 1 + this->Y())*256);
    char valor = this->MemoryRead(destaddr);
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

//LDX

void M6507::LDX_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr);
    this->X(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDX_absolute_Y(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->Y());
    this->X(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDX_imediate(char valor) {
    this->X(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDX_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr);
    this->X(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDX_zeropage_Y(unsigned char addr) {
    char valor = this->MemoryRead((short int) addr + (short int) this->Y());
    this->X(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//LDY

void M6507::LDY_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr);
    this->Y(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDY_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X());
    this->Y(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDY_imediate(char valor) {
    this->Y(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDY_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr);
    this->Y(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::LDY_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead((short int) addr + (short int) this->X());
    this->Y(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

#endif	/* M6507_LOAD_OPCODES_H */

