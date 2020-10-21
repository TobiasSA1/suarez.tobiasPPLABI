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


int mostrarUnAuto(eAuto miAuto,eMarca listaMarca[],eColor listaColor[])
{
    int i;
    int j;
    for(i=0; i< 5; i++)
    {
    if(miAuto.idMarca==listaMarca[i].idMarca)
        {
    for(j=0; j< 5; j++)
            {
    if(miAuto.idColor==listaColor[j].idColor)
                {
    printf("%d%10d/%d/%d%15s%15s%15s\n",miAuto.id,miAuto.fechaAuto.dia,miAuto.fechaAuto.mes,miAuto.fechaAuto.anio,listaMarca[i].descripcion,listaColor[j].nombreColor,miAuto.patente);break;
                }
            }
        }

    }
 return 0;

}

int mostrarTodosLosAutos(eAuto listaAutos[], int tam,eMarca listaMarca[],eColor listaColor[])
{
    int i;
    int error = 1;
    if(listaAutos!=NULL&&tam >0)
    {
        printf("\nID:\t  FECHA:\t  MARCA:\t  COLOR:\t PATENTE:\t\n");
        for(i=0; i< tam; i++)
        {
            if(listaAutos[i].isEmpty==OCUPADO)
            {
           mostrarUnAuto(listaAutos[i],listaMarca,listaColor);
           error = 0;
            }
        }
    }
    return error;
}

eAuto agregarAuto()

{
    eAuto miAuto;

        printf("\nIngrese la patente del auto: \n");
        fflush(stdin);
        fgets(miAuto.patente,6, stdin);

        printf("Ingrese la marca \n");
        printf(" 1000: RENAULT\n 1001: FIAT\n 1002: FORD\n 1003: CHEVROLET\n 1004: PEUGEOT\n");
        scanf("%d", &miAuto.idMarca);

        printf("Ingrese el color \n");
        printf(" 1: NEGRO\n 2: BLANCO\n 3: GRIS\n 4: ROJO\n 5: AZUL\n");
        scanf("%d", &miAuto.idColor);

        printf("Ingrese el dia: \n");
        scanf("%d",&miAuto.fechaAuto.dia);

        printf("Ingrese la mes: \n");
        scanf("%d",&miAuto.fechaAuto.mes);

        printf("Ingrese la anio: \n");
        scanf("%d",&miAuto.fechaAuto.anio);

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
        printf("A. Nueva patente\nB. Nueva marca\nC. Nuevo color\nS. Salir\n\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

         switch(opcion)
        {
            case 'a':
            printf("\nIngrese la nueva patente del auto: \n");
            fflush(stdin);
            fgets(listaAutos[i].patente,6,stdin);
            error = 0;
            break;

            case 'b':
            printf("Ingrese la nueva marca \n");
            printf(" 1000: RENAULT\n 1001: FIAT\n 1002: FORD\n 1003: CHEVROLET\n 1004: PEUGEOT\n");
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
    int idMarca[5] = {1000,1001,1002,1003,1004};
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
    printf("%5d%24s\n",listaMarca.idMarca,listaMarca.descripcion);
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
    printf("%5d%25s\n",listaColor.idColor,listaColor.nombreColor);
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
    printf("%8d%25s%15d\n",listaServicio.idServicio,listaServicio.descripcion,listaServicio.precio);
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

eTrabajo agregarTrabajo(eAuto listaAutos[],int tam,eMarca listaMarca[],eColor listaColor[],eServicio listaServicio[])

{
    eTrabajo miTrabajo;

        mostrarTodosLosAutos(listaAutos,tam,listaMarca,listaColor);
        printf("\nIngrese la PATENTE del auto a registrar el trabajo: \n");
        fflush(stdin);
        fgets(miTrabajo.patente,6, stdin);

        mostrarTodosLosServicios(listaServicio,4);
        printf("\nIngrese el ID del SERVICIO:\n");
        scanf("%d", &miTrabajo.idServicio);

        printf("Ingrese el dia:\n");
        scanf("%d",&miTrabajo.fecha.dia);

        printf("Ingrese el mes:\n");
        scanf("%d",&miTrabajo.fecha.mes);

        printf("Ingrese el anio:\n");
        scanf("%d",&miTrabajo.fecha.anio);


        miTrabajo.isEmpty = OCUPADO;

    return miTrabajo;

}

void cargarListaTrabajos(eTrabajo listaTrabajos[], int tam ,int legajo,eMarca listaMarca[],eColor listaColor[],eServicio listaServicio[],eAuto listaAutos[])
{
    int indice;
    indice = buscarTrabajoLibre(listaTrabajos, tam);
    if(indice != -1)
    {
        listaTrabajos[indice] = agregarTrabajo(listaAutos,tam,listaMarca,listaColor,listaServicio);
        listaTrabajos[indice].idTrabajo = legajo;
    }
    else
    {
        printf("No hay lugar.\n");
    }

}

int buscarTrabajoLibre(eTrabajo listaTrabajos[],int tam)
{
    int i;
    int indice=-1;
    for(i=0; i<tam; i++)
    {
        if(listaTrabajos[i].isEmpty==LIBRE)
        {
            indice = i;
            break;
        }
   }
   return indice;
}

int inicializarTrabajos(eTrabajo listaTrabajos[], int tam)
{
    int error = 1;
    int i;
    if(listaTrabajos!=NULL && tam >0)
    {
        for(i=0; i<tam; i++)
        {
        listaTrabajos[i].isEmpty = LIBRE;

        }
        error = 0;
    }
    return error;

}


int mostrarUnTrabajo(eTrabajo miTrabajo,eServicio listaServicio[])
{
    int i;
    for(i=0; i< 5; i++)
    {
    if(miTrabajo.idServicio==listaServicio[i].idServicio)
    {
    printf("%d%10d/%d/%d%15s%15s\n",
           miTrabajo.idTrabajo,miTrabajo.fecha.dia,miTrabajo.fecha.mes,miTrabajo.fecha.anio,listaServicio[i].descripcion,miTrabajo.patente);break;
    }

    }
 return 0;

}

int mostrarTodosLosTrabajos(eTrabajo listaTrabajos[], int tam,eServicio listaServicio[])
{
    int i;
    int error = 1;
    if(listaTrabajos!=NULL&&tam >0)
    {
        printf("\nID:\t FECHA:\t          SERVICIO:\t  PATENTE:\t\n");
        for(i=0; i< tam; i++)
        {
            if(listaTrabajos[i].isEmpty==OCUPADO)
            {
           mostrarUnTrabajo(listaTrabajos[i],listaServicio);
           error = 0;
            }
        }
    }
    return error;
}

int buscarAutoPorColor(eAuto listaAutos[],int tam,int idColor,eMarca listaMarca[],eColor listaColor[])
{
    int i;
    int indice=-1;
    printf("\nID:\t FECHA:\t MARCA:\t COLOR:\t PATENTE:\t\n");
    for(i=0; i<tam; i++)
    {
        if(listaAutos[i].idColor==idColor)
        {
            mostrarUnAuto(listaAutos[i],listaMarca,listaColor);
            break;
        }
   }
   return indice;
}

int buscarAutoPorMarca(eAuto listaAutos[],int tam,int idMarca,eMarca listaMarca[],eColor listaColor[])
{
    int i;
    int indice=-1;
    printf("\nID:\t FECHA:\t MARCA:\t COLOR:\t PATENTE:\t\n");
    for(i=0; i<tam; i++)
    {
        if(listaAutos[i].idMarca==idMarca)
        {
            mostrarUnAuto(listaAutos[i],listaMarca,listaColor);
            break;
        }
   }
   return indice;
}


int ordenarAutosPorMarca(eAuto listaAutos[], int tam)
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
        }

    }
  return error;
}


