#include "Fecha.h"

/* Constructores */
Fecha::Fecha(int d,int m,int a)
{
    dd = d;
    mm = m;
    aa = a;
}

Fecha::Fecha(const Fecha& obj)
{
    dd = obj.dd;
    mm = obj.mm;
    aa = obj.aa;
}

/* Operadores */
Fecha Fecha::operator++(int a)      //posincremento
{
    Fecha aux(*this);
    if(dd < cantDiasMes(mm,aa))
        dd++;
    else if(mm<12)
        {
            mm++;
            dd=1;
        }

        else
        {
            dd = 1;
            mm = 1;
            aa++;
        }
    return aux;
}

Fecha& Fecha::operator++()      //preincremento
{
    if(dd < cantDiasMes(mm,aa))
        dd++;
    else if(mm<12)
        {
            mm++;
            dd=1;
        }

        else
        {
            dd = 1;
            mm = 1;
            aa++;
        }
    return *this;
}

Fecha Fecha::operator--(int)
{
    Fecha aux(*this);
    if(dd > 1)
    {
        dd--;
    }
    else if(mm>1)
    {
        mm--;
        dd = cantDiasMes(mm,aa);
    }
    else
    {
        aa--;
        mm = 12;
        dd = cantDiasMes(mm,aa);
    }

    return aux;
}

Fecha& Fecha::operator--()
{
    if(dd > 1)
    {
        dd--;
    }
    else if(mm>1)
    {
        mm--;
        dd = cantDiasMes(mm,aa);
    }
    else
    {
        aa--;
        mm = 12;
        dd = cantDiasMes(mm,aa);
    }

    return *this;
}

Fecha& Fecha::operator=(const Fecha& obj)
{
    dd = obj.dd;
    mm = obj.mm;
    aa = obj.aa;
    return *this;
}

Fecha& Fecha::operator+=(const Fecha& obj)
{
    dd += obj.dd;
    while(dd>cantDiasMes(mm,aa))
    {
        dd -= cantDiasMes(mm,aa);
        if(mm==12)
        {
            mm = 1;
            aa++;
        }
        mm++;
    }
    mm += obj.mm;
    while(mm>12)
    {
        mm -= 12;
        aa++;
    }
    aa = obj.aa;
    return *this;
}

Fecha Fecha::operator+(const Fecha& obj)
{
    Fecha aux(*this);
    aux.dd += obj.dd;
    while(aux.dd>cantDiasMes(aux.mm,aux.aa))
    {
        aux.dd -= cantDiasMes(aux.mm,aux.aa);
        if(aux.mm==12)
        {
            aux.mm = 1;
            aux.aa++;
        }
        aux.mm++;
    }
    aux.mm += obj.mm;
    while(aux.mm>12)
    {
        aux.mm -= 12;
        aux.aa++;
    }
    aux.aa = obj.aa;
    return aux;
}

Fecha Fecha::operator-(const Fecha& obj)
{
    Fecha aux(*this);
    aux.dd -= obj.dd;
    while(aux.dd<1)
    {
        aux.dd += cantDiasMes(aux.mm,aux.aa);
        if(aux.mm == 1)
        {
            aux.aa--;
            aux.mm=12;
        }
        aux.mm--;
    }
    aux.mm -= obj.mm;
    while(mm<1)
    {
        aux.mm+=12;
        aux.aa--;
    }
    return aux;
}

Fecha& Fecha::operator-=(const Fecha& obj)
{
    dd -= obj.dd;
    while(dd<1)
    {
        dd += cantDiasMes(mm,aa);
        if(mm == 1)
        {
            aa--;
            mm=12;
        }
        mm--;
    }
    mm -= obj.mm;
    while(mm<1)
    {
        mm+=12;
        aa--;
    }
    return *this;
}

bool Fecha::operator<(const Fecha& obj)
{
    return ((dd+mm*100+aa*10000)-(obj.dd+obj.mm*100+obj.aa*10000)<0?true:false);
}

bool Fecha::operator<=(const Fecha& obj)
{
    return ((dd+mm*100+aa*10000)-(obj.dd+obj.mm*100+obj.aa*10000)<=0?true:false);
}

bool Fecha::operator>(const Fecha& obj)
{
    return ((dd+mm*100+aa*10000)-(obj.dd+obj.mm*100+obj.aa*10000)>0?true:false);
}

bool Fecha::operator>=(const Fecha& obj)
{
    return ((dd+mm*100+aa*10000)-(obj.dd+obj.mm*100+obj.aa*10000)>=0?true:false);
}

bool Fecha::operator==(const Fecha& obj)
{
    return ((dd+mm*100+aa*10000)-(obj.dd+obj.mm*100+obj.aa*10000)==0?true:false);
}

bool Fecha::operator!=(const Fecha& obj)
{
    return ((dd+mm*100+aa*10000)-(obj.dd+obj.mm*100+obj.aa*10000)!=0?true:false);
}

/* Metodos */
int Fecha::esBisiesto(int anio)
{
    if((anio%4 == 0) && (anio%400 == 0) && (!(anio%100)))
  {
      return 1; //es bisiesto
  }
  return 0;     //no es bisiesto
}

int Fecha::cantDiasMes(int mes, int anio)
{
    static const int cdm[2][12] =
    {
        {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };
    int i;
    i = esBisiesto(anio);
    return cdm[i][mes-1];
}

ostream& operator<<(ostream& sal, const Fecha& obj)
{
    cout<<"Dia: "<<obj.dd<<" Mes: "<<obj.mm<<" Anio: "<<obj.aa<<endl;
    return sal;
}

istream& operator>>(istream& ent, const Fecha& obj)
{
    cout<<"Ingrese dia: ";
    ent>>obj.dd;
    cout<<endl;

    cout<<"Ingrese mes: ";
    ent>>obj.mm;
    cout<<endl;

    cout<<"Ingrese anio: ";
    ent>>obj.mm;
    cout<<endl;
    return ent;
}

