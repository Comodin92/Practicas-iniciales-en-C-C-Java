#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include <iostream>

class Hora
{
    private:
    long seg;
    public:
    /* Constructores */
    Hora();
    Hora(long);
    /* Operadores */
    Hora operator+(const Hora&);
    Hora operator-(const Hora&);
    Hora operator+(const int);
    Hora operator-(const int);

    Hora& operator=(const Hora&);
    Hora& operator+=(const Hora&);
    Hora& operator-=(const Hora&);

    Hora operator++(int);               //posincremento
    Hora& operator++();

    bool operator==(const Hora&);
    bool operator!=(const Hora&);
    bool operator<=(const Hora&);
    bool operator<(const Hora&);
    bool operator>=(const Hora&);
    bool operator>(const Hora&);
    /* Metodos */


};


#endif // HORA_H_INCLUDED
