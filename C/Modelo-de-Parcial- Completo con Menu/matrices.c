#include <stdio.h>
#include <stdlib.h>

#include "matrices.h"

int orden()
{
// Solicita por pantalla el ingreso del orden de la matriz
    int o;
    printf("Ingrese orden: ");
    scanf("%d", &o);
    return o;
}

void cargar_matriz(int *m, int orden)
{
// Se carga la matriz de un orden dado
    int i,j;
    printf("\nCargar Matriz:\n");
    for(i=0;i<orden;i++)
    {
        for(j=0;j<orden;j++)
            scanf("%d",(m+i*orden+j));
    printf("\n");
    }
}

void mostrar_matriz(int *m, int orden)
{
// Se muestra la matriz de un orden dado
    int i,j;
    for(i=0;i<orden;i++)
    {
        for(j=0;j<orden;j++)
            printf("%5d",*(m+i*orden+j));
    printf("\n");
    }
}

int simetrica(int *m, int orden)
{
//  Verifica sí una matriz de orden dado es simetrica
    int i,j;
    for(i=0;i<orden;i++)
        for(j=0;j<orden;j++)
        if (*(m+i*orden+j) != *(m+j*orden+i))
            return 0;
    return 1;
}

int identidad(int *m, int orden)
{
// Verifica sí una matriz de orden dado es una matriz identidad
    int i,j;
    for(i=0;i<orden;i++)
        for(j=0;j<orden;j++)
                if((i==j && *(m+i*orden+j)!=1)||(i!=j && *(m+i*orden+j)!=0))
         	return 0;
   return 1;
}

int suma_princ(int *m, int orden)
{
// Suma los elementos de la diagonal principal de una matriz de enteros de orden dado
	int i,j,suma=0;
   for(i=0;i<orden;i++)
   	for(j=0;j<orden;j++)
      	if(i==j)
         	suma += *(m + i*orden + j);
   return suma;
}

int suma_secund(int *m, int orden)
{
// Suma los elementos de la diagonal secundaria de una matriz de enteros de orden dado
	int i,j,suma=0,n=0,x=(orden-1);
    for(i=0;i<orden;i++)
        for(j=0;j<orden;j++)
            if(i==n && j==x )
            {
         	suma += *(m + i*orden + j);
            n++;
            x--;
            }
   return suma;
}

int suma_arriba_princ(int *m, int orden)
{
// Suma los elementos por encima de la diagonal principal en una matriz de orden dado
	int i,j,suma=0;
    for(i=0;i<orden;i++)
        for(j=0;j<orden;j++)
            if(i<j)
                suma += *(m + i*orden + j);
    return suma;
}

int suma_abajo_princ(int *m, int orden)
{
// Suma los elementos por debajo de la diagonal principal de una matriz de orden dado
	int i,j,suma=0;
    for(i=0;i<orden;i++)
        for(j=0;j<orden;j++)
            if(i>j)
                suma += *(m + i*orden + j);
    return suma;
}

int suma_arriba_secund(int *m, int orden)
{
// Suma los elementos por encima de la diagonal secundaria en una matriz de orden dado
	int i,j,suma=0,n=0,x=(orden-1);
    for(i=0;i<orden;i++)
    {
        for(j=0;j<orden;j++)
            if(i==n && j<x)
                suma += *(m + i*orden + j);
        n++;
        x--;
    }
    return suma;
}

int suma_abajo_secund(int *m, int orden)
{
// Suma los elementos por debajo de la diagonal secundaria de una matriz de orden dado
	int i,j,suma=0,n=(orden-1),x=(orden-1);
    for(i=0;i<orden;i++)
    {
        for(j=0;j<orden;j++)
            if(i<n && n!=0 && j>x)
                suma += *(m + i*orden + j);
        n++;
        x--;
    }
    return suma;
}

void transponer(int *m , int orden)
{
    int i,j,cont=0,aux;
    for(i=0;i<orden;i++)
    {
        for(j=(0+cont);j<orden;j++)
        {
            aux=*(m+i*orden+j);
            *(m+i*orden+j)=*(m+j*orden+i);
            *(m+j*orden+i)=aux;
        }
        cont++;
    }

}

///FUNCIONES REPETIDAS REPASANDO PARA PARCIAL
/**
void mostrar_matriz_gen(int matriz [][TAMM], int fila, int col)
{
    int i,
        j;
    for (i=0;i<fila;i++)
        for (j=0;i<col;j++)
            printf ("\t%d",matriz[i][j]);
    printf("\n");
}

int simetrica_gen(int matriz[][TAMM], int fila, int col)
{
    int i,
        j;
    for( i=0 ; i<fila ; i++)
        for( j=0 ; j<col ; j++)
            if( matriz[i][j] != matriz [fila-i][col-j])
                return 0;
    return 1;
}

int suma_arriba_princ_gen (int matriz[][TAMM], int fila, int col)
{
    int i,
        j,
        suma = 0;
    for( i=0 ; i<fila ; i++)
        for( j=0 ; j<col ; j++)
            if( i < j )
                suma = suma + matriz[i][j];
    return suma;
}

int suma_arriba_secund_gen ( int matriz [][TAMM], int fila, int col)
{
    int i,
        j,
        x,
        suma = 0;
    if (fila != col)
        return -1;
    x = fila-1;

    for ( i=0 ; i<fila ; i++)
    {
        for ( j=0 ; j<col ; j++)
            if ( j<x )
                suma = suma + matriz [i][j];
    --x;
    }
    return suma;
}
**/

///FUNCIONES HECHAS EN 2015 2DO CUATRI NUESTRAS

