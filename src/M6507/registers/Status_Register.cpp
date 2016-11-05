#include "../M6507.h"

#define b_carry 0
#define b_zero 1
#define b_irq_disable 2
#define b_decimal_mode 3
#define b_brk_command 4
#define b_overflow 6
#define b_negative 7

bool M6507_Status_Register::carry() {
    return get_bit(this->reg_data, b_carry);
}

bool M6507_Status_Register::zero() {
    return get_bit(this->reg_data, b_zero);
}

bool M6507_Status_Register::irq_disable() {
    return get_bit(this->reg_data, b_irq_disable);
}

bool M6507_Status_Register::decimal_mode() {
    return get_bit(this->reg_data, b_decimal_mode);
}

bool M6507_Status_Register::brk_command() {
    return get_bit(this->reg_data, b_brk_command);
}

bool M6507_Status_Register::overflow() {
    return get_bit(this->reg_data, b_overflow);
}

bool M6507_Status_Register::negative() {
    return get_bit(this->reg_data, b_negative);
}

void M6507_Status_Register::bit_change(bool enable, unsigned char bit) {
	if (enable)
		this->reg_data = set_bit(this->reg_data, bit);
	else
		this->reg_data = clear_bit(this->reg_data, bit);
}

void M6507_Status_Register::carry(bool valor) {
	this->bit_change(valor, b_carry);
}

void M6507_Status_Register::zero(bool valor) {
	this->bit_change(valor, b_zero);
}

void M6507_Status_Register::irq_disable(bool valor) {
	this->bit_change(valor, b_irq_disable);
}

void M6507_Status_Register::decimal_mode(bool valor) {
	this->bit_change(valor, b_decimal_mode);
}

void M6507_Status_Register::brk_command(bool valor) {
	this->bit_change(valor, b_brk_command);
}

void M6507_Status_Register::overflow(bool valor) {
	this->bit_change(valor, b_overflow);
}

void M6507_Status_Register::negative(bool valor) {
	this->bit_change(valor, b_negative);
}
