#include "recursividad.h"
////////////////////////


int main()
{
    funciones();
    return 0;
}

void teoriaRecursividad()
{
    /***
    fc recursiva que se llama asi misma
    Matematicas
    factorial-> si n > 0 entonces n! = n*(n-1)
                si n = 0 -> n = 1 ;
                si n < 0 -> No está definida la función

    En general, no hay ciclos porqpue el que me dá el ciclo es la recursividad.
    Caso base!!! Siempre
    cuando se consulta el caso baso SIEMPRE, ANTES de llamar a la fc recursiva
    Ejercicio
    1 Cadena = "Hola"
    que la funcion muestre:
    poner asterisco antes y despues
    *
    h   a   h   h    hola    a       hola
    o   l   o   o    ola     la      hol
    l   o   l   l    la      ola     ho
    a   h   a   a            hola    h
    *       a   o
            l   h
            o
            h

    numer = 1234
        mostrar: 1, 2, 3 , 4
                4,3,2,1
                1234, 123, 12, 1
                1, 12, 123, 1234
                1234, 123, 12, 1, 12, 123, 1234
                1234, 234, 34, 4
                4, 34, 234,123

    fc(nro, caracter)
        fc(4, *)
    ****, ***, ** , *
    *, **, ***, ****

    fc muestre el numero en otra base ( nombase 10, base destino)
    fc(4,2)
    1   0   0
    fc(4,4)
    fc(4,16)

    dada una lista simple enlazada, mostrarla en orden inverso
    ***/
}

void funciones()
{
    char cad[] = "neuquen",
                 cadBinaria[] = "123456789",
                                carBin='9';
    int num = 1756,
        num_fac=9,
        num1_mcd = 19,
        num2_mcd = 0 ;
    printf("Iterativo\tEl factorial de %d es %.2f\n",num_fac,factorialI(num_fac));
    printf("Recursivo\tEl factorial de %d es %.2f\n",num_fac,factorialI(num_fac));
    printf("Orden normal\n*\n");
    cadenaOrden(cad);
    printf("*\n");
    printf("Orden inverso\n*\n");
    cadenaOrdenInverso(cad);
    printf("*\n");
    printf("normal inverso\n*\n");
    cadenaNormalInverso(cad);
    printf("*\n");
    printf("Mostrar Holaoh\n*\n");
    cadenaNormalInversoIncompleto(cad);
    printf("*\n");
    printf("Mostrar \nHola\nola\nla\n*\n");
    cadenaPalabraDecre(cad);
    printf("*\n");
    printf("Mostrar \na\nla\nola\nHola\n*\n");
    cadenaPalabraInversoDecre(cad);
    printf("*\n");
    printf("------------Mostrar \nHola\nHol\nHo\nH\n*\n");
    cadenaPalabraDecre2(cad);
    printf("*\n");
    /*******************************************************/
    printf("Mostrar %d\n*\n",num);
    mostrearNumEntero(num);
    printf("*\n");
    printf("Mostrar %d al revés\n*\n",num);
    mostrearNumEnteroInv(num);
    printf("*\n");
    printf("Mostrar %d decreciente\n*\n",num);
    mostrearNumDec(num);
    printf("*\n");
    printf("Mostrar %d creciente pero al revés\n*\n",num);
    mostrearNumCreInv(num);
    printf("*\n");
    printf("Mostrar %d decreciente y creciente\n*\n",num);
    mostrarNumEnteroInverso(num);
    printf("*\n");
    printf("Mostrar %d decreciente izquierda a derecha\n*\n",num);
    mostrarNumDecIzqDer(num);
    printf("*\n");
    printf("Mostrar %d decreciente Derecha a izquierda\n\n",num);
    mostrarNumDecDerIzq(num);
    /*********************************************************/
    printf("\n\nEl cambio de base de %d a base %d es ",num,3);
    cambioDeBase(num,9);
    printf("\n\n");
    if(esPalindromoRec(cad))
        printf("Es palindromo\n");
    else
        printf("No es palindromo\n");
    system("pause");
    printf("La cadena %s tiene %d caracteres\n",cad, strlenRecursiva(cad));
    printf("El MCD enter %d y %d es %d\n",num1_mcd, num2_mcd,calcularMCD(num1_mcd,num2_mcd) );

    printf("%s encontro el valor %c\n",busquedaBinariaRecursiva(cadBinaria,carBin)? "Se": "No",carBin);
}

