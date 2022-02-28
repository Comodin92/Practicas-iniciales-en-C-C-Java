/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/

#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED

#include <iostream>
#include <string>

#include "stdio.h"
#include "stdlib.h"

#include <cstdio>


using namespace std;


class Pers
{
    private:
    long    dni;         /// D. N. I.
  //char   *apyn;      // Apellido/s y nombre/s
    string  apyn;        /// Apellido/s y nombre/s en su defecto:  char   *apyn;
    char    sexo;        /// sexo de la persona
    int     edad;        /// edad de la persona


    public :
   /// friend operator >>(istream, Pers);  // ingresa por teclado un objeto

   // void ~Pers;
    Pers(long _dni=11111111, string _apyn="-", char _sexo='?', int edad=0);
    friend ostream &operator<<(ostream &obj, const Pers &person);
    friend istream &operator>>(istream &obs, Pers &persona);  	                                    // defecto
   // void Pers(long = 0L, string &= "NN", char = 'X', int = 0);  // parametrizado
    Pers operator++(int);                                                 // incrementa edad
/** corrija y complete la class, porque esto es espantoso!!!  **/
};
#endif

