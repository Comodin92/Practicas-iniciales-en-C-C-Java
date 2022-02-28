#ifndef PERSONA_H
#define PERSONA_H

#include "Fecha.h"
#include "Titular.h"
#include <iostream>
#include <string.h>

using namespace std;

class Titular;
class Persona
{
    public:
        Persona();
        Persona(long ,const char* ,const Fecha& ,unsigned int ,const Titular& );
        ~Persona();
        Persona(const Persona& other);
        friend char* duplicar_cad(const char* cad);
        friend ostream& operator<<(ostream& sal,const Persona& obj);
        Persona& operator=(const Persona& obj);
        long identificacion();
    protected:
    private:
        long dni;
        char* apyn;
        unsigned int nac;
        Fecha fnac;
        Titular t;
};

#endif // PERSONA_H
