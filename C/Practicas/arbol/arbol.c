#include "arbol.h"


//void teoriaArbol()
//{
/***
grado: dependiendo del grado del arbo, obtengo la cantidad maxima de hijos que puede tener un nodo
si tengo grado 4, todos los nodos deben tener 4 hijos

Cada nodo puede tener hasta n hijos pero como máximo 1 solo padre

nivel altura, nivel 0 -> altura nivel +1:   nivel 0 altura 1, nivel 1 altura 2
arbol binario -> como maximo tiene 2 hijos

arbol de grado 1 ¿Qué es? Es una lista simplemente enlazada

***/

//}

void crearArbol(t_arbol *pa)
{
    *pa = NULL;
}


int arbolVacio(const t_arbol *pa)
{
    return *pa == NULL;
}


int insertarEnOrdenR(t_arbol *pa, const void *d, unsigned cantBytes,
                     int (*cmp)(const void*d1, const void*d2))
{
    int comparacion;
    if(*pa)
    {
        comparacion = cmp(d, (*pa)->dato);
        if(comparacion == 0)
            return -1;
        if(comparacion < 0)
            return insertarEnOrdenR(&(*pa)->izq, d, cantBytes, cmp);
        else
            return  insertarEnOrdenR(&(*pa)->der,d, cantBytes, cmp);
    }
    if(!(*pa = (t_nodo*)malloc(sizeof(t_nodo))) || !((*pa)->dato = malloc(cantBytes)))
    {
        free(*pa);
        return 0;
    }
    (*pa)->cantBytes = cantBytes;
    memcpy((*pa)->dato, d, cantBytes );
    (*pa)->izq = NULL;
    (*pa)->der = NULL;
    return 1;
}

void mostrarInorden(const t_arbol *pa, void (*mostrar)(const void *d))///iterativa calse sig
{
    if(!*pa)
        return ;

    mostrarInorden(&(*pa)->izq, mostrar);
    mostrar((*pa)->dato);
    mostrarInorden(&(*pa)->der, mostrar);
}

void mostrarPreorden(const t_arbol *pa, void (*mostrar)(const void *d))
{
    if(!*pa)
        return ;
    mostrar((*pa)->dato);
    mostrarPreorden(&(*pa)->izq, mostrar);
    mostrarPreorden(&(*pa)->der, mostrar);
}
void mostrarPostorden(const t_arbol *pa, void (*mostrar)(const void *d))
{
    if(!*pa)
        return ;
    mostrarPostorden(&(*pa)->izq, mostrar);
    mostrarPostorden(&(*pa)->der, mostrar);
    mostrar((*pa)->dato);
}

int grabarArbolEnArchivo(const t_arbol *pa, unsigned cantBytes, void *dato, void *pf,
                         void (*accion)(const void*, const void*))
{
    if(*pa)
    {
        grabarArbolEnArchivo(&(*pa)->izq, cantBytes, dato,pf,accion);
        (*pa)->cantBytes = cantBytes;
        memcpy(dato,(*pa)->dato, MINIMO(cantBytes, (*pa)->cantBytes));
        accion(dato,pf);
        grabarArbolEnArchivo(&(*pa)->der, cantBytes, dato, pf, accion);
    }
    return 1;
}

void grabarEnArchivoTexto(const void *d1, const void*d2)
{
    ///fprintf((FILE*)d2,"%d\n",*(int*)d1);
    t_estr aux = *(t_estr*)d1;
    fprintf((FILE*)d2,"%-*s | %*d | %*.2f\n",10,aux.nombre, 10,aux.dni, 5, aux.nota);

}

int insertarEnOrdenI(t_arbol *pa, const void *d, unsigned cantBytes,
                     int (*cmp)(const void*d1, const void*d2))
{
    int comparacion=1;
    while(*pa)
    {
        comparacion = cmp(d, (*pa)->dato);
        if(comparacion == 0)
            return 0;
        if(comparacion < 0)
            pa = &(*pa)->izq;
        else
            pa = &(*pa)->der;
    }
    if(!(*pa = (t_nodo*)malloc(sizeof(t_nodo))) || !((*pa)->dato = malloc(cantBytes)))
    {
        free(*pa);
        return 0;
    }
    (*pa)->cantBytes = cantBytes;
    memcpy((*pa)->dato, d, cantBytes );
    (*pa)->izq = NULL;
    (*pa)->der = NULL;
    return 1;
}

