/* 
 * File:   main.cpp
 * Author: NatanaelRodrigo
 *
 * Created on 27 de Março de 2014, 15:08
 */

#include <cstdlib>
#include <cstdio>
#include <math.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int a,b,c;
    a = b = 1;
    b |= (1 << 2);
    c = b;
    c &= ~(1 << 0);
    printf("%i\n%i\n%i\n",a,b,c);
    scanf("%s");
    return 0;
}

