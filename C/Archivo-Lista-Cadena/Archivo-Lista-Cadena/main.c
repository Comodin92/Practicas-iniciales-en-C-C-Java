#include "../Bibiotlecas/archivos.h"
#include "../Bibiotlecas/vectores.h"
/**
Practica:
Crear un archivo con materias de ingenieria; separarlas por anio; crear 3 archivos alumnos con codigo de materias
aprobadas, decir que materias les falta para recibirse
mandar las materias aprobadas a un archivo de texto
una vez generado los 3 archivos txt, pasar los datos a una estructura e indicar el % de materias aprobadas y ordenarlos por
nombre de materia ignorand minusculas y mayusculas
**/
int main()
{
    t_alumno alumno1[]={{1023},
                        {1024},
                        {1025},
                        {1026},
                        {1027},
                        {1028},
                        {1029},
                        {1030},
                        {1031},
                        {1032},
                        {1033},
                        {1035},
                        {1108},
                        {1109},
                        {1110},
                        {1111},
                        {1112},
                        {1113},
                        {1114},
                        {1115},
                        {1116},
                        {1117},
                        {1118},
                        {1119},
                        {1120},
                        {1121},
                        {1122},
                        {1123},
                        {1124},
                        {1125},
                        {1126},
                        {1127},
                        {1129},
                        {1132},
                        {1133},
                        {1140},
                        {1141},
                        {1142},
                        {1136},
                        {1137}      },
    alumno2[]={
                        {1023},
                        {1024},
                        {1025},
                        {1026},
                        {1027},
                        {1028},
                        {1029},
                        {1112},
                        {1113},
                        {1114},
                        {1115},
                        {1116}
                },
    alumno3[]={
                        {1023},
                        {1024},
                        {1025},
                        {1026},
                        {1027},
                        {1028},
                        {1029}

    };
    t_ingenieria mat,mat_alu1,mat_alu2,mat_alu3;///,mat1,mat2,mat3,mat4,mat5;
    FILE *pf_r=NULL,*pf_1=NULL,*pf_2=NULL,*pf_3=NULL,*pf_4=NULL,*pf_5=NULL;


    crearArchivoAlumno(alumno1,"Alumno1.dat",40);
    crearArchivoAlumno(alumno2,"Alumno2.dat",12);
    crearArchivoAlumno(alumno3,"Alumno3.dat",7);

    printf("3 Archivos de alumnos creados\n\n");

    puts("******Archivo Materias*******\n");
    leerArchivo(pf_r,"Materias.dat",&mat);
    separaAnioArchivos(pf_r,pf_1,pf_2,pf_3,pf_4,pf_5,"Materias.dat");

    puts("*****Materias primer anio*****\n");
    leerArchivo(pf_1,"Primero.dat",&mat);

    puts("*****Materias Segundo anio*****\n");
    leerArchivo(pf_2,"Segundo.dat",&mat);

    puts("*****Materias Tercer anio*****\n");
    leerArchivo(pf_3,"Tercero.dat",&mat);

    puts("*****Materias Cuarto anio*****\n");
    leerArchivo(pf_4,"Cuarto.dat",&mat);

    puts("*****Materias Quinto anio*****\n");
    leerArchivo(pf_5,"Quinto.dat",&mat);

    printf("\n\n****ALUMNO 1*****\n");
    comparaAlumno1Materias("Alumno1.dat");

    printf("\n\n****ALUMNO 2*****\n");
    comparaAlumno2Materias("Alumno2.dat");

    printf("\n\n****ALUMNO 3*****\n");
    comparaAlumno3Materias("Alumno3.dat");





    return 0;
}
