#ifndef CUERDAS_H_INCLUDED
#define CUERDAS_H_INCLUDED

#include "Instrumento.h"


class Cuerdas : public Instrumento
{
public:
    Cuerdas(string nombre, char escala);
     ~Cuerdas();
    Cuerdas operator ++ (int);///POST INCREMENTO, ASIGNA LUEGO INCREMENTA
    Cuerdas& operator ++();///PRE INCREMENTO, INCREMENTA LUEGO ASIGN
    string getDetalles()const;

/// complete la declaración de la class
};
#endif // CUERDAS_H_INCLUDED
