#include "Irracional.h"

using namespace std;

Irracional :: Irracional(int nume, int deno){
    this->numerador = nume;
    this->denominador = deno;
}

int Irracional :: real(const Irracional& obj){
    int aux = obj.numerador/obj.denominador;
    return aux;
}

istream& operator >>(istream& ent, Irracional& obj){
    ent >> obj.numerador;
    ent >> obj.denominador;
    return ent;
}

ostream& operator <<(ostream& sal, const Irracional& obj){
    sal << obj.numerador << '/' << obj.denominador;
    return sal;
}

Irracional& Irracional :: operator += (const Irracional& obj){
    this->numerador = ( this->numerador * obj.denominador )+( obj.numerador * this->denominador );
    this->denominador = (this->denominador * obj.denominador);
    return (*this);
}
Irracional& Irracional :: operator = (const Irracional& obj){
    this->numerador = obj.numerador;
    this->denominador = obj.denominador;
    return (*this);
}
Irracional Irracional :: operator + (const Irracional& obj){
    Irracional aux(*this);  //ESTO ES NECESARIO ??? NO PUEDO CONSTRUIRLO SIN EL *THIS ????
    aux.numerador = ( this->numerador * obj.denominador )+( obj.numerador * this->denominador );
    aux.denominador = (this->denominador * obj.denominador);
    return aux;
}
Irracional Irracional :: operator * (const Irracional& obj){
    Irracional aux(*this);
    aux.numerador = (this->numerador * obj.numerador);
    aux.denominador = this->numerador * obj.denominador;
    return aux;
}

bool Irracional :: operator != (const Irracional& obj){
    if( (this->numerador * obj.denominador) == (this->denominador * obj.numerador) )
        return false;
    return true;
}

Irracional operator +(int var, const Irracional& obj){
    Irracional aux;
    aux.numerador = ( var * obj.denominador )+( obj.numerador );
    aux.denominador = obj.denominador;
    return aux;
}
