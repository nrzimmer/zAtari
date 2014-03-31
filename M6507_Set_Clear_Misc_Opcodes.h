/* 
 * File:   M6507_Set_Clear_Misc_Opcodes.h
 * Author: NatanaelRodrigo
 *
 * Created on 30 de Março de 2014, 14:05
 */

#ifndef M6507_SET_CLEAR_MISC_OPCODES_H
#define	M6507_SET_CLEAR_MISC_OPCODES_H

//Set and Clear OPCODES
//SEC
void M6507::SEC() {
    this->P_carry(true);
}
//SED
void M6507::SED() {
    this->P_decimal_mode(true);
}
//SEI
void M6507::SEI() {
    this->P_irq_disable(true);
}
//CLC
void M6507::CLC() {
    this->P_carry(false);
}
//CLD
void M6507::CLD() {
    this->P_decimal_mode(false);
}
//CLI
void M6507::CLI() {
    this->P_irq_disable(false);
}
//CLV
void M6507::CLV() {
    this->P_overflow(false);
}

//Misc OPCODES
//NOP
void M6507::NOP(){
    //NOPE
}
//BRK
void M6507::BRK(){
    this->P_brk_command(true);
}

#endif	/* M6507_SET_CLEAR_MISC_OPCODES_H */

