#include "../include/Vientos.h"

Vientos::Vientos(string nomb, char esc, string det)
: Instrumento(nomb,esc), detalle(det)
{}

string Vientos::getDetalles() const
{
    return "material:" + this->detalle;
}

Vientos& Vientos::operator--()
{
    this->escala--;
    this->ajustarEscala();
    return *this;
}

Vientos Vientos::operator--(int)
{
    Vientos aux(*this);

    this->escala--;
    this->ajustarEscala();

    return aux;
}


/// complete el desarrollo de los métodos de la class

