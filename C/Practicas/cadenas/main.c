/***
    Cadenas ---> vector de caracteres ( array de char). En C no existen los string
    Las variables dimensionables no se puede usar como una sola variable
    los leee y luego lo almacena en memoria de abajo hacia arriba
    C NO HACE CONTROL DE OVERFLOW, ES COMO UN HERMANO BOBO
    constante vector cuando declaramos con indice,
    constante el texto cuando declaramos como puntero
***/
///main.h
#include "main.h"
#include "ejercicioCadenas.h"
void claseTeorica();
void funcionesString();
//char* strcpy_mia(char *cad1, const char* cad2 );

int cmpChar(const void* d1, const void*d2)
{
    return *(char*)d1 - *(char*)d2;

}
int cmpInt(const void* d1, const void*d2)
{
    return *(int*)d1 - *(int*)d2;
}

void intercambio(const void *d1, const void *d2)
{
    int aux = *(int*)d1;
    *(int*)d1 = *(int*)d2;
    *(int*)d2 = aux;
}
int main()
{
    char cad[] = "1723920rasAAxcew-111";
    int cadInt[] = {1,2,3,4,5,6,3,8,1,10,11,123,143}, ce=13, i=0;
   /// claseTeorica();
    ///funcionesString();
//    puts(cad);
//    ordenamientoSelectivo(cad,cmpChar);
//    puts(cad);
    ordenamientoSelectivoInt(cadInt,13,cmpInt, intercambio);
    while(ce--)
    {
        printf("%d ",cadInt[i]);
        i++;
    }

    return 0;
}

void claseTeorica()
{
    char cad1[5] = "Hola", ///reserva x bytes de memoria para utilizar, donde x es lo que reservo explicita o implicitamente
        cad2[5] = "hola",
        cad3[] = "hola",
       /// cad4[10] = "si0123456789",
        cad5[2] = "no",
        cad6[] = {'a' , 'b' , 'c' },
        cad7[5] = {'a' , 'b' , 'c' },
        *cad9 = "Cadena",///Lo que es constante es la cadena "cadena", el puntero no.
        cad31[4] = "hola";
        ///cad8[5] = {'a' ,  , 'c' };
      ///  cad10[10] = 'x';
    int i=1;
    cad2[3] = 'x';
    ///cad2++; ///no se puede xq es un puntero CONSTANTE
    cad9++;
    ///*cad9 = 'b'; ///No puedo realizar esto
    cad9--;

    printf("Cad2 = %s\n", cad2);
    printf("Cad9 = %s\n", cad9);
    system("pause");
    printf("cad%d es %s\n\n", i++, cad1);
    printf("cad%d es %s\n\n", i++, cad2);
    printf("cad%d es %s\n\n", i++, cad3);
///    printf("cad%d es %s\n\n", i++, cad4);
    printf("cad%d es %s\n\n", i++, cad5);
    printf("cad%d es %s\n\n", i++, cad6);
    printf("cad%d es %s\n\n", i, cad7);
//    printf("cad%d es %s\n\n", i++, cad8);
//    i++;
    i+=2;
    printf("cad%d es %s\n\n", i, cad9);
        printf("cad31 es %s\n\n", cad31);

}


void funcionesString()
{
    int opcion;
    char palabraSinNormalizar[] = "  hola   ESTOY   €€~~¬¬ -##--.. , ,   noRMALIZando esta cadena",
          cadena[] = "anagrama con analisis de anana anana anana ",
          subcadena[] = "ana",
          numAconvertir[] = "390187";

    do
    {
        printf("1 - Librerias string\n2 - Normalizar\n\n\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            {
                simulacionString();
                break;
            }
            case 2:
            {
                printf("Cadena: %s\n", palabraSinNormalizar);
                normalizarCadena(palabraSinNormalizar);
                printf("Cadena normalizada; %s\n", palabraSinNormalizar);
                break;
            }
            case 3:
            {
                printf("Cadena: %s\n", cadena);
                printf("Subcadena: %s\n", subcadena);
                normalizarCadena(palabraSinNormalizar);
                printf("Hay %d ocurrencias (sin) \n", ocurrenciasSinSolapa(cadena , subcadena));
                printf("Hay %d ocurrencias (con)\n", ocurrenciasConSolapa(cadena , subcadena));
                break;
            }
            case 4:
            {
                printf("Cadena a convertir: %s\n", numAconvertir);
                printf("Cadena convertida: %d \n", atoi_mia(numAconvertir));
                break;
            }
        }
        printf("0 - Salir\n");
    }while(opcion != 0);
   /// char* strcpy_mia ( char* destino, const char * origen)
   /// printf("Inicio\n\ncad1 = %s \n\n cad2 = %s\n",cad1, cad2);
////    printf("Estamos trabajando con Strcpy\t%s \n ",strcpy_mia(cad2, cad1 ));
//    printf("Estamos trabajando con Strcpy - Original\t%s \n ",strcpy(cad21, cad2));
//    printf("Final:\ncad2 = %s \n cad21 = %s\n",cad2, cad21);

//    printf("Inicio\n\ncad1 = %s \n\n cad2 = %s\nCad21 *%s*\ncad11  %s\n",cad1, cad2, cad21, cad11);
//    printf("Estamos trabajando con Strcat\t%s \n ",strcat_mio(cad1, cad21 ));
//    printf("Estamos trabajando con Strcpy - Original\t%s \n ",strcat(cad11, cad21));
//    printf("Final:\n\n\ncad1 = %s \n\n cad2 %s\n\n cad21= *%s*\n Cad11 %s\n",cad1, cad2, cad21, cad11);

//    printf("Inicio\n\ncad1 = %s \n\n cad2 = %s\nCad21 *%s*\ncad11  %s\n",cad1, cad2, cad21, cad11);
//    printf("Estamos trabajando con Strcat\t%s \n ",strcat_mio(cad1, cad21));
//    printf("Estamos trabajando con Strcpy - Original\t%s \n ",strcat(cad11, cad21));
   /// printf("Estamos trabajando con strcat - control overflow\t%s \n ",strcat_mio_control(cad11, cad21));
   /// printf("Final:\n\n\ncad1 = %s \n\n cad2 %s\n\n cad21= *%s*\n Cad11 %s\n",cad1, cad2, cad21, cad11);


    /***
    size_t strlen (const char* cad)
    int strcmp ( const char * s1, const char* s2);
    char *strlwr( char *cad) o strupr ( ); /// convierte una cadena a minuscula o mayuscula
    char* strchr ( const char* cad, int c);
    char* strrchr ( const char* cad, int c);
    char *strstr(const char *s1, const char *s2); ///Primer aparicion desde la derecha
    strchr(
    ***/
}

void simulacionString()
{
    char destino[TAM]= "Please, ",
        origen[] = "Now Loading";
    int opcion;
    do
    {
        printf("1 - strcpy\n2 - strcat\n\n\n");
        printf("0 - Menu principal\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            {
                fflush(stdin);
                printf("Inicio:\n\nDestino: %s\nOrigen: %s\n\n",destino, origen);
                printf("Aca: %s\n",strcpy_mia
                       (destino, origen));
                printf("Final:\n\nDestino: %s\nOrigen: %s\n\n",destino, origen);
                break;
            }
            case 2:
            {
                printf("Inicio:\n\nDestino: %s\nOrigen: %s\n\n",destino, origen);
                printf("Se realizó concatenacion: %s\n",strcat_mio(destino, origen));
                printf("Final:\n\nDestino: %s\nOrigen: %s\n\n",destino, origen);
                break;
            }
        }
    }while(opcion != 0);

}


