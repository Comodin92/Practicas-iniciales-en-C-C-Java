#include "Persona.h"
#include "Varias.h"

/* constructores */
Persona::Persona()
{
    nom=NULL;
    fNac = Fecha();
    dni = 0;
}

Persona::Persona(char * n, char * d, const Fecha& f, int dni)
{
    nom = Varias::str_new_dup(n);
    if(n && *n && nom == NULL)
        cout<<"SIN MEMORIA";
    if(d)
        strcpy(dir,d);
    fNac = f;
    this->dni = dni;
}

Persona::Persona(const Persona& obj)                        //constructor de copia
{
    nom = Varias::str_new_dup(obj.nom);
    if(nom == NULL && obj.nom)
        cout<<"Error: sin memoria";
    strcpy(dir,obj.dir);
    fNac = obj.fNac;
    dni = obj.dni;
}

/*Persona::Persona(char * n= NULL, char * d= NULL, const Fecha& f =Fecha(),int dni=0)
{
    nom = n;
    dir = d;
    fNac = f;
    this->dni = dni;
}
*/

/* sobrecarga de operadores */
Persona& Persona::operator=(const Persona& obj)
{
    delete[]nom;
    nom=Varias::str_new_dup(obj.nom);
    if(nom==NULL && obj.nom)
        cout<<"Error: sin memoria";
    strcpy(dir,obj.dir);
    fNac = obj.fNac;
    dni = obj.dni;
    return *this;

}

Persona& Persona::operator++()                  //preincremento
{
    fNac++;
    return *this;
}

Persona Persona::operator++(int a)                 //posincremento
{
    Persona aux(*this);
    fNac++;
    return aux;

}

ostream& operator<<(ostream& sal,const Persona& obj)
{
    sal<<"Nombre: "<<obj.getNom()<<endl;
    sal<<"Direccion: "<<obj.getDir()<<endl;
    sal<<"Fecha de Nacimiento: "<<obj.getFnac()<<endl;
    sal<<"DNI: "<<obj.getDNI()<<endl;
    return sal;
}

istream& operator>>(istream& ent, Persona& obj)
{
    char aux[100];                      //auxiliar para lectura. Se pone una maxima longitud
    delete[]obj.nom;
    ent.ignore(100,'\n');               //una especie de fflush. Limpia el buffer.
    ent.getline(aux,sizeof(aux),'\n');
    obj.nom = Varias::str_new_dup(aux);
    if(obj.nom==NULL&&*aux)
        cout<<"SIN MEMORIA";

    ent.ignore(100,'\n');
    ent.getline(obj.dir,sizeof(obj.dir),'\n');

    ent>>obj.fNac;
    ent>>obj.dni;
    return ent;
}

/* destructor */
Persona::~Persona()
{
    delete[]nom;
    //el destructor llama a los destructores de los objetos que contiene (ejemplo: invoca al destructor de fNac)
}

/* metodos */

void Persona::mostrar()
{
    cout<<(nom?nom:"***")<<endl;    //Nulos no se tienen que mostrar -> aparecen feos.
    cout<<dir<<" "<<fNac<<" "<<dni<<endl;
}

char * Persona::getNom()const
{
    return nom;
}

const char * Persona::getDir()const
{
    return dir;
}

Fecha Persona::getFnac()const
{
    return fNac;
}

int Persona::getDNI()const
{
    return dni;
}
