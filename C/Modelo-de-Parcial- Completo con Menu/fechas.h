#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED
#define ANIO_BASE 1600
#define esBisiesto(X) (X)%400?!((X)%4) && (X)%100?1:0:1
///FECHAS
typedef struct
{
    int di,
        me,
        an;
}t_fecha;
typedef struct
{
    int di,
        an;
}t_fecha_jul;
int es_fecha_valida(const t_fecha *);
int es_fecha_juliana_valida(const t_fecha_jul *);
void ingresar_fecha(t_fecha *);
void ingresar_fecha_juliana_valida(t_fecha_jul *);
int cant_dias_mes(int, int);
void dia_sig(t_fecha *);
void sumar_dias(t_fecha *, int);
void restar_dias(t_fecha *, int);
void f_juliana(const t_fecha *, t_fecha_jul *);
void f_gregoriana(const t_fecha_jul *, t_fecha *);
int comp_fechas(const t_fecha *, const t_fecha *);
int dias_a(int, int);
int dif_fechas(const t_fecha *, const t_fecha *);
int dia_semana(const t_fecha *);
t_fecha obtener_fecha_maq();

#endif // FECHAS_H_INCLUDED
