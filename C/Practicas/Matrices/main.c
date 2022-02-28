#include "main.h"
#include "ejercicioMatrices.h"

int main()
{
    verMenu();
    return 0;
}

void verMenu()
{
    int m[FIL][COL];
    int opcion;
    do
    {
        printf("1 - Mostrar matris\n2 - crearMatriz\n3 - Mostrar Diagonal Principal\n4 - Mostrar Diagonal Secundaria"
               "\n5 - VerTrianguloSupDP\n6 - verTrianguloInfDP\n7 - VerTrianguloSupDS\n8 - verTrianguloInfDS\n"
               "9 - Ver vecinos dados i, j validos\n10 - Mostras triangulo por encima de ambas diagonales (T1)\n"
               "11 - T2 - NO \n12 - T3 - NO\n13 - T4 NO\n14 - Simetrica respecto diagonal principal\n"
               "15 - Simetrica respecto diagonal secundaria\n16 - Transponer en si misma\n17 - Matriz escalar\n"
               "18 - Matriz identidad\n19 - Recorrer matriz como diagonal secundaria - recorre solo hasta diagonal"
               "principal\n"
               " \n\n\n");
        printf("0 - Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
        {
            llamarMostrarMat(m, FIL, COL);
                        mostrarMatConEspacios(m, FIL, COL);

            system("pause");
            break;
        }
        case 2:
        {
            llenarMatriz(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);

            system("pause");
            break;
        }
        case 3:
        {
            llamarMostrarMat(m, FIL, COL);
            llamarMostrarDP(m, FIL, COL);
            system("pause");
            break;
        }
        case 4:
        {
            llamarMostrarMat(m, FIL, COL);
            llamarMostrarDS(m,FIL, COL);
            system("pause");
            break;
        }
        case 5:
        {
            llamarMostrarTrianguloSupDP(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 6:
        {
            llamarMostrarTrianguloSupDS(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 7:
        {
            llamarMostrarTrianguloSupDS(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 8:
        {
            llamarMostrarTrianguloInfDS(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 9:
        {
            llamarMostrarVecinos(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
         case 10:
        {
            llamarMostrarT1(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 11:
        {
            llamarMostrarT2(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 12:
        {
            llamarMostrarT3(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 13:
        {
            llamarMostrarT4(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
         case 14:
        {
            llamarEsSimetricaDP(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 15:
        {
            llamarEsSimetricaDS(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 16:
        {
            llamarTransponer(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 17:
        {
            llamaresEscalar(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 18:
        {
            llamaresEsIdentidad(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        case 19:
        {
            llamaresRecorrerComoDiagonalSecundaria(m, FIL, COL);
            llamarMostrarMat(m, FIL, COL);
            system("pause");
            break;
        }
        }
        system("cls");
    }
    while(opcion != 0);
}

void llamarMostrarMat(int m[][COL], const int fila, const int columna)
{
    printf("La matriz es: \n");
    mostrarMat(m, fila, columna);
}
void llamarMostrarDP(int m[][COL], const int fila, const int columna)
{
    printf("La Diagonal principal es:\n");
    mostrarDP(m, fila, columna);
}

void llamarMostrarDS(int m[][COL],const int fila, const int columna)
{
    printf("La diagonal secundaria es:\n");
    mostrarDS(m, fila, columna);
}
void llamarMostrarTrianguloSupDP(int m[][COL],const int fila, const int columna)
{
    printf("El triangulo superior respecto a diagonal principal\n");
    mostrarTrianguloSupDP(m,fila,columna);
}

void llamarMostrarTrianguloInfDP(int m[][COL],const int fila, const int columna)
{
    printf("El triangulo inferior respecto a diagonal principal:\n");
    mostrarTrianguloInfDP(m, fila, columna);
}

void llamarMostrarTrianguloSupDS(int m[][COL],const int fila, const int columna)
{
    printf("El triangulo superior respecto a diagonal secundaria:\n");
    mostrarTrianguloSupDS(m, fila, columna);
}

void llamarMostrarTrianguloInfDS(int m[][COL],const int fila, const int columna)
{
    printf("El triangulo inferior respecto a diagonal secundaria:\n");
    mostrarTrianguloInfDS(m, fila, columna);
}

void llamarMostrarVecinos(int m[][COL], const int fila, const int columna)
{
    int snr_i, snr_j;
    do
    {
        printf("Ingrese i j para verificar sus vecinos, es una matriz de orden %d\n",fila);
        scanf("%d%d",&snr_i, &snr_j);
    }while((snr_i >= 0 && snr_i >= fila) || ( snr_j >= 0 && snr_j >= columna));
    mostrarVecinos(m,fila,columna,snr_i, snr_j);
}

void llamarMostrarT1(int m[][COL], const int fila, const int columna)
{
    printf("el triangulo por encima de la diagonal principal y la diagonal secundaria (T1)|n");
    mostrarT1(m, fila, columna);
}

void llamarMostrarT2(int m[][COL], const int fila, const int columna)
{
    printf("el triangulo a la derecha de la diagonal principal y secundaria (T1)|n");
    mostrarT2(m, fila, columna);
}

void llamarMostrarT3(int m[][COL], const int fila, const int columna)
{
    printf("el triangulo por debajo de la diagonal principal y secundaria (T1)|n");
    mostrarT3(m, fila, columna);
}

void llamarMostrarT4(int m[][COL], const int fila, const int columna)
{
    printf("el triangulo a la izquierda de la diagonal principal y secundaria (T1)|n");
    mostrarT4(m, fila, columna);
}

void llamarEsSimetricaDP(int m[][COL], const int fila, const int columna)
{
    printf("La matriz %s simetrica respecto diagonal principal\n",esSimetricaDP(m,fila,columna)?"es":"no es");
}

void llamarEsSimetricaDS(int m[][COL], const int fila, const int columna)
{
    printf("La matriz %s simetrica respecto diagonal secundaria\n",esSimetricaDS(m,fila,columna)?"es":"no es");
}

void llamarTransponer(int m[][COL], const int fila, const int columna)
{
    transponer(m, fila, columna);
    mostrarMat(m,fila,columna);
}
void llamaresEscalar(int m[][COL], const int fila, const int columna)
{
    printf("La matriz %s escalar\n",esEscalar(m,fila, columna)? "es" : "no es");

}

void llamaresEsIdentidad(int m[][COL], const int fila, const int columna)
{
    printf("La matriz %s identidad\n",esIdentidad(m,fila, columna)? "es" : "no es");

}

void llamaresRecorrerComoDiagonalSecundaria(int m[][COL], const int fila, const int columna)
{
    recorrerComoDiagonalSecundaria(m,fila, columna);

}