int contarTodosNodos(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    return 1 + contarTodosNodos(&(*pa)->izq) + contarTodosNodos(&(*pa)->der);
}

int contarHojas( const t_arbol *pa)
{
    if(!*pa)
        return 0;
    if(!(*pa)->izq && !(*pa)->der)
        return 1;
    return contarHojas(&(*pa)->izq) + contarHojas(&(*pa)->der) ;
}

int contarNoHojas( const t_arbol *pa)
{
    if(!*pa)
        return 0;
    if(!(*pa)->izq  &&   !(*pa)->der)
        return 0;
    return 1 + contarNoHojas(&(*pa)->izq) + contarNoHojas(&(*pa)->der) ;
}

int alturaArbol(const t_arbol *pa)
{
    int hi, hd;
    if(!*pa)
        return 0;
    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);
    return (hi < hd) ? 1 + hd :  1+ hi;
}
void mostrarNodoPorAltura(const t_arbol *pa, int h)
{
    if(!*pa)
        return;
    if(h == 1 )
        mostrarEstructura((*pa)->dato);
    mostrarNodoPorAltura(&(*pa)->izq, h-1);
    mostrarNodoPorAltura(&(*pa)->der, h-1);
}
int mostrandoHastaAlturaIncluida(const t_arbol *pa, int h)
{
    if(!*pa)
        return 0;
    if( h >= 1 )
    {
        mostrarEstructura((*pa)->dato);
        return 1 +  mostrandoHastaAlturaIncluida(&(*pa)->izq, h-1) + mostrandoHastaAlturaIncluida(&(*pa)->der, h-1);
    }
    return 0;
}

int eliminarHoja(t_arbol *pa)
{
    if(!*pa)
        return 0;

    if(!(*pa)->izq && !(*pa)->der )
    {
        free((*pa)->dato);
        free(*pa);
        (*pa) = NULL;
        return 1;
    }
    return  eliminarHoja(&(*pa)->izq) + eliminarHoja(&(*pa)->der);

}
void buscarMayorClave(const t_arbol *pa)
{
    if(!*pa)
        return;

    buscarMayorClave(&(*pa)->der);
    if(!(*pa)->der)
    {
        printf("El dato mayor es: ");
        mostrarEstructura((*pa)->dato);
    }
}

t_arbol* buscarMayorClaveRetornandoNodo(const t_arbol *pa)
{
    if(!*pa)
        return (t_arbol*)(*pa);

    buscarMayorClave(&(*pa)->der);
    if(!(*pa)->der)
        return (t_arbol*)pa;
    return NULL;
}
void buscarMenorClave(const t_arbol *pa)
{
    if(!*pa)
        return;

    buscarMenorClave(&(*pa)->izq);
    if(!(*pa)->izq)
    {
        printf("El dato menor es: ");
        mostrarEstructura((*pa)->dato);
    }
}

t_arbol* buscarMenorClaveRetornandoNodo(const t_arbol *pa)
{
    if(!*pa)
        return *(t_arbol*)pa;

    buscarMenorClave(&(*pa)->izq);
    if(!(*pa)->izq)
        return(t_arbol*) pa;
    return NULL;
}


int promedioNodosPar(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    return calcularSumPar(pa)/contarNodosPares(pa);
}

int contarNodosPares(const t_arbol *pa)
{
    if(!*pa)
        return 0 ;

    if(cmpNodoPar((*pa)->dato))
           {
            mostrarEstructura((*pa)->dato);
            return 1 + contarNodosPares(&(*pa)->izq) + contarNodosPares(&(*pa)->der);
            }
    else
        return contarNodosPares(&(*pa)->izq) + contarNodosPares(&(*pa)->der);
}
int calcularSumPar(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    if(cmpNodoPar((*pa)->dato))
        return (castearEntero((*pa)->dato)) + calcularSumPar(&(*pa)->izq) + calcularSumPar(&(*pa)->der);
    else
        return calcularSumPar(&(*pa)->izq) + calcularSumPar(&(*pa)->der);
}

///aaaaaaaaaaaaaaaaa
int promedioNodosImpar(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    return calcularSumImpar(pa)/contarNodosImpares(pa);
}

