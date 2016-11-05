#include "M6507.h"

#define CPU_FETCH_OPCODE 	0x00
#define CPU_PARSE_OPCODE 	0x01

void M6507::step() {
	switch (this->cpu_status) {
		case CPU_FETCH_OPCODE:
			this->opcode_pc = this->PC()->get();
			this->opcode = this->MemoryRead(this->opcode_pc);
			this->PC()->increment();
			this->cpu_status = CPU_PARSE_OPCODE;
		break;
		case CPU_PARSE_OPCODE:
			
		break;
	}
}
