#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "Persona.h"
#include <iostream>


using namespace std;

class Empleado: public Persona
{
    private:
                float    sueldo;
    public:
            ///CONSTRUCTOR PARAMETRIZADO
                    Empleado ( long = 0, char* = NULL, float = 0);
            ///MUESTRA ALGO
            void    Hablar (void);
            ///MUESTRA EMPLEADO
            friend ostream& operator << (ostream&, const Empleado&);
            ///CONSTRUCTOR DE COPIA
                    Empleado (const Empleado&);
            ///CARGA EMPLEADO
            friend istream& operator >> (istream&, Empleado&);
};

#endif // EMPLEADO_H_INCLUDED
