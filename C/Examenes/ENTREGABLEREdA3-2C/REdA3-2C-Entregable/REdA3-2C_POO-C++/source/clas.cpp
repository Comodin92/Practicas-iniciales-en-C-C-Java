
#include "../include/clase.h"
/***
Tirando la excepcion acá me aseguro de que no se puede dividir por 0 en ningun caso,
porque estamos en el constructor ya que tendrán basura, para no preguntar en cada caso si
tienen que divirse por 0,para mi gusto es mejor ver las operaciones sin hacer ya que si corto
la ejecucion no me muestra el segundo racional.
***/
Racional::Racional(int nume, int deno)
{


    if(signo(deno))
    {
        nume = -nume;
        deno = -deno;
    }
    try{
        if(deno == 0)
    {
     throw "Imposible dividir por 0, al ser un constructor las variables tendran basura\n\n";
    }

    int divisor = mcd(nume, deno);
    this->nume = nume / divisor;
    this->deno = deno / divisor;
    }catch(const char *error){

        cout << "Error: "<<error<<endl;

    }
}

int Racional::absoluto(int n)
{
    if(signo(n))
        n = - n;
    return n;
}

int Racional::signo(int n)
{
    return n < 0 ;
}

int Racional::mcd(int a, int b)
{

    int resto = a % b;
    while(resto)
    {
        a = b;
        b = resto;
        resto = a % b;
    }
    return absoluto(b);

}

ostream &operator <<(ostream &salida, Racional racio)
{
    cout << racio.nume << '/' << racio.deno;
    return salida;
}

int Racional::getNumerador()
{
    return nume;
}

int Racional::getDenominador()
{
    return deno;
}

int Racional::enteroMasCercano()
{
    return float(nume) / deno + .5;
}

void Racional::aEnteroYFraccion(Racional r)
{
    /***
    tambien se las llaman mixtas
    donde num/den = entero entonces entero (num/den )- entero
    ***/

    int     enteros = r.nume / r.deno;
    cout << enteros << " " << (r.deno * (-enteros))+r.nume<<"/"<<r.deno;///

}

Racional Racional::operator++()
{
    ///nume += deno;
    nume = nume * 1 + deno; ///denominador * 1 + nume
    ///Como el denominador no se modifica no se lo utiliza
    return *this;
}

