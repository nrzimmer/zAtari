/* 
 * File:   util.h
 * Author: NatanaelRodrigo
 *
 * Created on 28 de Março de 2014, 16:58
 */
#ifndef UTIL_H
#define	UTIL_H

short int make_word(char lo, char hi) {
    return (short int) lo | ((short int) hi << 8);
}

char lo_byte(short int valor) {
    return (char) (short int) 255 & valor;
}

char hi_byte(short int valor) {
    short int mask = 255 << 8;
    return (char) ((mask & valor) >> 8);
}

char set_bit(char valor, char bit) {
    return valor | (1 << bit);
}

char clear_bit(char valor, char bit) {
    return valor & ~(1 << bit);
}

bool get_bit(char valor, char bit) {
    return valor & (1 << bit);
}

#endif	/* UTIL_H */

