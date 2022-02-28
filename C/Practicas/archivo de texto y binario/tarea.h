#ifndef TAREA_H_INCLUDED
#define TAREA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char apellido[20];
    char nombre [20];
    double sueldo;
}t_empleado;

typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    float promedio;

}t_estudiante;

void crearLoteEmpleado();
void crearLoteEstudiante();
void mostrar_archivo_empleado();
void mostrar_archivo_estudiante();
void interseccion_entre_archivos();




#endif // TAREA_H_INCLUDED
