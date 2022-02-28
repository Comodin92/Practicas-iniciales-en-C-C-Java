#include "funciones.h"
#include "fecha.h"

int main()
{
    Fecha F1(1,5,1991);
    Persona P1("Diego","Sanz","Niceto Vega 2345","Ituzaingo",Fecha(F1),21,36476895,'M');       // Constructor parametrizado
    Persona P2(P1);                                                                         // Constructor por copia
    Persona P3;                                                                             // Constructor por defecto
    Persona P4;
    Persona P5;
    /* CIN CON P4 */
    cout<<"================================="<<endl<<"Persona 4 (P4)"<<endl;
    cin>>P4;
    P4.mostrarPersona();
    cout<<"================================="<<endl<<"Persona 1 (P1)"<<endl;
    P3=P1;                                                                                  // Asigno contenido de P1 a P3
    P1.mostrarPersona();
    cout<<"================================="<<endl<<"Persona 2 (P2)"<<endl;
    P2.mostrarPersona();
    cout<<"================================="<<endl<<"Persona 3 (P3)"<<endl;
    P3.mostrarPersona();
    cout<<"================================="<<endl;
    if(P4<P1)
        cout<<"P4 es menor que P1"<<endl;

    if(P1>P4)
        cout<<"P1 es mayor que P4"<<endl;
    cout<<"================================="<<endl;
    P1++;
    cout<<"Son iguales?"<<endl;
    cout<<"P1"<<endl;
    P1.mostrarPersona();
    cout<<endl<<"P3"<<endl;
    P3.mostrarPersona();
    if(P3==P1)
        cout<<"Son Iguales! "<<endl;
    else
        cout<<"Son Distintos!"<<endl;
    cout<<"================================="<<endl;
    P5=++P4;
    P4.mostrarPersona();
    cout<<"================================="<<endl;
    cout<<P5;

    cout<<endl;
    return 0;
}
