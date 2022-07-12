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


/** \brief Reserva espacio en memoria para una nueva película
 *
 * \param void
 *
 * \return sMovie* Retorna un puntero a la película o NULL en caso de error
 *
 */
sMovie* movie_new(void);


/** \brief Reserva espacio en memoria para una nueva película y setea sus campos
 *         con los valores recibidos como parámetros
 *
 * \param titulo char* Nombre de la película
 * \param genero char* Género de la película
 * \param duracion int Duración de la película
 * \param descripcion char* Descripción de la película
 * \param puntaje float Puntaje de la película
 * \param linkImagen char* Link de imagen de la película
 *
 * \return sMovie* Retorna un puntero a la película o NULL en caso de error
 *
 */
sMovie* movie_newParametros(char* titulo, char* genero, int duracion, char* descripcion, float puntaje, char* linkImagen);


/** \brief Reserva espacio en memoria para una nueva película y setea sus campos como cadena
 *         con los valores recibidos como parámetros
 *
 * \param tituloStr char* Nombre de la película
 * \param generoStr char* Género de la película
 * \param duracionStr char* Duración de la película
 * \param descripcionStr char* Descripción de la película
 * \param puntajeStr char* Puntaje de la película
 * \param linkImagenStr char* Link de imagen de la película
 *
 * \return sMovie* Retorna un puntero a la película o NULL en caso de error
 *
 */
sMovie* movie_newParametrosTxt(char* tituloStr, char* generoStr, char* duracionStr, char* descripcionStr, char* puntajeStr, char* linkImagenStr);


/** \brief Libera el espacio ocupado por una película recibida como parámetro
 *
 * \param this sMovie* Puntero a la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_delete(sMovie* this);


/** \brief Setea el título de una película
 *
 * \param this sMovie* Puntero a la película
 * \param titulo char* Nombre de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_setTitulo(sMovie* this, char* titulo);


/** \brief Setea el género de una película
 *
 * \param this sMovie* Puntero a la película
 * \param genero char* Género de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_setGenero(sMovie* this, char* genero);


/** \brief Setea la duración de una película
 *
 * \param this sMovie* Puntero a la película
 * \param duracion int Duración de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_setDuracion(sMovie* this, int duracion);


/** \brief Setea la duración de una película recibiendola como cadena
 *
 * \param this sMovie* Puntero a la película
 * \param duracion char* Duración de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_setDuracionTxt(sMovie* this, char* duracion);


/** \brief Setea la descripción de una película
 *
 * \param this sMovie* Puntero a la película
 * \param descripcion char* Descripción de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_setDescripcion(sMovie* this, char* descripcion);


/** \brief Setea el puntaje de una película
 *
 * \param this sMovie* Puntero a la película
 * \param puntaje float Puntaje de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_setPuntaje(sMovie* this, float puntaje);


/** \brief Setea el puntaje de una película recibiendolo como cadena
 *
 * \param this sMovie* Puntero a la película
 * \param puntaje char* Puntaje de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_setPuntajeTxt(sMovie* this, char* puntaje);


/** \brief Setea el link de imagen de una película
 *
 * \param this sMovie* Puntero a la película
 * \param linkImagen char* Link de imagen de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_setLinkImagen(sMovie* this, char* linkImagen);


/** \brief Obtiene el título de una película
 *
 * \param this sMovie* Puntero a la película
 * \param titulo char* Puntero donde se guardará el nombre de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_getTitulo(sMovie* this, char* titulo);


/** \brief Obtiene el género de una película
 *
 * \param this sMovie* Puntero a la película
 * \param genero char* Puntero donde se guardará el genéro de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_getGenero(sMovie* this, char* genero);


/** \brief Obtiene la duración de una película
 *
 * \param this sMovie* Puntero a la película
 * \param duracion int* Puntero donde se guardará la duración de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_getDuracion(sMovie* this, int* duracion);


/** \brief Obtiene la duración de una película como cadena
 *
 * \param this sMovie* Puntero a la película
 * \param duracion char* Puntero donde se guardará la duración de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_getDuracionTxt(sMovie* this, char* duracion);


/** \brief Obtiene la descripción de una película
 *
 * \param this sMovie* Puntero a la película
 * \param descripcion char* Puntero donde se guardará la descripción de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_getDescripcion(sMovie* this, char* descripcion);


/** \brief Obtiene el puntaje de una película
 *
 * \param this sMovie* Puntero a la película
 * \param puntaje float* Puntero donde se guardará el puntaje de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_getPuntaje(sMovie* this, float* puntaje);


/** \brief Obtiene el puntaje de una película como cadena
 *
 * \param this sMovie* Puntero a la película
 * \param puntaje char* Puntero donde se guardará el puntaje de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_getPuntajeTxt(sMovie* this, char* puntaje);


/** \brief Obtiene el link de imagen de una película
 *
 * \param this sMovie* Puntero a la película
 * \param linkImagen char* Puntero donde se guardará el link de imagen de la película
 *
 * \return int Retorna 0 si está todo Ok o -1 si hubo un error
 *
 */
