#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;


class Cadena
{
 private:
    char * cad;
 public:
    /* Constructores */
    Cadena();
    Cadena(char * c);
    Cadena(const Cadena&);
    /* Operadores */
    Cadena& operator=(const Cadena&);
    Cadena operator+(const Cadena&);
    Cadena operator-(const Cadena&);
    Cadena& operator+=(const Cadena&);
    Cadena& operator-=(const Cadena&);

    bool operator==(const Cadena&);
    bool operator!=(const Cadena&);

    bool operator<(const Cadena&);
    bool operator<=(const Cadena&);
    bool operator>(const Cadena&);
    bool operator>=(const Cadena&);

    friend ostream& operator<<(ostream&,const Cadena&);
    friend istream& operator>>(istream&,Cadena&);
    /* Metodos*/
    /*Destructor */
    ~Cadena();

};


#endif // CADENA_H_INCLUDED
