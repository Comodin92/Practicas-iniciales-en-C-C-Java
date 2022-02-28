#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;

class Fecha
{
    private:
        int dd;
        int mm;
        int aaaa;
    public:
        Fecha();                    // Constructor por Defecto
        Fecha(int ,int ,int );      // Constructor Parametrizado
        Fecha(const Fecha& );       // Constructor por Copia
        // Operador de asignacion
        Fecha& operator=(const Fecha&);
        // Destructor
        ~Fecha();
        // Cout y Cin
        friend ostream& operator<<(ostream& ,const Fecha&);
        friend istream& operator>>(istream& ,Fecha&);
        void mostrarFecha();
        // Operadores de Igualdad y desigualdad
        bool operator==(const Fecha& );
        bool operator<(const Fecha& );
        bool operator>(const Fecha& );
};

#endif // FECHA_H_INCLUDED
