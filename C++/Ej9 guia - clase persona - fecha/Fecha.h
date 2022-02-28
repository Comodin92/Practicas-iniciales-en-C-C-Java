#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>

using namespace std;

class Fecha
{   private:
    long dd;
    public:
        /* Constructores */
        Fecha(long =0L);
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
        /* Destructor */

};

#endif // FECHA_H_INCLUDED
