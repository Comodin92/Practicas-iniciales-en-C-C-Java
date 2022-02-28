#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

#include <iostream>

using namespace std;

class Cadena
{
    private:
            char *cad;
            int   longi;
    public:
            ///CONSTRUCTOR DE CADENA
            Cadena ( char* = NULL );
            ///DESTRUCTOR DE CADENA
            ~Cadena ( );
            ///CONSTRUCTOR DE COPIA
            Cadena ( const Cadena& );
            ///SOBRECARGA DE OPERADOR =
            //Cadena& operator = ( const Cadena& );
            Cadena& operator = (const Cadena &);
            ///SOBRECARGA DE OPERADOR +
            Cadena operator + ( const Cadena& ) const;
            ///SOBRECARGA DE OPERADOR ==
            bool operator == ( const Cadena& ) const;
            ///SOBRECARGA DE OPERADOR +=
            Cadena& operator += ( const Cadena& );

            ///SOBRECARGA DE OPERADOR + ENTRE CADENA Y CHAR*
            Cadena operator + ( const char* )const;

            ///SOBRECARGA CON FUNCION AMIGA <<
            friend ostream& operator<< (ostream&, const Cadena&);
            ///SOBRECARGA CON FUNCION AMIGA >>
            friend istream& operator>> (istream&, Cadena&);
            ///SOBRECARGA CON FUNCION AMIGA ENTRE CHAR* Y CADENA
            friend Cadena operator + ( const char* , const Cadena&);
            ///VER LONGITUD DE CADENA
            int longitud ( void );
};

#endif // CADENAS_H_INCLUDED
