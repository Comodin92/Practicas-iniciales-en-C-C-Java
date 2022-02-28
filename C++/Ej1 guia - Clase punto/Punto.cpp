#include "punto.h"

/* Constructores */
Punto::Punto()
{
    coordX = 512;       //centro de la pantalla
    coordY = 384;
}

Punto::Punto(const Punto& obj)
{
    coordX = obj.coordX;
    coordY = obj.coordY;
}

Punto::Punto(int x)
{
    coordX = x;
    coordY = (3*x)/4;
}

Punto::Punto(int x, int y)
{
    coordX = x;
    coordY = y;
}

/* Sobrecarga de operadores */
Punto& Punto::operator=(const Punto& obj)
{
    coordX = obj.coordX;
    coordY = obj.coordY;
    return *this;
}

Punto& Punto::operator+=(const Punto& obj)
{
    coordX += obj.coordX;
    coordY += obj.coordY;
    return *this;
}

Punto& Punto::operator-=(const Punto& obj)
{
    coordX-=obj.coordX;
    coordY-=obj.coordY;
    return *this;
}
Punto Punto::operator++(int a)              //posincremento
{
    Punto aux(*this);
    coordX++;
    coordY++;
    return aux;
}

Punto& Punto::operator++()              //preincremento
{
    coordX++;
    coordY++;
    return *this;
}

Punto Punto::operator--(int a)          //posdecremento
{
    Punto aux(*this);
    coordX--;
    coordY--;
    return aux;
}

Punto& Punto::operator--()          //predecremento
{
    coordX--;
    coordY--;
    return *this;
}

ostream& operator<<(ostream& sal,const Punto& obj)
{
    sal<<"("<<obj.coordX<<","<<obj.coordY<<")"<<endl;
    return sal;
}

istream& operator>>(istream& ent,Punto &obj)
{
    cout<<"Ingrese X: "<<endl;
    ent>>obj.coordX;
    cout<<"Ingrese Y: "<<endl;
    ent>>obj.coordY;
    return ent;
}

Punto Punto::operator+(const Punto& obj)
{
    return Punto(obj.coordX+coordX,obj.coordY+coordY);
}

Punto Punto::operator-(const Punto& obj)
{
    return Punto(obj.coordX-coordX,obj.coordY-coordY);
}
/* Metodos */
void Punto::mostrar()
{
    cout<<"("<<coordX<<","<<coordY<<")"<<endl;
}

/* Destructor */
/*Punto::~Punto()
{
    cout<<"("<<coordX<<","<<coordY<<")"<<endl;
    cout<<"Direccion: "<<this<<endl;
}
*/
