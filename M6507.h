/* 
 * File:   M6507.h
 * Author: NatanaelRodrigo
 *
 * Created on 27 de Março de 2014, 15:10
 */

#ifndef M6507_H
#define	M6507_H9

#define v_carry 1
#define v_zero 2
#define v_irq_disable 4
#define v_decimal_mode 8
#define v_brk_command 16
#define v_overflow 64
#define v_negative 128

//TIA - WRITE ADDRESS SUMMARY (Write only)
#define VSYNC 0x00 //......1.  vertical sync set-clear
#define VBLANK 0x01 //11....1.  vertical blank set-clear
#define WSYNC 0x02 //<strobe>  wait for leading edge of horizontal blank
#define RSYNC 0x03 //<strobe>  reset horizontal sync counter
#define NUSIZ0 0x04 //..111111  number-size player-missile 0
#define NUSIZ1 0x05 //..111111  number-size player-missile 1
#define COLUP0 0x06 //1111111.  color-lum player 0 and missile 0
#define COLUP1 0x07 //1111111.  color-lum player 1 and missile 1
#define COLUPF 0x08 //1111111.  color-lum playfield and ball
#define COLUBK 0x09 //1111111.  color-lum background
#define CTRLPF 0x0A //..11.111  control playfield ball size & collisions
#define REFP0 0x0B //....1...  reflect player 0
#define REFP1 0x0C //....1...  reflect player 1
#define PF0 0x0D //1111....  playfield register byte 0
#define PF1 0x0E //11111111  playfield register byte 1
#define PF2 0x0F //11111111  playfield register byte 2
#define RESP0 0x10 //<strobe>  reset player 0
#define RESP1 0x11 //<strobe>  reset player 1
#define RESM0 0x12 //<strobe>  reset missile 0
#define RESM1 0x13 //<strobe>  reset missile 1
#define RESBL 0x14 //<strobe>  reset ball
#define AUDC0 0x15 //....1111  audio control 0
#define AUDC1 0x16 //....1111  audio control 1
#define AUDF0 0x17 //...11111  audio frequency 0
#define AUDF1 0x18 //...11111  audio frequency 1
#define AUDV0 0x19 //....1111  audio volume 0
#define AUDV1 0x1A //....1111  audio volume 1
#define GRP0 0x1B //11111111  graphics player 0
#define GRP1 0x1C //11111111  graphics player 1
#define ENAM0 0x1D //......1.  graphics (enable) missile 0
#define ENAM1 0x1E //......1.  graphics (enable) missile 1
#define ENABL 0x1F //......1.  graphics (enable) ball
#define HMP0 0x20 //1111....  horizontal motion player 0
#define HMP1 0x21 //1111....  horizontal motion player 1
#define HMM0 0x22 //1111....  horizontal motion missile 0
#define HMM1 0x23 //1111....  horizontal motion missile 1
#define HMBL 0x24 //1111....  horizontal motion ball
#define VDELP0 0x25 //.......1  vertical delay player 0
#define VDELP1 0x26 //.......1  vertical delay player 1
#define VDELBL 0x27 //.......1  vertical delay ball
#define RESMP0 0x28 //......1.  reset missile 0 to player 0
#define RESMP1 0x29 //......1.  reset missile 1 to player 1
#define HMOVE 0x2A //<strobe>  apply horizontal motion
#define HMCLR 0x2B //<strobe>  clear horizontal motion registers
#define CXCLR 0x2C //<strobe>  clear collision latches

//TIA - READ ADDRESS SUMMARY (Read only)
#define CXM0P 0x30 //11......  read collision M0-P1, M0-P0 (Bit 7,6)
#define CXM1P 0x31 //11......  read collision M1-P0, M1-P1
#define CXP0FB 0x32 //11......  read collision P0-PF, P0-BL
#define CXP1FB 0x33 //11......  read collision P1-PF, P1-BL
#define CXM0FB 0x34 //11......  read collision M0-PF, M0-BL
#define CXM1FB 0x35 //11......  read collision M1-PF, M1-BL
#define CXBLPF 0x36 //1.......  read collision BL-PF, unused
#define CXPPMM 0x37 //11......  read collision P0-P1, M0-M1
#define INPT0 0x38 //1.......  read pot port
#define INPT1 0x39 //1.......  read pot port
#define INPT2 0x3A //1.......  read pot port
#define INPT3 0x3B //1.......  read pot port
#define INPT4 0x3C //1.......  read input
#define INPT5 0x3D //1.......  read input

