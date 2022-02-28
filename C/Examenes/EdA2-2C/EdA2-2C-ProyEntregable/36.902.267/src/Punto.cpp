#include <math.h>
#include "Punto.h"

Punto::Punto(double x ,double y)
{
    this->x = x;
    this->y = y;
}

Punto Punto::operator - (const Punto& p) const
{
    return Punto( this->x - p.x , this->y - p.y);
}

double Punto::getY(void) const
{
    return y;
}

void Punto::setY(double y)
{
    this->y = y;
}

double Punto::getX(void) const
{
    return x;
}

void Punto::setX(double x)
{
    this->x = x;
}

ostream& operator <<(ostream& sal, const Punto& obj){
sal<<"("<<obj.getX()<<", "<<obj.getY()<<")";
return sal;
}

