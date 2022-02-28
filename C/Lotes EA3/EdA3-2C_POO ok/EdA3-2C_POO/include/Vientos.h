#ifndef VIENTOS_H_INCLUDED
#define VIENTOS_H_INCLUDED


#include "Instrumento.h"

class Vientos : public Instrumento
{
private:
    string detalle;
public:
    Vientos(string nomb, char esc, string det);
    ~Vientos(){};
    string getDetalles() const;
    Vientos& operator--(); //devuelve el obj modificado;
    Vientos operator--(int);
};
/// complete la declaración de la class

#endif // VIENTOS_H_INCLUDED