int movie_getLinkImagen(sMovie* this, char* linkImagen);


/** \brief Elimina la lista de películas
 *
 * \param lista sMovie** Array de Punteros a Peliculas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int movie_clear(sMovie** lista, int len);


/** \brief Indica que cada posición del array está vacía, asignando NULL a cada Puntero
 *
 * \param lista sMovie** Array de Punteros a Peliculas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int inicializarPeliculas(sMovie** lista, int len);


/** \brief Encuentra la primera posición libre del array
 *
 * \param lista sMovie** Array de Punteros a Peliculas
 * \param len int Cantidad de elementos del array
 * \param indice int* Lugar donde se guardará el primer índice disponible
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int buscarLugarLibre(sMovie** lista, int len, int* indice);


/** \brief Verifica si el array está vacío
 *
 * \param lista sMovie** Array de Punteros a Peliculas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int arrayIsEmpty(sMovie** lista, int len);


/** \brief Carga algunas películas para testear
 *
 * \param lista sMovie** Array de Punteros a Películas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int hardCodearPeliculas(sMovie** lista, int len);


/** \brief Lee las películas del archivo binario y las carga al array
 *
 * \param lista sMovie** Array de Punteros a Películas
 * \param len int Cantidad de elementos del array
 * \param ruta[] char Ubicación del archivo
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int leerPeliculas(sMovie** lista, int len, char ruta[]);


/** \brief Guarda al archivo binario las películas del array
 *
 * \param lista sMovie** Array de Punteros a Películas
 * \param len int Cantidad de elementos del array
 * \param ruta[] char Ubicación del archivo
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int guardarPeliculas(sMovie** lista, int len, char ruta[]);


/** \brief Agrega una película al archivo binario
 *
 * \param lista sMovie** Array de Punteros a Películas
 * \param len int Cantidad de elementos del array
 * \param indice int Posición del array a ser cargada
 *
 * \return int (0) - (-1) de acuerdo a si pudo agregar la película o no
 *
 */
int agregarPelicula(sMovie** lista, int len, int indice);


/** \brief Encuentra una película por nombre
 *
 * \param lista sMovie** Array de Punteros a Películas
 * \param len int Cantidad de elementos del array
 * \param titulo[] char Nombre de la película a buscar
 * \param indice int* Lugar donde se guardará el índice de la película encontrada
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int buscarPeliculaPorTitulo(sMovie** lista, int len, char titulo[], int* indice);


/** \brief Borra una película del archivo binario
 *
 * \param lista sMovie** Array de Punteros a Películas
 * \param len int Cantidad de elementos del array
 * \param indice int Posición del array a ser cargada
 *
 * \return int (0) - (-1) de acuerdo a si pudo eliminar la película o no
 *
 */
int borrarPelicula(sMovie** lista, int len, int indice);


/** \brief Modifica una película del archivo binario
 *
 * \param lista sMovie** Array de Punteros a Películas
 * \param len int Cantidad de elementos del array
 * \param indice int Posición del array a ser cargada
 *
 * \return int (0) - (-1) de acuerdo a si pudo modificar la película o no
 *
 */
int modificarPelicula(sMovie** lista, int len, int indice);


/** \brief Muestra los datos de una película
 *
 * \param unaPelicula sMovie* Película a ser mostrada
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int mostrarUnaPelicula(sMovie* unaPelicula);


/** \brief Muestra la lista de películas
 *
 * \param lista sMovie** Array de Punteros a Películas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int mostrarListaPeliculas(sMovie** lista, int len);


/** \brief Genera un archivo html a partir de las películas cargadas en el archivo binario
 *
 * \param lista sMovie** Lista de películas a ser agregadas en el archivo
 * \param len int Cantidad de elementos del array
 * \param nombre[] char Nombre para el archivo
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int generarPagina(sMovie** lista, int len, char nombre[]);


/** \brief Muestra el menu de Películas
 *
 * \param opcion int* Variable donde se guarda la opcion seleccionada por el usuario
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int mostrarMenuPrincipal(int* opcion);


#endif // MOVIE_H_INCLUDED
