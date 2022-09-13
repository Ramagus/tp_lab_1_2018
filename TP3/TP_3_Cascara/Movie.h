#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#define TITLE_LEN 20
#define GENRE_LEN 20
#define DESC_LEN 200
#define LINK_IMG_LEN 100

typedef struct
{
    char titulo[TITLE_LEN];
    char genero[GENRE_LEN];
    int duracion;
    char descripcion[DESC_LEN];
    float puntaje;
    char linkImagen[LINK_IMG_LEN];

} sMovie;


/** \brief Reserva espacio en memoria para una nueva pel�cula
 *
 * \param void
 *
 * \return sMovie* Retorna un puntero a la pel�cula o NULL en caso de error
 *
 */
sMovie* movie_new(void);


/** \brief Reserva espacio en memoria para una nueva pel�cula y setea sus campos
 *         con los valores recibidos como par�metros
 *
 * \param titulo char* Nombre de la pel�cula
 * \param genero char* G�nero de la pel�cula
 * \param duracion int Duraci�n de la pel�cula
 * \param descripcion char* Descripci�n de la pel�cula
 * \param puntaje float Puntaje de la pel�cula
 * \param linkImagen char* Link de imagen de la pel�cula
 *
 * \return sMovie* Retorna un puntero a la pel�cula o NULL en caso de error
 *
 */
sMovie* movie_newParametros(char* titulo, char* genero, int duracion, char* descripcion, float puntaje, char* linkImagen);


/** \brief Reserva espacio en memoria para una nueva pel�cula y setea sus campos como cadena
 *         con los valores recibidos como par�metros
 *
 * \param tituloStr char* Nombre de la pel�cula
 * \param generoStr char* G�nero de la pel�cula
 * \param duracionStr char* Duraci�n de la pel�cula
 * \param descripcionStr char* Descripci�n de la pel�cula
 * \param puntajeStr char* Puntaje de la pel�cula
 * \param linkImagenStr char* Link de imagen de la pel�cula
 *
 * \return sMovie* Retorna un puntero a la pel�cula o NULL en caso de error
 *
 */
sMovie* movie_newParametrosTxt(char* tituloStr, char* generoStr, char* duracionStr, char* descripcionStr, char* puntajeStr, char* linkImagenStr);


/** \brief Libera el espacio ocupado por una pel�cula recibida como par�metro
 *
 * \param this sMovie* Puntero a la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_delete(sMovie* this);


/** \brief Setea el t�tulo de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param titulo char* Nombre de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_setTitulo(sMovie* this, char* titulo);


/** \brief Setea el g�nero de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param genero char* G�nero de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_setGenero(sMovie* this, char* genero);


/** \brief Setea la duraci�n de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param duracion int Duraci�n de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_setDuracion(sMovie* this, int duracion);


/** \brief Setea la duraci�n de una pel�cula recibiendola como cadena
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param duracion char* Duraci�n de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_setDuracionTxt(sMovie* this, char* duracion);


/** \brief Setea la descripci�n de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param descripcion char* Descripci�n de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_setDescripcion(sMovie* this, char* descripcion);


/** \brief Setea el puntaje de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param puntaje float Puntaje de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_setPuntaje(sMovie* this, float puntaje);


/** \brief Setea el puntaje de una pel�cula recibiendolo como cadena
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param puntaje char* Puntaje de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_setPuntajeTxt(sMovie* this, char* puntaje);


/** \brief Setea el link de imagen de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param linkImagen char* Link de imagen de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_setLinkImagen(sMovie* this, char* linkImagen);


/** \brief Obtiene el t�tulo de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param titulo char* Puntero donde se guardar� el nombre de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_getTitulo(sMovie* this, char* titulo);


/** \brief Obtiene el g�nero de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param genero char* Puntero donde se guardar� el gen�ro de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_getGenero(sMovie* this, char* genero);


/** \brief Obtiene la duraci�n de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param duracion int* Puntero donde se guardar� la duraci�n de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_getDuracion(sMovie* this, int* duracion);


/** \brief Obtiene la duraci�n de una pel�cula como cadena
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param duracion char* Puntero donde se guardar� la duraci�n de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_getDuracionTxt(sMovie* this, char* duracion);


/** \brief Obtiene la descripci�n de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param descripcion char* Puntero donde se guardar� la descripci�n de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_getDescripcion(sMovie* this, char* descripcion);


/** \brief Obtiene el puntaje de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param puntaje float* Puntero donde se guardar� el puntaje de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_getPuntaje(sMovie* this, float* puntaje);


/** \brief Obtiene el puntaje de una pel�cula como cadena
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param puntaje char* Puntero donde se guardar� el puntaje de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_getPuntajeTxt(sMovie* this, char* puntaje);


/** \brief Obtiene el link de imagen de una pel�cula
 *
 * \param this sMovie* Puntero a la pel�cula
 * \param linkImagen char* Puntero donde se guardar� el link de imagen de la pel�cula
 *
 * \return int Retorna 0 si est� todo Ok o -1 si hubo un error
 *
 */
