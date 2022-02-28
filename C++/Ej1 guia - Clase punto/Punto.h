#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED
#include <iostream>

using namespace std;

class Punto
{
 private:
    int coordX, coordY;

 public:
    /* Constructores */
    Punto();
    Punto(const Punto&);
    Punto(int);
    Punto(int,int);
    /* Sobrecarga de operadores */
    Punto& operator=(const Punto&);
    Punto& operator+=(const Punto&);
    Punto& operator-=(const Punto&);
    Punto operator++(int);          //posincremento
    Punto& operator++();             //preincremento
    Punto operator--(int);          //posdecremento
    Punto& operator--();            //predecremento

    Punto operator+(const Punto&);
    Punto operator-(const Punto&);

    friend ostream& operator<<(ostream&,const Punto&);
    friend istream& operator>>(istream&,Punto&);


    /* Metodos */
    void mostrar();
    /* Destructor */
   // ~Punto();
};

#endif // PUNTO_H_INCLUDED
