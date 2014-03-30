/* 
 * File:   M6507_Store_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 28 de Março de 2014, 14:12
 */

#ifndef M6507_STORE_OPCODES_H
#define	M6507_STORE_OPCODES_H

//Store OPCODES
//STA

void M6507::STA_absolute(unsigned short int addr) {
    this->MemoryWrite(addr, this->A());
}

void M6507::STA_absolute_X(unsigned short int addr) {
    this->MemoryWrite(addr + this->X(), this->A());
}

void M6507::STA_absolute_Y(unsigned short int addr) {
    this->MemoryWrite(addr + this->Y(), this->A());
}

void M6507::STA_zeropage(unsigned char addr) {
    this->MemoryWrite(addr, this->A());
}

void M6507::STA_zeropage_indirect_X(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->X()) + (this->MemoryRead(addr + 1 + this->X())*256);
    this->MemoryWrite(destaddr, this->A());
}

void M6507::STA_zeropage_X(unsigned char addr) {
    this->MemoryWrite(addr + this->X(), this->A());
}

void M6507::STA_zeropage_indirect_Y(unsigned char addr) {
    unsigned short int destaddr;
    destaddr = this->MemoryRead(addr + this->Y()) + (this->MemoryRead(addr + 1 + this->Y())*256);
    this->MemoryWrite(destaddr, this->A());
}
//STX
void M6507::STX_absolute(unsigned short int addr) {
    this->MemoryWrite(addr,this->X());
}
void M6507::STX_zeropage(unsigned char addr) {
    this->MemoryWrite(addr,this->X());
}
void M6507::STX_zeropage_Y(unsigned char addr) {
        this->MemoryWrite(addr + this->Y(),this->X());
}
//STY
void M6507::STY_absolute(unsigned short int addr) {
    this->MemoryWrite(addr,this->Y());
}
void M6507::STY_zeropage(unsigned char addr) {
        this->MemoryWrite(addr,this->Y());
}
void M6507::STY_zeropage_X(unsigned char addr) {
        this->MemoryWrite(addr + this->X(),this->Y());
}

#endif	/* M6507_STORE_OPCODES_H */