#include "../include/Instrumento.h"





/// complete el desarrollo de los métodos de la class

Instrumento::Instrumento(string nombre, char escala):_nombre(nombre), _escala(escala)
{

}

string Instrumento::getNombre()const
{
    return _nombre;
}

char Instrumento::getEscala()const
{
    return _escala;
}

void Instrumento :: ajustarEscala()
{
    if(_escala > 'G')
        _escala -= ('G' - 'A' + 1);
    if(_escala < 'A')
        _escala += ('G' - 'A' +1);
}
