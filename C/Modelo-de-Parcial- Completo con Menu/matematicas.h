#ifndef MATEMATICAS_H_INCLUDED
#define MATEMATICAS_H_INCLUDED

#define esPar(X) ((X)%2 == 0 ? 1:0)
#define esImpar(X) ((X)%2 == 0 ? 0:1)
#define max( X, Y ) ( ( X ) > ( Y ) ? ( X ) : ( Y ) )
#define abs( X ) ( ( X ) >= 0 ? ( X ) : -( X ) )

double factorial(int);
int combinatorio(int, int);
double e_a_la_x(int, float);
float raizcuadrada(float, float);
int fibonacci(int);
float seno(float, float);
int clasificacion(int);
long int multiplicacion(int, int);
void cocienteyresto(int, int, int *, int *);
int suma_primeros_naturales(int);
int suma_primeros_pares(int);
int suma_pares_menores(int);
int primo(int);
int multiplicacion_rusa(int,int);
int parte_entera(float);
#endif // MATEMATICAS_H_INCLUDED
