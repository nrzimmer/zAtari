#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ctime>
#include "M6507/M6507.h"

using namespace std;

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

  #include <windows.h>

  inline void delay( unsigned long ms )
    {
    Sleep( ms );
    }

#else  /* presume POSIX */

  #include <unistd.h>

  inline void delay( unsigned long ms )
    {
    usleep( ms * 1000 );
    }

#endif


int main(int argc, char** argv) {
	std::srand(std::time(0));
    char dadosrom[4096];
    ifstream myFile("rr.a26", ios::in | ios::binary);
    myFile.read(dadosrom, 4096);
    myFile.close();
    M6507 emu((unsigned char *)dadosrom);
    //unsigned int cycles = 0;
    emu.step();
    printf("PC: %4x\t%s [%2x]\n", emu.get_opcode_pc(), emu.get_opcode_name(emu.get_opcode()).c_str(), emu.get_opcode());
/*    while (!emu.P_brk_command()) {
		if (emu.counter == CPU_READY) {
			std::cin.get();
			//delay(1);
			//cycles++;
			printf("PC: %4x\t%s (%2x)(%2x)\t\tA: %2x\tX: %2x\tY: %2x\tS: %2x\tNV-BDIZC:\t%i%i-%i%i%i%i%i\n", (unsigned short int)emu.PC(), emu.get_opcode_name(emu.last_instruction).c_str(), (unsigned char)emu.last_instruction, (unsigned char)emu.MemoryRead(emu.PC()+1), (unsigned char)emu.A(), (unsigned char)emu.X(), (unsigned char)emu.Y(), (unsigned char)emu.S(),emu.P_negative(), emu.P_overflow(), emu.P_brk_command(), emu.P_decimal_mode(), emu.P_irq_disable(), emu.P_zero(), emu.P_carry());
		}
        emu.step();
    }
    std::cin.get();
    printf("PC: %4x\t%s (%2x)(%2x)\t\tA: %2x\tX: %2x\tY: %2x\tS: %2x\tNV-BDIZC:\t%i%i-%i%i%i%i%i\n", (unsigned short int)emu.PC(), emu.get_opcode_name(emu.last_instruction).c_str(), (unsigned char)emu.last_instruction, (unsigned char)emu.MemoryRead(emu.PC()+1), (unsigned char)emu.A(), (unsigned char)emu.X(), (unsigned char)emu.Y(), (unsigned char)emu.S(),emu.P_negative(), emu.P_overflow(), emu.P_brk_command(), emu.P_decimal_mode(), emu.P_irq_disable(), emu.P_zero(), emu.P_carry());
    printf("\n\nBREAK!!!");
    std::cin.get();*/
    return 0;
}

