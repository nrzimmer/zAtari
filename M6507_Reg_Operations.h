/* 
 * File:   M6507_Reg_Operations.h
 * Author: NatanaelRodrigo
 *
 * Created on 27 de Março de 2014, 15:16
 */

#ifndef M6507_REG_OPERATIONS_H
#define	M6507_REG_OPERATIONS_H

bool M6507::P_carry() {
    return this->reg_carry;
}

bool M6507::P_zero() {
    return this->reg_zero;
}

bool M6507::P_irq_disable() {
    return this->reg_irq_disable;
}

bool M6507::P_decimal_mode() {
    return this->reg_decimal_mode;
}

bool M6507::P_brk_command() {
    return this->reg_brk_command;
}

bool M6507::P_overflow() {
    return this->reg_overflow;
}

bool M6507::P_negative() {
    return this->reg_negative;
}

char M6507::A() {
    return this->reg_a;
}

char M6507::Y() {
    return this->reg_y;
}

char M6507::X() {
    return this->reg_x;
}

char M6507::S() {
    return this->reg_s;
}

char M6507::P() {
    return this->reg_p;
}

unsigned short int M6507::PC() {
    return this->reg_pc;
}

unsigned char M6507::PC_H() {
    return this->reg_pc_h;
}

unsigned char M6507::PC_L() {
    return this->reg_pc_l;
}

void M6507::P_carry(bool valor) {
    if (this->reg_carry != valor) {
        if (this->reg_carry == 0) {
            this->reg_p += v_carry;
        } else {
            this->reg_p -= v_carry;
        }
        this->reg_carry = valor;
    }
}

void M6507::P_zero(bool valor) {
    if (this->reg_zero != valor) {
        if (this->reg_zero == 0) {
            this->reg_p += v_zero;
        } else {
            this->reg_p -= v_zero;
        }
        this->reg_zero = valor;
    }
}

void M6507::P_irq_disable(bool valor) {
    if (this->reg_irq_disable != valor) {
        if (this->reg_irq_disable == 0) {
            this->reg_p += v_irq_disable;
        } else {
            this->reg_p -= v_irq_disable;
        }
        this->reg_irq_disable = valor;
    }
}

void M6507::P_decimal_mode(bool valor) {
    if (this->reg_decimal_mode != valor) {
        if (this->reg_decimal_mode == 0) {
            this->reg_p += v_decimal_mode;
        } else {
            this->reg_p -= v_decimal_mode;
        }
        this->reg_decimal_mode = valor;
    }
}

void M6507::P_brk_command(bool valor) {
    if (this->reg_brk_command != valor) {
        if (this->reg_brk_command == 0) {
            this->reg_p += v_brk_command;
        } else {
            this->reg_p -= v_brk_command;
        }
        this->reg_brk_command = valor;
    }
}

void M6507::P_overflow(bool valor) {
    if (this->reg_overflow != valor) {
        if (this->reg_overflow == 0) {
            this->reg_p += v_overflow;
        } else {
            this->reg_p -= v_overflow;
        }
        this->reg_overflow = valor;
    }
}

void M6507::P_negative(bool valor) {
    if (this->reg_negative != valor) {
        if (this->reg_negative == 0) {
            this->reg_p += v_negative;
        } else {
            this->reg_p -= v_negative;
        }
        this->reg_negative = valor;
    }
}

void M6507::A(char valor) {
    this->reg_a = valor;
}

void M6507::Y(char valor) {
    this->reg_y = valor;
}

void M6507::X(char valor) {
    this->reg_x = valor;
}

void M6507::S(char valor) {
    this->reg_s = valor;
}

void M6507::PC(unsigned short int valor) {
    char valor_temp = 0;
    this->reg_pc = valor;
    if ((valor - 32768) >= 0) {
        valor -= 32768;
        valor_temp += 128;
    }
    if ((valor - 16384) >= 0) {
        valor -= 16384;
        valor_temp += 64;
    }
    if ((valor - 8192) >= 0) {
        valor -= 8192;
        valor_temp += 32;
    }
    if ((valor - 4096) >= 0) {
        valor -= 4096;
        valor_temp += 16;
    }
    if ((valor - 2048) >= 0) {
        valor -= 2048;
        valor_temp += 8;
    }
    if ((valor - 1024) >= 0) {
        valor -= 1024;
        valor_temp += 4;
    }
    if ((valor - 512) >= 0) {
        valor -= 512;
        valor_temp += 2;
    }
    if ((valor - 256) >= 0) {
        valor -= 256;
        valor_temp += 1;
    }
    this->reg_pc_h = valor_temp;
    this->reg_pc_l = (char) valor;
}

void M6507::update_zero_flag(char valor) {
    if (valor == 0)
        this->P_zero(true);
    else
        this->P_zero(false);
}

void M6507::update_negative_flag(char valor) {
    this->P_negative(get_bit(valor,7));
}

void M6507::update_overflow_flag(short int valor) {
    if (valor < -128 || valor > 127)
        this->P_overflow(true);
    else
        this->P_overflow(false);

}

void M6507::update_carry_flag(short int valor) {
    if ((int)(unsigned short int)valor < 0 || (int)(unsigned short int)valor > 255)
        this->P_carry(true);
    else
        this->P_carry(false);    
}

void M6507::P(char valor) {
    this->reg_p = valor;
    this->reg_carry = valor & (1 << 0);
    this->reg_zero = valor & (1 << 1);
    this->reg_irq_disable = valor & (1 << 2);
    this->reg_decimal_mode = valor & (1 << 3);
    this->reg_brk_command = valor & (1 << 4);
    this->reg_overflow = valor & (1 << 6);
    this->reg_negative = valor & (1 << 7);
}

#endif	/* M6507_REG_OPERATIONS_H */