int movie_getLinkImagen(sMovie* this, char* linkImagen);


/** \brief Elimina la lista de pel�culas
 *
 * \param lista sMovie** Array de Punteros a Peliculas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int movie_clear(sMovie** lista, int len);


/** \brief Indica que cada posici�n del array est� vac�a, asignando NULL a cada Puntero
 *
 * \param lista sMovie** Array de Punteros a Peliculas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int inicializarPeliculas(sMovie** lista, int len);


/** \brief Encuentra la primera posici�n libre del array
 *
 * \param lista sMovie** Array de Punteros a Peliculas
 * \param len int Cantidad de elementos del array
 * \param indice int* Lugar donde se guardar� el primer �ndice disponible
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int buscarLugarLibre(sMovie** lista, int len, int* indice);


/** \brief Verifica si el array est� vac�o
 *
 * \param lista sMovie** Array de Punteros a Peliculas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int arrayIsEmpty(sMovie** lista, int len);


/** \brief Carga algunas pel�culas para testear
 *
 * \param lista sMovie** Array de Punteros a Pel�culas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int hardCodearPeliculas(sMovie** lista, int len);


/** \brief Lee las pel�culas del archivo binario y las carga al array
 *
 * \param lista sMovie** Array de Punteros a Pel�culas
 * \param len int Cantidad de elementos del array
 * \param ruta[] char Ubicaci�n del archivo
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int leerPeliculas(sMovie** lista, int len, char ruta[]);


/** \brief Guarda al archivo binario las pel�culas del array
 *
 * \param lista sMovie** Array de Punteros a Pel�culas
 * \param len int Cantidad de elementos del array
 * \param ruta[] char Ubicaci�n del archivo
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int guardarPeliculas(sMovie** lista, int len, char ruta[]);


/** \brief Agrega una pel�cula al archivo binario
 *
 * \param lista sMovie** Array de Punteros a Pel�culas
 * \param len int Cantidad de elementos del array
 * \param indice int Posici�n del array a ser cargada
 *
 * \return int (0) - (-1) de acuerdo a si pudo agregar la pel�cula o no
 *
 */
int agregarPelicula(sMovie** lista, int len, int indice);


/** \brief Encuentra una pel�cula por nombre
 *
 * \param lista sMovie** Array de Punteros a Pel�culas
 * \param len int Cantidad de elementos del array
 * \param titulo[] char Nombre de la pel�cula a buscar
 * \param indice int* Lugar donde se guardar� el �ndice de la pel�cula encontrada
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int buscarPeliculaPorTitulo(sMovie** lista, int len, char titulo[], int* indice);


/** \brief Borra una pel�cula del archivo binario
 *
 * \param lista sMovie** Array de Punteros a Pel�culas
 * \param len int Cantidad de elementos del array
 * \param indice int Posici�n del array a ser cargada
 *
 * \return int (0) - (-1) de acuerdo a si pudo eliminar la pel�cula o no
 *
 */
int borrarPelicula(sMovie** lista, int len, int indice);


/** \brief Modifica una pel�cula del archivo binario
 *
 * \param lista sMovie** Array de Punteros a Pel�culas
 * \param len int Cantidad de elementos del array
 * \param indice int Posici�n del array a ser cargada
 *
 * \return int (0) - (-1) de acuerdo a si pudo modificar la pel�cula o no
 *
 */
int modificarPelicula(sMovie** lista, int len, int indice);


/** \brief Muestra los datos de una pel�cula
 *
 * \param unaPelicula sMovie* Pel�cula a ser mostrada
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int mostrarUnaPelicula(sMovie* unaPelicula);


/** \brief Muestra la lista de pel�culas
 *
 * \param lista sMovie** Array de Punteros a Pel�culas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int mostrarListaPeliculas(sMovie** lista, int len);


/** \brief Genera un archivo html a partir de las pel�culas cargadas en el archivo binario
 *
 * \param lista sMovie** Lista de pel�culas a ser agregadas en el archivo
 * \param len int Cantidad de elementos del array
 * \param nombre[] char Nombre para el archivo
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int generarPagina(sMovie** lista, int len, char nombre[]);


/** \brief Muestra el menu de Pel�culas
 *
 * \param opcion int* Variable donde se guarda la opcion seleccionada por el usuario
 *
 * \return int (-1) si hubo un error - (0) si est� todo ok
 *
 */
int mostrarMenuPrincipal(int* opcion);


#endif // MOVIE_H_INCLUDED