int contarNodosImpares(const t_arbol *pa)
{
    if(!*pa)
        return 0 ;
    if(!cmpNodoPar((*pa)->dato))
        return 1 + contarNodosImpares(&(*pa)->izq) + contarNodosImpares(&(*pa)->der);
    else
        return contarNodosImpares(&(*pa)->izq) + contarNodosImpares(&(*pa)->der);
}

int calcularSumImpar(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    if(!cmpNodoPar((*pa)->dato))
        {
            mostrarEstructura((*pa)->dato);
            return (castearEntero((*pa)->dato)) + calcularSumImpar(&(*pa)->izq) + calcularSumImpar(&(*pa)->der);
        }
    else
        return calcularSumImpar(&(*pa)->izq) + calcularSumImpar(&(*pa)->der);
}
int cmpNodoPar(const void *d)
{
    t_estr aux = *(t_estr*)d;
    return  (aux.dni)%2 == 0;
}

float castearEntero(const void *d)
{
    t_estr aux = *(t_estr*)d;
    return aux.nota;
}
int retornoPar(const void *d)
{
    return *(int*)d;
}

int cmp_Estr(const void *d1, const void *d2)
{
    t_estr  aux2 = *(t_estr*)d2,
            aux1 = *(t_estr*)d1;
    return strcmp(aux1.nombre, aux2.nombre);
}

int alturaSubArbolDer(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    return alturaArbol(&(*pa)->der);
}

int alturaSubArbolIzq(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    return alturaArbol(&(*pa)->izq);
}
void mostrarDesdeAlturaSinI(const t_arbol *pa, int h)
{
    if(!*pa)
        return;
    if(h < 1)
        mostrarEstructura((*pa)->dato);
    mostrarDesdeAlturaSinI(&(*pa)->izq, h - 1);
    mostrarDesdeAlturaSinI(&(*pa)->der, h - 1);
}
void mostrarDesdeAlturaInc(const t_arbol *pa, int h)
{
    if(!*pa)
        return;
    if(h <= 1)
        mostrarEstructura((*pa)->dato);
    mostrarDesdeAlturaInc(&(*pa)->izq, h - 1);
    mostrarDesdeAlturaInc(&(*pa)->der, h - 1);
}

///void podarArbolDesdeAlturaNR(t_arbol *pa, int h)
/// {   int hi = alturaSubArbolIzq(&(*pa)->izq),
///        hd = alturaSubArbolDer(&(*pa)->der);
///    if(hi > hd)
///        podarArbolDesdeAlturaNR(&(*pa)->izq, hi - hd);
///    else
///        podarArbolDesdeAlturaNR(&(*pa)->der, hd - hi);
///    podarArbolDesdeAlturaNR(pa, abs(hd - hi));
/// }
void podarArbolDesdeAlturaR(t_arbol *pa, int h)
{
    if(!*pa)
        return;
    if(h < 1)
    {
        free((*pa)->dato);
        free(*pa);
        (*pa) = NULL;
        return;
    }
    podarArbolDesdeAlturaR(&(*pa)->izq, h-1);
    podarArbolDesdeAlturaR(&(*pa)->der, h-1);
}
void podarArbolDesdeAlturaRInc(t_arbol *pa, int h)
{
    if(!*pa)
        return;
    if(h <= 1)
    {
        free((*pa)->dato);
        free(*pa);
        (*pa) = NULL;
        return;
    }
    podarArbolDesdeAlturaRInc(&(*pa)->izq, h-1);
    podarArbolDesdeAlturaRInc(&(*pa)->der, h-1);
}

void verArbol(const t_arbol *pa, int h, unsigned cantBytes)
{
    char sep = ' ';
    if(!*pa)
        return;
    imprimirArbol(pa, h, cantBytes, sep);
}
void imprimirArbol(const t_arbol *pa, int h, unsigned cantBytes, char sep)
{
    if(!*pa)
        return;

    imprimirArbol(&(*pa)->der, h+1, cantBytes, '/');
    mostrarIntArborlGirado((*pa)->dato, h, cantBytes, sep);
    imprimirArbol(&(*pa)->izq, h+1, cantBytes, 92);
}

