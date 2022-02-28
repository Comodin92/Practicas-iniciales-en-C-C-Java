#include "persona.h"

#include <iostream>
#include <string.h>

using namespace std;

///CONSTRUCTOR PARAMETRIZADO
        Persona ::  Persona ( long dni, char* nom)
{
    cout<<"construyendo cosas";
    this->dni = dni;
    if ( nom != NULL )
       {
            this->nombre = new char [ strlen( nom ) +1 ];
           strcpy( this->nombre , nom);
       }
       else
       {
           this->nombre = new char [ 1 ];
           strcpy(this->nombre , "");
       }
}
///MUESTRA ALGO
void Persona ::  Hablar (void)
{
    cout << "\tPersona dice hola"<<endl;
}
///MUESTRA PERSONA
ostream& operator << (ostream& salida, const Persona& obj)
{
    salida<<"\t[ "<<obj.dni<<" - "<<obj.nombre<<" ]";
    return salida;
}
///CONSTRUCTOR DE COPIA
        Persona ::  Persona (const Persona& obj)
{
    this->dni = obj.dni;
    this->nombre = new char [strlen ( obj.nombre )+1 ];
    strcpy ( this->nombre, obj.nombre );
}
///DESTRUCTOR
        Persona :: ~Persona ()
{
        delete [] nombre;
}
