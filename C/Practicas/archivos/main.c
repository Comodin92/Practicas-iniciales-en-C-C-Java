#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ES_BLANCO(X) ((X) == ' ' || (X) == '\t' ||  (X) == 10 ? 1 : 0)
#define ES_LETRA(X) ((((X)>= 'a' && (X)<= 'z') || ((X)>= 'A' && (X)<= 'Z'))? 1 : 0)

void estructuraTeoria();
void archivoTeoria();
void desencriptarLinea(char *linea);
void ejercicioDescriptar();
char caracterAnt(char linea, const int contador);
void invertirLinea( char *inicio, char *linea);


//typedef struct
//{
//    int dd,
//        mm,
//        aa;
//    char nombMes[10];
//} t_fecha;
//
//typedef struct s_alumno
//{
//    char nyap[40];
//    int dni;
//    char sx;
//    t_fecha fNac;
//    int matAp[50];
//    struct s_alumno *tutor;
//} t_alumno;


int main()
{
   /// estructuraTeoria();
    ///archivoTeoria();
///    lote_prueba();
    ejercicioDescriptar();

    return 0;
}
//
//void estructuraTeoria()
//{
//    t_fecha f1;
//    /// t_alumno al1;
//    t_alumno al2 = {"Juan Perez", 11111111, 'm', {9, 2, 1990, "febrero" },{0}};
//    f1.dd = 12;
//
//    f1.mm = 01;
//    f1.aa = 1992;
//    ///scanf(("%d", al1.fNac.aa));
//    strcpy(f1.nombMes, "enero");
//    fflush(stdin);
//    ///scanf("%s", f1.nombMes);
//    printf("%d / %d / %d corresponde al mes %s\n",f1.dd, f1.mm, f1.aa, f1.nombMes);
//    scanf("%d",&al2.matAp[9]);
//    printf("%s %c %d/%d/%d %s %d \n", al2.nyap, al2.sx, al2.fNac.dd, al2.fNac.mm, al2.fNac.aa, al2.fNac.nombMes,al2.matAp[9]);
//
//}
//
//void archivoTeoria()
//{
//    /***
//            Archivo
//            conjunto de datos, que perduran en el tiempo entre diferetente ejecuciones
//
//            clasificacion en funcion de como esta almacenada la informacion
//            binarios: tal como está en la memoria
//            texto: convierte el contenido de la memoria y lo codifica segun el codigo ascii
//
//            Clasificar en funcion de como fluye la informacion
//            entrada : escritura  -  Grabar en el archivo
//            salida: lectura - Leer en el archivo
//            e/s escritura/lectura - leer y grabar en el archivo
//
//            Clasificar en funcion del acceso a la informacion
//            secuencial -> en orden de a 1 desde el inicio
//            acceso directo -> directamente a un registro en particular
//
//            fopen -> abrir archivo y asociarlo con la zona de memoria
//            SIEMPRE que uso fopen debo verificar apertura archivo
//
//            apertura de archivos
//            binario
//            rb si existe lee, si no exite error
//            wb  si existe lo vacia y graba, si no existe lo crea y lo graba
//            r+b, w+b
//            texto
//            rt , wt, r+t, w+t
//
//            fclose ->
//
//            Leer parte A de archivos que tenemos en miel
//            Clase viernes 11hs+
//
//            rewind(pf) retrocede al comienzo del archivo (puntero a file apunta al inicio)
//            fseek --> mueve el puntero del archivo
//            int fseek(FILE *stream, long int desplazamiento, int origen);
//                fseek( FILE que uso, cantidad de bytes que quiero moverme, desde donde empiezo a
//                      contar esa cant bytes
//                                                            SEEK_SET -> inicio archivo
//                                                            SEEK_CUR -> POSICION ACTUAL PF
//                                                            SEEK_END -> final archivo
//
//            volver al inicio del archivo
//            fseek(pf, 0L, SEEK_SET);
//            ir al final del archivo
//            fseek(pf, 0L, SEEK_END);
//            ftell -> cant de caracteres -> Bytes desde el inicio a la posicion alctual
//            ir a la tercer posicion del archivo
//            fseek( pf, 2*sizeof(t_reg),SEEK_SET);
//
//            saber cantidad de registros
//            IR AL FINAL , ftell / sizeof
//
//
//    ***/
//
//}
//
//

void ejercicioDescriptar()
{
    FILE *pf_encrip, *pf_desenc;
    char linea[300];
    pf_encrip = fopen("archivoOfuscado11.txt","rt");
    if(!pf_encrip)
    {
        printf("Error al abrir archivo\n");
        return;
    }
    pf_desenc = fopen ("ArchivoDesen.txt","wt");
    if(!pf_desenc)
    {
        printf("Error al crear archivo\n");
        return ;
    }

    while(fgets(linea, sizeof(linea),pf_encrip))
    {
        desencriptarLinea(linea);
        ///fprintf(pf_desenc,"%s",linea);
        printf("%s\n",linea);
    }
}

void desencriptarLinea(char *linea)
{
    int contador;
    char *sigPal=linea, *inicio=linea;
    while(*linea != '\n')
    {
        while(ES_BLANCO(*linea))
            linea++;
        contador = 1;
        inicio = linea;
        while(*linea != ' ')
        {
            if(ES_LETRA (*linea))
                *linea = caracterAnt(*linea,contador++);
            linea++;
        }
        invertirLinea(inicio,linea-1);



    }
    ///borro espacio del inicio de la cadena



}
char caracterAnt(char linea, const int contador)
{
    char *inicio=linea, *letra, *sigPal=linea, abcdCircular[53]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    letra = strchr(abcdCircular, linea);
    letra -= contador;
    if( letra < abcdCircular)
        letra+=53;
    return *letra;
}

void invertirLinea( char *inicio, char *linea)
{
    char aux;
    while( inicio < linea )
    {
//        while(!ES_BLANCO(*linea) && !ES_LETRA(*linea))
//            linea--; ///Si hay mas de un punto, signos, etc
        aux = *linea;
        *linea = *inicio;
        *inicio = aux;
         inicio++;
         linea--;
    }
}
