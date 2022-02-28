#include "Hora.h"

Hora::Hora()
{
    dias=0;
    horas=0;
    minutos=0;
    segundos=0;
}

Hora::Hora(int s)
{
    while(s>86399)
    {   dias++;
        s-=86400;

    }
    horas=s/3600;
    minutos=(s-(horas*3600))/60;
    segundos=s-(horas*3600)-(minutos*60);
}

void Hora::mostrar()
{
    cout<<"("<<horas<<","<<minutos<<","<<segundos<<")"<<endl;
}

Hora Hora::operator++(int)
{
    Hora aux;
    aux.dias=dias;
    aux.horas=horas;
    aux.minutos=minutos;
    aux.segundos=segundos;

    segundos++;
    if(segundos>59)
    { segundos=0;
        minutos++;
        if(minutos>59)
        {   minutos=0;
            horas++;
            if(horas>23)
                horas=0;
                dias++;
        }

    }

    return aux;
}

Hora & Hora::operator--()
{
    segundos--;

   if(segundos<0)
    { segundos=59;
        minutos--;
        if(minutos<0)
        {   minutos=59;
            horas--;
            if(horas<0)
                horas=23;
                dias--;

        }

    }

return *this;

}

ostream& operator<<(ostream & salida, const Hora & h)
{
    salida<<"("<<h.horas<<","<<h.minutos<<","<<h.segundos<<")"<<endl;

    return salida;
}

istream & operator>>(istream & entrada, Hora & h)
{
    cout<<"Ingrese la cantidad de horas"<<endl;
    entrada>>h.horas;

    cout<<"Ingrese la cantidad de minutos"<<endl;
    entrada>>h.minutos;

    cout<<"Ingrese la cantidad de segundos"<<endl;
    entrada>>h.segundos;

    return entrada;
}






