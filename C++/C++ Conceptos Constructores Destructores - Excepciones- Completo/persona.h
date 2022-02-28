#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>

using namespace std;

class Persona
{
    protected:
                long    dni;
                char*   nombre;
    public:
            ///CONSTRUCTOR PARAMETRIZADO
                    Persona ( long = 0, char* = NULL);
            ///MUESTRA ALGO
       virtual void Hablar (void);
            ///MUESTRA PERSONA

            friend  ostream& operator << (ostream&, const Persona&);
            ///CONSTRUCTOR DE COPIA
                    Persona (const Persona&);
            ///DESTRUCTOR
                   ~Persona ();
};

#endif // PERSONA_H_INCLUDED
