#include "arbol.h"
#include "main.h"

int main()
{

    verMenu();
    return 0;
}


void verMenu()
{
    int         i,
               desdeAltura,
               opcion;

    t_arbol arbol_estructura;
    t_estr vec_est[] = {    {"Damian",1,10},
                            {"Carolina",4,6},
                            {"Edgardo", 3,4},
                            {"Karla",12,3},
                            {"Guarana",2,7},
                            {"ClearView",132, 500},
                            {"Elite",16,9},
                            {"Andrea",8,1}
                        },
        arbolTexto,
        busqueda,

    vecBusq[]= {
        {"Damian"},
        {"Karla"},
        {"Pepe"}
    };
    do
    {
        printf("1 - Crear arbol\n2-Rellenar arbol  (Recursivo)\n3 - Rellenar arbol (iterativo)\n"
               "4 - Mostrar arbol INORDER\n5 - Mostrar arbol PREORDEN\n6 - Mostrar arbol POSTORDEN\n"
               "7 - Cantidad de nodos\n8 - Cantidad nodos hojas\n9 - Cantidad nodos NO hojas\n"
               "10 - Cantidad nodos pares(dni)\n11 - Cantidad nodos impares(dni)\n12 - Promedio nodos pares (promedio de notas)\n"
               "13 - Promedio nodos impares(promedio de notas)\n14 - Mostrar nodos por altura\n15 - Mostras nodos hasta altura inclusive\n"
               "16 - Mostrar nodos desde altura\n17 - Mostras nodos desde altura inclusive\n18 - Ver arbol (girado 90ª a la izq)\n"
               "19 - Altura del arbol\n20 - Altura subarbol izquierdo\n21 - Altura subarbol derecho\n"
               "22 - Buscar clave menor\n23 - Buscar clave mayor\n24 - Busca no clave menor\n25 - Buscar no clave mayor\n"
               "26 - Eliminar nodos hojas\n27 - Podar arbol desde altura\n28 - Podar arbol desde altura inclusive\n"
               "29 - Grabar arbol en archivo de texto\n30 - Leer archivo de texto\n31 - Podar Arbol\n"
               "32 - Arbol Completo | Balanceado | Avl\n33 - Buscar dato clave\n34 - Borrar Nodo (Nombre)\n\n");
        printf("0 - Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
        {
            crearArbol(&arbol_estructura);
            system("cls");
            printf("Se creo arbol\n");
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            for(i=0; i<sizeof(vec_est)/sizeof(t_estr); i++)
                if( insertarEnOrdenR(&arbol_estructura, &vec_est[i],sizeof(t_estr),cmp_Estr))
                    printf("Se inserto en arbol\n");
                else
                    printf("No se inserto, es duplicado\n");
            system("pause");
            break;
        }
        case 3:
        {
             system("cls");
            for(i=0; i<sizeof(vec_est)/sizeof(t_estr); i++)
                if( insertarEnOrdenI(&arbol_estructura, &vec_est[i],sizeof(t_estr),cmp_Estr))
                    printf("Se inserto en arbol\n");
                else
                    printf("No se inserto, es duplicado\n");
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            printf("\ninorden ARBOL con varios datos \n");
            printf("%-*s| %*s | %*s\n",11,"Nombre",10,"D.N.I.",5,"Nota");
            printf("===============================\n");
            mostrarInorden(&arbol_estructura, mostrarEstructura);
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            printf("\npostorden ARBOL con varios datos \n");
            printf("%-*s| %*s | %*s\n",11,"Nombre",10,"D.N.I.",5,"Nota");
            printf("===============================\n");
            mostrarPostorden(&arbol_estructura, mostrarEstructura);
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            printf("\npreorden ARBOL con varios datos \n");
            printf("%-*s| %*s | %*s\n",11,"Nombre",10,"D.N.I.",5,"Nota");
            printf("===============================\n");
            mostrarPreorden(&arbol_estructura, mostrarEstructura);
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            printf("La cantidad de nodos es: %d \n\n\n",contarTodosNodos(&arbol_estructura));
            system("pause");
            break;
        }
        case 8:
        {
            system("cls");
            printf("Cantidad de nodos hojas: %d \n\n\n",contarHojas(&arbol_estructura));
            system("pause");
            break;
        }
        case 9:
        {
            system("cls");
            printf("Cantidad de nodos No hojas: %d \n",contarNoHojas(&arbol_estructura));
            system("pause");
            break;
        }
        case 10:
        {
            system("cls");
            printf("Cantidad de nodos pares(nota): %d \n",contarNodosPares(&arbol_estructura));
            system("pause");
            break;
        }
        case 11:
        {
            system("cls");
            printf("Cantidad de nodos impares(nota): %d \n",contarNodosImpares(&arbol_estructura));
            system("pause");
            break;
        }
        case 12:
        {
            system("cls");
            printf("El promedio de los nodos pares (nota) es: %d\n",promedioNodosPar(&arbol_estructura));
            system("pause");
            break;
        }
        case 13:
        {
            printf("El promedio de los nodos impar(nota) es: %d\n",promedioNodosImpar(&arbol_estructura));
            system("pause");
            break;
        }
        case 14:
        {

            system("cls");
            printf("Arbol\n");
            i=0;
            verArbol(&arbol_estructura,i,sizeof(t_estr));
            printf("Mostrar nodos por altura\nAltura 3:\n");

            mostrarNodoPorAltura(&arbol_estructura,3);
            system("pause");
            break;
        }
        case 15:
        {
            system("cls");
            printf("Arbol\n");
            i=0;
            verArbol(&arbol_estructura,i,sizeof(t_estr));
            printf("\n\nMostrar Nodos hasta altura 3 \n");
            printf("La cantidad de nodos mostrados hasta altura 3 incluida es %d\n",mostrandoHastaAlturaIncluida(&arbol_estructura, 3));
            system("pause");
            break;
        }
        case 16:
        {

            desdeAltura = 3;
            printf("Mostrando desde altura %d\n",desdeAltura);
            mostrarDesdeAlturaSinI(&arbol_estructura, desdeAltura);
            system("pause");
            break;
        }
        case 17:
        {
            system("cls");
            desdeAltura = 3;
            printf("Mostrando desde altura incluyendo %d\n",desdeAltura);
            mostrarDesdeAlturaInc(&arbol_estructura, desdeAltura);
            system("pause");
            break;
        }
        case 18:
        {
            system("cls");
            desdeAltura = 0;
            verArbol(&arbol_estructura, desdeAltura, sizeof(t_estr));
            system("pause");
            break;
        }
        case 19:
        {
            system("cls");
            printf("La altura del arbol es: %d \n", alturaArbol(&arbol_estructura));
            system("pause");
            break;
        }
        case 20:
        {
            system("cls");
            printf("Altura subArbol derecho%d\n",alturaSubArbolDer(&arbol_estructura));
            system("pause");
            break;
        }
        case 21:
        {
            system("cls");
            printf("Altura subArbol izquierdo%d\n",alturaSubArbolIzq(&arbol_estructura));
            system("pause");
            break;
        }
        case 22:
        {
            system("cls");
            buscarMenorClave(&arbol_estructura);
            system("pause");
            break;
        }
        case 23:
        {
            system("cls");
            buscarMayorClave(&arbol_estructura);
            system("pause");
            break;
        }
        case 24:
        {
            system("cls");
//            vecBusq[0].nota = 0;
            printf("El dato menor no clave es(nota):");
            mostrarMenorNoClave(&arbol_estructura,&vecBusq[0],sizeof(t_estr),cmp_Estr_NoClave);
            mostrarEstructura(&vecBusq[0]);
            system("pause");
            break;
        }
        case 25:
        {
            system("cls");
            vecBusq[0].dni = 0;
            vecBusq[0].nota = 0;
            printf("El dato mayor no clave es(nota):");
            mostrarMayorNoClave(&arbol_estructura,&vecBusq[0],sizeof(t_estr),cmp_Estr_NoClave);
            mostrarEstructura(&vecBusq[0]);
            system("pause");
            break;
        }
        case 26:
        {
            system("cls");
            printf("Se eliminaron %d hojas\n", eliminarHoja(&arbol_estructura));
            desdeAltura = 0;
            printf("Arbol luego de eliminar las hojas\n\n");
            verArbol(&arbol_estructura,desdeAltura, sizeof(t_estr));
            system("pause");
            break;
        }
        case 27:
        {
            system("cls");
            desdeAltura = 2;
            printf("Podando arbol desde altura\n");
            podarArbolDesdeAlturaR(&arbol_estructura, desdeAltura);
            system("pause");
            break;
        }
        case 28:
        {
            system("cls");
            printf("Podando arbol desde altura inclusive\n");
            printf("Desde que altura quiere podar\n");
            scanf("%d",&desdeAltura);
            podarArbolDesdeAlturaRInc(&arbol_estructura, desdeAltura);
            system("pause");
            break;
        }
        case 29:
        {
            system("cls");
            FILE*pf;
            pf=fopen("ArchivoArbol.txt","wt");
            if(!pf)
                exit(-20);
            grabarArbolEnArchivo(&arbol_estructura,sizeof(t_estr),&arbolTexto,pf,grabarEnArchivoTexto);
            fclose(pf);
            system("pause");
            break;
        }
        case 30:
        {
            system("cls");
            FILE*pf;
            pf=fopen("ArchivoArbol.txt","rt");
            if(!pf)
                exit(-20);
            leerArchivoTexto(pf,sizeof(t_estr),mostrarEstructura);
            system("pause");
            break;
        }
         case 31:
        {
            system("cls");
            printf("Borrando arbol\n");
            printf("La cantidad de nodos borrados son: %d\n",borrarArbol(&arbol_estructura,sizeof(t_estr),cmp_Estr));
            system("pause");
            break;
        }
         case 32:
        {
            system("cls");
            ///printf("¿El Arbol es Completo?\n");
            printf("El arbol %s completo\n", arbolCompleto(&arbol_estructura)? "Es": "No es");
            printf("El arbol %s Balanceado\n", esBalanceado(&arbol_estructura)? "Es": "No es");
            printf("El arbol %s AVL\n", esAvl(&arbol_estructura)? "Es": "No es");
            system("pause");
            break;
        }
        case 33:
        {
            system("cls");
            ///printf("¿El Arbol es Completo?\n");
            printf("Ingrese clave a buscar . Nombre\n");
            scanf("%s", busqueda.nombre);
            puts(busqueda.nombre);
            system("pause");
            if(!buscarClave(&arbol_estructura, &busqueda, sizeof(t_estr),cmp_Estr))
                printf("No se encontro clave\n");
            else
            {
                printf("El nodo que tiene la clave es\n\n\n");
                mostrarEstructura(&busqueda);
            }
            system("pause");
            break;
        }
        case 34:
        {
            system("cls");
            ///printf("¿El Arbol es Completo?\n");
            printf("Ingrese clave a buscar a borrar(Nombre) y mostrar\n\n");
            scanf("%s", busqueda.nombre);
            if(borrarNodoRaiz(&arbol_estructura, sizeof(t_estr),&busqueda, cmp_Estr))
            {
                printf("El nodo borrado es:\t");
                mostrarEstructura(&busqueda);
                printf("\n");
            }
            else
                printf("No se encontro clave \n");
            system("pause");
            break;
        }
        }
        system("cls");
    }
    while(opcion != 0);
}
