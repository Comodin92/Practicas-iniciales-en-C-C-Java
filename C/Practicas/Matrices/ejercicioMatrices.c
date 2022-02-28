#include "ejercicioMatrices.h"
#include "main.h"

void llenarMatriz(int m[][COL], const int fila, const int columna)
{
    int i, j,num=1;
    for (i = 0 ; i < fila ; i++)
    {
        for(j = 0 ; j < columna ; j++)
            m[i][j] = num++;
    }
}

void mostrarMat(int m[][COL], const int fila, const int columna)
{
    int i, j;
    for(i = 0 ; i < fila ; i++)
    {
        for( j = 0 ; j < columna ; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }
    printf("\n\n\n");
}

void mostrarDP(int m[][COL], const int fila, const int columna)
{
    int i;
    for(i = 0 ; i < fila ; i++)
        printf("%d\t",m[i][i]);
    printf("\n\n\n");
}

void mostrarDS(int m[][COL], const int fila, const int columna)
{
    int i;
    for(i = 0 ; i < fila ; i++)
        printf("%d\t",m[i][columna-1-i]);
    printf("\n\n\n");
}

void mostrarTrianguloSupDP(int m[][COL], const int fila, const int columna)
{
    int i,
        j;
    for(i = 0 ; i <fila ; i++)
    {
        for(j = i + 1 ; j < columna ; j++)
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}

void mostrarTrianguloInfDP(int m[][COL], const int fila, const int columna)
{
    int i,
        j;
    for(i = 1 ; i < fila ; i++)
    {
        for(j = 0 ; j < i ; j++)
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}

void mostrarTrianguloSupDS(int m[][COL],const int fila, const int columna)
{
    int i,
        j;
    for ( i = 0 ; i < fila-1 ; i++)
    {
        for(j = 0 ; j < columna - i - 1; j++)
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}

void mostrarTrianguloInfDS(int m[][COL],const int fila, const int columna)
{
    int i,
        j;
    for( i = 1 ; i < fila ; i++)
    {
        for(j = columna - i ; j < columna  ; j ++ )
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}

void mostrarVecinos(int m[][COL],
                    const int fila, const int columna,
                    const int snr_i, const int snr_j)
{
    int i,
        j;

    for(i = ES_MINIMO(snr_i); i <= ES_MAXIMO(snr_i); i++)/// i <= (snr_i == fila-1)? snr_i: snr_i + 1
    {
        for(j =  ES_MINIMO(snr_j) ; j <= ES_MAXIMO(snr_j); j++) ///(snr_j == columna-1)? snr_j: snr_j + 1
        {

            if( i == snr_i && j == snr_j)
                printf("\t");
            else
                printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

void mostrarT1(int m[][COL], const int fila, const int columna)
{
    int i,
        j;
    for(i = 0 ; i < fila/2 ; i++) ///<= para incluir diagonal
    {
        for(j = i + 1 ; j < columna - 1 - i ; j++) ///<= para incluir diagonal
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}

void mostrarT2(int m[][COL], const int fila, const int columna)
{
    int i,
        j;
    for(i = 1 ; i <  fila - 1; i++) ///<= para incluir diagonal
    {
        for(j = (columna/2) + 1 ; j < columna && i< j ; j++) ///<= para incluir diagonal
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}

void mostrarT3(int m[][COL], const int fila, const int columna)
{
    int i,
        j;
    for(i = (fila/2) +1  ; i < fila ; i++)  ///<= para incluir diagonal
    {
        for(j = columna - i ;  j < columna && i < j ;j++) ///<= para incluir diagonal
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}
void mostrarT4(int m[][COL], const int fila, const int columna)
{
    int i,
        j;
    for(i = (fila/2) +1  ; i < fila ; i++)  ///<= para incluir diagonal
    {
        for(j = columna - i ;  j < columna && i < j ;j++) ///<= para incluir diagonal
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}

int esSimetricaDP(int m[][COL],const int fila,const int columna)
{
    int i,
        j;
    for(i = 0 ; i < fila - 1 ; i++)
    {
        for( j = i + 1 ; j < columna ; j++)
            if(m[i][j] != m[j][i])
                return 0;
    }
    return 1;
}

int esSimetricaDS(int m[][COL],const int fila,const int columna)
{
    int i,
        j;
    for(i = 0 ; i < fila - 1 ; i++)
    {
        for(j = 0 ;  j < columna - i - 1 ; j++ )
            if(m[i][j] != m[j][i])
                return 0;
    }
    return 1;
}


void transponer(int m[][COL], const int fila, const int columna)
{
    int i,
        j,
        aux;
    for(i = 0 ; i < fila - 1 ; i++)
    {
        for( j = i + 1 ; j < columna ; j++)
        {
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}

int esEscalar(int m[][COL],const int fila, const int columna)
{
    int i,
        aux = m[0][0];

    for(i = 1 ; i < fila ; i++)
        if(aux != m[i][i])
            return 0;
    return 1;
}


int esIdentidad(int m[][COL],const int fila, const int columna)
{

    int i;
    for(i = 0 ; i < fila ; i++)
        if( m[i][i] != 1)
            return 0;
    return 1;
}
void mostrarMatConEspacios(int m[][COL], const int fila, const int columna)
{/**
    7   8   9   10  11  21
        5   7   6   3   1
            12  3   5   6
                6   8   7
                    8   9
                        1
    **/
    int i, j, cont=10;
    for(i=0; i < fila ; i++)
    {
        for(j=0; j<columna ; j++)
            m[i][j] = cont++;
    }
    for(i=0; i<fila; i++)
    {
        printf("%*s",(i)*sizeof(int),"");
        for(j=i; j<columna; j++)
            printf("%3d ",m[i][j]);
        printf("\n");
    }


}
void recorrerComoDiagonalSecundaria(int m[][COL],const int fila, const int columna)
{
    int i,
        j,
        aux;
    for( i = 0 ; i < fila ; i++)
    {
        aux = i;
        for( j = 0 ; j <= i ; j++)
           {
               printf("%d\t",m[aux--][j]);
               ///aux -- ;

           }
        printf("\n");
    }
    ///como ya se que i quedó en 4, no hace falta usar dos for, con uno solo que decremente la j es suficiente
    ///aux = i;
//    if()
//    for( j = ++aux ; j < columna ; j++ )
//    {
//        printf("%d\t", m[i][j]);
//
//    }
//

}
