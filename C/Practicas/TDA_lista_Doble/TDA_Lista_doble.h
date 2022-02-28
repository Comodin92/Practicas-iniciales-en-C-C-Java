#ifndef TDA_LISTA_DOBLE_H_INCLUDED
#define TDA_LISTA_DOBLE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUPLICADOS 0
#define MINIMO( X , Y )    (( X ) <= ( Y ) ? ( X ) : ( Y ) )

typedef struct sNodo
{
    void* dato;
    unsigned cantB;
    struct sNodo *sig;
    struct sNodo *ant;
} t_Nodo;

typedef t_Nodo* t_Lista;

void crearLista(t_Lista *lista);
void mostrarLista(const t_Lista *pl, void (*mostrar)(const void*d));
int listaVacia(const t_Lista *lista);
int listaLlena(const t_Lista *lista,unsigned cantBytes);
int ponerEnLista(t_Lista *lista,const void* dato, unsigned cantBytes,
                  int(*cmp)(const void*, const void*));
int cmpInt(const void* dato1, const void *dato2);
int elimiarXclave(t_Lista *lista, void* dato, unsigned cantBytes,
                  int(*cmp)(const void*, const void*));
void *mostrarID(const t_Lista *lista, void*(*accion)(const void*, void*), void* dato);
///void *mostrar(const void* dato1, void* dato2);
void mostrarInt(const void *d);
void *acumInt(const void* dato1, void * dato2);
void *mostrarDI(const t_Lista *lista, void*(*accion)(const void*, void*),void *dato);
#endif // TDA_LISTA_DOBLE_H_INCLUDED
