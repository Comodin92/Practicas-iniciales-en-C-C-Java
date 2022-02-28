#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include <iostream>

class Hora
{
    private:
    int hora,min,seg;
    public:
    /* Constructores */
    Hora();
    Hora(int,int,int);
    /* Operadores */
    Hora operator+(const Hora&);
    Hora operator-(const Hora&);
    Hora operator+(const int);          // suma cantidad de segundos
    Hora operator-(const int);          // resta cantidad de segundos

    Hora& operator=(const Hora&);       // asignacion
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
