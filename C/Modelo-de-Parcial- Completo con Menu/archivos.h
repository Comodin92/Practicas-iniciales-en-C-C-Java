#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#include "funciones.h"
#define PERS "PERSONA.BIN"
#define EMPLE "EMPLEADO.BIN"
#define CON_MSG 1
#define TAMAPYN 36

#define READ_TEXT         "rt"  //Abre un fichero de texto para lectura
#define WRITE_TEXT        "wt"  //Trunca, a longitud cero o crea un fichero de texto para escribir
#define READ_BIN          "rb"  //Abre un fichero en modo binario para lectura
#define WRITE_BIN         "wb"  //Trunca, a longitud cero o crea un fichero en modo binario para escribir
#define READ_TEXT_UPDATE  "r+t" //Abre un fichero de texto para actualización (lectura y escritura)
#define WRITE_TEXT_UPDATE "w+t" //Trunca, a longitud cero o crea un fichero de texto para actualización
#define READ_BIN_UPDATE   "r+b" //Abre un fichero en modo binario para actualización (lectura y escritura)
#define WRITE_BIN_UPDATE  "w+b" //Trunca, a longitud cero o crea un fichero en modo binario para actualización


#define PERSONA   "PERSONA.BIN"
#define DATOS     "DATOS.TXT"
#define EMPLEADO  "EMPLEADO.TXT"

int abrir_archivo(FILE **fp, const char *, const char *, int );
void mostrar_persona(const t_per *);

void cargar_archivo_texto_variable( FILE** , t_per *);
void cargar_archivo_binario_fijo( FILE**, t_per *);
void mostrar_archivo_binario_fijo( FILE**, t_per *);
void mostrar_archivo_texto_variable(FILE** , t_per*);

#endif // ARCHIVOS_H_INCLUDED
