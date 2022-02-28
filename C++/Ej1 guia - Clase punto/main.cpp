#include <iostream>
#include "Punto.h"

using namespace std;

int main()
{
    Punto p1(3,5);
    Punto p2(4,5);
    Punto p3 = p1+p2;
    cout<<p3;
    p2 = p3-p1;
    cout<<p1;
    cout<<p2;
    return 0;
}




