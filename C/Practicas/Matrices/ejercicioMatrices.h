#ifndef EJERCICIOMATRICES_H_INCLUDED
#define EJERCICIOMATRICES_H_INCLUDED
#define FIL 5
#define COL 5
#define ES_MINIMO(X) ((X)==0)? (X) : (X) - 1
#define ES_MAXIMO(X) ((X)== (COL-1)? (X) : (X)+1 )

void llenarMatriz(int v[FIL][COL], const int fila, const int columna);
void mostrarMat(int m[][COL], const int fila, const int columna);
void mostrarDP(int m[][COL], const int fila, const int columna);
void mostrarDS(int m[][COL], const int fila, const int columna);
void mostrarTrianguloSupDP(int m[][COL], const int fila, const int columna);
void mostrarTrianguloInfDP(int m[][COL],const int fila, const int columna);
void mostrarTrianguloSupDS(int m[][COL],const int fila, const int columna);
void mostrarTrianguloInfDS(int m[][COL],const int fila, const int columna);
void mostrarVecinos(int m[][COL],const int fila, const int columna,const int snr_i, const int snr_j);
void mostrarT1(int m[][COL], const int fila, const int columna);
void mostrarT2(int m[][COL], const int fila, const int columna);
void mostrarT3(int m[][COL], const int fila, const int columna);
void mostrarT4(int m[][COL], const int fila, const int columna);
int esSimetricaDP(int m[][COL],const int fila,const int columna);
int esSimetricaDS(int m[][COL],const int fila,const int columna);
void transponer(int m[][COL], const int fila, const int columna);
int esEscalar(int m[][COL],const int fila, const int columna);
int esIdentidad(int m[][COL],const int fila, const int columna);
void recorrerComoDiagonalSecundaria(int m[][COL],const int fila, const int columna);
void mostrarMatConEspacios(int m[][COL], const int fila, const int columna);



#endif // EJERCICIOMATRICES_H_INCLUDED
