/* Modelo de Parcial para Programacion 1 (Programacion II) v0.26 03/12/2015
   Este modelo implementa las funciones elementales del TP1, TP2, TP3, incluyendo muchas de parciales

   CAMBIOS:
   0.30 Habria que implementar algun ejemplo completo de TDA PILA, COLA LISTA y los menues
   No se implemento porque la promocione con 10
   0.26 Implemente muchas de matrices colgadas, decodificar y gregue las que faltaban de cadenas
   0.25 Implementacion de str_rchr y pruebas de todas las funciones
   0.24 Implementacion de funciones para mostrar y guardar binarios y texto y correcciones
   0.23 Implementacion de abs, max, y funciones de archivos binarios y de texto
   0.22 Correccion de todos los warnings, Implementacion de str_tok, str_spn, str_cspn, str_brk, str_cmpi, str_ncmp.
   0.21 Implementacion de desplazar_cadena, modificar_cadena, invertir_cadena, proxima_palabra, fin_palabra.
   0.20 Implementacion de esAlfanumerico, esPar, esImpar, pila circular y cola circular
   0.19 Correcion para que el Main de Arbol funcione y normalizacion de todas las funciones de los .h, .c
   0.15 Correcciones y cambio de estructura t_dato para que ARBOL funcione y muchos cambios de nombres de funciones
   0.10 Implementacion de ARBOL (t_nodo se diferencio de TDAs y TDA Arbol)
   0.7  Implementacion de Lista
   0.5  Implementacion de Cola Estatica y Dinamica y correccion de errores de Pila
   0.4  Implementacion de Pila Estatica y Dinamica
   0.3  Implementacion de Menues y cambios de estructuras.
   0.2  Implementacion de operaciones de Matrices y correccion de errores.
   0.1  Este proyecto me lo encontre con la Implementacion de Matematica, Fechas y Vectores.

   MATEMATICAS:
   .h:
   esPar, esImpar, abs, max
   .c:
    factorial, combinatorio, e_a_la_x, raizcuadrada, fibonacci, seno, clasificacion, multiplicacion,
    cocienteyresto, suma_primeros_naturales, suma_primeros_pares, suma_pares_menores, primo, multiplicacion_rusa,
    parte_entera.

   CADENAS:
   .h:
    esBlanco, esCaracter, aMayusc, aMinusc, esDigito, esAlfanumerico,
   .c:
    normalizar, reemplazar, cuentochar, anagrama, i_toa, a_toi, mem_move, mem_cpy, mem_cmp, strcat, str_cpy, str_lwr,
    str_upr, str_chr, str_str, str_cmp, str_len, to_lower, to_upper,desplazar_cadena, modificar_cadena,
    invertir_cadena, proxima_palabra, fin_palabra, str_tok, str_spn, str_cspn, str_brk, str_cmpi, str_ncmp,
    eliminarSubCad.

   VECTORES:
    tam, cargar_vector, mostrar_vector, insertar_en_pos, insertar_en_orden_vec, desplazamiento_derecha,
    desplazamiento_izquierda, eliminar_de_posicion, eliminar_1era_aparicion, eliminar_todas_apariciones.

   MATRICES:
   orden, cargar_matriz, mostrar_matriz, simetrica, identidad, suma_princ, suma_secund, suma_arriba_princ, suma_abajo_princ, suma_arriba_secund, suma_abajo_secund, transponer.

   FECHAS:
   .h:
    esBisiesto
   .c:
    es_fecha_valida, es_fecha_juliana_valida, ingresar_fecha, ingresar_fecha_juliana_valida, cant_dias_mes, dia_sig, sumar_dias,
    restar_dias, f_juliana, f_gregoriana, comp_fechas, dias_a, dif_fechas, dia_semana, t_fecha obtener_fecha_maq.

   PILA:
   Esta la implementacion estatica (s), dinamica (d) y circular (c)
    crear_pila_s, pila_llena_s, poner_en_pila_s, sacar_de_pila_s, ver_el_tope_s, pila_vacia_s, vaciar_pila_s.
    crear_pila_d, pila_llena_d, poner_en_pila_d, sacar_de_pila_d, ver_el_tope_d, pila_vacia_d, vaciar_pila_d.
    crear_pila_c, pila_llena_c, poner_en_pila_c, sacar_de_pila_c, ver_el_tope_c, pila_vacia_c, vaciar_pila_c.

   COLA:
   Esta la implementacion estatica (s), dinamica (d) y circular (c)
    crear_cola_s, cola_llena_s, cola_vacia_s, poner_en_cola_s, vaciar_cola_s, ver_primero_cola_s, sacar_de_cola_s.
    crear_cola_d, cola_llena_d, cola_vacia_d, poner_en_cola_d, vaciar_cola_d, ver_primero_cola_d, sacar_de_cola_d.
    crear_cola_c, cola_llena_c, cola_vacia_c, poner_en_cola_c, vaciar_cola_c, ver_primero_cola_c, sacar_de_cola_c.

   LISTA:
    crear_lista, lista_llena, lista_vacia, vaciar_lista, vaciar_lista_contarygrabar_en_arch, insertar_al_comienzo,
    insertar_al_final, insertar_en_orden_lista, buscar_en_lista_ordenada, buscar_en_lista_no_ordenada, ordenar_x_burbuja,
    eliminar_no_duplicados_lista_ordenada, eliminar_no_duplicados_lista_no_ordenada, eliminar_duplicados_lista_no_ordenada,
    eliminar_duplicados_lista_ordenada.

   ARBOL:
    mostrar_nodo_arbol, abrirArchivo, leerTxtEnArbol, en_orden, pre_orden, pos_orden, buscarR, crear_arbol, arbol_lleno,
    poner_en_arbol, eliminar_arbol, eliminar_arbol_y_contar, eliminar_arbol_y_contar_y_almacenar, eliminar_arbol_hasta_altura,
    eliminar_hojas, altura_arbol, contar_nodos_arbol, contar_nodos_hasta_altura, es_balanceado, es_completo,
    determinar_si_es_completo, determinar_si_es_balanceado, determinar_si_es_AVL, contar_hoja, contar_y_mostrar_hojas,
    contar_nodos_internos, contar_nodos_Internos_con_HD, contar_nodos_Internos_con_HI, contar_nodos_rama_I, contar_nodos_rama_D,
    contar_todos_nodos_con_HI, contar_todos_nodos_con_HD, contar_nodos_hasta_Hmenos1, contar_nodos_desdeH,
    mostrar_nodo_y_contar_de_H, contar_nodos_de_H, contar_nodos_rama_I, contar_nodos_rama_D, mostrar_losdeH, mostrar_hastaH,
    mostrar_desdeH, cargar_arbol_archivo_bin, insertar_en_arbol_recursivo.

FUNCIONA

   ARCHIVOS:
   abrir_archivo, mostrar_persona,cargar_archivo_texto_variable,
   cargar_archivo_binario_fijo, mostrar_archivo_binario_fijo,
   mostrar_archivo_texto_variable.

*/


