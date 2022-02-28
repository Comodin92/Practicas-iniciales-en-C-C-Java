/**//* 36.902.267-GUTIERREZ, EdgardoDamian-(04-1361) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
#include <string.h>
#include <stdlib.h>

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/

tLista* buscar_menor(tLista* pl, int (*comparar)(const void *, const void *));


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/
/**
void mostrarMovim_MIO(const void *d, FILE *fp)
{

}
 **/
/**
int compararMovim_MIO(const void *d1, const void *d2)
{

}
 **/
/**
int esCtaCte002_MIO(const void *d)
{

}
 **/
/**
int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri)
{

}
 **/
/**
void mostrarTotal_MIO(const void *d, FILE *fp)
{

}
 **/

/**//* para el TDA LISTA                                                  *//**/

int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int cant = 0 ;
    while(*p)
    {
        mostrar((*p)->info, fp);
        p = &(*p)->sig;
        cant++;
    }
    return cant;
}

void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    tLista *inicio=p, *recorre;
    tNodo *minimo,*aux;
    /** inicio, puntero a lista que siempre apuntara al inicio de la lista a ordenar
        recorre, puntero para recorrer lista para encontrar el minimo
        minimo puntero a nodo para almacenar el contenido del dato mas chico
        aux lo utilizo para no perder la referencia del siguiente del nodo minimo
    **/
    if(!*p)
    {
        puts("Error la lista esta vacia\n");
        return;
    }
    while((*inicio)->sig) ///Pregunto por el siguiente para no tener conflicto ocn el ultimo nodo
    {
        minimo = (*inicio);
        recorre = &(minimo)->sig; ///Lo inicio en el siguiente de recorre para no comparar el mismo dato
        while((*recorre)) ///Recorre es el siguiente de minimo
        {/**
                Recorro la lista para encontrar el minimo
        **/
            if(*recorre && comparar(&(minimo)->info, &(*recorre)->info) > 0) /// el siguiente es mas grande
                minimo= *recorre;
            recorre = &(*recorre)->sig;
        }
        (aux) = minimo->sig; /**Este puntero lo utilizo para no perder la referencia del siguiente
        minimo, al enlazar minico a donde corresponda**/
        if((comparar(&(*p)->info, &(minimo)->info) != 0))///Si el primer nodo no es el minimo
        {
            /**
                Me coloco una posicion atras del minimo,
            **/

            while(comparar(&(*p)->sig->info, &(minimo)->info) != 0)
                p = &(*p)->sig;
        }
        /**
        Realizo los enlaces
        **/
        (*p)->sig = (*inicio);
        minimo->sig = (*inicio)->sig;
        (*inicio)->sig = aux;
        (*inicio) =  minimo;
        p = &(*inicio)->sig; ///Reseteo pl desde la parte de la lista que me sirve ordenar
        inicio = &(*inicio)->sig;
    }
}

/**
int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int comparar2(const void *d),
                                      int acumular(void **, unsigned *,
                                                   const void *, unsigned),
                                      void mostrar(const void *, FILE *),
                                      void mostrar2(const void *, FILE *))
{




}
**/

int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int cant=0;
    while(*p)
    {
        tNodo *aux = *p;

        cant++;
        *p = aux->sig;
        if(mostrar && fp)
            mostrar(aux->info, fp);
        free(aux->info);
        free(aux);
    }
    return cant;


}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

