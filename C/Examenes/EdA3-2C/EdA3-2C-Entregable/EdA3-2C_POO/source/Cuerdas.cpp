#include <string.h>
#include "../include/Cuerdas.h"

/// complete el desarrollo de los métodos de la class
Cuerdas:: ~Cuerdas()
{
}


Cuerdas::Cuerdas(string nombre, char escala) : Instrumento(nombre,escala)
{
//    this->nombre = nombre;
//    this->escala = escala;
}
string Cuerdas::getDetalles()const
{
    return "hola";

}


Cuerdas  Cuerdas :: operator++(int)
{
    Cuerdas aux(*this); ///Cuerdas aux(this->_nombre, this->_escala);
    this->_escala ++ ;
    this->ajustarEscala();
    return aux;
}

Cuerdas &Cuerdas::operator++()
{
    this->_escala ++ ;
    this->ajustarEscala();

    return *this;
}
