#include "M6507.h"

#define CPU_FETCH_OPCODE 	0x00
#define CPU_PARSE_OPCODE 	0x01
#define CPU_FETCH_BYTE_HI	0x02
#define CPU_CALC_ADDRESS	0x03
#define CPU_FETCH_DATA		0x04
#define CPU_FETCH_INDEXED	0x05
#define CPU_FETCH_INDIRECT	0x06
#define CPU_EXEC_OPCODE		0x07


void M6507::step() {
	switch (this->cpu_status) {
		case CPU_FETCH_OPCODE:
			this->opcode_pc = this->PC()->get();
			this->opcode = this->fetch_data();
			this->PC()->increment();
			this->cpu_status = CPU_PARSE_OPCODE;
			this->opcode_byte_hi = 0;
		break; //CPU_FETCH_OPCODE END
		
		case CPU_PARSE_OPCODE:
			this->opcode_byte_lo = this->fetch_data();
			switch(this->opcode_mode[this->opcode]) {
				case _immediate:
				case _relative:
					this->PC()->increment();
				case _none:
				case _implied:
					this->cpu_status = CPU_EXEC_OPCODE;
				break;
				case _absolute:
				case _absoluteX:
				case _absoluteY:
				case _indirect:
					this->PC()->increment();
					this->cpu_status = CPU_FETCH_BYTE_HI;
				break;
				case _zeropage:
					this->PC()->increment();
					this->cpu_status = CPU_FETCH_DATA;
				break;
				case _zeropageX:
				case _zeropageY:
					this->PC()->increment();
					this->cpu_status = CPU_CALC_ADDRESS;
				break;
				case _indexedIndirect:
					this->PC()->increment();
					this->cpu_status = CPU_FETCH_INDEXED;
				break;
				case _indirectIndexed:
					this->PC()->increment();
					this->cpu_status = CPU_FETCH_INDIRECT;
				break;
			}
		break; //CPU_PARSE_OPCODE END
		
		case CPU_FETCH_BYTE_HI:
			this->opcode_byte_hi = this->fetch_data();
			this->PC()->increment();
			this->cpu_status = CPU_FETCH_DATA;
		break; //CPU_FETCH_BYTE_HI END
		
		case CPU_CALC_ADDRESS:
			if (this->cpu_boundary[this->opcode] > 0) {
				
			}
			else {
				
			}
		break; //CPU_CALC_ADDRESS END
		
		case CPU_FETCH_DATA:
			this->fetch_data(make_word(this->opcode_byte_lo, this->opcode_byte_hi));
			this->cpu_status = CPU_EXEC_OPCODE;
		break; //CPU_FETCH_DATA END
		
		case CPU_FETCH_INDEXED:
		break; //CPU_FETCH_INDEXED END
		
		case CPU_FETCH_INDIRECT:
		break; //CPU_FETCH_INDIRECT END
		
		case CPU_EXEC_OPCODE:
			this->cpu_status = CPU_FETCH_OPCODE;
			switch(this->opcode_id[this->opcode]) {
				case _ADC: this->ADC(); this->step(); break;
				case _AHX: this->AHX(); this->step(); break;
				case _ALR: this->ALR(); this->step(); break;
				case _ANC: this->ANC(); this->step(); break;
				case _AND: this->AND(); this->step(); break;
				case _ARR: this->ARR(); this->step(); break;
				case _ASL: this->ASL(); this->step(); break;
				case _AXS: this->AXS(); this->step(); break;
				case _BCC: this->BCC(); this->step(); break;
				case _BCS: this->BCS(); this->step(); break;
				case _BEQ: this->BEQ(); this->step(); break;
				case _BIT: this->BIT(); this->step(); break;
				case _BMI: this->BMI(); this->step(); break;
				case _BNE: this->BNE(); this->step(); break;
				case _BPL: this->BPL(); this->step(); break;
				case _BRK: this->BRK(); this->step(); break;
				case _BVC: this->BVC(); this->step(); break;
				case _CLC: this->CLC(); this->step(); break;
				case _CLD: this->CLD(); this->step(); break;
				case _CLI: this->CLI(); this->step(); break;
				case _CLV: this->CLV(); this->step(); break;
				case _CMP: this->CMP(); this->step(); break;
				case _CPX: this->CPX(); this->step(); break;
				case _CPY: this->CPY(); this->step(); break;
				case _DCP: this->DCP(); this->step(); break;
				case _DEC: this->DEC(); this->step(); break;
				case _EOR: this->EOR(); this->step(); break;
				case _INC: this->INC(); this->step(); break;
				case _INX: this->INX(); this->step(); break;
				case _INY: this->INY(); this->step(); break;
				case _ISC: this->ISC(); this->step(); break;
				case _JMP: this->JMP(); this->step(); break;
				case _JSR: this->JSR(); this->step(); break;
				case _KIL: this->KIL(); this->step(); break;
				case _LAS: this->LAS(); this->step(); break;
				case _LAX: this->LAX(); this->step(); break;
				case _LDA: this->LDA(); this->step(); break;
				case _LDX: this->LDX(); this->step(); break;
				case _LDY: this->LDY(); this->step(); break;
				case _LSR: this->LSR(); this->step(); break;
				case _NOP: this->NOP(); this->step(); break;
				case _ORA: this->ORA(); this->step(); break;
				case _PHA: this->PHA(); this->step(); break;
				case _PHP: this->PHP(); this->step(); break;
				case _PLA: this->PLA(); this->step(); break;
				case _RLA: this->RLA(); this->step(); break;
				case _ROL: this->ROL(); this->step(); break;
				case _ROR: this->ROR(); this->step(); break;
				case _RRA: this->RRA(); this->step(); break;
				case _RTI: this->RTI(); this->step(); break;
				case _RTS: this->RTS(); this->step(); break;
				case _SAX: this->SAX(); this->step(); break;
				case _SBC: this->SBC(); this->step(); break;
				case _SEC: this->SEC(); this->step(); break;
				case _SED: this->SED(); this->step(); break;
				case _SEI: this->SEI(); this->step(); break;
				case _SHA: this->SHA(); this->step(); break;
				case _SHY: this->SHY(); this->step(); break;
				case _SLO: this->SLO(); this->step(); break;
				case _SRE: this->SRE(); this->step(); break;
				case _STA: this->STA(); this->step(); break;
				case _STX: this->STX(); this->step(); break;
				case _STY: this->STY(); this->step(); break;
				case _TAS: this->TAS(); this->step(); break;
				case _TAX: this->TAX(); this->step(); break;
				case _TAY: this->TAY(); this->step(); break;
				case _TSX: this->TSX(); this->step(); break;
				case _TXA: this->TXA(); this->step(); break;
				case _TXS: this->TXS(); this->step(); break;
				case _TYA: this->TYA(); this->step(); break;
				case _XAA: this->XAA(); this->step(); break;
			}
		break; //CPU_EXEC_OPCODE END
	}
}
