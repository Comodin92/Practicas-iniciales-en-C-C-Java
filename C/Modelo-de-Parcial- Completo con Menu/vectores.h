#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

int insertar_tamanio_vector();
void cargar_vector(int *, int);
void mostrar_vector(int *, int);
void insertar_en_pos(int *, int, int);
void insertar_en_orden_vec(int v[], int, int);
void desplazamiento_derecha (int v[], int , int );
void desplazamiento_izquierda (int v[], int , int);
void eliminar_de_posicion (int v[],int, int);
int eliminar_1era_aparicion(int *, int , int);
int eliminar_todas_apariciones(int v[], int, int);

#endif // VECTORES_H_INCLUDED
