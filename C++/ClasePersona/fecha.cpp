#include "fecha.h"

/* DECLARACIONES CLASE FECHA*/
Fecha::Fecha()
{
    dd=0;
    mm=0;
    aaaa=0;
}

Fecha::Fecha(int d,int m,int a)
{
    dd=d;
    mm=m;
    aaaa=a;
}

Fecha::Fecha(const Fecha&f)
{
    dd=f.dd;
    mm=f.mm;
    aaaa=f.aaaa;
}

Fecha& Fecha::operator=(const Fecha&obj)
{
    dd=obj.dd;
    mm=obj.mm;
    aaaa=obj.aaaa;
    return *this;
}

Fecha::~Fecha()
{

}

ostream& operator<<(ostream& sal,const Fecha&f)
{
    cout<<"----------"<<endl;
    sal<<"Dia: "<<f.dd<<endl;
    sal<<"Mes: "<<f.mm<<endl;
    sal<<"Año: "<<f.aaaa<<endl;
    cout<<"----------"<<endl;
    return sal;
}

istream& operator>>(istream& ent,Fecha& f)
{
    cout<<"Ingrese Fecha"<<endl<<"----------"<<endl;
    cout<<"Dia: ";
    ent>>f.dd;
    cout<<endl;
    cout<<"Mes: ";
    ent>>f.mm;
    cout<<endl;
    cout<<"Año: ";
    ent>>f.aaaa;
    cout<<endl;
    return ent;
}

void Fecha::mostrarFecha()
{
    cout<<"Fecha "<<endl<<"----------"<<endl;
    cout<<"Dia: "<<dd<<endl;
    cout<<"Mes: "<<mm<<endl;
    cout<<"Año: "<<aaaa<<endl<<"----------"<<endl;
}

bool Fecha::operator==(const Fecha& f)
{
    if(aaaa==f.aaaa)
    {
        if(mm==f.mm)
        {
            if(dd==f.dd)
                return true;
        }
    }
    return false;
}

// FECHA MAS GRANDE, ES LA MAS RECIENTE

bool Fecha::operator<(const Fecha& f)
{
    if(aaaa>=f.aaaa)
    {
        if(aaaa==f.aaaa)
        {
            if(mm>=f.mm)
            {
                if(mm==f.mm)
                {
                    if(dd>f.dd)
                        return true;
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

bool Fecha::operator>(const Fecha& f)
{
    if(aaaa<=f.aaaa)
    {
        if(aaaa==f.aaaa)
        {
            if(mm<=f.mm)
            {
                if(mm==f.mm)
                {
                    if(dd<f.dd)
                        return true;
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
