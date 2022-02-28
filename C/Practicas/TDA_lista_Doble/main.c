#include "TDA_Lista_doble.h"

int main()
{
    int vec[]= {3,6,78,1,0,-12,3,1,1},
    vec_elim[] = {1, 3, 100, 12 },
                            i;
    t_Lista lista;
    crearLista(&lista);
    for(i = 0 ; i < sizeof(vec)/sizeof(int); i++)
        ponerEnLista(&lista,&vec[i],sizeof(int),cmpInt);
    /// ponerAlFinal(&lista,sizeof(int),&vec[i]);
    ///ponerAlInicio(&lista, sizeof(int), &vec[i]);
    printf("Lista cargada\n");
    ///mostrarLista(&lista, mostrarInt);
    mostrarLista(&lista,mostrarInt);
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
   /// printf("Lista procesada\n");
    ///procesarListaO(&lista, compEstruc, sumarPedidos);
    ///procesarListaD(&lista, compEstruc, sumarPedidos);
    ///mostrarLista(&lista, mostrarPed);

    return 0;
}
