#include "cadenas.h"
#include <stdio.h>

///NORMALIZA CADENA
char* normalizar(char* s)
{
    char *dev=s,
         *fin=s;
    while(*fin)
    {
        while(esBlanco(*fin))
            fin++;
        if(*fin)
        {
            *s=aMayusc(*fin);
            s++;
            fin++;
        }
        while(!esBlanco(*fin)&&*fin)
        {
            *s=aMinusc(*fin);
            s++;
            fin++;
        }
        if(esBlanco(*fin))
        {
            *s=' ';
            s++;
            fin++;
        }
    }
    if(s>dev&&esBlanco(*(s-1)))
        s--;
    *s='\0';
    return dev;
}
///VERIFICA SI 2 CADENAS SON ANAGRAMA
int anagrama(char* cad1,char* cad2)
{
    char *aux1=cad1,//Recordar donde empezaba la cadena
         *aux2=cad2;//Recordar donde empezaba la cadena
    int   auxcant1,
          auxcant2;
    while(*cad1)
    {
        cad1 = proxima_palabra(cad1);
        //printf("el primer char es %c",*cad1);
        auxcant1=cuentochar(aux1,*cad1);
        auxcant2=cuentochar(aux2,*cad1);
        if(auxcant1!=auxcant2)//Primer comparacion valida
            return 0;
        cad1++;
    }
    while(*cad2)
    {
        cad2=proxima_palabra(cad2);
        auxcant2=cuentochar(aux2,*cad2);
        auxcant1=cuentochar(aux1,*cad2);
        if(auxcant1!=auxcant2)//Segunda comparacion valida
            return 0;
        cad2++;
    }
 return 1;
}
///CUENTA LA CANTIDAD DE CHAR EN UNA PALABRA HASTA ESPACIO
int cuentochar(const char* cad1,char c)
{
    int cant=0;
    while(*cad1)
    {
        while(esBlanco(*cad1))
            cad1++;
        if(*cad1==c)
            cant++;
        cad1++;
    }
    return cant;
}
///OBTIENE DE INT LA CADENA DE CHAR CORRESPONDIENTE
char *i_toa(int n, char *s, int base)
{
    static const char digitos []={"0123456789ABCDEFGHIJKLMNOPQRSTUVWYZ"};
    char * ini = s,
         * fin,
         aux;
    unsigned num,
             resto;
    if( base == 10 && n < 0 )
    {
        *ini='-';
         ini++;
         num = (unsigned)-n;
    }
    else
        num = (unsigned)n;
    fin=ini;
    do
    {
        resto = num % base;
        *fin = digitos [resto];
        fin++;
        num /= base;
    }while (num);
    *fin = '\0';
    fin--;
    while(ini < fin)
    {
        aux = *ini;
        *ini = *fin;
        *fin = aux;
        ini++;
        fin--;
    }
    return s;
}
///OBTIENE DE CADENA DE CHAR* LOS INT CORRESPONDIENTES
int a_toi(const char *cad)
{
    int     acum = 0;
    char    signo;
    while(esBlanco (*cad))
        cad++;
    if(*cad=='-')
    {
        cad++;
        signo='-';
    }
    else
    {
        if(*cad=='+')
            cad++;
        signo='+';
    }
    while(esDigito(*cad))
    {
        acum = acum * 10 + *cad - '0';
        cad++;
    }
    return (signo == '-' ? -acum : acum );
}

void *mem_chr (const void *cadena, const char caracter, int cantidad)
{
    while ( cantidad && caracter != *(char*)cadena )
    {
        cantidad--;
        cadena++;
    }
    return cantidad ? (char*)cadena : NULL;
}
///MUEVE MEMORIA Y VALIDA EL MOVIMIENTO
void *mem_move (void* dest, const void *orig, int cant)
{
    //La copia termina tan pronto como se copió el byte car de orig a
    //dest, o se han copiado cant bytes de orig a dest, lo que ocurra primero
    //Aunque los bloques orig y dest estén superpuestos los bytes en las
    //areas superpuestas se copian correctamente a dest
	char       *tmp = dest;
	const char *aux   = orig;

	if (dest <= orig)
    {
        while (cant--)
			*tmp++ = *aux++;
	}
	else
    {
		tmp += cant;
		aux += cant;
		while (cant--)
			*(--tmp) = *(--aux);
	}
	return dest;
}
///COPIA MEMORIA PERO NO VALIDA
void *mem_cpy(void *dest, const void *orig, int cant)
{
    //La copia termina tan pronto como se copió el byte car de orig a
    //dest, o se han copiado cant bytes de orig a dest, lo que ocurra primero .
    void *auxi = dest;
    while(cant--)
    {
        dest = (void*)orig;
        dest++;
        orig++;
    }
    return auxi;
}
///COMPARA MEMORIA Y TIENE DELIMITADOR DE CUANTA COMPARAR
int mem_cmp ( const void *cad1, const void *cad2, int cant)
{
    //Compara los primeros cant bytes a partir de las direcciones
    //cad1 y cad2 como unsigned char
    if ( !cant)
        return 0;
    while ( cant && *(char*)cad1 == *(char*)cad2 )
    {
        cant--;
        cad1++;
        cad2++;
    }
    return *(unsigned char *)cad1 - *(unsigned char *)cad2;
}

