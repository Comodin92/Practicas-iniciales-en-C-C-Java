#include "Varias.h"

char * Varias::str_new_dup(const char * s)
{
    if(s && *s)                 //s es distinto de null, y s tiene algun caracter distinto de \0
    {
        char * aux = new char[strlen(s)+1];  //new es como un malloc.
        if(aux)
        {
            strcpy(aux,s);
        }
        return aux;
    }
    return NULL;
}
