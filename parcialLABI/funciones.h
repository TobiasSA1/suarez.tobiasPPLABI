#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
int idMarca;
char descripcion[20];
}eMarca;

typedef struct{
int idColor;
char nombreColor[20];
}eColor;

typedef struct{
int id;
char patente[6];
int idMarca;
int idColor;
int isEmpty;
}eAuto;

typedef struct{
int idServicio;
char descripcion[20];
int precio;
}eServicio;

typedef struct{
int idTrabajo;
int patente;

}eTrabajo;

typedef struct{
int dia;
int mes;
int anio;
}eFecha;

int inicializarAuto(eAuto listaAutos[], int tam);
int mostrarUnAuto(eAuto miAuto);
int mostrarTodosLosAutos(eAuto listaAutos[], int tam);
eAuto agregarAuto();
int buscarLibre(eAuto listaAutos[],int tam);
void cargarListaAutos(eAuto listaAutos[], int tam ,int legajo);
int bajaAuto(eAuto listaAutos[], int tam, int id);
int buscarAutoPorId(eAuto listaAutos[], int tam,int id);
int modificarAuto(eAuto listaAutos[], int tam);
int ordenarAutosPorMarcaYPatente(eAuto listaAutos[], int tam);

void hardcodearMarca(eMarca listaMarca[],int tam);
void hardcodearColor(eColor listaColor[],int tam);
void hardcodearServicio(eServicio listaServicio[],int tam);

int mostrarUnaMarca(eMarca listaMarca);
int mostrarTodosLasMarcas(eMarca listaMarca[], int tam);
int mostrarUnColor(eColor listaColor);
int mostrarTodosLosColores(eColor listaColor[], int tam);
int mostrarUnServicio(eServicio listaServicio);
int mostrarTodosLosServicios(eServicio listaServicio[], int tam);



#endif // FUNCIONES_H_INCLUDED
