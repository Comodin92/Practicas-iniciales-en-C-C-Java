#include "TDA_lista.h"


void mostrarInt(const void *d1)
{
    printf("%d\n",*(int*)d1);
}

int cmpInt(const void *d1, const void *d2)
{
    return *(int*)d2 - *(int*)d1;

}

void mostrarPed(const void* d1)
{
    tPedidos *pedido = (tPedidos*)d1;
 printf("%d | %s | %d\n", pedido->cod, pedido->descrip, pedido->cantP);
}

int cmpPedido(const void *d1, const void *d2)
{
    tPedidos *p1 = (tPedidos*)d1;
    tPedidos *p2 = (tPedidos*)d2;

    if(p1->cod != p2->cod)
            return p2->cod - p1->cod;
    if(p1->descrip !=  p2->descrip)
        return p2->cod - p1->cod;
    return 0;
}
void sumarPedidos(void* estruc1, const void* estruc2)
{
    ((tPedidos*)estruc1)->cantP+=((tPedidos*)estruc2)->cantP;
}

int compEstruc(const void* dato1,const void* dato2)
{
    tPedidos *pedido=(tPedidos*) dato1;
    tPedidos *pedido2=(tPedidos*) dato2;
    int result;

    if((result=pedido->cod-pedido2->cod)==0)
        return *pedido->descrip-*pedido2->descrip;

    return result;
}
int main()
{
    tPedidos pedidos[]= {   {1,"Lysoform",5},
                            {2,"Alcohol en gel",2},
                            {6,"Lavandina",3},
                            {3,"Alcohol en gel",4},
                            {2,"Alcohol en gel",2},
                            {1,"Lysoform",8},
                            {1,"Lysoform",2},
                            {2,"Alcohol en gel",1},
                            {2,"Alcohol en gel",4},
                            {6,"Lavandina",3},
                            {2,"Alcohol en gel",2},
                            {6,"Lavandina",12},
                            {6,"Lavandina",7},
                            {2,"Alcohol en gel",2},
                            {6,"Lavandina",10},
                             {1,"Lysoform",5},
    };
    int vec[]= {3,6,78,1,0,-12,3,1,1},
               vec_elim[] = {1, 3, 100, 12 },
                            i;
    t_Lista lista;
    crearLista(&lista);
    for(i = 0 ; i < sizeof(pedidos)/sizeof(tPedidos); i++)
        ponerEnOrden(&lista,sizeof(pedidos),&pedidos[i],cmpInt);
    /// ponerAlFinal(&lista,sizeof(int),&vec[i]);
    ///ponerAlInicio(&lista, sizeof(int), &vec[i]);
    printf("Lista cargada\n");
    ///mostrarLista(&lista, mostrarInt);
    mostrarLista(&lista, mostrarPed);
//    for(i = 0 ; i < sizeof(vec_elim)/sizeof(int); i++)
//    {
//        sacarDeLista(&lista,sizeof(int),&vec_elim[i],cmpInt);
//        printf("Asi va quedando la lista\n");
//        mostrarLista(&lista, mostrarInt);
//
//    }
    ///mostrarLista(&lista, mostrarInt);
    ///vaciarLista(&lista);
    ///mostrarLista(&lista, mostrarInt);
    printf("Lista procesada\n");
    ///procesarListaO(&lista, compEstruc, sumarPedidos);
    procesarListaD(&lista, compEstruc, sumarPedidos);
    mostrarLista(&lista, mostrarPed);
    printf("Lista luego de borrar desde el nodo 3\n");
    borrarPorNodo(&lista);
    mostrarLista(&lista,mostrarPed);
    return 0;
}

