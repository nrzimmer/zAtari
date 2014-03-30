/* 
 * File:   M6507.h
 * Author: NatanaelRodrigo
 *
 * Created on 27 de Março de 2014, 15:10
 */

#ifndef M6507_H
#define	M6507_H9

#define v_carry 1;
#define v_zero 2;
#define v_irq_disable 4;
#define v_decimal_mode 8;
#define v_brk_command 16;
#define v_overflow 64;
#define v_negative 128;

class M6507 {
protected:
    //Variaveis dos registradores
    bool reg_carry;
    bool reg_zero;
    bool reg_irq_disable;
    bool reg_decimal_mode;
    bool reg_brk_command;
    bool reg_overflow;
    bool reg_negative;
    char reg_a;
    char reg_y;
    char reg_x;
    unsigned char reg_s;
    unsigned char reg_pc_l;
    unsigned char reg_pc_h;
    char reg_p;
    unsigned short int reg_pc;
    //memoria total 64K (para leitura)
    //char memory[2^16];
    //bloco de 8K de memoria (para replicação)
    char memory_block[2^13];
    
    //Metodos genericos usados internamente
    void update_zero_flag(char valor);
    void update_negative_flag(char valor);
    void update_overflow_flag(short int valor);
    void update_carry_flag(short int valor);
    void push_stack(char valor);
    char pop_stack();
    void ADC(char valor);
    void SBC(char valor);
    void CMP(char val1, char val2);
public:
    //Metodos de manipulação da memória
    char MemoryRead(unsigned short int addr);
    void MemoryWrite(unsigned short int addr, char valor);

    //Metodos para ler os valores dos registradores
    bool P_carry();
    bool P_zero();
    bool P_irq_disable();
    bool P_decimal_mode();
    bool P_brk_command();
    bool P_overflow();
    bool P_negative();
    char A();
    char Y();
    char X();
    char S();
    char P();
    unsigned short int PC();
    unsigned char PC_H();
    unsigned char PC_L();

    //Metodos para alterar os valores dos registradores
    void P_carry(bool valor);
    void P_zero(bool valor);
    void P_irq_disable(bool valor);
    void P_decimal_mode(bool valor);
    void P_brk_command(bool valor);
    void P_overflow(bool valor);
    void P_negative(bool valor);
    void P(char valor);
    void A(char valor);
    void Y(char valor);
    void X(char valor);
    void S(char valor);
    void PC(char valor_l, char valor_h);
    void PC(short int valor);

    //Load OPCODES
    //LDA
    void LDA_absolute(unsigned short int addr); //AD
    void LDA_absolute_X(unsigned short int addr); //BD
    void LDA_absolute_Y(unsigned short int addr); //B9
    void LDA_imediate(char valor); //A9
    void LDA_zeropage(unsigned char addr); //A5
    void LDA_zeropage_indirect_X(unsigned char addr); //A1
    void LDA_zeropage_X(unsigned char addr); //B5
    void LDA_zeropage_indirect_Y(unsigned char addr); //B1
    //LDX
    void LDX_absolute(unsigned short int addr); //AE
    void LDX_absolute_Y(unsigned short int addr); //BE
    void LDX_imediate(char valor); //A2
    void LDX_zeropage(unsigned char addr); //A6
    void LDX_zeropage_Y(unsigned char addr); //B6
    //LDY
    void LDY_absolute(unsigned short int addr); //AC
    void LDY_absolute_X(unsigned short int addr); //BC
    void LDY_imediate(char valor); //A0
    void LDY_zeropage(unsigned char addr); //A4
    void LDY_zeropage_X(unsigned char addr); //B4

    //Store OPCODES
    //STA
    void STA_absolute(unsigned short int addr); //8D
    void STA_absolute_X(unsigned short int addr); //9D
    void STA_absolute_Y(unsigned short int addr); //99
    void STA_zeropage(unsigned char addr); //85
    void STA_zeropage_indirect_X(unsigned char addr); //81
    void STA_zeropage_X(unsigned char addr); //95
    void STA_zeropage_indirect_Y(unsigned char addr); //91
    //STX
    void STX_absolute(unsigned short int addr); //8E
    void STX_zeropage(unsigned char addr); //86
    void STX_zeropage_Y(unsigned char addr); //96
    //STY
    void STY_absolute(unsigned short int addr); //8C
    void STY_zeropage(unsigned char addr); //84
    void STY_zeropage_X(unsigned char addr); //94

