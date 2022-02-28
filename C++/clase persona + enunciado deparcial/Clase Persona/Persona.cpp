#include "Persona.h"

char* duplicar_cad(const char* cad)
{
    char* aux;

    if(cad && *cad)
    {
        try
        {
            aux=new char[strlen(cad)+1];
            strcpy(aux,cad);
            return aux;
        }
        catch(bad_alloc &err)
        {
            cerr<<"No hay memoria Error: "<<err.what()<<endl;
        }
    }

    return NULL;
}

Persona::Persona()
{
    dni=0;
    apyn=NULL;
    nac=0;
    fnac=Fecha();
    t=Titular();
}

Persona::~Persona()
{
    delete []apyn;
}

Persona::Persona(const Persona& obj)
{
    dni=obj.dni;
    nac=obj.nac;
    fnac=obj.fnac;
    t=obj.t;
    apyn=duplicar_cad(obj.apyn);
    if(!apyn && obj.apyn && *obj.apyn)
        cerr<<"Error en constructor por Copia"<<endl;
}

Persona::Persona(long dni,const char* apyn,const Fecha& fnac,unsigned int nac,const Titular& t)
{
    this->dni=dni;
    this->fnac=fnac;
    this->nac=nac;
    this->apyn=duplicar_cad(apyn);
    this->t=t;
    if(!this->apyn && apyn && *apyn)
        cerr<<"Error en constructor Parametrizado"<<endl;
}

ostream& operator<<(ostream& sal,const Persona& obj)
{
    sal<<endl<<"Dni: "<<obj.dni<<endl<<"AP. NOM: "<<((obj.apyn)?obj.apyn:"Sin asignar")<<endl<<"Nacionalidad: "<<obj.nac<<endl<<"Fecha Nac: "<<obj.fnac<<endl;
    cout<<obj.t<<endl;
    return sal;
}

Persona& Persona::operator=(const Persona& obj)
{
    dni=obj.dni;
    fnac=obj.fnac;
    nac=obj.nac;
    t=obj.t;
    apyn=duplicar_cad(obj.apyn);
    if(!apyn && obj.apyn && *obj.apyn)
        cerr<<"Error en operador ="<<endl;

    return *this;
}

long Persona::identificacion()
{
    return dni;
}
