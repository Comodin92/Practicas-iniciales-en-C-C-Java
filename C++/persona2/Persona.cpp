#include "Persona.h"
char *duplicarCadena(const char *cad)
{
    if(cad && *cad)
    {
        try
        {
            char *aux = new char[strlen(cad)+1];
            strcpy(aux,cad);
            return aux;
        }
        catch(bad_alloc &exc)
        {
           cerr<<"sin memoria duplicarCadena()" << exc.what()<<endl;
        }
    }
    return NULL;
}

ostream & operator << (ostream &salida, const Persona &objPers)
{
    salida << "NyA: " <<(objPers.apyn ? objPers.apyn : "S/D" )<< " Edad: " << (objPers.edad >-1 ? objPers.edad : 0)
    <<"Sexo: " << (objPers.sexo != 'x' ? objPers.sexo : '?') <<" DNI: " <<(objPers.dni > -1L ? objPers.dni : 0L)<<endl;
    return salida;
}
Persona::Persona(const char *nyap, const int ed, const char sexo, const long dni)
{
    edad = ed;
    this->sexo = sexo;
    this->dni = dni;
    apyn = duplicarCadena(nyap);
    if(!apyn && nyap &&*nyap)
        cerr<<"sin memoria constructor parametrizado"<<endl;
}

Persona::~Persona()
{
    if(apyn)
    {
        delete []apyn;
        apyn = NULL;
    }
}

Persona::Persona(const Persona& obj)
{
    edad = obj.edad;
    sexo = obj.sexo;
    dni = obj.dni;
    apyn = duplicarCadena(obj.apyn);
    if(!apyn && obj.apyn && *obj.apyn)
        cerr<<"sin memoria constructor de copia"<<endl;
}
Persona & Persona :: operator = (const Persona & obj)
{
    edad = obj.edad;
    sexo = obj.sexo;
    dni = obj.dni;
    apyn = duplicarCadena(obj.apyn);
    if(!apyn && obj.apyn && *obj.apyn)
        cerr<<"sin memoria operator = "<<endl;
    return *this;
}
istream & operator >>(istream &ing, Persona &objPers)
{
    cout <<"Ingrese DNI: ";
    ing>>objPers.dni;
    cout <<"Ingrese Nombre y apellido: ";
    char *aux = new char[500];
    if(aux)
    {
        ing.ignore(500,'\n'); //limpio buffer
        ing.getline(aux,500,'\n');
        if(objPers.apyn)
            delete[]objPers.apyn;
        objPers.apyn = duplicarCadena(aux);
        if(!objPers.apyn && *aux)
            cerr<<"Error de memoria en operator >>"<<endl;
        delete[]aux;
        //ing.ignore(1000,'\n');
    }
    cout<<"Ingrese sexo: ";
    ing>>objPers.sexo;
    cout<<"Ingrese edad: ";
    ing>>objPers.edad;
    return ing;
}

void Persona :: verPersona()const
{
    cout<<"Nombre: " << ((apyn != NULL) ? apyn : "S/D")  << " edad: "<< edad << " sexo: " <<  sexo << " dni: " << dni<<endl;
}
