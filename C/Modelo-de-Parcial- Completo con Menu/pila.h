#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "funciones.h"
/**DEFINICION ESTRUCTURA PILA ESTATICA**/
typedef struct
{
    t_info  pila [TAM_PILA];
    int     tope;
}t_pila_s;

/**DEFINICION ESTRUCTURA PILA DINAMICA**/
typedef t_nodo * t_pila_d;

/**DEFINICION ESTRUCTURA PILA CIRCULAR **/
typedef t_nodo * t_pila_c;

/**DECLARACION DE PRIMITIVAS DE PILA ESTATICA**/
void crear_pila_s ( t_pila_s *);
int pila_llena_s ( const t_pila_s *);
int poner_en_pila_s ( t_pila_s *, const t_info *);
int sacar_de_pila_s ( t_pila_s *, t_info *);
int ver_el_tope_s ( const t_pila_s *, t_info *);
int pila_vacia_s ( const t_pila_s *);
void vaciar_pila_s ( t_pila_s *);

/*DECLARACION DE PRIMITIVAS DE PILA DINAMICA*/
void crear_pila_d ( t_pila_d *);
int pila_llena_d ( const t_pila_d *);
int poner_en_pila_d ( t_pila_d *, const t_info *);
int sacar_de_pila_d ( t_pila_d *, t_info *);
int ver_el_tope_d ( const t_pila_d*, t_info *);
int pila_vacia_d ( const t_pila_d *);
void vaciar_pila_d ( t_pila_d *);


void crear_pila_c ( t_pila_c *);
int pila_llena_c ( const t_pila_c *);
int poner_en_pila_c ( t_pila_c *, const t_info *);
int sacar_de_pila_c ( t_pila_c *, t_info *);
int ver_el_tope_c ( const t_pila_c *, t_info *);
int pila_vacia_c ( const t_pila_c *);
void vaciar_pila_c ( t_pila_c *);


#endif // PILA_H_INCLUDED
