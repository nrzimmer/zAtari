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
    unsigned char reg_p;
    unsigned short int reg_pc;
    //memoria total 64K (para leitura)
    //char memory[2^16];
    //bloco de 8K de memoria (para replicação)
    unsigned char memory_block[8192];

    //Metodos genericos usados internamente
    void update_zero_flag(char valor);
    void update_negative_flag(char valor);
    void update_overflow_flag(short int valor);
    void update_carry_flag(short int valor);
    void push_stack(unsigned char valor);
    unsigned char pop_stack();
    void ADC(char valor);
    void SBC(char valor);
    void CMP(char val1, char val2);
    void inc_pc();
    void inc_pc(unsigned short int valor);
public:
    unsigned char last_instruction;
    M6507(char ROM[4096]);
    void step();
    //Metodos de manipulação da memória
    unsigned char MemoryRead(unsigned short int addr);
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
    void PC(unsigned short int valor);

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

unsigned char M6507::MemoryRead(unsigned short int addr) {
    while (addr > 0x1FFF)
        addr -= 0x2000;
    if (addr < 0)
        addr += 0x2000;
    return this->memory_block[addr];
}

void M6507::MemoryWrite(unsigned short int addr, char valor) {
    while (addr > 0x1FFF)
        addr -= 0x2000;
    if (addr < 0)
        addr += 0x2000;
    this->memory_block[addr] = valor;
}

unsigned char M6507::pop_stack() {
    unsigned char sp = this->S();
    sp -=1;
    this->S(sp);
    return this->MemoryRead(511 - sp);
}

void M6507::push_stack(unsigned char valor) {
    unsigned char sp = this->S();
    this->MemoryWrite(511 - sp, valor);
    sp +=1;
    this->S(sp);
}

void M6507::inc_pc() {
    this->PC(this->PC() + 1);
}

void M6507::inc_pc(unsigned short int valor) {
    this->PC(this->PC() + valor);
}

M6507::M6507(char ROM[4096]) {
    int i;
    for (i = 0; i < 4096; i++)
        this->memory_block[i] = 0;
    for (i = 4096; i < 8192; i++)
        this->memory_block[i] = ROM[i - 4096];
    this->reg_carry = false;
    this->reg_zero = false;
    this->reg_irq_disable = false;
    this->reg_decimal_mode = false;
    this->reg_brk_command = false;
    this->reg_overflow = false;
    this->reg_negative = false;
    this->reg_a = 0;
    this->reg_y = 0;
    this->reg_x = 0;
    this->reg_s = 0;
    this->reg_pc_l = 0;
    this->reg_pc_h = 0;
    this->reg_p = 0;
    this->reg_pc = make_word(this->MemoryRead(0xFFFC), this->MemoryRead(0xFFFD));
    this->last_instruction = 0;
}

