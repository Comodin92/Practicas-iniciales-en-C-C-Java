#ifndef PERCUSION_H_INCLUDED
#define PERCUSION_H_INCLUDED


#include "Instrumento.h"

class Percusion : public Instrumento
{
    public:
            Percusion(string nombre);
            virtual ~Percusion(){};

            Percusion operator++(int);
            Percusion &operator++();
            Percusion operator--(int);
            Percusion &operator--();

            string getDetalles()const;
};
#endif // PERCUSION_H_INCLUDED
