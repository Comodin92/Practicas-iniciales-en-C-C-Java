#include <iostream>
#include "fecha.h"
using namespace std;
int esFechaValida(int,int,int);
int esBisiesto(int);


void Fecha::mostrar()
{

    cout<<"Dia: "<<dia<<"\nMes: "<<mes<<"\nAnio: "<<anio<<endl;

}
Fecha::Fecha(int d, int m, int a)///PARAMETRIZADO
{
    this->dia=d;
    this->mes=m;   ///USO THIS PARA SABER DIFERENCIAR A QUE X HACEMOS REFERENCIA, REFERENCIA A SI MISMO, DICE QUE SON LOS OBJETOS PRIVADOS
    this->anio=a;

}

 Fecha::Fecha(const Fecha &obj)///CONSTUCTOR DE COPIA
{
    dia=obj.dia;
    mes=obj.mes;
    anio=obj.anio;
}

Fecha& Fecha::operator=(const Fecha& fec)
{
    dia=fec.dia;
    mes=fec.mes;
    anio=fec.anio;
    return *this;
}

istream& operator>>(istream& ent, Fecha& fec)
{
    do
    {
        cout<<"\nIngrese el dia: ";
        cin>>fec.dia;
        cout<<"\nIngrese el mes: ";
        cin>>fec.mes;
        cout<<"\nIngrese el anio: ";
        cin>>fec.anio;
    }
    while(!(esFechaValida(fec.dia,fec.mes,fec.anio)));
    return ent;
}

ostream& operator<<(ostream& salida, Fecha& fec)
{
    salida<<fec.dia<<"/"<<fec.mes<<"/"<<fec.anio<<endl;
    return salida;
}



int esBisiesto(int a)
{
    return ((a%4==0 && a%100!=0) || (a%400==0));
}

int esFechaValida(int d, int m, int a)
{
    int vec[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    vec[1]+= esBisiesto(a);
    if( (m>0&&m<13) && (d>0&&d<=vec[m-1]) && (a>1600&&a<9999))
        return 1;
    return 0;
}