void M6507::step() {
    unsigned char instruction = (unsigned char) this->MemoryRead(this->PC());
    unsigned char lo, hi;
    this->inc_pc();
    this->last_instruction = instruction;
    switch (instruction) {
        case 0xAD:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            LDA_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0xBD:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            LDA_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0xB9:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            LDA_absolute_Y(make_word(lo, hi));
            inc_pc();
            break;
        case 0xA9:
            LDA_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xA5:
            LDA_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xA1:
            LDA_zeropage_indirect_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xB5:
            LDA_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xB1:
            LDA_zeropage_indirect_Y(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xAE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            LDX_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0xBE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            LDX_absolute_Y(make_word(lo, hi));
            inc_pc();
            break;
        case 0xA2:
            LDX_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xA6:
            LDX_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xB6:
            LDX_zeropage_Y(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xAC:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            LDY_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0xBC:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            LDY_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0xA0:
            LDY_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xA4:
            LDY_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xB4:
            LDY_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x8D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            STA_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x9D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            STA_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0x99:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            STA_absolute_Y(make_word(lo, hi));
            inc_pc();
            break;
        case 0x85:
            STA_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x81:
            STA_zeropage_indirect_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x95:
            STA_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x91:
            STA_zeropage_indirect_Y(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x8E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            STX_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x86:
            STX_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x96:
            STX_zeropage_Y(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x8C:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            STY_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x84:
            STY_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x94:
            STY_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x6D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ADC_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x7D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ADC_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0x79:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ADC_absolute_Y(make_word(lo, hi));
            inc_pc();
            break;
        case 0x69:
            ADC_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x65:
            ADC_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x61:
            ADC_zeropage_indirect_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x75:
            ADC_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x71:
            ADC_zeropage_indirect_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xED:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            SBC_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0xFD:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            SBC_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0xF9:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            SBC_absolute_Y(make_word(lo, hi));
            inc_pc();
            break;
        case 0xE9:
            SBC_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xE5:
            SBC_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xE1:
            SBC_zeropage_indirect_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xF5:
            SBC_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xF1:
            SBC_zeropage_indirect_Y(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xEE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            INC_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0xFE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            INC_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0xE6:
            INC_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xF6:
            INC_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xE8:
            INX();
            break;
        case 0xC8:
            INY();
            break;
        case 0xCE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            DEC_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0xDE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            DEC_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0xC6:
            DEC_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xD6:
            DEC_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xCA:
            DEX();
            break;
        case 0x88:
            DEY();
            break;
        case 0x0A:
            ASL();
            break;
        case 0x0E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ASL_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x1E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ASL_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0x06:
            ASL_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x16:
            ASL_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x4A:
            LSR();
            break;
        case 0x4E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            LSR_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x5E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            LSR_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0x46:
            LSR_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x56:
            LSR_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x2A:
            ROL();
            break;
        case 0x2E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ROL_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x3E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ROL_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0x26:
            ROL_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x36:
            ROL_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x6A:
            ROR();
            break;
        case 0x6E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ROR_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x7E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ROR_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0x66:
            ROR_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x76:
            ROR_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x2D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            AND_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x3D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            AND_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0x39:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            AND_absolute_Y(make_word(lo, hi));
            inc_pc();
            break;
        case 0x29:
            AND_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x25:
            AND_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x21:
            AND_zeropage_indirect_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x35:
            AND_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x31:
            AND_zeropage_indirect_Y(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x0D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ORA_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x1D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ORA_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0x19:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            ORA_absolute_Y(make_word(lo, hi));
            inc_pc();
            break;
        case 0x09:
            ORA_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x05:
            ORA_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x01:
            ORA_zeropage_indirect_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x15:
            ORA_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x11:
            ORA_zeropage_indirect_Y(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x4D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            EOR_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x5D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            EOR_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0x49:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            EOR_absolute_Y(make_word(lo, hi));
            inc_pc();
            break;
        case 0x59:
            EOR_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x45:
            EOR_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x41:
            EOR_zeropage_indirect_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x55:
            EOR_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x51:
            EOR_zeropage_indirect_Y(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xCD:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            CMP_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0xDD:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            CMP_absolute_X(make_word(lo, hi));
            inc_pc();
            break;
        case 0xD9:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            CMP_absolute_Y(make_word(lo, hi));
            inc_pc();
            break;
        case 0xC9:
            CMP_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xC5:
            CMP_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xC1:
            CMP_zeropage_indirect_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xD5:
            CMP_zeropage_X(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xD1:
            CMP_zeropage_indirect_Y(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xEC:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            CPX_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0xE0:
            CPX_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xE4:
            CPX_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xCC:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            CPY_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0xC0:
            CPY_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xC4:
            CPY_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x2C:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            BIT_absolute(make_word(lo, hi));
            inc_pc();
            break;
        case 0x89:
            BIT_imediate(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x24:
            BIT_zeropage(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x90:
            BCC(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xB0:
            BCS(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xF0:
            BEQ(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x30:
            BMI(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xD0:
            BNE(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x10:
            BPL(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x50:
            BVC(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0x70:
            BVS(MemoryRead(PC())); //A2
            inc_pc();
            break;
        case 0xAA:
            TAX();
            break;
        case 0x8A:
            TXA();
            break;
        case 0xA8:
            TAY();
            break;
        case 0x98:
            TYA();
            break;
        case 0xBA:
            TSX();
            break;
        case 0x9A:
            TXS();
            break;
        case 0x48:
            PHA();
            break;
        case 0x68:
            PLA();
            break;
        case 0x08:
            PHP();
            break;
        case 0x28:
            PLP();
            break;
        case 0x4C:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            JMP(make_word(lo, hi));
            break;
        case 0x6C:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            JMP_indirect(make_word(lo, hi));
            break;
        case 0x20:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            JSR(make_word(lo, hi));
            break;
        case 0x60:
            RTS();
            break;
        case 0x40:
            RTI();
            break;
        case 0x38:
            SEC();
            break;
        case 0xF8:
            SED();
            break;
        case 0x78:
            SEI();
            break;
        case 0xD8:
            CLD();
            break;
        case 0x18:
            CLC();
            break;
        case 0x58:
            CLI();
            break;
        case 0xB8:
            CLV();
            break;
        case 0xEA:
            NOP();
            break;
        case 0x00:
        default:
            BRK();
            break;
    }
}