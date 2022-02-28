#ifndef PILA_D_H_INCLUDED
#define PILA_D_H_INCLUDED

#include "funciones.h"

typedef t_nodo * t_pila_c;

void crear_pila_c ( t_pila_c *);
int pila_llena_c ( const t_pila_c *);
int poner_en_pila_c ( t_pila_c *, const t_info *);
int sacar_de_pila_c ( t_pila_c *, t_info *);
int ver_el_tope_c ( const t_pila_c *, t_info *);
int pila_vacia_c ( const t_pila_c *);
void vaciar_pila_c ( t_pila_c *);

#endif // PILA_D_H_INCLUDED
