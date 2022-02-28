#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#include <string>

using namespace std;

class Instrumento
{
    protected:
        string _nombre;
        char _escala;
        void ajustarEscala();
    public:
        Instrumento(string nombre, char escala);
        virtual ~Instrumento(){};
        string getNombre()const;
        char getEscala()const;
        virtual string getDetalles()const = 0;
};
#endif // INSTRUMENTO_H_INCLUDED


