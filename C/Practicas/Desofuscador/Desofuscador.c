#include "Desofuscador.h"

char* restador(char* str)
{
	int i = 1;
	char aux;

	char* straux = str;
	if (!str)
		return str;
	while (*str >= ' ')
	{
		while (!(*str >= 'A' && *str <= 'Z' || *str >= 'a' && *str <= 'z'))
		{
			i = (*str == ' ') ? (1) : (i);
			str++;
		}
		aux = *str;
		aux -= i;
		if (aux >= 'A' && aux <= 'Z' && *str >= 'a' && *str <= 'z') //si era minuscula y ahora es mayuscula
			aux = 'Z' - (i - (*str - 'a') - 1);
		else if (aux < 'A') //si se fue del rango de las letras por la resta
			aux = 'z' - ('A' - aux) + 1;
		else if (aux < 'a' && aux > 'Z') // si esta entre las mayus y minus.
			aux = 'Z' - ('a' - aux) + 1;
		*str = aux;
		i++;
		str++;
	}
	return straux;
}

char* inversor(char* str)
{
	char* pLect = str;
	char* ptraux=str;
	char* ret = str;
	char aux;
	while (*str)
	{

		while (*pLect > ' '  && *pLect) 
			pLect++;
		ptraux = pLect + 1;
		pLect--;
		while (pLect > str)
		{
			if (*pLect == '.')
				pLect--;
			aux = *pLect;
			*pLect = *str;
			*str = aux;
			pLect--;
			str++;
		}
		str = pLect = ptraux;
	}
	return ret;
}
