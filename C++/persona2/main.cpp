#include "Persona.h"

int main()
{
    Persona c1("Carlos",30,'M',123456),c2(c1),c3,c4,c5;
    c1.~Persona();

    cout<<c2;
    c3 = c2;
    cout<<c4;
    cin>>c5;
    cout<<c5;
    //c3.verPersona();
    //c1.verPersona();
    //c2.verPersona();
    return 0;
}
