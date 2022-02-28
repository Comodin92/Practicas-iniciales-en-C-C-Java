/**//*             en los siguientes macroreemplazos indique:             *//**/
/**//*    su(s)         APELLIDO(S)     completo(s)                       *//**/
/**//*    su(s)         Nombre(S)       completo(s)                       *//**/
/**//*    su legajo     NÚMERO DE DNI   con los puntos de millón y de mil *//**/
/**//*    COMISIÓN                                                        *//**/
/**//*              reemplazando los que están como ejemplo               *//**/
#define APELLIDO    "Gutierrez"
#define NOMBRE      "Damian Edgardo"
#define DOCUMENTO   "36.902.267"
#define COMISION    "02(3362)"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** aquí insertaremos nuestras observaciones / correcciones                  **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ *//**/



/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <string.h>
/***
    Macros utilizados
***/
#define ES_MAYUSCULA(X) (((X)>= 'A' && (X)<= 'Z'))
#define A_MAYUSCULA(X) ((ES_MAYUSCULA(X)? (X) : (X) - 32 ))
#define ES_BLANCO(X) ((X) == ' ' || (X) == '\t' ||  (X) == 10 ? 1 : 0)
#define DOBLE_BLANCO(x)  (ES_BLANCO(x) && ES_BLANCO(x+1)())? 0 : 1
/***
    Prototipos que usé para punto 1a
***/
char buscarAparicion(const char *linea,const char *busq) ;
void guardarTamCampo(const char *linea,int *campos);
void texto_a_estructura(char *linea,tPedido *ped, int *campos, int posi);
void copiarCodigoClave(char *claPro, const char *ini, const char *fin);
/** para el PUNTO 1 a.- **/
int leerTxtGrabarBin_MIO(const char *nomSinExt, int campos[][9], int filaTope,
                         const char *txt, const char *bin)
{
    /***
           Variables:
           Char Linea[] : Lugar donde cargo los registros del archivo, uso una capacidad estimada que no me creará conflicto
           char nomArcTex, nomArcTex : son donde almaceno el nombre del archivo / lugar de destino
           band_R1 : bandera que utilizo para usar el primer registro de cada archivo, el que me indica que tipo de archivo es A,B,C,D,E,etc.
           posi: Es la posicion de el array bidimensional donde voy a trabajar, si es la posicion 1, debo trabajarlo como 1-1 ya que el vec arranca de 0 logicamente
           cant_regis: Cuenta la cantidad de registros
           tipo : contendrá el char que me necesito para ver el tipo de archivo, ejemplo si tengo Tipo_A, luego de un proceso en tipo tengo 'A'
        ***/
    char linea[60],
         nomArcTex[strlen(nomSinExt) + strlen(txt)+1],
         nomArcBin[strlen(nomSinExt) + strlen(bin)+1], ///Ya que no tengo el nombre del archivo debo armarlo yo, reservo espacio suficiente
         tipo;
    int band_R1 = 1,
        posi,
        cant_regis=0;
    tPedido ped;
    ///Copio y concateno para obtener el nombre de cada archivo
    strcpy(nomArcTex,nomSinExt);
    strcat(nomArcTex,txt);
    strcpy(nomArcBin,nomSinExt);
    strcat(nomArcBin,bin);

    FILE *arch_txt = fopen(nomArcTex, "rt"),
          *arch_bin = fopen( nomArcBin, " w + b");
    if(!arch_bin ||!arch_txt)
    {
        if(!arch_txt && !arch_bin)
        {
            printf("Error com ambos archivos\n");
            fclose(arch_bin);
            fclose(arch_txt);
            return -3;
        }
        if(!arch_bin)
        {
            printf("Error com archivo binario\n");
            fclose(arch_bin);
            fclose(arch_txt);
            return -2;
        }
        printf("Error com archivo texto\n");
        fclose(arch_bin);
        fclose(arch_txt);
        return -1;
    }
    while(fgets(linea,sizeof(linea),arch_txt))
    {
        cant_regis++;
        if(band_R1) ///Si es el primer registro debo saber que tipo de archivo tengo, porque varia el orden de los campos de la estructura
        {
            tipo = buscarAparicion(linea,"Tipo_");
            band_R1 = 0;
            posi = (A_MAYUSCULA(tipo) - 64); /// A tiene ascii 65 si le resto 64 o el ascii del '@' obtengo 1, si está en minuscula hago conversion para aplicar la resta
        }
        if( posi > filaTope) ///Si la fila se excede salgo y doy mensaje de error
        {
            printf("La fila se excede, fila %d -> tope %d",posi,filaTope);
            return -4;
        }
        if(cant_regis == 3) ///Si estoy en registro 3 debo calcular el tamaño de cada campo
            guardarTamCampo(linea,campos[posi-1]);
        if(cant_regis >= 4) ///Ya cuando estemos en los registros mayores al 4to hacemos el resto de procedimientos
        {
            texto_a_estructura(linea,&ped,campos[posi-1], posi); ///Cargo la estructura para poder grabarlo en el archivo correspondiente
            fwrite(&ped,sizeof(tPedido),1,arch_bin);
        }
    }
    rewind(arch_bin); ///Retrocedo al inicio
    fread(linea, sizeof(char),sizeof(linea)/sizeof(char),arch_bin);
    while(!feof(arch_bin))
        fread(linea, sizeof(char),sizeof(linea)/sizeof(char),arch_bin);
    fclose(arch_bin);
    fclose(arch_txt);
    return cant_regis;
}

