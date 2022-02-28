#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "funciones.h"

/*DEFINICION ESTRUCTURA ARBOL DINAMICA*/
typedef struct s_nodo_a
{
    t_info info;
    struct s_nodo_a *izq,
                    *der;
}t_nodo_a;

typedef t_nodo_a    *t_arbol; //porque termina siendo un puntero a puntero de t_nodo_a

/*DECLARACION DE PRIMITIVAS DE LISTA DINAMICA*/

void mostrar_nodo_arbol( t_info *d);//
int abrirArchivo(FILE **, const char *, const char *, int );    //NO SON DE LOPEZ
void leerTxtEnArbol(FILE*,t_info*,t_arbol*,t_cmp);              //NO SON DE LOPEZ
///BUSQUEDA Y MUESTRA
void en_orden ( const t_arbol *);//
void pre_orden ( const t_arbol *);//
void pos_orden ( const t_arbol *);//
int buscarR(t_arbol*,t_info*,t_cmp);   //NO SON DE LOPEZ
int buscar_en_arbol (t_arbol*, t_info*);
///ELEMENTALES
void crear_arbol ( t_arbol *);//
int arbol_lleno ( const t_arbol*);
int poner_en_arbol ( t_arbol *, const t_info *);//
void eliminar_arbol (t_arbol *);//
int eliminar_arbol_y_contar (t_arbol *);
int eliminar_arbol_y_contar_y_almacenar (t_arbol *, FILE *);
int eliminar_arbol_hasta_altura (t_arbol*, int);
int eliminar_hojas(t_arbol *);
///PARA DETERMINAR PROPIEDADES DE ARBOLES
int altura_arbol ( const t_arbol *);//
int contar_nodos_arbol ( const t_arbol *);            //NO SON DE LOPEZ
int contar_nodos_hasta_altura ( const t_arbol *, int);// //NO SON DE LOPEZ
int es_balanceado (const t_arbol *);//
int es_completo (const t_arbol *);//
int determinar_si_es_completo ( const t_arbol *, int);//
int determinar_si_es_balanceado (const t_arbol *, int);//
int determinar_si_es_AVL (const t_arbol *);
int contar_hoja (const t_arbol *);
int contar_y_mostrar_hojas(const t_arbol *); // NO SON DE LOPEZ
int contar_nodos_internos(const t_arbol *); // NO SON DE LOPEZ
int contar_nodos_Internos_con_HD(const t_arbol *); // NO SON DE LOPEZ
int contar_nodos_Internos_con_HI(const t_arbol *); // NO SON DE LOPEZ
int contar_nodos_rama_I(const t_arbol *); // NO SON DE LOPEZ
int contar_nodos_rama_D(const t_arbol *); // NO SON DE LOPEZ
int contar_todos_nodos_con_HI(const t_arbol *); // NO SON DE LOPEZ
int contar_todos_nodos_con_HD(const t_arbol *); // NO SON DE LOPEZ
int contar_nodos_hasta_Hmenos1(const t_arbol *, int); // NO SON DE LOPEZ
int contar_nodos_desdeH(const t_arbol *, int); // NO SON DE LOPEZ
int mostrar_nodo_y_contar_de_H(t_arbol *, int); // NO SON DE LOPEZ
int contar_nodos_de_H(const t_arbol *p, int h);
int contar_nodos_rama_I(const t_arbol *); // NO SON DE LOPEZ
int contar_nodos_rama_D(const t_arbol *); // NO SON DE LOPEZ
void mostrar_losdeH(t_arbol *, int);       //NO SON DE LOPEZ
void mostrar_hastaH(t_arbol *, int ); // NO SON DE LOPEZ
void mostrar_desdeH(t_arbol *, int); // NO SON DE LOPEZ

///ARCHIVOS Y ARBOLES
void cargar_arbol_archivo_bin (t_arbol *, FILE *);
int insertar_en_arbol_recursivo (t_arbol *, t_info *);

#endif  //  ARBOL_H_INCLUDED
