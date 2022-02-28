#include "Cadena.h"

/* Constructores */
Cadena::Cadena()
{
    cad = NULL;
}

Cadena::Cadena(char * c)
{
    cad = new char[strlen(c)+1];
    strcpy(cad,c);
}

Cadena::Cadena(const Cadena& obj)
{
    strcpy(cad,obj.cad);
}

/* Operadores */
Cadena& Cadena::operator=(const Cadena& obj)
{
    strcpy(cad,obj.cad);
    return *this;
}

Cadena Cadena::operator+(const Cadena& obj)
{
    Cadena c(*this);
    strcat(c.cad,obj.cad);
    return c;
}

Cadena& Cadena::operator+=(const Cadena& obj)
{
    strcat(cad,obj.cad);
    return *this;
}

Cadena Cadena::operator-(const Cadena& obj)               //le quita los que son comunes.
{
    Cadena aux(*this);
    char * pc1,* pc2;
    pc1 = aux.cad;
    while(*pc1)
    {
        pc2 = obj.cad;
        while(*pc2)
        {
            if(*pc1 == *pc2)
                *pc1 = ' ';
            pc2++;
        }
        pc1++;
    }
    return aux;
}


Cadena& Cadena::operator-=(const Cadena& obj)               //le quita los que son comunes.
{
    char * pc1,* pc2;
    pc1 = cad;
    while(*pc1)
    {
        pc2 = obj.cad;
        while(*pc2)
        {
            if(*pc1 == *pc2)
                *pc1 = ' ';
            pc2++;
        }
        pc1++;
    }
    return *this;
}

bool Cadena::operator==(const Cadena& obj)
{
    return (strcmp(cad,obj.cad)==0?true:false);
}

bool Cadena::operator!=(const Cadena& obj)
{
    return (strcmp(cad,obj.cad)!=0?true:false);
}

bool Cadena::operator<(const Cadena& obj)
{
    return (strcmp(cad,obj.cad)<0?true:false);
}

bool Cadena::operator<=(const Cadena& obj)
{
    return (strcmp(cad,obj.cad)<=0?true:false);
}

bool Cadena::operator>(const Cadena& obj)
{
    return (strcmp(cad,obj.cad)>0?true:false);
}

bool Cadena::operator>=(const Cadena& obj)
{
    return (strcmp(cad,obj.cad)>=0?true:false);
}

ostream& operator<<(ostream& ent,const Cadena& c)
{
    ent<<c.cad;
    return ent;
}

istream& operator>>(istream& sal,Cadena& c)
{
    sal>>c.cad;
    return sal;
}
/* Metodos*/
/*Destructor */
Cadena::~Cadena()
{
    delete[]cad;
}