char buscarAparicion(const char *linea,const char *busq)
{
    /***
        Debo buscar Tipo_ y acontinuacion tengo la letra que necesito
        logica:
        1 - Mientras cadena exita
        2 - comparo ambas cadenas punteros a cadena
        3.1 - si el contenido de cada puntero es igual incremente ambas cadeans
        3.2 - si son distintas, incremento linea(donde busco) y reseteo busqu( cadena que busco) con un
        puntero al inicio de subcadena

    ***/
    char *resetBus= (char*) busq;
    while(*linea)
    {
        if(*linea == *busq)
            busq++;
        else
            busq =resetBus;
        linea++;
        if(!*busq)
            return *linea;
    }
    return '\0';
}

void guardarTamCampo(const char *linea,int *campos)
{
    /***
    Como el tercer registro del archivo determina la capacidad maxima de un campo y tenemos un vector de enteros
    con espacios disponible para usar, decido determinar el tam de cada campo y almacenarlos en dicho vector
        _______________________________________________
        | 1  | 3  | 4  |  2 |  0  |  3 | 4  | 5  |  11 | son valores aleatorios, no son para tomar como ejemplos del ejercicio
        utilizo los primero 4 posicions del vec para determinar el orden de los campos, dejo la posicion 5
        con basura o con lo que se haya inicializado y uso de la posicion 5 a la 9 el tamaño de cada campo
        ejemplo
        posicion 5 me dice cual es el tamaño del campo 1, posicion 6 tamaño del campo 2, etc.
    Logica:
        1 - Mientras exista cadena
        2 - posicion puntM en la posicion de insercion
        3 -  y la linea sea igual a '=' comparo. (uso while porque se que son consecutivos y hay 1 espacio de separacion
                                                  entre campo y campo (o vulgarmente entre = e = )
        4 - Cargo el tamaño del campo e incremente linea y campo ( vector de enteros)
    ***/
    int tam_campo=0,
        *puntM = campos +5;
    while(*linea)
    {
        while(*linea == '=')
        {
            tam_campo++;
            linea++;
        }
        *puntM = tam_campo;
        tam_campo = 0;
        linea++;
        puntM++;
    }
}


