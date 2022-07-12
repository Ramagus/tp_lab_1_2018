#include <stdio.h>
#include <stdlib.h>
#include "Movie.h"
#include "Input.h"
#define PATH "peliculas.bin"
#define TAM 10

int main()
{
    sMovie* arrayPeliculas[TAM];
    int auxIndice;
    char auxTitulo[TITLE_LEN];
    int flagExit = 0;
    int opcion;

    if(!inicializarPeliculas(arrayPeliculas, TAM))
    {
        leerPeliculas(arrayPeliculas, TAM, PATH);

        do
        {
            if(!mostrarMenuPrincipal(&opcion))
            {
                switch(opcion)
                {
                    case 1:

                        if(!buscarLugarLibre(arrayPeliculas, TAM, &auxIndice))
                        {
                            printf("\n");
                            system("pause");
                            system("cls");

                            printf("\tALTA DE PELICULA\n");

                            if(!agregarPelicula(arrayPeliculas, TAM, auxIndice))
                            {
                                printf("\nPelicula cargada correctamente\n");
                                guardarPeliculas(arrayPeliculas, TAM, PATH);
                            }

                            else
                            {
                                printf("\nError en el alta\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay lugar disponible\n");
                        }

                        break;

                    case 2:

                        if(!arrayIsEmpty(arrayPeliculas, TAM))
                        {
                            if(!mostrarListaPeliculas(arrayPeliculas, TAM) &&
                               !utn_getAlfaNumerico(auxTitulo, "\n\nIngrese el titulo de la pelicula a borrar: ", "Error. Reingrese solo numeros y/o letras: ", 3, TITLE_LEN, 2))
                            {
                                if(!buscarPeliculaPorTitulo(arrayPeliculas, TAM, auxTitulo, &auxIndice))
                                {
                                    printf("\n");
                                    system("pause");
                                    system("cls");

                                    printf("\tBAJA DE PELICULA\n");
                                    mostrarUnaPelicula(*(arrayPeliculas + auxIndice));

                                    if(utn_respuestaEsAfirmativa("\n\nEsta seguro que desea borrar esta pelicula? (S/N): ", "Error. Solo S o N: ") == 1 &&
                                       !borrarPelicula(arrayPeliculas, TAM, auxIndice))
                                    {
                                        printf("\nPelicula borrada correctamente\n");
                                        guardarPeliculas(arrayPeliculas, TAM, PATH);
                                    }

                                    else
                                    {
                                        printf("\nNo se pudo borrar la pelicula\n");
                                    }
                                }

                                else
                                {
                                    printf("\nError en la baja\n");
                                }
                            }
                        }

                        else
                        {
                            printf("\nNo hay peliculas para borrar\n");
                        }

                        break;

                    case 3:

                        if(!arrayIsEmpty(arrayPeliculas, TAM))
                        {
                            if(!mostrarListaPeliculas(arrayPeliculas, TAM) &&
                               !utn_getAlfaNumerico(auxTitulo, "\n\nIngrese el titulo de la pelicula a modificar: ", "Error. Reingrese solo numeros y/o letras: ", 3, TITLE_LEN, 2))
                            {
                                if(!buscarPeliculaPorTitulo(arrayPeliculas, TAM, auxTitulo, &auxIndice))
                                {
                                    printf("\n");
                                    system("pause");
                                    system("cls");

                                    printf("\tMODIFICACION DE PELICULA\n");
                                    mostrarUnaPelicula(*(arrayPeliculas + auxIndice));

                                    if(utn_respuestaEsAfirmativa("\n\nEsta seguro que desea modificar esta pelicula? (S/N): ", "Error. Solo S o N: ") == 1 &&
                                       !modificarPelicula(arrayPeliculas, TAM, auxIndice))
                                    {
                                        printf("\nPelicula modificada correctamente\n");
                                        guardarPeliculas(arrayPeliculas, TAM, PATH);
                                    }

                                    else
                                    {
                                        printf("\nNo se pudo modificar la pelicula\n");
                                    }
                                }

                                else
                                {
                                    printf("\nError en la modificacion\n");
                                }
                            }
                        }

                        else
                        {
                            printf("\nNo hay peliculas para modificar\n");
                        }

                       break;

                    case 4:

                        if(!arrayIsEmpty(arrayPeliculas, TAM))
                        {
                            if(!generarPagina(arrayPeliculas, TAM, "../../TP3/template/paginaWeb.html"))
                            {
                                printf("\nArchivo generado con exito\n");
                            }

                            else
                            {
                                printf("\nNo se pudo generar el archivo\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay peliculas para generar la pagina web\n");
                        }

                        break;

                    case 5:

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nUsted ha salido del menu principal\n");

                            flagExit = 1;
                        }

                        break;
                }
            }

            printf("\n");
            system("pause");
            system("cls");

        } while(opcion != 5 || !flagExit);

        movie_clear(arrayPeliculas, TAM);
    }

    else
    {
        printf("Error en la inicializacion\n");
    }

    return 0;
}
