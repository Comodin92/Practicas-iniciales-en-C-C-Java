#include <string.h>
#include "../include/Percusion.h"
#include "../include/CambioEscalaException.h"
#include "../include/Instrumento.h"


/// complete el desarrollo de los métodos de la class

Percusion::Percusion( string nombre):Instrumento(nombre, 'X')
{


//    this->Nombre=Nombre;
//    this->Escala='X';
//    this->Detalles="";
//    if(Escala!='C'&&Escala!='E'&&Escala!='F'&&Escala!='D'&&Escala!='A'&&Escala!='B'&&Escala!='X')
//       throw ("No se registraron cambios");

}

string Percusion::getDetalles()const
{
    return "";
}

Percusion Percusion::operator++(int)
{
    throw CambioEscalaException();
}

Percusion &Percusion::operator++()
{
    throw CambioEscalaException();
}
Percusion Percusion::operator--(int)
{
    throw CambioEscalaException();
}

Percusion &Percusion::operator--()
{
    throw CambioEscalaException();
}
