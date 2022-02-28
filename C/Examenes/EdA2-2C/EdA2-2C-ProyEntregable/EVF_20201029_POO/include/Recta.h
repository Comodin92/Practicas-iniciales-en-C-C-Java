#ifndef RECTA_H
#define RECTA_H

#include <iostream>

#include "Punto.h"

using namespace std;


class Recta
{
private:
    Punto p1,p2;

public:
    Recta(const Punto& p1 , const Punto& p2);
    Punto operator&&(const Recta& p)const;
    ///es un metodo perteneciente a la clase ya que el obj llamador pertenece a la misma
    double operator -(const Punto &p)const;
    ///El objeto llamador pertenece a la clase, de caso contrario, se usaria friend
    friend ostream& operator <<(ostream& sal, const Recta& r);
};
#endif // RECTA_H
