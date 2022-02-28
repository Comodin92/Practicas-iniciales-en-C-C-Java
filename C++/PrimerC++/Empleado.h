#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "Persona.h"
#include "Fecha.h"

using namespace std;

class Empleado : public Persona{ //LOS DOS PUNTOS INDICAN HERENCIA;
                                //ESTA ES UNA HERENCIA PUBLICA, OSEA SOLO VERE LOS ATRIBUTOS Y METODOS PUBLICOS
private:
    float sueldo;
    long legajo;
    Fecha fchIng;

public:
    Fecha fecha();//FUNCION QUE DEVUELVE UNA FECHA, ESTOY SOBREESCRIBIENDO LA FUNCION FECHA DE LA CLASE PERSONA, QUE ES DE QUIEN HERED

    Empleado(const Empleado &);
    Empleado(long = 0, const char *apyn = NULL, const Fecha &fchNac = Fecha(), int = 0, double = 0.0);
            //dni       apellido y nombre       fecha nacimiento                legajo      sueldo
            //CUANDO PASAMOS UN PUNTERO O UNA REFERENCIA (COMO FECHA Y APELLIDO) HAY QUE DAR EL NOMBRE DEL PARAMETRO
    Empleado(const char *, long, float);
//    Empleado(const Empleado&);
    void mostrar(void); //ES UN METODO QUE SE LLAMA IGUAL QUE EN LA CLASE BASE
    void hablar(void);  //ES UN METODO QUE SE LLAMA IGUAL QUE EN LA CLASE BASE
    friend ostream& operator << (ostream&, const Empleado&);
};

#endif // EMPLEADO_H_INCLUDED