int mostrarPorColorYMarca(eAuto listaAutos[],int tam,int idMarca,int idColor,eMarca listaMarca[],eColor listaColor[])
{
    int i;
    int indice=-1;
    int contador=0;
    for(i=0; i<tam; i++)
    {
        if(listaAutos[i].idMarca==idMarca&&listaAutos[i].idColor==idColor)
        {
            contador++;

        }
   }
    printf("La cantidad de autos con ese color y marca:%d ",contador);
   return indice;
}

int contadorMarcas(eAuto listaAutos[],int tam,int idMarca,int idColor,eMarca listaMarca[],eColor listaColor[])
{
    int i;
    int indice=-1;
    int contadorMarca1=0;
    int contadorMarca2=0;
    int contadorMarca3=0;
    int contadorMarca4=0;
    int contadorMarca5=0;

    for(i=0; i<tam; i++)
    {
        if(listaAutos[i].idMarca==1000)
        {

            contadorMarca1++;
        }
        if(listaAutos[i].idMarca==1001)
        {
            contadorMarca2++;

        }
        if(listaAutos[i].idMarca==1002)
        {
            contadorMarca3++;

        }
        if(listaAutos[i].idMarca==1003)
        {
            contadorMarca4++;

        }
        if(listaAutos[i].idMarca==1004)
        {
            contadorMarca5++;

        }
   }
    if(contadorMarca1>contadorMarca2&&contadorMarca1>contadorMarca3&&contadorMarca1>contadorMarca4&&contadorMarca1>contadorMarca5)
    {
     printf("\nLa cantidad de autos RENAULT: %d\n",contadorMarca1);
    }

    if(contadorMarca2>contadorMarca1&&contadorMarca2>contadorMarca3&&contadorMarca2>contadorMarca4&&contadorMarca2>contadorMarca5)
    {
      printf("La cantidad de autos FIAT: %d\n",contadorMarca2);
    }

    if(contadorMarca3>contadorMarca1&&contadorMarca3>contadorMarca2&&contadorMarca3>contadorMarca4&&contadorMarca3>contadorMarca5)
    {
    printf("La cantidad de autos FORD: %d\n",contadorMarca3);
    }
    if(contadorMarca4>contadorMarca1&&contadorMarca4>contadorMarca2&&contadorMarca4>contadorMarca3&&contadorMarca4>contadorMarca5)
    {
    printf("La cantidad de autos CHEVROLET: %d\n",contadorMarca4);
    }
    if(contadorMarca5>contadorMarca1&&contadorMarca5>contadorMarca2&&contadorMarca5>contadorMarca3&&contadorMarca5>contadorMarca4)
    {
    printf("La cantidad de autos PEUGEOT: %d\n",contadorMarca5);
    }
   return indice;
}