//PIA 6532 - RAM, Switches, and Timer (Read/Write)
//80..FF  RAM     11111111  128 bytes RAM (in PIA chip) for variables and stack
#define SWCHA 0x280 //11111111  Port A; input or output  (read or write)
#define SWACNT 0x281 //11111111  Port A DDR, 0= input, 1=output
#define SWCHB 0x282 //11111111  Port B; console switches (read only)
#define SWBCNT 0x283 //11111111  Port B DDR (hardwired as input)
#define INTIM 0x284 //11111111  Timer output (read only)
#define INSTAT 0x285 //11......  Timer Status (read only, undocumented)
#define TIM1T 0x294 //11111111  set 1 clock interval (838 nsec/interval)
#define TIM8T 0x295 //11111111  set 8 clock interval (6.7 usec/interval)
#define TIM64T 0x296 //11111111  set 64 clock interval (53.6 usec/interval)
#define T1024T 0x297 //11111111  set 1024 clock interval (858.2 usec/interval)

class M6507 {
protected:
    //Constantes
    unsigned char RIOT_IO[8];
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
    unsigned char lo, hi;
    while (addr > 0x1FFF)
        addr -= 0x2000;
    if (addr < 0)
        addr += 0x2000;
    lo = lo_byte(addr);
    hi = hi_byte(addr);
    /*
     * RIOT RAM and mirrors
     * $0D80 - $0DFF = mirror of the RIOT RAM
     * $0C80 - $0CFF = mirror of the RIOT RAM
     * $0980 - $09FF = mirror of the RIOT RAM
     * $0880 - $08FF = mirror of the RIOT RAM
     * $0580 - $05FF = mirror of the RIOT RAM
     * $0480 - $04FF = mirror of the RIOT RAM
     * $0180 - $01FF = mirror of the RIOT RAM (used by the 6507 for its stack memory)
     * $0080 - $00FF = 128 bytes of RIOT RAM
     * 
     * xxx0 xx0x  1??? ????
     */
    if ((!get_bit(hi, 1)) & (!get_bit(hi, 4)) & (get_bit(lo, 7))) {
        hi = 0;
        addr = make_word(lo, hi);
        this->memory_block[addr] = valor;
        this->memory_block[addr + 0x100] = valor;
        this->memory_block[addr + 0x400] = valor;
        this->memory_block[addr + 0x500] = valor;
        this->memory_block[addr + 0x800] = valor;
        this->memory_block[addr + 0x900] = valor;
        this->memory_block[addr + 0xC00] = valor;
        this->memory_block[addr + 0xD00] = valor;
    } else {
        /*
         * RIOT's IO
         * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
         * $02F8 - $02FB = mirror of $0280 - $0283
         * $02F0 - $02F3 = mirror of $0280 - $0283
         * $02E8 - $02EB = mirror of $0280 - $0283
         * $02E0 - $02E3 = mirror of $0280 - $0283
         * $02D8 - $02DB = mirror of $0280 - $0283
         * $02D0 - $02D3 = mirror of $0280 - $0283
         * $02C8 - $02CB = mirror of $0280 - $0283
         * $02C0 - $02C3 = mirror of $0280 - $0283
         * $02B8 - $02BB = mirror of $0280 - $0283
         * $02B0 - $02B3 = mirror of $0280 - $0283
         * $02A8 - $02AB = mirror of $0280 - $0283
         * $02A0 - $02A3 = mirror of $0280 - $0283
         * $0298 - $029B = mirror of $0280 - $0283
         * $0290 - $0293 = mirror of $0280 - $0283
         * $0288 - $028B = mirror of $0280 - $0283
         * $0283 = data-direction control for I/O register B
         * $0282 = I/O register B
         * $0281 = data-direction control for I/O register A
         * $0280 = I/O register A
         * 
         * xxx0 xx1x 1xxx x0??
         */
        if ((!get_bit(hi, 4)) & (get_bit(hi, 1)) & (get_bit(lo, 7)) & (!get_bit(lo, 2))) {
            int loop1, loop2;
            for (loop1 = 0; loop1 < 8; loop1++) {
                hi = this->RIOT_IO[loop1];
                lo = 0x80 | get_bit(lo, 0) | (get_bit(lo, 1) << 1);
                addr = make_word(lo, hi);
                for (loop2 = 1; loop2 < 16; loop2++) {
                    this->memory_block[addr + 8 * loop2] = valor;
                }
            }
        } else {
            /*
             * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
             * $02FC - $02FF = mirror of $029C - $029F
             * $02F4 - $02F7 = mirror of $0294 - $0297
             * $02DC - $02DF = mirror of $029C - $029F
             * $02D4 - $02D7 = mirror of $0294 - $0297
             * $02BC - $02BF = mirror of $029C - $029F
             * $02B4 - $02B7 = mirror of $0294 - $0297
             * $029F = enable the timer interrupt and set the timer using the 1024-cycle interval
             * $029E = enable the timer interrupt and set the timer using the 64-cycle interval
             * $029D = enable the timer interrupt and set the timer using the 8-cycle interval
             * $029C = enable the timer interrupt and set the timer using the 1-cycle interval
             * $0297 = disable the timer interrupt and set the timer using the 1024-cycle interval
             * $0296 = disable the timer interrupt and set the timer using the 64-cycle interval
             * $0295 = disable the timer interrupt and set the timer using the 8-cycle interval
             * $0294 = disable the timer interrupt and set the timer using the 1-cycle interval
             * xxx0 xx1x 1xx1 ?1??
             */
            if ((!get_bit(hi, 4)) & (get_bit(hi, 1)) & (get_bit(lo, 7)) & (get_bit(lo, 4)) & (get_bit(lo, 2))) {
                int loop1, loop2;
                for (loop1 = 0; loop1 < 8; loop1++) {
                    hi = this->RIOT_IO[loop1];
                    lo = 0x94 | get_bit(lo, 0) | (get_bit(lo, 1) << 1) | (get_bit(lo, 3) << 3);
                    addr = make_word(lo, hi);
                    for (loop2 = 1; loop2 < 8; loop2++) {
                        this->memory_block[addr + 0x20 * loop2] = valor;
                    }
                }
            } else {
                /*
                 * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
                 * $02Ax - $02Fx = same mirrors as $029x shown below
                 * $029E, $029C, $0296, $0294 = mirrors of $028E, $028C, $0286, and $0284
                 * $028E = mirror of $028C
                 * $028C = enable the timer interrupt and read the timer
                 * $0286 = mirror of $0284
                 * $0284 = disable the timer interrupt and read the timer
                 * xxx0 xx1x 1xxx ?1x0
                 */
                if ((!get_bit(hi, 4)) & (get_bit(hi, 1)) & (get_bit(lo, 7)) & (get_bit(lo, 2)) & (!get_bit(lo, 0))) {
                    int loop1, loop2;
                    for (loop1 = 0; loop1 < 8; loop1++) {
                        hi = this->RIOT_IO[loop1];
                        lo = 0x84 | (get_bit(lo, 3) << 3);
                        addr = make_word(lo, hi);
                        for (loop2 = 1; loop2 < 8; loop2++) {
                            this->memory_block[addr + (0x10 * loop2)] = valor;
                            this->memory_block[addr + (0x10 * loop2) + 2] = valor;
                        }
                    }

                } else {
                    /*
                     * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
                     * $029x - $02Fx = same mirrors as $028x shown below
                     * $028F, $028D, $0287 = mirrors of $0285
                     * $0285 = read the interrupt flags
                     * xxx0 xx1x 1xxx x1x1
                     */
                    if ((!get_bit(hi, 4)) & (get_bit(hi, 1)) & (get_bit(lo, 7)) & (get_bit(lo, 2)) & (get_bit(lo, 0))) {
                        int loop1, loop2;
                        for (loop1 = 0; loop1 < 8; loop1++) {
                            hi = this->RIOT_IO[loop1];
                            lo = 0x85 | (get_bit(lo, 3) << 3);
                            addr = make_word(lo, hi);
                            for (loop2 = 1; loop2 < 8; loop2++) {
                                this->memory_block[addr + (0x10 * loop2)] = valor;
                                this->memory_block[addr + (0x10 * loop2) + 2] = valor;
                                this->memory_block[addr + (0x10 * loop2) + 8] = valor;
                                this->memory_block[addr + (0x10 * loop2) + 10] = valor;
                            }
                        }
                    } else {
                        /*
                         * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
                         * $02Ax, $02Cx, $02Ex = same mirrors as $028x shown below
                         * $028C - $028F = mirrors of $0284 - $0287
                         * $0287 = enable the PA7 interrupt and select positive edge-detect
                         * $0286 = enable the PA7 interrupt and select negative edge-detect
                         * $0285 = disable the PA7 interrupt and select positive edge-detect
                         * $0284 = disable the PA7 interrupt and select negative edge-detect
                         * xxx0 xx1x 1xx0 x1??
                         */
                        if ((!get_bit(hi, 4)) & (get_bit(hi, 1)) & (get_bit(lo, 7)) & (!get_bit(lo, 4)) & (get_bit(lo, 2))) {
                            int loop1, loop2;
                            for (loop1 = 0; loop1 < 8; loop1++) {
                                hi = this->RIOT_IO[loop1];
                                lo = 0x84 | get_bit(lo, 0) | (get_bit(lo, 1) << 1);
                                addr = make_word(lo, hi);
                                for (loop2 = 1; loop2 < 6; loop2++) {
                                    this->memory_block[addr + (0x20 * loop2)] = valor;
                                    this->memory_block[addr + (0x20 * loop2) + 8] = valor;
                                }
                            }
                        } else {
                            if (addr < 0x80) {
                                int loop;
                                for (loop = 0; loop < 16; loop++) {
                                    this->memory_block[addr + (0x100 * loop)] = valor;
                                    if (addr < 0x40) {
                                        this->memory_block[addr + 0x40 + (0x100 * loop)] = valor;
                                    } else {
                                        this->memory_block[addr - 0x40 + (0x100 * loop)] = valor;
                                    }
                                }
                            } else
                                this->memory_block[addr] = valor;
                        }
                    }
                }
            }
        }
    }
}

