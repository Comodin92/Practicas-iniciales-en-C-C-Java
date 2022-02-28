/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 36.902.267-GUTIERREZ, EdgardoDamian-(04-1361)  *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**   DESARROOLLE LAS "FUNCIONES MIEMBRO" DE LA CLASE    **//**//**//**/

#include "Prisma.h"

ostream& operator <<(ostream& sal, const Prisma& obj){
    sal << obj.alto << 'x'<<obj.ancho<<
    'x'<<obj.profundidad<<'x'<<obj.color;
    return sal;
}

Prisma::Prisma(string col, int al, int anc, int prof)
{
    this->color = col;
    this->alto= al;
    this->ancho = anc;
    this->profundidad = prof;
}

Prisma::Prisma(const Prisma &obj)
{
    this->color = obj.color;
    this->alto= obj.alto;
    this->ancho = obj.ancho;
    this->profundidad = obj.profundidad;

}

Prisma operator*(const int x, Prisma &obj)
{
    Prisma aux_obj;
    aux_obj.alto = obj.alto * x;
    aux_obj.ancho = obj.ancho * x;
    aux_obj.profundidad = obj.profundidad * x;
    aux_obj.color = obj.color;
    return aux_obj;

}

Prisma Prisma::operator++(int)
{
    Prisma aux(*this);
    alto++;
    ancho ++;
    profundidad++;
    return aux;
}

Prisma &Prisma::operator--()
{
    alto--;
    ancho --;
    profundidad--;
    return *this;
}
