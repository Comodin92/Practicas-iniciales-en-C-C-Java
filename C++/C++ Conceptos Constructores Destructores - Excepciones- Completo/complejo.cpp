#include "complejo.h"

#include <iostream>
#define PRUEBA

using namespace std;

///CONSTRUCTOR PARAMETRIZADO DE COMPLEJO
    Complejo::Complejo( double re, double im )
{
    this->re = re;
    this->im = im;
}

///HACE LO DE PRINTF CON COMPLEJO
void Complejo::Mostrar( void )
{
    cout << "\tCreaste ("<<re<<","<<im<<")" << endl;
}

///CONSTRUCTOR DE COPIA DE COMPLEJO
    Complejo::Complejo( const Complejo &obj )
{
    re=obj.re;
    im=obj.im;
}

///DESTRUCTOR DE COMPLEJO
    Complejo :: ~Complejo( )
{
    /*
    cout    << "Ejecutando Destructor con la memoria "
            << this
            << " que tiene los valores ("<<re<<","<<im<<")"<< endl;
    cout    << "Destruyendo..."
            << this
            << " con valores ("
            << re
            << ","
            << im
            << ')'
            << endl;
    */
}

///SOBRECARGA DE OPERADOR =
Complejo & Complejo :: operator = ( const Complejo & obj )
{
    re  =   obj.re;
    im  =   obj.im;
    return  *this;
}

///SOBRECARGA DE OPERADOR +
Complejo Complejo :: operator + ( const Complejo & obj ) const
{   //LLAME AL CONSTRUCTOR Y LE DI EL RESULTADO DE LAS OPERACIONES
    Complejo aux ( re+obj.re , im+ obj.im );
    return aux;
}

///SOBRECARGA DE OPERADOR + CON UN REAL
Complejo Complejo :: operator + ( const double& obj )const
{
    Complejo aux ( re+obj, im );
    return aux;
}


///SOBRECARGA DE OPERADOR ==
bool Complejo :: operator == ( const Complejo& obj) const
{
    return ( re == obj.re && im == obj.im );
}

///SOBRECARGA DE OPERADOR += CON COMPLEJO
Complejo& Complejo :: operator += ( const Complejo & obj )
{
    re  +=   obj.re;
    im  +=   obj.im;
    return *this;
}

///SOBRECARGA DE OPERADOR += CON ENTERO O DOBLE
Complejo & Complejo :: operator += ( const double & obj )
{
    this->re += obj;
    this->im = im;
    return *this;
}

/// SOBRECARGA DE OPERADOR *
Complejo Complejo :: operator * ( const Complejo & obj )const
{
    Complejo aux (re*obj.re - im*obj.im , re*obj.im + im*obj.re);
    return aux;
}

///SOBRECARGA DE OPERADOR + CON ENTERO Y COMPLEJO AMIGA
Complejo             operator + (const double& d, const Complejo& obj)
{
    Complejo aux (d+ obj.re, obj.im );
    return aux;
}

///SOBRECARGA DE OPERADOR ++ PREINCREMENTO
Complejo& Complejo :: operator ++ ( )
{
    re++;
    im++;
    return *this;
}

///SOBRECARGA DE OPERADOR ++ POSINCREMENTO
Complejo Complejo :: operator ++ ( int )
{
    Complejo aux ( *this );
    re++;
    im++;
    return aux;
}



ostream&             operator << (ostream& salida, const Complejo& obj)
{
    salida<<"\tCreaste ("<<obj.re<<","<<obj.im<<")\n";
    return salida;
}

istream&             operator >> (istream& entrada, Complejo& obj)
{
    cout<<"\tParte Real:\t  ";
    entrada>>obj.re;
    cout<<"\tParte Imaginaria: ";
    entrada>>obj.im;
    //    entrada.ignore( MAX_BUFFER,'\n' );
    entrada.ignore();

    return entrada;
}
