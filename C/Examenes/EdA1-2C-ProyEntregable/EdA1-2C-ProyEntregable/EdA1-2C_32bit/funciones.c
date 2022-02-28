/**//* 36.902.267-Gutierrez,EdgardoDamian-(02-3362) *//**/
/**//*          ACÁ DEBE INDICAR SU NÚMERO DE DNI, APELLIDO(S) Y          *//**/
/**//*          NOMBRE(S) COMPLETOS Y COMISIÓN TAL COMO SE INDICA         *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ *//**/
///Lo que utilicé en funciones.h

#define ES_LET(X) ((((X)>= 'a' && (X)<= 'z') || ((X)>= 'A' && (X)<= 'Z')))
#define ES_DIG(X) (((X)<= '9' && (X) >= '0'))
#define ES_VAL(x) (((x) == 'Ü') ||((x)== 'ü' ) || (x)== 'ñ' || (x)== 'Ñ')
#define ES_ACEN_MAY(x) ((x)=='Á' || (x) == 'É' ||(x)== 'Í' ||(x)== 'Ó' || (x) == 'Ú')
#define ES_VAL_DIA(x) ((x)=='á' || (x) == 'é' ||(x)== 'í' ||(x)== 'ó' || (x) == 'ú')
#define ES_CARACTER_VALIDO(x) (ES_LET(x) || ES_DIG(x) || ES_VAL(x) || ES_VAL_DIA(x) ||ES_ACEN_MAY(x))

void mostrarPalabraslargas(FILE *fpPantalla, char m[][TAM_PAL_MAX],
                           int palabra_mas_larga, int  tope);
void intercambiar(int* d1, int* d2);

void mostrarPalabraslargas(FILE *fpPantalla, char m[][TAM_PAL_MAX],
                           int palabra_mas_larga, int  tope);

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/
/***
    FUNCIONES PARA EJERCICIO 1
***/

void procesarArchivo_MIO(FILE *fpEnt, FILE *fpPantalla)
{   /**
    Declaraciçión de variables, les dejo algnos comentarios para facilitar la lectura
        linea[] -> vector que utilizo para almacenar los registros del archivo de texto
         *pIni -> puntero que apunta al comienzo de una palabra
         *pFin  -> puntero que apunta al final de una palabra
         m[][] -> Matriz para almacenar las palabras con más caracteres
        *pMat -> puntero a la matriz

        cant_car  -> cantidad de caracteres que tiene una palabra
        max_palabra -> la cantidad maxima de caracteres
        cant_lineas_txt -> Cantidad de registros o "lineas" que hay en el archivo
        cant_lineas_vacias -> cantidad de registros o "lineas" sin caracteres validos
        cant_tot_pal -> cantidad de palabras que hay en todo el archivo completo
        palabra_mas_larga -> cantidad de palabras mas grandes del registro
    **/
    char linea[199],
         *pIni,
         *pFin,
         m[CANT_PAL_MAX][TAM_PAL_MAX]= {},
                                       *pMat;
    int cant_cara=0,
        max_palabra=0,
        marca=1,
        cant_lineas_txt=0,
        cant_lineas_vacias=0,
        cant_tot_pal=0,
        palabra_mas_larga=0;

    pMat=m[0];
    while(fgets(linea, sizeof(linea),fpEnt))
    {
        cant_lineas_txt++;
        pIni = proxPal_MIO(linea);
        if(*pIni == '\n' || !ES_CARACTER_VALIDO(*pIni))
            cant_lineas_vacias++;
        while(*pIni != '\n' && *pIni )
        {
            if(ES_CARACTER_VALIDO(*pIni))
                cant_tot_pal++;
            pFin = finPal_MIO(pIni);
            cant_cara = tamPal_MIO(pIni, pFin);
            if(marca)
            {
                max_palabra = cant_cara;
                marca=0;
            }
            if(max_palabra == cant_cara)
               {
                   pMat = copiarPal_MIO(pMat, pIni,max_palabra,TAM_PAL_MAX);
                   palabra_mas_larga++;
               }
            if(max_palabra < cant_cara)
            {
                max_palabra = cant_cara;
                pMat = m[0];
                pMat = copiarPal_MIO(pMat, pIni,max_palabra ,TAM_PAL_MAX);
                palabra_mas_larga = 1;
            }
            pIni = proxPal_MIO(pFin+1);
        }
    }
    if(!cant_lineas_vacias && !cant_tot_pal)
        fprintf(fpPantalla,"El archivo está vacío\n");
    else
   {
        fprintf(fpPantalla,"El archivo tiene un total de %d línea(s) de texto.\n"
            "Hay %d línea(s) sin palabras.\n"
            "Hay un total de %d palabra(s).\n"
            "La palabra más larga tiene %d caracter(es).\n"
            "Hay %d palabra(s) con esa cantidad de caracteres\n"
            "Se muestra(n) la(s) %d palabra(s) más larga(s))\n",
            cant_lineas_txt,cant_lineas_vacias,cant_tot_pal,cant_cara,palabra_mas_larga,
            palabra_mas_larga);
        mostrarPalabraslargas(fpPantalla, m, max_palabra, palabra_mas_larga);

   }
}


