#include "TDA_Lista_doble.h"

void crearLista(t_Lista *lista)
{
    *lista = NULL;
}
int listaVacia(const t_Lista *lista)
{
    return *lista==NULL;
}
int listaLlena(const t_Lista *lista,unsigned cantBytes)
{
    return 0;
}
int ponerEnLista(t_Lista *lista,const void* dato, unsigned cantBytes,
                 int(*cmp)(const void*, const void*))
{
    t_Nodo *act = *lista,
            *auxSig,
            *auxAnt,
            *nue;
    int res;

    if(*lista)
    {
        while((res = cmp(dato,act->dato)) > 0 && act->sig)
            act = act->sig;

        while((res = cmp(dato,act->dato)) < 0 && act->ant)
            act = act->ant;

        if(res > 0)
        {
            auxSig = act->sig;
            auxAnt = act;
        }
        else if(res < 0)
        {
            auxSig = act;
            auxAnt = act->ant;
        }
        else
            return DUPLICADOS;
    }
    else
    {
        auxSig = NULL;
        auxAnt = NULL;
    }

    if(!(nue = (t_Nodo*)malloc(sizeof(t_Nodo))) ||
            !(nue->dato = malloc(cantBytes)))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato, dato, cantBytes);
    nue->cantB = cantBytes;

    nue->sig = auxSig;
    nue->ant = auxAnt;

    if(auxSig)
        auxSig->ant = nue;
    if(auxAnt)
        auxAnt->sig = nue;

    *lista = nue;

    return 1;
}
int elimiarXclave(t_Lista *lista, void* dato, unsigned cantBytes,
                  int(*cmp)(const void*, const void*))
{
    t_Nodo *act = *lista,
            *auxSig,
            *auxAnt;
    int res;

    if(!act)
        return 0;

    while((res = cmp(dato,act->dato)) != 0 && act->sig)
        act = act->sig;

    if(res)
    {
        act = *lista;

        while((res = cmp(dato,act->dato)) != 0 && act->ant)
            act = act->ant;
        if(res)
            return 0;
    }
    auxSig = act->sig;
    auxAnt = act->ant;

    if(auxSig)
        auxSig->ant = auxAnt;

    if(auxAnt)
        auxAnt->sig = auxSig;

    *lista = auxSig ? auxSig : auxAnt;

    memcpy(dato,act->dato,MINIMO(cantBytes,act->cantB));
    free(act->dato);
    free(act);

    return 1;
}
int cmpInt(const void* dato1, const void *dato2)
{
    return *(int*)dato1-*(int*)dato2;
}
void *mostrarID(const t_Lista *lista, void*(*accion)(const void*, void*),void *dato)
{
    t_Nodo *act = *lista;
    void *res;

    if(!act)
        return 0;

    while(act->ant)
        act = act->ant;

    while(act)
    {
        res = accion(act->dato,dato);
        act = act->sig;
    }

    return res;
}
void *mostrarDI(const t_Lista *lista, void*(*accion)(const void*, void*),void *dato)
{
    t_Nodo *act = *lista;
    void *res;

    if(!act)
        return 0;

    while(act->sig)
        act = act->sig;

    while(act)
    {
        res = accion(act->dato,&res);
        act = act->ant;
    }

    return res;
}
//void* mostrar(const void* dato1, void* dato2)
//{
//    printf("%d\t",*(int*)dato1);
//    return NULL;
//}
void mostrarInt(const void *dato)
{
    printf("%d\n", *(int*)dato);

}
void *acumInt(const void* dato1, void * dato2)
{
    if(*(int*)dato1 > 49 && *(int*)dato1 < 101)
        *(int*)dato2 += *(int*)dato1;
    return dato2;
}
void mostrarLista(const t_Lista *lista,
                  void (*mostrar)(const void *d1))
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