int mostrarSeparadoPorMarca(eAuto listaAutos[],int tam,int idMarca,int idColor,eMarca listaMarca[],eColor listaColor[])
{
    int i;
    int indice=-1;
    for(i=0; i<tam; i++)
    {
        if(listaAutos[i].idMarca==1000)
        {
        printf("\n***RENAULT***\n");
        printf("\nID:\t FECHA:\t MARCA:\t COLOR:\t PATENTE:\t\n");
        mostrarUnAuto(listaAutos[i],listaMarca,listaColor);
        }


        if(listaAutos[i].idMarca==1001)
        {
        printf("\n***FIAT***\n");
        printf("\nID:\t FECHA:\t MARCA:\t COLOR:\t PATENTE:\t\n");
        mostrarUnAuto(listaAutos[i],listaMarca,listaColor);
        }


        if(listaAutos[i].idMarca==1002)
        {
        printf("\n***FORD***\n");
        printf("\nID:\t FECHA:\t MARCA:\t COLOR:\t PATENTE:\t\n");
        mostrarUnAuto(listaAutos[i],listaMarca,listaColor);
        }


        if(listaAutos[i].idMarca==1003)
        {
        printf("\n***CHEVROLET***\n");
        printf("\nID:\t FECHA:\t MARCA:\t COLOR:\t PATENTE:\t\n");
        mostrarUnAuto(listaAutos[i],listaMarca,listaColor);
        }


        if(listaAutos[i].idMarca==1004)
        {
        printf("\n***PEUGEOT***\n");
        printf("\nID:\t FECHA:\t MARCA:\t COLOR:\t PATENTE:\t\n");
        mostrarUnAuto(listaAutos[i],listaMarca,listaColor);
        }
   }

   return indice;
}

int ordenarPorFecha(eAuto listaAutos[], int tam,eMarca listaMarca[],eColor listaColor[])
{
    int i;
    int j;
    int error = 2;
    eAuto auxAuto;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(listaAutos[i].fechaAuto.anio>listaAutos[j].fechaAuto.anio)
                {
                auxAuto = listaAutos[i];
                listaAutos[i] = listaAutos[j];
                listaAutos[j] = auxAuto;
                error = 1;
                }
            else
            {
               if(listaAutos[i].fechaAuto.anio==listaAutos[j].fechaAuto.anio)
               {
                   if(listaAutos[i].fechaAuto.mes>listaAutos[j].fechaAuto.mes)
                   {
                        auxAuto = listaAutos[i];
                        listaAutos[i] = listaAutos[j];
                        listaAutos[j] = auxAuto;
                        error = 0;
                   }
                    else
                    {
                        if(listaAutos[i].fechaAuto.dia==listaAutos[j].fechaAuto.dia)
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

    }
    printf("\n***EL AUTO MAS VIEJO***\n");
  return error;
}

int mostrarAutoMasViejo(eAuto listaAutos[], int tam,eMarca listaMarca[],eColor listaColor[])
{
    int i;
    int error = 1;
    if(listaAutos!=NULL&&tam >0)
    {
        printf("\nID:\t  FECHA:\t  MARCA:\t  COLOR:\t PATENTE:\t\n");
        for(i=0; i< tam; i++)
        {
            if(listaAutos[i].isEmpty==OCUPADO)
            {
           mostrarUnAuto(listaAutos[i],listaMarca,listaColor);break;
           error = 0;
            }
        }
    }
    return error;
}

