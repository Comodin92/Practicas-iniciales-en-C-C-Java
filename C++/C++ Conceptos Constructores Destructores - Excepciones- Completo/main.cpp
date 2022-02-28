#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "complejo.h"
#include "cadenas.h"
#include "persona.h"
#include "empleado.h"
#include "figura.h"
#include "triangulo.h"
#include "rectangulo.h"

using namespace std;

int main()
{
    system ("color 0E" );
    cout<<"\t--------------EXCEPCIONES-----------------------"<<endl;
    cout<<"Inicio de programa"<<endl;
    long x = 1000000000;
    try
    {
        long *y = new long [x];
        cout<<"memoria asignada"<<endl;
    }
    catch (bad_alloc &em)
    {
        cout<<em.what();
    }

    cout <<"\tPrimer programa de objetos\n";


    cout<<"\t--------------COMPLEJO--------------------------"<<endl;
    /** COMPLEJOS **/
    cout<<endl;
    Complejo    c0;
    cout <<"\tc0";
    c0.Mostrar();
    Complejo    c1(1,2);
    cout <<"\tc1";
    c1.Mostrar();
    Complejo    c2 (3,5);
    cout <<"\tc2";
    c2.Mostrar();
    Complejo    c3 (c1);
    cout <<"\tc3 (c1)";
    c3.Mostrar();
    Complejo    c4;//Los construyo y no me importa su contenido porque va a ser algo de c3
                c4=c3;
    cout <<"\tc4 = c3";
    c4.Mostrar();
    Complejo    c5;
    c5=c4+c3+c2;
    cout <<"\tc5 = c4 + c3 + c2";
    c5.Mostrar();
    Complejo    c6 (1,1);
    cout <<"\tc6";
    c6.Mostrar();
    c6+=c5;
    cout <<"\tc6 += c5";
    c6.Mostrar();
    Complejo    c7;
                c7=c6;
                c7+=4;
    cout <<"\tc7 = c6, c7 += 4";
    c7.Mostrar();
    Complejo    c8;
                c8=c7*c6;
    cout <<"\tc8 = c7 x c6";
    c8.Mostrar();
    Complejo    c9;
                c9=c8+4;
    cout <<"\tc9 = c8 + 4";
    c9.Mostrar();
                c9++;
    cout <<"\tc9++";
    c9.Mostrar();
                ++c9;
    cout <<"\t++c9";
    c9.Mostrar();
    Complejo    c10;
    cout<<"\tc10 ( cin >> y cout << )"<<endl;
    cin>>c10;
    cout<<c10;
    Complejo    c11;
    c11=7+c10;
    cout <<"\tc11 = 7 + c10";
    cout<<c11;
    cout<<"\t--------------CADENAS---------------------------"<<endl;
    /** CADENAS **/
    Cadena cad1 (" \"cad1\" ");
    cout<<"\tcad1 tiene: "<<cad1<<endl;
    Cadena cad2 (" \"cad2\" ");
    cout<<"\tcad2 tiene: "<<cad2<<endl;
    Cadena cad3 (cad2);
    cout<<"\tcad3(cad2): " <<cad3<<endl;
    Cadena cad4;
    cad4=cad1;
    cout<<"\tcad4=cad1:  "<<cad4<<endl;
    if(cad1 == cad4)
        cout<<"\tEntro al if (cad1 == cad 4)"<<endl;
    Cadena cad5;
    cad1+=cad2;
    cout<<"\tcad1+=cad2: "<<cad1<<endl;
    cin>>cad5;
    cout<<"\tdeberia verse cad5: "<<cad5<<endl;
    Cadena cad6;
    cad6=cad1+"Hola";
    cout<<"\tcad6=cad1+Hola: "<<cad6<<endl;
    Cadena cad7;
    cad7="Hola"+cad1;
    cout<<"\tcad7=Hola+cad1: "<<cad7<<endl;
    cout<<"\tLongitud de cad1: "<<cad1.longitud()<<endl;
    cout<<"\t--------------EMPLEADO--------------------------"<<endl;
    /** PERSONA Y EMPLEADO **/
    Empleado emple1;
    cin>>emple1;
    cout<<endl;
    Empleado emple2;
    cin>>emple2;
    cout<<endl;
    cout<<emple1<<endl;
    cout<<emple2<<endl;
    Persona per1 (99888777,"Charly de la People");
    cout<<per1<<endl;

    char temp [30];
    strcpy(temp,"Charly de la People");
    Empleado emple4 (11222333,temp,4200); //PORQUE ANDA MAL
    cout<< "AAAAA: <<"<<emple4<<endl;
    Persona pers1;
    cout<<"\tPersona pers1 dice: ";
    pers1.Hablar();
    cout<<"\tEmpleado emple1 dice: ";
    emple1.Hablar();

    Persona *emple3 = new Empleado (3,"Juan",4200); //Precargo Empleado
    cout<<"\tPersona emple3 dice: "; //Hago a hablar al puntero emple3 de tipo Persona
    emple3->Hablar();//y habla como Empleado a pesar de ser creado como puntero Persona
    cout<<endl;
    cout<<"\t-----------FIGURAS ABSTRACTAS-------------------"<<endl;
    /** FIGURAS ABSTRACTAS Y METODOS VIRTUALES **/
    Rectangulo r1 (1,2);
    cout<<"\tArea del Rectangulo (1,2) es: "<<endl;
    r1.Mostrar_area();
    cout<<"\tArea del Rectangulo (1,2)"<<endl;
    Figura *r2 = new Rectangulo (2,4);
    cout<<"\tArea del Rectangulo (2,4) llamado desde puntero Figura: "<<endl;
    r2->Mostrar_area();
    ///Si mando los 2 explota el de Empleado Persona
    /*Figura *t1 = new Triangulo (2,4);
    cout<<"\tArea del Trangulo (2,4) llamado desde puntero Figura: "<<endl;
    t1->Mostrar_area();
    */
    return 0;
}
