#include "Punto.h"

/*Punto::Punto()
{
    x=0;
    y=0;
}*/

Punto::~Punto() // AUTOMATICAMENTE ANTES DE FINALIZAR LA EJECUCION ELIMINA
{
    /** delete[]variable  en este caso no hace falta */
    cout<<"Se elimino ( "<<x<<" , "<<y<<" )"<<endl;
}

/*Punto::Punto(const Punto& p)
{
    x=p.x;
    y=p.y;
}*/

/*Punto::Punto(int x,int y)
{
    this->x=x;
    this->y=y;
}*/

Punto::Punto(int x,int y)
{
    this->x=x;
    this->y=y;
}

void Punto::mostrar_Punto()
{
    cout<<"x="<<x<<endl<<"y="<<y<<endl;
}

int Punto::Getx()
{
    return x;
}

void Punto::Setx(int x)
{
    this->x=x;
}

int Punto::Gety()
{
    return y;
}

void Punto::Sety(int y)
{
    this->y=y;
}

Punto& Punto::operator=(const Punto& p)
{
    x=p.x;
    y=p.y;
    return *this;
}

Punto Punto::operator+(const Punto& p)const
{
    return Punto (x+p.x,y+p.y); // ni siquiera necesita nombre
}

Punto Punto::operator-(const Punto&p)const
{
    return Punto (x-p.x,y-p.y);
}

Punto Punto::operator*(const Punto&p)const
{
    return Punto(x*p.x,y*p.y);
}

Punto Punto::operator/(const Punto&p)const
{
    if(p.x!=0 && p.y!=0)
        return Punto(x/p.x,y/p.y);
    return *this;
}

bool Punto::operator==(const Punto&p)const
{
    return (x==p.x && y==p.y);
}

bool Punto::operator!=(const Punto&p)const
{
    return (x!=p.x && y!=p.y);
}

Punto& Punto::operator+=(const Punto&p)
{
    x+=p.x;
    y+=p.y;
    return *this;
}

Punto& Punto::operator-=(const Punto&p)
{
    x-=p.x;
    y-=p.y;
    return *this;
}

Punto& Punto::operator*=(const Punto&p)
{
    x*=p.x;
    y*=p.y;
    return *this;
}

Punto& Punto::operator/=(const Punto&p)
{
    if(p.x!=0 && p.y!=0)
    {
        x/=p.x;
        y/=p.y;
        return *this;
    }
    return *this;
}

Punto Punto::operator-()const
{
    return Punto(-x,-y);
}

Punto& Punto::operator++()
{
    ++x;
    ++y;
    return *this;
}

Punto& Punto::operator--()
{
    --x;
    --y;
    return *this;
}

Punto Punto::operator++(int)
{
    return Punto(x++,y++);
}

Punto Punto::operator--(int)
{
    return Punto(x--,y--);
}

Punto Punto::operator*(int n)const
{
    return Punto(x*n,y*n);
}

Punto& Punto::operator*=(int n)
{
    x*=n;
    y*=n;
    return *this;
}

Punto operator*(int n,const Punto&p)
{
    return Punto(p.x*n,p.y*n);
}

istream&operator>>(istream& ent,Punto& p)
{
    cout<<"x= ";
    ent>>p.x;
    cout<<"y= ";
    ent>>p.y;
    return ent;
}

ostream&operator<<(ostream& sal,const Punto& p)
{
    sal<<'('<<p.x<<" , "<<p.y<<')'<<endl;
    return sal;
}
