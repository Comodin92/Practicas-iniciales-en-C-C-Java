#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matematicas.h"

double factorial(int n)
{
// Función que calcula el factorial de un numero entero
// Precondición: n es mayor o igual a 0
    if(n < 2)   // 0! = 1 ; 1! = 1
        return 1;
    else  // n es mayor o igual a 2
        return n * factorial(n-1);
}

int combinatorio(int m, int n)
{
// Función que calcula el combinatorio m sobre n
// Precondición:    n es mayor o igual a 0
//                  m es mayor o igual a n
    return (factorial(m)/(n * factorial(m-n)));
}

double e_a_la_x(int x, float tol)
{
// Función que calcula e a la x
// El proceso termina cuando se obtiene un término
// calculado que sea menor que la tolerancia
    int i = 1;
    double aux = 1, res;
    while((res = ((pow(x,i))/(factorial(i)))) > tol)
    {
        aux += res;
        i++;
    }
    return aux;
}

float raizcuadrada(float x, float tol)
{
// Función que calcula la raíz cuadrada de un número positivo
// Precondición: x mayor o igual a 0
// El proceso termina cuando la diferencia de dos términos
// consecutivos es menor que la tolerancia
    float aux = 1, aux1;
    aux1 = 0.5 * ( (aux) + ( x / (aux) ) );
    while( fabs(aux1-aux) > tol )
    {
        aux = aux1;
        aux1 = 0.5 * ( (aux) + ( x / (aux) ) );
    }
    return aux;
}

int fibonacci(int x)
{
// Función que determina sí un entero pertence a la serie de Fibonacci
// Precondición: x mayor o igual a 1
    int cont = 0;
    long a = 0, b = 1, aux, fibo = 0;
    while(fibo < x)
    {
        aux = a;
        fibo = a + b;
        if(x == fibo)
            cont++;
        a += b;
        b = aux;
    }
    return cont;
}

float seno(float x, float tol)
{
// Función que calcula el seno de un número x (en radianes)
// El proceso termina cuando se obtiene un término
// calculado (en valor absoluto) que sea menor que la tolerancia
    int i = 1;
    float aux = 0, aux1;
    aux1 = (-(pow((-1),i) * (pow(x,(2*i-1))) / factorial(2*i-1)));
    while(fabs(aux1) > tol)
    {
        aux += aux1;
        i++;
        aux1 = (-(pow((-1),i) * (pow(x,(2*i-1))) / factorial(2*i-1)));
    }
    return aux;
}

int clasificacion(int x)
{
// Función que determina sí un número natural es PERFECTO, DEFICIENTE o ABUNDANTE
// Precondición: x (Número Natural)
// Devuelve 0 si es PERFECTO, -1 si es DEFICIENTE y 1 si es ABUNDANTE
    int i,suma = 0;
	for( i=1 ; i<x ; i++ )
    {
        if((x%i) == 0)
            suma += i;
	}
	return (suma==x?0:suma<x?-1:1);
}

long int multiplicacion(int x1, int x2)
{
// Función que calcula el producto por sumas sucesivas
// de dos números naturales
    long int suma = 0, i;
    for( i=0 ; i<x2 ; i++ )
        suma += x1;
    return suma;
}

void cocienteyresto(int a, int b, int *cociente, int *resto)
{
// Función que obtiene el cociente entero A/B y el resto
// Precondición: B no puede ser 0
    *cociente = a/b;
    *resto = a%b;
}

int suma_primeros_naturales(int x)
{
// Función que calcula la suma de los primeros N
// números naturales
// Precondición: x (NÚMERO NATURAL)
    int i, suma = 0;
	for( i=0 ; i<=x ; i++ )
        suma += i;
    return suma;
}

int suma_primeros_pares(int x)
{
// Función que calcula la suma de los primeros N
// números pares
// Precondición: x (NÚMERO NATURAL)
    int i = 0, suma = 0;
    for( i=0 ; i<=2*x ; i++ )
    {
        if((i%2) == 0)
            suma += i;
    }
    return suma;
}

int suma_pares_menores(int x)
{
// Función que calcula la suma de los números pares menores que x
// Precondición: x (NÚMERO NATURAL)
    int i = 0, suma = 0;
    for( i=0 ; i<x ; i++ )
    {
        if((i%2) == 0)
            suma += i;
    }
    return suma;
}

int primo(int x)
{
// Función que determina sí un número natural es primo
// Precondición: x (NÚMERO NATURAL)
    int i, aux = 0;
	for( i=1 ; i<=x ; i++ )
    {
        if((x%i) == 0)
            aux++;
    }
    return(aux <= 2?1:0);   // Sí devuelve 2 o menos es primo
}

int multiplicacion_rusa(int x1,int x2)
{
// Obtiene el producto de dos números naturales
// Precondición: x1 y x2 (NÚMEROS NATURALES)
    int producto = 0;
    while(x1 >= 1)
    {
        if((x1%2) != 0)
            producto += x2;
        x2 = x2*2;
        x1 = x1/2;
    }
    return producto;
}

int parte_entera(float a)
{
// Función que obtiene la parte entera de un número real
    return (int)a;
}
