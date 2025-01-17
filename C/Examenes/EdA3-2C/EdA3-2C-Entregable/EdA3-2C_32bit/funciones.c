/**//*             en los siguientes macroreemplazos indique:             *//**/
/**//*    su(s)         APELLIDO(S)     completo(s)                       *//**/
/**//*    su(s)         Nombre(S)       completo(s)                       *//**/
/**//*    su legajo     N�MERO DE DNI   con los puntos de mill�n y de mil *//**/
/**//*    COMISI�N                                                        *//**/
/**//*              reemplazando los que est�n como ejemplo               *//**/
#define APELLIDO    "Gutierrez"
#define NOMBRE      "Damian, Edgardo"
#define DOCUMENTO   "36.902.267"
#define COMISION    " 02(3362)"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** aqu� insertaremos nuestras observaciones y / o correcciones              **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO DESDE AC� *//**/

int compararClave(const void * , const void *);
int compararNota(const void * , const void *);

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO HASTA AC� *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <stdlib.h>
#include <string.h>

/** para el PUNTO 1 a.- **/

int ponerEnListaDoblNMejores_MIO(tListaDobl * lista, const void *nota,
                                 size_t cantBytes, int tope)
{
    /// printf("PEPE109\n");
    tNodoDobl * actual = *lista,
                *izquierdo,
                *derecho = NULL,
                 *ultimo = NULL,
                  *anteultimo,
                  *pBorrado;
    int cant=1, cmp, eliminados = 0, cambiosVal=0, marcaCoincide=0;
    if(!actual)
    {
        izquierdo=derecho=NULL;
    }
    else
    {
        while(actual->izq)
            actual= actual->izq;
        while(actual->der && (!derecho || cant < tope))
        {
            if(compararNota(actual->info, actual->der->info ) != 0)
                pBorrado = actual;
            if(!derecho && compararClave(nota,actual->info)>=0)
            {
                if(compararClave(nota,actual->info)>0)
                {
                    derecho = actual;
                    izquierdo = actual->izq;
                }
                else
                {
                    izquierdo = actual;
                    derecho = actual->der;
                }
            }
            actual = actual->der;
            cant++;
            if( cant == tope)
            {
                ultimo = actual;
                if(compararNota(actual->info,nota) > 0)
                {
                    return NO_SE_INSERTA;

                }
            }
        }
        if(ultimo == NULL)
            ultimo = actual;

        anteultimo = ultimo->izq;
        cmp=compararNota(nota, ultimo->info);
        if(cmp < 0 && cant >= tope )
        {
            printf("Borrando: %s \n", ((tEvalua*)pBorrado->info)->clave);
            return NO_SE_INSERTA;
        }

        if(cant >= tope && cmp>0  && marcaCoincide==0 && pBorrado)
        {
            printf("Se rompe aca\n");
            ultimo = pBorrado->der;
            anteultimo = pBorrado;
            anteultimo->der = NULL;
            while(ultimo)
            {
                printf("Borrando-> : %s\n", ((tEvalua*)ultimo->info)->clave);
                tNodoDobl * auxiliar = ultimo->der;
                free(ultimo->info);
                free(ultimo);
                ultimo = auxiliar;
                eliminados++;
            }
        }
        if(!derecho)
        {
            if(compararClave(nota,actual->info)>0)
            {
                derecho = actual;
                izquierdo = actual->izq;
            }
            else
            {
                izquierdo = actual;
                derecho = actual->der;
            }
        }
    }
    tNodoDobl * nue = (tNodoDobl*)malloc(sizeof(tNodoDobl));
    if(!nue)
        return SIN_MEMORIA;
    nue->info = malloc(cantBytes);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEMORIA;
    }
    memcpy(nue->info, nota, cantBytes);
    nue->tamInfo = cantBytes;
    nue->izq = izquierdo;
    nue->der = derecho;
    if(izquierdo)
        izquierdo->der = nue;

    if(derecho)
        derecho->izq = nue;
    *lista = nue;
    return eliminados>0?(-1)*eliminados: TODO_BIEN;
}