///CONCATENA 2 CADENAS
char *str_cat(char *dest, const char *orig)
{
    //Concatena una copia de orig al final de dest, la longitud de la cadena
    //resultante es la suma de las longitudes, la cadena resultante tendrá su carácter
    //terminador nulo . El terminador nulo de dest es pisado por el primer carácter
    //de orig y así sucesivamente .
    char* aux = dest;
    while ( *dest)
        dest++;
    while ( *orig )
    {
         *dest = *(char*)orig;
         dest++;
         orig++;
    }
    *dest = '\0';
    return aux;
}
///COMPARA 2 CADENAS
int str_cmp(const char *cad1, const char *cad2)
{
    //Hace una comparación sin signo (unsigned char) de las cadenas cad1 y cad2
    while(*cad1 && *cad1 == *cad2)
    {
        cad1++;
        cad2++;
    }
    return *(unsigned char *)cad1 - *(unsigned char *)cad2;
}
///COMPARA Y SI HAY MAYUSCULAS O MINUSCULAS LAS ESTANDARISA EN LA COMPARACION
int str_cmpi(const char* cad1,const char* cad2)
{
    //Hace una comparación indistintamente si sean mayusculas o minusculas entre cad1 y cad2

    while( *cad1 && *cad2 && !((aMinusc(*cad1)) - (aMinusc(*cad2)) ) )
    {
        cad1++;
        cad2++;
    }
    return ( (aMinusc(*cad1) ) - ( aMinusc(*cad2) ) );
}
///COMPARA HASTA UN MAXIMO NUMERO DE COMPARACIONES
int str_ncmp(const char*cad1 , const char*cad2 ,int max )
{
    //Compara cad1 y cad2 hasta null de alguna o maxima cantidad de comparaciones de max
    while( max>0 && *cad1 && *cad2 && !( *cad1 - *cad2 ) )
    {
        cad1++;
        cad2++;
        max--;
    }
    return *cad1 - *cad2;
}
///COPIA 2 CADENAS
char *str_cpy(char *dest, const char *orig)
{
    //Copia la cadena desde orig a dest, termina una vez copiado el terminador nulo
    char *auxi = dest;
    while( *orig )
    {
        *dest = *(char*)orig;
        dest++;
        orig++;
    }
    *dest = '\0';
    return auxi;
}
///CUENTA LONGITUD DE CADENA
int str_len(const char *cade)
{
    int cont = 0;
    while( *cade != '\0')
        {
            cont++;
            cade++;
        }
    return cont;

}
///CADENA A MINUSCULAS
char *str_lwr(char *orig)
{
    //Transforma los carácteres en mayúscula de la cadena, cuya dirección de
    //comienzo recibe, a minúscula (A..Z -> a..z)
    char *aux = orig;
    while( *orig )
    {
        *orig = to_lower(*orig);
        //*orig = aMinusc (*orig);
        orig++;

    }
    return aux;

}
///CADENA A MAYUSCULAS
char *str_upr(char *orig)
{
    //Transforma los carácteres en minúscula de la cadena, cuya dirección de
    //comienzo recibe, a mayúscula (a..z -> A..Z)
    char *aux = orig;
    while( *orig )
    {
       *orig = to_upper (*orig);
       //*orig = aMayusc (*orig);
       orig++;
    }

    return aux;
}
///CARACTER A MINUSCULAS
int to_lower(int x)
{
    //Devuelve el número de ASCII de la minúscula si recibe una mayúscula, de
    //lo contrario devuelve lo que recibe
    return x == -1 ? x : (x &= 0xff) >= 'A' && x <= 'Z' ? x + 'a' - 'A' : x;
}
///CARACTER A MAYUSCULAS
int to_upper(int x)
{
    //Devuelve el número de ASCII de la mayúscula si recibe una minúscula, de
    //lo contrario devuelve lo que recibe
    return x == -1 ? x : (x &= 0xff) >= 'a' && x <= 'z' ? x + 'A' - 'a' : x;
}
///BUSCA EN CADENA CARACTER
char *str_chr (const char *cadena, char caracter)
{
    // Busco hasta final de cadena y comparo, si lo encuentro lo devuelvo, sino NULL
    while ( *cadena && *cadena != caracter )
        cadena++;
    return (*cadena == caracter ? (char*)cadena:NULL);
}
///BUSCA EN CADENA CARACTER DE FIN A PRINCIPIO
char *str_rchr(const char *cadena, char caracter)
{
    const char *aux = cadena;
    while(*cadena++);
    while ( *cadena != *aux && *cadena != caracter )
        cadena--;
    return (*cadena == caracter ? (char*)cadena:NULL);
}
///BUSCA EN CADENA CADENA
char * str_str (const char* donde, const char *que)
{
    //Esta funcion busca en donde, lo que quiero encontrar a nivel cadenas
    // Si lo encuentro devuelvo la cadena, sino NULL
    const char *d,
               *q;
    while ( *donde )
    {
        d = donde;
        q = que;
        while ( *d == *q && *q )
        {
            d++;
            q++;
        }
        if ( *q == '\0' )
            return (char*)donde;
        donde++;
    }
    return NULL;
}
///REMPLAZA EN CADENA UNA CADENA BUSCADA CON OTRA MAS LARGA
char *reemplazar (char *cadena, const char * bus, const char* rec)
{
    char* aux; //Asigno donde empieza la cadena
    int   long_bus = str_len(bus); // longitud de palabra a buscar
    int   long_rec = str_len(rec); // longitud de palabra a reemplazar
    aux = str_str(cadena,bus); // comparo char a char hasta encontrar la ocurrencia
    while (aux)
    {   //Copio pasando en donde lo que quiero desde la cantidad que quiero
        // aux+long_rec es desde donde aux+long_bus es quien copio y
        // str_len(aux+long_bus) + 1 es la cantidad de bytes a copiar
        mem_move( aux+long_rec, aux+long_bus, str_len(aux+long_bus) + 1 );
        // luego de expandirla reemplazo aux con lo de rec con la distancia long_rec
        mem_move( aux, rec, long_rec);
        aux = str_str( aux + long_rec, bus); // comparo char a char hasta encontrar la ocurrencia
    }
    return cadena;
}
///DESPLAZA CADENA LA CANTIDAD DESEADA DESDE HACIA DONDE
void desplazar_cadena (char * donde,  char* desde, int cant)
{
    desde++;
    while ( --cant )
    {
        *donde = *desde;
        desde++;
        donde++;
    }
}

