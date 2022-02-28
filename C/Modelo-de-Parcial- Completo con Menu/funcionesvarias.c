#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionesvarias.h"

void fin_anormal(char *msj)
{
    if(*msj)
        printf("\n%s",msj);
    pausa("SE CANCELA EL PROCESO");
    exit(1);
}

void pausa(char *msj)
{
    if (*msj)
        printf("\n%s",msj);
    puts("\nPRESIONE -ENTER- PARA CONTINUAR...");
    fflush(stdin);
    scanf("%*c");
}

char menu(const char m[][TAM], const char *tit)
{
//  entrada: matriz de caracteres y título del menu
//  salida: opcion elegida por el usuario (CHAR)
    char op;    /* Variable que contiene la opción elegida por el usuario */
    op = pedir_opcion(m, tit, "Ingrese su opcion");
    while ( !strchr(m[0], op))  /* m[0] contiene las opciones,
                                se verifica sí la opción ingresada es válida */
        op = pedir_opcion(m, tit, "OPCION ERRONEA. Ingresela nuevamente");
    return op;
}

char pedir_opcion(const char m[][TAM], const char *tit, const char *msj)
{
//  Definición de Variables
    char op;
    int i;
//  Lógica
    system("CLS");
    printf("\n\n %s \n", tit); /* Imprime el título */
    for ( i=1 ; i <= strlen(m[0]) ; i++ )
    /* Imprime cada una de las líneas de opciones */
        printf("\n  %c.- %s", m[0][i-1], m[i]);
    printf("\n\n  %s: ", msj);  /* Imprime mensaje de entrada */
    fflush(stdin);  /* Limpia el buffer */
    scanf("%c", &op);   /* Lee la opción del teclado */
    return ( aMayusc(op) ); /* Devuelve la opción en mayúscula */
}


