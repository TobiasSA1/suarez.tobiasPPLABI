#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
int dia;
int mes;
int anio;
}eFecha;

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
eFecha fechaAuto;
}eAuto;

typedef struct{
int idServicio;
char descripcion[20];
int precio;
}eServicio;

typedef struct{
int idTrabajo;
char patente[6];
int idServicio;
eFecha fecha;
int isEmpty;
}eTrabajo;

/** \brief Inicializa el estado de los elementos del array
 *
 * \param listaAutos[]
 * \param tam int
 * \return int
 *
 */
int inicializarAuto(eAuto listaAutos[], int tam);

/** \brief Muestra un auto por pantalla
 *
 * \param miAuto eAuto
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \return int
 *
 */
int mostrarUnAuto(eAuto miAuto,eMarca listaMarca[],eColor listaColor[]);

/** \brief Muestra todos los autos por pantalla
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \return int
 *
 */
int mostrarTodosLosAutos(eAuto listaAutos[], int tam,eMarca listaMarca[],eColor listaColor[]);

/** \brief Registra los datos de un auto y los retorna
 *
 * \return eAuto
 *
 */
eAuto agregarAuto();

/** \brief Busca los elementos con isEmpty LIBRE y los devuelve
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eAuto listaAutos[],int tam);

/** \brief Llama a la funcion buscar libre para obtener la posicion de un elemento libre y llama a la funcion agregarAuto para llenarlo
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param legajo int
 * \return void
 *
 */
void cargarListaAutos(eAuto listaAutos[], int tam ,int legajo);

/** \brief Sobreescribe el valor de isEmpty de OCUPADO a LIBRE para "borrar" el auto
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param id int
 * \return int
 *
 */
int bajaAuto(eAuto listaAutos[], int tam, int id);

/** \brief Recibe el ID y los compara para devolver el ID
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarAutoPorId(eAuto listaAutos[], int tam,int id);

/** \brief Modifica los datos patente, marca y color
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \return int
 *
 */
int modificarAuto(eAuto listaAutos[], int tam);

/** \brief Ordena los autos por marca y patente
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \return int
 *
 */
int ordenarAutosPorMarcaYPatente(eAuto listaAutos[], int tam);

/** \brief Establece valores para el array MARCA
 *
 * \param listaMarca[] eMarca
 * \param tam int
 * \return void
 *
 */
void hardcodearMarca(eMarca listaMarca[],int tam);

/** \brief Establece valores para el array COLOR
 *
 * \param listaColor[] eColor
 * \param tam int
 * \return void
 *
 */
void hardcodearColor(eColor listaColor[],int tam);
/** \brief Establece valores para el array SERVICIO
 *
 * \param listaServicio[] eServicio
 * \param tam int
 * \return void
 *
 */
void hardcodearServicio(eServicio listaServicio[],int tam);

/** \brief Muestra una Marca
 *
 * \param listaMarca eMarca
 * \return int
 *
 */
int mostrarUnaMarca(eMarca listaMarca);
/** \brief Muestra todas las Marcas
 *
 * \param listaMarca[] eMarca
 * \param tam int
 * \return int
 *
 */
int mostrarTodosLasMarcas(eMarca listaMarca[], int tam);
/** \brief Muestra un color
 *
 * \param listaColor eColor
 * \return int
 *
 */
int mostrarUnColor(eColor listaColor);

/** \brief Muestra todos los colores
 *
 * \param
 * \param
 * \return
 *
 */
int mostrarTodosLosColores(eColor listaColor[], int tam);

/** \brief Muestra un servicio
 *
 * \param listaServicio eServicio
 * \return int
 *
 */
int mostrarUnServicio(eServicio listaServicio);
/** \brief Muestra todos los servicios
 *
 * \param listaServicio[] eServicio
 * \param tam int
 * \return int
 *
 */
int mostrarTodosLosServicios(eServicio listaServicio[], int tam);


