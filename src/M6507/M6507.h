#ifndef M6507_H
#define	M6507_H9

#include "../util/data_manipulation.h"
#include <iostream>

#define CPU_READY -1

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

//Opcodes IDs
#define _ADC	0x00
#define _AHX	0x01
#define _ALR	0x02
#define _ANC	0x03
#define _AND	0x04
#define _ARR	0x05
#define _ASL	0x06
#define _AXS	0x07
#define _BCC	0x08
#define _BCS	0x09
#define _BEQ	0x0A
#define _BIT	0x0B
#define _BMI	0x0C
#define _BNE	0x0D
#define _BPL	0x0E
#define _BRK	0x0F
#define _BVC	0x10
#define _CLC	0x11
#define _CLD	0x12
#define _CLI	0x13
#define _CLV	0x14
#define _CMP	0x15
#define _CPX	0x16
#define _CPY	0x17
#define _DCP	0x18
#define _DEC	0x19
#define _EOR	0x1A
#define _INC	0x1B
#define _INX	0x1C
#define _INY	0x1D
#define _ISC	0x1E
#define _JMP	0x1F
#define _JSR	0x20
#define _KIL	0x21
#define _LAS	0x22
#define _LAX	0x23
#define _LDA	0x24
#define _LDX	0x25
#define _LDY	0x26
#define _LSR	0x27
#define _NOP	0x28
#define _ORA	0x29
#define _PHA	0x2A
#define _PHP	0x2B
#define _PLA	0x2C
#define _RLA	0x2D
#define _ROL	0x2E
#define _ROR	0x2F
#define _RRA	0x30
#define _RTI	0x31
#define _RTS	0x32
#define _SAX	0x33
#define _SBC	0x34
#define _SEC	0x35
#define _SED	0x36
#define _SEI	0x37
#define _SHA	0x38
#define _SHY	0x39
#define _SLO	0x3A
#define _SRE	0x3B
#define _STA	0x3C
#define _STX	0x3D
#define _STY	0x3E
#define _TAS	0x3F
#define _TAX	0x40
#define _TAY	0x41
#define _TSX	0x42
#define _TXA	0x43
#define _TXS	0x44
#define _TYA	0x45
#define _XAA	0x46


//Address modes
#define	implied		0x00
#define	indirectX	0x01
#define	none		0x02
#define	zeropage	0x03
#define	immidiate	0x04
#define	accumulator	0x05
#define	absolute	0x06
#define	relative	0x07
#define	indirectY	0x08
#define	zeropageX	0x09
#define	absoluteY	0x0A
#define	absoluteX	0x0B
#define	indirect	0x0C
#define	zeropageY	0x0D

class M6507_Register_8BIT {
	protected:
		unsigned char reg_data;
	public:
		unsigned char set(unsigned char value);
		unsigned char get();
};

class M6507_Program_Counter {
	protected:
		unsigned short int program_counter;
	public:
		unsigned short int set(unsigned short int value);
		unsigned short int increment();
		unsigned short int increment(unsigned short int value);
		unsigned short int get();
		unsigned char low();
		unsigned char high();
};

class M6507_Status_Register: public M6507_Register_8BIT {
	protected:
		void bit_change(bool enable, unsigned char bit);
	public:
		void carry(bool valor);
		void zero(bool valor);
		void irq_disable(bool valor);
		void decimal_mode(bool valor);
		void brk_command(bool valor);
		void overflow(bool valor);
		void negative(bool valor);
		bool carry();
		bool zero();
		bool irq_disable();
		bool decimal_mode();
		bool brk_command();
		bool overflow();
		bool negative();
};

