#include "M6507.h"
#include <cstdio>

unsigned char M6507::MemoryRead(unsigned short int addr) {
    addr &= 0x1FFF;
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
     * !0x1200	  0x80
     * xxx0 xx0x  1??? ????
     */
    if (((0x1200 & addr) == 0) && ((0x80 & addr) == 0x80)) {
        addr &= 0xFF;
        return this->memory_block[addr];
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
         * !0x1004
         * 0x280
         * xxx0 xx1x 1xxx x0??
         */
        if (((0x1004 & addr) == 0) && ((0x280 & addr) == 0x280)) {
				addr &= 0x283;
				return this->memory_block[addr];
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
             * !0x1000
             * 0x294
             * xxx0 xx1x 1xx1 ?1??
             */
            if (((addr & 0x1000) == 0) && ((addr & 0x294) == 0x294)) {
					addr &= 0x29f;
					return this->memory_block[addr];
            } else {
                /*
                 * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
                 * $02Ax - $02Fx = same mirrors as $029x shown below
                 * $029E, $029C, $0296, $0294 = mirrors of $028E, $028C, $0286, and $0284
                 * $028E = mirror of $028C
                 * $028C = enable the timer interrupt and read the timer
                 * $0286 = mirror of $0284
                 * $0284 = disable the timer interrupt and read the timer
                 * !0x1001
                 * 0x284
                 * xxx0 xx1x 1xxx ?1x0
                 */
                if (((addr & 0x1001) == 0) && ((addr & 0x284) == 0x284)) {
						addr &= 0x28C;
						return this->memory_block[addr];
                } else {
                    /*
                     * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
                     * $029x - $02Fx = same mirrors as $028x shown below
                     * $028F, $028D, $0287 = mirrors of $0285
                     * $0285 = read the interrupt flags
                     * !0x1000
                     * 0x285
                     * xxx0 xx1x 1xxx x1x1
                     */
                    if (((addr & 0x1000) == 0) && ((addr & 0x285) == 0x285)) {
							return this->memory_block[0x285];
                    } else {
                        /*
                         * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
                         * $02Ax, $02Cx, $02Ex = same mirrors as $028x shown below
                         * $028C - $028F = mirrors of $0284 - $0287
                         * $0287 = enable the PA7 interrupt and select positive edge-detect
                         * $0286 = enable the PA7 interrupt and select negative edge-detect
                         * $0285 = disable the PA7 interrupt and select positive edge-detect
                         * $0284 = disable the PA7 interrupt and select negative edge-detect
                         * !0x1010
                         * 0x284
                         * xxx0 xx1x 1xx0 x1??
                         */
                        if (((addr & 0x1010) == 0) && ((addr & 0x284) == 0x284)) {
                                addr &= 0x287;
								return this->memory_block[addr];
                        } else {
                                return this->memory_block[addr];
                        }
                    }
                }
            }
        }
    }
}

unsigned char M6507::MemoryReadZeroPage(unsigned char addr) {
    return this->MemoryRead(ZeroPage(addr));
}

