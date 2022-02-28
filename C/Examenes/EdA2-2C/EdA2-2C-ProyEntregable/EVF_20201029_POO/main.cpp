#include <iostream>

#include "Recta.h"

using namespace std;

int main()
{
    Recta r1(Punto(2, 0), Punto(0, 2));
    Recta r2(Punto(1, 0), Punto(1, 2));

    Punto p(2,2);

    cout << "Punto de Interseccion entre las rectas " <<
            r1 << " y " << r2 << ": " << (r1 && r2) << endl; ///(r1 && r2)

    cout << "Distancia del punto " << p << " a la recta " <<
            r1 << ": " << (r1 - p) << endl;///r1 - p

    cout << "Distancia del punto " << p << " a la recta " <<
            r2 << ": " << (r2 - p ) << endl; /// - p

    return 0;
}
