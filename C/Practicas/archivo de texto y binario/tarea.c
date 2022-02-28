#include "tarea.h"

void crearLoteEmpleado()
{
    t_empleado emple[] =
    {
        {1,"Angeles","Romina",500},
        {2,"Benitez","Jose",1200},
        {3,"Canales","Martin",5100},
        {4,"Diaz","Manuel",1500},
        {5,"Estebanez","Eduardo",4400},
        {6,"Fernandez","Romina",5050},
        {7,"Gutierrez","Cecilia",300},
        {10,"Gutierrez","Damian",5900},
        {12,"Gutierrez","Juan",5400}


    };
    FILE* pf = fopen("Empleado.dat","wb");
    if(!pf)
    {
        printf("Error al abrir archivo empleados\n");
        exit(1);
    }
    fwrite(emple,sizeof(t_empleado),sizeof(emple)/sizeof(t_empleado),pf);
    fclose(pf);
}
void crearLoteEstudiante()
{
    t_estudiante est[] =
    {
        {1,"Angeles","Romina",1},
        {2,"Benitez","Jose",3},
        {3,"Canales","Martin",2},
        {4,"Diaz","Manuel",7},
        {5,"Estebanez","Eduardo",6},
        {6,"Fernandez","Romina",4},
        {7,"Gutierrez","Cecilia",8},
        {8,"Gutierrez","Damian",9},
        {10,"Gutierrez","Juan",10}


    };
    FILE* pf = fopen("Estudiante.dat","wb");
    if(!pf)
    {
        printf("Error al abrir archivo estudiante para crear lote de prueba\n");
        exit(1);
    }
    fwrite(est,sizeof(t_estudiante),sizeof(est)/sizeof(t_estudiante),pf);
    fclose(pf);
}

void mostrar_archivo_empleado()
{

    t_empleado emple;
    FILE  *pf=fopen("Empleado.dat","rb");
    if(!pf)
    {
        printf("Error al abrir el archivo empleado en Funcion mostrar_archivo_empleado\n");
        exit(1);

    }
    fread(&emple,sizeof(t_empleado),1,pf);
    while(!feof(pf))
    {
        printf("Dni: %d\t Apellido: %s\tNombre: %s \tSueldo: %.2f\n",emple.dni,emple.apellido,emple.nombre,emple.sueldo);
        fread(&emple,sizeof(t_empleado),1,pf);



    }

    fclose(pf);
}

void mostrar_archivo_estudiante()
{
    t_estudiante est;
    FILE  *pf=fopen("Estudiante.dat","rb");
    if(!pf)
    {
        printf("Error al abrir el archivo empleado en Funcion mostrar_archivo_estudiante\n");
        exit(1);

    }
    fread(&est,sizeof(t_estudiante),1,pf);
    while(!feof(pf))
    {
        printf("Dni: %d\t Apellido: %s\tNombre: %s \tPromedio: %.2f\n",est.dni,est.apellido,est.nombre,est.promedio);
        fread(&est,sizeof(t_estudiante),1,pf);
    }

    fclose(pf);


}

void interseccion_entre_archivos()
{
    t_empleado emple;
    t_estudiante estu;
    FILE *pf_empleado,*pf_estudiante,*pf_interseccion;
    pf_empleado = fopen("Empleado.dat","rb");
    if(!pf_empleado)
    {
        printf("Error al abrir archivo empleado en actualizar archivo\n");
        fclose(pf_empleado);
        exit(1);
    }
    pf_estudiante=fopen("Estudiante.dat","rb");
    if(!pf_estudiante)
    {
        printf("Error al abrir archivo estudiante en actualizar archivo\n");
        fclose(pf_empleado);
        fclose(pf_estudiante);
        exit(1);
    }
    pf_interseccion=fopen("interseccion.txt","wt");
    if(!pf_interseccion)
    {
        printf("Error al abrir archivo interseccion\n");
        fclose(pf_empleado);
        fclose(pf_estudiante);
        fclose(pf_interseccion);
        exit(1);
    }

    fread(&estu,sizeof(t_estudiante),1,pf_estudiante);
    fread(&emple,sizeof(t_empleado),1,pf_empleado);
    while(!feof(pf_empleado) || !feof(pf_estudiante))
    {
        if(emple.dni == estu.dni)

            fprintf(pf_interseccion,"Dni:%d  Apellido: %s Nombre:%s Sueldo: %.2f\n",
                    emple.dni,emple.apellido,emple.nombre,emple.sueldo);
        else if(emple.dni < estu.dni)
            fread(&emple,sizeof(t_empleado),1,pf_empleado);
        else
            fread(&estu,sizeof(t_estudiante),1,pf_estudiante);





        fread(&estu,sizeof(t_estudiante),1,pf_estudiante);
        fread(&emple,sizeof(t_empleado),1,pf_empleado);
    }


}
