#include "funciones.h"
#include "fecha.h"

Persona::Persona()
{
    nom=NULL;
    ape=NULL;
    dom=NULL;
    fnac=Fecha();
    edad=0;
    dni=0;
}

Persona::Persona(char *n,char *a,char *d,char *l ,const Fecha&f,int e ,long int dni,char s)
{
    nom=str_new_dup(n);
    if(nom==NULL && n)
        cout<<"Error Sin Memoria"<<endl;
    ape=str_new_dup(a);
    if(ape==NULL && a)
        cout<<"Error Sin Memoria"<<endl;
    dom=str_new_dup(d);
    if(dom==NULL && d)
        cout<<"Error Sin Memoria"<<endl;
    if(l)
        strcpy(loc,l);
    fnac=f;
    edad=e;
    this->dni=dni;
    sexo=s;
}

Persona::Persona(const Persona& obj)
{
    nom=str_new_dup(obj.nom);
    if(nom==NULL && obj.nom)
        cout<<"Error Sin Memoria"<<endl;
    ape=str_new_dup(obj.ape);
    if(ape==NULL && obj.ape)
        cout<<"Error Sin Memoria"<<endl;
    dom=str_new_dup(obj.dom);
    if(dom==NULL && obj.dom)
        cout<<"Error Sin Memoria"<<endl;
    strcpy(loc,obj.loc);
    fnac=obj.fnac;
    dni=obj.dni;
    sexo=obj.sexo;
}

/*Persona::Persona(char *n=NULL,char *a=NULL,char *d=NULL,char *l=NULL,int e=0,const Fecha&f=Fecha(),long int dni=0,char s='')
{
    nom=str_new_dup(n);
    if(nom==NULL && n)
        cout<<"Error Sin Memoria"<<endl;
    ape=str_new_dup(a);
    if(ape==NULL && a)
        cout<<"Error Sin Memoria"<<endl;
    dom=str_new_dup(d);
    if(dom==NULL && d)
        cout<<"Error Sin Memoria"<<endl;
    strcpy(loc,l);
    fnac=f;
    edad=e;
    this->dni=dni;
    sexo=s;
}
*/
Persona::~Persona()
{
    delete []nom;
    delete []ape;
    delete []dom;
}


char* Persona::str_new_dup(const char *s)
{
    if(s && *s)
    {
        char *aux=new char[(strlen(s)+1)];
        if(aux)
            strcpy(aux,s);
        return aux;
    }
    return NULL;
}

ostream& operator<<(ostream& sal,const Persona& obj)
{
    cout<<"Persona"<<endl<<"----------"<<endl;
    sal<<"Nombre: "<<obj.nom<<endl;
    sal<<"Apellido: "<<obj.ape<<endl;
    sal<<"Domicilio: "<<obj.dom<<endl;
    sal<<"Localidad: "<<obj.loc<<endl;
    sal<<"Fecha "<<endl<<obj.fnac<<endl;
    sal<<"Edad: "<<obj.edad<<endl;
    sal<<"DNI: "<<obj.dni<<endl;
    sal<<"Sexo: "<<obj.sexo<<endl;
    return sal;
}

istream& operator>>(istream& ent,Persona& obj)
{
    char aux[100];
    delete []obj.nom;
    cout<<"Persona";
    cout<<endl;
    ent.ignore(100,'\n');
    cout<<"Nombre: ";
    ent.getline(aux,sizeof(aux),'\n');
    obj.nom= obj.str_new_dup(aux);
    if(obj.nom==NULL && *aux)
        cout<<"Error Sin Memoria"<<endl;
    cout<<endl;
    delete []obj.ape;
    ent.ignore(100,'\n');
    cout<<"Apellido: ";
    ent.getline(aux,sizeof(aux),'\n');
    obj.ape= obj.str_new_dup(aux);
    if(obj.ape==NULL && *aux)
        cout<<"Error Sin Memoria"<<endl;
    cout<<endl;
    delete []obj.dom;
    ent.ignore(100,'\n');
    cout<<"Domicilio: ";
    ent.getline(aux,sizeof(aux),'\n');
    obj.dom= obj.str_new_dup(aux);
    if(obj.dom==NULL && *aux)
        cout<<"Error Sin Memoria"<<endl;
    cout<<endl;
    cout<<"Localidad: ";
    ent.getline(obj.loc,sizeof(obj.loc),'\n');
    cout<<endl;
    ent>>obj.fnac;
    cout<<endl;
    cout<<"Edad: ";
    ent>>obj.edad;
    cout<<endl;
    cout<<"DNI: ";
    ent>>obj.dni;
    cout<<endl;
    cout<<"Sexo: ";
    ent>>obj.sexo;
    cout<<endl;
    return ent;
}

void Persona::mostrarPersona()
{
    cout<<"Persona"<<endl<<"----------"<<endl;
    cout<<"Nombre: "<<nom<<endl;
    cout<<"Apellido: "<<ape<<endl;
    cout<<"Domicilio: "<<dom<<endl;
    cout<<"Localidad: "<<loc<<endl;
    cout<<endl<<"Fecha Nacimiento"<<endl<<fnac<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"Sexo: "<<sexo<<endl;
}

Persona& Persona::operator=(const Persona& obj)             // operador asignacion
{
    delete []nom;
    nom= str_new_dup(obj.nom);
    if(nom==NULL && obj.nom)
        cout<<"Error Sin Memoria"<<endl;
    delete []ape;
    ape= str_new_dup(obj.ape);
    if(ape==NULL && obj.ape)
        cout<<"Error Sin Memoria"<<endl;
    delete []dom;
    dom= str_new_dup(obj.dom);
    if(dom==NULL && obj.dom)
        cout<<"Error Sin Memoria"<<endl;
    strcpy(loc,obj.loc);
    fnac=obj.fnac;
    edad=obj.edad;
    dni=obj.dni;
    sexo=obj.sexo;
    return *this;
}

Persona& Persona::operator++()      // Pre Incremento
{
    edad++;
    return *this;
}

Persona Persona::operator++(int a)  // Pos Incremento
{
    Persona aux(*this);
    edad++;
    return aux;
}

bool Persona::operator==(const Persona& obj)
{
    if(strcmp(nom,obj.nom)==0)
    {
        if(strcmp(ape,obj.ape)==0)
        {
            if(strcmp(dom,obj.dom)==0)
            {
                if(strcmp(loc,obj.loc)==0)
                {
                    if(fnac==obj.fnac)              // Operador == de Clase Fecha
                    {
                        if(edad==obj.edad)
                        {
                            if(dni==obj.dni)
                            {
                                if(sexo==obj.sexo)
                                    return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Persona::operator<(const Persona &obj)
{
    return fnac<obj.fnac?true:false;                    // Las comparaciones se realizan con las fechas se encuentran en el fecha.cpp
}

bool Persona::operator>(const Persona &obj)
{
    return fnac>obj.fnac?true:false;
}
