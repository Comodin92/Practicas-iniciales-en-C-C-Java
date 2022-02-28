#include "TDA_lista.h"

void crearLista(t_Lista *pl)
{
    *pl = NULL;
}

int listaVacia(const t_Lista *pl)
{
    return *pl == NULL;
}

int listaLlena(const t_Lista *pl, unsigned cantByte)
{
    t_Nodo *aux;
    aux = (t_Nodo*)malloc(sizeof(t_Nodo));
    aux->dato = malloc(cantByte);
    free(aux->dato);
    free(aux);
    return !aux || !aux->dato;

}

int ponerAlFinal(t_Lista *pl, unsigned cantByte, const void* dato)
{
    t_Nodo *nue;
    while(*pl)
        pl = &(*pl)->sig;
    nue = (t_Nodo*)malloc(sizeof(t_Nodo));
    if(!nue)
        return 0;
    nue->dato = malloc(cantByte);
    if(!nue->dato)
        return 0;
    memcpy(nue->dato,dato,cantByte);
    nue->cantBy = cantByte;
    nue->sig = NULL;
    *pl = nue;
    return 1;
}

int ponerEnOrden(t_Lista *pl, unsigned cantByte,
                 const void *dato,int(*cmp)(const void *d1, const void *d2))
{
    t_Nodo *nue;
    int cmp_fc=1;
    while(*pl && (cmp_fc = cmp(dato, (*pl)->dato) ) < 0)
        pl = &(*pl)->sig;
    nue = (t_Nodo*)malloc(sizeof(t_Nodo));
    if(!nue)
        return 2;
    nue->dato = malloc(cantByte);
    if(!nue->dato)
        return 2;
    memcpy(nue->dato, dato, cantByte);
    nue->cantBy = cantByte;
    nue->sig = (*pl);
    (*pl) = nue;
    return 1;

}

int ponerAlInicio(t_Lista *pl, unsigned cantByte, const void* dato)
{
    t_Nodo *nue;
    nue = (t_Nodo*)malloc(sizeof(t_Nodo));
    if(!nue)
        return 0;
    nue->dato = malloc(cantByte);
    if(!nue->dato)
        return 0;
    memcpy(nue->dato, dato, sizeof(unsigned));
    nue->cantBy = cantByte;
    nue->sig = (*pl);
    (*pl) = nue;
    return 1;
}
void vaciarLista(t_Lista *pl)
{
    t_Nodo *elim= (*pl);
    while(*pl)
    {
        (*pl) = elim->sig;
        free(elim->dato);
        free(elim);
        elim = (*pl);
    }

}
void mostrarLista(const t_Lista *lista,
                  void (*mostrarInt)(const void *d1))
{
    if(!*lista)
    {
        printf("La lista está vacía\n");
        return;
    }
    while(*lista)
    {
        mostrarInt((*lista)->dato);
        lista = & (*lista)->sig;
    }
}
int borrarPorNodo(t_Lista *pl)
{
    int nodo = 1;
    t_Nodo *elim;
    while(*pl && nodo--)
        pl= &(*pl)->sig;

    elim = (*pl);
    (*pl) = NULL;
    free(elim->dato);
    free(elim);
    return 1;
}
int sacarDeLista(t_Lista *pl, unsigned cantByte, void* dato,
                 int (*cmp)(const void *d1, const void *d2))
{
    t_Nodo *elim;
    while(*pl && (cmp(dato, (*pl)->dato)  !=  0 ))
        pl = &(*pl)->sig;
    if(!*pl || cmp(dato, (*pl)->dato)  !=  0 )
        return 0;
    elim = (*pl);
    memcpy(dato, elim->dato, MINIMO(cantByte,elim->cantBy));
    (*pl) = elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}

void procesarListaO(t_Lista *lista,
                    int (*cmp)(const void*,const void*),
                    void (*accion)(void*,const void*))
{
    t_Nodo *elim;

    while(*lista)
    {

        while((*lista)->sig && !cmp((*lista)->dato,(*lista)->sig->dato))
        {
            elim=(*lista)->sig;
            accion((*lista)->dato,elim->dato);
            (*lista)->sig=elim->sig;
            free(elim->dato);
            free(elim);
        }
        lista=&(*lista)->sig;
    }
}

void procesarListaD(t_Lista *pl,
                    int (*cmp)(const void*,const void*),
                    void (*accion)(void*,const void*))
{
    t_Nodo *elim;
    t_Lista *recorre;
    while(*pl)
    {
        recorre = &(*pl)->sig;
        while((*recorre))
        {
            if( (*recorre) && !cmp((*pl)->dato, (*recorre)->dato) )
            {
                elim = (*recorre);
                accion((*pl)->dato, elim->dato);
                (*recorre) = elim->sig;
                free(elim->dato);
                free(elim);
            }
            else
                recorre = &(*recorre)->sig;
        }
        pl = &(*pl)->sig;
    }
}

int nMejoresLista(t_Lista *pl, unsigned cantBytes, const void*,int n,
                  int(*cmp)(const void *d1, const void *d2))
{
    t_Lista *dondeInserto, *ultimoRepetido;
    t_Nodo *elim;
    int cantNodos=0,
        cmp_fc;
    while(*pl && (cmp_fc = cmp(dato, (*pl)->dato) ) < 0)
        {
            cantNodos++;
            pl = &(*pl)->sig;
        }
    while(*pl && (*pl)->sig)
    {
        cantNodos++;
        if((cmp( (*pl)->dato, (*pl)->sig->dato) ) < 0)


    }

    nue = (t_Nodo*)malloc(sizeof(t_Nodo));
    if(!nue)
        return 2;
    nue->dato = malloc(cantByte);
    if(!nue->dato)
        return 2;
    memcpy(nue->dato, dato, cantByte);
    nue->cantBy = cantByte;
    nue->sig = (*pl);
    (*pl) = nue;



    return 1;
}