void mostrarIntArborlGirado( const void *d , int h, unsigned cantBytes, char sep)
{
    t_estr aux = *(t_estr*)d;
    printf("%*s %c %-s | %d | %.2f\n",h*cantBytes,"",sep,aux.nombre,aux.dni, aux.nota);


}
int buscarClave(const t_arbol *pa, void *d, unsigned cantBytes,
                int (*cmp)(const void *d1, const void *d2))
{
    int compa;
    if(!*pa)
        return 0;
    if(*pa)
    {
        compa = cmp(d, (*pa)->dato);
        if(compa == 0 )
        {
            memcpy(d, (*pa)->dato, MINIMO(cantBytes, (*pa)->cantBytes));
            return 1;
        }
        else if(compa < 0)
            return buscarClave(&(*pa)->izq, d, cantBytes, cmp);
        else
           return buscarClave(&(*pa)->der, d, cantBytes, cmp);
    }
    return 0;
}

t_arbol* buscarClaveRetornoNodo(const t_arbol *pa, void *d, unsigned cantBytes,
                int (*cmp)(const void *d1, const void *d2))
{
    int compa;
    if(!*pa)
        return NULL;
    if(*pa)
    {
        compa = cmp(d, (*pa)->dato);
        if(compa == 0 )
        {
            memcpy(d, (*pa)->dato, MINIMO(cantBytes, (*pa)->cantBytes));
            return (t_arbol*)pa;
        }
        else if(compa < 0)
            return (t_arbol*)buscarClaveRetornoNodo(&(*pa)->izq, d, cantBytes, cmp);
        else
          return (t_arbol*)buscarClaveRetornoNodo(&(*pa)->der, d, cantBytes, cmp);
    }
    return NULL;
}


int borrarNodoRaiz(t_arbol *pa,unsigned cantBytes, void *dato,
                         int (*cmp)(const void *d1, const void *d2))
{
    t_arbol *aux;
    t_nodo *elim;
    int hi, hd;
    if(!*pa)
        return 0;
    pa = buscarClaveRetornoNodo(pa,dato,cantBytes,cmp);
//    mostrarEstructura((*pa)->dato);
//    /system("pause");
    if(!(*pa))
        return 0;
    if( !(*pa)->der && !(*pa)->izq)
    {
        memcpy(dato, (*pa)->dato, cantBytes);
        free((*pa)->dato);
        free((*pa));
        (*pa) = NULL;
        return 1;
    }
    else
    {
        hi = alturaArbol(&(*pa)->izq);
        hd = alturaArbol(&(*pa)->der);
        if(hi > hd)
            {
                aux = buscarMayorClaveRetornandoNodo(&(*pa)->izq);
                ///memcpy((*pa)->dato, (*aux)->dato, cantBytes);
                ///(*pa)->cantBytes = cantBytes;
                elim = *aux;
                (*aux) = elim->izq;
            }
        else
            {
                aux = buscarMenorClaveRetornandoNodo(&(*pa)->der);
              ///  memcpy((*pa)->dato, (*aux)->dato, cantBytes);
               /// (*pa)->cantBytes = cantBytes;
                elim = *aux;
                (*aux) = elim->der;
            }
            (*pa)->dato = elim->dato;
            free((*pa)->dato);
            (*pa)->cantBytes = elim->cantBytes;
            free(elim);
    }
    return 1;
}
//void intercambiar( void *ori, void *desm unsigned cantBytes)
//{
//    t_estr  origen = *(t_estr*)ori->dato,
//            destino = *(t_estr*)des->dato,
//            aux;
//
//    memcpy(aux, origen, cantBytes)
//    memcpy(origen, destino, cantBytes);
//    memcpy(destino, aux, cantBytes);
//}

void mostrarMenorNoClave(const t_arbol *pa, void *d, unsigned cantBytes,
                         int(*cmp)(const void *d1, const void *d2))
{
    const t_arbol *aux =  pa;
    if(!*pa)
        return;
    aux = buscarMenorNoClave(&(*pa)->izq, aux, cantBytes, cmp);
    aux = buscarMenorNoClave(&(*pa)->der, aux, cantBytes, cmp);
    memcpy (d, (*aux)->dato, MINIMO(cantBytes, (*aux)->cantBytes));
    return;
}

