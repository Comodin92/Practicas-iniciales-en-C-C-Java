#include "Titular.h"

Titular::Titular()
{
    nroCta=0;
    descA=0;
}

Titular::~Titular()
{
    //dtor
}

Titular::Titular(const Titular& obj)
{
    nroCta=obj.nroCta;
    descA=obj.descA;
}

Titular::Titular(long nroCta,double descA)
{
    this->nroCta=nroCta;
    this->descA=descA;
}

ostream& operator<<(ostream& sal,const Titular& obj)
{
    sal<<"Nro Cuenta: "<<obj.nroCta<<endl<<"Descubierto Autorizado: "<<obj.descA<<endl;
    return sal;
}

Titular& Titular::operator=(const Titular& obj)
{
    nroCta=obj.nroCta;
    descA=obj.descA;
    return *this;
}

long Titular::identificacion()
{
    return nroCta;
}
