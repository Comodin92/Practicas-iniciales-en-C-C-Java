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



/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO 1 c.- **/
int ponerEnListaDoblNCalif(tListaDobl *lista, const void *nota,
                           size_t cantBytes, int tope);

int ponerEnListaDoblNCalif_MIO(tListaDobl *lista, const void *nota,
                               size_t cantBytes, int tope);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/


#endif

