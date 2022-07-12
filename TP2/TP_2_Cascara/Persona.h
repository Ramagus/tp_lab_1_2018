#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#define NOMBRE_LEN 50

#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define NOMBRE 0
#define EDAD 1
#define DNI 2

typedef struct
{
    char nombre[NOMBRE_LEN];
    int edad;
    int dni;
    int estado;

} ePersona;


/** \brief Indica que cada posición del array está vacía, estableciendo la bandera (estado) en TRUE
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int inicializarPersonas(ePersona lista[], int len);


/** \brief Encuentra la primera posición libre del array
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error o el primer índice disponible
 *
 */
int obtenerEspacioLibre(ePersona lista[], int len);


/** \brief Verifica si el estado de cada posicion del array es TRUE
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int arrayIsEmpty(ePersona lista[], int len);


/** \brief Carga algunas personas para testear
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int hardcodearPersonas(ePersona lista[], int len);


/** \brief Guarda los datos de una persona
 *
 * \param unaPersona ePersona* Persona a ser cargada
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int cargarPersona(ePersona* unaPersona);


/** \brief Asigna los datos de una persona en la posicion especificada
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 * \param indice int Posicion del array a ser cargada
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int agregarPersona(ePersona lista[], int len, int indice);


/** \brief Elimina una persona en la posicion especificada cambiando su estado a FALSE
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 * \param indice int Posicion del array a ser eliminada
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int borrarPersona(ePersona lista[], int len, int indice);


/** \brief Encuentra una persona por DNI
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 * \param dni int DNI a ser buscado
 *
 * \return int (-1) si hubo un error o el índice de la persona encontrada
 *
 */
int buscarPorDni(ePersona lista[], int len, int dni);


/** \brief Compara los valores de dos string
 *
 * \param a char* Primer string
 * \param b char* Segundo string
 * \param length int Longitud de String
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer string es menor al segundo string en su valor
 *             ( 0) si ambos string son iguales
 *             ( 1) si el primer string es mayor al segundo string en su valor
 *
 */
int compararString(char* a, char* b, int length);


/** \brief Compara los valores de dos int
 *
 * \param a int Primer int
 * \param b int Segundo int
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer int es menor al segundo int
 *             ( 0) si ambos int son iguales
 *             ( 1) si el primer int es mayor al segundo int
 *
 */
int compararInt(int a, int b);


/** \brief Compara los valores de los datos de dos personas
 *
 * \param a ePersona* Primera persona
 * \param b ePersona* Segunda persona
 * \param criterio int Criterio de ordenamiento
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int compararCriterio(ePersona* a, ePersona* b, int criterio);


/** \brief Intercambia los valores de dos personas
 *
 * \param a ePersona* Primera persona
 * \param b ePersona* Segunda persona
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int swapPersonas(ePersona* a, ePersona* b);


/** \brief Ordena los elementos en el array de personas
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 * \param criterio int Criterio de ordenamiento
 * \param order int [1] indica UP - [0] indica DOWN
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int ordenarPersonas(ePersona lista[], int len, int criterio, int order);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param criterio int* Lugar donde se guardará el criterio elegido
 *
 * \return int (-1) ai hubo un error - (0) si está todo ok
 *
 */
int elegirCriterioOrdenamiento(int* criterio);


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int elegirSentidoOrdenamiento(int* order);


/** \brief Imprime los datos de una persona
 *
 * \param unaPersona ePersona* Persona a mostrar
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int mostrarUnaPersona(ePersona* unaPersona);


/** \brief Imprime el contenido del array de personas
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int mostrarListaPersonas(ePersona lista[], int len);


/** \brief Cuenta la cantidad de personas dentro del rango de edad
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 * \param minEdad int Edad minima del rango
 * \param maxEdad int Edad maxima del rango
 * \param cantidad int* Variable donde se guardará la cantidad
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int contarPersonasPorEdad(ePersona lista[], int len, int minEdad, int maxEdad, int* cantidad);


/** \brief Busca el máximo contador de rango de edades
 *
 * \param cont[] int Array donde se almacenan los contadores
 * \param len int Cantidad de contadores
 * \param maximo int* Variable donde se guardará el máximo contador
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int encontrarMaximaCantidad(int cont[], int len, int* maximo);


/** \brief Imprime el gráfico que muestra la cantidad de cada rango de edades
 *
 * \param lista[] ePersona Array de personas
 * \param len int Cantidad de elementos del array
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int mostrarGraficoEdades(ePersona lista[], int len);


/** \brief Muestra el menu de Personas
 *
 * \param opcion int* Lugar donde se guardará la opcion seleccionada por el usuario
 *
 * \return int (-1) si hubo un error - (0) si está todo ok
 *
 */
int mostrarMenuPrincipal(int* opcion);


#endif // PERSONA_H_INCLUDED
