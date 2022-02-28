#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

#define TAM 32
#define esBlanco(X) ((X)==' '||(X)=='\t')
#define esCaracter(X) (((X)>='a'&&(X)<='z')||((X)>='A'&&(X)<='Z'))
#define aMayusc(X) ((X)>='a'&&(X)<='z'?(X)-32:(X))
#define aMinusc(X) ((X)>='A'&&(X)<='Z'?(X)+32:(X))
#define esDigito(X) ((X)>='0' && (X)<='9'? 1:0)
#define esAlfanumerico(X) ((X)>='a'&&(X)<='z'||(X)>='A'&&(X)<='Z'||(X)>='0' && (X)<='9'?1:0)

///FUNCIONES DE PARCIALES
char* eliminarSubCad( char *, const char * );
int palindromo(const char *);
char* normalizar( char* );
char* reemplazar (char *, const char * , const char* ); //De parcial
int cuentochar(const char*,char);
char* busco_primer_char(char*); //Busca char valido en cadena
int anagrama(char*,char*); //prueba si es anagrama
char *i_toa(int , char *, int); //devuelve char de unos enteros
int a_toi(const char *);//devuelve entero desde una cadena de char
///FUNCIONES STANDARD DE LOPEZ
void *mem_chr (const void *, const char, int);
void *mem_move (void*, const void *, int ); //mueve memoria y valida el movimiento
void *mem_cpy (void *, const void *, int ); //mueve memoria copiandola
int mem_cmp ( const void *, const void *, int );
char *str_cat (char *, const char *);
char *str_cpy (char *, const char *);
char *str_tok (char *, const char *);
char *str_lwr (char *);
char *str_upr (char *);
char *str_chr (const char *, char );
char *str_rchr(const char *, char );
char *str_str (const char *, const char *);
char *str_pbrk(const char *, const char *); //primer comparacion entre cadenas igual

int str_spn(const char *, const char* );
int str_cspn(const char *, const char *);
int str_cmp(const char *, const char *);
int str_cmpi(const char* ,const char *);
int str_ncmp(const char* , const char* ,int );
int str_len(const char *);
int to_lower(int );
int to_upper(int );
///RENATA ENCRIPTACION DE CADENA
void desplazar_cadena (char * ,  char*, int );
void modificar_cadena (char * , const int );
void invertir_cadena (char *, const int );
char *proxima_palabra (const char *);
char *fin_palabra ( const char* );

///punto 8

int cuentaPalabras( const char *);
int longitud ( const char * );
char * primerPalabra ( const char *, char * );
int repite ( const char *, const char * );




#endif // CADENAS_H_INCLUDED
