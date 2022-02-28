#include "lista_d.h"
int insertar_en_orden_doble (t_lista_doble *p, const t_info *d, int(*comparar)(const t_info*, const t_info*), void(*acumular)(t_info *, const t_info*) )
{
    t_nodo_d    *act = *p,
                *nue, //para obtener memoria
                *ant,
                *sig;
    int     cmp;
    if (act == NULL)
    {
        ant = NULL;
        sig = NULL;
    }
    else
    {
        while ( act->sig && comparar( &act->info, d ) < 0)
            act = act->sig;
        while ( act->ant && comparar( &act->info, d ) > 0)
            act = act->ant;

        cmp = comparar( & act->info, d );
        if ( cmp == 0) //si son iguales
        {
            acumular( &act->info, d );
            *p = act;//para devolver
            return CLA_DUP; //salida del igual asi no sigue en laparte de abajo
        }
        if ( cmp < 0 ) //osea me quede viendo el nodo siguiente p<q
        {
            ant = act;
            sig = act->sig;
        }
        else
        {
            ant = act->ant;
            sig = act;
        }
    }
    ///ANOTAR
    nue = ( t_nodo_d* ) malloc( sizeof ( t_nodo_d ) );
    if (nue == NULL)
        return SIN_MEM; // sale porque no puedo asignar memoria
    nue->info = *d;
    nue->ant = ant;
    nue->sig = sig;
    if ( ant)
        ant->sig = nue;
    *p = nue;
    return CORRECTO;
}
    // LOPEZ
    ///para la lista doblemente enlazada la lista se quede viendo al ultimo que se inserto
    ///ir al comienzo de una lista
    /// ir al comienzo de la lista y recuperar el nodo de lista
    /// avanzar uno devuelve falso cuando no hay mas nodos

