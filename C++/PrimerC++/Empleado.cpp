#include "Empleado.h"
#include "Persona.h"
#include "Fecha.h"

//OK
Empleado :: Empleado(const Empleado &obj): Persona(static_cast < const Persona& >(obj)){
    this->legajo = obj.legajo;
    this->sueldo = obj.sueldo;
}

//OK
Empleado :: Empleado(long dni, const char *apyn, const Fecha &fchNac, int leg, double sueldo): Persona(apyn,dni,fchNac){//EL CONSTRUCTOR DE PERSONA NO ESTA HECHO CON LA FECHA
    this->legajo = leg;
    this->sueldo = sueldo;
}

Fecha Empleado :: fecha(){
    return this->fchIng;
}

//OK
ostream& operator << (ostream& sal, const Empleado& emp){
    sal << static_cast <const Persona& > (emp);//CASTEO EL EMPLEADO QUE RECIBO A PERSONA, ENTONCES AL TENER UNA PERSONA, CUANDO UTILIZO LA FUNCION << (MENOR MENOR) IMPRIME LOS DATOS CORRESPONDIENTES A PERSONA DEL EMPLEADO QUE RECIBI (ES DECIR APELLIDO DNI FCH_NAC
    sal << "\nLegajo: " << emp.legajo << "\nSueldo: " << emp.sueldo << "\nFecha de ingreso: " << emp.fchIng;
    return sal;
}

//OK
void Empleado :: hablar(void){
    cout << "Hola, EMPLEADO \"" << this->apyn << "\" hablando" << endl << endl;
}

//OK
void Empleado :: mostrar(void){//OK
    cout << "[" << apyn << " - Legajo: " << legajo << "]\tMostrando EMPLEADO mediante metodo 'mostrar'" << endl;
}
