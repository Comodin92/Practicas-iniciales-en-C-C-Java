#include "Fecha.h"

/* Constructores */
Fecha::Fecha(long d)
{
    dd = d;
}

Fecha::Fecha(const Fecha& obj)
{
    dd = obj.dd;
}

/* Operadores */
Fecha Fecha::operator++(int a)      //posincremento
{
    Fecha aux(*this);
    dd++;
    return aux;
}

Fecha& Fecha::operator++()      //preincremento
{
    dd++;
    return *this;
}

Fecha Fecha::operator--(int)
{
    Fecha aux(*this);
    dd--;
    return aux;
}

Fecha& Fecha::operator--()
{
    dd--;

    return *this;
}

Fecha& Fecha::operator=(const Fecha& obj)
{
    dd = obj.dd;
    return *this;
}

Fecha& Fecha::operator+=(const Fecha& obj)
{
    dd += obj.dd;
    return *this;
}

Fecha Fecha::operator+(const Fecha& obj)
{
    Fecha aux(*this);
    aux.dd += obj.dd;
    return aux;
}

Fecha Fecha::operator-(const Fecha& obj)
{
    Fecha aux(*this);
    aux.dd -= obj.dd;
    return aux;
}

Fecha& Fecha::operator-=(const Fecha& obj)
{
    dd -= obj.dd;
    return *this;
}

bool Fecha::operator<(const Fecha& obj)
{
    return (dd-obj.dd<0?true:false);
}

bool Fecha::operator<=(const Fecha& obj)
{
    return (dd-obj.dd<=0?true:false);
}

bool Fecha::operator>(const Fecha& obj)
{
    return (dd-obj.dd>0?true:false);
}

bool Fecha::operator>=(const Fecha& obj)
{
    return (dd-obj.dd>=0?true:false);
}

bool Fecha::operator==(const Fecha& obj)
{
    return (dd-obj.dd==0?true:false);
}

bool Fecha::operator!=(const Fecha& obj)
{
    return (dd-obj.dd!=0?true:false);
}

ostream& operator<<(ostream& sal, const Fecha& obj)
{
    cout<<"Dia: "<<obj.dd<<endl;
    return sal;
}

istream& operator>>(istream& ent, const Fecha& obj)
{
    cout<<"Ingrese dia: ";
    ent>>obj.dd;
    cout<<endl;
    return ent;
}