///CODIFICACION RENATA
///MODIFICA A LA CADENA INCREMENTANDO N CANTIDAD DE LETRAS SIENDO N LA POSICION A LA LETRA CORRESPONDIENTE
void modificar_cadena (char * cad, const int cant)
{
    int num= 0;
    while ( num < cant)
    {
        num++;
        *cad += num;
        if( *cad > 'z')
            *cad = 'a' + *cad - 'z';
        cad++;
    }
}
///INVIERTO CADENA CON LA CANTIDAD DE CARACTERES QUE LE INDICO
void invertir_cadena (char *cad, const int cant)
{
    char aux,
        *fin = cad + cant -1; //Lleve a final de cadena
    while (fin > cad)
    {
        aux  = *cad;
        *cad = *fin;
        *fin = aux;
        cad++;
        fin--;
    }
}

char *proxima_palabra ( const char* cad)
{
    while (esBlanco(*cad))
        cad++;
    return (char*)cad;
}

char *fin_palabra ( const char* cad)
{   /** || *cad != '\0' || y cualquier caracter que se te ocurra**/
    while (esCaracter(*cad) )
        cad++;
    return (char*)cad;
}

char *str_tok ( char *array, const char *delimitador)
{
    char *aux = NULL;
    static char *cadena;
    int cant = 0;

    if (array != NULL)
        cadena = array;
    cant = str_spn ( cadena, delimitador );
    while ( cant != 0)
    {
        *cadena = '\0';
        ++cadena;
        --cant;
    }
    if ( *cadena != '\0' )
    {
        aux = cadena;
        cant = str_cspn( cadena, delimitador );
        cadena += cant;
        *cadena = '\0';
        ++cadena;
    }
    return aux;
}

