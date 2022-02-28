#include "pila_c.h"

/*DEFINICION FUNCIONES DE PILA CIRCULAR*/
///CREAR PILA CIRCULAR
void crear_pila_c ( t_pila_c *p)
{
    *p = NULL;
}
///PILA LLENA CIRCULAR
int pila_llena_c ( const t_pila_c *p)
{
    t_nodo  *aux = ( t_nodo *) malloc(sizeof(t_nodo));
    free(aux);
    return aux == NULL;
}
///PONER EN PILA CIRCULAR
int poner_en_pila_c ( t_pila_c *p, const t_info *d)
{
    t_nodo  *aux = ( t_nodo *) malloc(sizeof(t_nodo));
    if( aux == NULL )
        return 0;
    aux->info = *d;
    if ( *p == NULL )
    {
        aux->sig = aux;
        *p = aux;
    }
    else
    {
        aux->sig  = (*p)->sig;
        (*p)->sig = aux;
    }
    return 1;
}
///SACAR DE PILA CIRCULAR
int sacar_de_pila_c ( t_pila_c *p, t_info *d)
{
    t_nodo *aux;
    if( *p == NULL )
        return 0;
    aux = (*p)->sig;
    *d  = aux->info;
    if ( aux == aux->sig )
        *p = NULL;
    else
        (*p)->sig  = aux->sig;
    free(aux);
    return 1;
}
///VER EL TOPE DE PILA CIRCULAR
int ver_el_tope_c ( const t_pila_c *p, t_info *d)//
{
    if ( *p == NULL )
        return 0;
    *d  = (*p)->info;
    return 1;
}
///PILA VACIA CIRCULAR
int pila_vacia_c ( const t_pila_c *p)//
{
    return *p == NULL;
}
///VACIAR LA PILA CIRCULAR
void vaciar_pila_c ( t_pila_c *p)
{
       while(*p)
    {
        aux = (*p)->sig;
        (*p)->sig = aux->sig;
        if(*p == aux)
            *p = NULL;
        free(aux);
    }
}

