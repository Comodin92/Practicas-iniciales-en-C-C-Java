#ifndef PERCUSION_H_INCLUDED
#define PERCUSION_H_INCLUDED


#include "Instrumento.h"

class Percusion : public Instrumento
{
public:
    Percusion(string nomb);
    string getDetalles() const;
    ~Percusion(){};
    Percusion& operator--();
    Percusion operator--(int);
    Percusion& operator++();
    Percusion operator++(int);
};

/// complete la declaración de la class

#endif // PERCUSION_H_INCLUDED
