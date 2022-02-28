#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "recursividad.h"

/*** CLASE RENATA TEORIA***/
void teoriaRecursividad();
/*** DESARROLLO DE FUNCIONES***/
void funciones();

double factorialI(int num);
double factorialR(int num);

///////////////////
void cadenaOrden(const char *cad);
void cadenaOrdenInverso(char *cad);
void cadenaNormalInverso(char *cad);
void cadenaNormalInversoIncompleto(char *cad);
void cadenaPalabraDecre(char *cad);
void cadenaPalabraInversoDecre(char *cad);
void cadenaPalabraDecre2(char *cad);
void mostrasPalDecre(char *cad, int tam);

////////////////
void mostrearNumEntero(int n);
void mostrearNumEnteroInv(int num);
void mostrearNumDec(int n);
void mostrearNumCreInv(int num);
void mostrarNumEnteroInverso(int num);
void mostrarNumDecIzqDer( int num);
double contarUnidadesNum(int num);
void numDecIzqDer(int num, double mult);
void mostrarNumDecDerIzq( int num);
void numDecIzqDer(int num, double mult);
void numDecDerIzq(int num, double mult);


/****************************/

void cambioDeBase(int num, int baseDestino);
int esPalindromoRec(char *cad);
int esPalindromo( char* cad, char *fin);
int strlenRecursiva(char *cad);
int calcularMCD(int num1, int num2);
int MCD(int dividendo, int divisor);
int busquedaBinariaIterativa(char *cad, char valor);
int busquedaBinariaRecursiva(char *cad, char valor);
int busqBin(char *inf, char *sup, char *medio, char valor);



#endif // RECURSIVIDAD_H_INCLUDED
