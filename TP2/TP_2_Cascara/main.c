#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "Input.h"
#define MAX 20

int main()
{
    ePersona arrayPersonas[MAX];

    int opcion;
    int auxIndice;
    int auxDni;
    int auxOrder;

    int flag = 0;

    if(!inicializarPersonas(arrayPersonas, MAX))
    {
        hardcodearPersonas(arrayPersonas, MAX);

        do
        {
            if(!mostrarMenuPrincipal(&opcion))
            {
                switch(opcion)
                {
                    case 1:

                        auxIndice = obtenerEspacioLibre(arrayPersonas, MAX);

                        if(auxIndice > -1)
                        {
                            printf("\n");
                            system("pause");
                            system("cls");

                            printf("\tALTA DE PERSONA\n\n");

                            if(!agregarPersona(arrayPersonas, MAX, auxIndice))
                            {
                                printf("\nAlta realizada correctamente\n");
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

                        if(!arrayIsEmpty(arrayPersonas, MAX))
                        {
                            if(!mostrarListaPersonas(arrayPersonas, MAX) &&
                               !utn_getNumero(&auxDni, "\nIngrese el DNI de la persona a borrar: ", "Error. Reingrese solo numeros enteros entre 1 y 100000000: ", 1, 100000000, 2))
                               {
                                   auxIndice = buscarPorDni(arrayPersonas, MAX, auxDni);

                                   if(auxIndice > -1)
                                   {
                                        printf("\n");
                                        system("pause");
                                        system("cls");

                                        printf("\tBAJA DE PERSONA\n\n");

                                        printf("*--------------------*----*--------*\n");
                                        printf("|%-20s|%-4s|%-8s|\n", "NOMBRE", "EDAD", "DNI");
                                        printf("*--------------------*----*--------*\n");
                                        mostrarUnaPersona(&arrayPersonas[auxIndice]);
                                        printf("*--------------------*----*--------*\n");

                                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a esta persona? (S/N): ", "\nError. Solo S o N: ") == 1 &&
                                          !borrarPersona(arrayPersonas, MAX, auxIndice))
                                        {
                                           printf("\nBaja realizada correctamente\n");
                                        }

                                        else
                                        {
                                           printf("\nError en la baja\n");
                                        }
                                   }

                                   else
                                   {
                                       printf("\nNo se pudo realizar la baja\n");
                                   }
                               }
                        }

                        else
                        {
                            printf("\nNo hay personas para borrar\n");
                        }

                        break;

                    case 3:

                        if(!arrayIsEmpty(arrayPersonas, MAX))
                        {
                            if(!elegirSentidoOrdenamiento(&auxOrder) && !ordenarPersonas(arrayPersonas, MAX, NOMBRE, auxOrder) &&
                               !mostrarListaPersonas(arrayPersonas, MAX))
                            {
                                printf("\nMuestra realizada correctamente\n");
                            }

                            else
                            {
                                printf("\nError en la muestra\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay personas para mostrar\n");
                        }

                        break;

                    case 4:

                        if(!arrayIsEmpty(arrayPersonas, MAX))
                        {
                            if(!mostrarGraficoEdades(arrayPersonas, MAX))
                            {
                                printf("\nGr%cfico mostrado correctamente\n", 160);
                            }

                            else
                            {
                                printf("\nError en la muestra\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay personas para mostrar\n");
                        }

                        break;

                    case 5:

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "\nError. Solo S o N: ") == 1)
                        {
                            printf("\nUsted ha salido del menu\n");

                            flag = 1;
                        }

                        break;
                }
            }

            printf("\n");
            system("pause");
            system("cls");

        } while(opcion != 5 || !flag);
    }

    else
    {
        printf("Error en la inicializacion\n");
    }

    return 0;
}
