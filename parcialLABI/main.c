#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define LIBRE 1
#define OCUPADO 0
#include "funciones.h"
int main()
{
    eAuto listaAutos[TAM];
    eMarca listaMarca[5];
    eColor listaColor[5];
    eServicio listaServicio[4];

    inicializarAuto(listaAutos,TAM);

    hardcodearColor(listaColor,5);
    hardcodearMarca(listaMarca,5);
    hardcodearServicio(listaServicio,4);



    char opcion;
    int id;
    int barrera=-1;
    int legajo = 0;
    printf("******************");
    do
    {
        printf("\nMENU DE OPCIONES: \n");
        printf(" A. ALTA AUTO\n B. MODIFICAR AUTO \n C. BAJA AUTO\n D. LISTAR AUTOS\n E. LISTAR MARCAS\n F. LISTAR COLORES\n G. LISTAR SERVICIOS\n H. ALTA TRABAJO\n I. LISTAR TRABAJOS\n\nElija una opcion: ");
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
                    printf("Debe realizar primero la alta de autos.");
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
                    printf("Debe realizar primero la alta de autos.");
                }


                 break;

            case 'd':
                if(barrera==1)
                {
                ordenarAutosPorMarcaYPatente(listaAutos,TAM);
                mostrarTodosLosAutos(listaAutos,TAM);
                }
                 else
                {
                    printf("Debe realizar primero la alta de autos.");
                }


                 break;

            case 'e': mostrarTodosLasMarcas(listaMarca,5); break;

            case 'f': mostrarTodosLosColores(listaColor,5); break;

            case 'g': mostrarTodosLosServicios(listaServicio,4); break;

            /*case 'h': break;

            case 'i': break;*/

        }

    }while(opcion!='s');
    return 0;
}
