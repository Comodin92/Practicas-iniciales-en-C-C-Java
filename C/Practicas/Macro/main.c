#include <stdio.h>
#include <stdlib.h>
#define ABSOLUTO(X) (((X)< 0)?-(X):(X))
#define PARTE_ENTERA(X) ((int)(X))
#define PARTE_DECIMAL(X) ((X)-PARTE_ENTERA(X))
#define REDONDEO(X) (PARTE_ENTERA(X) + ((PARTE_DECIMAL(X) >= 0.5)? 1 : 0))

#define ES_LETRA(X) ((((X)>= 'a' && (X)<= 'z') || ((X)>= 'A' && (X)<= 'Z'))? 1 : 0)
#define ES_VOCAL(X) ((A_MINUSCULA(X)== 'a' || A_MINUSCULA(X)== 'e' || A_MINUSCULA(X)== 'i' || A_MINUSCULA(X)== 'o' || A_MINUSCULA(X)== 'u' ) ? 1 : 0)
#define ES_DIGITO(X) (((X)<= 9 && (X) >= 0)? 1 : 0)
#define ES_MAYUSCULA(X) (((X)>= 'A' && (X)<= 'Z')? 1 : 0)
#define ES_MINUSCULA(X) (((X)>= 'a' && (X)<= 'z')? 1 : 0)
#define A_MAYUSCULA(X) ((ES_MAYUSCULA(X)? (X) : (X) - 32 ))
#define A_MINUSCULA(X) ((ES_MINUSCULA(X)? (X) : (X) + 32 ))
#define ES_BLANCO(X) ((X) == ' ' || (X) == '\t' ||  (X) == 10 ? 1 : 0)



int main()
{
    int dato_absoluto = -12, digito_noDigito = 111, ascii= 64;
    float dato_par_entera = 7.3;
    char letra_noLetra= '.',
         mayus_noMayus= 'a',
         minus_noMinus = 'x',
         espacio_NoEspacio = ' ' ;
    printf("El valor absoluto de %d es %d\n\n", dato_absoluto, ABSOLUTO(dato_absoluto));
    printf("Parte entera de %.2f es %d\n\n",dato_par_entera, PARTE_ENTERA(dato_par_entera));
    printf("Parte decima de %.2f es %.2f\n\n", dato_par_entera, PARTE_DECIMAL(dato_par_entera));
    printf("El redonde de %.2f es %d\n\n", dato_par_entera, REDONDEO(dato_par_entera));
    printf("El caracter %c %s letra\n\n",letra_noLetra, ES_LETRA(letra_noLetra)? "es" : "no es");
    printf("El caracter %d %s digito\n\n ",digito_noDigito, ES_DIGITO(digito_noDigito)? "es" : "no es");
    printf("El caracter %c %s mayuscula\n\n ",mayus_noMayus , ES_MAYUSCULA(mayus_noMayus)? "es" : "no es");
    printf("El caracter %c %s minuscula\n\n ",minus_noMinus , ES_MINUSCULA(minus_noMinus)? "es" : "no es");
    printf("El caracter %c en mayuscula es %c \n\n ",minus_noMinus , A_MAYUSCULA(minus_noMinus));
        printf("El caracter %c es \n\n ",minus_noMinus ,minus_noMinus);
    printf("El caracter %c en minuscula es %c \n\n ",minus_noMinus , A_MINUSCULA(minus_noMinus));
    printf("El caracter %c %s blanco\n\n ",espacio_NoEspacio , ES_BLANCO(espacio_NoEspacio)? "es" : "no es");
   /// printf("El codigo ascci de %c es %d\n\n", ascii, ascii);
    return 0;
}

int convertirEntero(const char* ini)
{
    char *fin;
    int resultado=0,
        multiplo10=1;
    while(*ini !=  '\n' && *ini)
    {
        while(!ES_DIGITO(*ini))
            ini++;
        fin=(char*)ini;
        while(ES_DIGITO(*fin))
            fin++;
        fin--;
        while(fin >= ini)
        {
            resultado += (((*fin) -'0')*multiplo10);
            multiplo10*=10;
            fin--;
        }
                printf("%d\n",resultado);
        ///system("pause");
        return resultado;
    }


    return 1;
}
void mostrarCampos(int campos[][9], int posi)
{
    int i, j;
    for(i = posi-1 ; i<= posi-1 ; i++ )
    {

        for(j = 0 ; j < 9 ; j++)
            printf("%d\t", campos[i][j]);
        printf("\n");
    }
}
