#include "alumno.h"
///SI ES MAYOR A 1500 LE ASIGNO 500 PESOS MAS A SU SUELDO
int main()
{
    t_alumno alu;
    FILE*pf;
    pf=fopen("Historicos_Precios.dat","rb+");
    if(!pf)
        exit(1);
    fread(&alu,sizeof(t_alumno),1,pf);
    while(!feof(pf))
    {
        if(alu.sueldo > 1500)
          {
                alu.sueldo+=500;
                fseek(pf,-sizeof(t_alumno),SEEK_CUR);
                fwrite(&alu,sizeof(t_alumno),1,pf);
                fseek(pf,0 * sizeof(t_alumno),SEEK_CUR);
                fread(&alu,sizeof(t_alumno),1,pf);

          }
        else
            fread(&alu,sizeof(t_alumno),1,pf);
    }
    rewind(pf);
     fread(&alu,sizeof(t_alumno),1,pf);
    while(!feof(pf))
    {
        printf("Nro Cuenta: %d | Fecha: %d/%d/%d | Saldo: %f\n",alu.nro_cuenta,alu.fecha.d,alu.fecha.m,alu.fecha.a,alu.sueldo);
        fread(&alu,sizeof(t_alumno),1,pf);
    }
    return 0;
}
