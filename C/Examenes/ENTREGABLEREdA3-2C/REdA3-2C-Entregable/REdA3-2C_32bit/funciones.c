/**//*             en los siguientes macroreemplazos indique:             *//**/
/**//*    su(s)         APELLIDO(S)     completo(s)                       *//**/
/**//*    su(s)         Nombre(S)       completo(s)                       *//**/
/**//*    su legajo     NÚMERO DE DNI   con los puntos de millón y de mil *//**/
/**//*    COMISIÓN                                                        *//**/
/**//*              reemplazando los que están como ejemplo               *//**/
#define APELLIDO    "Gutierrez"
#define NOMBRE      "Edgardo Damian"
#define DOCUMENTO   "36.902.267"
#define COMISION    "02(3362)"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** aquí insertaremos nuestras observaciones y / o correcciones              **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ *//**/



/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <stdlib.h>
#include <string.h>
int compararClave(const void * d1, const void * d2);
int compararNota(const void * d1, const void * d2);

/** para el PUNTO 1 c.- **/
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

int ponerEnListaDoblNCalif_MIO(tListaDobl *lista, const void *nota,
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
        while(actual->der && (!derecho || cambiosVal < tope))
        {
            if(compararNota(actual->info, actual->der->info ) != 0)
            {
                cambiosVal++;
                pBorrado = actual;
            }
            if(compararNota(nota, (actual)->info) == 0)
                marcaCoincide++;

            if(!derecho&&compararClave(nota,actual->info)>=0)
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
            if(marcaCoincide == tope-1)
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
        if(cmp < 0 && cant >= tope && cambiosVal == tope-1 )
        {
            printf("Borrando: %s \n", ((tEvalua*)pBorrado->info)->clave);
            return NO_SE_INSERTA;
        }
        else
        {
            if(cant >= tope && cmp>0 && anteultimo &&
                    cambiosVal == tope-1 && marcaCoincide==0)
            {
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
/**                  FIN de PUNTO 1 **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

