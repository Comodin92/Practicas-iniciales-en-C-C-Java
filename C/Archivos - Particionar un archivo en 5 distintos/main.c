
#include "../../Bibiotlecas/archivos.h"

void leerArchivo(const char  *apertura,FILE* pf,const char* nombre);

int main()
{
    t_ingenieria ing;
    char escritura[]="wb",
         lectura[]="rb",
         escrituraLectura[]="w + b",
         Archivo[]="Materias",
         primero[]="Primero",
         segundo[]="segundo",
         tercero[]="tercero",
         cuarto[]="cuarto",
         quinto[]="quinto",
         extencion[]=".dat";

    FILE *pf_ing,
         *pf_1,
         *pf_2,
         *pf_3,
         *pf_4,
         *pf_5;
    pf_ing=fopen(strcat(Archivo,extencion),lectura);
    if(!pf_ing)
    {
        printf("Error al abrir pf_ing\n");
        fclose(pf_ing);
        exit(1);
    }
    pf_1=fopen(primero,escritura);
    if(!pf_1)
    {
        printf("Error al crear archivo primero\n");
        fclose(pf_ing);
        fclose(pf_1);
        exit(2);

    }
    pf_2=fopen(segundo,escritura);
    if(!pf_2)
    {
        printf("Error al crear archivo segundo\n");
        fclose(pf_ing);
        fclose(pf_1);
        fclose(pf_2);
        exit(2);

    }
    pf_3=fopen(tercero,escritura);
    if(!pf_3)
    {
        printf("Error al crear archivo tercero\n");
        fclose(pf_ing);
        fclose(pf_1);
        fclose(pf_2);
        fclose(pf_3);
        exit(3);
    }
    pf_4=fopen(cuarto,escritura);
    if(!pf_4)
    {
        printf("Error al crear archivo cuarto\n");
        fclose(pf_ing);
        fclose(pf_1);
        fclose(pf_2);
        fclose(pf_3);
        fclose(pf_4);

        exit(4);
    }
    pf_5=fopen(quinto,escritura);
    if(!pf_4)
    {
        printf("Error al crear archivo quinto\n");
        fclose(pf_ing);
        fclose(pf_1);
        fclose(pf_2);
        fclose(pf_3);
        fclose(pf_4);
        fclose(pf_5);
        exit(5);
    }

    fread(&ing,sizeof(t_ingenieria),1,pf_ing); ///lee el archivo origen
    while(!feof(pf_ing))
    {
        switch(ing.anio)
        {
        case 1:
            fwrite(&ing,sizeof(t_ingenieria),1,pf_1);
            break;
        case 2:
            fwrite(&ing,sizeof(t_ingenieria),1,pf_2);
            break;
        case 3:
            fwrite(&ing,sizeof(t_ingenieria),1,pf_3);
            break;
        case 4:
            fwrite(&ing,sizeof(t_ingenieria),1,pf_4);
            break;
        case 5:
            fwrite(&ing,sizeof(t_ingenieria),1,pf_5);
            break;
        }

        fread(&ing,sizeof(t_ingenieria),1,pf_ing); ///Segunda lectura


    }


    fclose(pf_ing);
    fclose(pf_1);
    fclose(pf_2);
    fclose(pf_3);
    fclose(pf_4);
    fclose(pf_5);
    leerArchivo(lectura,pf_1,primero);
    leerArchivo(lectura,pf_2,segundo);
    leerArchivo(lectura,pf_3,tercero);
    leerArchivo(lectura,pf_4,cuarto);
    leerArchivo(lectura,pf_5,quinto);


    return 0;
}


void leerArchivo(const char *apertura,FILE* pf,const char* nombre )
{
    t_ingenieria ing;
    pf=fopen(nombre,apertura);
    if(!pf)
    {
        printf("Error en el archivo %s\n",nombre);
        return ;
    }
    fread(&ing,sizeof(t_ingenieria),1,pf);
    printf("Archivo %s\n\n",nombre);
    while(!feof(pf))
    {
        printf("%d | %s | %s | %d \n",ing.codigo,ing.materia,ing.docente,ing.anio);
        fread(&ing,sizeof(t_ingenieria),1,pf);
    }
    fclose(pf);



}