#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"
#include "lista.h"
#include "funciones.h"
#include "lista_d.h"
#include "fechas.h"
#include "funcionesvarias.h"
#include "matematicas.h"
#include "matrices.h"
#include "vectores.h"
#include "cadenas.h"
#include "arbol.h"
#include "archivos.h"

#define SUPERTAM 100
int main()
{
    //Ejemplo de como Crear las funciones como variables
    //t_acu acu = &acumular;
    //t_cmp cmp = &comparar;


/*DEFINICION DE MENUES*/
    const char opciones[][TAM] = {"1234567S",
                                  "MATEMATICAS - ",
                                  "FECHAS      - ",
                                  "VECTORES    - ",
                                  "MATRICES    - ",
                                  "CADENAS     - ",
                                  "ARBOLES     - ",
                                  "ARCHIVOS    - ",
                                  "SALIR"};
    char op;
//  Lógica
    do
    {
        op = menu(opciones, "MENU DE FUNCIONES");
        switch(op)
        {
            case '1':menu_math();break;
            case '2':menu_fecha();break;
            case '3':menu_vect();break;
            case '4':menu_mat();break;
            case '5':menu_cad();break;
            case '6':menu_arb();break;
            case '7':menu_arch();break;
        }
    } while ( op != 'S' );
    return 0;
}
///FUNCIONES DE MENU
void menu_math()
{
    char OP;
    const char OPCIONES[][TAM]={"12345VS",
                                "FACTORIAL",
                                "COMBINATORIO",
                                "EXPONENCIAL",
                                "RAIZ CUADRADA",
                                "SENO",
                                "VOLVER","SALIR"};
    do
    {
        OP=menu(OPCIONES,"Grupo de Ejercicios de Calculos Matematicos");
                        switch(OP)
                        {
                            case '1':ej1_factorial();break;
                            case '2':ej2_combinatorio();break;
                            case '3':ej3_exponencial();break;
                            case '4':ej4_raiz();break;
                            case '5':ej5_seno();break;
                            case 'S':exit(0);
                        }
    }while(OP!='V');
}
void menu_fecha()
{
    char OP;
    const char OPCIONES[][TAM]={"12345VS",
                                "SUMAR DIAS",
                                "RESTAR DIAS",
                                "COMPARAR FECHAS",
                                "DIFERENCIA DIAS ENTRE FECHAS",
                                "DIA DE LA SEMANA",
                                "VOLVER","SALIR"};
    do
    {
        OP=menu(OPCIONES,"Grupo de Ejercicios de Fecha");
                        switch(OP)
                        {   case '1':ej_sumar_dias();break;
                            case '2':ej_restar_dias();break;
                            case '3':ej_compara_fechas();break;
                            case '4':ej_dif_entre_fechas();break;
                            case '5':ej_dia_sem();break;
                            case 'S':exit(0);
                        }
    }while(OP!='V');
}
void menu_vect()
{
    char OP;
    const char OPCIONES[][TAM]={"12345VS",
                                "INSERTAR EN POSICION",
                                "INSERTAR EN ORDEN",
                                "ELIMINAR DE POSICION",
                                "ELIMINAR PRIMERA APARICION",
                                "ELIMINAR TODAS LAS APARICIONES",
                                "VOLVER","SALIR"};
    do
    {
        OP=menu(OPCIONES,"Grupo de Ejercicios de Vectores");
                        switch(OP)
                        {
                            case '1':ej_insertar();break;
                            case '2':ej_insertar_ordenadamente();break;
                            case '3':ej_eliminar();break;
                            case '4':ej_eliminar_una_vez();break;
                            case '5':ej_eliminar_siempre();break;
                            case 'S':exit(0);
                        }
    }while(OP!='V');
}
void menu_mat()
{
    char OP;
    const char OPCIONES[][TAM]={"123456789VS",
                                "SIMETRICA",
                                "TRASPONER",
                                "IDENTIDAD",
                                "SUMA DIAGONAL PRINCIPAL",
                                "SUMA DIAGONAL SECUNDARIA",
                                "SUMA SUP DIAGONAL PRINCIPAL",
                                "SUMA SUP DIAGONAL SECUNDARIA",
                                "SUMA INF DIAGONAL PRINCIPAL",
                                "SUMA INF DIAGONAL SECUNDARIA",
                                "VOLVER","SALIR"};
    do
    {
        OP=menu(OPCIONES,"Grupo de Ejercicios de Matrices");
                        switch(OP)
                        {
                            case '1':ej_simetrica();break;
                            case '2':ej_transponer();break;
                            case '3':ej_identidad();break;
                            case '4':ej_suma_diag();break;
                            case '5':ej_suma_diag_sec();break;
                            case '6':ej_suma_sup_diag();break;
                            case '7':ej_suma_sup_diag_sec();break;
                            case '8':ej_suma_inf_ppal();break;
                            case '9':ej_suma_inf_sec();break;
                            case 'S':exit(0);
                        }
    }while(OP!='V');
}
void menu_cad()
{
    char OP;
    const char OPCIONES[][TAM]={"123456789ABCDEFGHVS",
                                "PALINDROMO",
                                "NORMALIZAR",
                                "ANAGRAMA",
                                "ATOI NUM  - CHAR ",
                                "ITOA CHAR - NUM ",
                                "COMPARAR CADENAS",
                                "COPIAR CADENAS",
                                "MINUSCULAS",
                                "MAYUSCULAS",
                                "BUSCAR CHAR EN CADENA",
                                "BUSCAR CADENA EN CADENA",
                                "LONG CADENA",
                                "REEMPLAZAR CADENAS",
                                "CONCATENAR CADENAS",
                                "ENCRIPTAR CADENA",
                                "TROZAR CADENA CON UN CHAR",
                                "ELIMINAR DE CADENA SUBCAD",
                                "VOLVER","SALIR"};
    do
    {
        OP=menu(OPCIONES,"Grupo de Ejercicios de Cadenas");
                        switch(OP)
                        {
                            case '1':ej_palindromo();break;
                            case '2':ej_normalizar();break;
                            case '3':ej_anagrama();break;
                            case '4':ej_atoi();break;
                            case '5':ej_itoa();break;
                            case '6':ej_str_cmp();break;
                            case '7':ej_str_cpy();break;
                            case '8':ej_str_lwr();break;
                            case '9':ej_str_upr();break;
                            case 'A':ej_str_chr();break;
                            case 'B':ej_str_str();break;
                            case 'C':ej_str_len();break;
                            case 'D':ej_reemplazar();break;
                            case 'E':ej_str_cat();break;
                            case 'F':ej_encriptar();break;
                            case 'G':ej_str_tok();break;
                            case 'H':ej_eliminarSubCad();break;
                            case 'I':ej_ejercicio8();break;
                            case 'S':exit(0);
                        }
    }while(OP!='V');
}
void menu_arb()
{
    t_arbol arbol;
    t_info info;
    FILE*pf;
    int contHojas=0;
    int contNodosInt = 0;
    int cantNodos = 0;
    int contNodosHD=0;
    int contNodosHI=0;
    int nodosConHI =0;
    int nodosConHD =0;
    int altura, h;
    int nodosHastaHM1 = 0;
    int nodosDesdeH = 0;
    int nodosEnH = 0;
    int nodosEnH2 = 0;
    int cantNodosRI = 0;
    int cantNodosRD = 0;
    char OP;
    t_cmp cmp = &comparar;

    const char OPCIONES[][TAM]={"123456789ABCDEFGHIJKLMNOPQVS",
                                "CREAR ARBOL",                      /*1*/
                                "CARGAR ARBOL DE ARCHIVO",          /*2*/
                                "RECORRER EN PRE_ORDEN",            /*3*/
                                "RECORRER EN IN_ORDEN",             /*4*/
                                "RECORRER EN POS_ORDEN",            /*5*/
                                "MOSTRAR Y CONTAR HOJAS",           /*6*/
                                "MOSTRAR NODOS INTERNOS",           /*7*/
                                "MOSTRAR NODOS INTERNOS CON HD",    /*8*/
                                "MOSTRAR NODOS INTERNOS CON HI",    /*9*/
                                "MOSTRAR NODOS QUE TIENEN HI",      /*A*/
                                "MOSTRAR NODOS QUE TIENEN HD",      /*B*/
                                "ALTURA DE ARBOL",                  /*C*/
                                "MOSTRAR NODOS DE UNA H",           /*D*/
                                "MOSTRAR NODOS HASTA UNA H",        /*E*/
                                "MOSTRAR NODOS DESDE UNA H",        /*F*/
                                "CANTIDAD DE NODOS HASTA H",        /*G*/
                                "CANTIDAD DE NODOS DESDE H",        /*H*/
                                "CANTIDAD DE NODOS EN H",           /*I*/
                                "VER Y CANT. DE NODOS EN H",        /*J*/
                                "CANTIDAD TOTAL DE NODOS",          /*K*/
                                "CANTIDAD DE NODOS EN RI",          /*L*/
                                "CANTIDAD DE NODOS EN RD",          /*M*/
                                "VER SI ARBOL ES COMPLETO",         /*N*/
                                "VER SI ARBOL ES BALANCEADO",       /*O*/
                                "VER SI ARBOL ES AVL",              /*P*/
                                "ELIMINAR HOJAS",                   /*Q*/
                                "VOLVER","SALIR"};                  /*V*//*S*/
    do
    {
        OP=menu(OPCIONES,"Grupo de Ejercicios de Arbol");
                        switch(OP)
                        {
                            case '1':crear_arbol(&arbol);pausa("");break;
                            case '2':if(abrirArchivo(&pf,"ARBOL.TXT","r",1))
                                     {
                                        leerTxtEnArbol(pf,&info,&arbol,cmp);
                                        fclose(pf);
                                     }pausa("");break;
                            case '3':pre_orden(&arbol);pausa("");break;
                            case '4':en_orden(&arbol);pausa("");break;
                            case '5':pos_orden(&arbol);pausa("");break;
                            case '6':contHojas = contar_y_mostrar_hojas(&arbol);
                                     printf("La cantidad de hojas es: %d\n", contHojas);pausa("");break;
                            case '7':contNodosInt = contar_nodos_internos(&arbol);
                                     printf("La cantidad de nodos internos es: %d\n", contNodosInt);pausa("");break;
                            case '8':contNodosHD = contar_nodos_Internos_con_HD(&arbol);
                                     printf("La cantidad de nodos internos con hijos derechos es: %d\n",contNodosHD);pausa("");break;
                            case '9':contNodosHI = contar_nodos_Internos_con_HI(&arbol);
                                     printf("La cantidad de nodos internos con hijos izquierdos es: %d\n",contNodosHI);pausa("");break;
                            case 'A':nodosConHI = contar_todos_nodos_con_HI(&arbol);
                                     printf("La cantidad de nodos que tienen hijos izquierdos es: %d\n",nodosConHI);pausa("");break;
                            case 'B':nodosConHD = contar_todos_nodos_con_HD(&arbol);
                                     printf("La cantidad de nodos que tienen hijos derechos es: %d\n",nodosConHD);pausa("");break;
                            case 'C':altura = altura_arbol(&arbol);
                                     printf("La altura del arbol es: %d\n", altura);
                                     printf("El nivel del arbol es: %d\n", altura-1);pausa("");break;
                            case 'D':printf("Ingrese la altura: ");
                                     fflush(stdin);
                                     scanf("%d", &h);
                                     mostrar_losdeH(&arbol, h);pausa("");break;
                            case 'E':printf("Ingrese la altura: ");
                                     fflush(stdin);
                                     scanf("%d", &h);
                                     mostrar_hastaH(&arbol, h);pausa("");break;
                            case 'F':printf("Ingrese la altura: ");
                                     fflush(stdin);
                                     scanf("%d", &h);
                                     mostrar_desdeH(&arbol, h);pausa("");break;
                            case 'G':printf("Ingrese la altura: ");
                                     fflush(stdin);
                                     scanf("%d", &h);
                                     nodosHastaHM1=contar_nodos_hasta_Hmenos1(&arbol, h);
                                     printf("La cantidad de nodos hasta la altura %d (sin incluirla) es: %d\n", h, nodosHastaHM1);pausa("");break;
                            case 'H':printf("Ingrese la altura: ");
                                     fflush(stdin);
                                     scanf("%d", &h);
                                     nodosDesdeH = contar_nodos_desdeH(&arbol, h);
                                     printf("La cantidad de nodos desde la altura %d es: %d\n", h, nodosDesdeH);pausa("");break;
                            case 'I':printf("Ingrese la altura: ");
                                     fflush(stdin);
                                     scanf("%d", &h);
                                     nodosEnH = contar_nodos_de_H(&arbol, h);
                                     printf("La cantidad de nodos en la altura %d es: %d\n", h, nodosEnH);pausa("");break;
                            case 'J':printf("Ingrese la altura: ");
                                     fflush(stdin);
                                     scanf("%d", &h);
                                     nodosEnH2 = mostrar_nodo_y_contar_de_H(&arbol, h);
                                     printf("La cantidad de nodos en la altura %d es: %d\n", h, nodosEnH2);pausa("");break;
                            case 'K':cantNodos = contar_nodos_arbol(&arbol);
                                     printf("La cantidad de nodos totales es: %d", cantNodos);pausa("");break;
                            case 'L':cantNodosRI = contar_nodos_rama_I(&arbol);
                                     printf("La cantidad de nodos en la rama izquierda es: %d", cantNodosRI);pausa("");break;
                            case 'M':cantNodosRD = contar_nodos_rama_D(&arbol);
                                     printf("La cantidad de nodos en la rama derecha es: %d", cantNodosRD);pausa("");break;
                            case 'N':if(es_completo(&arbol))
                                        printf("Es arbol completo");
                                    else
                                        printf("No es arbol completo");pausa("");break;
                            case 'O':if(es_balanceado(&arbol))
                                        printf("Es arbol balanceado");
                                    else
                                        printf("no es arbol balanceado");pausa("");break;
                            case 'P':if(determinar_si_es_AVL(&arbol))
                                        printf("Es AVL");
                                    else
                                        printf("no es arbol AVL");pausa("");break;
                            case 'Q':eliminar_hojas(&arbol);pausa("");break;
                            case 'S':eliminar_arbol(&arbol);exit(0);
                        }
    }while(OP!='V');
    eliminar_arbol(&arbol);
}

