#include <string.h>
#include <iostream>
#include "Fecha.h"
#include <stdlib.h>

using namespace std;

Fecha :: Fecha(long diaRel){
    this->diaRel = diaRel;
}

Fecha &Fecha :: operator = (const Fecha& f){
    this->diaRel = f.diaRel;
    return *this;
}

istream& operator>>(istream& ent, Fecha& f){
    int d,m,a;
    char car;
    ent >> d >> car >> m >> car >> a;
    /*while(!f.esFechaValida(d,m,a)){
        cout << "Fecha incorrecta, ingrese otra: ";
        ent >> d >> car >> m >> car >> a;
    }*/
    f.diaRel = 1800;//f.dmaANum(d,m,a);
    return ent;
}

ostream& operator <<(ostream&sal, const Fecha& f){
    int a, m, d;
    //f.getAnioMesDia(a,m,d);
    sal << d << '/' << m << '/' << a;
    return sal;
}
