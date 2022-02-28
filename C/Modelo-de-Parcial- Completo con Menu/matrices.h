#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#define TAMM 50

int orden();
void cargar_matriz(int *m, int);
void mostrar_matriz(int * m, int);
int simetrica(int *m, int);
int identidad(int *m, int);
int suma_princ(int *, int);
int suma_secund(int *, int);
int suma_arriba_princ(int *, int);
int suma_abajo_princ(int *, int);
int suma_arriba_secund(int *, int);
int suma_abajo_secund(int *, int);
void transponer(int * , int);

void mostrar_matriz_gen(int [][TAMM], int , int );
int simetrica_gen(int [][TAMM], int, int);

int simetrica_gen(int [][TAMM], int, int);
int suma_arriba_princ_gen (int [][TAMM], int, int);
int suma_arriba_secund_gen ( int [][TAMM], int, int);


///nuestras
void multiplicar( int [][TAMM], int [][TAMM], int [][TAMM], int, int, int );
void mostrarMatriz( int [][TAMM], int, int );
void ingresarMatriz( int [][TAMM], int, int );

int sumaSobreDiagP( int [][TAMM], int );
int sumaSobreDiagPIncluida( int [][TAMM], int );
int sumaBajoDiagP( int [][TAMM], int );
int sumaBajoDiagPIncluida( int [][TAMM], int );
int traza( int [][TAMM], int );

int sumaSobreDiagS( int [][TAMM], int );
int sumaSobreDiagSIncluida( int [][TAMM], int );
int sumaBajoDiagS( int [][TAMM], int );
int sumaBajoDiagSIncluida( int [][TAMM], int );
int trazaS( int [][TAMM], int );

int esDiagonal( int [][TAMM], int );
int esIdentidad( int [][TAMM], int );

int simetricaP( int [][TAMM], int );
int simetricaS( int [][TAMM], int );
void transpuesta( int [][TAMM], int );
#endif // MATRICES_H_INCLUDED