    //Arithmetic OPCODES
    //ADC
    void ADC_absolute(unsigned short int addr); //6D
    void ADC_absolute_X(unsigned short int addr); //7D
    void ADC_absolute_Y(unsigned short int addr); //79
    void ADC_imediate(char valor); //69
    void ADC_zeropage(unsigned char addr); //65
    void ADC_zeropage_indirect_X(unsigned char addr); //61
    void ADC_zeropage_X(unsigned char addr); //75
    void ADC_zeropage_indirect_Y(unsigned char addr); //71
    //SBC
    void SBC_absolute(unsigned short int addr); //ED
    void SBC_absolute_X(unsigned short int addr); //FD
    void SBC_absolute_Y(unsigned short int addr); //F9
    void SBC_imediate(char valor); //E9
    void SBC_zeropage(unsigned char addr); //E5
    void SBC_zeropage_indirect_X(unsigned char addr); //E1
    void SBC_zeropage_X(unsigned char addr); //F5
    void SBC_zeropage_indirect_Y(unsigned char addr); //F1

    //Increment and Decrement OPCODES
    //INC
    void INC_absolute(unsigned short int addr); //EE
    void INC_absolute_X(unsigned short int addr); //FE
    void INC_zeropage(unsigned char addr); //E6
    void INC_zeropage_X(unsigned char addr); //F6
    //INX
    void INX(); //E8
    //INY
    void INY(); //C8
    //DEC
    void DEC_absolute(unsigned short int addr); //CE
    void DEC_absolute_X(unsigned short int addr); //DE
    void DEC_zeropage(unsigned char addr); //C6
    void DEC_zeropage_X(unsigned char addr); //D6
    //DEX
    void DEX(); //CA
    //DEY
    void DEY(); //88

    //Shit and Rotate OPCODES
    //ASL
    void ASL(); //0A
    void ASL_absolute(unsigned short int addr); //0E
    void ASL_absolute_X(unsigned short int addr); //1E
    void ASL_zeropage(unsigned char addr); //06
    void ASL_zeropage_X(unsigned char addr); //16
    //LSR
    void LSR(); //4A
    void LSR_absolute(unsigned short int addr); //4E
    void LSR_absolute_X(unsigned short int addr); //5E
    void LSR_zeropage(unsigned char addr); //46
    void LSR_zeropage_X(unsigned char addr); //56
    //ROL
    void ROL(); //2A
    void ROL_absolute(unsigned short int addr); //2E
    void ROL_absolute_X(unsigned short int addr); //3E
    void ROL_zeropage(unsigned char addr); //26
    void ROL_zeropage_X(unsigned char addr); //36
    //ROR
    void ROR(); //6A
    void ROR_absolute(unsigned short int addr); //6E
    void ROR_absolute_X(unsigned short int addr); //7E
    void ROR_zeropage(unsigned char addr); //66
    void ROR_zeropage_X(unsigned char addr); //76

    //Logic OPCODES
    //AND
    void AND_absolute(unsigned short int addr); //2D
    void AND_absolute_X(unsigned short int addr); //3D
    void AND_absolute_Y(unsigned short int addr); //39
    void AND_imediate(char valor); //29
    void AND_zeropage(unsigned char addr); //25
    void AND_zeropage_indirect_X(unsigned char addr); //21
    void AND_zeropage_X(unsigned char addr); //35
    void AND_zeropage_indirect_Y(unsigned char addr); //31
    //ORA
    void ORA_absolute(unsigned short int addr); //0D
    void ORA_absolute_X(unsigned short int addr); //1D
    void ORA_absolute_Y(unsigned short int addr); //19
    void ORA_imediate(char valor); //09
    void ORA_zeropage(unsigned char addr); //05
    void ORA_zeropage_indirect_X(unsigned char addr); //01
    void ORA_zeropage_X(unsigned char addr); //15
    void ORA_zeropage_indirect_Y(unsigned char addr); //11
    //EOR
    void EOR_absolute(unsigned short int addr); //4D
    void EOR_absolute_X(unsigned short int addr); //5D
    void EOR_absolute_Y(unsigned short int addr); //49
    void EOR_imediate(char valor); //59
    void EOR_zeropage(unsigned char addr); //45
    void EOR_zeropage_indirect_X(unsigned char addr); //51
    void EOR_zeropage_X(unsigned char addr); //45
    void EOR_zeropage_indirect_Y(unsigned char addr); //51

