
#include "main.h"
#include <fstream>


int main()
{
    cout << "Creando pers1." << endl;
    Pers pers1;
    cout << "Mostrando pers1: ";
    cout << pers1 << endl;

    cout << "Ingresando pers1" << endl;
    //cin  >> pers1;
    stringstream ss;
    ss.str("11222333-M-57-BECERRA, Maria");
    ss >> pers1;

    cout << "Mostrando pers1: ";
    cout << pers1 << endl;
    cout << "Incrementando la edad de pers1: " <<
         pers1++ << endl;
    cout << "Mostrando pers1: ";
    cout << pers1 << endl;

    return 0;
}

