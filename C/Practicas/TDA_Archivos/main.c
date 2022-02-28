#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int nota;
    char nyap[20];
}t_recursante_eterno;

void ordernarArchivoPilas();
void texto_a_estructura(char *linea, t_recursante_eterno *recursante);
void cargarMat(t_recursante_eterno aula_recursantes[][1],t_recursante_eterno recursante, int f, int c);



int main()
{
    ordernarArchivoPilas();
    claseLista();

    return 0;
}

void ordernarArchivoPilas()
{
    t_recursante_eterno recursante,
                        aula_recursantes[20][1];
    char linea[50];
    FILE *pf_texto;
    int cant_reg;
    pf_texto = fopen("notas_alumnos.txt", "rt");
    if(!pf_texto)
    {
        printf("Error al abrir archivo texto\n");
        exit(3);
        fclose(pf_texto);
    }
    while(fgets(linea,sizeof(linea),pf_texto))
    {
        texto_a_estructura(linea, &recursante);
        cargarMat(aula_recursantes,recursante,20,1);


    }
}


void texto_a_estructura(char *linea, t_recursante_eterno *recursante)
{
    char *p;
    p = strchr(linea,'\n');
    *p = '\0';
    p = strchr(linea, '-');
    *p = '\0';
    p++;
    sscanf(p,"%s",recursante->nyap);
    recursante->nota  = atoi(linea);

}

void cargarMat(t_recursante_eterno aula_recursantes[][1],t_recursante_eterno recursante,int f,int c)
{
    int i;

    for(i=0 ; i < )


}

