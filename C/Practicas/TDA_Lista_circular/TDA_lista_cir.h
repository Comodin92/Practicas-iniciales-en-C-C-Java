#ifndef TDA_LISTA_CIR_H_INCLUDED
#define TDA_LISTA_CIR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo
{
    void *dato;
    struct sNOdo *sig;
    unsigned CantByte;
}tNodo;

typedef tNodo *tLista;

void crearLista(tLista *pl);

#endif // TDA_LISTA_CIR_H_INCLUDED