void multiplicar( int m1[][TAMM], int m2[][TAMM], int res[][TAMM], int fi, int fico, int co )
{
    int i, j, ciclo;

    for( i=0; i<fi; i++ )
    {
        for( j=0; j<co; j++ )
        {
            for( ciclo=0, res[i][j]=0; ciclo<fico; ciclo++ )
            {
                res[i][j] += m1[i][ciclo] * m2[ciclo][j];
            }
        }
    }
}

void mostrarMatriz( int m[][TAMM], int f, int c )
{
    int i, j;
    for( i=0; i<f; i++ )
    {
        printf("\n\t");
        for( j=0; j<c; j++ )
        {
            printf( "%d\t", m[i][j] );
        }
    }
    printf("\n\n");
}

void ingresarMatriz( int m[][TAMM], int f, int c )
{
    int i, j;
    for( i=0; i<f; i++ )
    {
        for( j=0; j<c; j++ )
        {
            printf("<%d,%d>: ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}

int sumaSobreDiagP( int m[][TAMM], int n )
{
    int s=0, i, j, e=1;
    for( i=0; i<n; i++ )
    {
        for( j=e; j<n; j++ )
        {
            s += m[i][j];
        }
        e++;
    }
    return s;
}


int sumaSobreDiagPIncluida( int m[][TAMM], int n )
{
    int s=0, i, j, e=0;
    for( i=0; i<n; i++ )
    {
        for( j=e; j<n; j++ )
        {
            s += m[i][j];
        }
        e++;
    }
    return s;
}

int sumaBajoDiagP( int m[][TAMM], int n )
{
    int s=0, i, j, e=n-2;
    for( i=n-1; i>0; i-- )
    {
        for( j=e; j>=0; j-- )
        {
            s += m[i][j];
        }
        e--;
    }
    return s;
}

int sumaBajoDiagPIncluida( int m[][TAMM], int n )
{
    int s=0, i, j, e=n-1;
    for( i=n-1; i>=0; i-- )
    {
        for( j=e; j>=0; j-- )
        {
            s+= m[i][j];
        }
        e--;
    }
    return s;
}


int sumaSobreDiagS( int m[][TAMM], int n )
{
    int i, j, e=n-1, s=0;
    for( i=0; i<n-1; i++ )
    {
        for( j=0; j<e; j++ )
        {
            s += m[i][j];
        }
        e--;
    }
    return s;
}
int sumaSobreDiagSIncluida( int m[][TAMM], int n )
{

    int i, j, e=n, s=0;
    for( i=0; i<n; i++ )
    {
        for( j=0; j<e; j++ )
        {
            s += m[i][j];
        }
        e--;
    }
    return s;

}
int sumaBajoDiagS( int m[][TAMM], int n )
{
    int i, j, s=0, e=1;
    for( i=n-1; i>0; i--)
    {
        for( j=e; j<n; j++ )
        {
            s += m[i][j];
        }
        e++;
    }
    return s;
}

int sumaBajoDiagSIncluida( int m[][TAMM], int n )
{
    int i, j, s=0, e=0;
    for( i=n-1; i>=0; i--)
    {
        for( j=e; j<n; j++ )
        {
            s += m[i][j];
        }
        e++;
    }
    return s;
}

int traza( int m[][TAMM], int n )
{
    int i=0, s=0;
    while( i < n )
    {
        s += m[i][i];
        i++;
    }
    return s;
}

int trazaS( int m[][TAMM], int n )
{
    int i=0, j=n-1, s=0;
    while( i < n )
    {
        s += m[i][j];
        i++;
        j--;
    }
    return s;
}

int esDiagonal( int m[][TAMM], int n )
{
    int i, j, e=1;
    for( i=0; i<n; i++ )
    {
        if( m[i][i] == 0 )
            return 0;
        for( j=e; j<n; j++ )
        {
            if( m[i][j] != 0 || m[j][i] != 0 )
                return 0;
        }
        e++;
    }
    return 1;
}

int esIdentidad( int m[][TAMM], int n )
{
    int i, j, e=1;
    for( i=0; i<n; i++ )
    {
        if( m[i][i] != 1 )
            return 0;
        for( j=e; j<n; j++ )
        {
            if( m[i][j] != 0 || m[j][i] != 0 )
                return 0;
        }
        e++;
    }
    return 1;
}
/*
int simetrica( int m[][TAMM], int n) //recorriendo por encima
{
    int i, j, e=1;
    for( i=0; i<n; i++ )
    {
        for( j=e; j<n; j++ )
        {
            if( m[i][j] != m[j][i] )
                return 0;
        }
        e++;
    }
    return 1;
}*/

int simetricaP( int m[][TAMM], int n) //recorriendo por debajo
{
    int i, j, e=n-2;
    for( i=n-1; i>0; i-- )
    {
        for( j=e; j>=0; j-- )
        {
            if( m[i][j] != m[j][i] )
                return 0;
        }
        e--;
    }
    return 1;
}

int simetricaS( int m[][TAMM], int n) //recorriendo por debajo
{
    int i, j, e=1;

    for( i=n-1; i>0; i-- )
    {
        for( j=e; j<n; j++ )
        {
            if( m[i][j] != m[n-j-1][n-i-1] )
                return 0;
        }
        e++;
    }
    return 1;
}

/*
int simetricaS( int m[][TAMM], int n) //recorriendo por encima
{
    int i, j, e=n-2;

    for( i=0; i<n-1; i++ )
    {
        for( j=e; j>0; j-- )
        {
            if( m[i][j] != m[n-j-1][n-i-1] )
                return 0;
        }
        e--;
    }
    return 1;
}*/

void transpuesta( int m[][TAMM], int n )
{
    int i, j, aux, e=1;

    for( i=0; i<n; i++ )
    {
        for( j=e; j<n; j++ )
        {
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
        e++;
    }
}

