#ifndef VIENTOS_H_INCLUDED
#define VIENTOS_H_INCLUDED


#include "Instrumento.h"

class Vientos : public Instrumento
{
    private:
    string _material;

    public:
            Vientos(string nombre, char escala, string material);
            virtual ~Vientos(){};
            Vientos operator --(int);
            string getDetalles()const;
            Vientos& operator --();
};
#endif // VIENTOS_H_INCLUDED
