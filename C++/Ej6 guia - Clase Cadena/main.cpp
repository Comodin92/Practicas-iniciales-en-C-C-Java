#include <iostream>
#include "Cadena.h"

using namespace std;

int main()
{
    Cadena cadena("Sarasa");
    Cadena cadena2("ab");
    cadena -= cadena2;
    cout<<cadena;
    return 0;
}
