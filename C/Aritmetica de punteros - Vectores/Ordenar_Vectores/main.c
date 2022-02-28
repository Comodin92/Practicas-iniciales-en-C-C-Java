#include <stdio.h>
#include <stdlib.h>
void ordenarVecAsc(int *cad,int ce);
void intercambio(int *n1, int *n2);
void mostrarVec(int* vec);
void ordenarVecDesc(int *vec,int ce);
void ordenSelAsc(int *vec, int ce);


int main()
{
    int vec[]={12,9,11,1,33,100,200,999,1022,8},ce=10,vec2[]={120,90,110,10,330,1000,2000,9990,10220,80};
    printf("Vector por defecto\n");
    mostrarVec(vec);
    /*ordenarVecAsc(vec,ce);
    mostrarVec(vec);
    printf("Vector por defecto\n");
    mostrarVec(vec2);
    ordenarVecDesc(vec2,ce);
    mostrarVec(vec2);*/
    /**ORDENAMIENTO SELECTIVO**/
    ordenSelAsc(vec,ce);
    mostrarVec(vec);

    return 0;
}
///BURBUJEO
void ordenarVecAsc(int *cad,int ce)
{
    int aux,*ini=cad,*fin=cad+ce;
    while(ini < fin)
    {
        while(cad < fin)
        {

            if(*cad > *(cad+1))
               intercambio(cad,cad+1);
            cad++;

        }

        fin--;
        cad = ini;


    }

}

void intercambio(int *n1, int *n2)
{
    int aux;
    aux=*n1;
    *n1=*n2;
    *n2=aux;


}
void mostrarVec(int *vec)
{
    int *fin=vec+10;
    while(vec < fin)
    {
        printf("%d\t",*vec);
        vec++;
    }
    printf("\n");


}

void ordenarVecDesc(int *vec,int ce)
{
    int *inic=vec,*fin=vec+ce;
    while(inic < fin)
    {
        while( vec <  fin)
        {
            if(*vec < *(vec+1))
                intercambio(vec,vec+1);
            vec++;

        }
        fin--;
        vec=inic;
    }


}
///ORDEN SELECTIVO
void ordenSelAsc(int *vec,int ce)
{
    int *fin=vec+(ce-1), *recorre=vec+1, *comp=vec, menor;

    while(vec < fin)
    {
        menor=buscarMenor()
        while(recorre <=fin)
        {
            if(*comp < *recorre)
                recorre++;
            else
            {
                comp=recorre;
                recorre++;
            }
        }
        if(comp != vec)
            intercambio(vec,comp);
        vec++;
        recorre = vec;

    }

}
