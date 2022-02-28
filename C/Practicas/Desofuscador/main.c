#include "Desofuscador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	char c[250];
	char* ptrC;
	FILE* pf = fopen("archivoOfuscado.txt", "rt");
	FILE* pf2 = fopen("archivoDESofuscado.txt", "wt");
	while (fgets(c, 250, pf))
	{
		ptrC = inversor(restador(c));
		printf("%s", ptrC);
		fwrite(ptrC, strlen(ptrC), 1, pf2);
	}
	fclose(pf);
	fclose(pf2);
}