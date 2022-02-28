#include "../Bibiotlecas/archivos.h"
/**
usar un archivo de texto y pasarlo a una estructura y luego a un binario
**/

int main()
{
    t_ingenieria materias;
    char linea[200];
    FILE *pf_bin = fopen("MateriasAlumno.dat","w+b");
    FILE* pf_text=fopen("MateriasAlumno1.txt","rt");
    if(!pf_text || !pf_bin)
        exit(1);
    fgets(linea,sizeof(linea),pf_text);
    while(!feof(pf_text))
    {
        textoAEstructura(linea,&materias);
        fwrite(&materias,sizeof(t_ingenieria),1,pf_bin);
       /// printf("%d | %s | %s | %d \n",materias.codigo,materias.materia,materias.docente,materias.anio);
        fgets(linea,sizeof(linea),pf_text);
    }

    fseek(pf_bin,0,SEEK_SET);
    fread(&materias, sizeof(t_ingenieria),1,pf_bin);
    while(!feof(pf_bin))
    {
            printf("%d | %s | %s | %d \n",materias.codigo,materias.materia,materias.docente,materias.anio);
            fread(&materias, sizeof(t_ingenieria),1,pf_bin);
    }

    fclose(pf_bin);
    fclose(pf_text);

    return 0;
}
