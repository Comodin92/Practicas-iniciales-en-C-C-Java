#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
int insertar_tamanio_vector()
{
// Solicita por pantalla el ingreso del tamaño del vector
    int t;
    printf("Ingrese tamano del vector: ");
    scanf("%d", &t);
    return t;
}
void cargar_vector(int *v, int tam)
{
// Se carga el vector de un tamaño dado
    int i;
    printf("\nCargar Vector:\n");
    for(i=0;i<tam;i++)
    {
        printf("\r");
        scanf("%d",(v+i));
    }
}
void mostrar_vector(int *v, int tam)
{
    int i;
    printf("\n[");
    for (i = 0 ; i<tam ; i++)
        printf(" %d ", *(v+i));
    printf("]\n");
}
void insertar_en_pos(int *v, int pos, int elem)
{
// Función que inserta un elemento en una posición dada
// de un arreglo de enteros
    int aux, i = 0;
    pos--;
    do
    {
        aux = *(v+pos+i);
        *(v+pos+i) = elem;
        elem = aux;
        i++;
    } while (*(v+pos+i));
    *(v+pos+i) = elem;
}
void insertar_en_orden_vec(int v[], int n, int tam)
{
// Función que inserta un elemento en orden ascendente
// de un arreglo de enteros
    int i,marca=0;
    for (i=0;i<tam;i++)
    {
        if ((n< v[i])&& marca==0)
        {
           desplazamiento_derecha(v,i,tam);
           v[i]=n;
           marca=1;
        }
    }
}
void desplazamiento_derecha (int v[], int pos, int tam)
{
    int i;
    for (i=tam-1;i>=pos-1;i--)
         v[i+1]=v[i];
}
void desplazamiento_izquierda (int v[], int pos, int tam)
{
    int i;
    for (i=pos-1;i<tam-1;i++)
         v[i]=v[i+1];

}
void eliminar_de_posicion (int v[],int pos, int tam)
{
// Elimina un elemento de un arreglo dada la posición
    desplazamiento_izquierda(v,pos,tam);
}
int eliminar_1era_aparicion(int *v, int num, int tam)
{
// Elimina la primera aparición de un elemento en un arreglo de enteros
	int i,aux;
    for(i=0;i<tam;i++)
        if(num == *(v+i))
      	{
            aux=*(v+i);
            *(v+i)=*(v+i+1);
            *(v+i+1)=aux;
         }
        return 1;
}
int eliminar_todas_apariciones(int v[], int elem, int tam)
{
    int i, cont = 0;
    for (i=0;i<tam;i++)
    {
        if (elem == v[i])
            cont++;
        else
            v[i-cont] = v[i];
    }
    return cont;
}
