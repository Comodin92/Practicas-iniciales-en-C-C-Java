#ifndef IRRACIONAL_H_INCLUDED
#define IRRACIONAL_H_INCLUDED
#include <stdlib.h>
#include <iostream>

using namespace std;

class Irracional{
private:
    int numerador;
    int denominador;

public:
    Irracional(int = 0, int = 0);
    int real(const Irracional&);
    friend istream& operator >>(istream&, Irracional&);
    friend ostream& operator <<(ostream&, const Irracional&);
    friend Irracional operator +(int, const Irracional&);
    Irracional & operator += (const Irracional&);
    Irracional & operator = (const Irracional&);
    Irracional operator + (const Irracional&);
    Irracional operator * (const Irracional&);
    bool operator != (const Irracional&);
};

#endif // IRRACIONAL_H_INCLUDED
