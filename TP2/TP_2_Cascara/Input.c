#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Input.h"

#define MAX_LEN 100


/** \brief Lee de stdin una cadena hasta que encuentra un '\n' o hasta que haya copiado
 *         un m�ximo de "longitud - 1" caracteres
 *
 * \param pResultado char* Puntero al espacio de memoria donde se copiar� la cadena obtenida
 * \param longitud int Define el tama�o de cadena
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud);


/** \brief Verifica si la cadena ingresada es num�rica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es num�rica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite);


/** \brief Obtiene un n�mero entero
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene un n�mero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado);


/** \brief Verifica si la cadena ingresada es alfab�tica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es alfab�tica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esAlfabetica(char* cadena, int limite);


/** \brief Obtiene una cadena alfab�tica
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena alfab�tica y -1 (ERROR) si no
 *
 */
static int getStringAlfabetico(char* pResultado);


/** \brief Obtiene un caracter
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene un solo caracter y -1 (ERROR) si no
 *
 */
static int getChar(char* pResultado);


int utn_formatearCadena(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        strlwr(cadena);

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(i == 0 || isspace(cadena[i - 1]))
            {
                cadena[i] = toupper(cadena[i]);
            }
        }

        retorno = 0;
    }

    return retorno;
}

static int getString(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int len;

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);

        if(fgets(bufferString, MAX_LEN, stdin) != NULL)
        {
            len = strnlen(bufferString, MAX_LEN);

            if(len < longitud)
            {
                if(bufferString[len - 1] == '\n')
                {
                    bufferString[len - 1] = '\0';
                }

                strncpy(cadena, bufferString, longitud);
                retorno = 0;
            }
        }
    }

    return retorno;
}

static int esNumerica(char* cadena, int limite)
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
                if((i == 0) && (cadena[i] == '-' || cadena[i] == '+'))
                {
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esNumerica(bufferString, MAX_LEN) == 1)
    {
        *pResultado = atoi(bufferString);
        retorno = 0;
    }

    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    int flagError = 0;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if((!getInt(&bufferInt)) && (bufferInt >= minimo && bufferInt <= maximo))
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int esAlfabetica(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isalpha(cadena[i]) && !isspace(cadena[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getStringAlfabetico(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esAlfabetica(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getAlfabetico(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringAlfabetico(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int getChar(char* pResultado)
{
    int retorno = -1;
    char bufferChar;
    char auxString[5];
    int len;

    if(pResultado != NULL && !getString(auxString, sizeof(auxString)))
    {
        len = strnlen(auxString, sizeof(auxString));

        if(len == 1)
        {
            bufferChar = auxString[0];
            *pResultado = bufferChar;
            retorno = 0;
        }
    }

    return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int flagError = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

			if(!getChar(&bufferChar))
			{
				if(isalpha(minimo) && isalpha(maximo))
                {
                    if((isupper(minimo) && isupper(maximo)) && islower(bufferChar))
                    {
                        bufferChar = toupper(bufferChar);
                    }

                    else if((islower(minimo) && islower(maximo)) && isupper(bufferChar))
                    {
                        bufferChar = tolower(bufferChar);
                    }
                }

                if(bufferChar >= minimo && bufferChar <= maximo)
                {
                    *pResultado = bufferChar;
                    retorno = 0;
                    break;
                }
			}

			reintentos--;

		} while(reintentos >= 0);
	}

	return retorno;
}

int utn_respuestaEsAfirmativa(char* mensaje, char* mensajeError)
{
    int retorno = -1;
    int flagError = 0;
    char dato = '\0';

    if(mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            dato = toupper(getche());
            printf("\n");

        } while(dato != 'S' && dato != 'N');

        switch(dato)
        {
            case 'S':

                retorno = 1;

                break;

            case 'N':

                retorno = 0;

                break;
        }
    }

    return retorno;
}
