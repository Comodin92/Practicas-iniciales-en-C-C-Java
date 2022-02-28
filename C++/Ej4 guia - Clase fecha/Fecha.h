#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>

using namespace std;

class Fecha
{   private:
    int dd, mm,aa;
    public:
        /* Constructores */
        Fecha(int=0,int=0,int=0);
        Fecha(const Fecha&);
        /* Sobrecarga de operadores */
        Fecha operator++(int);
        Fecha&operator++();
        Fecha operator--(int);
        Fecha& operator--();
        Fecha& operator=(const Fecha&);
        Fecha operator+(const Fecha&);
        Fecha operator-(const Fecha&);
        Fecha& operator+=(const Fecha&);
        Fecha& operator-=(const Fecha&);

        bool operator<(const Fecha&);
        bool operator<=(const Fecha&);
        bool operator>(const Fecha&);
        bool operator>=(const Fecha&);
        bool operator==(const Fecha&);
        bool operator!=(const Fecha&);

        friend ostream& operator<<(ostream&,const Fecha&);
        friend istream& operator>>(istream&,const Fecha&);
        /* Metodos */
        int esBisiesto(int);
        int cantDiasMes(int, int);
        /* Destructor */

};

#endif // FECHA_H_INCLUDED
