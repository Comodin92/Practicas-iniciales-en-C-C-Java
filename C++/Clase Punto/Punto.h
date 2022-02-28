#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;

class Punto
{
    public:
        /** Default constructor */
        //Punto();
        /** Default destructor */
        ~Punto();
        /** Copy constructor */
        //Punto(const Punto& other);
        /** Constructor Parametrizado */
        Punto(int x=5,int y=10);
        //Punto(int ,int );
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Punto& operator=(const Punto&);
        Punto operator+(const Punto&)const;
        Punto operator-(const Punto&)const;
        Punto operator*(const Punto&)const;
        Punto operator/(const Punto&p)const;
        bool operator==(const Punto&)const;
        bool operator!=(const Punto&)const;
        Punto& operator+=(const Punto&);
        Punto& operator-=(const Punto&);
        Punto& operator*=(const Punto&);
        Punto& operator/=(const Punto&);
        Punto operator-()const;
        Punto& operator++(); // preIncremento
        Punto operator++(int); // posIncremento
        Punto& operator--();
        Punto operator--(int);
        Punto operator*(int)const;
        Punto& operator*=(int);
        friend Punto operator*(int ,const Punto&);
        friend istream&operator>>(istream&,Punto&);
        friend ostream&operator<<(ostream&,const Punto&);
        int Getx();
        void Setx(int);
        int Gety();
        void Sety(int );
        void mostrar_Punto();
    protected:
    private:
        int x; //!< Member variable "x"
        int y; //!< Member variable "y"
};

#endif // PUNTO_H
