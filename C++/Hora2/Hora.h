#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include <iostream>

using namespace std;

class Hora
{   int dias;
    int horas;
    int minutos;
    int segundos;

public:

    Hora();

    Hora(int);

    void mostrar();

    Hora  operator++(int);

    Hora & operator--();

friend  ostream& operator<<(ostream &, const Hora &);

friend istream & operator>>(istream &, Hora &);
};


#endif // HORA_H_INCLUDED
