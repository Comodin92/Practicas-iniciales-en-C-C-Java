#include "../Bibiotlecas/libreriasString.h"

int main()
{
    int opc,cantidad;
    char cad1[10]="Pezzola",
         cad2[]="Renata",
         cadena[]="Activa tu cuenta",
         c='a';
    do
        {
            printf("\t\tLIBRERIAS STRING\n\n1-STRCAT\n2-STRCHR\n3-STRCMP\n4-STRCPY\n5-STRLEN\n"
                   "6-STRNCAT\n7-STRNCMP\n8-STRNCPY\n0-SALIR\n");
            scanf("%d",&opc);
            switch(opc)
            {
            case 1:
                printf("Añade una copia de la cadena apuntada por s2 (incluyendo el carácter nulo) al final de"
                "la cadena apuntada por s1. El carácter inicial de s2 sobrescribe el carácter nulo al final"
               "de s1\n\n");
               fflush(stdin);
               if(sizeof(cad1) > strlen(cad1)+strlen(cad2))
                    printf("Luego de concatenar queda %s\n",str_cat(cad1,cad2));
               else
                    printf("No se puede concatenar, no hay espacio en la cadena\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Localiza la primera aparición de c (convertido a unsigned char) en la cadena apuntada"
                        "por s (incluyendo el carácter nulo).\n\n");
                printf("La cadena es %s y el caracter a buscar es %c \n",cadena,c);
                printf("Al aplicar la funcion: \t%s \n",str_chr(cadena,c));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("Compara la cadena apuntada por cad1 con la cadena apuntada por cad2.\n");
                switch(str_cmp(cad1,cad2))
                {
                case 1:
                        printf("%s es mas grande que %s\n",cad1, cad2);
                        break;
                case 0:
                        printf("%s y %s son iguales\n",cad1,cad2);
                        break;
                case -1:
                        printf("%s es mas chico que %s\n",cad1,cad2);

                }
                system("pause");
                system("cls");
                break;
                case 4:
                    printf("Copia la cadena apuntada por s2 (incluyendo el carácter nulo) a la cadena apuntada por s1\n");
                    if(sizeof(cad1) > strlen(cad2))
                        printf("cadena a copiar %s\nCadena copiada %s\n",cad2,str_cpy(cad1,cad2));
                    else
                        printf("Imposible copiar\n");
                system("pause");
                system("cls");
                break;
                case 5:
                    printf("Calcula el número de caracteres de la cadena apuntada por s.\n\n");
                    printf("La cantidad de caracteres de %s es %d\n",cad1,str_len(cad1));
                    system("pause");
                    system("cls");
                break;

                case 6:
                    printf("Añade no más de n caracteres (un carácter nulo y los demás caracteres siguientes no son añadidos)"
                           "de la cadena apuntada por s2 al final de la cadena apuntada por s1. El carácter inicial de s2"
                            "sobrescribe el carácter nulo al final de s1. El carácter nulo siempre es añadido al resultado.\n");

                    printf("Ingrese cantidad de caracteres a copiar en cad1\n");
                    scanf("%d",&cantidad);
                    if((sizeof(cad1) - strlen(cad1) > cantidad) || strlen(cad2) > cantidad)
                        printf("Concatenar %d caracteres de %s en %s: %s\n",cantidad,cad2,cad1,str_n_cat(cad1,cad2,cantidad));
                    else
                        printf("No se puede concatenar\n");
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    printf("Compara no más de n caracteres (caracteres posteriores al carácter nulo no se tienen en"
                            "cuenta) de la cadena apuntada por s1 con la cadena apuntada por s2.\n");
                    printf("Ingrese el cantidad de caracteres a comparar\n");
                    scanf("%d",&cantidad);
                  if(strlen(cad2) > cantidad || strlen(cad1) > cantidad )
                       {

                        switch(str_n_cmp(cad1,cad2,cantidad))
                        {
                        case 1:
                                printf("%s es mas grande que %s\n",cad1, cad2);
                                break;
                        case 0:
                                printf("%s y %s son iguales\n",cad1,cad2);
                                break;
                        case -1:
                                printf("%s es mas chico que %s\n",cad1,cad2);

                        }
                       }
                    else
                        printf("Imposible comparar\n");
                system("pause");
                system("cls");
                break;
            case 8:
                printf("Copia no más de n caracteres (caracteres posteriores al carácter nulo no son copiados) "
                        "de la cadena apuntada por s2 a la cadena apuntada por s1.");
                printf("Inserte cantidad de caracteres a copiar\n");
                scanf("%d",&cantidad);
                printf("Cadena a copiar: %s \ncadena copiada: %s\n",cad2,str_n_cpy(cad1,cad2,cantidad));
                system("pause");
                system("cls");
                break;
            }
        }while(opc!=0);
    return 0;
}
