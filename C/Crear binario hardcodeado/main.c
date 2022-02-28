#include <stdio.h>
#include <stdlib.h>
#define TAM 30
typedef struct
{
    int d,m,a;
}t_fecha;

typedef struct
{
    t_fecha fecha_nac;
    int edad;
    int dni;
    char nomre[TAM];
    char apellido[TAM];
    float nota1;
    float nota2;
}t_alumno;
int main()
{
    t_alumno alumno[] = {{{12,01,1992},25,36902267,"Damian","Gutierrez",8,7},
                        {{12,01,1992},25,36902267,"Juan","Gutierrez",5,4},
                        {{12,01,1992},25,36902267,"Daniel","Gutierrez",2,7},
                        {{12,01,1992},25,36902267,"Cecilia","Gutierrez",4,7},
                        {{12,01,1992},25,36902267,"Andrea","Briseno",10,10},
                        {{12,01,1992},25,36902267,"Lorena","Dilorenso",2,2},
                        {{12,01,1992},25,36902267,"Carolina","Martinez",7,2},
                        {{12,01,1992},25,36902267,"Leila","Fernandez",7,6}};

    FILE* pf=fopen("Calificacion.dat","wb");
    if(pf)
        {
                fwrite(alumno,sizeof(t_alumno),8,pf );

                fclose(pf);

        }
    rewind(pf);
    pf=fopen("Calificacion.dat","rb");
    fread(&alumno,sizeof(t_alumno),1,pf);
    while(!feof(pf))
    {
        printf("%d/%d/%d | %d | %d | %s | %s | %f | %f\n",alumno->fecha_nac.d,
           alumno->fecha_nac.m,alumno->fecha_nac.a, alumno->edad, alumno->dni,alumno->nomre,
            alumno->apellido,alumno->nota1,alumno->nota2 );
        fread(&alumno,sizeof(t_alumno),1,pf);

    }

    fclose(pf);

return 0;
}
