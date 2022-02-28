#include <math.h>

#include "RectaException.h"
#include "Recta.h"
#include <cmath>

Recta::Recta(const Punto& p1,const Punto& p2)
{
    this->p1 = p1;
    this->p2 = p2;
}

Punto Recta::operator&&(const Recta &r2)const
{
    try
    {
    ///Para evitar confusion y facilitar la lectura usaré variables para identificar los Xi e Y
    double x1= p1.getX(),
           y1= p1.getY(),
           x2= p2.getX(),
           y2= p2.getY(),
           x3= r2.p1.getX(),
           y3= r2.p1.getY(),
           x4= r2.p2.getX(),
           y4= r2.p2.getY(),
           denominador;
    Punto aux;

    ///realizamos el calculo, primero el denominador se repite para ambas coordenadas
    denominador =( ((x1 - x2 )*(y3 - y4)) - ((y1 - y2)*(x3- x4))  );

//    denominador = 0;
    if(!denominador) ///Si el denominador es 0 tiramos la excepcion
        {
            cout<<"Error en interseccion enttre recta "<< *this << "y"<< r2 << endl<< "El denominador es 0"<<endl;
            throw RectaException();
        }
    aux.setX ( ((( (x1*y2) - (y1*x2)) * (x3 - x4))  -  (((x1 - x2)* ((x3*y4) - (y3*x4 ) )))) / denominador );
    aux.setY(((( (x1*y2) - (y1*x2)  ) * (y3 - y4))  -  (((y1 - y2)* ((x3*y4) - (y3*x4 )) )))  /denominador );
    return aux;
    }catch(RectaException& error)
    {
                throw error;
    }

    return 1;
}

double  Recta::operator -(const Punto &p) const
{
    try{
    double aux,
            numerador,
            denominador,
           x0= p.getX(),
           y0= p.getY(),
           x1= this->p1.getX(),
           y1= p1.getY(),
           x2= p2.getX(),
           y2=  p2.getY();

    numerador = (((y2-y1)*x0 ) - ((x2-x1)*y0 ) + (x2*y1) - (y2*x1)); ///algoritmo por enunciado
    numerador = (numerador <0 ) ? numerador*(-1): numerador;
    aux  = pow((y2 - y1), 2) +    pow((x2 - x1), 2); ///Uso resultado para no declarar otra variable
    ///aux = -1;
    ///aux = 0;
    if(aux <= 0) ///No puede ser 0 por ser parte del denominador ni tampoco negativo ya que hay que hacerle la raiz cuadrada
    {
        cout<<"Error, en distancia del punto" << p << "a la recta"<< *this <<endl<< "El denominador es 0"<<endl;
         throw RectaException();
    }
    denominador = sqrt(aux);

    return numerador / denominador;

    }
    catch(RectaException& error)
    {
        throw error;
    }
    return 1;
}

ostream& operator <<(ostream& sal, const Recta& r)
{
    sal<<"["<<r.p1<<", "<<r.p2<<"]";
    return sal;
}

