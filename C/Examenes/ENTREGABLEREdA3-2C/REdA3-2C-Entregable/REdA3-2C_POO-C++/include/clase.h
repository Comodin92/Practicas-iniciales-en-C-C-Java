#ifndef CLASE_H_INCLUDED
#define CLASE_H_INCLUDED

#include <iostream>
#include <stdlib.h>

using namespace std;

class Racional
{
    private:
    int     nume,
            deno;
    public:
    ///Constructor parametrizado
    Racional(int = 1, int = 1);

    int absoluto(int);
    int mcd(int, int);
    int signo(int);
    int getNumerador();
    int getDenominador();
    int enteroMasCercano();
    void aEnteroYFraccion(Racional);
    Racional operator++();
    friend ostream &operator <<(ostream &, Racional);

};

#endif // CLASE_H_INCLUDED