void M6507::MemoryWrite(unsigned short int addr, unsigned char valor) {
    addr &= 0x1FFF;
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
     * !0x1200	  0x80
     * xxx0 xx0x  1??? ????
     */
    if (((0x1200 & addr) == 0) && ((0x80 & addr) == 0x80)) {
        addr &= 0xFF;
        this->memory_block[addr] = valor;
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
         * !0x1004
         * 0x280
         * xxx0 xx1x 1xxx x0??
         */
        if (((0x1004 & addr) == 0) && ((0x280 & addr) == 0x280)) {
				addr &= 0x283;
				this->memory_block[addr] = valor;
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
             * !0x1000
             * 0x294
             * xxx0 xx1x 1xx1 ?1??
             */
            if (((addr & 0x1000) == 0) && ((addr & 0x294) == 0x294)) {
					addr &= 0x29f;
					this->memory_block[addr] = valor;
            } else {
                /*
                 * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
                 * $02Ax - $02Fx = same mirrors as $029x shown below
                 * $029E, $029C, $0296, $0294 = mirrors of $028E, $028C, $0286, and $0284
                 * $028E = mirror of $028C
                 * $028C = enable the timer interrupt and read the timer
                 * $0286 = mirror of $0284
                 * $0284 = disable the timer interrupt and read the timer
                 * !0x1001
                 * 0x284
                 * xxx0 xx1x 1xxx ?1x0
                 */
                if (((addr & 0x1001) == 0) && ((addr & 0x284) == 0x284)) {
						addr &= 0x28C;
						this->memory_block[addr] = valor;
                } else {
                    /*
                     * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
                     * $029x - $02Fx = same mirrors as $028x shown below
                     * $028F, $028D, $0287 = mirrors of $0285
                     * $0285 = read the interrupt flags
                     * !0x1000
                     * 0x285
                     * xxx0 xx1x 1xxx x1x1
                     */
                    if (((addr & 0x1000) == 0) && ((addr & 0x285) == 0x285)) {
							this->memory_block[0x285] = valor;
                    } else {
                        /*
                         * $0Fxx, $0Exx, $0Bxx, $0Axx, $07xx, $06xx, $03xx = same mirrors as $02xx shown below
                         * $02Ax, $02Cx, $02Ex = same mirrors as $028x shown below
                         * $028C - $028F = mirrors of $0284 - $0287
                         * $0287 = enable the PA7 interrupt and select positive edge-detect
                         * $0286 = enable the PA7 interrupt and select negative edge-detect
                         * $0285 = disable the PA7 interrupt and select positive edge-detect
                         * $0284 = disable the PA7 interrupt and select negative edge-detect
                         * !0x1010
                         * 0x284
                         * xxx0 xx1x 1xx0 x1??
                         */
                        if (((addr & 0x1010) == 0) && ((addr & 0x284) == 0x284)) {
                                addr &= 0x287;
								this->memory_block[addr] = valor;
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
                            } else {
                                this->memory_block[addr] = valor;
							}
                        }
                    }
                }
            }
        }
    }
}

/*
unsigned char M6507::pop_stack() {
    unsigned char sp = this->S().set(this->S().get() + 1);
    return this->MemoryRead(0x80 + sp);
}

void M6507::push_stack(unsigned char valor) {
    unsigned char sp = this->S().set(this->S().get() - 1);
    this->MemoryWrite(0x81 + sp, valor);
}
*/

M6507::M6507(unsigned char ROM[4096]) {
    int i;
    for (i = 0; i <= 0x1FFF; i++) {
		this->memory_block[i] = random_char();
	}
    for (i = 4096; i < 8192; i++)
        this->memory_block[i] = ROM[i - 4096];
    this->reg_p.carry(false);
    this->reg_p.zero(false);
    this->reg_p.irq_disable(false);
    this->reg_p.decimal_mode(false);
    this->reg_p.brk_command(false);
    this->reg_p.overflow(false);
    this->reg_p.negative(false);
    this->A()->set(0);
    this->Y()->set(0);
    this->X()->set(0);
    this->S()->set(0);
    this->PC()->set(make_word(this->MemoryRead(0xFFFC), this->MemoryRead(0xFFFD)));
    this->opcode = 0;
    this->RIOT_IO[0] = 0x02;
    this->RIOT_IO[1] = 0x03;
    this->RIOT_IO[2] = 0x06;
    this->RIOT_IO[3] = 0x07;
    this->RIOT_IO[4] = 0x0A;
    this->RIOT_IO[5] = 0x0B;
    this->RIOT_IO[6] = 0x0E;
    this->RIOT_IO[7] = 0x0F;
    this->cpu_status = 0x00;
    this->opcode_pc = 0x1234;
}

std::string M6507::get_opcode_name(unsigned char valor) {
	return this->opcode_name[valor];
}

M6507_Register_8BIT* M6507::A() {
	return &this->reg_a;
}

M6507_Register_8BIT* M6507::Y() {
	return &this->reg_y;
}

M6507_Register_8BIT* M6507::X() {
	return &this->reg_x;
}

M6507_Register_8BIT* M6507::S() {
	return &this->reg_s;
}

M6507_Status_Register* M6507::P() {
	return &this->reg_p;
}

M6507_Program_Counter* M6507::PC() {
	return &this->reg_pc;
}

unsigned char M6507::get_opcode() {
	return this->opcode;
}

unsigned short int M6507::get_opcode_pc() {
	return this->opcode_pc;
}
