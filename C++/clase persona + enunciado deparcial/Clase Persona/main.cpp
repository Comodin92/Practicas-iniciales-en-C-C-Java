#include "Persona.h"
#include "Fecha.h"
#include "Titular.h"

int main()
{
    Titular t1(323232,1520.300);
    Persona p1(22405678, "Perez, Juan" , Fecha(23,7,1981),1,t1);
    Persona p2;
    Persona p3(p1);

    p2=p3;
    cout <<"p3: "<< p3 <<"p2: "<<p2<<endl;
    cout <<"dni: "<<p1.identificacion()<<endl;
    cout <<"Nro de cuenta: "<< t1.identificacion()<<endl;

    return 0;
}