unsigned char M6507::pop_stack() {
    unsigned char sp = this->S();
    sp += 1;
    this->S(sp);
    return this->MemoryRead(0x80 + sp);
}

void M6507::push_stack(unsigned char valor) {
    unsigned char sp = this->S();
    this->MemoryWrite(0x80 + sp, valor);
    sp -= 1;
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
    this->RIOT_IO[0] = 0x02;
    this->RIOT_IO[1] = 0x03;
    this->RIOT_IO[2] = 0x06;
    this->RIOT_IO[3] = 0x07;
    this->RIOT_IO[4] = 0x0A;
    this->RIOT_IO[5] = 0x0B;
    this->RIOT_IO[6] = 0x0E;
    this->RIOT_IO[7] = 0x0F;
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
            inc_pc();
            LDA_absolute(make_word(lo, hi));
            break;
        case 0xBD:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            LDA_absolute_X(make_word(lo, hi));
            break;
        case 0xB9:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            LDA_absolute_Y(make_word(lo, hi));
            break;
        case 0xA9:
            LDA_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xA5:
            LDA_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xA1:
            LDA_zeropage_indirect_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xB5:
            LDA_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xB1:
            LDA_zeropage_indirect_Y(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xAE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            LDX_absolute(make_word(lo, hi));
            break;
        case 0xBE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            LDX_absolute_Y(make_word(lo, hi));
            break;
        case 0xA2:
            LDX_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xA6:
            LDX_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xB6:
            LDX_zeropage_Y(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xAC:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            LDY_absolute(make_word(lo, hi));
            break;
        case 0xBC:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            LDY_absolute_X(make_word(lo, hi));
            break;
        case 0xA0:
            LDY_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xA4:
            LDY_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xB4:
            LDY_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x8D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            STA_absolute(make_word(lo, hi));
            break;
        case 0x9D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            STA_absolute_X(make_word(lo, hi));
            break;
        case 0x99:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            STA_absolute_Y(make_word(lo, hi));
            break;
        case 0x85:
            STA_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x81:
            STA_zeropage_indirect_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x95:
            STA_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x91:
            STA_zeropage_indirect_Y(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x8E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            STX_absolute(make_word(lo, hi));
            break;
        case 0x86:
            STX_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x96:
            STX_zeropage_Y(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x8C:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            STY_absolute(make_word(lo, hi));
            break;
        case 0x84:
            STY_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x94:
            STY_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x6D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ADC_absolute(make_word(lo, hi));
            break;
        case 0x7D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ADC_absolute_X(make_word(lo, hi));
            break;
        case 0x79:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ADC_absolute_Y(make_word(lo, hi));
            break;
        case 0x69:
            ADC_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x65:
            ADC_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x61:
            ADC_zeropage_indirect_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x75:
            ADC_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x71:
            ADC_zeropage_indirect_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xED:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            SBC_absolute(make_word(lo, hi));
            break;
        case 0xFD:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            SBC_absolute_X(make_word(lo, hi));
            break;
        case 0xF9:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            SBC_absolute_Y(make_word(lo, hi));
            break;
        case 0xE9:
            SBC_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xE5:
            SBC_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xE1:
            SBC_zeropage_indirect_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xF5:
            SBC_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xF1:
            SBC_zeropage_indirect_Y(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xEE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            INC_absolute(make_word(lo, hi));
            break;
        case 0xFE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            INC_absolute_X(make_word(lo, hi));
            break;
        case 0xE6:
            INC_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xF6:
            INC_zeropage_X(MemoryRead(PC()));
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
            inc_pc();
            DEC_absolute(make_word(lo, hi));
            break;
        case 0xDE:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            DEC_absolute_X(make_word(lo, hi));
            break;
        case 0xC6:
            DEC_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xD6:
            DEC_zeropage_X(MemoryRead(PC()));
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
            inc_pc();
            ASL_absolute(make_word(lo, hi));
            break;
        case 0x1E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ASL_absolute_X(make_word(lo, hi));
            break;
        case 0x06:
            ASL_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x16:
            ASL_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x4A:
            LSR();
            break;
        case 0x4E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            LSR_absolute(make_word(lo, hi));
            break;
        case 0x5E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            LSR_absolute_X(make_word(lo, hi));
            break;
        case 0x46:
            LSR_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x56:
            LSR_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x2A:
            ROL();
            break;
        case 0x2E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ROL_absolute(make_word(lo, hi));
            break;
        case 0x3E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ROL_absolute_X(make_word(lo, hi));
            break;
        case 0x26:
            ROL_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x36:
            ROL_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x6A:
            ROR();
            break;
        case 0x6E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ROR_absolute(make_word(lo, hi));
            break;
        case 0x7E:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ROR_absolute_X(make_word(lo, hi));
            break;
        case 0x66:
            ROR_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x76:
            ROR_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x2D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            AND_absolute(make_word(lo, hi));
            break;
        case 0x3D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            AND_absolute_X(make_word(lo, hi));
            break;
        case 0x39:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            AND_absolute_Y(make_word(lo, hi));
            break;
        case 0x29:
            AND_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x25:
            AND_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x21:
            AND_zeropage_indirect_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x35:
            AND_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x31:
            AND_zeropage_indirect_Y(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x0D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ORA_absolute(make_word(lo, hi));
            break;
        case 0x1D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ORA_absolute_X(make_word(lo, hi));
            break;
        case 0x19:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            ORA_absolute_Y(make_word(lo, hi));
            break;
        case 0x09:
            ORA_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x05:
            ORA_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x01:
            ORA_zeropage_indirect_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x15:
            ORA_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x11:
            ORA_zeropage_indirect_Y(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x4D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            EOR_absolute(make_word(lo, hi));
            break;
        case 0x5D:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            EOR_absolute_X(make_word(lo, hi));
            break;
        case 0x49:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            EOR_absolute_Y(make_word(lo, hi));
            break;
        case 0x59:
            EOR_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x45:
            EOR_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x41:
            EOR_zeropage_indirect_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x55:
            EOR_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x51:
            EOR_zeropage_indirect_Y(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xCD:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            CMP_absolute(make_word(lo, hi));
            break;
        case 0xDD:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            CMP_absolute_X(make_word(lo, hi));
            break;
        case 0xD9:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            CMP_absolute_Y(make_word(lo, hi));
            break;
        case 0xC9:
            CMP_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xC5:
            CMP_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xC1:
            CMP_zeropage_indirect_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xD5:
            CMP_zeropage_X(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xD1:
            CMP_zeropage_indirect_Y(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xEC:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            CPX_absolute(make_word(lo, hi));
            break;
        case 0xE0:
            CPX_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xE4:
            CPX_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xCC:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            CPY_absolute(make_word(lo, hi));
            break;
        case 0xC0:
            CPY_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xC4:
            CPY_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x2C:
            lo = MemoryRead(PC());
            inc_pc();
            hi = MemoryRead(PC());
            inc_pc();
            BIT_absolute(make_word(lo, hi));
            break;
        case 0x89:
            BIT_imediate(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x24:
            BIT_zeropage(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x90:
            BCC(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xB0:
            BCS(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xF0:
            BEQ(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x30:
            BMI(MemoryRead(PC()));
            inc_pc();
            break;
        case 0xD0:
            BNE(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x10:
            BPL(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x50:
            BVC(MemoryRead(PC()));
            inc_pc();
            break;
        case 0x70:
            BVS(MemoryRead(PC()));
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