void menu_arch()
{
    char OP;
    const char OPCIONES[][TAM]={"1234VS",
                                "CARGAR ARCHIVO TEXTO VARIABLE",
                                "CARGAR ARCHIVO BINARIO FIJO",
                                "MOSTRAR ARCHIVO TEXTO VARIABLE",
                                "MOSTRAR ARCHIVO BINARIO FIJO",
                                "VOLVER","SALIR"};
    do
    {
        OP=menu(OPCIONES,"Grupo de Ejercicios de Archivos");
                        switch(OP)
                        {
                            case '1': ej_cargar_archivo_texto_variable();break;
                            case '2': ej_cargar_archivo_binario_fijo();break;
                            case '3': ej_mostrar_archivo_texto_variable();break;
                            case '4': ej_mostrar_archivo_binario_fijo();break;
                            case 'S': exit(0);
                        }
    }while(OP!='V');
}

///FUNCIONES DE EJECUCION DE CADA MENU
void ej1_factorial()
{
    int ent1;
    double result_d;
    do
    {
    system("CLS");
    printf("Ingrese entero al que se le quiere hacer el factorial: ");
    fflush(stdin);
    scanf("%d",&ent1);
    } while (ent1 < 0);
    result_d = factorial(ent1);
    printf("\n\nEl factorial de %d es %.0f", ent1, result_d);
    pausa("");
}
void ej2_combinatorio()
{
    int result_i, ent2, ent1;
    do {  //COMBINATORIO
    system("CLS");
    printf("Combinatorio de m sobre n\n");
    printf("\nIngrese n: ");
    fflush(stdin);
    scanf("%d",&ent2);
    } while (ent2 < 0);
    do {
    system("CLS");
    printf("Combinatorio de m sobre n\n");
    printf("\nIngrese n: %d", ent2);
    printf("\nIngrese m: ");
    fflush(stdin);
    scanf("%d",&ent1);
    } while (ent1 < ent2);
    result_i = combinatorio(ent1, ent2);
    printf("\n\nEl combinatorio de %d sobre %d es %d", ent1, ent2, result_i);
    pausa("");
}
void ej3_exponencial()
{
    int ent1;
    float tol;
    double result_d;
    do {  //e A LA x
    system("CLS"); printf("e a la x\n");
    printf("\nIngrese tolerancia: ");
    fflush(stdin);
    scanf("%f",&tol);
    } while (tol < 0 || tol > 1);
    printf("\nIngrese exponente: ");
    fflush(stdin);
    scanf("%d",&ent1);
    result_d = e_a_la_x(ent1, tol);
    printf("\n\nEl resultado de e a la %d con una tolerancia de %f es %f", ent1, tol, result_d);
    pausa("");
}
void ej4_raiz()
{
    float result_f, flo1, tol;
    do {  //RAIZ CUADRADA
    system("CLS"); printf("Raiz Cuadrada de x\n");
    printf("\nIngrese tolerancia: ");
    fflush(stdin);
    scanf("%f",&tol);
    } while (tol < 0 || tol > 1);
    printf("\nIngrese x: ");
    fflush(stdin);
    scanf("%f",&flo1);
    result_f = raizcuadrada(flo1, tol);
    printf("\n\nLa raiz cuadrade de %f con una tolerancia de %f es %f", flo1, tol, result_f);
    pausa("");
}
void ej5_seno()
{
    float result_f, flo1, tol;
    do {  //SENO
    system("CLS"); printf("Seno de x\n");
    printf("\nIngrese tolerancia: ");
    fflush(stdin);
    scanf("%f",&tol);
    } while (tol < 0 || tol > 1);
    printf("\nIngrese x: ");
    fflush(stdin);
    scanf("%f",&flo1);
    result_f = seno(flo1, tol);
    printf("\n\nEl seno de %f con una tolerancia de %f es %f", flo1, tol, result_f);
    pausa("");
}
void ej_sumar_dias()
{
    t_fecha f1;
    int i;
    system("CLS");
    ingresar_fecha(&f1);
    printf("Ingrese los días a sumar: ");
    scanf("%d",&i);
    sumar_dias(&f1,i);
    printf("\n\nLa fecha sumada %d dias es %02d/%02d/%04d", i, f1.di, f1.me, f1.an);
    pausa("");
}
void ej_restar_dias()
{
    t_fecha f1;
    int i;
    system("CLS");
    ingresar_fecha(&f1);
    printf("Ingrese los días a restar: ");
    scanf("%d",&i);
    restar_dias(&f1,i);
    printf("\n\nLa fecha restada %d dias es %02d/%02d/%04d", i, f1.di, f1.me, f1.an);
    pausa("");
}
void ej_compara_fechas()
{
    t_fecha f1, f2;
    int i;
    system("CLS");
    printf("Comparacion de fechas\n\nPrimer Fecha:");
    ingresar_fecha(&f1);
    printf("\nSegunda Fecha:");
    ingresar_fecha(&f2);
    i = comp_fechas(&f1, &f2);
    if (i == -1)
        printf("\n\nLa fecha %02d/%02d/%04d es MENOR a la fecha %02d/%02d/%04d", f1.di, f1.me, f1.an, f2.di, f2.me, f2.an);
    else
    {
        if (i == 1)
            printf("\n\nLa fecha %02d/%02d/%04d es MAYOR a la fecha %02d/%02d/%04d", f1.di, f1.me, f1.an, f2.di, f2.me, f2.an);
        else
            printf("\n\nLas fechas %02d/%02d/%04d y %02d/%02d/%04d son IGUALES", f1.di, f1.me, f1.an, f2.di, f2.me, f2.an);
    }
    pausa("");
}
void ej_dif_entre_fechas()
{
    t_fecha f1, f2;
    int i;
    system("CLS");
    printf("Diferencia de dias entre fechas\n\nPrimer Fecha:");
    ingresar_fecha(&f1);
    printf("\nSegunda Fecha:");
    ingresar_fecha(&f2);
    i = dif_fechas(&f1, &f2);
    printf("\n\nLa diferencia de dias entre %02d/%02d/%04d y %02d/%02d/%04d es %d", f1.di, f1.me, f1.an, f2.di, f2.me, f2.an, i);
    pausa("");
}
void ej_dia_sem()
{
    char dias[7][10] = {"DOMINGO", "LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO"};
    t_fecha f1;
    int i;
    system("CLS");
    printf("Dia de la semana");
    ingresar_fecha(&f1);
    i = dia_semana(&f1);
    printf("\n\nEl dia de la semana de la fecha %02d/%02d/%04d es %s", f1.di, f1.me, f1.an, dias[i]);
    pausa("");
}
void ej_insertar()
{
    // Insertar elmento en posición de un arreglo de enteros
    int elem, pos, v1[TAMM], t;
    system("CLS");
    printf("Insertar elmento en posicion de un arreglo de enteros\n\n");
    fflush(stdin);
    t=insertar_tamanio_vector();
    cargar_vector(&v1[0],t);
    printf("Ingrese el elemento: ");
    fflush(stdin);
    scanf("%d", &elem);
    printf("Ingrese la posicion en donde insertar el elemento: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nVector Original\n");
    mostrar_vector(&v1[0],t);
    insertar_en_pos(&v1[0], pos, elem);
    printf("\nVector Modificado\n");
    mostrar_vector(&v1[0],t + 1);
    pausa("");
}
void ej_insertar_ordenadamente()
{
    // Insertar elmento en orden ascendente de un arreglo de enteros
    int elem, v1[TAMM], t;
    system("CLS"); printf("Insertar elmento en orden dentro de un arreglo de enteros\n\n");
    fflush(stdin);
    t=insertar_tamanio_vector();
    cargar_vector(&v1[0],t);
    printf("Ingrese el elemento: ");
    fflush(stdin);
    scanf("%d", &elem);
    printf("\nVector Original\n");
    mostrar_vector(&v1[0],t);
    insertar_en_orden_vec(v1, elem, t);
    printf("\nVector Modificado\n");
    mostrar_vector(&v1[0],t + 1);
    pausa("");
}
void ej_eliminar()
{
    // Elimina un elemento de un arreglo de enteros dada la posición
    int pos, v1[TAMM], t;
    system("CLS");
    printf("Elimina un elemento de un arreglo de enteros dada la posicion\n\n");
    fflush(stdin);
    t=insertar_tamanio_vector();
    cargar_vector(&v1[0],t);
    printf("Ingrese la posicion del elemento a borrar: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nVector Original\n");
    mostrar_vector(&v1[0],t);
    eliminar_de_posicion(v1, pos, t);
    printf("\nVector Modificado\n");
    mostrar_vector(&v1[0],t - 1);
    pausa("");
}
void ej_eliminar_una_vez()
{
    // Elimina la primera aparición de un elemento en un arreglo
    //de enteros
    int elem, v1[TAMM], t;
    system("CLS");
    printf("Elimina la primera aparicion de un elemento en un arreglo de enteros\n\n");
    fflush(stdin);
    t=insertar_tamanio_vector();
    cargar_vector(&v1[0],t);
    printf("Ingrese el elemento a borrar: ");
    fflush(stdin);
    scanf("%d", &elem);
    printf("\nVector Original\n");
    mostrar_vector(&v1[0],t);
    eliminar_1era_aparicion(&v1[0], elem, t);
    printf("\nVector Modificado\n");
    mostrar_vector(&v1[0],t - 1);
    pausa("");
}
void ej_eliminar_siempre()
{
    // Elimina todas las apariciones de un elemento en un arreglo
    //de enteros
    int elem, v1[TAMM], t, x;
    system("CLS");
    printf("Elimina todas las apariciones de un elemento en un arreglo de enteros\n\n");
    fflush(stdin);
    t=insertar_tamanio_vector();
    cargar_vector(&v1[0],t);
    printf("Ingrese el elemento a borrar: ");
    fflush(stdin);
    scanf("%d", &elem);
    printf("\nVector Original\n");
    mostrar_vector(&v1[0],t);
    x = eliminar_todas_apariciones(v1, elem, t);
    printf("\nVector Modificado\n");
    mostrar_vector(&v1[0],t - x);
    pausa("");
}
void ej_simetrica()
{
    int result, ord, m[TAMM][TAMM];
    system("CLS"); printf("Matriz Simetrica\n\n");
    fflush(stdin);
    ord=orden();
    cargar_matriz(&m[0][0],ord);
    printf("Matriz Original\n\n");
    mostrar_matriz(&m[0][0],ord);
    result = simetrica(&m[0][0],ord);
    if(result==1)
        printf("\nLa matriz es simetrica");
    else
        printf("\nLa matriz NO es simetrica");
    pausa("");
}
void ej_transponer()
{
    // TRANSPONER
    int ord, m[TAMM][TAMM];
    system("CLS"); printf("Trasponer matriz\n\n");
    fflush(stdin);
    ord=orden();
    cargar_matriz(&m[0][0],ord);
    printf("Matriz Original\n\n");
    mostrar_matriz(&m[0][0],ord);
    transponer(&m[0][0],ord);
    printf("\nMatriz Transpuesta\n\n");
    mostrar_matriz(&m[0][0],ord);
    pausa("");
}
void ej_identidad()
{
    // IDENTIDAD
    int result, ord, m[TAMM][TAMM];
    system("CLS");
    printf("Matriz Identidad\n\n");
    fflush(stdin);
    ord=orden();
    cargar_matriz(&m[0][0],ord);
    printf("Matriz Original\n\n");
    mostrar_matriz(&m[0][0],ord);
    result=identidad(&m[0][0],ord);
        if(result==1)
            printf("\nMatriz identidad");
        else
            printf("\nMatriz no es de identidad");
    pausa("");
}
void ej_suma_diag()
{
    // SUMA DIAGONAL PRINCIPAL
    int ord, m[TAMM][TAMM];
    system("CLS");
    printf("Suma diagonal principal\n\n");
    fflush(stdin);
    ord=orden();
    cargar_matriz(&m[0][0],ord);
    printf("Matriz Original\n\n");
    mostrar_matriz(&m[0][0],ord);
    printf("\nLa suma de la diagonal principal es %d", suma_princ(&m[0][0],ord));
    pausa("");
}
void ej_suma_diag_sec()
{
    // SUMA DIAGONAL SECUNDARIA
    int ord, m[TAMM][TAMM];
    system("CLS");
    printf("Suma diagonal secundaria\n\n");
    fflush(stdin);
    ord=orden();
    cargar_matriz(&m[0][0],ord);
    printf("Matriz Original\n\n");
    mostrar_matriz(&m[0][0],ord);
    printf("\nLa suma de la diagonal secundaria es %d", suma_secund(&m[0][0],ord));
    pausa("");
}
void ej_suma_sup_diag()
{
    // SUMA ELEMENTOS POR ENCIMA DE LA DIAGONAL PRINCIPAL
    int ord, m[TAMM][TAMM];
    system("CLS");
    printf("Suma de elementos por encima de la diagonal principal\n\n");
    fflush(stdin);
    ord=orden();
    cargar_matriz(&m[0][0],ord);
    printf("Matriz Original\n\n");
    mostrar_matriz(&m[0][0],ord);
    printf("\nLa suma de los elementos que estan por encima de la diagonal principal es %d",suma_arriba_princ(&m[0][0],ord));
    pausa("");
}
void ej_suma_sup_diag_sec()
{
    // SUMA ELEMENTOS POR ENCIMA DE LA DIAGONAL SECUNDARIA
    int ord, m[TAMM][TAMM];
    system("CLS");
    printf("Suma de elementos por encima de la diagonal secundaria\n\n");
    fflush(stdin);
    ord=orden();
    cargar_matriz(&m[0][0],ord);
    printf("Matriz Original\n\n");
    mostrar_matriz(&m[0][0],ord);
    /**suma_arriba_secund_gen(&m[0][0],ord,ord));*/
    printf("\nLa suma de los elementos que estan por encima de la diagonal Secundaria es %d",suma_arriba_secund(&m[0][0],ord));
    pausa("");
}
void ej_suma_inf_ppal()
{
    // SUMA ELEMENTOS POR DEBAJO DE LA DIAGONAL PRINCIPAL
    int ord, m[TAMM][TAMM];
    system("CLS");
    printf("Suma de elementos por debajo de la diagonal principal\n\n");
    fflush(stdin);
    ord=orden();
    cargar_matriz(&m[0][0],ord);
    printf("Matriz Original\n\n");
    mostrar_matriz(&m[0][0],ord);
    printf("\nLa suma de los elementos que estan por debajo de la diagonal principal es %d",suma_abajo_princ(&m[0][0],ord));
    pausa("");
}
void ej_suma_inf_sec()
{
    //SUMA ELEMENTOS POR DEBAJO DE LA DIAGONAL SECUNDARIA
    int ord, m[TAMM][TAMM];
    system("CLS");
    printf("Suma de elementos por debajo de la diagonal secundaria\n\n");
    fflush(stdin);
    ord=orden();
    cargar_matriz(&m[0][0],ord);
    printf("Matriz Original\n\n");
    mostrar_matriz(&m[0][0],ord);
    printf("\nLa suma de los elementos que estan por abajo de la diagonal secundaria es %d",suma_abajo_secund(&m[0][0],ord));
    pausa("");
}
void ej_palindromo()
{
    char texto[TAM];
    printf("Ingrese texto: ");
    fflush(stdin);
    gets(texto);
        if(palindromo(texto))
        printf("\n\tEs Palindromo");
    else
        printf("\n\tNo es Palindromo");

    pausa("");
}

