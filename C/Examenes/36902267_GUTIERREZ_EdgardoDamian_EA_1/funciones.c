
#include "funciones.h"

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

/// Para evitar conflicto con la matriz rectangular, recorro media matriz y
/// realizo el intercambio
void rotarMat180_MIO(int m[][COLUM], int filas, int colum)
{
    int i, j, aux;
    for(i=0 ; i <=  filas/2 +1 ; i++)
    {
        for(j=0 ; j < colum ; j++)
        {
            aux = m[i][j];
            m[i][j] = m[filas-1-i][colum -1 -j];
            m[filas-1-i][colum -1 -j] = aux;
        }
    }
}
int  mostrarMatTriangDerInf_MIO(int m[][COLUM], int filas, int colum)
{
    int i,j;
    for(i = 0 ; i < filas ; i++)
    {
/** Para no realizar un for colocando cantidad de espacioes necesarios,
por lo tanto uso %*S**/
        printf("%*s",(filas - 1- i)* sizeof(int),"");
        for(j = colum -1 - i; j < colum ; j++)
            printf("%4d",m[i][j]);
        printf("\n");
    }
    return 1;
}

int  contarOcurrencias2_MIO(const char *cad, const char *sub)
{
    int cant=0;
    if(!*sub)
        return ++cant;
    while(*cad)
    {
        while(*cad && toupper(*cad)!= toupper(*sub))
            cad++;
        cad = CmpCadSubcad(cad, sub,&cant);
    }
    return cant;
}
char* CmpCadSubcad(const char* cad, const char* sub, int* cant)
{
    while(*cad)
    {
        if( *cad && A_MAYUSCULA(*cad) == A_MAYUSCULA(*sub))
        {
            cad++;
            sub++;
        }
        else
        {
            if(!*sub)
                (*cant)++;
            return (char*)cad;
        }
    }
    if(!*sub)
        (*cant)++;
    return (char*) cad;
}
int  contarOcurrencias1_MIO(const char *cad, const char *sub)
{
    int cant=0, cant_elem_sub=strlen(sub), retorno_comp;
    if(!*sub)
        return ++cant;
    while(*cad)
    {
        cad = obtenerPrimerAparicion(cad, sub);
        retorno_comp = compararNcaracteres(cad,sub,cant_elem_sub);
        if(!*cad)
            return cant;
        if(retorno_comp == 0 )
        {
            cant++;
            if(cant_elem_sub == 1)
                cad++;
            else
                cad = incrementarPosicionesCad(cad,cant_elem_sub-1);
        }
        else
            cad++;


    }
    return cant;
}

char* obtenerPrimerAparicion(const char* cad, const char* sub)
{
    while(*cad && A_MAYUSCULA(*cad)!= A_MAYUSCULA(*sub))
        cad++;
    return (char*)cad;
}

int compararNcaracteres(const char* cad, const char* sub,int cant_sub)
{
    while(*cad && *sub && cant_sub > 0 )
    {
        if(A_MAYUSCULA(*cad)== A_MAYUSCULA(*sub))
        {
            cad++;
            sub++;
        }
        else
            return cant_sub;
        cant_sub--;
    }
    return cant_sub;
}

char* incrementarPosicionesCad(const char* cad,int cant_elem)
{
    while(*cad && cant_elem >0)
    {
        cad++;
        cant_elem--;
    }
    return (char*)cad;
}

