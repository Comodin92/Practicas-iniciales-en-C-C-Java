#include "tarea.h"
int main()
{
    crearLoteEmpleado();
    crearLoteEstudiante();
    printf("Archivo Empleados\n\n");
    mostrar_archivo_empleado();
    printf("Archivo Estudiante\n\n");
    mostrar_archivo_estudiante();
    interseccion_entre_archivos();
    return 0;
}