int str_spn ( const char *dest, const char *quien)
{   //Averigua la longitud del segmento inicial de un string que consista
    //únicamente en caracteres contenidos dentro de una máscara dada.
    int cant = 0;
    while ( *dest != '\0' )
    {
        const char *aux = quien;
        while (*dest != *aux && *aux != '\0' )
            ++aux;
        if ( *dest == *aux )
            ++cant;
        else
            break;
        ++dest;
    }
    return cant;
}

int str_cspn (const char *dest, const char *quien)
{   // Averiguar la longitud del segmento inicial que no coincida con una máscara
    int cant = 0;
    while ( *dest != '\0' )
    {
        const char *aux = quien;
        while (*dest != *aux && aux != '\0')
            ++aux;
        if (*dest == *aux)
            break;
        else
            ++cant;
        ++dest;
    }
    return cant;
}

char *str_pbrk(const char *cad1, const char *quien)
{  //Localiza caracteres de quien en la cadena
    const char *aux = quien;
    if (! *cad1 )
        return (char *) NULL;
    while (*cad1)
    {
        for (aux = quien; *aux; aux++)
        {
            if (*cad1 == *aux)
                break;
        }
        if (*aux)
            break;
        cad1++;
    }
    if (*aux == '\0')
    cad1 = NULL;
    return (char *) cad1;
}
///ELIMINA EN CADENA LA SUBCADENA ENCONTRADA
char * eliminarSubCad( char *cad, const char *sub )
{
    int ls = str_len( sub );
    char *aux;

    aux = str_str( cad, sub );
    while ( aux )
    {
        str_cpy( aux, aux + ls );
        aux = str_str( cad, sub );
    }
    return cad;
}

int palindromo(const char *palabra)
{
    char    *origen=(char*)palabra,
            *fin;
            //*aux1=palabra,
           // *aux2=palabra,
           // *aux3;
           // *aux2=*aux3;//porque negro
    int     cant=-1,
            cantaux=0;
    while(*palabra)
    {
        if(!esBlanco(*palabra))
            cant++;
        palabra++;
    }
    cant/=2;
    palabra--;
    fin=(char*)palabra;
    while(cantaux <= cant)
    {
        while(esBlanco(*origen))
            origen++;
        while(esBlanco(*fin))
            fin--;
        //if(!esBlanco(*origen)&&*origen)//que puse
        if(*origen!=*fin)
        {
            return 0;
            //*aux1=*origen;//
            //*aux2=*origen;
            //aux1++;
            //aux2++;
            //origen++;
        }
    origen++;
    fin--;
    cantaux++;
    }
    /*hile(aux2!=aux3)
    {
        if(*aux1==*aux3)
        {
            aux1--;
            aux3++;
        }
        else
            return 0;
    }*/
    return 1;
}



int cuentaPalabras( const char *cad )
{
    char *s=(char*)cad;
    int cont=0;

    while ( *s && *s!='.' )
    {
        while ( esBlanco(*s) )
            s++;

        while( *s && !esBlanco(*s) && *s!='.' )
            s++;

        if( esBlanco(*s) || *s=='.' )
            cont++;
    }

    if (!esBlanco(*(s-1)) && *s!='.' )
        cont++;

    if( *s=='.' && esBlanco(*(s-1)))
       cont--;

    return cont;
}

int longitud ( const char * s )
{
    char *cad=(char*)s;
    int cont=0,
        aux=0;

    while( *cad && *cad!='.' )
    {
        while( esBlanco(*cad) )
        {
            cad++;
        }

        while( *cad && !esBlanco(*cad) && *cad!='.' )
        {
            cont++;
            cad++;
        }

        if(cont>aux)
        {
            aux=cont;
        }
        cont=0;
    }
    return aux;
}

char * primerPalabra( const char * texto, char * pripal )
{
    char *s=(char*)texto,
         *pri=pripal;
    int flag=0;

    while( *s && flag==0 )
    {
        while( esBlanco(*s) )
            s++;

        while( *s && !esBlanco(*s) && *s!='.' )
        {
            *pri=*s;
            pri++;
            s++;
        }
        flag=1;
    }
    *pri='\0';
    return pripal;
}

int repite ( const char * texto, const char * palabra )
{
    char *s=(char*)texto,
         *pal=(char*)palabra;

    int cont=0;

    while ( *s && *s!='.' )
    {
        while( *pal && *s==*pal )
        {
            s++;
            pal++;
            if(*pal=='\0')
        {
            cont++;
        }
        }

       pal=(char*)palabra;
       s++;
    }
    return cont;
}