class M6507 {
protected:
    //Constantes
	std::string opcode_name[256] = 		   {"BRK","ORA","KIL","SLO","NOP","ORA","ASL","SLO","PHP","ORA","ASL","ANC","NOP","ORA","ASL","SLO",
											"BPL","ORA","KIL","SLO","NOP","ORA","ASL","SLO","CLC","ORA","NOP","SLO","NOP","ORA","ASL","SLO",
											"JSR","AND","KIL","RLA","BIT","AND","ROL","RLA","PLP","AND","ROL","ANC","BIT","AND","ROL","RLA",
											"BMI","AND","KIL","RLA","NOP","AND","ROL","RLA","SEC","AND","NOP","RLA","NOP","AND","ROL","RLA",
											"RTI","EOR","KIL","SRE","NOP","EOR","LSR","SRE","PHA","EOR","LSR","ALR","JMP","EOR","LSR","SRE",
											"BVC","EOR","KIL","SRE","NOP","EOR","LSR","SRE","CLI","EOR","NOP","SRE","NOP","EOR","LSR","SRE",
											"RTS","ADC","KIL","RRA","NOP","ADC","ROR","RRA","PLA","ADC","ROR","ARR","JMP","ADC","ROR","RRA",
											"BVS","ADC","KIL","RRA","NOP","ADC","ROR","RRA","SEI","ADC","NOP","RRA","NOP","ADC","ROR","RRA",
											"NOP","STA","NOP","SAX","STY","STA","STX","SAX","DEY","NOP","TXA","XAA","STY","STA","STX","SAX",
											"BCC","STA","KIL","AHX","STY","STA","STX","SAX","TYA","STA","TXS","TAS","SHY","STA","SHX","AHX",
											"LDY","LDA","LDX","LAX","LDY","LDA","LDX","LAX","TAY","LDA","TAX","LAX","LDY","LDA","LDX","LAX",
											"BCS","LDA","KIL","LAX","LDY","LDA","LDX","LAX","CLV","LDA","TSX","LAS","LDY","LDA","LDX","LAX",
											"CPY","CMP","NOP","DCP","CPY","CMP","DEC","DCP","INY","CMP","DEX","AXS","CPY","CMP","DEC","DCP",
											"BNE","CMP","KIL","DCP","NOP","CMP","DEC","DCP","CLD","CMP","NOP","DCP","NOP","CMP","DEC","DCP",
											"CPX","SBC","NOP","ISC","CPX","SBC","INC","ISC","INX","SBC","NOP","SBC","CPX","SBC","INC","ISC",
											"BEQ","SBC","KIL","ISC","NOP","SBC","INC","ISC","SED","SBC","NOP","ISC","NOP","SBC","INC","ISC"};
											
	unsigned char opcode_id[256] 	=	   {_BRK,_ORA,_KIL,_SLO,_NOP,_ORA,_ASL,_ASL,_PHP,_ORA,_ASL,_ANC,_NOP,_ORA,_ASL,_SLO,
											_BPL,_ORA,_KIL,_SLO,_NOP,_ORA,_ASL,_SLO,_CLC,_ORA,_NOP,_SLO,_NOP,_ORA,_ASL,_SLO,
											_JSR,_AND,_KIL,_RLA,_BIT,_AND,_ROL,_RLA,_PHP,_AND,_ROL,_ANC,_BIT,_AND,_ROL,_RLA,
											_BMI,_AND,_KIL,_RLA,_NOP,_AND,_ROL,_RLA,_SEC,_AND,_NOP,_RLA,_NOP,_AND,_ROL,_RLA,
											_RTI,_EOR,_KIL,_SRE,_NOP,_EOR,_LSR,_SRE,_PHA,_EOR,_LSR,_ALR,_JMP,_EOR,_LSR,_SRE,
											_BVC,_EOR,_KIL,_SRE,_NOP,_EOR,_LSR,_SRE,_CLI,_EOR,_NOP,_SRE,_NOP,_EOR,_LSR,_SRE,
											_RTS,_ADC,_KIL,_RRA,_NOP,_ADC,_ROR,_RRA,_PLA,_ADC,_ROR,_ARR,_JMP,_ADC,_ROR,_RRA,
											_BVC,_ADC,_KIL,_RRA,_NOP,_ADC,_ROR,_RRA,_SEI,_ADC,_NOP,_RRA,_NOP,_ADC,_ROR,_RRA,
											_NOP,_STA,_NOP,_SAX,_STY,_STA,_STX,_SAX,_DEC,_NOP,_TXA,_XAA,_STY,_STA,_STX,_SAX,
											_BCC,_STA,_KIL,_AHX,_STY,_STA,_STX,_SAX,_TYA,_STA,_TXS,_TAS,_SHY,_STA,_SHA,_AHX,
											_LDY,_LDA,_LDX,_LAX,_LDY,_LDA,_LDX,_LAX,_TAY,_LDA,_TAX,_LAX,_LDY,_LDA,_LDX,_LAX,
											_BCS,_LDA,_KIL,_LAX,_LDY,_LDA,_LDX,_LAX,_CLV,_LDA,_TSX,_LAS,_LDY,_LDA,_LDX,_LAX,
											_CPY,_CMP,_NOP,_DCP,_CPY,_CMP,_DEC,_DCP,_INY,_CMP,_DEC,_AXS,_CPY,_CMP,_DEC,_DCP,
											_BNE,_CMP,_KIL,_DCP,_NOP,_CMP,_DEC,_DCP,_CLD,_CMP,_NOP,_DCP,_NOP,_CMP,_DEC,_DCP,
											_CPX,_SBC,_NOP,_ISC,_CPX,_SBC,_INC,_ISC,_INX,_SBC,_NOP,_SBC,_CPX,_SBC,_INC,_ISC,
											_BEQ,_SBC,_KIL,_ISC,_NOP,_SBC,_INC,_ISC,_SED,_SBC,_NOP,_ISC,_NOP,_SBC,_INC,_ISC};