void ej_normalizar()
{
    //Normaliza una cadena con o sin espacios de cualquier cantidad
    //poniendo mayuscula al principio y lo demas con minusculas
    char texto[TAM];
    printf("Ingrese texto: ");
    fflush(stdin);
    gets(texto);
    normalizar(texto);
    printf("%s",texto); //No va &texto
    pausa("");
}
void ej_anagrama()
{
    char cadena1[TAM],
         cadena2[TAM];
    printf("\n\tIngresar 1er Cadena: ");
    fflush(stdin);
    gets(cadena1);
    printf("\n\tIngresar 2da Cadena: ");
    fflush(stdin);
    gets(cadena2);
    printf("\n\t");
    puts(cadena1);
    printf("\n\t");
    puts(cadena2);
    if(anagrama(cadena1,cadena2))
        printf("\n\tEs Anagrama");
    else
        printf("\n\tNo es Anagrama");
    pausa("");
}
void ej_atoi()
{
    printf("\tUtilizando atoi creo numeros con cadenas");
    char cadena [TAM];
    int num;
    printf("\n\tIngrese una cadena de enteros");
    fflush(stdin);
    gets(cadena);
    num = a_toi(cadena);
    printf("\n\tLa cadena numerica ingresada es : %d",num);
    pausa("");
}
void ej_itoa()
{
    printf("\tUtilizando itoa creo cadena con numeros");
    char ar[10];
    int n,
        base;
    printf("\n\tIngrese el numero y la base a la que desea convertir");
    scanf("%d%d",&n,&base);
    i_toa(n,ar,base);
    printf("\tEl numero ((%d)) convertido a la base es ((%s))",n,ar);
    pausa("");
}
void ej_str_cmp()
{
    printf("\tUtilizando str_cmp comparo cadenas");
    char cadena1 [TAM];
    char cadena2 [TAM];
    printf("\n\tIngrese datos en primer cadena: ");
    fflush(stdin);
    gets(cadena1);
    printf("\n\tIngrese datos en segunda cadena: ");
    fflush(stdin);
    gets(cadena2);
    if (! str_cmp(cadena1,cadena2) )
        printf("\n\tSon Iguales");
    else
        printf("\n\tSon distintas");
    pausa("");
}
void ej_str_cpy()
{
    printf("\tUtilizando str_cpy copio cadena y caracter nulo");
    char cadena1 [TAM];
    char cadena2 [TAM];
    printf("\n\tIngrese datos en primer cadena: ");
    fflush(stdin);
    gets(cadena1);
    str_cpy(cadena2,cadena1);
    printf("\nCadena 1: ");
    puts(cadena1);
    printf("\nCadena 2: ");
    puts(cadena2);
    pausa("");
}
void ej_str_lwr()
{
    printf("\tUtilizando str_lwr y to_lower hago minusculas todo cadena");
    char cadena [TAM];
    printf("\n\tIngrese datos en cadena: ");
    fflush(stdin);
    gets(cadena);
    str_lwr(cadena);
    puts(cadena);
    pausa("");
}
void ej_str_upr()
{
    printf("\tUtilizando str_upr y to_upper hago mayusculas todo cadena");
    char cadena [TAM];
    printf("\n\tIngrese datos en cadena: ");
    fflush(stdin);
    gets(cadena);
    str_upr(cadena);
    puts(cadena);
    pausa("");
}
void ej_str_chr()
{
    printf("\tUtilizando str_chr comparo ocurrencias de caracter en cadena");
    char cadena [TAM];
    char caracter;
    printf("\n\tingrese datos en cadena: ");
    fflush(stdin);
    gets(cadena);
    printf("\tIngrese caracter a buscar: ");
    fflush(stdin);
    scanf("%c",&caracter);
    if ( str_chr(cadena,caracter) )
        printf("\tEl caracter buscado se encontro");
    else
        printf("\tEl caracter buscado no se encontro");
    pausa("");
}
void ej_str_str()
{
    printf("\tUtilizando str_str comparo ocurrencias de cadena2 en cadena 1");
    char cadena1 [TAM],
         cadena2 [TAM];
    printf("\n\tIngrese datos en cadena1: ");
    fflush(stdin);
    gets(cadena1);
    printf("\tIngrese datos en cadena2: ");
    fflush(stdin);
    gets(cadena2);
    if (str_str(cadena1,cadena2))
        printf("\tLa cadena buscada se encontro");
    else
        printf("\tLa cadena buscada no se encontro");
    pausa("");
}
void ej_str_len()
{
    printf("\tUtilizando str_len veo la longitud de cadena");
    char cadena [TAM];
    printf("\n\tIngrese datos en cadena: ");
    fflush(stdin);
    gets(cadena);
    printf("\tLa cadena mide: %d", str_len(cadena) );
    pausa("");
}
void ej_reemplazar()
{
    char cadena1 [TAM],
         cadena2 [TAM],
         cadena3 [TAM];
    printf("\tReemplazar usa mem_move, asi que puede a la cadena 1");
    printf("\n\treemplazar ocurrencias de cadena 2 con cadena 3 muy larga");
    printf("\n\tIngrese datos en cadena1: ");
    fflush(stdin);
    gets(cadena1);
    printf("\n\tIngrese datos en cadena2: ");
    fflush(stdin);
    gets(cadena2);
    printf("\n\tIngrese datos en cadena2: ");
    fflush(stdin);
    gets(cadena3);
    reemplazar(cadena1,cadena2,cadena3);
    printf("\n\tLa cadena 1 quedo: %s",cadena1);
    pausa("");
}
void ej_str_cat()
{
    char cadena1 [TAM],
         cadena2 [TAM];
    printf("\tUtilizando str_cat cadena 1 le agrego cadena 2 si hay memoria");
    printf("\n\tIngrese datos en cadena1: ");
    fflush(stdin);
    gets(cadena1);
    printf("\n\tIngrese datos en cadena2: ");
    fflush(stdin);
    gets(cadena2);
    str_cat(cadena1,cadena2);
    printf("\n\tLa cadena 1 quedo: %s",cadena1);
    pausa("");
}

