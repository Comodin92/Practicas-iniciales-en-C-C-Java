#include <string.h>
#include "archivos.h"
#include "fechas.h"
#include "cadenas.h"
///ABRE ARCHIVO VALIDO
int abrir_archivo(FILE **fp, const char *nom, const char *modo, int consin)
{
    *fp=fopen(nom,modo);
    if(*fp == NULL)
    {
        if( consin == CON_MSG)
            fprintf(stderr,"Error abriendo \"%s\" en modo \"%s\"n",nom,modo);
    return 0;
    }
return 1;
}
///MUESTRA T_PER VALIDO
void mostrar_persona(const t_per *d)
{
    if(d)
    {
        printf("%08ld %-*s %c %02d/%02d/%04d %8.2lf\n"
               ,d->dni
               ,sizeof(d->apyn)-1, d->apyn
               ,d->sex
               ,d->fec.di,d->fec.me,d->fec.an
               ,d->importe);
    }
    else
    {
        printf("D. N. I. %-*.*sSEX  FECHA    IMPORTE\n",
               sizeof(d->apyn)-1,sizeof(d->apyn)-1, "   Apellido(s) y Nombre(s)"
               );
               //-*.*s
    }
}
///EJEMPLO DE CARGA DE T_PER Y GUARDA ARCHIVO
void cargar_archivo_texto_variable(FILE**fp_datos, t_per *d)
{
    int i=0,
        tope;
    if( (*fp_datos=fopen(DATOS,WRITE_TEXT)) == NULL )
        return ;
    printf("\tIngrese cantidad de registros a cargar en DATOS :");
    fflush(stdin);
    scanf("%d",&tope);
    while(i<tope)
    {
        /*Ingreso apyn*/
        printf("\tIngresar Nombre: ");
        fflush(stdin);
        //scanf("%s",a->apyn); NO ANDA ESTA MIERDA
        gets(d->apyn);
        str_upr(d->apyn);
        d->sex = to_upper(d->sex);
        /*Ingreso dni*/
        do{
            printf("\tIngresar DNI:");
            fflush(stdin);
            scanf("%ld",&d->dni);
        }while (&d->dni < 0);
        /*Ingreso sexo*/
        do{
            printf("\tIngresar SEXO (M/N):");
            fflush(stdin);
            scanf("%c",&d->sex);
            d->sex = to_upper(d->sex);
        }while (d->sex != 'M' && d->sex != 'F');
        /*Ingreso fecha*/
        ingresar_fecha (&d->fec);
        /*Ingreso importe*/
        do{
            printf("\tIngresar SUELDO - IMPORTE:");
            fflush(stdin);
            scanf("%f",&d->importe);
        }while (&d->importe < 0);
        /*Ingresa datos en el archivo*/
        fflush(stdin);
        fprintf(*fp_datos,"%ld|%s|%c|%02d/%02d/%04d|%.2f\n"
                         ,d->dni
                         ,d->apyn
                         ,d->sex
                         ,d->fec.di,d->fec.me
                         ,d->fec.an
                         ,d->importe);
        //exit(34);
        /*muestro datos de archivo lindo*/
        printf("\tRegistro ingresado con exito: \n\t[%08ld %s %c %02d/%02d/%04d %8.2lf]\n"
               ,d->dni
               ,d->apyn
               ,d->sex
               ,d->fec.di,d->fec.me,d->fec.an
               ,d->importe);
        /*muestro datos de archivo por funcion*/
        mostrar_persona(d);
        i++;
    }
    fclose(*fp_datos);
    printf("\a");
}
///EJEMPLO DE CARGA BINARIA HARDCODEADO DE T_PER
void cargar_archivo_binario_fijo(FILE**fp_datos, t_per *d)
{
    //Esta preinicializacion no es necesaria, pero es mas rapida que andar cargando datos y queda de ejemplo
    //exit(9);
    t_per persona [] = {{00000001,"LOPEZ, LUIS",'M',{14,11,1969},12800},
                        {00000002,"GIL, MYRIAM",'M',{14,11,1969},12800},
                        {00000003, "PEREZ, SILVIA", 'F',{14,11,1969},12800},
                        {00000004, "LEIBOVICH, DANIEL", 'M',{14,11,1969},12800},
                        {00000005, "SZKLANNY, FERNANDO", 'M',{14,11,1969},12800},
                        {00000006, "TANTIGNONE, HUGO", 'M',{14,11,1969},12800},
                        {00000007, "HNATIUK, JAIR", 'M',{14,11,1969},12800},
                        {00000021, "DIAZ, DANIEL", 'M',{14,11,1969},12800},
                        {00000022, "DIVITO, DANIEL", 'M',{14,11,1969},12800},
                        {00000010, "CROCCO, LAURA", 'F',{14,11,1969},12800},
                        {00000011, "BALONI, RICARDO", 'M',{14,11,1969},12800},
                        {00000012, "BERTUA, JULIO", 'M',{14,11,1969},12800},
                        {00000013, "MOYA, MANUEL", 'M',{14,11,1969},12800},
                        {00000014, "BEVILACQUA ALEJANDRO", 'M',{14,11,1969},12800},
                        {00000015, "LEVI, MARCELO", 'M',{14,11,1969},12800},
                        {00000016, "GARRIDO, GRACIELA", 'F',{14,11,1969},12800},
                        {00000017, "BELLANI, MARCELA", 'F',{14,11,1969},12800},
                        {00000031, "MENEGUZZO, PATRICIO", 'M',{14,11,1969},12800},
                        {00000032, "RODRIGUEZ, ENRIQUE", 'M',{14,11,1969},12800},
                        {00000020, "PAFUNDI, FEDERICO", 'M',{14,11,1969},12800},
                        {00000021, "MEDINA, NOEMI", 'F',{14,11,1969},12800},
                        {00000022, "LARROSA, MONICA", 'F',{14,11,1969},12800},
                        {00000023, "SALVADOR, ALICIA", 'F',{14,11,1969},12800},
                        {00000024, "DIVITO, DANIEL", 'M',{14,11,1969},12800}};

    if( (*fp_datos=fopen(PERSONA,WRITE_BIN)) == NULL )
        return ;
    if ( fp_datos )
    {
        fwrite( persona ,1 ,sizeof(persona) ,*fp_datos );
        fclose( *fp_datos );
        printf("\a");
    }
}
///MUESTRA EL BINARIO
void mostrar_archivo_binario_fijo(FILE* *fp_datos, t_per *dato)
{
    if(!abrir_archivo(&*fp_datos,PERSONA,READ_BIN,CON_MSG))
        return;
    mostrar_persona(NULL);
    fread(dato,sizeof(t_per),1,*fp_datos);
    while(!feof(*fp_datos))
    {
       mostrar_persona(dato);
        fread(dato,sizeof(t_per),1,*fp_datos);
    }
    fclose(*fp_datos);
}
///MUESTRA EL TEXT
void mostrar_archivo_texto_variable(FILE* *fp_datos, t_per *dato)
{
    char  linea [500],
          *aux;
    t_per  reg;
    if(!abrir_archivo(&*fp_datos,DATOS,READ_BIN,CON_MSG))
        return;
    mostrar_persona(NULL);
    while ( fgets( linea, sizeof(linea) ,*fp_datos ) )
    {
        if ( ( aux = strrchr (linea, '\n') ) == NULL )
        {
            fclose(*fp_datos);
            fprintf(stderr,"Error -KXP1\n");
            return;
        }
        /**Importe**/
        *aux = '\0';
        aux = strrchr (linea, '|');
        sscanf(aux+1,"%f",&reg.importe);
        *aux = '\0';
        /**Fecha**/
        aux = strrchr(linea,'|');
        sscanf(aux+1,"%d/%d/%d",&reg.fec.di
                               ,&reg.fec.me
                               ,&reg.fec.an);
        *aux = '\0';
        /**SEXO**/
        aux = strrchr(linea,'|');
        sscanf(aux+1,"%c",&reg.sex);
        *aux = '\0';
        /**APYN**/
        aux = strrchr(linea,'|');
        str_cpy(reg.apyn,aux+1);
        *aux = '\0';
        /**DNI**/
        aux = strrchr(linea,'|');
        sscanf(linea,"%ld",&reg.dni);
        mostrar_persona(&reg);
    }
    fclose(*fp_datos);
}

void mostrar_archivo_texto_variable(FILE** , t_per*);
