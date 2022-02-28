#include "ejercicioMemDinamica.h"

void teoriaMemoriaDinamica()
{
   /***
   yo decido cuando la reservo - Ventaja
   no me tengo que olvidar de liberarla - Desventaja
   To decido cuando liberarla

   void* malloc(size_t tam) ///tam es una canti de bytes
   - Null si no hay espacio
   - Dir inicio espacio adjudicado
   t_alumno *pa;
    pp = malloc(TAM);
    ///leer pp -> como interpretarlo -> casteando
    pa = (t_alumno*)pp;
   void calloc(size_t mem, size_t tam)
   Liberar memoria
   void free(void* puntero)

   void *realloc ( void* puntero, size_t tam);
   ///reasigno memoria dinamica

   ***/

}
void teoriaMemoriaEstatica()
{
    /***
    memoria estatica, se reserva cuando se declara
        Se inician al inicio de un bloque y se libera al final del bloque donde se defina

    ***/
    int x = 4,i;
    float y = 2.99;
    for(i=1; i < 5 ; i++)
    {
        int x = 9;
        printf("%d\n",x);
        if(x <= 4)
        {
            int x = 1 ;
            printf("%f\n", x * y);
        }
        printf("%d",x);
    }
    printf("%d",x);

}

void ejercicioMemoriaDinamica()
{
    int *pVec, vec[10], *pAux, i;
    pVec = (int*)malloc(sizeof(int)*10);
    if(!pVec)
    {
        puts("Error de sistema");
        return;
    }
    for(i=0; i < 10 ; i++)
       {
           *pVec+= i+1;
           pVec++;
       }
    pVec-=10;
    for(i=0; i < 10 ; i++)
        {
            printf("%d ",*pVec);
            pVec++;
        }
    pAux = (int *) realloc(pVec,sizeof(int)*20);
    if(!pAux)
        return ;
    for(i=0; i < 10 ; i++)
        {
            *pVec = i +10;
            pVec++;
        }
    for(i=0; i < 10 ; i++)
        {
            printf("%d ",*pVec);
            pVec++;
        }

}

-
