#ifndef DATA_MANIP_H
#define	DATA_MANIP_H

#include <iostream>
#include <ctime>

unsigned short int make_word(unsigned char lo, unsigned char hi);
unsigned char lo_byte(unsigned short int valor);
unsigned char hi_byte(unsigned short int valor);
unsigned char set_bit(unsigned char valor, unsigned char bit);
unsigned char clear_bit(unsigned char valor, unsigned char bit);
unsigned short int ZeroPage(unsigned short int valor);
unsigned char random_char();
bool get_bit(unsigned char valor, unsigned char bit);

#endif	/* DATA_MANIP_H */
