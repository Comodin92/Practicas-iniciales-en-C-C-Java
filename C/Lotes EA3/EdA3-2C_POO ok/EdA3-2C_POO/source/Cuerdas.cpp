#include "../include/Cuerdas.h"

Cuerdas::Cuerdas(string nomb, char esc) : Instrumento(nomb,esc)
{}

string Cuerdas::getDetalles() const
{
    return "";
}

Cuerdas& Cuerdas::operator++()
{
    this->escala++;
    this->ajustarEscala();
    return *this;
}

Cuerdas Cuerdas::operator++(int)
{
    Cuerdas aux(*this);

    this->escala++;
    this->ajustarEscala();

    return aux;
}

/// complete el desarrollo de los métodos de la class