void texto_a_estructura(char *linea,tPedido *ped, int *campos, int posi)
{
    /***
       Como ya se el tamaño máximo de cada campo (dado por el 3er registro),
       busco un puntero al inicio y otro al final de cada campos, además como hay 1 espacio entre campo y campo (Si usa
       tam maximo). Si no ocupa el tamaño máximo solo es cuestion de validar. Utilizo un swicht para determinar en que orden
       se vienen los datos.
       lógica:
        1 - Mientras la cadena sea válida repito el ciclo
        2 - posiciono ini al comienzo del campo y fin al final (previamente cargué el tam de cada campo en el vec de entero)
        3 - Pongo \0 en fin
        4 - Asigno el campo correspondiente a la estructura
        5 -  Mientras no esté en el ultimo campo ini va al inicio del siguiente campo
        6 -  incremento campos ( vector de enteros donde tengo el orden de los campos y el tamaño de los mismos)

    ***/
    char *fin = linea, *ini=linea;
    while(*fin ||*fin == '\n')
    {
        fin += (*(campos+5));
        *fin = '\0';
        switch(*campos)
        {
        case 1:
            copiarCodigoClave(ped->codClie,ini, fin-1);
            fflush(stdin);
            break;
        case 2:
            copiarCodigoClave(ped->claProd,ini,fin-1);
            fflush(stdin);
            break;
        case 3:
        {
            ped->cantPed = atoi(ini);
            break;
        }
        case 4:
            ped->precUni = atof(ini);
            break;
        }
        *fin = ' ';
        fin++;
        if(*fin || *fin == '\n')
            ini = fin;
        campos++;
    }
    fflush(stdin);
}

void copiarCodigoClave(char *clav, const char *ini, const char *fin)
{
    /***
         puntero inicio está al comienzo de la palabra y puntero fin al final del tamaño maximo de la palabra,
         entonces debo retroceder hasta encontrar caracter válido y luego copia hasta que la direccion de memoria de ini
         llegue hasat la direccion d fin
         Logica:
         1 Retrocedo fin a el ultimo caracter válido (aplicada al contexto del ejercicio) de la cadena
         2 Mientras direccion de inicio sea menor o igual que direccion fin
         3 copio en la cadena destino(clav) lo que tengo en origen(ini)
         4 IMPORTANTE colocarle el fin de cadena porque sino va a mostrar el resto de basura que tenga
         4.2 Cuando digo resto de basura me refiero a que el campo puede ser de 10 por ejemplo y tengo como palabra "Hola"
         Si no coloco \0 luego de 'a' me muestra los otros campos con lo que tengan

    ***/
    while(ES_BLANCO(*fin))
        fin--;
    while(ini <= fin)
    {
        *clav = *ini;
        ini++;
        clav++;
    }
    *clav = '\0';
}
/***
    Prototipos que usé para punto 1b
***/
int cmpPedidos(const void *d1, const void*d2);

/** para el PUNTO 1 b.- **/
int leerPedsYAgrupar_MIO(const char *nomSal,
                         const char *nomEnt1, const char *nomEnt2)
{
    tPedido nue_reg,regis_lect;
    int cant_reg = 0;
    FILE *arch_eA, *arch_eB, *arche_agru;

    arch_eA = fopen(nomEnt1, "rb");
    if(!arch_eA)
        return -1;
    arch_eB = fopen(nomEnt2, "rb");
    if(!arch_eA)
        return -2;
    arche_agru = fopen(nomSal, "w + b");
    if(!arche_agru)
        return -3;
    fread(&regis_lect, sizeof(tPedido),1,arch_eA);
    while(!feof(arch_eA)) ///Concateno primer archivo
    {
        cant_reg++;
        fwrite(&regis_lect, sizeof(tPedido),1,arche_agru);
        fread(&regis_lect, sizeof(tPedido),1,arch_eA);
    }
    fread(&regis_lect, sizeof(tPedido),1,arch_eB);
    while(!feof(arch_eB)) ///Concateno el segundo archivo
    {
        cant_reg++;
        fwrite(&regis_lect, sizeof(tPedido),1,arche_agru);
        fread(&regis_lect, sizeof(tPedido),1,arch_eB);
    }
    rewind(arche_agru);
    fread(&nue_reg, sizeof(tPedido),1,arche_agru);
    while(!feof(arche_agru))
        fread(&nue_reg, sizeof(tPedido),1,arche_agru);
    fclose(arche_agru);
    fclose(arch_eA);
    fclose(arch_eB);
    return 1;
}

