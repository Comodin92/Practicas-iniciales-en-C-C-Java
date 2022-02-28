/**DADO UN ARCHIVO CREAR 3 ARCHIVOS APROBADOS, DESAPROBADOS Y PROMOCIONADOS**/
#include "funciones.h"

int main()
{
    crearArchivo1();/** creo una hoja de calculo**/

    FILE*pf=fopen(PRIMERO,"rb");
    FILE*pf2=fopen(SEGUNDO,"rb");
    FILE*pf_Aprobados=fopen(APROBADO,"w+b");
    FILE*pf_Desaprobados=fopen(DESAPROBADO,"w+b");
    FILE*pf_Promocionados=fopen(PROMOCIONADO,"w+b");
    if(!pf)
        exit(1);
    if(!pf2)
        exit(1);
    if(!pf_Aprobados)
        exit(3);
    if(!pf_Desaprobados)
        exit(3);
    if(!pf_Promocionados)
        exit(3);
    printf("\n\nArchivo 1:\n");
    mostrarArchivo(pf);
    printf("\n\nArchivo 2:\n");
    mostrarArchivo(pf2);
    rewind(pf);
    rewind(pf2);
    separarArchivos(pf,pf2,pf_Aprobados,pf_Desaprobados,pf_Promocionados);
    rewind(pf_Aprobados);
    printf("\n\nAprobados:\n");
    mostrarArchivo(pf_Aprobados);
    rewind(pf_Desaprobados);
    printf("\n\nDesaprobados:\n");
    mostrarArchivo(pf_Desaprobados);
    rewind(pf_Promocionados);
    printf("\n\nPromocionados 1:\n");
    mostrarArchivo(pf_Promocionados);
    fclose(pf);
    fclose(pf_Aprobados);
    fclose(pf_Desaprobados);
    fclose(pf_Promocionados);
    fclose(pf2);


    return 0;
}
