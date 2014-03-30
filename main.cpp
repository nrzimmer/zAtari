/* 
 * File:   main.cpp
 * Author: NatanaelRodrigo
 *
 * Created on 27 de Março de 2014, 15:08
 */

#include <cstdlib>
#include <cstdio>
#include <math.h>
#include "util.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    printf("%i\n%i,%i\n",make_word(1,2),lo_byte(make_word(1,2)),hi_byte(make_word(1,2)));
    scanf("%s");
    return 0;
}