int  ordenarArchivo_MIO(const char *archEnt, const char *archSal)
{
    char linea[500],linea_aux_pila[500];
    int cant_pal_pil=0, cant_pal_lin=0, max_pal_pil=0, max_pal_lin=0;
    tPila pilaOrdenada, pilaAux; ///Hago uso de 2 pilas, una para ir insertando respetando un orddden
                                 /// y la aux para no perder los datos cuando desapilo
    FILE *pf_entrada, *pf_salida;
    pf_entrada = fopen(archEnt, "rt");
    if(!pf_entrada)
        {
            puts("Error apertura en archivo entrada\n");
            fclose(pf_entrada);
            exit(ERROR_ARCH_ENT);
        }

    pf_salida = fopen(archSal, "wt");
    if(!pf_salida)
    {
        puts("Error apertura en archivo salida\n");
        fclose(pf_salida);
        fclose(pf_entrada);
        exit(ERROR_ARCH_SAL);
    }
    crearPila(&pilaOrdenada);
    crearPila(&pilaAux);
    while(fgets(linea,sizeof(linea), pf_entrada))
    {
        if(pilaVacia(&pilaOrdenada)) ///Si la pila esta vacia ya es el maximo
        {
            if(!ponerEnPila(&pilaOrdenada,linea, strlen(linea)+1))
                puts("Error al poner en pila,cuando la pila esta vacia\n");
        }
        else
        {
            ///Obtengo cantidad de palabras de la registro del archivo y del tope de la pila ordenada
            cant_pal_lin = contarPalabras(linea);
            verTope(&pilaOrdenada, linea_aux_pila, sizeof(linea_aux_pila));
            cant_pal_pil = contarPalabras(linea_aux_pila);
            while( !pilaVacia(&pilaOrdenada) && cant_pal_pil < cant_pal_lin)
            {
                sacarDePila(&pilaOrdenada, linea_aux_pila, sizeof( linea_aux_pila));
                ponerEnPila(&pilaAux, linea_aux_pila, sizeof(linea_aux_pila));
                verTope(&pilaOrdenada, linea_aux_pila,sizeof(linea_aux_pila));
                cant_pal_pil = contarPalabras(linea_aux_pila);
            }
        while(!pilaVacia(&pilaOrdenada) && (cant_pal_lin == cant_pal_pil))
        {
            max_pal_lin = tamPalabraMasGrande(linea);
            max_pal_pil = tamPalabraMasGrande(linea_aux_pila); ///Estoy viendo el tope
            if( max_pal_lin >= max_pal_pil)
            {
                sacarDePila(&pilaOrdenada, linea_aux_pila, sizeof(linea_aux_pila));
                ponerEnPila(&pilaAux, linea_aux_pila, strlen(linea_aux_pila)+1);
            }
            verTope(&pilaOrdenada,linea_aux_pila, sizeof(linea_aux_pila));
            cant_pal_lin = tamPalabraMasGrande(linea_aux_pila);
        }
        ///poner en pila ordenada, sacar de pila aux y meter en pila ordenada
        ponerEnPila(&pilaOrdenada, linea, strlen(linea)+1 );
        while(sacarDePila(&pilaAux,linea_aux_pila, sizeof(linea_aux_pila)))
            ponerEnPila(&pilaOrdenada, linea_aux_pila, strlen(linea_aux_pila)+1);
            }
    }
    while(sacarDePila(&pilaOrdenada, linea_aux_pila,sizeof(linea_aux_pila)))
        fprintf(pf_salida,"%s\n",linea_aux_pila);
    fclose(pf_entrada);
    fclose(pf_salida);
    return 1;

}
int contarPalabras(const char* cad)
{
    int canti = 0;
    while(*cad)
    {
        cad=buscarInicioPalabra(cad);
        while( ES_LETRA(*cad) || ES_VOCAL_CON_ACENTO(*cad))
            cad++;
        if(*cad)
            canti++;
    }
    return canti;
}
char* buscarInicioPalabra(const char* cad)
{
    while(*cad && !ES_LETRA(*cad) )
        cad++;
    return (char*)cad;
}


int tamPalabraMasGrande(const char* linea)
{
    int cant_pala, canti_pal_max=0, marca=1;
    while(*linea)
    {
        cant_pala = 0;
        linea = buscarInicioPalabra(linea);
        if(!*linea)
            return canti_pal_max;
        while((*linea && ES_LETRA(*linea) || ES_VOCAL_CON_ACENTO(*linea)))
        {
            linea++;
            cant_pala++;
        }
        if(marca)
        {
            canti_pal_max = cant_pala;
            marca = 0;
        }
        else
        {

            if(canti_pal_max < cant_pala)
                canti_pal_max = cant_pala;

        }
    }
    return canti_pal_max;
}



void crearPila_MIO(tPila *p)
{
    p->tope = TAM_PILA;

}


int  pilaLlena_MIO(const tPila *p, unsigned cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned);

}


int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes)
{
    if(p->tope < cantBytes + sizeof(unsigned))
        return 0;
    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));
    return 1;
}


int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes)
{
    unsigned tInfo;
    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tInfo, p->pila +p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), minimo(cantBytes, tInfo));
    return 1;
}

int  pilaVacia_MIO(const tPila *p)
{
    return p->tope  == TAM_PILA;

}


int  sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes)
{
    unsigned tInfo;

    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, minimo(cantBytes, tInfo));
    p->tope += tInfo;
    return 1;

}

///No la utilizo
void vaciarPila_MIO(tPila *p)
{
    p->tope == TAM_PILA;
}



/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
