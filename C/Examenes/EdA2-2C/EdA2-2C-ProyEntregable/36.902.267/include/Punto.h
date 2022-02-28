#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;


class Punto
{
private:
    double x, y;

public:
    ///Con este constructor es suficiente, si le asigno valor al crearlo me lo carga pero
    ///si no me asigna ningun valor se incializa con 0 (en el parametro sin valor)
    Punto(double x=0, double y=0);

    Punto operator - (const Punto& p) const;
    ///Se utilizan para acceder a las atributos privados x y desde afuera del
    ///encapsulamiento
    void setX(double);
    double getX(void) const;
    void setY(double);
    double getY(void) const;
    friend ostream& operator <<(ostream& sal, const Punto& obj);
};
#endif // PUNTO_H
