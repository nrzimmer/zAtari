#include "data_manipulation.h"

unsigned short int make_word(unsigned char lo, unsigned char hi) {
    return (unsigned short int) lo | ((unsigned short int) hi << 8);
}

unsigned char lo_byte(unsigned short int valor) {
    return (unsigned char) (unsigned short int) 255 & valor;
}

unsigned char hi_byte(unsigned short int valor) {
    return (unsigned char) ((0xFF00 & valor) >> 8);
}

unsigned char set_bit(unsigned char valor, unsigned char bit) {
    return valor | (1 << bit);
}

unsigned char clear_bit(unsigned char valor, unsigned char bit) {
    return valor & ~(1 << bit);
}

bool get_bit(unsigned char valor, unsigned char bit) {
    return valor & (1 << bit);
}

unsigned char ZeroPage(unsigned short int valor) {
	return (unsigned char) valor & 0xFF;
}

unsigned char random_char() {
	return (unsigned char) std::rand() & 0xFF;
}
