#include "Hora.h"

    /* Constructores */
Hora::Hora()
{
    seg = 0L;
}

Hora::Hora(long i)
{
    seg = i;
}
    /* Operadores */
Hora Hora::operator+(const Hora& obj)
{
    return Hora(seg+obj.seg);
}

Hora Hora::operator-(const Hora& obj)
{
    return Hora(seg-obj.seg);
}

Hora Hora::operator+(const int i)
{
    return Hora(seg+i);

}

Hora Hora::operator-(const int i)
{
    return Hora(seg-i);
}

Hora& Hora::operator=(const Hora& obj)
{
    seg = obj.seg;
    return *this;
}

Hora& Hora::operator+=(const Hora& obj)
{
    seg += obj.seg;
    return *this;
}

Hora& Hora::operator-=(const Hora& obj)
{
    seg -= obj.seg;
    return *this;
}

Hora Hora::operator++(int i)
{
    Hora aux(*this);
    seg++;
    return aux;
}

Hora& Hora::operator++()
{
    seg++;
    return *this;
}

bool Hora::operator==(const Hora& obj)
{
    return ((obj.seg==seg)?true:false);
}

bool Hora::operator!=(const Hora& obj)
{
    return ((obj.seg!=seg)?true:false);
}

bool Hora::operator<=(const Hora& obj)
{
    return ((obj.seg<=seg)?true:false);
}

bool Hora::operator<(const Hora& obj)
{
    return ((obj.seg<seg)?true:false);
}

bool Hora::operator>=(const Hora& obj)
{
    return ((obj.seg>=seg)?true:false);
}

bool Hora::operator>(const Hora& obj)
{
    return ((obj.seg>seg)?true:false);
}
    /* Metodos */
