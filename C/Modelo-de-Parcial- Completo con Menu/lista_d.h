#ifndef LISTA_D_H_INCLUDED
#define LISTA_D_H_INCLUDED
#include "funciones.h"

typedef struct s_nodo_d
{
    t_info  info;
    struct s_nodo_d *ant,
                    *sig;
}t_nodo_d;
typedef t_nodo_d    *t_lista_doble;

int insertar_en_orden_doble (t_lista_doble *, const t_info *, int(*comparar)(const t_info*, const t_info*), void(*acumular)(t_info *, const t_info*) );


#endif // LISTA_D_H_INCLUDED