//int ponerEnListaDoblNMejores_MIO(tListaDobl * lista, const void *nota,
//                                 size_t cantBytes, int tope)
//{
//    tNodoDobl * actual = *lista;
//    tNodoDobl *izquierdo, *derecho = NULL, *ultimo = NULL, *anteultimo, *pBorrado;
//    int cant=1, cmp, eliminados = 0;
//    if(!actual)
//        izquierdo=derecho=NULL;
//    else
//    {
//        while(actual->izq)
//            actual= actual->izq;
//        while(actual->der && (!derecho|| cant<tope))
//        {   if(compararNota(actual->info, actual->der->info ) != 0)
//                pBorrado = actual;
//            if(!derecho && compararClave(nota,actual->info)>=0)
//            {
//                if(compararClave(nota,actual->info)>0)
//                {
//                    derecho = actual;
//                    izquierdo = actual->izq;
//                }
//                else
//                {
//                    izquierdo = actual;
//                    derecho = actual->der;
//                }
//            }
//            actual = actual->der;
//            cant++;
//            if(cant==tope)
//            {
//                ultimo = actual;
//                if(compararNota(actual->info,nota)>0)
//                    return NO_SE_INSERTA;
//            }
//        }
//        if(ultimo == NULL)
//            ultimo = actual;
//        anteultimo = ultimo->izq;
//        cmp=compararNota(nota, ultimo->info);
//        if(cmp < 0 && cant >= tope)
//            return NO_SE_INSERTA;
//        if(cant >= tope && cmp>0 && pBorrado)/// && compararNota(anteultimo->info,ultimo->info)!=0 )
//        {
//            printf("Aca ni entra\n");
//            anteultimo->der = NULL;
//            actual = anteultimo;
//                ultimo = pBorrado->der;
//                anteultimo = pBorrado;
//                anteultimo->der = NULL;
//            while(ultimo)
//            {
//                tNodoDobl * auxiliar = ultimo->der;
//                free(ultimo->info);
//                free(ultimo);
//                ultimo = auxiliar;
//                eliminados++;
//            }
//        }
//        if(!derecho)
//        {
//            if(compararClave(nota,actual->info)>0)
//            {
//                derecho = actual;
//                izquierdo = actual->izq;
//            }
//            else
//            {
//                izquierdo = actual;
//                derecho = actual->der;
//            }
//        }
//    }
//    tNodoDobl * nue = (tNodoDobl*)malloc(sizeof(tNodoDobl));
//    if(!nue)
//        return SIN_MEMORIA;
//    nue->info = malloc(cantBytes);
//    if(!nue->info)
//    {
//        free(nue);
//        return SIN_MEMORIA;
//    }
//    memcpy(nue->info, nota, cantBytes);
//    nue->tamInfo = cantBytes;
//    nue->izq = izquierdo;
//    nue->der = derecho;
//    if(izquierdo)
//        izquierdo->der = nue;
//    if(derecho)
//        derecho->izq = nue;
//    *lista = nue;
//    return eliminados>0?(-1)*eliminados: TODO_BIEN;
//}


/** para el PUNTO 1 b.- **/
int ponerEnListaSimpNMejores_MIO(tListaSimp *lista, const void *nota,
                                 size_t cantBytes, int tope)

{
    tListaSimp * act = lista,
                 *nodoUlti = lista,
                  *nodoAnteUlt;
    int cantNodos=1,
        comp,
        cantEliminados =0;
    if(*act)
    {
        while(*nodoUlti && (*nodoUlti)->sig && cantNodos<tope)
        {

            nodoAnteUlt = nodoUlti;
            nodoUlti = &(*nodoUlti )->sig;
            cantNodos++;
            if(compararClave(nota,(*nodoUlti)->info)<0)
                act=nodoUlti;
        }
        if(!*nodoUlti)
        {
            nodoAnteUlt = NULL;
        }

        comp=compararNota(nota, (*nodoUlti)->info);
        if(cantNodos >= tope && comp < 0)
            return NO_SE_INSERTA;
        if(comp > 0 && *nodoAnteUlt && *nodoUlti &&
                compararNota((*nodoAnteUlt)->info,(*nodoUlti)->info)!=0)
        {
            while(*nodoUlti)
            {
                tNodoSimp * aux = *nodoUlti;
                *nodoUlti = aux->sig;
                free(aux->info);
                free(aux);
                cantEliminados++;
            }
        }
    }
    while(*act && compararClave(nota,(*act)->info)<0)
        act = &(*act)->sig;
    tNodoSimp * nue = (tNodoSimp*)malloc(sizeof(tNodoSimp));
    if(!nue)
        return SIN_MEMORIA;
    nue->info = malloc(cantBytes);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEMORIA;
    }
    memcpy(nue->info, nota, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *act;
    *act = nue;
    return cantEliminados>0?(-1)*cantEliminados: TODO_BIEN;
}

int compararNota(const void * d1, const void * d2)
{
    tEvalua * n1 = (tEvalua*)d1;
    tEvalua * n2 = (tEvalua*)d2;
    return n1->calif-n2->calif;
}

int compararClave(const void * d1, const void * d2)
{
    tEvalua * n1 = (tEvalua*)d1;
    tEvalua * n2 = (tEvalua*)d2;
    if(n1->calif == n2->calif)
        return strcmp(n2->clave,n1->clave);
    else
        return n1->calif-n2->calif;
}


/**                  FIN de PUNTO 1 **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

