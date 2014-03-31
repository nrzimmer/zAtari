/* 
 * File:   main.cpp
 * Author: NatanaelRodrigo
 *
 * Created on 27 de Março de 2014, 15:08
 */

#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include "util.h"
#include "M6507.h"
#include "M6507_Reg_Operations.h"
#include "M6507_Load_Opcodes.h"
#include "M6507_Store_Opcodes.h"
#include "M6507_Arithmetic_Opcodes.h"
#include "M6507_Inc_Dec_Opcodes.h"
#include "M6507_Shit_Rotate_Opcodes.h"
#include "M6507_Logic_Opcodes.h"
#include "M6507_CMP_Test_Bits_Opcodes.h"
#include "M6507_Branch_Opcodes.h"
#include "M6507_Sub_Jump_Opcodes.h"
#include "M6507_Transfer_Opcodes.h"
#include "M6507_Stack_Opcodes.h"
#include "M6507_Set_Clear_Misc_Opcodes.h"

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


/*
 * 
 */
int main(int argc, char** argv) {
    char dadosrom[4096];
    ifstream myFile("c:\\rr.a26", ios::in | ios::binary);
    myFile.read(dadosrom, 4096);
    myFile.close();
    M6507 emu(dadosrom);
    while (!emu.P_brk_command()) {
        system("cls");
        printf("%2x\n\nPC: %4x\tA: %2x\tX: %2x\tY: %2x\tS: %2x\n\n", (unsigned char)emu.last_instruction, (unsigned short int)emu.PC(), (unsigned char)emu.A(), (unsigned char)emu.X(), (unsigned char)emu.Y(), (unsigned char)emu.S());
        printf("P: %i%i-%i%i%i%i%i\n   NV-BDIZC\n\n", emu.P_negative(), emu.P_overflow(), emu.P_brk_command(), emu.P_decimal_mode(), emu.P_irq_disable(), emu.P_zero(), emu.P_carry());
        if (emu.PC() == 0xf018)
            std::cin.get();
        //delay(1500);
        emu.step();
    }
    std::cin.get();
   
    system("cls");
        printf("%2x\n\nPC: %4x\tA: %2x\tX: %2x\tY: %2x\tS: %2x\n\n", (unsigned char)emu.last_instruction, (unsigned char)emu.PC(), (unsigned char)emu.A(), (unsigned char)emu.X(), (unsigned char)emu.Y(), (unsigned char)emu.S());
    printf("P: %i%i-%i%i%i%i%i\n   NV-BDIZC\n\n", emu.P_negative(), emu.P_overflow(), emu.P_brk_command(), emu.P_decimal_mode(), emu.P_irq_disable(), emu.P_zero(), emu.P_carry());
    printf("\n\nBREAK!!!");
    std::cin.get();
    return 0;
}

