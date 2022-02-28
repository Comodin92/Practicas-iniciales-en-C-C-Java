#ifndef EJERCICIOCADENAS_H_INCLUDED
#define EJERCICIOCADENAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 25
#define ES_LETRA(X)  (((X)<= 'Z' && (X)>= 'A') || ((X)<= 'z' && (X)>= 'a' ))
#define ES_BLANCO(X)   ((X) == ' ' || (X) == '\t')
#define ES_MAYUSCULA(X) ((X)>= 'A' && (X)<= 'Z')
#define ES_MINUSCULA(X) ((X)>= 'a' && (X)<= 'z')
#define A_MAYUSCULA(X) (ES_MAYUSCULA(X)? (X) : (X) - 32 )
#define A_MINUSCULA(X) (ES_MINUSCULA(X)? (X) : (X) + 32 )


char *strcpy_mia(char *cad1, const char* cad2 );
char* strcat_mio ( char* destino, const char* origen);
size_t strlen_mio ( const char* cad);
int normalizarCadena( char* cad);

int ocurrenciasConSolapa(const char *cadena , const char* subcadena);
int ocurrenciasSinSolapa(const char *cadena , const char* subcadena);
int atoi_mia(const char *cadNum);

int ordenamientoSelectivo(char *cad,
                          int (*cmp)(const void *d1, const void *d2));

int ordenamientoSelectivoInt(int *cadInt, int ce,
                             int (*cmpInt)(const void *d1, const void *d2),
                            void (*intercambio)(const void *da1, const void* da2));

 void ordenarSelecGenerico( void *vec, int ce, int size,
                             int (*cmpInt)(const void *d1, const void *d2),
                             void (*intercambio)(const void *da1, const void* da2)) ;
#endif // EJERCICIOCADENAS_H_INCLUDED
