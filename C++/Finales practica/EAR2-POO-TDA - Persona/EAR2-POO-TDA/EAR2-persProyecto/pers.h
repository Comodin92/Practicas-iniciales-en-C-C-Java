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
    long    dni;         /// D. N. I.
  //char   *apyn;      // Apellido/s y nombre/s
    string  apyn;        /// Apellido/s y nombre/s en su defecto:  char   *apyn;
    char    sexo;        /// sexo de la persona
    int     edad;        /// edad de la persona

    friend operator >>(istream, Pers);  // ingresa por teclado un objeto
    friend operator <<(ostream, Pers);  // muestra por pantalla un objeto
    void ~Pers;
public :
    void Pers(void);    	                                    // defecto
    void Pers(long = 0L, string &= "NN", char = 'X', int = 0);  // parametrizado
    Pers++;                                                  // incrementa edad
/** corrija y complete la class, porque esto es espantoso!!!  **/

#endif

