#include "empleado.h"

#define MAX_BUFFER 100

#include <iostream>
#include <string.h>


using namespace std;

///CONSTRUCTOR PARAMETRIZADO
        Empleado ::  Empleado ( long dni, char* nom, float sue ) : Persona ( dni, nom)
{
    this->sueldo = sue;
}
///MUESTRA ALGO
void    Empleado ::  Hablar (void)
{
    cout << "\tEmpleado dice hola"<<endl;
}
///MUESTRA EMPLEADO
ostream& operator << (ostream& salida, const Empleado& obj)
{
    salida<<"\t[ "<<obj.dni<<" - "<<obj.nombre<<" - "<<obj.sueldo<<" ]";
    return salida;
}
///CONSTRUCTOR DE COPIA
        Empleado ::  Empleado (const Empleado& obj): Persona (dni,nombre)
{
    ///PORQUE USO EL INICIALIZADOR DE PERSONA
    //this->dni = obj.dni;
    //this->nombre = new char [strlen ( obj.nombre )+1 ];
    //strcpy ( this->nombre, obj.nombre );
    this->sueldo = obj.sueldo;
}

///CARGA EMPLEADO
istream& operator >> (istream&entrada, Empleado&obj)
{
    cout<<"\tIngrese DNI: ";
    cin>>obj.dni;
    char temp[MAX_BUFFER];
    cout<<endl;
    cout<<"\tIngrese Nombre  ";
    cin.ignore( );
    cin.getline (temp,MAX_BUFFER);
    delete [] obj.nombre;
    obj.nombre = new char [strlen(temp)+1];
    strcpy(obj.nombre,temp);
    cout<<endl;
    cout<<"\tIngresar sueldo: ";
    cin>>obj.sueldo;
    return entrada;
}
