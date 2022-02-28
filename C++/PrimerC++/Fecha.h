#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>

using namespace std;

class Fecha{
    long diaRel;

public:
    Fecha (long = 1901);
    Fecha& operator = (const Fecha&);
    friend istream& operator>>(istream&, Fecha&);//CIN AL SER FUNCON AMIGA ESTOY DICIENDO QUE TENDRA ACCESO A LOS MIEMBROS PRIVADOS DE LA CLASE
    friend ostream& operator<<(ostream&, const Fecha&);//COUT
    };

#endif // FECHA_H_INCLUDED
