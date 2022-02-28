#include "../include/Vientos.h"




/// complete el desarrollo de los métodos de la class

Vientos :: Vientos(string nombre,char escala, string material):Instrumento(nombre, escala), _material(material)
{
//    this->_nombre = nombre;
//    this-> _escala = escala;
//    this->_material = material;
}

Vientos  Vientos :: operator--(int)
{
    Vientos aux(*this); ///Cuerdas aux(this->_nombre, this->_escala);
    this->_escala -- ;
    this->ajustarEscala();
    return aux;
}

Vientos &Vientos::operator--()
{
    this->_escala -- ;
    this->ajustarEscala();

    return *this;
}

string Vientos::getDetalles()const
{
    return "material" + _material;

}
