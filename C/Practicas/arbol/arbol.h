#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(X, Y) ( (X ) <= (Y) ? (X) : (Y))

typedef struct
{
    char nombre[10];
    int dni;
    float nota;
}t_estr;

typedef struct s_nodo
{
    unsigned cantBytes;
    void* dato;
    struct s_nodo *izq;
    struct s_nodo *der;
}t_nodo;

typedef t_nodo *t_arbol;

void teoriaArbol();

void crearArbol(t_arbol *pa);
int arbolVacio(const t_arbol *pa);
int insertarEnOrdenR(t_arbol *pa, const void *d, unsigned cantBytes,
                     int (*cmp)(const void* d1, const void* d2));
int insertarEnOrdenI(t_arbol *pa, const void *d, unsigned cantBytes,
                     int (*cmp)(const void* d1, const void* d2));

void mostrarInorden(const t_arbol *pa, void (*mostrar)(const void *d));
void mostrarInordenIterativa(const t_arbol *pa, void (*mostrar)(const void *d));


void mostrarPreorden(const t_arbol *pa, void (*mostrar)(const void *d));
void mostrarPostorden(const t_arbol *pa, void (*mostrar)(const void *d));

int grabarArbolEnArchivo(const t_arbol *pa, unsigned cantBytes, void *dato, void *pf,
                        void (*accion)(const void*, const void*));
//int cargarArchivoEnArbol();
int cmp_Estr(const void *d1, const void *d2);
int cmpInt(const void *d1, const void *d2);

void grabarEnArchivoTexto(const void *d1, const void*d2);
int contarTodosNodos(const t_arbol *pa);
int contarHojas( const t_arbol *pa);
int contarNoHojas( const t_arbol *pa);
int alturaArbol(const t_arbol *pa);
void mostrarNodoPorAltura(const t_arbol *pa, int h);
int mostrandoHastaAlturaIncluida(const t_arbol *pa, int h);
int eliminarHoja(t_arbol *pa);
void buscarMayorClave(const t_arbol *pa);
void buscarMenorClave(const t_arbol *pa);
int promedioNodosPar(const t_arbol *pa);
int promedioNodosImpar(const t_arbol *pa);
int contarNodosImpares(const t_arbol *pa);
int cmpNodoPar(const void *d);
int retornoPar(const void *d);
int contarNodosPares(const t_arbol *pa);
int calcularSumPar(const t_arbol *pa);
int calcularSumImpar(const t_arbol *pa);
int contarNodosImpares(const t_arbol *pa);
float castearEntero(const void *d);
void mostrarEstructura( const void *d);
void mostrarInt( const void *d);
int alturaSubArbolDer(const t_arbol *pa);
int alturaSubArbolIzq(const t_arbol *pa);
void podarArbolDesdeAlturaNR(t_arbol *pa, int h);
void podarArbolDesdeAlturaR(t_arbol *pa, int h);
void podarArbolDesdeAlturaRInc(t_arbol *pa, int h);
void verArbol(const t_arbol *pa, int h, unsigned cantBytes);
void imprimirArbol(const t_arbol *pa, int h, unsigned cantBytes, char sep);
void mostrarDesdeAlturaSinI(const t_arbol *arbolR, int h);
void mostrarDesdeAlturaInc(const t_arbol *arbolR, int h);
void mostrarIntArborlGirado( const void *d , int h, unsigned cantByte, char sep);
int buscarClave(const t_arbol *pa, void *d, unsigned cantBytes,
                int (*cmp)(const void *d1, const void *d2));
void mostrarMenorNoClave(const t_arbol *pa, void *d, unsigned cantBytes,
                         int(*cmp)(const void *d1, const void *d2));

void mostrarMayorNoClave(const t_arbol *pa, void *d, unsigned cantBytes,
                         int(*cmp)(const void *d1, const void *d2));
const t_arbol* buscarMayorNoClave(const t_arbol *pa, const t_arbol *aux, unsigned cantBytes,
                            int(*cmp)(const void *d1, const void *d2));
int cmp_Estr_NoClave(const void *d1, const void *d2);
                           ///int(*cmp)(const void *d1, const void *d2));
const t_arbol* buscarMenorNoClave(const t_arbol *pa,const t_arbol *aux, unsigned cantBytes,
                            int(*cmp)(const void *d1, const void *d2));
void leerArchivoTexto(FILE *pf, unsigned cantBytes,
                      void (*mostrar)(const void*d));
int borrarArbol(t_arbol *pa, unsigned cantBytes,
            int (*cmp)(const void *d1, const void *d2));
int arbolCompleto(const t_arbol *pa);
int esArbolCompleto(const t_arbol *pa, int h);
int esBalanceado(const t_arbol *pa);
int esAvl(const t_arbol *pa);
int borrarNodoRaiz(t_arbol *pa,unsigned cantBytes, void *dato,
                         int (*cmp)(const void *d1, const void *d2));
t_arbol* buscarClaveRetornoNodo(const t_arbol *pa, void *d, unsigned cantBytes,
                int (*cmp)(const void *d1, const void *d2));
t_arbol* buscarMenorClaveRetornandoNodo(const t_arbol *pa);
t_arbol* buscarMayorClaveRetornandoNodo(const t_arbol *pa);
void intercambiar(void *origen, void *destino);


#endif // ARBOL_H_INCLUDED