/** para el PUNTO 1 c.- **/
int leerPedsYResumir_MIO(const char *nomSal, const char *nomEnt)
{
    /***
        Variables:
        tPila pilaOrdenada, pilaAux : Pila ordenada, es donde voy a dejar los registros ordenados y pila aux la uso para recibir los datos que saco temporalmente de ordenada
        tPedido pedido_reg, pedido_pil; Pedido_Reg es estructura donde voy a recibir los campos del archivo, pedido_pila es estructura donde cargo los campos que saco de pila
        tResumido resum, resum_aux : Son las estructuras finales, a diferencia del tPedido este tiene un identificador de registro. Almaceno la pila ordenada en resum,
        y uso resum_aux para agarrar lo que hay en tope (en el proceso final)
        int cant_reg determina la cantidad de registros
        acum_PU=0 acumulador donde guardo cantidad pedidos
        marca_PU=1 bandera para un proceso para acumular cantidad de pedidos

        Para ordenar el archivo hago uso de 2 colas, uso una pila para ir insertando ordenado y la otra como apoyo para sacar de la ordenada (si el cliente que quiero
        insertar no va encima del tope de pila). Luego de ordenarlo proceso a acumular cuando el cliente y clave de producto son iguales pero cuando el precio unitario
        es distinto no acumulo y lo trabajo como 2 clientes distintos.
         Lógica: Vamos directo al ordenamiento con pilas
         1 Si la pila está vacia inserto, ya que sé que es el más grande por ser el primero -> leo siguiente reg
         2 comparo lo que hay en tope y en el registro del archivo, si el cliente de la estructura es mayor que el de la pila
         2.1 Saco de la pila y pongo en pila aux(mientras tenga algo) hasta que la estructura del registro no sea mayor que la estructura de la pila
         2.2 Cuando llego al lugar de insercion coloco el registro del archivo en pila ordenada, y vuelvo a poner todo lo que tenia en pila aux en pila ordenada
         2.3 si el cliente de la estructura NO es mayor que el de la pila -> inserto en pila ordenada
         4 leo siguiente registro, y repito el ciclo hasta leer todo el archivo.
         5 Una vez que tengo el archivo ordenado comienzo a acumular siempre y cuando el cliente tenga mismo codigo cliente y clave producto, si tienen distinto
         precio unitario, no se acumula, Se toman como 2 clientes diferentes
    ***/
    tPila pilaOrdenada, pilaAux;
    tPedido pedido_reg, pedido_pil;
    tResumido resum, resum_aux;
    int cant_reg=1,
        acum_PU=0,
        marca_PU=1,
        marcaTope=1;
    FILE *arch_ent, *arch_sal;
    arch_ent = fopen(nomEnt,"rb");
    if(!arch_ent)
        return -1;
    arch_sal = fopen(nomSal,"w + b");
    if(!arch_sal)
        return -1;

    fread(&pedido_reg, sizeof(tPedido),1,arch_ent);
    crearPila(&pilaAux);
    crearPila(&pilaOrdenada);
    while(!feof(arch_ent))
    {
        if(pilaVacia(&pilaOrdenada)) ///si la pila está vacia inserto
        {
            ponerEnPila(&pilaOrdenada,&pedido_reg,sizeof(pedido_reg));
        }
        else ///si la pila no está vacia debo comparar lo que tengo en tope(ultimo insertado en pila) y el registro del archivo que leí
        {
            verTope(&pilaOrdenada,&pedido_pil,sizeof(pedido_pil));
            if( cmpPedidos(&pedido_reg,&pedido_pil) > 0)
                ///registro es mayor q tope
            {
                do
                {
                    sacarDePila(&pilaOrdenada,&pedido_pil,sizeof(pedido_pil));
                    ponerEnPila(&pilaAux, &pedido_pil, sizeof(pedido_pil));
                }/*** Mientras el tope tenga algo o el registro siga siendo mayor que tope seguire sacando de pila e insertando en pilaAux***/
                while(verTope(&pilaOrdenada,&pedido_pil, sizeof(pedido_pil)) && cmpPedidos(&pedido_reg,&pedido_pil) > 0 );
                ponerEnPila(&pilaOrdenada, &pedido_reg,sizeof(pedido_reg)); ///Coloco el registro del archivo en pila ordenada
                while(sacarDePila(&pilaAux,&pedido_pil,sizeof(pedido_pil))) ///Saco lo que puse en pilaAux y vuelvo a insertarlo en pilaOrdenada para mantener orden
                    ponerEnPila(&pilaOrdenada, &pedido_pil, sizeof(pedido_pil) );
            }
            else ///pero si el registro  es menor que el tope
                ponerEnPila(&pilaOrdenada, &pedido_reg,sizeof(pedido_reg));
        }
        fread(&pedido_reg, sizeof(tPedido),1,arch_ent); ///Leo siguiente registro
    }
    ///cant_reg = ftell(arch_ent)/sizeof(tPedido);
    while(sacarDePila(&pilaOrdenada, &resum, sizeof(resum)))
    {
        if(verTope(&pilaOrdenada,&resum_aux,sizeof(resum_aux)) && cmpPedidos(&resum.pedido,&resum_aux.pedido) == 0 && marca_PU) ///Guardo el primer precio unitario de la pila
        {
            acum_PU = resum.pedido.cantPed;
            marca_PU = 0;
        }
        while( marcaTope && cmpPedidos(&resum.pedido,&resum_aux.pedido) == 0 && resum.pedido.precUni == resum_aux.pedido.precUni)
        {
            /***
                   mientras sean el mismo cliente acumulo con mismo precio unitario
            ***/
            acum_PU+=resum_aux.pedido.cantPed;
            sacarDePila(&pilaOrdenada, &resum, sizeof(resum));
            marcaTope=  verTope(&pilaOrdenada,&resum_aux,sizeof(resum_aux));
        }///Cuando salgo actualizo registro y si ACUM_PU tiene valor no nulo es porque al menos 1 vez se repite el cliente
        if(acum_PU)
            resum.pedido.cantPed = acum_PU;
        resum.nroRegistro = cant_reg++;
        fwrite(&resum,sizeof(tResumido),1,arch_sal); ///Grabo en archivo Resumido
        marca_PU =1;
        acum_PU = 0;
    }
    rewind(arch_sal); ///Retrocedo al inicio
    fread(&resum,sizeof(tResumido),1,arch_sal);
    while(!feof(arch_sal))
        fread(&resum,sizeof(tResumido),1,arch_sal);

    fclose(arch_ent);
    fclose(arch_sal);
    return cant_reg;
}
int cmpPedidos(const void *p1,const void *p2)
{
    tPedido *ped1=(tPedido*) p1;
    tPedido *ped2=(tPedido*) p2;
    int res;
    if((res = strcmp(ped1->codClie, ped2->codClie) ) ==  0 )
        return (strcmp(ped1->claProd, ped2->claProd)) ;
    return res;

}
/** para el PUNTO 1 d.- **/ ///NO HAY ENUNCIADO
int despacharPedidos_MIO(const char *nomOka, const char *nomBlk,
                         const char *nomUnk, const char *nomPagos,
                         const char *nomResu)
{
    return 1;
}

/**                  FIN de PUNTO 1 **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para crear y mostrar los datos de PUNTO 2 **/


/** HASTA ACÁ NO VA EN EL "ENTREGABLE"                                       **/





/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

