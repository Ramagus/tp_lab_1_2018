#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "Movie.h"
#define BUFFER_LEN 1500


/**
 * \brief Verifica si la cadena ingresada es numérica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es numérica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isInt(char* cadena, int limite);


/**
 * \brief Verifica si la cadena ingresada es flotante
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad máxima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es flotante, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int isFloat(char* cadena, int limite);


/**
 * \brief Verifica si la duración es válida
 *
 * \param duracion int Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidDuration(int duracion);


/**
 * \brief Verifica si el puntaje es válido
 *
 * \param puntaje float Atributo a ser analizado
 *
 * \return int Retorna 1 si es válido, 0 si no lo es
 *
 */
static int isValidScore(float puntaje);


/** \brief Muestra el menu de Modificacion de Peliculas
 *
 * \param opcion char* Variable donde se guarda la opcion seleccionada por el usuario
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
static int mostrarMenuModificacion(char* opcion);


/** \brief Arma el diseño de la página web de películas
 *
 * \param pArch1 FILE* Puntero a un archivo a ser leído
 * \param pArch2 FILE* Puntero a otro archivo a ser escrito
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
static int escribirPagina(FILE* pArch1, FILE* pArch2);


/** \brief Agrega los datos de una película a la página web
 *
 * \param this sMovie* Puntero a la película
 * \param pArch FILE* Puntero al archivo
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
static int escribirPelicula(sMovie* this, FILE* pArch);


/** \brief Agrega los datos de la lista de películas a la página web
 *
 * \param lista sMovie** Array de Punteros a Películas
 * \param len int Cantidad de elementos del array
 * \param pArch FILE* Puntero al archivo
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
static int escribirListaPeliculas(sMovie** lista, int len, FILE* pArch);


sMovie* movie_new(void)
{
    sMovie* this = NULL;

    this = (sMovie*) malloc(sizeof(sMovie));

    return this;
}

sMovie* movie_newParametros(char* titulo, char* genero, int duracion, char* descripcion, float puntaje, char* linkImagen)
{
    sMovie* this = NULL;

    if(titulo != NULL && genero != NULL && descripcion != NULL && linkImagen != NULL)
    {
        this = movie_new();

        if(this != NULL && (movie_setTitulo(this, titulo) || movie_setGenero(this, genero) ||
           movie_setDuracion(this, duracion) || movie_setDescripcion(this, descripcion) ||
           movie_setPuntaje(this, puntaje) || movie_setLinkImagen(this, linkImagen)))
        {
            movie_delete(this);
            this = NULL;
        }
    }

    return this;
}

sMovie* movie_newParametrosTxt(char* tituloStr, char* generoStr, char* duracionStr, char* descripcionStr, char* puntajeStr, char* linkImagenStr)
{
    sMovie* this = NULL;

    if(tituloStr != NULL && generoStr != NULL && duracionStr != NULL && descripcionStr != NULL && puntajeStr != NULL && linkImagenStr != NULL)
    {
        this = movie_new();

        if(this != NULL && (movie_setTitulo(this, tituloStr) || movie_setGenero(this, generoStr) ||
           movie_setDuracionTxt(this, duracionStr) || movie_setDescripcion(this, descripcionStr) ||
           movie_setPuntajeTxt(this, puntajeStr) || movie_setLinkImagen(this, linkImagenStr)))
        {
            movie_delete(this);
            this = NULL;
        }
    }

    return this;
}

int movie_delete(sMovie* this)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        free(this);

        auxReturn = 0;
    }

    return auxReturn;
}


int movie_setTitulo(sMovie* this, char* titulo)
{
    int auxReturn = -1;

    if(this != NULL && titulo != NULL && esAlfaNumerica(titulo, TITLE_LEN) == 1)
    {
        strncpy(this->titulo, titulo, TITLE_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_setGenero(sMovie* this, char* genero)
{
    int auxReturn = -1;

    if(this != NULL && genero != NULL && esAlfabetica(genero, GENRE_LEN) == 1)
    {
        strncpy(this->genero, genero, GENRE_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_setDuracion(sMovie* this, int duracion)
{
    int auxReturn = -1;

    if(this != NULL && isValidDuration(duracion))
    {
        this->duracion = duracion;
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_setDuracionTxt(sMovie* this, char* duracion)
{
    int auxReturn = -1;
    int auxDuracion;

    if(this != NULL && duracion != NULL && isInt(duracion, BUFFER_LEN) == 1)
    {
        auxDuracion = atoi(duracion);

        if(isValidDuration(auxDuracion))
        {
            this->duracion = auxDuracion;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int movie_setDescripcion(sMovie* this, char* descripcion)
{
    int auxReturn = -1;

    if(this != NULL && descripcion != NULL && esAlfaNumerica(descripcion, DESC_LEN) == 1)
    {
        strncpy(this->descripcion, descripcion, DESC_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_setPuntaje(sMovie* this, float puntaje)
{
    int auxReturn = -1;

    if(this != NULL && isValidScore(puntaje))
    {
        this->puntaje = puntaje;
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_setPuntajeTxt(sMovie* this, char* puntaje)
{
    int auxReturn = -1;
    float auxPuntaje;

    if(this != NULL && puntaje != NULL && isFloat(puntaje, BUFFER_LEN) == 1)
    {
        auxPuntaje = atof(puntaje);

        if(isValidScore(auxPuntaje))
        {
            this->puntaje = auxPuntaje;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int movie_setLinkImagen(sMovie* this, char* linkImagen)
{
    int auxReturn = -1;

    if(this != NULL && linkImagen != NULL && esAlfaNumerica(linkImagen, LINK_IMG_LEN) == 1)
    {
        strncpy(this->linkImagen, linkImagen, LINK_IMG_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_getTitulo(sMovie* this, char* titulo)
{
    int auxReturn = -1;

    if(this != NULL && titulo != NULL)
    {
        strncpy(titulo, this->titulo, TITLE_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_getGenero(sMovie* this, char* genero)
{
    int auxReturn = -1;

    if(this != NULL && genero != NULL)
    {
        strncpy(genero, this->genero, TITLE_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_getDuracion(sMovie* this, int* duracion)
{
    int auxReturn = -1;

    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_getDuracionTxt(sMovie* this, char* duracion)
{
    int auxReturn = -1;

    if(this != NULL && duracion != NULL)
    {
        snprintf(duracion, BUFFER_LEN, "%d", this->duracion);
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_getDescripcion(sMovie* this, char* descripcion)
{
    int auxReturn = -1;

    if(this != NULL && descripcion != NULL)
    {
        strncpy(descripcion, this->descripcion, DESC_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_getPuntaje(sMovie* this, float* puntaje)
{
    int auxReturn = -1;

    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_getPuntajeTxt(sMovie* this, char* puntaje)
{
    int auxReturn = -1;

    if(this != NULL && puntaje != NULL)
    {
        snprintf(puntaje, BUFFER_LEN, "%.2f", this->puntaje);
        auxReturn = 0;
    }

    return auxReturn;
}

int movie_getLinkImagen(sMovie* this, char* linkImagen)
{
    int auxReturn = -1;

    if(this != NULL && linkImagen != NULL)
    {
        strncpy(linkImagen, this->linkImagen, LINK_IMG_LEN);
        auxReturn = 0;
    }

    return auxReturn;
}

static int isInt(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isFloat(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tienePunto = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if(cadena[i] == '.' && tienePunto == 0)
                {
                    tienePunto = 1;
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isValidDuration(int duracion)
{
    int retorno = 0;

    if(duracion >= 15 && duracion <= 420)
    {
        retorno = 1;
    }

    return retorno;
}

static int isValidScore(float puntaje)
{
    int retorno = 0;

    if(puntaje >= 1 && puntaje <= 100)
    {
        retorno = 1;
    }

    return retorno;
}

int movie_clear(sMovie** lista, int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL)
            {
                movie_delete(*(lista + i));
                *(lista + i) = NULL;
            }
        }

        retorno = 0;
    }

    return retorno;
}

int inicializarPeliculas(sMovie** lista, int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            *(lista + i) = NULL;
        }

        retorno = 0;
    }

    return retorno;
}

int buscarLugarLibre(sMovie** lista, int len, int* indice)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0 && indice != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(*(lista + i) == NULL)
            {
                *indice = i;
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int arrayIsEmpty(sMovie** lista, int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        retorno = 1;

        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL)
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int hardCodearPeliculas(sMovie** lista, int len)
{
    int retorno = -1;
    int flagAdd = 0;
    int flagDelete;
    int index;
    int i;
    int cant;

    sMovie auxArray[] =
    {
        {"Back to the Future", "Aventura", 116,
         "Marty McFly, a 17-year-old high school student, is accidentally sent thirty years into the past in a time-traveling DeLorean invented by his close friend, the eccentric scientist Doc Brown",
         87, "https://www.imdb.com/title/tt0088763/mediaviewer/rm554638848/"},

        {"Ghostbusters", "Fantasia", 105,
         "Three former parapsychology professors set up shop as a unique ghost removal service",
         71, "https://www.imdb.com/title/tt0087332/mediaviewer/rm1280169216/"},

        {"The Exorcist", "Horror", 122,
         "When a 12-year-old girl is possessed by a mysterious entity, her mother seeks the help of two priests to save her",
         81, "https://www.imdb.com/title/tt0070047/mediaviewer/rm1202605312/"},

        {"Schindler's List", "Drama", 195,
         "In German-occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis",
         94, "https://www.imdb.com/title/tt0108052/mediaviewer/rm1610023168/"}
    };

    sMovie* this = NULL;

    if(lista != NULL && len > 0)
    {
        cant = sizeof(auxArray) / sizeof(sMovie);

        if(cant <= len)
        {
            for(i = 0; i < cant; i++)
            {
                this = movie_new();
                flagDelete = 0;

                if(!movie_delete(this))
                {
                    this = NULL;
                    flagDelete = 1;
                }

                if(flagDelete && !buscarLugarLibre(lista, len, &index))
                {
                    this = movie_newParametros((*(auxArray + i)).titulo, (*(auxArray + i)).genero, (*(auxArray + i)).duracion,
                                               (*(auxArray + i)).descripcion, (*(auxArray + i)).puntaje, (*(auxArray + i)).linkImagen);

                    if(this != NULL)
                    {
                        *(lista + index) = this;

                        flagAdd = 1;
                    }
                }

                else
                {
                    break;
                }
            }

            if(flagAdd)
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

int leerPeliculas(sMovie** lista, int len, char ruta[])
{
    int retorno = -1;
    int flagMovie = 0;
    int flagArch = 1;
    int index;

    FILE* pArch = NULL;
    sMovie* this = NULL;

    if(lista != NULL && len > 0 && ruta != NULL)
    {
        pArch = fopen(ruta, "rb");

        if(pArch != NULL)
        {
            do
            {
                this = movie_new();

                if(this != NULL)
                {
                    index = -1;

                    if(!buscarLugarLibre(lista, len, &index) && fread(this, sizeof(sMovie), 1, pArch) == 1)
                    {
                        *(lista + index) = this;

                        flagMovie = 1;
                    }

                    else
                    {
                        movie_delete(this);
                        this = NULL;

                        if(index == -1)
                        {
                            break;
                        }
                    }
                }

                else
                {
                    break;
                }

            } while(!feof(pArch));

            fclose(pArch);
            pArch = NULL;
        }

        else
        {
            hardCodearPeliculas(lista, len);
            guardarPeliculas(lista, len, ruta);

            flagArch = 0;
        }

        if(flagMovie || !flagArch)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int guardarPeliculas(sMovie** lista, int len, char ruta[])
{
    int retorno = -1;
    int i;

    FILE* pArch = NULL;
    sMovie* this = NULL;

    if(lista != NULL && len > 0 && ruta != NULL)
    {
        pArch = fopen(ruta, "wb");

        if(pArch != NULL)
        {
            for(i = 0; i < len; i++)
            {
                this = *(lista + i);

                if(this != NULL)
                {
                    fwrite(this, sizeof(sMovie), 1, pArch);
                }
            }

            fclose(pArch);
            pArch = NULL;

            retorno = 0;
        }
    }

    return retorno;
}

int agregarPelicula(sMovie** lista, int len, int indice)
{
    int retorno = -1;

    char auxTitulo[TITLE_LEN];
    char auxGenero[GENRE_LEN];
    int auxDuracion;
    char auxDescripcion[DESC_LEN];
    float auxPuntaje;
    char auxLinkImagen[LINK_IMG_LEN];

    sMovie* this = NULL;

    if(lista != NULL && len > 0 && indice >= 0 && indice < len && *(lista + indice) == NULL &&
       !utn_getAlfaNumerico(auxTitulo, "\nIngrese titulo: ", "Error. Reingrese solo letras y/o numeros: ", 3, TITLE_LEN, 2) &&
       !utn_getAlfabetico(auxGenero, "\nIngrese genero: ", "Error. Reingrese solo letras: ", 3, GENRE_LEN, 2) &&
       !utn_getNumero(&auxDuracion, "\nIngrese duracion entre 15 y 420: ", "Error. Reingrese solo numeros enteros entre 15 y 420: ", 15, 420, 2) &&
       !utn_getAlfaNumerico(auxDescripcion, "\nIngrese descripcion: ", "Error. Reingrese solo letras y/o numeros: ", 3, DESC_LEN, 2) &&
       !utn_getNumeroFlotante(&auxPuntaje, "\nIngrese puntaje entre 1 y 100: ", "Error. Reingrese solo numeros enteros entre 1 y 100: ", 1, 100, 2) &&
       !utn_getAlfaNumerico(auxLinkImagen, "\nIngrese link de imagen: ", "Error. Reingrese solo letras y/o numeros: ", 10, LINK_IMG_LEN, 2))
    {
        this = movie_newParametros(auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLinkImagen);

        if(this != NULL)
        {
            *(lista + indice) = this;

            retorno = 0;
        }
    }

    return retorno;
}

int buscarPeliculaPorTitulo(sMovie** lista, int len, char titulo[], int* indice)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0 && titulo != NULL && indice != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL && strncmp((*(lista + i))->titulo, titulo, TITLE_LEN) == 0)
            {
                *indice = i;
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int borrarPelicula(sMovie** lista, int len, int indice)
{
    int retorno = -1;

    if(lista != NULL && len > 0 && indice >= 0 && indice < len &&
       *(lista + indice) != NULL && !movie_delete(*(lista + indice)))
    {
        *(lista + indice) = NULL;

        retorno = 0;
    }

    return retorno;
}

static int mostrarMenuModificacion(char* opcion)
{
    int retorno = -1;

    if(opcion != NULL)
    {
        printf("\tMENU DE MODIFICACION\n\n");

        printf("A- Titulo\n");
        printf("B- Genero\n");
        printf("C- Duracion\n");
        printf("D- Descripcion\n");
        printf("E- Puntaje\n");
        printf("F- Link Imagen\n");
        printf("G- Salir\n");

        if(!utn_getCaracter(opcion, "\nIngrese una opcion: ", "Error. Reingrese una opcion correcta: ", 'A', 'G', 2))
        {
            retorno = 0;
        }
    }

    return retorno;
}

int modificarPelicula(sMovie** lista, int len, int indice)
{
    int retorno = -1;
    int flagMod = 0;
    int flagExit = 0;
    char opcion;

    char auxTitulo[TITLE_LEN];
    char auxGenero[GENRE_LEN];
    int auxDuracion;
    char auxDescripcion[DESC_LEN];
    float auxPuntaje;
    char auxLinkImagen[LINK_IMG_LEN];

    if(lista != NULL && len > 0 && indice >= 0 && indice < len && *(lista + indice) != NULL)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            if(!mostrarMenuModificacion(&opcion))
            {
                switch(opcion)
                {
                    case 'A':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el titulo de la pelicula? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getAlfaNumerico(auxTitulo, "\nIngrese nuevo titulo: ", "Error. Reingrese solo letras y/o numeros: ", 3, TITLE_LEN, 2) &&
                           !movie_setTitulo(*(lista + indice), auxTitulo))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'B':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el genero de la pelicula? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxGenero, "\nIngrese nuevo genero: ", "Error. Reingrese solo letras: ", 3, GENRE_LEN, 2) &&
                           !movie_setGenero(*(lista + indice), auxGenero))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'C':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar la duracion de la pelicula? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getNumero(&auxDuracion, "\nIngrese nueva duracion entre 15 y 420: ", "Error. Reingrese solo numeros enteros entre 15 y 420: ", 15, 420, 2) &&
                           !movie_setDuracion(*(lista + indice), auxDuracion))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'D':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar la descripcion de la pelicula? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getAlfaNumerico(auxDescripcion, "\nIngrese nueva descripcion: ", "Error. Reingrese solo letras y/o numeros: ", 3, DESC_LEN, 2) &&
                           !movie_setDescripcion(*(lista + indice), auxDescripcion))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'E':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el puntaje de la pelicula? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getNumeroFlotante(&auxPuntaje, "\nIngrese nuevo puntaje entre 1 y 100: ", "Error. Reingrese solo numeros enteros entre 1 y 100: ", 1, 100, 2) &&
                           !movie_setPuntaje(*(lista + indice), auxPuntaje))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'F':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el link de imagen de la pelicula? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getAlfaNumerico(auxLinkImagen, "\nIngrese nuevo link de imagen: ", "Error. Reingrese solo letras y/o numeros: ", 10, LINK_IMG_LEN, 2) &&
                           !movie_setLinkImagen(*(lista + indice), auxLinkImagen))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'G':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nUsted ha salido del menu de modificacion\n");

                            flagExit = 1;
                        }

                        break;
                }
            }

        } while(opcion != 'G' || !flagExit);

        if(flagMod)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int mostrarUnaPelicula(sMovie* unaPelicula)
{
    int retorno = -1;

    char auxTitulo[TITLE_LEN];
    char auxGenero[GENRE_LEN];
    int auxDuracion;
    char auxDescripcion[DESC_LEN];
    float auxPuntaje;
    char auxLinkImagen[LINK_IMG_LEN];

    if(unaPelicula != NULL && !movie_getTitulo(unaPelicula, auxTitulo) && !movie_getGenero(unaPelicula, auxGenero) &&
       !movie_getDuracion(unaPelicula, &auxDuracion) && !movie_getDescripcion(unaPelicula, auxDescripcion) &&
       !movie_getPuntaje(unaPelicula, &auxPuntaje) && !movie_getLinkImagen(unaPelicula, auxLinkImagen))
    {
        printf("\n\n--TITULO: %s\n", auxTitulo);
        printf("--GENERO: %s\n", auxGenero);
        printf("--DURACION: %d\n", auxDuracion);
        printf("--DESCRIPCION: %s\n", auxDescripcion);
        printf("--PUNTAJE: %.2f\n", auxPuntaje);
        printf("--LINK IMAGEN: %s\n", auxLinkImagen);

        retorno = 0;
    }

    return retorno;
}

int mostrarListaPeliculas(sMovie** lista, int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tLISTA DE PELICULAS\n");

        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL)
            {
                mostrarUnaPelicula(*(lista + i));
            }
        }

        retorno = 0;
    }

    return retorno;
}

static int escribirPagina(FILE* pArch1, FILE* pArch2)
{
    int retorno = -1;
    int i = 0;

    char buffer[BUFFER_LEN];

    if(pArch1 != NULL && pArch2 != NULL)
    {
        do
        {
            *(buffer + i) = fgetc(pArch1);
            i++;

        } while(i < BUFFER_LEN && !feof(pArch1));

        *(buffer + i - 1) = '\0';

        fprintf(pArch2, "%s", buffer);

        retorno = 0;
    }

    return retorno;
}

static int escribirPelicula(sMovie* this, FILE* pArch)
{
    int retorno = -1;

    char auxTitulo[TITLE_LEN];
    char auxGenero[GENRE_LEN];
    int auxDuracion;
    char auxDescripcion[DESC_LEN];
    float auxPuntaje;
    char auxLinkImagen[LINK_IMG_LEN];

    char buffer[BUFFER_LEN];

    if(this != NULL && pArch != NULL && !movie_getTitulo(this, auxTitulo) && !movie_getGenero(this, auxGenero) &&
       !movie_getDuracion(this, &auxDuracion) && !movie_getDescripcion(this, auxDescripcion) &&
       !movie_getPuntaje(this, &auxPuntaje) && !movie_getLinkImagen(this, auxLinkImagen))
    {
        snprintf(buffer, BUFFER_LEN, "\t\t\t<!-- Repetir esto para cada pelicula -->\n"
                                     "\t\t\t<article class='col-md-4 article-intro'>\n"
                                     "\t\t\t\t<a href='#'>\n"
                                     "\t\t\t\t\t<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                                     "\t\t\t\t</a>\n"
                                     "\t\t\t\t<h3>\n"
                                     "\t\t\t\t\t<a href='#'>%s</a>\n"
                                     "\t\t\t\t</h3>\n"
                                     "\t\t\t\t<ul>\n"
                                     "\t\t\t\t\t<li>G&eacute;nero: %s</li>\n"
                                     "\t\t\t\t\t<li>Puntaje: %.2f</li>\n"
                                     "\t\t\t\t\t<li>Duraci&oacute;n: %d</li>\n"
                                     "\t\t\t\t</ul>\n"
                                     "\t\t\t\t<p>%s</p>\n"
                                     "\t\t\t</article>\n"
                                     "\t\t\t<!-- Repetir esto para cada pelicula -->\n\n\n", auxLinkImagen, auxTitulo, auxGenero,
                                                                                             auxPuntaje, auxDuracion, auxDescripcion);

        fprintf(pArch, "%s", buffer);

        retorno = 0;
    }

    return retorno;
}

static int escribirListaPeliculas(sMovie** lista, int len, FILE* pArch)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0 && pArch != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL)
            {
                escribirPelicula(*(lista + i), pArch);
            }
        }

        retorno = 0;
    }

    return retorno;
}

int generarPagina(sMovie** lista, int len, char nombre[])
{
    int retorno = -1;

    FILE* pIndex1 = NULL;
    FILE* pIndex2 = NULL;
    FILE* pWeb = NULL;

    if(lista != NULL && len > 0 && nombre != NULL)
    {
        pIndex1 = fopen("../../TP3/template/index_1.txt", "r");
        pWeb = fopen(nombre, "w");
        pIndex2 = fopen("../../TP3/template/index_2.txt", "r");

        if(pIndex1 != NULL && pWeb != NULL && pIndex2 != NULL && !escribirPagina(pIndex1, pWeb) &&
           !escribirListaPeliculas(lista, len, pWeb) && !escribirPagina(pIndex2, pWeb))
        {
            fclose(pIndex1);
            pIndex1 = NULL;

            fclose(pWeb);
            pWeb = NULL;

            fclose(pIndex2);
            pIndex2 = NULL;

            retorno = 0;
        }
    }

    return retorno;
}

int mostrarMenuPrincipal(int* opcion)
{
    int retorno = -1;

    if(opcion != NULL)
    {
        printf("\tMENU PRINCIPAL\n\n");

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        if(!utn_getNumero(opcion, "\nIngrese una opcion: ", "Error. Reingrese una opcion correcta: ", 1, 5, 2))
        {
            retorno = 0;
        }
    }

    return retorno;
}
