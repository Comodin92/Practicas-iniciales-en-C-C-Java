#include "../include/Instrumento.h"
#include "../include/CambioEscalaException.h"

Instrumento::Instrumento(string nomb, char esc)
{
    this->nombre = nomb;
    this->escala = esc;
}

string Instrumento::getNombre() const
{
    return this->nombre;
}

char Instrumento::getEscala() const
{
    return this->escala;
}

void Instrumento::ajustarEscala()
{
    if(escala>'G')
        escala = 'A';
    if(escala<'A')
        escala = 'G';
}

/// complete el desarrollo de los métodos de la class

