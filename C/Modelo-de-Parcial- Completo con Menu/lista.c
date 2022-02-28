#define ELIMINAR_O_NO   0
#define ELIMINAR_NODO   1
#include "lista.h"
/*FUNCIONES DE LISTA*/
///CREAR LISTA
void crear_lista ( t_lista *p )
{
    *p = NULL;
}
///VER SI LISTA ESTA LLENA
int lista_llena ( const t_lista *p )
{
    t_nodo *aux = ( t_nodo *) malloc( sizeof ( t_nodo ) );
    free(aux);
    return aux == NULL;
}
///VER SI LISTA ESTA VACIA
int lista_vacia ( const t_lista *p )
{
    return *p == NULL;
}
///VACIAR LISTA
void vaciar_lista( t_lista *p )
{
    t_nodo *aux;
    while (*p)
    {
        aux = *p;
        *p = aux->sig;
        free(aux);
    }
}
///VACIAR LISTA Y CONTAR Y GRABAR ARCHIVO CON CAMBIOS
int vaciar_lista_contarygrabar_en_arch( t_lista *p, FILE *fp)
{
    t_nodo * aux;
    int     cant=0;
    while ( *p )
    {
        aux = *p;
        *p = aux->sig;
        fwrite( &aux->info, sizeof(t_info), 1, fp);
        free(aux);
    }
    return cant;
}
///INSERTAR AL COMIENZO DE LISTA
int insertar_al_comienzo( t_lista *p, const t_info *d)
{
    t_nodo *nue = (t_nodo* ) malloc (sizeof (t_nodo) );
    if ( nue == NULL )
        return 0;
    nue->info = *d; //Le envio lo que apunta d, no el puntero
    nue->sig = *p;
    *p = nue;
    return 1;
}
///INSERTAR AL FINAL DE LISTA
int insertar_al_final ( t_lista *p, const t_info *d)
{
    t_nodo *nue = ( t_nodo *) malloc( sizeof(t_nodo) );
    if ( nue == NULL )
        return 0;
    while ( *p )
        p = &(*p)->sig;
    nue->info = *d;
    nue->sig = NULL;
    *p = nue;
    return 1;
}
///INSERTAR EN ORDEN EN LISTA
int insertar_en_orden_lista ( t_lista *p, const t_info *d)
{
    t_nodo *nue;
    while ( *p && comparar ( &(*p)->info, d ) < 0 )
        p = &(*p)->sig; //La direccion de sig se la doy a p
    if ( *p && comparar ( &(*p)->info, d ) == 0 )
    {
        acumular ( &(*p)->info, d );
        return 2;
    }
    nue = ( t_nodo * ) malloc ( sizeof ( t_nodo ) );
    nue->sig = *p;
    nue->info = *d;
    *p = nue;
    return 1;
}
///BUSCAR EN LISTA ORDENADA
int buscar_en_lista_ordenada ( t_lista *p, t_info *d, int a )
{
    t_nodo *aux;
    while ( *p && comparar ( &(*p)->info, d) < 0 )
        p = &(*p)->sig;
    if ( *p && comparar ( &(*p)->info, d )== 0)
    {
        aux = *p;
        *d = aux->info;
        if ( ELIMINAR_O_NO == ELIMINAR_NODO)
        {
            *p = aux->sig;
            free(aux);
        }
        return 1;
    }
    return 0;
}
///BUSCAR EN LISTA NO ORDENADA
int buscar_en_lista_no_ordenada ( t_lista *p, t_info *d, int a)
{
    t_nodo *aux;
    while ( *p && comparar( &(*p)->info, d ) != 0 )
        p = &(*p)->sig;

    if(*p)
    {
        aux = *p;
        *d = aux->info;
        if( ELIMINAR_O_NO == ELIMINAR_NODO )
        {
            *p = aux->sig;
            free(aux);
        }
        return 1;
    }
    return 0;
}
///ORDENAR X BURBUJA LISTA (OJO CON EL INTERCAMBIO)
void ordenar_x_burbuja (t_lista *p)
{
    int marca = 1;
    t_lista *q;
    t_nodo *aux;
    if ( *p ) //Hay primer Nodo?
    {
        while ( marca )
        {
            marca = 0;
            q = p; //Ojo como se asigna esto
            while ( (*q)->sig )
            {
                if ( comparar ( &(*p)->info, &(*q)->info ) > 0) //P Dato Info Q Dato Info Sig
                {
                    marca = 1;              //aux =*q;
                    aux = *q;               //aux2= aux->sig;
                    *q = aux->sig;          //aux3= aux2->sig;
                    aux->sig = (*q)->sig;   //*q = aux2;
                    (*q)->sig = aux;        //aux->sig = aux3;
                }                           //aux2->sig = aux;
            q = &(*q)->sig;
            }
        }
    }
}
///ELIMINAR NO DUPLICADOS EN LISTA ORDENADA
int eliminar_no_duplicados_lista_ordenada ( t_lista *p)
{
    int cant = 0;
    t_nodo *aux;
    while ( *p && (*p)->sig )
    {
        if (comparar(&(*p)->info, &(*p)->sig->info) < 0)
        {
            aux = *p;
            *p = aux->sig;
            free(aux);
            cant ++;
        }
        else
        {
            aux = *p;
            while (aux->sig && comparar (&aux->info, &aux->sig->info) == 0 )
                aux = aux->sig;
            p = &aux->sig;
        }
    }
    if( *p )
    {
        free(*p);
        *p = NULL;
        cant++;
    }
    return cant;
}
///ELIMINAR NO DUPLICADOS EN LISTA NO ORDENADA
int eliminar_no_duplicados_lista_no_ordenada ( t_lista *p)
{
    int cant = 0,
        duplicado;
    t_nodo  *aux,
            *ppio = *p;
    while ( *p )
    {
        aux = ppio;
        duplicado = 0;
        while ( aux && duplicado < 2)
        {
            if ( comparar (&aux->info, &(*p)->info) == 0 )
                duplicado++;
            aux = aux->sig;
        }
        if ( duplicado == 1)
        {
            aux = *p;
            *p = aux->sig;
            free(aux);
            cant++;
        }
        else
            p =&(*p)->sig;
    }
    return cant;
}
///ELIMINAR DUPLICADOS EN LISTA NO ORDENADA
int eliminar_duplicados_lista_no_ordenada ( t_lista *p)
{
    t_nodo *aux;
    t_lista *q;
    int cant=0;
    while( *p )
    {
        q = &(*p)->sig;
        while( *q )
        {
                if( *q && comparar( &(*p)->info, &(*q)->info ) == 0 )
                {
                    aux = *q;
                    *q = aux->sig;
                    cant++;
                    acumular( &(*p)->info, &aux->info );
                    free(aux);
                }
                else
                {
                    q = &(*q)->sig;
                }
        }
        p = &(*p)->sig;
    }
    return cant;
}
///ELIMINAR DUPLICADOS EN LISTA ORDENADA
int eliminar_duplicados_lista_ordenada ( t_lista *p)
{
    t_nodo *aux;
    t_lista *q;
    int cant=0;
    q = &(*p)->sig;
    while( *p )
    {
        q = &(*p)->sig;
        while( *q && comparar( &(*p)->info, &(*q)->info) == 0)
        {
            aux = *q;
            *q = aux->sig;
            cant++;
            acumular( &(*p)->info, &aux->info );
            free(aux);
        }
        p = &(*p)->sig;
    }
    return cant;
}
