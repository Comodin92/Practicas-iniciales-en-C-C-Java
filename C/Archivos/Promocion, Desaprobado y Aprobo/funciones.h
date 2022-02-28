#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define PRIMERO "Primero.bin"
#define SEGUNDO "Segundo.bin"
#define APROBADO "Aprobados.bin"
#define DESAPROBADO "Desaprobado.bin"
#define PROMOCIONADO "Promocionado.bin"
#define TAM 20
#define ALU_PROMOCIONA(x) ((x) >= 7 )
#define ALU_APRUEBA(x) ((x) >= 4 && (x) <= 6 )
#define ALU_DESAPRUEBA(x) ((x) <= 4 )
typedef struct
{
    char nya[TAM];
    float nota1,
          nota2;
}tAlumno;


void crearArchivo1();
void crearArchivo2();
void mostrarArchivo(FILE* pf);
void separarArchivos(FILE* pf,FILE* pf2,FILE* pf_Aprobados,FILE* pf_Desaprobados,FILE* pf_Promocionados);



#endif // FUNCIONES_H_INCLUDED
