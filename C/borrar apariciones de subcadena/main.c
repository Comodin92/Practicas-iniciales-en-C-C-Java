#include <stdio.h>
#include <stdlib.h>
///Dami del futuro cuando leas esto, acordate de hacer los dibujos porque no vas a entender nada
char* borrar_de_subcadena(char * destino, const char* origen);///No se si es optimo pero pareciera que se del tema(?
int main()
{
    char destino[]="Damian no es crack";
    char origen[]="Damian";
    printf("%s\n",borrar_de_subcadena(destino,origen));
    return 0;
}

char* borrar_de_subcadena(char * destino, const char* origen)
{
    char *marca, *ret = destino,*ini=destino;

    while(*origen)
    {
        destino = ini;
        while(*origen && *destino)
        {
            if( *destino == *origen )
            {
                marca = destino;
                while(*(destino+1))
                {
                    *destino = *(destino+1);
                    destino++;
                }
                *destino = '\0';
                destino = marca;
            }
            else
                destino++;
        }
        origen++;
    }
    return ret;
}
