#include <stdio.h>
#include <stdlib.h>
int insertarElemento(int *vec,const int tam, int *ce, const int num);
void mostrarVec(int *v,int ce);
int insertarEnPosicion(int *vec, int *ce, const int num, const int tam, const int posi);
int eliminarElementoPorPosicion(int *vec, int tam, const int posi, int *datoElim, int *ce );
int insertarElementoOrdenado(int *vec, int tam, const int dato, int *ce);
int borrarOcurrenciasOrdenado(int *vec, const int tam, int *ce);
int borrarOcurrenciasDesordenado(int *vec, const int tam, int *ce);
int borrarAparicion(int *v,const int tam,int *ce,const int elemento);
int contarParesImpares( int *v, const int tam, int* ce, int *ce_par, int *ce_impar);

int main()
{
    int ce=13, tam=20,num,v[]={6,6,2,2,2,4,2,6,6,6,10,10,10},numEl, ce_par=0, ce_impar=0;
    mostrarVec(v,4);

    do
    {
        mostrarVec(v,ce);
        printf("Ingrese dato a borrar - 999 termina\n\n\n");
        scanf("%d",&num);
        if(num != 999)
           {///int contarParesImpares( int *v, const int tam, int* ce, int *ce_par, *ce_impar)
              /// insertarElemento(v,5,&ce,num);
              ///insertarEnPosicion(v,&ce,num,6,2);
               ///eliminarElementoPorPosicion(v,6,1,&numEl,&ce);
               if(!contarParesImpares(v,tam,&ce,&ce_par, &ce_impar));
                    printf("No se pudo insertar\n");
                printf("Pares: %d \n impares: %d \ntotal hay %d elementos",ce_par, ce_impar, ce);
               ///printf("Elemento borrado %d\n",numEl);
            ///   mostrarVec(v,ce);
           }

    }while(num != 999);
    return 0;
}

int insertarElemento(int *vec,const int tam, int *ce, const int num)
{
    int aux_posicion = *ce;
    if(*ce == (tam-1)) ///Vector lleno
       {
           puts("Vector lleno");
          return 0;
       }
  ///  *(vec+(*ce)) = num;
    while(aux_posicion)
    {
         vec++;
        aux_posicion--;
    }
    *vec = num;
    (*ce)++;
    return 1;
}

int insertarEnPosicion(int *vec, int *ce, const int num, const int tam, const int posi)
{
    if(*ce >= (tam-1))
        return 0; ///No puedo insertar en el vector
    int *pfin=(vec+((*ce)-1)), *pPosi= vec + (posi-1);
    while(pfin >= pPosi)
    {
        *(pfin+1) = *pfin ;
        pfin--;
    }
    (*pPosi) = num;
    (*ce)++;
    return 1;
}

int eliminarElementoPorPosicion(int *vec, int tam, const int posi, int *datoElim, int *ce )
{
    if(!(*ce) ) ///Si el vec esta vacio
       {
           puts("Vector vacios, no se puede eliminar");
           return 0;
       }
    int *pfin=(vec+((*ce)-1)), *pElim= vec + (posi-1);
    (*datoElim) = *pElim;
    while(pfin >= pElim)
    {
        *pElim = *(pElim+1);
        pElim++;
    }
    (*ce)--;
    return 1;
}
void mostrarVec(int *v, int ce)
{
    printf("Vector:\n ");
    while(ce)
    {
        printf("%d\n",*v);
        ce--;
        v++;
    }
    ///printf("\n");
}

int insertarElementoOrdenado(int *vec, int tam, const int dato, int *ce)
{
    /**
        NO ACEPTA MAS DATOS SI NO HAY ESPACIO
    **/
    int *pfin = vec + ( (*ce) - 1);
    if(*ce >= (tam-1))
    {
        puts("No es posible insertar, no hay espacio disponible");
        return 0;
    }
    if(*ce) ///Si hay al menos 1 elemento, no acepta datos repetidos
    {
        while(*vec < dato && vec<=pfin) ///Posiciono vec en lugar para insertar
            vec++;
        if(*vec == dato)
        {
            puts("No se aceptan datos repetidos");
            return 0;
        }
        while(pfin >= vec) ///Genero el espacio
        {
            *(pfin+1) = *pfin;
           pfin--;
        }
    }
    *vec = dato;
    (*ce)++;
    return 1;
}

//int borrarOcurrenciasOrdenado(int *vec, const int tam, int *ce)
//{
//    int *pfin= vec + ((*ce)-1), *pRecorre=vec+1;
//    if(!*vec)
//    {
//        puts("Vector vacio");
//        return 0;
//    }
//    while(pRecorre <= pfin)
//    {
//        if(*vec == *pRecorre)
//            {
//                *pRecorre = *(pRecorre+1);
//                (*ce)--;
//            }
//            pRecorre++;
//    }
//    return 1;
//}
int borrarOcurrenciasOrdenado(int *vec, const int tam, int *ce)
{
   int *pfin= vec + ((*ce)-1), *pRecorre=vec+1;
   if(!*vec)
   {
     puts("Vector vacio");
     return 0;
   }
   while(pRecorre <= pfin ) ///Mientras tenga datos
  {
     if( *vec == *pRecorre ) ///Si es igual incremento puntero recorre
        (*ce)--;
    else
   {
         vec++;
        *vec = *pRecorre;
    }
   pRecorre++;
  }
  return 1;

}

//int borrarOcurrenciasDesordenado(int *vec, const int tam, int *ce)
//{
//    int *pfin= vec + ((*ce)-1), *pRecorre=vec+1, *pUbicacion;
//    if(!*vec)
//    {
//        puts("Vector vacio, dami sos tonto?");
//        return 0;
//    }
//    while(pRecorre <= pfin ) ///Mientras tenga datos
//    {
//        if( *vec != *pRecorre  ) ///Si es igual incremento lectura
//            pRecorre++;
//        else
//        {
//            pUbicacion = pRecorre;
//            while(pRecorre < pfin)
//                *pRecorre = *(pRecorre+1);
//            pfin--;
//            (*ce)--;
//            pRecorre = pUbicacion;
//        }
//    }
//    printf("Cantidad elemento: %d\n",*ce);
//    return 1;
//}

int borrarAparicion(int *v,const int tam,int *ce,const int elemento)
{
    int *pfin = v + ((*ce)-1), *pRecorre = v;
    if(!*v)
        return 0;
    while( pRecorre <= pfin )
    {
        if( *pRecorre == elemento)
        {
            (*ce)--;
            while( pRecorre < pfin)
            {
                *pRecorre  = *(pRecorre+1);
                pRecorre++;
            }
            return 1;
        }
        pRecorre++;
    }
    return 0;
}

int contarParesImpares( int *v, const int tam, int* ce, int *ce_par, int *ce_impar)
{
    int *pFin= v + (*(ce)-1) ;
    *ce_par = *ce_impar = 0;
    if(!*ce || *ce > tam)
        return 0;
    while(v <= pFin)
    {
        if( * v % 2 == 0)
            (*ce_par)++;
        else
            (*ce_impar)++;
        v++;
    }
    return 1;




}