/** \brief Inicializa el estado isEmpty a OCUPADO de Trabajos
 *
 * \param listaTrabajos[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int inicializarTrabajos(eTrabajo listaTrabajos[], int tam);
/** \brief Busca en el array de trabajos los elementos LIBRES y los retorna
 *
 * \param listaTrabajos[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int buscarTrabajoLibre(eTrabajo listaTrabajos[],int tam);

/** \brief Llama a la funcion buscar trabajo libre para obtener la posicion del elemento y sobreescribe los datos ahi
 *
 * \param listaTrabajos[] eTrabajo
 * \param tam int
 * \param legajo int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \param listaServicio[] eServicio
 * \param listaAutos[] eAuto
 * \return void
 *
 */
void cargarListaTrabajos(eTrabajo listaTrabajos[], int tam ,int legajo,eMarca listaMarca[],eColor listaColor[],eServicio listaServicio[],eAuto listaAutos[]);
/** \brief Registra los datos del trabajo
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \param listaServicio[] eServicio
 * \return eTrabajo
 *
 */
eTrabajo agregarTrabajo(eAuto listaAutos[],int tam,eMarca listaMarca[],eColor listaColor[],eServicio listaServicio[]);

/** \brief Muestra un trabajo
 *
 * \param miTrabajo eTrabajo
 * \param listaServicio[] eServicio
 * \return int
 *
 */
int mostrarUnTrabajo(eTrabajo miTrabajo,eServicio listaServicio[]);
/** \brief Muestra todos los trabajos
 *
 * \param listaTrabajos[] eTrabajo
 * \param tam int
 * \param listaServicio[] eServicio
 * \return int
 *
 */
int mostrarTodosLosTrabajos(eTrabajo listaTrabajos[], int tam,eServicio listaServicio[]);


/** \brief Muestra los autos segun el color que ingresaste
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param idColor int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \return int
 *
 */
int buscarAutoPorColor(eAuto listaAutos[],int tam,int idColor,eMarca listaMarca[],eColor listaColor[]);

/** \brief Muestra las marcas segun el color que ingresaste
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param idMarca int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \return int
 *
 */
int buscarAutoPorMarca(eAuto listaAutos[],int tam,int idMarca,eMarca listaMarca[],eColor listaColor[]);

/** \brief Muestra los autos segun el color y marca que hayas elegido
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param idMarca int
 * \param idColor int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \return int
 *
 */
int mostrarPorColorYMarca(eAuto listaAutos[],int tam,int idMarca,int idColor,eMarca listaMarca[],eColor listaColor[]);

/** \brief Cuenta la cantidad de autos que tiene cada marca y te retorna la que mas tiene
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param idMarca int
 * \param idColor int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \return int
 *
 */
int contadorMarcas(eAuto listaAutos[],int tam,int idMarca,int idColor,eMarca listaMarca[],eColor listaColor[]);

/** \brief  Muestra los autos separados por sus marcas
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param idMarca int
 * \param idColor int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \return int
 *
 */
int mostrarSeparadoPorMarca(eAuto listaAutos[],int tam,int idMarca,int idColor,eMarca listaMarca[],eColor listaColor[]);

/** \brief Ordena los autos por fecha, del mas viejo primero al mas chico ultimo
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \return int
 *
 */
int ordenarPorFecha(eAuto listaAutos[], int tam,eMarca listaMarca[],eColor listaColor[]);

/** \brief Muestra solamente el primer elemento del array, y lo utilizo para mostrar el auto mas viejo
 *
 * \param listaAutos[] eAuto
 * \param tam int
 * \param listaMarca[] eMarca
 * \param listaColor[] eColor
 * \return int
 *
 */
int mostrarAutoMasViejo(eAuto listaAutos[], int tam,eMarca listaMarca[],eColor listaColor[]);

#endif // FUNCIONES_H_INCLUDED
