#include "../M6507.h"

unsigned char M6507_Register_8BIT::set(unsigned char value) {
	this->reg_data = value;
	return this->reg_data;
}

unsigned char M6507_Register_8BIT::get() {
	return this->reg_data;
}
