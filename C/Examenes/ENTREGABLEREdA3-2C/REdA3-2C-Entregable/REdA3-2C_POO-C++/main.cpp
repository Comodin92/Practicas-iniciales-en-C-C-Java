
#include "include/main.h"


int main()
{
    int         nume = 7575,
                deno = 0;//72

    cout << "creando objeto racional con " << nume << " y " << deno << endl;

    Racional    r(nume, deno);

    operarConRacional(r);

    nume = 66;
    deno = 54;

    cout << "creando objeto racional con " << nume << " y " << deno << endl;
    Racional    otro(nume, deno);

    operarConRacional(otro);


    return 0;
}

void operarConRacional(Racional r1)
{
    cout << "Racional r1 = " << r1 << endl;
    cout << " - Numerador = " << r1.getNumerador() << endl <<
            " - Denominador = " << r1.getDenominador() << endl <<
            " - Entero mas cercano = " << r1.enteroMasCercano() << endl <<
            " - entero + fraccion = ";
    Racional().aEnteroYFraccion(r1);
    cout << endl;
    cout << " - ++r1 = " << ++r1 << endl << endl;
}

