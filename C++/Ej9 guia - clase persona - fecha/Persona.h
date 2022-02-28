#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "Fecha.h"
#include "Varias.h"
#include <string.h>
#include <iostream>

class Persona
{
    private:
        char * nom;                 //asignacion dinámica de memoria. es un puntero contenido el objeto a un sector de memoria fuera de este.
        char dir[30];               //asignacion estática. el vector esta contenido en el objeto.
        Fecha fNac;
        int dni;
    public:
        Persona();          //constructor por defecto.
        Persona(char *, char *,const Fecha&, int);
        //Persona(char * = NULL, char * = NULL, const Fecha&=Fecha(),int =0);
        Persona(const Persona&);
        /* sobrecarga de operadores */
        Persona& operator=(const Persona&);
        Persona operator++(int);          //posincremento                    ...pre/posincremento aumenta en 1 dia la fecha.
        Persona&operator++();             //preincremento
        friend ostream& operator<<(ostream&,const Persona&);
        friend istream& operator>>(istream&,Persona&);
        /* metodos */
        void mostrar();
        char * getNom()const;
        const char * getDir()const;
        Fecha getFnac()const;
        int getDNI()const;
        /* Destructo r*/
        ~Persona();
};

#endif // PERSONA_H_INCLUDED
