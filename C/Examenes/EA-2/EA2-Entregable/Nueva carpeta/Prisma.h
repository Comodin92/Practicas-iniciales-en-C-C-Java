/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 36.902.267-GUTIERREZ, EdgardoDamian-(04-1361)  *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**         COMPLETE LA DECLARACIÓN DE LA CLASE          **//**//**//**/

#ifndef PRISMA_H_
#define PRISMA_H_

#include <iostream>
#include <string>

using namespace std;

class Prisma
{
private:
    int alto;
    int ancho;
    int profundidad;
    string color;     /// <--preferentemente, de lo contrario:  char *color;

public:
    Prisma(string col="Incoloro", int al=1, int anc=1, int prof=1);
    Prisma(const Prisma&);
    friend istream& operator >>(istream&, Prisma&);
    friend ostream& operator <<(ostream&, const Prisma&);
    friend Prisma operator*(const int x, Prisma &obj);
    Prisma operator++(int);
    Prisma &operator--();

};
#endif // PRISMA_H_

