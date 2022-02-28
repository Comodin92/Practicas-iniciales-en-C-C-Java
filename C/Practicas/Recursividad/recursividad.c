#include "recursividad.h"



double factorialI(int n)
{
    int i;
    double resultado=1;
    for(i = n ; i > 1 ; i--)
        resultado *=  (i);
    return resultado;
}
double factorialR(int num)
{
    if(num == 0)
        return 1;
    return num*factorialR(num-1);
}
void cadenaOrden(const char *cad)
{
    if(!*cad)
        return;
    printf("%c\n",*cad);
    cadenaOrden(cad+1);

}

void cadenaOrdenInverso( char *cad)
{
    if(!*cad)
        return;
    cadenaOrden(cad+1);
    printf("%c\n",*cad);

}
void cadenaNormalInverso(char *cad)
{
    if(!*(cad + 1))
    {
        printf("%c\n",*cad);
        return;
    }
    printf("%c\n",*cad);
    cadenaNormalInverso(cad+1);
    printf("%c\n",*cad);
}

void cadenaNormalInversoIncompleto(char *cad)
{
    if(!*(cad+2))
    {
        printf("%c\n",*(cad));
        printf("%c\n",*(cad+1));
        return;
    }
    printf("%c\n",*cad);
    cadenaNormalInversoIncompleto(cad+1);
    printf("%c\n",*cad);
}
void cadenaPalabraDecre(char *cad)
{
    if(!*cad)
        return;
    printf("%s\n",cad);
    cadenaPalabraDecre(cad+1);
}
void cadenaPalabraInversoDecre(char *cad)
{
    if(!*cad)
        return;
    cadenaPalabraInversoDecre(cad+1);
    printf("%s\n",cad);
}
void cadenaPalabraDecre2(char *cad)
{
    char tam = strlen(cad);
    mostrasPalDecre(cad, tam);
}
void mostrasPalDecre(char *cad, int tam)
{
    if(tam <= 0)
    {
        return;
    }
    printf("%.*s\n",tam,cad);
    mostrasPalDecre(cad,tam-1);
}
////////////////////////////
void mostrearNumEntero(int n)
{
    if(!n)
        return;
    mostrearNumEntero(n/10);
    printf("%d\t",n%10);
}

void mostrearNumEnteroInv(int n)
{
    if(!n)
        return;
    printf("%d\t",n%10);
    mostrearNumEnteroInv(n/10);
}

void mostrearNumDec(int n)
{
    if(!n)
        return;
    printf("%d\t",n);
    mostrearNumDec(n/10);
}

void mostrearNumCreInv(int num)
{
    if(!num)
        return ;
    mostrearNumCreInv(num/10);
    printf("%d\t",num);
}
void mostrarNumEnteroInverso(int n)
{
    if(n < 10)
    {
        printf("%d\t",n);
        return;
    }
    printf("%d\t",n);
    mostrarNumEnteroInverso(n/10);
    printf("%d\t",n);
}

void mostrarNumDecIzqDer( int num)
{
    double mult = contarUnidadesNum(num);
    mult = pow(10, mult);
    numDecIzqDer(num, mult);

}

double contarUnidadesNum(int num)
{
    double res= 1;
    while( num>0 && (num = num/10))
        res++;
    return res;
}

void numDecIzqDer(int num, double mult)
{
    if(num <= 0)
        return ;
    mult = mult/10;
    printf("%d\t",num);
    numDecIzqDer(num%(int)mult,mult); ///Queda mal asi pero lo hago para hacer otra funcion para hacerla recursiva

}

void mostrarNumDecDerIzq( int num)
{
    double mult = contarUnidadesNum(num);
    mult = pow(10, mult);
    numDecDerIzq(num, mult);
}

void numDecDerIzq(int num, double mult)
{
    if(num <= 0)
        return ;
    mult = mult/10;
    numDecDerIzq(num%(int)mult,mult);
    printf("%d\t",num);
}

/*****************************/

void cambioDeBase(int num, int baseDestino)
{
    if( num < baseDestino)
    {
        printf("%d",num);
        return;
    }
    cambioDeBase(num/baseDestino, baseDestino);
    printf("%d",num%baseDestino);
}

int esPalindromoRec(char *cad)
{
    int tam = strlen(cad)- 1;
    return esPalindromo(cad, cad+tam);
}

int esPalindromo( char* cad, char *fin)
{
    if(cad >= fin)
        return 1;
//    if(*cad != *fin)
//        return 0;
//    if( *cad == ' ' && *cad == *fin)
//        return esPalindromo(cad+1, fin-1);
    if(*cad == ' ')
        return esPalindromo(cad+1, fin);
    if(*fin == ' ')
        return esPalindromo(cad, fin-1);
    if(*cad == *fin)
        return esPalindromo(cad+1, fin-1);
    return 0;
} ///Macro para que no se solamente esapcio blanco, datos no permitidos

int strlenRecursiva(char *cad)
{
    if(!*cad)
        return 0;
    return 1 + strlenRecursiva(cad+1);
}

int calcularMCD(int num1, int num2)
{
    if((num1<0 || num2<0) || (!num1 || !num2))
    {
        printf("\nUno de los numeros es negativo o es cero\n");
        return -2;
    }
    if(num1 > num2)
        return MCD(num1,num2);
    else
        return MCD(num2,num1);
    return 1;
}

int MCD(int dividendo, int divisor)
{
    if(divisor == 0)
        return dividendo;
    MCD(divisor, dividendo % divisor);
    ///return dividendo;
}

int busquedaBinariaIterativa(char *cad, char valor)
{
    char *inf=cad, *sup= cad + (strlen(cad)-1), *medio= (cad + ((sup-inf)/2));

    /// printf("\nEn cad hay %c \n En fin hay %c \n en mitad hay %c\n",*inf,*sup,*medio);
    while( (inf+1) != sup  )
    {
        if(*medio == valor)
            return 1;
        if(*medio < valor)
            inf = medio;
        if(*medio > valor)
            sup = medio;
        medio = inf +((sup - inf )/2);
    }
    if((*inf == valor) || (*sup == valor))
        return 1;
    return 0;
}

int busquedaBinariaRecursiva(char *cad, char valor)
{
    char *inf=cad, *sup= cad + (strlen(cad)-1), *medio= (cad + ((sup-inf)/2));
    return busqBin(inf, sup, medio, valor);
}

int busqBin(char *inf, char *sup, char *medio, char valor)
{
    if(*medio==valor)
        return 1;
    if(*medio < valor)
        busqBin(medio+1,sup, inf +((sup - inf )/2), valor );
    if(*medio > valor)
        busqBin(inf,medio-1, inf +((sup - inf )/2), valor );
    return 0;
}


