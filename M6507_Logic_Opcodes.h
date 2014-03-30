/* 
 * File:   M6507_Logic_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 29 de Março de 2014, 21:06
 */

#ifndef M6507_LOGIC_OPCODES_H
#define	M6507_LOGIC_OPCODES_H

//Logic OPCODES
//AND

void M6507::AND_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr) & this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::AND_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X()) & this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::AND_absolute_Y(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->Y()) & this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::AND_imediate(char valor) {
    char nvalor = valor & this->A();
    this->A(nvalor);
    this->update_negative_flag(nvalor);
    this->update_zero_flag(nvalor);
}

void M6507::AND_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr) & this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::AND_zeropage_indirect_X(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->X()) + (this->MemoryRead(addr + 1 + this->X())*256);
    char valor = this->MemoryRead(destaddr) & this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::AND_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead(addr + this->X()) & this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::AND_zeropage_indirect_Y(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->Y()) + (this->MemoryRead(addr + 1 + this->Y())*256);
    char valor = this->MemoryRead(destaddr) & this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

//ORA
void M6507::ORA_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr) | this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ORA_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X()) | this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ORA_absolute_Y(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->Y()) | this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ORA_imediate(char valor) {
    char nvalor = valor | this->A();
    this->A(nvalor);
    this->update_negative_flag(nvalor);
    this->update_zero_flag(nvalor);
}

void M6507::ORA_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr) | this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ORA_zeropage_indirect_X(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->X()) + (this->MemoryRead(addr + 1 + this->X())*256);
    char valor = this->MemoryRead(destaddr) | this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ORA_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead(addr + this->X()) | this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::ORA_zeropage_indirect_Y(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->Y()) + (this->MemoryRead(addr + 1 + this->Y())*256);
    char valor = this->MemoryRead(destaddr) | this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}
//EOR
void M6507::EOR_absolute(unsigned short int addr) {
    char valor = this->MemoryRead(addr) ^ this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::EOR_absolute_X(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->X()) ^ this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::EOR_absolute_Y(unsigned short int addr) {
    char valor = this->MemoryRead(addr + this->Y()) ^ this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::EOR_imediate(char valor) {
    char nvalor = valor ^ this->A();
    this->A(nvalor);
    this->update_negative_flag(nvalor);
    this->update_zero_flag(nvalor);
}

void M6507::EOR_zeropage(unsigned char addr) {
    char valor = this->MemoryRead(addr) ^ this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::EOR_zeropage_indirect_X(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->X()) + (this->MemoryRead(addr + 1 + this->X())*256);
    char valor = this->MemoryRead(destaddr) ^ this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::EOR_zeropage_X(unsigned char addr) {
    char valor = this->MemoryRead(addr + this->X()) ^ this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}

void M6507::EOR_zeropage_indirect_Y(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->Y()) + (this->MemoryRead(addr + 1 + this->Y())*256);
    char valor = this->MemoryRead(destaddr) ^ this->A();
    this->A(valor);
    this->update_negative_flag(valor);
    this->update_zero_flag(valor);
}


#endif	/* M6507_LOGIC_OPCODES_H */

