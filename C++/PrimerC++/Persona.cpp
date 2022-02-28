#include <iostream>
#include <string.h>
#include "persona.h"

using namespace std;

//OK
Persona :: Persona(const char *apyn, long dni, const Fecha &fchNac){//OK
    this->dni = dni;
    this->apyn = new char[(strlen(apyn))+1];//RESERVO LA CANTIDAD STRLEN(APYN)+1 LUGARES DE MEMORIA
    strcpy(this->apyn,apyn);
    this->fchNac = fchNac;
}

//OK
Persona :: Persona(const Persona &obj){//OK
    this->dni = obj.dni;
    this->apyn = new char[strlen(obj.apyn)+1];
    strcpy(this->apyn,obj.apyn);
    this->fchNac = obj.fchNac;
}

//OK
void Persona :: mostrar(void){
    cout << "[" << apyn << "-" << dni << "]\tMostrando PERSONA mediante metodo 'mostrar'" << endl;
}

Persona :: ~Persona(){
    delete[]apyn;
}

//OK
void Persona :: hablar(void){
    cout << "Hola, PERSONA \"" << this->apyn << "\" hablando" << endl << endl;
}

Fecha Persona :: fecha(){
    return this->fchNac;
}

//OK
ostream& operator <<(ostream& sal, const Persona& obj){
    sal << "Sobrecargando operador \"<<\"\nDNI: " << obj.dni << "\nNombre: " << obj.apyn << "\nFecha Nac: " << obj.fchNac;
    return sal;
}
