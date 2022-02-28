#include <stdio.h>
#include <stdlib.h>
#include "../Bibiotlecas/vectores.h"

int main()
{
    int vec[TAM]={1,2,2,1},opc,num,pos,ce=4,tam=20;
    char nume[TAM]={"5184"};
    do{
            printf("\t\tTRABAJO PRACTICO 1\n\n\tMATEMATICAS\nIndique el numero de ejercicio\nEjercicio 22\nEjercicio 23\n"
                  "Ejercicio 24\nEjercicio 25\nEjercicio 26(Sin hacer\nEjercicio 27\nEjercicio 28 (Verificar 6*100=599\n0-Salir\n");
            scanf("%d",&opc);


    switch(opc)
    {

    case 22:

        printf("Enunciado\nInserte un elemento en un arreglo de enteros, dada la posicion de insercion\n");
        printf("Ingrese numero a insertar y la posicion\n");
        scanf("%d%d",&num,&pos);
        printf("Vector antes de insertar\n");
        mostrarVector(vec,ce);
        if(insertarEnPosicion(vec,num,&ce,tam,pos))
        {
                printf("Vector luego de insertar\n");
                mostrarVector(vec,ce);
        }
        else
            printf("Imposible ingresar\n");
        break;

    case 23:
        printf("Enunciado\nInserte un elemento en un arreglo de enteros, sin alterar el orden\n");
        printf("Ingrese numero a insertar\n");
        scanf("%d",&num);
        printf("Vector antes de insertar\n");
        mostrarVector(vec,ce);
        if(insertarEnOrden(vec,num,&ce,tam))
            {
                printf("Vector luego de insertar\n");
                mostrarVector(vec,ce);

            }
        else
            printf("Imposible ingresar\n");
        break;

    case 24:
        printf("Enunciado\nBorrar un elemento en un arreglo de enteros, dado una posicion\n");
        printf("Ingrese posicion a eliminar\n");
        scanf("%d",&pos);
        printf("Vector antes de borrar\n");
        mostrarVector(vec,ce);
        if(eliminarElementoPosi(vec,&ce,tam,pos))
        {   printf("Vector luego de borrar\n");
            mostrarVector(vec,ce);
        }
        else
            printf("Imposible borrar\n");
        break;


    case 25:
        printf("Enunciado\nEliminar la primer aparicion de un  elemento en un arreglo de enteros\n");
        printf("Ingrese numero a borrar\n");
        scanf("%d",&num);
        printf("Vector antes de borrar\n");
        mostrarVector(vec,ce);
        if(BorrarPrimerAparicion(vec,&ce,num,tam))
        {
            printf("Vector luego de borrar\n");
            mostrarVector(vec,ce);

        }
        else
            printf("Imposible borrar\n");

        break;
    case 27:
        printf("Enunciado\nDeterminar si una array es palindromo\n");
        printf("Vector:\n");
        mostrarVector(vec,ce);
        if(esPalindromo(vec,&ce,tam))
            printf("Es palindromo\n");
        else
            printf("No es palindromo\n");
        break;
    case 28:
        printf("Enunciado\nDevolver el valor numerico de una cadena de caracteres\n");
        printf("El valor numerico es: %d\n",devolverValorNumerico(nume));

        system("pause");

    }

    }while(opc != 0);
    return 0;
}
