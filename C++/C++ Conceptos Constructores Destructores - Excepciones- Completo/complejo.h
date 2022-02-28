#ifndef COMPLEJO_H_INCLUDED
#define COMPLEJO_H_INCLUDED
#define PRUEBA
#define TAM_CADENA 100
#define MAX_BUFFER 100
#include <iostream>

using namespace std;

class Complejo
{
    private:
            double  re,
                    im;
    public:
            ///CONSTRUCTOR PARAMETRIZADO DE COMPLEJO
            Complejo ( double = 0 , double = 0);
            ///HACE LO DE PRINTF CON COMPLEJO
            void Mostrar ( void );
            ///CONSTRUCTOR DE COPIA COMPLEJO
            Complejo ( const Complejo& );

            ///SOBRECARGA DE OPERADOR =
            Complejo& operator = ( const Complejo& );
            ///SOBRECARGA DE OPERADOR +
            Complejo operator + ( const Complejo& )const;
            Complejo operator + ( const double& )const;
            ///SOBRECARGA DE OPERADOR ==
            bool operator == ( const Complejo& )const;
            ///SOBRECARGA DE OPERADOR +=
            Complejo& operator += ( const Complejo& );
            Complejo& operator += ( const double& );
            ///SOBRECARGA DE OPERADOR *
            Complejo operator * ( const Complejo&)const;
            ///SOBRECARGA DE OPERADOR ++ PREINCREMENTO
            Complejo& operator ++ (  );
            ///SOBRECARGA DE OPERADOR ++ POSTINCREMENTO
            Complejo operator ++ ( int );

            ///SOBRECARGA CON FUNCION AMIGA + CON DIFERENTE TIPADO
            friend Complejo operator + (const double& , const Complejo& );
            ///SOBRECARGA CON FUNCION AMIGA <<
            friend ostream& operator<< (ostream&, const Complejo&);
            ///SOBRECARGA CON FUNCION AMIGA >>
            friend istream& operator>> (istream&, Complejo&);

    #ifdef PRUEBA
            ///DESTRUCTOR
            ~Complejo(void);
    #endif // PRUEBA
};



#endif // COMPLEJO_H_INCLUDED