void ej_encriptar()
{
    //char cadena1 [TAM] = {"abc1def3bdjps"};
    char cadena1 [] = {"juancito no vino a bibioteca"},
         *ini,
         *fin;
    int  cant;

    char * aux = cadena1;

    printf("\n\tEncripta cadena, si la cantidad de caracteres es par, la invierte\n\ty si es impar dependiendo de la posicion que este la letra, la cambia por la siguiente correspondiente a esa cantidad");
    printf("\n\tLa cadena tiene: %s",cadena1);

    while ( *aux )
    {
        //HAGO EL CALCULO DE LA EXTENSION DE LA PALABRA EN EL ARRAY
        ini = proxima_palabra ( aux );
        fin = fin_palabra ( ini );
        cant =  (int) (fin - ini );
        //HAGO LO QUE LA ALGORITMIA ME PIDE
        //MODIFICA E INVIERTE SI ES PAR, SI ES IMPAR INVIERTE
        if(esPar(cant))
            modificar_cadena(ini,cant);
        invertir_cadena(ini,cant);
        //PREPARO EL PUNTERO CADENA PARA LA SIGUIENTE PALABRA
        aux = fin;
    }
    printf("\n\tLa cadena quedo: %s",cadena1);
    pausa("");
}



void ej_str_tok()
{
    printf(" Utilizando str_tok cargo una cadena y la trozo con los simbolos deseados");
    char cad1 [TAM],
         cad2 [TAM];
    char *lista [16] = {NULL};
    int i= 0;
    printf("\n\tIngrese cadena: ");
    fflush(stdin);
    gets(cad1);
    printf("\n\tIndique simbolos por los cuales trozar: ");
    fflush(stdin);
    fflush(stdin);
    gets(cad2);
    printf("\n\tLa cadena : [%s]",cad1);
    printf("\n\tse trozara con cualquiera de estos simbolos : [%s]",cad2);
    lista [i] = str_tok (cad1,cad2);
    while( lista [i] != NULL)
    {
        ++i;
        lista[i] = str_tok (NULL,cad2);
    }
    for (i=0; lista [i] != NULL; i++)
        printf ("\t%p : %s\n", lista[i], lista[i] );
    printf ("\t%p : \n", lista[i]);
    pausa("");
}

