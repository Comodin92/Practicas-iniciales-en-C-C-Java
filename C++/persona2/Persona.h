#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string.h>
using namespace std;

class Persona
{
    public:
        Persona(const char * = NULL, const int = -1, const char = 'x',const long = -1L);
        virtual ~Persona();
        Persona(const Persona& );
        char *getapyn();
        void setapyn(char *val);
        int Getedad();
        void Setedad(int );
        char Getsexo();
        void Setsexo(char );
        long Getdni();
        void Setdni(long );
        void verPersona()const;
        friend ostream & operator <<(ostream &, const Persona &);
        friend istream & operator >>(istream &, Persona &);
        Persona & operator = (const Persona &);
    protected:
    private:
        char *apyn;
        int edad;
        char sexo;
        long dni;
};

#endif // PERSONA_H
