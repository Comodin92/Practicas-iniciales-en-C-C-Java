#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <iostream>
#include "Fecha.h"

class Persona{
    long dni;
    Fecha fchNac;
protected:
    char *apyn;

public:
    Fecha fecha();//DEVUELVE UNA FECHA
    Persona(const char *, long, const Fecha&);
    Persona(const Persona&);//RECIBE REFERENCIA AL OBJETO A COPIAR, NO PUNTERO
    void mostrar(void);
    //virtual void mostrar(void) = 0; SI HAGO ESTO ESTOY INICIALIZANDO UNA FUNCION VIRTUAL, QUE SE LLAMA FUNCION VIRTUAL PURA
    //                                 LO QUE IMPLICA QUE LA CLASE SERÁ ABSTRACTA. ES LA UNICA FORMA DE DECALARAR UNA CLASE ABSTRACTA
    void hablar(void);
    ~Persona();//DESTRUCTORES, TIENE SENTIDO SU USO UNICAMENTE CUANDO HAY ASIGNACION DINAMICA DE MEMORIA
    friend ostream& operator <<(ostream&, const Persona&);
};

#endif // PERSONA_H_INCLUDED