void mostrarPalabraslargas(FILE *fpPantalla, char m[][TAM_PAL_MAX],
                            int cant_palabras, int  tamPalabra)
{   /**
        Al mostrar tomo como referencia, la cantidad de palabras como las filas a recorrer y tamPalabra
        como la cantidad de caracteres por fila.
    **/
    int i,j;
    for(i = 0 ; i < tamPalabra  ; i++)
    {
        fprintf(fpPantalla,"%2d - ",i+1);
        for(j = 0 ; j <  cant_palabras && j < TAM_PAL_MAX; j++)
                fprintf(fpPantalla,"%c",m[i][j]);
            fprintf(fpPantalla, "\n");
    }
}


char* proxPal_MIO(const char *linea)
{   /**
        buscamos el primer caracter valido y esto nos da como resultado el comienzo de la siguiente palabra.
    **/

    while(*linea == '\t' || *linea == ' ')
        linea++;
    while(*linea && *linea != '\n' && !esLetraODigito_MIO(*linea))
        linea++;
    return (char*)linea;

}


int esLetraODigito_MIO(char c)
{
    /**
        Decidí realizar macros porque es mas prolijo y mas legible al leer el codigo
    **/
    return ES_CARACTER_VALIDO(c);
}


char *finPal_MIO(const char *s)
{
    /**
        Como recibo el comienzo de el primer caracter de la palabra, busco el primer caracter no valido
        asi ya tengo donde termina la palabra para futuros procesos
    **/
    while(ES_CARACTER_VALIDO(*s))
        s++;
    s--;
    return (char*)s;
}


size_t tamPal_MIO(const char *ini, const char *fin)
{
    unsigned int cantidad=0;
    while(ini <= fin) ///Recorro la palabra hasta llegar a su fin y cuento sus caracteres
    {
        cantidad++;
        ini++;
    }
    return cantidad;
}

char *copiarPal_MIO(char *dest, const char *orig, size_t tam, int tope)
{
    /**
        En esta funcion tuve en cuentas 3 posibilidades :
        1 - Si tam > tope (aux <0)   -> La palabra que quiero ingresar excede del maximo permitido
        2 - tam == tope (aux = 0) ->  Ingresa la palabra entera exactamente
        3 -  tam < tope (aux > 0) -> ingresa la palabra entero pero con espacios disponibles ( hablando
                            de la capacidad maxima que nos permiten)

    **/
    int aux = tope - tam;
    while(*orig != '\n' && tam-- && tope--)
    {
        *dest = *orig;
        dest++;
        orig++;
    }
    ///tope >0 cuando la palabra entra con espacios disponibles para agregar '\n'
    if(tope>0)
        *dest = '\n';
    /**
     si tope es mas grande que tam, debo desplazarma a la primer posicion de la siguiente palabra.
     Por ejemplo si recorro 10 caracteres en total, debo posicionarme 10 caracteres mas para estar
     al comienzo de la siguiente. Si bien las matrices graficamente la vemos como vectores una abajo
     del otro, en memoria las matrices son vectores continuos ( uno al lado del otro)
     si aux es < 0 o aux = 0 el comportamiento es el mismo. por eso solo pregunto cuando me quede espacio
    **/
    if(aux > 0)
    {
        dest+=aux;
        return dest;
    }
    ///retorno la direccion donde voy a insertar la proxima palabra
    return dest;
}

/***
    FUNCIONES EJERCICIO 2
***/


int traspRespAlCentro_MIO(int mat[][M_COLUM], int filas, int colum)
{
    int i,
        j,
        aux,
        cant=0;
    for(i = 0 ; i < filas/2 ; i++)
    {
        for(j = 0 ; j < colum ; j++)
        {
            intercambiar(&mat[i][j], &mat[filas - 1 - i][colum - 1 -j]);

//            aux = mat[i][j];
//            mat [i][ j] = mat[filas - 1 - i][ colum - 1 - j];
//            mat[filas - 1 - i][ colum - 1 - j]  = aux;
            cant++;
        }
    }
    if(filas % 2 != 0)
    {
        for(i=(filas/2) ; i <= (filas/2) ; i++)
        {
            for(j = 0 ; j < colum /2 ; j++)
            {
                intercambiar(&mat[i][j], &mat[i][colum - 1 -j]);
                cant ++;
            }
        }
    }
    return cant;
}

int mostrarTriangSup_MIO(int mat[][M_COLUM], int filas, int colum,
                         FILE *fpPantalla)
{
    int i,
        j,
        cont=0,
        cant_espa=0;
    for(i = 0 ; i < filas ; i++)
    {
        fprintf(fpPantalla,"%*s",cant_espa,"");
        for(j = i ; j < colum ; j++)
        {
            fprintf(fpPantalla,"%4d",mat[i][j]);
            cont++;
        }
        cant_espa+=4;
        fprintf(fpPantalla,"\n");
    }
    return cont;
}
void intercambiar(int* d1, int* d2)
{
    int aux = *d1;
        *d1 = *d2 ;
         *d2 = aux;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**
int esLetraODigito_MIO(char c)
{

}

char *proxPal_MIO(const char *s)
{

}

char *finPal_MIO(const char *s)
{

}

size_t tamPal_MIO(const char *ini, const char *fin)
{

}

char *copiarPal_MIO(char *dest, const char *orig, size_t tam, int tope)
{

}

void procesarArchivo_MIO(FILE *fpEnt, FILE *fpPantalla)
{

}


int traspRespAlCentro_MIO(int mat[][M_COLUM], int filas, int colum)
{

}

int mostrarTriangSup_MIO(int mat[][M_COLUM], int filas, int colum,
                         FILE *fpPantalla)
{

}

 */
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

