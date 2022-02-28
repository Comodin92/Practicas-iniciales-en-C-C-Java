#include "Hora.h"

    /* Constructores */
Hora::Hora()
{
    hora = min = seg = 0;
}

Hora::Hora(int h, int m, int s)
{
    hora = h;
    min = m;
    seg = s;
}
    /** Operadores */
Hora Hora::operator+(const Hora& obj)
{
    return Hora(hora+obj.hora,min+obj.min,seg+obj.seg);
}

Hora Hora::operator-(const Hora& obj)
{
    return Hora(hora-obj.hora,min-obj.min,seg-obj.seg);
}

Hora Hora::operator+(const int i)
{
    return Hora(hora,min,seg+i);

}

Hora Hora::operator-(const int i)
{
    return Hora(hora,min,seg-i);
}

Hora& Hora::operator=(const Hora& obj)
{
    hora = obj.hora;
    min = obj.min;
    seg = obj.seg;
    return *this;
}

Hora& Hora::operator+=(const Hora& obj)     // este incremento es entre clases hora
{
    hora += obj.hora;                       // este incremento se realiza en enteros
    min += obj.min;
    seg += obj.seg;
    return *this;
}

Hora& Hora::operator-=(const Hora& obj)
{
    hora -= obj.hora;
    min -= obj.min;
    seg -= obj.seg;
    return *this;
}

Hora Hora::operator++(int i) ///?                  ?????????????????
{
    Hora aux(*this); //???
    seg++;
    return aux;
}

Hora& Hora::operator++()
{
    seg++;
    return *this;
}

bool Hora::operator==(const Hora& obj)
{
    return ((obj.hora==hora)&&(obj.min==min)&&(obj.seg==seg)?true:false);
}

bool Hora::operator!=(const Hora& obj)
{
    return ((obj.hora==hora)&&(obj.min==min)&&(obj.seg==seg)?false:true);
}

bool Hora::operator<=(const Hora& obj)
{
    return ((obj.hora<=hora)&&(obj.min<=min)&&(obj.seg<=seg)?true:false);
}

bool Hora::operator<(const Hora& obj)
{
    if(obj.hora<=hora)
    {
        if(obj.hora==hora)
        {
            if(obj.min<=min)
            {
                if(obj.min==min)
                {
                    if(obj.seg<seg)
                        return true;
                    else
                        return false;
                }
                return true;
            }
        }
        return true;
    }
    return false;
}

bool Hora::operator>=(const Hora& obj)
{
    return ((obj.hora>=hora)&&(obj.min>=min)&&(obj.seg>=seg)?true:false);
}

bool Hora::operator>(const Hora& obj)
{
    return ((obj.hora>hora)&&(obj.min>min)&&(obj.seg>seg)?true:false);
}
    /* Metodos */
