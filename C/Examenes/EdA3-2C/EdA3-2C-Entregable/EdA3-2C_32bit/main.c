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

    punto_1_a(fpPantalla);

    punto_1_b(fpPantalla);


    fclose(fpPantalla);
#ifdef CODIGO_ALUMNO
    system("start Notepad pantalla.txt");
#else
    system("start Notepad pantallaBIEN.txt");
#endif
    return 0;
}


/** función: punto_1_a
 **
 **/
void punto_1_a(FILE *fpPantalla)
{
    tEvalua     nota;
    int         valDev = 0,
                nMejores = 1;
    tListaDobl  lista;

    crearListaDobl(&lista);
    fprintf(fpPantalla,
            "******************************************** \n"
            "*    Punto 1 a.-: comienza a ejecutarse.   * \n"
            "******************************************** \n");

    while(obtenerEvaluacion(&nota))
    {
        fprintf(fpPantalla, "Poniendo ...  ");
        mostrarNota(&nota, fpPantalla);
#ifdef PUNTO_1_A
        valDev = ponerEnListaDoblNMejores_MIO(&lista, &nota, sizeof(nota),
                                              nMejores);

#else
        valDev = ponerEnListaDoblNMejores(&lista, &nota, sizeof(nota),
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
            "*         Fin ejecución Punto 1 a.-        * \n"
            "******************************************** \n\n",
            valDev);
}

/** función: punto_1_b
 **
 **/
void punto_1_b(FILE *fpPantalla)
{
    tEvalua     nota;
    int         valDev = 0,
                nMejores = 2;
    tListaSimp  lista;

    crearListaSimp(&lista);
    fprintf(fpPantalla,
            "******************************************** \n"
            "*    Punto 1 b.-: comienza a ejecutarse.   * \n"
            "******************************************** \n");

    while(obtenerEvaluacion(&nota))
    {
        fprintf(fpPantalla, "Poniendo ...  ");
        mostrarNota(&nota, fpPantalla);
#ifdef PUNTO_1_B
        valDev = ponerEnListaSimpNMejores_MIO(&lista, &nota, sizeof(nota),
                                              nMejores);
#else
        valDev = ponerEnListaSimpNMejores(&lista, &nota, sizeof(nota),
                                          nMejores);
#endif
        fprintf(fpPantalla, "- La función devolvió %d.\n", valDev);
        valDev = mostrarListaS(&lista, mostrarNota, fpPantalla);
        fprintf(fpPantalla, "- Hay %d nodos.\n", valDev);
    }
    valDev = vaciarListaSimp(&lista);
    fprintf(fpPantalla,
            "Se eliminaron %d nodos de la lista.\n"
            "******************************************** \n"
            "*         Fin ejecución Punto 1 b.-        * \n"
            "******************************************** \n\n",
            valDev);
}

