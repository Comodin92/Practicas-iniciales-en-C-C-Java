#ifndef CAMBIOESCALAEXCEPTION_H_INCLUDED
#define CAMBIOESCALAEXCEPTION_H_INCLUDED

#include <iostream>
using namespace std;

class CambioEscalaException : public exception
{
public:
    CambioEscalaException(){};
    string what()
    {
        return "No permite cambio de escala";
    }
};
/// complete la declaración de la class

#endif // CAMBIOESCALAEXCEPTION_H_INCLUDED
