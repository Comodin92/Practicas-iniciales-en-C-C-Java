#ifndef CUERDAS_H_INCLUDED
#define CUERDAS_H_INCLUDED


#include "Instrumento.h"

class Cuerdas : public Instrumento
{
public:
    Cuerdas(string nomb, char esc);
    ~Cuerdas(){};
    string getDetalles() const;
    Cuerdas& operator++(); //devuelve el obj modificado;
    Cuerdas operator++(int); //devuelve copia;
};
/// complete la declaración de la class

#endif // CUERDAS_H_INCLUDED
