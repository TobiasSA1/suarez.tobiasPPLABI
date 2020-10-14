#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define LIBRE 1
#define OCUPADO 0
#include "funciones.h"

int inicializarAuto(eAuto listaAutos[], int tam)
{
    int error = 1;
    int i;
    if(listaAutos!=NULL && tam >0)
    {
        for(i=0; i<tam; i++)
        {
        listaAutos[i].isEmpty = LIBRE;

        }
        error = 0;
    }
    return error;

}


int mostrarUnAuto(eAuto miAuto)
{
    {
    printf("%d\t %s\t %d\t %d\t",miAuto.id,miAuto.patente,miAuto.idMarca,miAuto.idColor);
    }
 return 0;

}

int mostrarTodosLosAutos(eAuto listaAutos[], int tam)
{
    int i;
    int error = 1;
    if(listaAutos!=NULL&&tam >0)
    {
        printf("\nID:\t PATENTE:\t ID MARCA:\t ID COLOR:\t\n");
        for(i=0; i< tam; i++)
        {
            if(listaAutos[i].isEmpty==OCUPADO)
            {
           mostrarUnAuto(listaAutos[i]);
           error = 0;
            }
        }
    }
    return error;
}

eAuto agregarAuto()

{
    eAuto miAuto;

        printf("Ingrese la patente del auto: \n");
        fflush(stdin);
        fgets(miAuto.patente,6, stdin);

        printf("Ingrese la marca \n");
        printf(" 1: RENAULT\n 2: FIAT\n 3: FORD\n 4: CHEVROLET\n 5: PEUGEOT\n");
        scanf("%d", &miAuto.idMarca);

        printf("Ingrese el color \n");
        printf(" 1: NEGRO\n 2: BLANCO\n 3: GRIS\n 4: ROJO\n 5: AZUL\n");
        scanf("%d", &miAuto.idColor);

        miAuto.isEmpty = OCUPADO;

    return miAuto;

}

int buscarLibre(eAuto listaAutos[],int tam)
{
    int i;
    int indice=-1;
    for(i=0; i<tam; i++)
    {
        if(listaAutos[i].isEmpty==LIBRE)
        {
            indice = i;
            break;
        }
   }
   return indice;
}

void cargarListaAutos(eAuto listaAutos[], int tam ,int legajo)
{
    int indice;
    indice = buscarLibre(listaAutos, tam);
    if(indice != -1)
    {
        listaAutos[indice] = agregarAuto();
        listaAutos[indice].id = legajo;
    }
    else
    {
        printf("No hay lugar.\n");
    }

}

int bajaAuto(eAuto listaAutos[], int tam, int id)
{

    int indice;
    int i;

    indice = buscarAutoPorId(listaAutos,tam,id);

    for(i=0; i<tam;i++)
    {
        if(indice == listaAutos[i].id)
        {
            listaAutos[i].isEmpty=LIBRE;
            break;
        }


    }

  return 0;
}

int buscarAutoPorId(eAuto listaAutos[], int tam,int id)
{
    int i;
    int indice;
    for(i=0; i<tam; i++)
    {
        if (listaAutos[i].id == id && listaAutos[i].isEmpty == OCUPADO)
            {
                indice = listaAutos[i].id;break;
            }
    }

 return indice;
}

