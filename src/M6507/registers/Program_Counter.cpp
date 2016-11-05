#include "../M6507.h"

unsigned short int M6507_Program_Counter::set(unsigned short int value) {
	this->program_counter = value;
	return this->program_counter;
}

unsigned short int M6507_Program_Counter::increment() {
	this->program_counter++;
	return this->program_counter;
}

unsigned short int M6507_Program_Counter::increment(unsigned short int value) {
	this->program_counter += value;
	return this->program_counter;
}

unsigned short int M6507_Program_Counter::get() {
	return this->program_counter;
}

unsigned char M6507_Program_Counter::low() {
	return (unsigned char) this->program_counter & 0xFF;
}

unsigned char M6507_Program_Counter::high() {
	return (unsigned char) (this->program_counter & 0xFF00) >> 8;
}