void ej_eliminarSubCad()
{
    char cadena1 [TAM],
         cadena2 [TAM];
    printf("\tUtilizando eliminarSubCad cadena 1 le elimino lo de cadena 2");
    printf("\n\tIngrese datos en cadena1: ");
    fflush(stdin);
    gets(cadena1);
    printf("\n\tIngrese datos en cadena2: ");
    fflush(stdin);
    gets(cadena2);
    eliminarSubCad( cadena1 , cadena2 );
    printf("\n\tLa cadena 1 quedo: %s",cadena1);
    pausa("");

}

void ej_ejercicio8()
{
    char texto[TAMM],
         pri[TAMM];

    printf("Ingrese un texto: ");
    fflush(stdin);
    gets(texto);
    printf("El texto tiene %d palabras.\n"
           "La longitud de la palabra mas larga es %d letras.\n"
           "Se repite %d veces la primer palabra que es \"%s\".",
           cuentaPalabras(texto),
           longitud(texto),
           repite(texto,pri),
           primerPalabra(texto,pri)
           );
}


void ej_cargar_archivo_texto_variable()
{
    FILE*   pf_text;
    t_per   dato;
    //if( cargar(&dato,pf) != 0 );
    cargar_archivo_texto_variable(&pf_text, &dato);
    pausa("");
}

