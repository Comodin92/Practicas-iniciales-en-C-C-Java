#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;


/* escalas musicales:
DO 	RE 	MI 	FA 	SOL LA 	SI
C 	D 	E 	F 	G 	A 	B
*/

class Instrumento
{
protected:
    string nombre;
    char escala;
    void ajustarEscala();
public:
    Instrumento(string nomb, char esc);
    virtual ~Instrumento(){};
    string getNombre() const;
    char getEscala() const;
    virtual string getDetalles() const = 0;
};

/// complete la declaración de la class

#endif // INSTRUMENTO_H_INCLUDED
