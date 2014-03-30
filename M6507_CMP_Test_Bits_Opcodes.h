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

void M6507::CMP_absolute(unsigned short int addr) {
    char val1, val2, res;
    val1 = this->A();
    val2 = this->MemoryRead(addr);
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CMP_absolute_X(unsigned short int addr) {
    char val1, val2, res;
    val1 = this->A();
    val2 = this->MemoryRead(addr + this->X());
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CMP_absolute_Y(unsigned short int addr) {
    char val1, val2, res;
    val1 = this->A();
    val2 = this->MemoryRead(addr + this->Y());
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CMP_imediate(char valor) {
    char val1, val2, res;
    val1 = this->A();
    val2 = valor;
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CMP_zeropage(unsigned char addr) {
    char val1, val2, res;
    val1 = this->A();
    val2 = this->MemoryRead(addr);
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CMP_zeropage_indirect_X(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->X()) + (this->MemoryRead(addr + 1 + this->X())*256);
    char val1, val2, res;
    val1 = this->A();
    val2 = this->MemoryRead(destaddr);
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CMP_zeropage_X(unsigned char addr) {
    char val1, val2, res;
    val1 = this->A();
    val2 = this->MemoryRead(addr + this->X());
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CMP_zeropage_indirect_Y(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->X()) + (this->MemoryRead(addr + 1 + this->X())*256);
    char val1, val2, res;
    val1 = this->A();
    val2 = this->MemoryRead(destaddr);
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}
//CPX

void M6507::CPX_absolute(unsigned short int addr) {
    char val1, val2, res;
    val1 = this->X();
    val2 = this->MemoryRead(addr);
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CPX_imediate(char valor) {
    char val1, val2, res;
    val1 = this->X();
    val2 = valor;
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CPX_zeropage(unsigned char addr) {
    char val1, val2, res;
    val1 = this->X();
    val2 = this->MemoryRead(addr);
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}
//CPY

void M6507::CPY_absolute(unsigned short int addr) {
    char val1, val2, res;
    val1 = this->Y();
    val2 = this->MemoryRead(addr);
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CPY_imediate(char valor) {
    char val1, val2, res;
    val1 = this->Y();
    val2 = valor;
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}

void M6507::CPY_zeropage(unsigned char addr) {
    char val1, val2, res;
    val1 = this->Y();
    val2 = this->MemoryRead(addr);
    res = val1 - val2;
    this->update_zero_flag(res);
    if ((unsigned char) val1 < (unsigned char) val2)
        this->P_carry(false);
    else
        this->P_carry(true);
    this->P_negative(res & 7);
}
//BIT

void M6507::BIT_absolute(unsigned short int addr) {
    this->update_negative_flag(this->MemoryRead(addr));
    this->update_zero_flag(this->A() & this->MemoryRead(addr));
    this->P_overflow(this->MemoryRead(addr) &(1 << 6));
}

void M6507::BIT_imediate(char valor) {
    this->update_negative_flag(valor);
    this->update_zero_flag(this->A() & valor);
    this->P_overflow(valor & (1 << 6));
}

void M6507::BIT_zeropage(unsigned char addr) {
    this->update_negative_flag(this->MemoryRead(addr));
    this->update_zero_flag(this->A() & this->MemoryRead(addr));
    this->P_overflow(this->MemoryRead(addr) &(1 << 6));
}


#endif	/* M6507_CMP_TEST_BITS_OPCODES_H */

