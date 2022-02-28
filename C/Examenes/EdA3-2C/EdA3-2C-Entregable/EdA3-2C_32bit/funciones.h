/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER MODIFICACIÓN QUE HAGA NO SERÁ TENIDA EN CUENTA.      *//**/
/**//**//*                                                                *//**/
/**//**//*     ¡No debería hacer ninguna modificación en este archivo!    *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>

#include "que_hice.h"
#include "tda_definiciones.h"

typedef struct
{
    char    clave[8];
    int     calif;
} tEvalua;


/** funciones de servicio **/
int obtenerEvaluacion(tEvalua *nota);

void crearListaDobl(tListaDobl *lista);

int vaciarListaDobl(tListaDobl *lista);

void crearListaSimp(tListaSimp *lista);

int vaciarListaSimp(tListaSimp *lista);

void mostrarNota(const void *d, FILE *fpPantalla);

int mostrarListaD(tListaDobl *lista, void(*mostrar)(const void *, FILE *),
                  FILE *fpPantalla);

int mostrarListaS(tListaSimp *lista, void(*mostrar)(const void *, FILE *),
                  FILE *fpPantalla);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO 1 a.- **/
int ponerEnListaDoblNMejores(tListaDobl *lista, const void *nota,
                             size_t cantBytes, int tope);

int ponerEnListaDoblNMejores_MIO(tListaDobl *lista, const void *nota,
                                 size_t cantBytes, int tope);

/** para el PUNTO 1 b.- **/
int ponerEnListaSimpNMejores(tListaSimp *lista, const void *nota,
                             size_t cantBytes, int tope);

int ponerEnListaSimpNMejores_MIO(tListaSimp *lista, const void *nota,
                                 size_t cantBytes, int tope);
int cmp_alum(const void *d1, const void *d2);
int cmp_nota(const void* d1, const void *d2);
int obtenerMinimo(const void *d);
int cantidadNodosLista(tListaSimp *pa);
int cantidadMinRepetidos(tListaSimp *pa);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/


#endif

