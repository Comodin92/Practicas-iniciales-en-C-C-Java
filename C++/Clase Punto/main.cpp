#include "Punto.h"

int main()
{
    Punto p1;
    Punto p2;
    Punto p3;
    Punto p4;

    cin>>p2;
    cout<<p2;

    cout<<"p3:"<<endl;
    p3.mostrar_Punto();

    cin>>p2;
    cin>>p3;
    if(p2==p3)
        cout<<"SON IGUALES"<<endl;
    else
        cout<<"SON DISTINTOS"<<endl;

    return 0;
}