int modificarAuto(eAuto listaAutos[], int tam)
{
    char auxChar;
    int i;
    int error = 1;
    char opcion;

    printf("Ingrese la patente a modificar: \n");
    scanf("%s", &auxChar);

    for(i=0; i<tam;i++)
    {
        if(auxChar == listaAutos[i].patente)
        {
        printf("\nMENU DE OPCIONES \n");
        printf("A. Nueva patente\nB. Nueva marca\nC. Nuevo color\nS. Salir\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

         switch(opcion)
        {
            case 'a':
            printf("Ingrese la nueva patente del auto: \n");
            fflush(stdin);
            fgets(listaAutos[i].patente,6,stdin);
            error = 0;
            break;

            case 'b':
            printf("Ingrese la nueva marca \n");
            printf(" 1: RENAULT\n 2: FIAT\n 3: FORD\n 4: CHEVROLET\n 5: PEUGEOT\n");
            scanf("%d", &listaAutos[i].idMarca);
            error = 0;
            break;

            case 'c':
            printf("Ingrese el color \n");
            printf(" 1: NEGRO\n 2: BLANCO\n 3: GRIS\n 4: ROJO\n 5: AZUL\n");
            scanf("%d", &listaAutos[i].idColor);
            error = 0;
            break;

            case 's':
            printf("Salio del modificar autos!\n"); break;

            default:printf("\nLa opcion ingresada es incorrecta o esta en MAYUSCULA.\n");

        }
    }
    }
    return error;

}

void hardcodearMarca(eMarca listaMarca[],int tam)
{
    int i;
    int idMarca[5] = {1000,1001,1002,1004,1005};
    char descripcion[5][20] = {"RENAULT","FIAT","FORD","CHEVROLET","PEUGEOT"};

      for(i=0; i<tam; i++)
  {
      listaMarca[i].idMarca = idMarca[i];
      strcpy(listaMarca[i].descripcion, descripcion[i]);
  }

}

void hardcodearColor(eColor listaColor[],int tam)
{
    int i;
    int idColor[5] = {1,2,3,4,5};
    char nombreColor[5][20] = {"NEGRO","BLANCO","GRIS","ROJO","AZUL"};

    for(i=0; i<tam; i++)
    {
      listaColor[i].idColor = idColor[i];
      strcpy(listaColor[i].nombreColor, nombreColor[i]);
    }

}

void hardcodearServicio(eServicio listaServicio[],int tam)
{
    int i;

    int idServicio[4] = {1,2,3,4};
    char descripcion[4][20]={"Lavado","Pulido","Encerado","Completo"};
    int precio[4] = {250,300,400,600};

    for(i=0; i<tam; i++)
    {
      listaServicio[i].idServicio = idServicio[i];
      strcpy(listaServicio[i].descripcion, descripcion[i]);
      listaServicio[i].precio = precio[i];
    }

}

int ordenarAutosPorMarcaYPatente(eAuto listaAutos[], int tam)
{
    int i;
    int j;
    int error = 2;
    eAuto auxAuto;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(listaAutos[i].idMarca>listaAutos[j].idMarca)
            {
                auxAuto = listaAutos[i];
                listaAutos[i] = listaAutos[j];
                listaAutos[j] = auxAuto;
                error = 1;
            }
            else
            {
               if(listaAutos[i].idMarca==listaAutos[j].idMarca)
               {
                   if(strcmp(listaAutos[i].patente,listaAutos[j].patente)>0)
                   {
                        auxAuto = listaAutos[i];
                        listaAutos[i] = listaAutos[j];
                        listaAutos[j] = auxAuto;
                        error = 0;
                   }
               }
            }
        }

    }
  return error;
}

int mostrarUnaMarca(eMarca listaMarca)
{
    {
    printf("%d\t %s\t ",listaMarca.idMarca,listaMarca.descripcion);
    }
 return 0;

}

int mostrarTodosLasMarcas(eMarca listaMarca[], int tam)
{
    int i;
    int error = 1;
    if(listaMarca!=NULL&&tam >0)
    {
        printf("ID MARCA:\t DESCRIPCION:\t\n");
        for(i=0; i< tam; i++)
        {
           mostrarUnaMarca(listaMarca[i]);
           error = 0;
            }
        }

    return error;
}

int mostrarUnColor(eColor listaColor)
{
    {
    printf("%d\t %s\t ",listaColor.idColor,listaColor.nombreColor);
    }
 return 0;

}

int mostrarTodosLosColores(eColor listaColor[], int tam)
{
    int i;
    int error = 1;
    if(listaColor!=NULL&&tam >0)
    {
        printf("ID COLOR:\t NOMBRE COLOR:\t\n");
        for(i=0; i< tam; i++)
        {
           mostrarUnColor(listaColor[i]);
           error = 0;
            }
        }

    return error;
}

int mostrarUnServicio(eServicio listaServicio)
{
    {
    printf("%d\t %s\t %d\t",listaServicio.idServicio,listaServicio.descripcion,listaServicio.precio);
    }
 return 0;

}

int mostrarTodosLosServicios(eServicio listaServicio[], int tam)
{
    int i;
    int error = 1;
    if(listaServicio!=NULL&&tam >0)
    {
        printf("ID SERVICIO:\t NOMBRE SERVICIO:\t PRECIO:\t\n");
        for(i=0; i< tam; i++)
        {
           mostrarUnServicio(listaServicio[i]);
           error = 0;
            }
        }

    return error;
}

