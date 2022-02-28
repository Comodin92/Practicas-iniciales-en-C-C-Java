/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER MODIFICACIÓN QUE HAGA NO SERÁ TENIDA EN CUENTA.      *//**/
/**//**//* SÓLO PARA QUE CAMBIE LAS CANTIDADES DE FILAS Y COLUMNAS        *//**/
/**//**//* DURANTE SUS PRUEBAS      *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO_1 **/
#define ARCH_PUNTO_1        "datos.txt"

#define TAM_PAL_MAX     20
#define CANT_PAL_MAX    20
#define ES_LET(X) ((((X)>= 'a' && (X)<= 'z') || ((X)>= 'A' && (X)<= 'Z')))
#define ES_DIG(X) (((X)<= '9' && (X) >= '0'))
#define ES_VAL(x) (((x) == 'Ü') ||((x)== 'ü' ) || (x)== 'ñ' || (x)== 'Ñ')
#define ES_ACEN_MAY(x) ((x)=='Á' || (x) == 'É' ||(x)== 'Í' ||(x)== 'Ó' || (x) == 'Ú')
#define ES_VAL_DIA(x) ((x)=='á' || (x) == 'é' ||(x)== 'í' ||(x)== 'ó' || (x) == 'ú')
#define ES_CARACTER_VALIDO(x) (ES_LET(x) || ES_DIG(x) || ES_VAL(x) || ES_VAL_DIA(x) ||ES_ACEN_MAY(x))


void crearDatosPunto1(const char *nomArch, int nroDeLote);

void procesarArchivo(FILE *fpEnt, FILE *fpPantalla);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO_2 **/
#define N_FILAS         15
#define M_COLUM         17



int crearMat(int mat[][M_COLUM], int filas, int colum);
int mostrarMat(int mat[][M_COLUM], int filas, int colum, FILE *fpPantalla);
void mostrarPalabraslargas(FILE *fpPantalla, char m[][TAM_PAL_MAX],
                           int palabra_mas_larga, int  tope);
int traspRespAlCentro(int mat[][M_COLUM], int filas, int colum);

int mostrarTriangSup(int mat[][M_COLUM], int filas, int colum,
                     FILE *fpPantalla);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** función que determina si su argumento es un dígito, una letra mayúscula o
 **     minúscula acentuada o no, u con diéresis (ü / Ü), o ñ / Ñ
 **/
int esLetraODigito_MIO(char c);

/** función que busca el comienzo de una palabra desde la dirección que recibe
 **/
char *proxPal_MIO(const char *s);

/** función que busca el carácter que está a continuación de una palabra
 **/
char *finPal_MIO(const char *s);

/** función que determina el tamaño de una palabra (su cantidad de carácteres)
 **/
size_t tamPal_MIO(const char *ini, const char *fin);


/** función que copia una cadena de caracteres, recibe la cantidad de caracteres
 **     a copiar además de el espacio posible a utilizar
 **     para de copiar cuando se cumpla una de las dos cosas
 **/
char *copiarPal_MIO(char *dest, const char *orig, size_t tam, int tope);

/** función que lee el archivo que recibe (¿ya abierto?) por argumento y hace
 **     las determinaciones pedidas
 **/
void procesarArchivo_MIO(FILE *fpEnt, FILE *fpPantalla);


/** función que intercambia los elementos de la matriz respecto al centro
 **/
int traspRespAlCentro_MIO(int mat[][M_COLUM], int filas, int colum);

/** función que muestra la triangular superior de la matriz
 **/
int mostrarTriangSup_MIO(int mat[][M_COLUM], int filas, int colum,
                         FILE *fpPantalla);

void intercambiar(int* d1, int* d2);

int obtenerMaximo(int cant_cara, int max_palabra);

void mostrarPalabraslargas(FILE *fpPantalla, char m[][TAM_PAL_MAX],
                           int palabra_mas_larga, int  tope);
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#endif // FUNCIONES_H_

