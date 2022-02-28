/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ NO DEBE HACER NINGUNA MODIFICACIÓN                         *//**/
/**//**//*      SÓLO PARA SUS PRUEBAS CON LOS DISTINTOS                   *//**/
/**//**//*      LOTES E INVOCAR A SUS FUNCIONES                           *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include "main.h"


int main()
{
    FILE   *fpPantalla;
#ifdef CODIGO_ALUMNO
    fpPantalla = fopen("pantalla.txt", "wt");
#else
    fpPantalla = fopen("pantallaBIEN.txt", "wt");
#endif
    if(fpPantalla == NULL)
        fpPantalla = stdout;

    punto_1_c(fpPantalla);


    fclose(fpPantalla);
#ifdef CODIGO_ALUMNO
    system("start Notepad pantalla.txt");
#else
    system("start Notepad pantallaBIEN.txt");
#endif
    return 0;
}


/** función: punto_1_c
 **
 **/
void punto_1_c(FILE *fpPantalla)
{
    tEvalua     nota;
    tListaDobl  lista;
    int         valDev = 0,
                nMejores = 7;
/// pruebe con  ^^^^^^^^^^^^^ diversas  nMejores  calificaciones

    crearListaDobl(&lista);
    fprintf(fpPantalla,
            "******************************************** \n"
            "*    Punto 1 c.-: comienza a ejecutarse.   * \n"
            "******************************************** \n");

    while(obtenerEvaluacion(&nota))
    {
        fprintf(fpPantalla, "Poniendo ...  ");
        mostrarNota(&nota, fpPantalla);
#ifdef PUNTO_1_C
        valDev = ponerEnListaDoblNCalif_MIO(&lista, &nota, sizeof(nota),
                                            nMejores);

#else
        valDev = ponerEnListaDoblNCalif(&lista, &nota, sizeof(nota),
                                        nMejores);
#endif
        fprintf(fpPantalla, "- La función devolvió %d.\n", valDev);
        valDev = mostrarListaD(&lista, mostrarNota, fpPantalla);
        fprintf(fpPantalla, "- Hay %d nodos.\n", valDev);
    }
    valDev = vaciarListaDobl(&lista);
    fprintf(fpPantalla,
            "Se eliminaron %d nodos de la lista.\n"
            "******************************************** \n"
            "*         Fin ejecución Punto 1 c.-        * \n"
            "******************************************** \n\n",
            valDev);
}

