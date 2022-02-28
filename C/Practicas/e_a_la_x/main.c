#include <stdio.h>
#include <stdlib.h>

double e_a_la_X(const int num, const float tol);
double factorial(int x);
double raizCuadrada(const int num, const float tolerancia);


int main()
{
    int num=5;
    float tol=0.00001;
//   /// printf("Ingrese valor para calcular Factorialñ a la X\n");
//    ///scanf("%d",&num);
//   /// printf("El valor del factorial es %d: %.2lf\n",num,factorial(num));
//    printf("Ingrese valor para calcular e a la X\n");
//    scanf("%d",&num);
//    printf("Ingrese Tolerancia en formato x.xxxxxx \n");
//    scanf("%f",&tol);
   printf("El valor de e a la %d es: %.2lf\n",num,e_a_la_X(num,tol));
    ///printf("Raiz cuadrada: %lf\n",raizCuadrada(4,0.00001));

    return 0;
}
double e_a_la_X(const int num, const float tolerancia)
{
    double res_final=1,
           calculo_termino;
    int numerador=1, denominador=1;
     do
    {
        numerador*=num;
        calculo_termino = (double)numerador/factorial(denominador++) ;
        res_final += calculo_termino;
    }while(calculo_termino > tolerancia);
    return res_final;
}


double factorial(int x)
{
    if(!x)
        return 1;
    double resultado = x;
    while(--x)
        resultado *=x;
   return resultado;
}

double raizCuadrada(const int num, const float tolerancia)
{
    ///int n=1;
    double nMasUno=0,n=1;
    while( abs(n-nMasUno) > tolerancia)
    {
        printf("Valor %f\n",(n-nMasUno));
        nMasUno = 1/2 * (n + (num/n));
        n = nMasUno;
    }
    return nMasUno;
}
