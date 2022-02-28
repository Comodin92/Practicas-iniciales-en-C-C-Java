#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#define TAM_COLA 100
#include "funciones.h"
/**DEFINICION ESTRUCTURA COLA ESTATICA**/
typedef struct
{
    t_info cola [TAM_COLA];
    int     pri,
            ult,
            cant;
}t_cola_s;
/**DEFINICION ESTRUCTURA COLA DINAMICA**/
typedef struct
{
    t_nodo  *pri,
            *ult;
}t_cola_d;

/**DEFINICION ESTRUCTURA COLA CIRCULAR**/
typedef t_cola_d  t_cola_c;
/**
typedef struct
{
    t_nodo *pri;
    t_nodo *ult;
}t_cola_c;
**/

/**DECLARACION DE PRIMITIVAS DE COLA ESTATICA**/
void crear_cola_s ( t_cola_s * );
int cola_llena_s ( const t_cola_s * );
int cola_vacia_s ( const t_cola_s * );
int poner_en_cola_s ( t_cola_s *, const t_info * );
void vaciar_cola_s  ( t_cola_s *);
int ver_primero_cola_s ( const t_cola_s *, t_info * );
int sacar_de_cola_s ( t_cola_s *, t_info * );
/**DECLARACION DE PRIMITIVAS DE COLA DINAMICA**/
void crear_cola_d ( t_cola_d * );
int cola_llena_d ( const t_cola_d * );
int cola_vacia_d ( const t_cola_d * );
int poner_en_cola_d ( t_cola_d *, const t_info * );
void vaciar_cola_d  ( t_cola_d *);
int ver_primero_cola_d ( const t_cola_d *, t_info * );
int sacar_de_cola_d ( t_cola_d *, t_info * );
/**DECLARACION DE PRIMITIVAS DE COLA CIRCULAR**/
void crear_cola_c ( t_cola_c * );
int cola_llena_c ( const t_cola_c * );
int cola_vacia_c ( const t_cola_c * );
int poner_en_cola_c ( t_cola_c *, const t_info * );
void vaciar_cola_c  ( t_cola_c *); //No recupera la info//
int ver_primero_cola_c ( const t_cola_c *, t_info * ); //Recupera l info del primer nodo//
int sacar_de_cola_c ( t_cola_c *, t_info * ); //Recupera la info del primer nodo y luego elimina a ese primer nodo//


#endif // COLA_H_INCLUDED