void ej_cargar_archivo_binario_fijo()
{
    FILE*   pf_bin;
    t_per   dato;
    //if( cargar(&dato,pf) != 0 );
    cargar_archivo_binario_fijo(&pf_bin, &dato);
    pausa("");
}

void ej_mostrar_archivo_binario_fijo()
{
    /**Forma directa en funcion**/
    FILE*   pf_bin;
    t_per   dato;
    if(!abrir_archivo(&pf_bin,PERSONA,READ_BIN,CON_MSG))
        return;
    mostrar_persona(NULL);
    fread(&dato,sizeof(t_per),1,pf_bin);
    while(!feof(pf_bin))
    {
       mostrar_persona(&dato);
        fread(&dato,sizeof(t_per),1,pf_bin);
    }
    fclose(pf_bin);
    /**Forma indirecta con funcion, lopez dice
    que el fclose es peligroso y no tiene sentido llamar a una funcion
    para que esta abra el archivo
    ya  que queda instanciada el fclose en la funcion**/
    mostrar_archivo_binario_fijo(&pf_bin, &dato);
    pausa("");
}

void ej_mostrar_archivo_texto_variable()
{
    /**Forma directa en funcion**/
    FILE*   pf_text;
    t_per   dato;
    /**Forma indirecta con funcion, lo  ºpez dice
    que el fclose es peligroso y no tiene sentido llamar a una funcion
    para que esta abra el archivo
    ya  que queda instanciada el fclose en la funcion**/
    mostrar_archivo_texto_variable(&pf_text, &dato);
    pausa("");
}

