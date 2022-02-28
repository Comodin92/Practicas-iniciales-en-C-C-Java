#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d;
    int m;
    int a;
}t_fecha;


typedef struct
{
    int nro_cuenta;
    t_fecha fecha;
    float sueldo;

}t_alumno;
#endif // ALUMNO_H_INCLUDED
