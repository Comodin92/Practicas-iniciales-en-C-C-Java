#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#define ES_LETRA(x) ((((x)<= 'z') && ((x)>='a')) || (((x)<= 'Z') && ((x)>='A'))) ? 1: 0
#define ES_VOCAL_CON_ACENTO(x) (((((x)>='á') && (x)<= 'ù') || ((x)== 'é')) ? 1 : 0)
#define A_MAYUSCULA(x) (((x)<= 'Z' && (x)>='A' )? (x) : (x)-32)

#define minimo( X, Y )  (( X ) <= ( Y ) ? ( X ) : ( Y ))



/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#define FILAS       15
#define COLUM       13


int  cargarMatConsec(int m[][COLUM], int filas, int colum);
int  mostrarMat(int m[][COLUM], int filas, int colum);
void rotarMat180(int m[][COLUM], int filas, int colum);
int  mostrarMatTriangDerInf(int m[][COLUM], int filas, int colum);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
void inhibirArchivo(const char *nomArch);
void habilitarArchivo(const char *nomArch);

#define ARCH_ENT    "datos.txt"
#define ARCH_SAL    "nuevo.txt"

int  crearArchivo(const char *nomArch);

void mostrarArchivo(const char *nomArch);

#define ERROR_ARCH_ENT      -1
#define ERROR_ARCH_SAL      -2

int  ordenarArchivo(const char *archEnt, const char *archSal);

/* --------------------------------o---x---o--------------------------------
 *          para la pila con asignación ESTÁTICA de memoria
 *          ***declare y desarrolle sólo las que necesite***
 * --------------------------------o---x---o-------------------------------- */
#define     TAM_PILA        50000


typedef struct
{
    char        pila[TAM_PILA];
    unsigned    tope;
} tPila;

void crearPila(tPila *p);
int  pilaLlena(const tPila *p, unsigned cantBytes);
int  ponerEnPila(tPila *p, const void *d, unsigned cantBytes);
int  verTope(const tPila *p, void *d, unsigned cantBytes);
int  pilaVacia(const tPila *p);
int  sacarDePila(tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

///Ejercicio1
void rotarMat180_MIO(int m[][COLUM], int filas, int colum);
int  mostrarMatTriangDerInf_MIO(int m[][COLUM], int filas, int colum);

///Ejercicio2
int  contarOcurrencias1_MIO(const char *cad, const char *sub);
char* obtenerPrimerAparicion(const char* cad, const char* sub);
int compararNcaracteres(const char* cad, const char* sub,int cant_sub);
int  contarOcurrencias2_MIO(const char *cad, const char *sub);
char* CmpCadSubcad(const char* cad, const char* sub, int* cant);
char* incrementarPosicionesCad(const char* cad,int cant_elem);

///Ejercicio3


int  ordenarArchivo_MIO(const char *archEnt, const char *archSal);
int contarPalabras(const char* cad);
char* buscarInicioPalabra(const char* cad);
int tamPalabraMasGrande(const char* linea);

void crearPila_MIO(tPila *p);
int  pilaLlena_MIO(const tPila *p, unsigned cantBytes);
int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes);
int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes);
int  pilaVacia_MIO(const tPila *p);
int  sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes);
void vaciarPila_MIO(tPila *p);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/



#endif // FUNCIONES_H_
