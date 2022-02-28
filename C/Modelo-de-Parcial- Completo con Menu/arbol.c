#include "arbol.h"
/*FUNCIONES DE ARBOL*/
///ARBOL EN ORDEN CENTRAL
void en_orden ( const t_arbol *p)
{
    if ( *p)
    {
        en_orden(&(*p)->izq);
        mostrar_nodo_arbol(&(*p)->info);
        en_orden(&(*p)->der);
    }
}
///PRE ORDEN DE UN ARBOL
void pre_orden ( const t_arbol *p)
{
    if ( *p)
    {
        mostrar_nodo_arbol(&(*p)->info);
        pre_orden(&(*p)->izq);
        pre_orden(&(*p)->der);
    }
}
///POS ORDEN DE UN ARBOL
void pos_orden ( const t_arbol *p)
{
    if ( *p)
    {
        pos_orden(&(*p)->izq);
        pos_orden(&(*p)->der);
        mostrar_nodo_arbol(&(*p)->info);
    }
}
///
void mostrar_nodo_arbol( t_info *d)
{
    if (d)
        //printf("\n\n%s",d->apyn);
        printf("\n\n%d",d->cla);
    else
        printf("\n\n NOMBRE");
}
///CREAR ARBOL
void crear_arbol ( t_arbol *p)
{
    *p = NULL;
}
///VERIFICAR SI ARBOL ESTA LLENO
int arbol_lleno ( const t_arbol*p )
{
    t_nodo_a *aux = (t_nodo_a *) malloc( sizeof ( t_nodo_a ) );
    free(aux);
    return aux == NULL;
}
///PONER INFO EN ARBOL
/*ver si esta bien el amnejo de punteros y el manejo de (*p)*/
int poner_en_arbol ( t_arbol *p, const t_info *d )
{
    int cmp;
    while ( *p && ( cmp = comparar( &(*p)->info, d ) ) != 0 )
    {
        if ( cmp > 0 )
            p = &(*p)->izq;
        else
            p = &(*p)->der;
    }
    if ( cmp == 0)
        return CLA_DUP;
    *p = ( t_nodo_a* ) malloc ( sizeof ( t_nodo_a ) );
    if ( *p == NULL )
        return SIN_MEM;
    (*p)->info = *d;
    (*p)->izq = NULL;
    (*p)->der = NULL;
    return CORRECTO;
}
/// BUSCAR EN ARBOL BINARIO
int buscar_en_arbol (t_arbol* p, t_info* d)
{
    int cmp;
    while ( *p && ( cmp = comparar( &(*p)->info, d ) ) != 0 )
    {
        if ( cmp > 0 )
            p = &(*p)->izq;
        else
            p = &(*p)->der;
    }
    if ( !*p )
        return 0;
    *d = (*p)->info;
    return CORRECTO;
}

