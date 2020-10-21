#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define LIBRE 1
#define TAMT 30
#define OCUPADO 0
#include "funciones.h"
int main()
{
    eAuto listaAutos[TAM];
    eMarca listaMarca[5];
    eColor listaColor[5];
    eServicio listaServicio[4];
    eTrabajo listaTrabajos[30];

    inicializarAuto(listaAutos,TAM);
    inicializarTrabajos(listaTrabajos,TAMT);

    hardcodearColor(listaColor,5);
    hardcodearMarca(listaMarca,5);
    hardcodearServicio(listaServicio,4);



    char opcion;
    char opcion2;
    int id;
    int barrera=-1;
    int barrera2=-1;
    int legajo = 0;
    int legajoTrabajo = 0;

    int idColor=0;
    int idMarca=0;

    printf("******************");
    do
    {
        printf("\nMENU DE OPCIONES: \n\n");
        printf(" a. ALTA AUTO\n b. MODIFICAR AUTO \n c. BAJA AUTO\n d. LISTAR AUTOS\n e. LISTAR MARCAS\n f. LISTAR COLORES\n g. LISTAR SERVICIOS\n h. ALTA TRABAJO\n i. LISTAR TRABAJOS\n j. INFORMES\n s. SALIR\n\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {
            case 'a':

                legajo++;
                barrera = 1;
                cargarListaAutos(listaAutos,TAM,legajo);

                break;


            case 'b':
                if(barrera==1)
                {
                modificarAuto(listaAutos,TAM);
                }
                 else
                {
                    printf("\nDebe realizar primero la alta de autos.\n");
                }


                 break;

            case 'c':
                if(barrera==1)
                {
                    printf("\nIngrese el id a eliminar:\n ");
                    scanf("%d", &id);
                    bajaAuto(listaAutos,TAM,id);

                }
                 else
                {
                    printf("\nDebe realizar primero la alta de autos.\n");
                }


                 break;

            case 'd':
                if(barrera==1)
                {
                    int buscarLista;
                    buscarLista=buscarLibre(listaAutos,TAM);
                    if(buscarLista==0)
                        {
                    printf("\n**No hay ningun auto para mostrar.**\n");
                        }
                    else
                        {
                ordenarAutosPorMarcaYPatente(listaAutos,TAM);
                mostrarTodosLosAutos(listaAutos,TAM,listaMarca,listaColor);
                        }

                }
                 else
                {
                    printf("\nDebe realizar primero la alta de autos.\n");
                }


                 break;

            case 'e': mostrarTodosLasMarcas(listaMarca,5); break;

            case 'f': mostrarTodosLosColores(listaColor,5); break;

            case 'g': mostrarTodosLosServicios(listaServicio,4); break;

            case 'h':
                if(barrera==1)
                {
                 barrera2=1;
                 legajoTrabajo++;
                 cargarListaTrabajos(listaTrabajos,TAMT,legajoTrabajo,listaMarca,listaColor,listaServicio,listaAutos);break;
                }
                  else
                {
                    printf("\nDebe realizar primero la alta de autos.\n");
                }


            case 'i':
                if(barrera==1)
                {
                    if(barrera2==1)
                        {
                mostrarTodosLosTrabajos(listaTrabajos,TAMT,listaServicio);break;
                        }
                    else
                        {
                        printf("\nDebe realizar primero la alta de trabajos.\n");
                        }
                }

                else
                {
                    printf("\nDebe realizar primero la alta de autos.\n");
                }

            case 'j':
                    if(barrera==1)
                {
                    printf("\nSUBMENU INFORMES: \n\n");
                    printf(" a. MOSTRAR AUTOS POR COLOR\n b. MOSTRAR AUTOS POR MARCA\n c. MOSTRAR AUTO MAS VIEJO\n d. MOSTRAR AUTOS ORDENADOS POR MARCA\n e. MOSTRAR POR COLOR Y MARCA\n f. MOSTRAR CANTIDAD DE AUTOS POR MARCA\n s. SALIR\n\nElija una opcion: ");
                    fflush(stdin);
                    scanf("%c", &opcion2);
                        switch(opcion2)
                                {
                        case 'a':
                        mostrarTodosLosColores(listaColor,5);
                        printf("\nIngrese el color a buscar.\n");
                        scanf("%d", &idColor);
                        buscarAutoPorColor(listaAutos,TAM,idColor,listaMarca,listaColor);break;

                        case 'b':
                        mostrarTodosLasMarcas(listaMarca,5);
                        printf("\nIngrese el ID de la marca a buscar.\n");
                        scanf("%d", &idMarca);
                        buscarAutoPorMarca(listaAutos,TAM,idMarca,listaMarca,listaColor);break;

                        case 'c':
                        ordenarPorFecha(listaAutos,TAM,listaMarca,listaColor);
                        mostrarAutoMasViejo(listaAutos,TAM,listaMarca,listaColor);break;

                        case 'd':
                        mostrarSeparadoPorMarca(listaAutos,TAM,idMarca,idColor,listaMarca,listaColor);break;

                        case 'e':
                        mostrarTodosLosColores(listaColor,5);
                        printf("\nIngrese el color a contar.\n");
                        scanf("%d", &idColor);
                        mostrarTodosLasMarcas(listaMarca,5);
                        printf("\nIngrese el ID de la marca a contar.\n");
                        scanf("%d", &idMarca);
                        mostrarPorColorYMarca(listaAutos,TAM,idMarca,idColor,listaMarca,listaColor);break;

                        case 'f':
                        contadorMarcas(listaAutos,TAM,idMarca,idColor,listaMarca,listaColor);break;

                        case 's':break;
                                }
                }
                 else
                {
                    printf("\nDebe realizar primero la alta de autos.\n");
                }



            case 's': break;


        }

    }while(opcion!='s');
    return 0;
}