	unsigned char opcode_bytes[256] =	   {1,2,1,2,2,2,2,2,1,2,1,2,2,2,2,2,
											2,2,1,2,2,2,2,2,1,3,1,3,2,2,2,2,
											2,2,1,2,2,2,2,2,1,2,1,2,2,2,2,2,
											2,2,1,2,2,2,2,2,1,3,1,3,2,2,2,2,
											1,2,1,2,2,2,2,2,1,2,1,2,2,2,2,2,
											2,2,1,2,2,2,2,2,1,3,1,3,2,2,2,2,
											1,2,1,2,2,2,2,2,1,2,1,2,3,2,2,2,
											2,2,1,2,2,2,2,2,1,3,1,3,2,2,2,2,
											2,2,2,2,2,2,2,2,1,2,1,2,2,2,2,2,
											2,2,1,2,2,2,3,3,1,3,1,3,2,2,3,3,
											2,2,2,2,2,2,2,2,1,2,1,2,2,2,2,2,
											2,2,1,2,2,2,3,3,1,3,1,3,2,2,3,3,
											2,2,2,2,2,2,2,2,1,2,1,2,2,2,2,2,
											2,2,1,2,2,2,2,2,1,3,1,3,2,2,2,2,
											2,2,2,2,2,2,2,2,1,2,1,2,2,2,2,2,
											2,2,1,2,2,2,2,2,1,3,1,3,2,2,2,2};
		

