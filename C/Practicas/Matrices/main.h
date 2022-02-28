#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "ejercicioMatrices.h"
#include <stdio.h>
#include <stdlib.h>


void verMenu();
void llamarMostrarMat(int m[][COL], const int fila, const int columna);
void llamarMostrarDP(int m[][COL],const int fila, const int columna);
void llamarMostrarDS(int m[][COL],const int fila, const int columna);
void llamarMostrarTrianguloSupDP(int m[][COL],const int fila, const int columna);
void llamarMostrarTrianguloInfDP(int m[][COL],const int fila, const int columna);
void llamarMostrarTrianguloSupDS(int m[][COL],const int fila, const int columna);
void llamarMostrarTrianguloInfDS(int m[][COL],const int fila, const int columna);
void llamarMostrarVecinos(int m[][COL], const int fila, const int columna);
void llamarMostrarT1(int m[][COL], const int fila, const int columna);
void llamarMostrarT2(int m[][COL], const int fila, const int columna);
void llamarMostrarT3(int m[][COL], const int fila, const int columna);
void llamarMostrarT4(int m[][COL], const int fila, const int columna);
void llamarEsSimetricaDP(int m[][COL], const int fila, const int columna);
void llamarEsSimetricaDS(int m[][COL], const int fila, const int columna);
void llamarTransponer(int m[][COL], const int fila, const int columna);
void llamaresEscalar(int m[][COL], const int fila, const int columna);
void llamaresEsIdentidad(int m[][COL], const int fila, const int columna);
void llamaresRecorrerComoDiagonalSecundaria(int m[][COL], const int fila, const int columna);





#endif // MAIN_H_INCLUDED
