#include <iostream>
#include "Hora.h"

using namespace std;

int main()
{
    Hora h1(86399);
    h1.mostrar();

    Hora h2(86400);
    h2.mostrar();

    Hora h3(86401);
    h3.mostrar();

    Hora h4(83565);
    h4.mostrar();

    Hora h5(34837);
    h5.mostrar();

    h5++;
    h5.mostrar();

    --h5;
    h5.mostrar();

    cout<<h5;

    Hora h6;

    cin>>h6;

    cout<<h6;


    return 0;
}
