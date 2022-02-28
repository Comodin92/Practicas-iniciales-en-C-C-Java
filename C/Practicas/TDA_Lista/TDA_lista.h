#ifndef TDA_LISTA_H_INCLUDED
#define TDA_LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X, Y) ( (X ) <= (Y) ? (X) : (Y))
typedef struct
{
    int cod;
    char descrip[100];
    unsigned cantP;
}tPedidos;


typedef struct s_nodo
{
    unsigned cantBy;
    void* dato;
    struct s_nodo *sig;
}t_Nodo;

typedef t_Nodo *t_Lista;


void crearLista(t_Lista *pl);
int listaVacia(const t_Lista *pl);
int listaLlena(const t_Lista *pl, unsigned cantByte);
int ponerAlFinal(t_Lista *pl, unsigned cantByte, const void* dato);
void vaciarLista(t_Lista *pl);
int ponerAlInicio(t_Lista *pl, unsigned cantByte, const void* dato);

int ponerEnOrden(t_Lista *pl, unsigned cantByte, const void* dato,
                 int(*cmp)(const void *d1, const void *d2));

void mostrarLista(const t_Lista *lista, void (*mostrarInt)(const void *d1));
int sacarDeLista(t_Lista *pl, unsigned cantByte, void* dato,
                 int (*cmp)(const void *d1, const void *d2));
void procesarListaO(t_Lista *lista,
                   int (*cmp)(const void*,const void*),
                   void (*accion)(void*,const void*));
void procesarListaD(t_Lista *lista,
                   int (*cmp)(const void*,const void*),
                   void (*accion)(void*,const void*));

int borrarPorNodo(t_Lista *pl);
int nMejoresLista(t_Lista *pl, unsigned cantBytes, const void*,int n,
                  int(*cmp)(const void *d1, const void *d2));
#endif // TDA_LISTA_H_INCLUDED
