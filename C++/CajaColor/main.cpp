#include "CajaColor.h"

int main()
{
    CajaColor   c1(10.5,20.0,32,"Celeste y Blanco"),
                c2(),
                c3;
    c2=c1--;
    c3=c2++;
    CajaColor   c4=c3++,
                c5(c2);
    cout<<c4<<endl;
    c4.CambiarColor("Azul de prusia intenso");
    c5=c4;
    cout<<c1<<endl;
    cout<<c2<<endl;
    cout<<c3<<endl;
    cout<<c4<<endl;
    cout<<c5<<endl;

    return 0;
}