/// ELIMINAR ARBOL NODO A NODO
void eliminar_arbol (t_arbol *p)
{
    if (*p)
    {
        eliminar_arbol(&(*p)->izq);
        eliminar_arbol(&(*p)->der);
        free (*p);
        *p = NULL;
    }
}
/// ELIMINAR ARBOL NODO A NODO Y CONTAR LOS NODOS ELIMINADOS
int eliminar_arbol_y_contar (t_arbol *p)
{
    if (*p)
    {
        int cant = eliminar_arbol_y_contar(&(*p)->izq) +
                   eliminar_arbol_y_contar(&(*p)->der);
        free (*p);
        *p = NULL;
        return cant + 1;
    }
    return 0;
}
/// ELIMINA ARBOL Y CUENTA ALMACENANDO EN ALGUN LUGAR LOS NODOS
int eliminar_arbol_y_contar_y_almacenar (t_arbol *p, FILE *fp)
{
    if (*p)
    {
        ///PRE_ORDEN
        fwrite( &(*p)->info, sizeof (t_info),1,fp);
        int cant = eliminar_arbol_y_contar_y_almacenar( &(*p)->izq, fp );
        ///EN_ORDEN
        cant +=    eliminar_arbol_y_contar_y_almacenar( &(*p)->der, fp );
        ///POS_ORDEN
        free (*p);
        *p = NULL;
        return cant + 1;
    }
    ///LO QUE DEBERIA IR EN CADA TIPO SERIA:::
    //                      fwrite( &(*p)->info, sizeof (t_info),1,fp);
    return 0;
}
/// ELIMINA ARBOL HASTA CIERTA ALTURA
int eliminar_arbol_hasta_altura (t_arbol*p , int altura)
{
    if (*p)
    {
        int hi = altura_arbol( &(*p)->izq),
            hd = altura_arbol( &(*p)->der);
        if (hi >= altura)
        {
            eliminar_arbol(&(*p)->izq);
            eliminar_arbol(&(*p)->der);
        }
        if (hd >= altura)
        {
            eliminar_arbol(&(*p)->izq);
            eliminar_arbol(&(*p)->der);
        }
         return 1;
    }
     return 0;
}
///ALTURA QUE TIENE UN ARBOL
//ENTENDIDA
int altura_arbol ( const t_arbol *p)
{
    if ( *p)
    {
        int hi = altura_arbol( &(*p)->izq),
            hd = altura_arbol( &(*p)->der);
        if ( hi >= hd )
            return hi+1;
        else
            return hd+1;
    }
    return 0;
}
///VALIDACION DE ARBOL
int contar_nodos_arbol (  const t_arbol *p )
{
    if ( *p)
        return 0;
    return contar_nodos_arbol(&(*p)->izq) + contar_nodos_arbol(&(*p)->der) +1;
}
/// CANTIDAD DE NODOS HASTA CIERTA ALTURA EN ARBOL
int contar_nodos_hasta_altura ( const t_arbol *p, int h)
{
    if ( *p || h <= 0)
        return 0;
    return contar_nodos_hasta_altura(&(*p)->izq , h-1 ) + contar_nodos_hasta_altura(&(*p)->der , h-1 ) + 1;
}
/// CONFIRMA SI EL ARBOL ES BALANCEADO
int es_balanceado (const t_arbol *p)
{
    int h = altura_arbol(p);
    return determinar_si_es_balanceado(p,h);
}
/// CONFIRMA SI EL ARBOL ES COMPLETO
int es_completo (const t_arbol *p)
{
    int h = altura_arbol(p);
    return determinar_si_es_completo(p,h);
}
/// ES QUIEN DETERMINA SI ES COMPLETO CON LA ALTURA DADA A ES COMPLETO
int determinar_si_es_completo ( const t_arbol *p, int h)
{
    if ( *p)
        return determinar_si_es_completo(&(*p)->izq,h-1) && determinar_si_es_completo(&(*p)->der,h-1);
    return h == 0;
}
/// ES QUIEN DETERMINA SI ES BALANCEADO CON LA ALTURA DADA A ES BALANCEADO
int determinar_si_es_balanceado (const t_arbol *p, int h)
{
    if ( *p)
        return determinar_si_es_balanceado(&(*p)->izq,h-1) && determinar_si_es_balanceado(&(*p)->der,h-1);
    return h <= 1;

}
///ARBOL DE TIPO AVL CON HOJAS FALTANTES Y HASTA UNA HOJA EN EL ULTIMO NIVEL
int determinar_si_es_AVL (const t_arbol *p)
{
    if ( *p)
    {
        if ( abs( altura_arbol(&(*p)->izq)-altura_arbol((&(*p)->der)) ) > 1 )
            return 0;
        return determinar_si_es_AVL ( &(*p)->izq ) && determinar_si_es_AVL( &(*p)->der );
    }
    return 1;
}
///CONTAR HOJAS DE ARBOL
int contar_hoja (const t_arbol *p)
{
    if ( *p)
    {
        if ((*p)->izq == NULL && (*p)->der == NULL )
            return 1;
        return contar_hoja(&(*p)->izq) + contar_hoja(&(*p)->der);
    }
    return 0;
}
/// CARGA ARBOL EN UN ARCHIVO BINARIO
void cargar_arbol_archivo_bin (t_arbol *p, FILE *fp)
{
    t_info reg;
    rewind(fp);
    fread(&reg,sizeof(t_info),1,fp);
    while (!feof(fp))
    {
        insertar_en_arbol_recursivo (p,&reg);//abria que poner la funcion de comparacion
    fread(&reg,sizeof(t_info),1,fp);
    }
}
/// CARGA EN ARBOL DE FORMA RECURSIVA
int insertar_en_arbol_recursivo (t_arbol *p, t_info *d)
{
    if ( *p)
    {
        int cmp = comparar(&(*p)->info,d);
        if (cmp == 0)
            return CLA_DUP;
        if (cmp < 0)
            insertar_en_arbol_recursivo(&(*p)->izq,d);
        else
            insertar_en_arbol_recursivo(&(*p)->der,d);
    }
    else
    {
        (*p) = (t_nodo_a*) malloc( sizeof (t_nodo_a) );
        if (*p == NULL )
            return SIN_MEM;
        (*p)->info = *d;
        (*p)->izq = NULL;
        (*p)->der = NULL;
        return CORRECTO;
    }
    return 0;
}
/// CUENTA LAS HOJAS Y LAS MUESTRA
int contar_y_mostrar_hojas(const t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq == NULL && (*p)->der == NULL)
        {
            printf("%d\t", (*p)->info.cla);
            //printf("%d\t", (*p)->info.dni);
            mostrar_nodo_arbol(&(*p)->info);
            return 1;
        }
        return contar_y_mostrar_hojas(&(*p)->izq) + contar_y_mostrar_hojas(&(*p)->der);
    }
    return 0;
}
/// CUENTA LA CANTIDAD DE NODOS INTERNOS
int contar_nodos_internos(const t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq || (*p)->der)
          {
              printf("%d\t", (*p)->info.cla);
              //printf("%d\t", (*p)->info.dni);
              return contar_nodos_internos(&(*p)->izq) + contar_nodos_internos(&(*p)->der) + 1;
          }

    }

    return 0;
}
/// CUENTA NODOS INTERNOS A CIERTA ALTURA POR DERECHA
int contar_nodos_Internos_con_HD(const t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq == NULL && (*p)->der )
            printf("%d\t", (*p)->info.cla);
            //printf("%d\t", (*p)->info.dni);

        return contar_nodos_Internos_con_HD(&(*p)->izq) + contar_nodos_Internos_con_HD(&(*p)->der) + ((*p)->izq == NULL && (*p)->der);
    }
    return 0;
}
/// CUENTA NODOS INTERNOS A CIERTA ALTURA POR IZQUIERDA
int contar_nodos_Internos_con_HI(const t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq && (*p)->der == NULL)
            //printf("%d\t", (*p)->info.dni);
            printf("%d\t", (*p)->info.cla);


        return contar_nodos_Internos_con_HI(&(*p)->izq) + contar_nodos_Internos_con_HI(&(*p)->der) + ((*p)->izq && (*p)->der == NULL);
    }
    return 0;
}
/// CUENTA TODOS LOS NODOS CON CIERTA ALTURA POR IZQUIERDA
int contar_todos_nodos_con_HI(const t_arbol *p)
{
     if(*p)
    {
        if((*p)->izq)
            //printf("%d\t", (*p)->info.dni);
            printf("%d\t", (*p)->info.cla);
        return contar_todos_nodos_con_HI(&(*p)->izq) + contar_todos_nodos_con_HI(&(*p)->der) + (((*p)->izq) ? 1:0);
    }
    return 0;
}
/// CUENTA TODOS LOS NODOS CON CIERTA ALTURA POR DERECHA
int contar_todos_nodos_con_HD(const t_arbol *p)
{
     if(*p)
    {
        if((*p)->der)
            //printf("%d\t", (*p)->info.dni);
            printf("%d\t", (*p)->info.cla);
        return contar_todos_nodos_con_HD(&(*p)->izq) + contar_todos_nodos_con_HD(&(*p)->der) + (((*p)->der) ? 1:0);
    }
    return 0;
}
/// CUENTA NODOS HASTA UNA MENOS LA ALTURA
int contar_nodos_hasta_Hmenos1(const t_arbol *p, int h)
{
    if(*p && h>1)
        return contar_nodos_hasta_Hmenos1(&(*p) -> izq, h-1) + contar_nodos_hasta_Hmenos1(&(*p) -> der, h-1) + 1;
    return 0;
}
/// CUENTA NODOS DESDE CIERTA ALTURA
int contar_nodos_desdeH(const t_arbol *p, int h)
{
    if(*p)
    {
        return contar_nodos_desdeH(&(*p)->der, h-1) + contar_nodos_desdeH(&(*p)->izq, h-1) + (h<=1 ? 1:0);
    }
    return 0;
}
/// MUESTRA NODOS Y LOS CUENTA CON CIERTA ALTURA
int mostrar_nodo_y_contar_de_H(t_arbol *p, int h) //muestra y cuenta todos los nodos de tal altura.
{
    if(*p)
    {
        if(h==1)
            mostrar_nodo_arbol(&(*p)->info);
        return mostrar_nodo_y_contar_de_H(&(*p)->izq, h-1) + mostrar_nodo_y_contar_de_H(&(*p)->der, h-1) + (h==1 ? 1:0);
    }
    return 0;
}
/// CUENTA NODOS DE CIERTA ALTURA
int contar_nodos_de_H(const t_arbol *p, int h) //cuenta la cant de nodos de una altura
{
    if(*p)
        return contar_nodos_de_H(&(*p)->izq, h-1) + contar_nodos_de_H(&(*p)->der, h-1) + (h==1 ? 1:0);
    return 0;
}
/// CUENTA NODOS DE LA RAMA IZQUIERDA
int contar_nodos_rama_I(const t_arbol *p)
{
   if(*p)
        return contar_nodos_arbol(&(*p) -> izq);
   return 0;
}
/// CUENTA NODOS DE LA RAMA DERECHA
int contar_nodos_rama_D(const t_arbol *p)
{
   if(*p)
        return contar_nodos_arbol(&(*p) -> der);
   return 0;
}
/// ELIMINA LAS HOJAS DE UN ARBOL
int eliminar_hojas(t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq==NULL && (*p)->der==NULL)
        {
            free(*p);
            *p=NULL;
            return 1;
        }

        eliminar_hojas(&(*p)->izq);
        eliminar_hojas(&(*p)->der);
    }
    return 0;
}
/// MUESTRA ARBOL HASTA CIERTA ALTURA
void mostrar_hastaH(t_arbol *p, int h)//Mostrar nodos hasta tal altura (sin incluirla).
{
    if(*p)
    {
        //mostrar_nodo_arbol(&(*p)->info); --> para incluir los nodos de la h, la funcion mostrar_nodo_arbol deberia de estar aca.
        if(h>1)
        {
            mostrar_nodo_arbol(&(*p)->info);
            mostrar_hastaH(&(*p)->der, h-1);
            mostrar_hastaH(&(*p)->izq, h-1);
        }
    }
}
/// MUESTRA ARBOL DESDE CIERTA ALTURA
void mostrar_desdeH(t_arbol *p, int h) //muestra nodos desde tal altura.
{
    if(*p)
    {
        if(h<=1)
            mostrar_nodo_arbol(&(*p)->info);
        mostrar_desdeH(&(*p)->der, h-1);
        mostrar_desdeH(&(*p)->izq, h-1);
    }
}
/// MUESTRA LOS NODOS DE UNA ALTURA EN PARTICULAR
void mostrar_losdeH(t_arbol *p, int h)
{
    if(*p)
    {
        if(h==1)
        mostrar_nodo_arbol(&(*p)->info);
        else
        {
            mostrar_losdeH(&(*p) -> der, h-1);
            mostrar_losdeH(&(*p) -> izq, h-1);
        }
    }
}
/// ABRE UN ARCHIVO DE TEXTO VARIALE LEVANTANDO EN MEMORIA
int abrirArchivo(FILE **pf, const char *nombre, const char *modo, int conSin) //el **pf porque hay que pasar la direccion del puntero para que lo modiffique dentro del main, de lo contrario la modificacion va a ser locar, dentro de la funcion y cuando salga se pierde.
{    //ADAPTARLAS PARA DNI
    *pf = fopen(nombre, modo);
    if(*pf == NULL && conSin == 1)
        fprintf(stderr, "ERROR abriendo\"%s\" en modo \"%s\".\n", nombre, modo);
    return *pf != NULL;
}
/// LEE EL ARCHIVO DE TEXTO POR LA CLAVE DNI (ERA LA CLA) Y LO CARGA EN EL ARBOL DE FORMA RECURSIVA
void leerTxtEnArbol(FILE*pf,t_info*d,t_arbol*p,t_cmp cmp) //ADAPTARLAS PARA DNI
{
    char cad[10];
    while(fgets(cad,sizeof(cad),pf))
        {
            //sscanf(cad,"%d",&d->dni);
            sscanf(cad,"%d",&d->cla);
            insertar_en_arbol_recursivo(p,d);
        }
}

