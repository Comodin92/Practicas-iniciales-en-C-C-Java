#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <string.h>
#include "fecha.h"

using namespace std;

class Persona
{
    private:
        char *nom;
        char *ape;
        char *dom;
        char loc[26];
        Fecha fnac;
        int edad;
        long int dni;
        char sexo;
    public:
        Persona();  // Constructor por Defecto
        Persona(char *,char *,char *,char *,const Fecha& ,int ,long int ,char );    // Constructor Parametrizado
        Persona(const Persona&);    // Constructor por Copia
        //Persona(char *=NULL ,char *=NULL ,char *=NULL ,char *=NULL ,int =0,const Fecha&=Fecha() ,long int =0 ,char =''); Constructor Parametrizado por Defecto
        char *str_new_dup(const char *);
        ~Persona();
        // Cout y Cin
        friend ostream& operator<<(ostream&, const Persona&);
        friend istream& operator>>(istream&,Persona&);
        // Mostrar Clase Persona por Pantalla
        void mostrarPersona();
        // Asignacion
        Persona& operator=(const Persona&);
        // Pos Incremento y Pre Incremento aumentan en 1 la edad
        Persona operator++(int);
        Persona& operator++();
        // Verificar si dos clases persona son iguales
        bool operator==(const Persona&);
        // Desigualdad entre Fecha de Nacimiento
        bool operator<(const Persona&);
        bool operator>(const Persona&);
};

#endif // FUNCIONES_H_INCLUDED
