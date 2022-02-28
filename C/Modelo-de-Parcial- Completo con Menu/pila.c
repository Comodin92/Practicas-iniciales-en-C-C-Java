#include "pila.h"
/**DEFINICION FUNCIONES DE PILA ESTATICA**/
///PILA ESTATICA
void crear_pila_s ( t_pila_s *p)
{
    p->tope = 0;
}
///PILA LLENA
int pila_llena_s ( const t_pila_s *p)
{
    return p->tope == TAM_PILA;
}
///PONER EN PILA
int poner_en_pila_s ( t_pila_s *p, const t_info *d)
{
    if(p->tope == TAM_PILA)
        return 0;
    p->pila [p->tope] = *d;
    p->tope++;
    return 1;
}
///SACAR DE PILA
int sacar_de_pila_s ( t_pila_s *p, t_info *d)
{
    if(p->tope == 0)
        return 0;
    p->tope --;
    *d = p->pila [p->tope];
    return 1;
}
///VER EL TOPE DE PILA
int ver_el_tope_s ( const t_pila_s *p, t_info *d)
{
    if( p->tope == 0 )
        return 0;
    *d = p->pila[p->tope-1];
    return 1;
}
///PILA VACIA
int pila_vacia_s ( const t_pila_s *p)
{
    return p->tope == 0;
}
///VACIAR LA PILA
void vaciar_pila_s ( t_pila_s *p)
{
    p->tope = 0;
}
/**DEFINICION FUNCIONES DE PILA DINAMICA**/
///CREAR PILA
void crear_pila_d ( t_pila_d *p)
{
    *p = NULL;
}
///PILA LLENA
int pila_llena_d ( const t_pila_d *p)
{
    t_nodo  *aux = ( t_nodo *) malloc(sizeof(t_nodo));
    free(aux);
    return aux == NULL;
}
///PONER EN PILA
int poner_en_pila_d ( t_pila_d *p, const t_info *d)
{
    t_nodo  *aux = ( t_nodo *) malloc(sizeof(t_nodo));
    if( aux == NULL )
        return 0;
    aux->info = *d;
    aux->sig = *p;
    *p = aux;
    return 1;
}
///SACAR DE PILA
int sacar_de_pila_d ( t_pila_d *p, t_info *d)
{
    if( *p == NULL )
        return 0;
    t_nodo *aux;
    aux = *p;
    *d  = aux->info;
    *p  = aux->sig;
    free(aux);
    return 1;
}
///VER EL TOPE DE PILA
int ver_el_tope_d ( const t_pila_d *p, t_info *d)
{
    if ( *p == NULL )
        return 0;
    *d  = (*p)->info;
    return 1;
}
///PILA VACIA
int pila_vacia_d ( const t_pila_d *p)
{
    return *p == NULL;
}
///VACIAR LA PILA
void vaciar_pila_d ( t_pila_d *p)
{
    t_nodo  *aux;
    while ( *p )
    {
        aux = *p;
        *p  = aux->sig;
        free(aux);
    }
}

/**DEFINICION FUNCIONES DE PILA CIRCULAR**/
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
    t_nodo *aux;
       while(*p)
    {
        aux = (*p)->sig;
        (*p)->sig = aux->sig;
        if(*p == aux)
            *p = NULL;
        free(aux);
    }
}
