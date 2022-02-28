#ifndef FUNCIONESVARIAS_H_INCLUDED
#define FUNCIONESVARIAS_H_INCLUDED

#define TAM 32

#include "cadenas.h"

void fin_anormal(char *);
void pausa(char *);
char menu(const char m[][TAM], const char *);
char pedir_opcion(const char m[][TAM], const char *, const char *);

void menu_math();
void menu_fecha();
void menu_vect();
void menu_mat();
void menu_cad();
void menu_arb();
void menu_arch();
void ej1_factorial();
void ej2_combinatorio();
void ej3_exponencial();
void ej4_raiz();
void ej5_seno();
void ej_sumar_dias();
void ej_restar_dias();
void ej_compara_fechas();
void ej_dif_entre_fechas();
void ej_dia_sem();
void ej_insertar();
void ej_insertar_ordenadamente();
void ej_eliminar();
void ej_eliminar_una_vez();
void ej_eliminar_siempre();
void ej_simetrica();
void ej_transponer();
void ej_identidad();
void ej_suma_diag();
void ej_suma_diag_sec();
void ej_suma_sup_diag();
void ej_suma_sup_diag_sec();
void ej_suma_inf_ppal();
void ej_suma_inf_sec();
void ej_palindromo();
void ej_normalizar();
void ej_anagrama();
void ej_atoi();
void ej_itoa();
void ej_str_cmp();
void ej_str_cpy();
void ej_str_lwr();
void ej_str_upr();
void ej_str_chr();
void ej_str_str();
void ej_str_len();
void ej_reemplazar();
void ej_str_cat();
void ej_encriptar();
void ej_str_tok();
void ej_eliminarSubCad();
void ej_ejercicio8();
void ej_crear_arbol();
void ej_cargar_arbol_archivo();
void ej_preorden();
void ej_inorden();
void ej_posorden();
void ej_mostrar_contar_hojas();
void ej_mostrar_internos();
void ej_mostrar_internos_HD();
void ej_mostrar_internos_HI();
void ej_mostrar_tienen_HD();
void ej_mostrar_tienen_HI();
void ej_altura_arbol();
void ej_mostrar_de_altura();
void ej_mostrar_hasta_altura();
void ej_mostrar_desde_altura();
void ej_cantidad_nodos_de_altura();
void ej_cantidad_nodos_total();
void ej_cantidad_nodos_RI();
void ej_cantidad_nodos_RD();
void ej_ver_si_es_completo();
void ej_ver_si_es_balanceado();
void ej_ej_ver_si_es_avl();
void ej_eliminar_hojas();
void ej_cargar_archivo_texto_variable();
void ej_cargar_archivo_binario_fijo();
void ej_mostrar_archivo_binario_fijo();
void ej_mostrar_archivo_texto_variable();
#endif // FUNCIONESVARIAS_H_INCLUDED
