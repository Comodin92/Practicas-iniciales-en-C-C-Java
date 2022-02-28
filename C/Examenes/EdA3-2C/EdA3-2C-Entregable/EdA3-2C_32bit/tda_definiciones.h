#ifndef TDA_DEFINICIONES_H_
#define TDA_DEFINICIONES_H_

/** etiquetas t�picas de TDA (salvo para primitivas booleanas) **/

#define SIN_MEMORIA     0
#define TODO_BIEN       1
#define CLAVE_DUPLICADA 2

/** etiquetas espec�ficas para Punto 1 a.- **/
#define NO_SE_INSERTA   4    /// cuando ya hay las cant mejores notas


/**//*  Tipo de dato para TDAs con asignaci�n din�mica de memoria imple-  *//**/
/**//*      mentados en listas simplemente enlazadas                      *//**/
typedef struct sNodoSimp
{
    void               *info;
    unsigned            tamInfo;
    struct sNodoSimp   *sig;
} tNodoSimp;

typedef tNodoSimp      *tListaSimp;


/**//*  Tipo de dato para TDAs con asignaci�n din�mica de memoria imple-  *//**/
/**//*       mentados en listas doblemente enlazadas o con nodos con do-  *//**/
/**//*       ble enlace                                                   *//**/
typedef struct sNodoDobl
{
    void               *info;
    unsigned            tamInfo;
    struct sNodoDobl   *izq,
                       *der;
} tNodoDobl;

typedef tNodoDobl      *tListaDobl;

typedef tNodoDobl      *tArbol;




#endif // TDA_DEFINICIONES_H_