	unsigned char opcode_mode[256] = 	   {0x00,0x01,0x02,0x01,0x03,0x03,0x03,0x03,0x00,0x04,0x05,0x04,0x06,0x06,0x06,0x06,
											0x07,0x08,0x02,0x08,0x09,0x09,0x09,0x09,0x00,0x0A,0x02,0x0A,0x0B,0x0B,0x0B,0x0B,
											0x06,0x01,0x02,0x01,0x03,0x03,0x03,0x03,0x00,0x04,0x05,0x04,0x06,0x06,0x06,0x06,
											0x07,0x08,0x02,0x08,0x09,0x09,0x09,0x09,0x00,0x0A,0x02,0x0A,0x0B,0x0B,0x0B,0x0B,
											0x00,0x01,0x02,0x01,0x03,0x03,0x03,0x03,0x00,0x04,0x05,0x04,0x06,0x06,0x06,0x06,
											0x07,0x08,0x02,0x08,0x09,0x09,0x09,0x09,0x00,0x0A,0x02,0x0A,0x0B,0x0B,0x0B,0x0B,
											0x00,0x01,0x02,0x01,0x03,0x03,0x03,0x03,0x00,0x04,0x05,0x04,0x0C,0x06,0x06,0x06,
											0x07,0x08,0x02,0x08,0x09,0x09,0x09,0x09,0x00,0x0A,0x02,0x0A,0x0B,0x0B,0x0B,0x0B,
											0x04,0x01,0x04,0x01,0x03,0x03,0x03,0x03,0x00,0x04,0x00,0x04,0x06,0x06,0x06,0x06,
											0x07,0x08,0x02,0x08,0x09,0x09,0x0D,0x0D,0x00,0x0A,0x00,0x0A,0x0B,0x0B,0x0A,0x0A,
											0x04,0x01,0x04,0x01,0x03,0x03,0x03,0x03,0x00,0x04,0x00,0x04,0x06,0x06,0x06,0x06,
											0x07,0x08,0x02,0x08,0x09,0x09,0x0D,0x0D,0x00,0x0A,0x00,0x0A,0x0B,0x0B,0x0A,0x0A,
											0x04,0x01,0x04,0x01,0x03,0x03,0x03,0x03,0x00,0x04,0x00,0x04,0x06,0x06,0x06,0x06,
											0x07,0x08,0x02,0x08,0x09,0x09,0x09,0x09,0x00,0x0A,0x02,0x0A,0x0B,0x0B,0x0B,0x0B,
											0x04,0x01,0x04,0x01,0x03,0x03,0x03,0x03,0x00,0x04,0x00,0x04,0x06,0x06,0x06,0x06,
											0x07,0x08,0x02,0x08,0x09,0x09,0x09,0x09,0x00,0x0A,0x02,0x0A,0x0B,0x0B,0x0B,0x0B};

										
    unsigned char opcode_cycles[256] =	   {7,6,0,6,3,3,5,5,3,2,2,2,4,4,6,6,
											2,5,0,5,4,4,6,6,2,4,2,7,4,4,7,7,
											6,6,0,6,3,3,5,5,4,2,2,2,4,4,6,6,
											2,5,0,5,4,4,6,6,2,4,2,7,4,4,7,7,
											6,6,0,6,3,3,5,5,3,2,2,2,3,4,6,6,
											2,5,0,5,4,4,6,6,2,4,2,7,4,4,7,7,
											6,6,0,6,3,3,5,5,4,2,2,2,5,4,6,6,
											2,5,0,5,4,4,6,6,2,4,2,7,4,4,7,7,
											2,6,2,6,3,3,3,3,2,2,2,2,4,4,4,4,
											2,6,0,5,4,4,4,4,2,5,2,5,5,5,5,5,
											2,6,2,6,3,3,3,3,2,2,2,2,4,4,4,4,
											2,5,0,5,4,4,4,4,2,4,2,4,4,4,4,4,
											2,6,2,6,3,3,5,5,2,2,2,2,4,4,3,6,
											2,5,0,5,4,4,6,6,2,4,2,7,4,4,7,7,
											2,6,2,6,3,3,5,5,2,2,2,2,4,4,6,6,
											2,5,0,5,4,4,6,6,2,4,2,7,4,4,7,7};
	
	unsigned char cpu_boundary[256] =	   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
											2,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,
											0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
											2,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,
											0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
											2,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,
											0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
											2,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,
											0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
											2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
											0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
											2,1,0,1,0,0,0,0,0,1,0,1,1,1,1,1,
											0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
											2,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0,
											0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
											2,1,0,1,0,0,0,0,0,1,0,0,1,1,0,0};

    unsigned char RIOT_IO[8];
    //Variaveis dos registradores
    M6507_Register_8BIT reg_a;
    M6507_Register_8BIT reg_y;
    M6507_Register_8BIT reg_x;
    M6507_Register_8BIT reg_s;
    M6507_Status_Register reg_p;
    M6507_Program_Counter reg_pc;
    //memoria total 64K (para leitura)
    //char memory[2^16];
    //bloco de 8K de memoria (para replicação)
    unsigned char memory_block[8192];
    //Metodos genericos usados internamente
    void update_zero_flag(unsigned char valor);
    void update_negative_flag(unsigned char valor);
    void update_overflow_flag(unsigned short int valor);
    void update_carry_flag(unsigned short int valor);
    //void push_stack(unsigned char valor);
    //unsigned char pop_stack();
    unsigned char opcode;
    unsigned char opcode_byte_lo;
    unsigned char opcode_byte_hi;
    unsigned char cpu_status;
    unsigned short int opcode_pc;
    
public:
	std::string get_opcode_name(unsigned char valor);
	unsigned char get_opcode();
	unsigned short int get_opcode_pc();
	
    M6507(unsigned char ROM[4096]);
    void step();
    bool page_boundary_check(unsigned short int addr, unsigned char reg);
    
    //Metodos de manipulação da memória
    unsigned char MemoryRead(unsigned short int addr);
    unsigned char MemoryReadZeroPage(unsigned char addr);
    void MemoryWrite(unsigned short int addr, unsigned char valor);

    //Metodos para ler os valores dos registradores

    M6507_Register_8BIT* A();
    M6507_Register_8BIT* Y();
    M6507_Register_8BIT* X();
    M6507_Register_8BIT* S();
    M6507_Status_Register* P();
    M6507_Program_Counter* PC();
};

#endif	/* M6507_H */
