#include <iostream>
#include <stdlib.h>
#include "Persona.h"
#include "Fecha.h"
#include "Empleado.h"

//int dividir(int, int);

/*EN HERENCIA PUBLICA
SE HEREDA:
    VARIABLES MIEMBRO Y METODOS

NO SE HEREDA:
    CONSTRUCTORES
    DESTRUCTORES
    FUNCIONES FRIEND
    OPERADOR DE ASIGNACION SOBRECARGADO
    FUNCIONES Y VARIABLES MIEMBRO ESTATICAS

*/

using namespace std;

int main()
{
    //PRUEBAS PERSONA
    Fecha f1(2010);
    Persona p1("Dami",36902267,f1);    p1.mostrar();    cout << endl;
    Persona p2(p1);    p2.hablar();
    Fecha f3 = p2.fecha();
    cout << "Mostrando fecha de nacimiento de \"p2\" " << f3 << endl << endl;
//    p2.~Persona; COMO USAR ESTE DESTRUCTOR ?????
    cout << "Destructor de \"p2\" utilizado" << endl << endl;
    cout << p1 << endl << endl;

    //PRUEBAS EMPLEADO
    Empleado e1(30254321,"Edgardo",f1,35422,6000);//CONSTRUCTOR PARAMETRIZADO
    e1.mostrar();
    e1.hablar();
    Empleado e2(e1);//CONSTRUCTOR DE COPIA
    e2.mostrar();cout << "Habiendo utilizado el constructor de copia" << endl;
    e2.hablar();
    cout << e1 << endl;

    /*
    //PRUEBA DE EXCEPCIONES
    int cociente, numerador = 5, denominador = 0;
    try{
        cociente = dividir(numerador,denominador);
        cout << cociente;
    }catch(DividirPorCeroException &exDpc){
        cout << exDpc.what() << endl;
    }

    double *x;
    try{
        x = new double[10000000000];
        x[0] = 100;
        delete[] x;
    }catch(std :: bad_alloc&){
        cout << "Memoria Insuficiente";
    }
*/
    return 0;
}
/*
int dividir(int numerador, int denominador){
    if(denominador == 0)
        throw DividirPorCeroException(); //SI EJECUTO EL THROW NO EJECUTO EL RETURN, CORTA TODO ACA
    return numerador/denominador;
}
*/
