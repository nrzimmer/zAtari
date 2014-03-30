/* 
 * File:   M6507_CMP_Test_Bits_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 30 de Março de 2014, 10:59
 */

#ifndef M6507_CMP_TEST_BITS_OPCODES_H
#define	M6507_CMP_TEST_BITS_OPCODES_H

//Compare and Test Bit
//CMP

void M6507::CMP(char val1, char val2) {
    char res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(get_bit(res, 7));
}

void M6507::CMP_absolute(unsigned short int addr) {
    this->CMP(this->A(), this->MemoryRead(addr));
}

void M6507::CMP_absolute_X(unsigned short int addr) {
    this->CMP(this->A(), this->MemoryRead(addr + this->X()));
}

void M6507::CMP_absolute_Y(unsigned short int addr) {
    this->CMP(this->A(), this->MemoryRead(addr + this->Y()));
}

void M6507::CMP_imediate(char valor) {
    this->CMP(this->A(), valor);
}

void M6507::CMP_zeropage(unsigned char addr) {
    this->CMP(this->A(), this->MemoryRead(addr));
}

void M6507::CMP_zeropage_indirect_X(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->X()) + (this->MemoryRead(addr + 1 + this->X())*256);
    this->CMP(this->A(), this->MemoryRead(destaddr));
}

void M6507::CMP_zeropage_X(unsigned char addr) {
    this->CMP(this->A(), this->MemoryRead(addr + this->X()));
}

void M6507::CMP_zeropage_indirect_Y(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->X()) + (this->MemoryRead(addr + 1 + this->X())*256);
    this->CMP(this->A(), this->MemoryRead(destaddr));
}
//CPX

void M6507::CPX_absolute(unsigned short int addr) {
    this->CMP(this->X(), this->MemoryRead(addr));
}

void M6507::CPX_imediate(char valor) {
    this->CMP(this->X(), valor);
}

void M6507::CPX_zeropage(unsigned char addr) {
    this->CMP(this->X(), this->MemoryRead(addr));
}
//CPY

void M6507::CPY_absolute(unsigned short int addr) {
    this->CMP(this->Y(), this->MemoryRead(addr));
}

void M6507::CPY_imediate(char valor) {
    this->CMP(this->Y(), valor);
}

void M6507::CPY_zeropage(unsigned char addr) {
    this->CMP(this->Y(), this->MemoryRead(addr));
}
//BIT

void M6507::BIT_absolute(unsigned short int addr) {
    this->update_negative_flag(this->MemoryRead(addr));
    this->update_zero_flag(this->A() & this->MemoryRead(addr));
    this->P_overflow(get_bit(this->MemoryRead(addr), 6));
}

void M6507::BIT_imediate(char valor) {
    this->update_negative_flag(valor);
    this->update_zero_flag(this->A() & valor);
    this->P_overflow(get_bit(valor, 6));
}

void M6507::BIT_zeropage(unsigned char addr) {
    this->update_negative_flag(this->MemoryRead(addr));
    this->update_zero_flag(this->A() & this->MemoryRead(addr));
    this->P_overflow(get_bit(this->MemoryRead(addr), 6));
}


#endif	/* M6507_CMP_TEST_BITS_OPCODES_H */

