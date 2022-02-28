#include "cola.h"


/**DEFINICION FUNCIONES COLA ESTATICA**/
///CREAR COLA
void crear_cola_s ( t_cola_s *p )
{
    p->cant = 0;
    p->pri  = 0;
    p->ult  =-1;
}
///COLA LLENA
int cola_llena_s ( const t_cola_s *p )
{
    return p->cant == TAM_COLA;
}
///COLA VACIA
int cola_vacia_s ( const t_cola_s *p )
{
    return p->cant == 0;
}
///PONER EN COLA
int poner_en_cola_s ( t_cola_s *p, const t_info *d )
{
    if ( p->cant == TAM_COLA)
        return 0;
    p->cant ++;
    p->ult  ++;
    if( p->ult == TAM_COLA)
        p->ult = 0;
    p->cola[p->ult] = *d;
    return 1;
}
///VACIAR COLA
void vaciar_cola_s  ( t_cola_s *p)
{
    p->cant =  0;
    p->pri  =  0;
    p->ult  = -1;
}
///VER PRIMERO DE COLA
int ver_primero_cola_s  ( const t_cola_s *p, t_info *d )
{
    if( p->cant == 0)
        return 0;
    *d = p->cola [p->pri];
    return 1;
}
///SACAR DE COLA
int sacar_de_cola_s ( t_cola_s *p, t_info *d )
{
    if ( p-> cant == 0)
        return 0;
    *d = p->cola [p->pri];
    p->pri ++;
    if(p->pri == TAM_COLA)
        p->pri = 0;
    p->cant--;
    return 1;
}

/**DEFINICION FUNCIONES COLA DINAMICA**/
///CREAR COLA
void crear_cola_d ( t_cola_d *p )
{
    p->pri = NULL;
    p->ult = NULL;
}
///COLA LLENA
int cola_llena_d ( const t_cola_d *p )
{
    t_nodo  *aux = ( t_nodo *) malloc( sizeof(t_nodo));
    free(aux);
    return aux == NULL;
}
///COLA VACIA
int cola_vacia_d ( const t_cola_d *p )
{
    return p->pri == NULL;
}
///PONER EN COLA
int poner_en_cola_d ( t_cola_d *p, const t_info *d )
{
    t_nodo  *aux = (t_nodo *) malloc(sizeof(t_nodo));
    if(aux == NULL)
        return 0;
    aux->info   = *d;
    aux->sig    = NULL;
    if( p->ult )
    {
        p->ult->sig = aux;
        p->ult = aux;
    }
    else
    {
        p->pri  = aux;
        p->ult  = aux;
    }
    return 1;
}
///VACIAR COLA
void vaciar_cola_d  ( t_cola_d *p)
{
    t_nodo  *aux;
    while (p->pri)
    {
        aux     = p->pri;
        p->pri  = aux->sig; //El ultimo aux->sig va a ser el NULL
        free(aux);
    }
    aux->sig = NULL; //Asi quedan ambos como NULL
}
///VER PRIMERO DE COLA
int ver_primero_cola_d  ( const t_cola_d *p, t_info *d )
{
    if (p->pri == NULL)
        return 0;
    *d = p->pri->info;
    return 1;
}
///SACAR DE COLA
int sacar_de_cola_d ( t_cola_d *p, t_info *d )
{
    t_nodo *aux;
    if (p->pri == NULL)
        return 0;
    aux     = p->pri;
    *d      = aux->info;
    if( p->pri == p->ult)
    {
        p->pri = NULL;
        p->ult = NULL;
    }
    else
        p->pri = aux->sig;
    free(aux);
    return 1;
}


/**DEFINICION FUNCIONES COLA CIRCULAR **/
///CREAR COLA
void crear_cola_c ( t_cola_c *p )
{
    p->pri = NULL;
    p->ult = NULL;
}
///COLA LLENA
int cola_llena_c ( const t_cola_c *p )
{
    t_nodo  *aux = ( t_nodo *) malloc( sizeof(t_nodo));
    free(aux);
    return aux == NULL;
}
///COLA VACIA
int cola_vacia_c ( const t_cola_c *p )
{
    return p->pri == NULL;
}
///PONER EN COLA
int poner_en_cola_c ( t_cola_c *p, const t_info *d )
{
    t_nodo  *aux = (t_nodo *) malloc(sizeof(t_nodo));
    if(aux == NULL)
        return 0;
    aux->info   = *d;
    if(!p->pri)
    {
        p->pri=aux;
        aux->sig=aux;
    }
    else
    {
        aux->sig = p->pri;
        p->ult->sig = aux;
    }
    p->ult=aux;
    return 1;
}
///VACIAR COLA
void vaciar_cola_c  ( t_cola_c *p)
{   //Recuerda la direccion del primer nodo.//
    t_nodo *rec=p->pri;
    t_nodo *aux;
    if(rec)
    {
        while(rec!=p->pri->sig)
        {
            aux=p->pri;
            p->pri=aux->sig;
            free(aux);
        }
        p->pri=NULL;
        free(p->ult);
        p->ult=NULL;
    }
}
///VER PRIMERO DE COLA
int ver_primero_cola_c  ( const t_cola_c *p, t_info *d )
{
    if (p->pri == NULL)
        return 0;
    *d = p->pri->info;
    return 1;
}
///SACAR DE COLA
int sacar_de_cola_c ( t_cola_c *p, t_info *d )
{
    t_nodo *aux;
    if(p->pri!=p->pri->sig)
    {
        *d          = p->pri->info;
        aux         = p->pri;
        p->pri      = aux->sig;
        p->ult->sig = p->pri;
        free(aux);
    }
    else
    {
        *d          = p->pri->info;
        free(p->pri);
        p->pri = NULL;
        p->ult = NULL;
    }
    return 1;
}