    //Compare and Test Bit
    //CMP
    void CMP_absolute(unsigned short int addr); //CD
    void CMP_absolute_X(unsigned short int addr); //DD
    void CMP_absolute_Y(unsigned short int addr); //D9
    void CMP_imediate(char valor); //C9
    void CMP_zeropage(unsigned char addr); //C5
    void CMP_zeropage_indirect_X(unsigned char addr); //C1
    void CMP_zeropage_X(unsigned char addr); //D5
    void CMP_zeropage_indirect_Y(unsigned char addr); //D1
    //CPX
    void CPX_absolute(unsigned short int addr); //EC
    void CPX_imediate(char valor); //E0
    void CPX_zeropage(unsigned char addr); //E4
    //CPY
    void CPY_absolute(unsigned short int addr); //CC
    void CPY_imediate(char valor); //C0
    void CPY_zeropage(unsigned char addr); //C4
    //BIT
    void BIT_absolute(unsigned short int addr); //2C
    void BIT_imediate(char valor); //89
    void BIT_zeropage(unsigned char addr); //24

    //Branch OPCODES
    //BCC
    void BCC(char valor); //90
    //BCS
    void BCS(char valor); //B0
    //BEQ
    void BEQ(char valor); //F0
    //BMI
    void BMI(char valor); //30
    //BNE
    void BNE(char valor); //D0
    //BPL
    void BPL(char valor); //10
    //BVC
    void BVC(char valor); //50
    //BVS
    void BVS(char valor); //70

    //Transfer OPCODES
    //TAX
    void TAX(); //AA
    //TXA
    void TXA(); //8A
    //TAY
    void TAY(); //A8
    //TYA
    void TYA(); //98
    //TSX
    void TSX(); //BA
    //TXS
    void TXS(); //9A

    //Stack OPCODES
    //PHA
    void PHA(); //48
    //PLA
    void PLA(); //68 
    //PHP
    void PHP(); //08
    //PLP
    void PLP(); //28

    //Subroutine and Jump OPCODE
    //JMP
    void JMP(unsigned short int addr); //4C
    void JMP_indirect(unsigned short int addr); //6C
    //JSR
    void JSR(unsigned short int addr); //20
    //RTS
    void RTS(); //60
    //RTI
    void RTI(); //40

    //Set and Clear OPCODES
    //SEC
    void SEC(); //38
    //SED
    void SED(); //F8
    //SEI
    void SEI(); //78
    //CLC
    void CLC(); //18
    //CLD
    void CLD(); //D8
    //CLI
    void CLI(); //C8
    //CLV
    void CLV(); //B8

    //Misc OPCODES
    //NOP
    void NOP(); //EA
    //BRK
    void BRK(); //00
};

#endif	/* M6507_H */

char M6507::MemoryRead(unsigned short int addr) {
    while(addr > 8191)
        addr -= 8192;
    if (addr < 0)
        addr += 8192;
    return this->memory_block[addr];
}

void M6507::MemoryWrite(unsigned short int addr, char valor) {
    while(addr > 8191)
        addr -= 8192;
    if (addr < 0)
        addr += 8192;
    this->memory_block[addr] = valor;
}

char M6507::pop_stack() {
    if (this->S() == 255)
        this->S(0);
    else
        this->S(this->S() + 1);
    return this->MemoryRead(256 + this->S());
}

void M6507::push_stack(char valor) {
    this->MemoryWrite(256 + this->S(), valor);
    if (this->S() == 0)
        this->S(255);
    else
        this->S(this->S() - 1);
}