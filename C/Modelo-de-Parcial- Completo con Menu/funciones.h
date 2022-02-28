#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>///FUNCIONES DE ENTRADA SALIDA
#include <stdlib.h>///FUNCIONES DE LIBRERIA DE CADENA DE CARACTERES
#include <ctype.h>///FUNCIONES DE CADENAS
#include "fechas.h"
#define CLA_DUP     0
#define SIN_MEM     1
#define CORRECTO    1
#define NO_EXISTE   0
#define TAM_PILA 100
/*DEFINICION DE INFORMACION*/
///PERSONAS
typedef struct
{
    int cla;
}t_dato;

typedef struct
{
    long    dni;
    char    apyn[36],
            sex;
    t_fecha fec;
    float   importe;
}t_per;
/*DEFINICION PILA PAQUETE DE INFORMACION*/
//typedef t_per    t_info; Para la estructura de DNI
typedef t_dato      t_info; //Para la estructura de arbol numero
/*DEFINICION ESTRUCTURA NODOS DINAMICOS*/
typedef struct s_nodo
{
    t_info  info;
    struct  s_nodo  *sig;
}t_nodo;
typedef void(*t_acu)(t_info *, const t_info * );

void acumular ( t_info *, const t_info * );
/*DEFINICION DE ESTRUCTURA DE COMPARACION*/
///COMPARACION POR PARAMETRO
typedef int(*t_cmp)(const t_info* , const t_info*);
int comparar (const t_info *, const t_info *);

#endif // FUNCIONES_H_INCLUDED
