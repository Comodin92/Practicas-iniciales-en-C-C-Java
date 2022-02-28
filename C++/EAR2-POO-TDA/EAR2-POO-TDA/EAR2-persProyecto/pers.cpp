/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/

#include "pers.h"
/// DESARROLLE ACÁ LOS MÉTODOS (y FUNCIONES MIEMBRO) DE LA CLASS
Pers::Pers(long _dni, string _apyn, char _sexo, int _edad)
{
    dni = _dni;
    apyn = _apyn;
    sexo = _sexo;
    edad = _edad;

}
ostream &operator<<(ostream &obj, const Pers &perso) {
    obj << "Nombre: " << perso.apyn << endl<<
    " Edad: " << perso.edad<<endl<<
    "Dni:" << perso.dni<<endl<<
    "sexo: " << perso.sexo<<endl;
    return obj;
}


istream &operator>>(istream &obj, Pers &persona){
    cout<<"Ingrese nombre y apellido: ";
    ///cin.getline(persona.apyn,300,'\n');
    obj>>persona.apyn;
    cout<<"Ingrese Edad:";
    obj>>persona.edad;
    cout<<"Ingrese dni:";
    obj>>persona.dni;
    cout<<"Ingrese Sexo: m/f";
    obj>>persona.sexo;
    return obj;
}

Pers Pers::operator++(int)
{
    Pers aux = *this;
    this->edad++;
    return aux;

}                                                 // incrementa edad