const t_arbol* buscarMenorNoClave(const t_arbol *pa, const t_arbol *aux, unsigned cantBytes,
                            int(*cmp)(const void *d1, const void *d2))
{
    int compa ;
    if(!*pa)
        return (t_arbol*)aux;
    compa = cmp((*aux)->dato, (*pa)->dato);
    if(compa > 0)
        aux = (t_arbol*) pa;
    aux = buscarMenorNoClave(&(*pa)->izq, aux, cantBytes, cmp);
    aux = buscarMenorNoClave(&(*pa)->der, aux, cantBytes, cmp);
    return (t_arbol*)aux;
}
void mostrarMayorNoClave(const t_arbol *pa, void *d, unsigned cantBytes,
                         int(*cmp)(const void *d1, const void *d2))
{
    const t_arbol *aux = pa;
    if(!*pa)
        return;
    aux = buscarMayorNoClave(&(*pa)->izq, aux, cantBytes, cmp);
    aux = buscarMayorNoClave(&(*pa)->der, aux, cantBytes, cmp);
    memcpy (d, (*aux)->dato, MINIMO(cantBytes, (*aux)->cantBytes));
    return;
}

const t_arbol* buscarMayorNoClave(const t_arbol *pa, const  t_arbol *aux, unsigned cantBytes,
                            int(*cmp)(const void *d1, const void *d2))
{
    if(*pa)
    {
        if( cmp((*aux)->dato, (*pa)->dato) < 0)
            aux = (t_arbol*)pa;
        aux = buscarMayorNoClave(&(*pa)->izq, aux, cantBytes, cmp);
        aux = buscarMayorNoClave(&(*pa)->der, aux, cantBytes, cmp);
        return aux;
    }
    return aux;
}
int borrarArbol(t_arbol *pa, unsigned cantBytes,
            int (*cmp)(const void *d1, const void *d2))
{
    if(!*pa)
        return 0;
    borrarArbol(&(*pa)->izq,cantBytes,cmp) ;
    borrarArbol(&(*pa)->der,cantBytes,cmp);
    free((*pa)->dato);
    free((*pa));
    (*pa) = NULL;
    return 1;
}

int arbolCompleto(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    return esArbolCompleto(pa,alturaArbol(pa));
}

int esArbolCompleto(const t_arbol *pa, int h )
{
    if(!*pa)
        return 0;
    if( h == 1)
        return 1;
    return esArbolCompleto(&(*pa)->izq, h - 1) && esArbolCompleto(&(*pa)->der, h -1 );
}

int esBalanceado(const t_arbol *pa)
{
    int alt = alturaArbol(pa);
    if(!*pa)
        return 0;

    return esArbolCompleto(pa,alt-1);
}
 int esAvl(const t_arbol *pa)
{
    int altIzq,
        altDer;

    if(!*pa)
        return 1;

    altDer = alturaArbol(&(*pa)->der);
    altIzq = alturaArbol(&(*pa)->izq);

    if(abs(altDer - altIzq) > 1)
        return 0;

    return esAvl(&(*pa)->izq) &&
           esAvl(&(*pa)->der);
}

int cmpInt(const void *d1, const void *d2)
{
    int x1 = *(int*)d1,
        x2 = *(int*)d2;
    return x1- x2;
}

void mostrarInt( const void *d)
{
    printf("%d\n",*(int*)d);
}

void mostrarEstructura( const void *d)
{
    t_estr aux = *(t_estr*)d;
    printf("%-*s | %*d | %*.2f\n",10,aux.nombre, 10,aux.dni, 5, aux.nota);
}

int cmp_Estr_NoClave(const void *d1, const void *d2)
{
    t_estr  aux2 = *(t_estr*)d2,
            aux1 = *(t_estr*)d1;
    return aux1.nota - aux2.nota;
}

void leerArchivoTexto(FILE *pf, unsigned cantBytes,
                      void (*mostrar)(const void*d))
{
    char cad[100];
    while(fgets(cad,sizeof(cad),pf))
        printf("%s\n",cad);

    fclose(pf);
}


//t_arbol * borrarNodoRaiz(t_arbol *pa, ,unsigned cantBytes, void *dato,
//                         int (*cmp)(const void *d1, const void *d2))
//{
//    if(!*pa)
//        return pa;
//    buscar
//
//
//
//
//
//
//
//}
