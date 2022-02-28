#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
using namespace std;
class Fecha
{
    public:
        void mostrar();
        Fecha(int d=01, int m=01, int a=1601);
        Fecha(const Fecha&);
        Fecha& operator=(const Fecha&);
        friend istream& operator>>(istream& , Fecha& ); ///Flijo de salida
        friend ostream& operator<<(ostream&, Fecha&);


    private:
        int dia;
        int mes;
        int anio;

};


#endif // FECHA_H_INCLUDED
