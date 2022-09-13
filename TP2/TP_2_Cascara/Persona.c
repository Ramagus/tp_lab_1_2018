#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "Input.h"
#define CONT_LEN 3

int inicializarPersonas(ePersona lista[], int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            lista[i].estado = TRUE;
        }

        retorno = 0;
    }

    return retorno;
}

int obtenerEspacioLibre(ePersona lista[], int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(lista[i].estado)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int arrayIsEmpty(ePersona lista[], int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        retorno = 1;

        for(i = 0; i < len; i++)
        {
            if(!lista[i].estado)
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int hardcodearPersonas(ePersona lista[], int len)
{
    int retorno = -1;
    int indice;
    int i;
    int cant;
    int flag = FALSE;

    ePersona auxArray[] =
    {
        {"Daniela", 17, 11222333, FALSE},
        {"Santiago", 16, 22444555, FALSE},
        {"Carla", 15, 33666777, FALSE},
        {"Juan", 14, 44888999, FALSE},
        {"Florencia", 19, 55999888, FALSE},
        {"Jorge", 40, 12777666, FALSE},
        {"Belen", 25, 25555444, FALSE},
        {"Nicolas", 21, 30333222, FALSE},
        {"Paula", 30, 35123321, FALSE},
        {"Alejandro", 33, 20456654, FALSE},
        {"Marcela", 35, 17789987, FALSE},
        {"Ricardo", 44, 28010232, FALSE},
        {"Valentina", 42, 36101353, FALSE},
        {"Miguel", 50, 15440051, FALSE},
        {"Natalia", 46, 10006601, FALSE}
    };

    if(lista != NULL && len > 0)
    {
        cant = sizeof(auxArray) / sizeof(ePersona);

        if(cant <= len)
        {
            for(i = 0; i < cant; i++)
            {
                indice = obtenerEspacioLibre(lista, len);

                if(indice > -1)
                {
                    lista[indice] = auxArray[i];
                    flag = TRUE;
                }

                else
                {
                    break;
                }
            }

            if(flag)
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

int cargarPersona(ePersona* unaPersona)
{
    int retorno = -1;

    if(unaPersona != NULL &&
       !utn_getAlfabetico(unaPersona->nombre, "Ingrese nombre: ", "Error. Reingrese solo letras: ", 3, NOMBRE_LEN, 2) &&
       !utn_formatearCadena(unaPersona->nombre, NOMBRE_LEN) &&
       !utn_getNumero(&unaPersona->edad, "\nIngrese edad entre 1 y 100: ", "Error. Reingrese solo numeros enteros entre 1 y 100: ", 1, 100, 2) &&
       !utn_getNumero(&unaPersona->dni, "\nIngrese DNI: ", "Error. Reingrese solo numeros enteros entre 1 y 100000000: ", 1, 100000000, 2))
    {
        unaPersona->estado = FALSE;

        retorno = 0;
    }

    return retorno;
}

int agregarPersona(ePersona lista[], int len, int indice)
{
    int retorno = -1;

    if(lista != NULL && len > 0 && indice >= 0 && indice < len &&
       lista[indice].estado && !cargarPersona(&lista[indice]))
    {
        retorno = 0;
    }

    return retorno;
}

int borrarPersona(ePersona lista[], int len, int indice)
{
    int retorno = -1;

    if(lista != NULL && len > 0 && indice >= 0 && indice < len && !lista[indice].estado)
    {
        lista[indice].estado = TRUE;

        retorno = 0;
    }

    return retorno;
}

int buscarPorDni(ePersona lista[], int len, int dni)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0 && dni > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(!lista[i].estado && lista[i].dni == dni)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int compararString(char* a, char* b, int length)
{
    int retorno = -2;
    int auxCmp;

    if(a != NULL && b != NULL && length > 0)
    {
        auxCmp = strncmp(a, b, length);

        if(auxCmp < 0)
        {
            retorno = -1;
        }

        else if(auxCmp == 0)
        {
            retorno = 0;
        }

        else
        {
            retorno = 1;
        }
    }

    return retorno;
}

int compararInt(int a, int b)
{
    int retorno = -2;

    if(a > 0 && b > 0)
    {
        if(a < b)
        {
            retorno = -1;
        }

        else if(a == b)
        {
            retorno = 0;
        }

        else
        {
            retorno = 1;
        }
    }

    return retorno;
}

int compararCriterio(ePersona* a, ePersona* b, int criterio)
{
    int retorno = -3;

    if(a != NULL && b != NULL && criterio >= 0)
    {
        switch(criterio)
        {
            case NOMBRE:

                retorno = compararString(a->nombre, b->nombre, NOMBRE_LEN);

                break;

            case EDAD:

                retorno = compararInt(a->edad, b->edad);

                break;

            case DNI:

                retorno = compararInt(a->dni, b->dni);

                break;
        }
    }

    return retorno;
}

int swapPersonas(ePersona* a, ePersona* b)
{
    int retorno = -1;
    ePersona temp;

    if(a != NULL && b != NULL)
    {
        temp = *a;
        *a = *b;
        *b = temp;

        retorno = 0;
    }

    return retorno;
}

int ordenarPersonas(ePersona lista[], int len, int criterio, int order)
{
    int retorno = -1;
    int i;
    int auxLen;
    int flagSwap;

    if(lista != NULL && len > 0 && criterio >= 0 && (order == UP || order == DOWN))
    {
        auxLen = len;

        do
        {
            flagSwap = FALSE;

            for(i = 0; i < auxLen - 1; i++)
            {
                if(!lista[i].estado && !lista[i + 1].estado &&
                   compararCriterio(&lista[i], &lista[i + 1], criterio) == order - !order &&
                   !swapPersonas(&lista[i], &lista[i + 1]))
                {
                    flagSwap = TRUE;
                }
            }

            auxLen--;

        } while(flagSwap);

        retorno = 0;
    }

    return retorno;
}

int elegirCriterioOrdenamiento(int* criterio)
{
    int retorno = -1;
	char opcion;

    if(criterio != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tCRITERIO DE ORDENAMIENTO\n\n");
        printf("A. Nombre\n");
        printf("B. Edad\n");
        printf("C. DNI\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'C', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *criterio = NOMBRE;

                    break;

                case 'B':

                    *criterio = EDAD;

                    break;

                case 'C':

                    *criterio = DNI;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int elegirSentidoOrdenamiento(int* order)
{
    int retorno = -1;
	char opcion;

    if(order != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tSENTIDO DE ORDENAMIENTO\n\n");
        printf("A. Orden Ascendente\n");
        printf("B. Orden Descendente\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *order = UP;

                    break;

                case 'B':

                    *order = DOWN;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int mostrarUnaPersona(ePersona* unaPersona)
{
    int retorno = -1;

    if(unaPersona != NULL)
    {
        printf("|%-20s|%-4d|%-8d|\n", unaPersona->nombre, unaPersona->edad, unaPersona->dni);

        retorno = 0;
    }

    return retorno;
}

int mostrarListaPersonas(ePersona lista[], int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE PERSONAS\n\n");

        printf("*--------------------*----*--------*\n");
        printf("|%-20s|%-4s|%-8s|\n", "NOMBRE", "EDAD", "DNI");
        printf("*--------------------*----*--------*\n");

        for(i = 0; i < len; i++)
        {
            if(!lista[i].estado && mostrarUnaPersona(&lista[i]))
            {
                break;
            }
        }

        printf("*--------------------*----*--------*\n");

        if(i == len)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int contarPersonasPorEdad(ePersona lista[], int len, int minEdad, int maxEdad, int* cantidad)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0 && minEdad >= 1 && maxEdad <= 100 && cantidad != NULL)
    {
        *cantidad = 0;

        for(i = 0; i < len; i++)
        {
            if(!lista[i].estado && lista[i].edad >= minEdad && lista[i].edad <= maxEdad)
            {
                (*cantidad)++;
            }
        }

        retorno = 0;
    }

    return retorno;
}

int encontrarMaximaCantidad(int cont[], int len, int* maximo)
{
    int retorno = -1;
    int i;

    if(cont != NULL && len > 0 && maximo != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(i == 0 || cont[i] > *maximo)
            {
                *maximo = cont[i];
            }
        }

        retorno = 0;
    }

    return retorno;
}

int mostrarGraficoEdades(ePersona lista[], int len)
{
    int retorno = -1;
    int contRangoEdades[CONT_LEN];
    int maxCont;
    char caracter;
    int i;
    int j;

    if(lista != NULL && len > 0 &&
       !contarPersonasPorEdad(lista, len, 1, 17, &contRangoEdades[0]) &&
       !contarPersonasPorEdad(lista, len, 19, 35, &contRangoEdades[1]) &&
       !contarPersonasPorEdad(lista, len, 36, 100, &contRangoEdades[2]) &&
       !encontrarMaximaCantidad(contRangoEdades, CONT_LEN, &maxCont))
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tGRAFICO DE EDADES\n\n");

        for(i = maxCont - 1; i >= 0; i--)
        {
            for(j = 0; j < CONT_LEN; j++)
            {
                if(i < contRangoEdades[j])
                {
                    caracter = '*';
                }

                else
                {
                    caracter = ' ';
                }

                printf("%13c", caracter);
            }

            printf("\n");
        }

        printf("%13s %15s %9s\n", "< 18", "19 - 35", "> 35");

        retorno = 0;
    }

    return retorno;
}

int mostrarMenuPrincipal(int* opcion)
{
    int retorno = -1;

    if(opcion != NULL)
    {
        printf("\tMENU PRINCIPAL\n\n");

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        if(!utn_getNumero(opcion, "\nIngrese una opcion: ", "Error. Reingrese una opcion correcta: ", 1, 5, 2))
        {
            retorno = 0;
        }
    }

    return retorno;
}
