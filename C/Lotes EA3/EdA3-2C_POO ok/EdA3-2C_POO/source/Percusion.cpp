#include <string.h>
#include "../include/Percusion.h"
#include "../include/CambioEscalaException.h"

Percusion::Percusion(string nomb)
    : Instrumento(nomb,'X')
{}

string Percusion::getDetalles() const
{
    return "";
}

Percusion& Percusion::operator--()
{
    throw CambioEscalaException();
}
Percusion Percusion::operator--(int)
{
    throw CambioEscalaException();
}
Percusion& Percusion::operator++()
{
    throw CambioEscalaException();
}
Percusion Percusion::operator++(int)
{
    throw CambioEscalaException();
}

/// complete el desarrollo de los métodos de la class

