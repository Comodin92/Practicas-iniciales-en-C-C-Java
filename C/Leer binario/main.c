#include <stdio.h>
#include <stdlib.h>
#define TAM 200
typedef struct
{
    int d,m,a;
}t_fecha;

typedef struct
{
    t_fecha fecha_nac;
    int edad;
    int dni;
    char nombre[TAM];
    char apellido[TAM];
    float nota1;
    float nota2;
}t_alumno;

typedef struct
{
    char materia[100];
    int anio;
    char docente[50];
    int codigo;
}tMateria;


int main()
{
    /**t_fecha fecha_nac;
    int edad;
    int dni;
    char nomre[TAM];
    char apellido[TAM];
    float nota1;
    float nota2;*/
    t_alumno alumno;
    tMateria materia;
    //char cadena[100];
    FILE* pf=fopen("MATERIAS.DAT","rb");
    if(!pf)
        exit(1);
    fread(&materia,sizeof(tMateria),1,pf);
    while(!feof(pf))
    {
       /* printf("%d/%d/%d | %d | %d | %s | %s | %f | %f\n",alumno.fecha_nac.d,
           alumno.fecha_nac.m,alumno.fecha_nac.a, alumno.edad, alumno.dni,alumno.nombre,
            alumno.apellido,alumno.nota1,alumno.nota2 );
            */
        printf("%s | %s |%d | %d\n",materia.materia,materia.docente,materia.anio,materia.codigo);

        fread(&materia,sizeof(tMateria),1,pf);

    }

    fclose(pf);
    return 0;
}
