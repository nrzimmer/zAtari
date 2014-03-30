/* 
 * File:   M6507_Arithmetic_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 28 de Março de 2014, 19:42
 */

#ifndef M6507_ARITHMETIC_OPCODES_H
#define	M6507_ARITHMETIC_OPCODES_H

//Arithmetic OPCODES
//ADC

void M6507::ADC_absolute(unsigned short int addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc + this->MemoryRead(addr) + (int) this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc += this->MemoryRead(addr) + (int) this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::ADC_absolute_X(unsigned short int addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc + this->MemoryRead(addr + this->X()) + (int) this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc += this->MemoryRead(addr + this->X()) + (int) this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::ADC_absolute_Y(unsigned short int addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc + this->MemoryRead(addr + this->Y()) + (int) this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc += this->MemoryRead(addr + this->Y()) + (int) this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::ADC_imediate(char valor) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc + valor + (int) this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc += valor + (int) this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::ADC_zeropage(unsigned char addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc + this->MemoryRead(addr) + (int) this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc += this->MemoryRead(addr) + (int) this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::ADC_zeropage_indirect_X(unsigned char addr) {
    short int destaddr;
    destaddr = this->MemoryRead(this->X() + addr) + (256 * this->MemoryRead(this->X() + addr + 1));
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc + this->MemoryRead(destaddr) + (int) this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc += this->MemoryRead(destaddr) + (int) this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::ADC_zeropage_X(unsigned char addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc + this->MemoryRead(addr + this->X()) + (int) this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc += this->MemoryRead(addr + this->X()) + (int) this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::ADC_zeropage_indirect_Y(unsigned char addr) {
    short int destaddr;
    destaddr = this->MemoryRead(this->Y() + addr) + (256 * this->MemoryRead(this->Y() + addr + 1));
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc + this->MemoryRead(destaddr) + (int) this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc += this->MemoryRead(destaddr) + (int) this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}
//SBC

void M6507::SBC_absolute(unsigned short int addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc - this->MemoryRead(addr) - (int) !this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc -= this->MemoryRead(addr) - (int) !this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::SBC_absolute_X(unsigned short int addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc - this->MemoryRead(addr + this->X()) - (int) !this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc -= this->MemoryRead(addr + this->X()) - (int) !this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::SBC_absolute_Y(unsigned short int addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc - this->MemoryRead(addr + this->Y()) - (int) !this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc -= this->MemoryRead(addr + this->Y()) - (int) !this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::SBC_imediate(char valor) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc - valor - (int) !this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc -= valor - (int) !this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::SBC_zeropage(unsigned char addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc - this->MemoryRead(addr) - (int) !this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc -= this->MemoryRead(addr) - (int) !this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::SBC_zeropage_indirect_X(unsigned char addr) {
    short int destaddr;
    destaddr = this->MemoryRead(this->X() + addr) + (256 * this->MemoryRead(this->X() + addr + 1));
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc - this->MemoryRead(destaddr) - (int) !this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc -= this->MemoryRead(destaddr) - (int) !this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::SBC_zeropage_X(unsigned char addr) {
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc - this->MemoryRead(addr + this->X()) - (int) !this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc -= this->MemoryRead(addr + this->X()) - (int) !this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}

void M6507::SBC_zeropage_indirect_Y(unsigned char addr) {
    short int destaddr;
    destaddr = this->MemoryRead(this->Y() + addr) + (256 * this->MemoryRead(this->Y() + addr + 1));
    char Acc = this->A();
    short int IAcc;
    IAcc = Acc - this->MemoryRead(destaddr) - (int) !this->P_carry();
    this->update_carry_flag(IAcc);
    this->update_overflow_flag(IAcc);
    Acc -= this->MemoryRead(destaddr) - (int) !this->P_carry();
    this->A(Acc);
    this->update_negative_flag(Acc);
    this->update_zero_flag(Acc);
}


#endif	/* M6507_ARITHMETIC_OPCODES_H */

