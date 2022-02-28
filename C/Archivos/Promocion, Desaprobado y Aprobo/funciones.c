#include "funciones.h"
void crearArchivo1()
{
    tAlumno alu[]={    {"damian",7,7},
                        {"juan",8,9},
                        {"erica",9,9},
                        {"cecilia",10,9},
                        {"Pedro",2,2},
                        {"Pepe",5,5}
                    };
    FILE*fp=fopen(PRIMERO,"wb");
    if(fp)
    {
        fwrite(alu,sizeof(tAlumno),6,fp);
        fclose(fp);
    }
}


void crearArchivo2()
{
    tAlumno alu[]={    {"Edgardo",4,3},
                        {"Andrea",6,9},
                        {"clash",7,7},
                        {"Reynaldo",2,1},
                        {"Messi",5,4},
                        {"Jime",6,6}
                    };
    FILE*fp=fopen(SEGUNDO,"wb");
    if(fp)
    {
        fwrite(&alu,sizeof(tAlumno),6,fp);
        fclose(fp);
    }



}

void mostrarArchivo(FILE* pf1)
{
    tAlumno alu;
    fread(&alu,sizeof(tAlumno),1,pf1);
    while(!feof(pf1))
    {
        printf("%s | %f | %f \n",alu.nya,alu.nota1,alu.nota2);
        fread(&alu,sizeof(tAlumno),1,pf1);

    }

}

void separarArchivos(FILE *pf,FILE *pf2,FILE *pf_Aprobados,FILE *pf_Desaprobados,FILE *pf_Promocionados)
{
    tAlumno alu1,alu2;

    fread(&alu1,sizeof(tAlumno),1,pf);
    while(!feof(pf))
    {
        if(ALU_PROMOCIONA(alu1.nota1) && ALU_PROMOCIONA(alu1.nota2))
                fwrite(&alu1,sizeof(tAlumno),1,pf_Promocionados);
            else
                if(ALU_DESAPRUEBA(alu1.nota1) ||ALU_DESAPRUEBA(alu1.nota2))
                    fwrite(&alu1,sizeof(tAlumno),1,pf_Desaprobados);
                else
                    if(ALU_APRUEBA(alu1.nota1) && ALU_APRUEBA(alu1.nota2))
                        fwrite(&alu1,sizeof(tAlumno),1,pf_Aprobados);
        fread(&alu1,sizeof(tAlumno),1,pf);
    }

    fread(&alu2,sizeof(tAlumno),1,pf2);


}
