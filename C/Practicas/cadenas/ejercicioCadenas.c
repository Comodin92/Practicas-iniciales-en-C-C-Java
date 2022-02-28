#include "ejercicioCadenas.h"
#include "main.h"



int ordenamientoSelectivo(char *cad,
                          int (*cmp)(const void *d1, const void *d2))
{
    char*  pRecorre,
           *pMenorMayor ,
           aux,
           opcion;
    if(!*cad)
        return 0;
    printf("Desea ordenarlo de forma ascendente (a) o descendente (d)\n");
    scanf("%c",&opcion);
    while(*(cad+1))
    {
        pMenorMayor = cad;
        pRecorre = cad+1;
        while(*pRecorre)
        {
            if(opcion == 'a')
            {
                if(cmp(pRecorre,pMenorMayor )< 0)
                    pMenorMayor = pRecorre;
            }
            else
            {
                if(cmp(pRecorre,pMenorMayor ) > 0)
                    pMenorMayor = pRecorre;
            }
            pRecorre++;
        }
        aux = *pMenorMayor;
        *pMenorMayor = *cad;
        *cad = aux;
        cad++;
    }
    return 1;
}

int ordenamientoSelectivoInt(int *cadInt, int ce,
                             int (*cmpInt)(const void *d1, const void *d2),
                             void (*intercambio)(const void *da1, const void* da2))
{
    int *pfin = cadInt + (ce -1),
         *pMenorMayor,
         *pRecorre,
         aux;
    char opcion;
    if(!ce)
        return 0;
    printf("Desea ordenarlo de forma ascendente (a) o descendente (d)\n");
    scanf("%c",&opcion);
    while(cadInt < pfin)
    {
        pMenorMayor = cadInt;
        pRecorre = cadInt+1;
        while(pRecorre <= pfin)
        {
            if(opcion == 'a')
            {
                if(cmpInt(pRecorre,pMenorMayor )< 0)
                    pMenorMayor = pRecorre;
            }
            else
            {
                if(cmpInt(pRecorre,pMenorMayor ) > 0)
                    pMenorMayor = pRecorre;
            }
            pRecorre++;
        }
        if(pMenorMayor != cadInt) ///mientras el minimo o maximo no sea el primero
            intercambio(pMenorMayor, cadInt);
        cadInt++;
    }
    return 1;
}

 void ordenarSelecGenerico( void *vec, int ce, int size,
                             int (*cmpInt)(const void *d1, const void *d2),
                             void (*intercambio)(const void *da1, const void* da2))
{
        int aux;
        void *pfin,
         *pMenorMayor,
         *pRecorre;
    char opcion;
    if(!ce)
        return 0;
    pfin = cadInt + (ce -1),
    printf("Desea ordenarlo de forma ascendente (a) o descendente (d)\n");
    scanf("%c",&opcion);
    while(cadInt < pfin)
    {
        pMenorMayor = cadInt;
        pRecorre = cadInt+1;
        while(pRecorre <= pfin)
        {
            if(opcion == 'a')
            {
                if(cmpInt(pRecorre,pMenorMayor )< 0)
                    pMenorMayor = pRecorre;
            }
            else
            {
                if(cmpInt(pRecorre,pMenorMayor ) > 0)
                    pMenorMayor = pRecorre;
            }
            pRecorre++;
        }
        if(pMenorMayor != cadInt) ///mientras el minimo o maximo no sea el primero
            intercambio(pMenorMayor, cadInt);
        cadInt++;
    }
    return 1;
}

}

char* strcpy_mia(char *destino, const char* origen )
{
    char *aux=destino;
    while(*origen) ///*origen != '\0'
    {
        *destino = *origen;
        origen++;
        destino++;
    }
    *destino = '\0';
    return aux;
}

char* strcat_mio ( char* destino, const char* origen)
{
    char *aux=destino;
    if( TAM < (strlen(destino) + strlen(origen)));
    {
        puts("No se puede concatenar, no hay espacio");
        return NULL;
    }
    while(*destino)
        destino++;
    while(*origen)
    {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
    return aux;
}
size_t strlen_mio ( const char* cad)
{
    int ce=0;
    if(!*cad)
        return ce;
    while(*cad)
    {
        ce++;
        cad++;
    }
    return ce;
}
//char *strcat_mio_control(char *cad11, const char* cad21)
//{
//    char *aux=cad11;
//    printf("sizeof(cad11) %d\n", sizeof(cad11));
//    printf("strlen(cad11)  = %d\n", strlen(cad11));
//    printf("strlen(cad21) = %d\n", strlen(cad21));
//    printf("strlen(cad11) + strlen(cad21) %d\n ");
//    if(sizeof(cad11) < strlen(cad11) + strlen(cad21))
//        printf("No es posible\n");
//    return aux;
//}

int normalizarCadena( char* cad)
{
    int marca=1, marca_mayus=1;
    char *destino = cad;
    if(!*cad)
        return 0;
    while( *cad)
    {
        while(ES_BLANCO(*cad) || !ES_LETRA(*cad))
            cad++;
        while(ES_LETRA(*cad))
        {
            if(marca_mayus)
            {
                *destino = A_MAYUSCULA(*cad);
                marca_mayus = 0;
            }
            else
                *destino = A_MINUSCULA(*cad);
            destino++;
            cad++;
        }
        if(marca)
        {
            *destino = ',';
            destino++;
            marca = 0;
        }
        *destino = ' ';
        destino++;
    }
    *(destino-1) ='.';
    *(destino) = '\0';
    return 1;
}

int ocurrenciasSinSolapa(const char *cadena , const char* subcadena)
{
    const char *reseteSub = subcadena;
    int cant_ocu=0;
    if(!*cadena || !*subcadena)
        return cant_ocu;
    while(*cadena)
    {
        if(*cadena != *subcadena)
        {

            if(reseteSub != subcadena) ///PREGUNTO SI SUBCADENA NO APUNTA AL INICIO
                subcadena = reseteSub;
        }
        else
            subcadena++;
        cadena++;
        if(!*subcadena)
        {
            cant_ocu++;
            subcadena = reseteSub;
        }
    }
    return cant_ocu;
}

int ocurrenciasConSolapa(const char *cadena , const char* subcadena)
{
    int cant_ocu  = 0 ;
    if(!*cadena || !*subcadena)
        return cant_ocu;
    while(*cadena)
    {
        cadena = strchr(cadena, *subcadena);
        if(!*cadena)
            return cant_ocu;
        if(!strncmp(cadena, subcadena, strlen(subcadena)))
            cant_ocu++;
        cadena+=(strlen(subcadena)-1);
    }
    return cant_ocu;
}

int atoi_mia(const char *cadNum)
{
    const char *pri=cadNum;
    int num_conv=0, multip=1;
    while(*(cadNum+1))
        cadNum++;
    while(cadNum >= pri)
    {
        num_conv += ((*cadNum) -'0')*multip;
        multip*=10;
        cadNum--;
    }
    return num_conv;
}

//void corrimientos(char *cad,  int desp, int *ce, const int tam)
//{
//    int restoDiv;
//    char *inicio=cad, *pFin = cad + ((*ce) - 1);
//    if(!desp)
//        return;
//    if(desp > 0 )
//    {
//        if(*ce == tam-1) ///lleno
//        {
//            restoDiv = desp % (tam-1);
//
//
//        }
//
//    }
//
//}
