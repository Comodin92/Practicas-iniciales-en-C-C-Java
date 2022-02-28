#include "CajaColor.h"

char *str_new_dup(char *s)
{
    if(s && *s)
    {
        char *aux=new char[strlen(s)+1];
        if(aux)
            strcpy(aux,s);
        return aux;
    }
    return NULL;
}


/////////////////////////////////////////////////////////////////
//CONSTRUCTORES
/////////////////////////////////////////////////////////////////

CajaColor::CajaColor()
{
    ancho=alto=largo=0.0;
    color=NULL;
}

CajaColor::CajaColor(float anc,float alt,float lar,char *c)
{
    ancho=anc;
    alto=alt;
    largo=lar;
    color=str_new_dup(c);
    if(c && *c && color==NULL)
        cout<<"Error Sin Memoria!"<<endl;
}

CajaColor::CajaColor(const CajaColor& obj)
{
    ancho=obj.ancho;
    alto=obj.alto;
    largo=obj.largo;
    color=str_new_dup(obj.color);
    if(obj.color && color==NULL)
        cout<<"Error Sin Memoria!"<<endl;
}

/////////////////////////////////////////////////////////////////
// DESTRUCTOR
/////////////////////////////////////////////////////////////////

CajaColor::~CajaColor()
{
    delete []color;
}

/////////////////////////////////////////////////////////////////

void CajaColor::CambiarColor(char *cn)
{
    delete []color;
    color=str_new_dup(cn);
}

CajaColor& CajaColor::operator=(const CajaColor& obj)
{
    ancho=obj.ancho;
    alto=obj.alto;
    largo=obj.largo;
    delete []color;
    color=str_new_dup(obj.color);
    return *this;
}

ostream& operator<<(ostream& sal,CajaColor& obj)
{
    cout<<"Ancho: ";
    sal<<obj.ancho<<endl;
    cout<<"Alto: ";
    sal<<obj.alto<<endl;
    cout<<"Largo: ";
    sal<<obj.largo<<endl;
    cout<<"Color: ";
    sal<<(obj.color?obj.color:"***")<<endl;
    return sal;
}

CajaColor CajaColor::operator++(int)
{
    CajaColor aux(*this);
    if(largo<MAX_LONG)
        largo++;
    return aux;
}

CajaColor CajaColor::operator--(int)
{
    CajaColor aux(*this);
    if(alto>MIN_ALT)
        alto--;
    return aux;
}
