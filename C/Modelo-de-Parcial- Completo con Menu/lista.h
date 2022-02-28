#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "funciones.h"

/*DEFINICION ESTRUCTURA LISTA DINAMICA
typedef struct s_nodo
{
    t_info info;
    struct s_nodo *sig;
} *t_lista;*/
typedef t_nodo * t_lista;

/*DECLARACION DE PRIMITIVAS DE LISTA DINAMICA*/
///ELEMENTALES
void crear_lista ( t_lista * );
int lista_llena ( const t_lista * );
int lista_vacia ( const t_lista * );
void vaciar_lista( t_lista * );
int vaciar_lista_contarygrabar_en_arch( t_lista *, FILE * );
///DE INSERCION
int insertar_al_comienzo( t_lista *, const t_info * );
int insertar_al_final ( t_lista *, const t_info * );
int insertar_en_orden_lista ( t_lista *, const t_info * );
///BUSQUEDA
int buscar_en_lista_ordenada ( t_lista *, t_info *, int );
int buscar_en_lista_no_ordenada ( t_lista *, t_info *, int );
void ordenar_x_burbuja (t_lista * );
///DE ELIMINACION
int eliminar_no_duplicados_lista_ordenada ( t_lista * );
int eliminar_no_duplicados_lista_no_ordenada ( t_lista * );
int eliminar_duplicados_lista_no_ordenada ( t_lista * );
int eliminar_duplicados_lista_ordenada ( t_lista * );

#endif // LISTA_H_INCLUDED
