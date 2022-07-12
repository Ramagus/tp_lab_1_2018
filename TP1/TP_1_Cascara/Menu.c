#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Menu.h"
#include "Input.h"
#include "Calculadora.h"

int mostrarMenuOpciones(double numero1, double numero2, int flagNum1, int flagNum2, int* opcion)
{
    int ret = -1;

    if(opcion != NULL)
    {
        printf("\tCALCULADORA\n\n");
        printf("1- Ingresar 1er operando (A = ");

        if(flagNum1 == 0)
        {
            printf("x)\n");
        }

        else
        {
            printf("%g)\n", numero1);
        }

        printf("2- Ingresar 2do operando (B = ");

        if(flagNum2 == 0)
        {
            printf("y)\n");
        }

        else
        {
            printf("%g)\n", numero2);
        }

        printf("3- Calcular la suma (A + B)\n");
        printf("4- Calcular la resta (A - B)\n");
        printf("5- Calcular la division (A / B)\n");
        printf("6- Calcular la multiplicacion (A * B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular el factorial (B!)\n");
        printf("9- Calcular todas las operaciones\n");
        printf("10- Salir\n");

        if(utn_getNumero(opcion, "\nElija una opcion: ", "Error. Solo numeros enteros: ") == 0)
        {
            ret = 0;
        }
    }

    return ret;
}

int esEntero(double numero)
{
    int ret = 0;

    if(fmod(numero, 1) == 0)
    {
        ret = 1;
    }

    return ret;
}

int procesarFactorial(double numero, unsigned long int* fact, int* flagFact)
{
    int ret = -1;
    int aux;

    if(fact != NULL && flagFact != NULL)
    {
        if(esEntero(numero))
        {
            aux = (int) numero;

            if(!factorial(aux, fact))
            {
                *flagFact = 1;
            }
        }

        else
        {
            *flagFact = -1;
        }

        ret = 0;
    }

    return ret;
}

int realizarOperaciones(double numero1, double numero2, double* suma, double* resta, double* division,
						double* multiplicacion, unsigned long int* fact1, unsigned long int* fact2,
						int* flagDiv, int* flagFact1, int* flagFact2)
{
    int ret = -1;

    if(suma != NULL && resta != NULL && division != NULL && multiplicacion != NULL && fact1 != NULL &&
	   fact2 != NULL && flagDiv != NULL && flagFact1 != NULL && flagFact2 != NULL)
    {
        printf("\nSe realizaran las siguientes operaciones:\n\n");

        printf("a) Suma (A + B)\n");
        printf("b) Resta (A - B)\n");
        printf("c) Division (A / B)\n");
        printf("d) Multiplicacion (A * B)\n");
        printf("e) Factorial (A!)\n");
        printf("f) Factorial (B!)\n");

        if(!sumar(numero1, numero2, suma) && !restar(numero1, numero2, resta) && !multiplicar(numero1, numero2, multiplicacion) &&
           !procesarFactorial(numero1, fact1, flagFact1) && !procesarFactorial(numero2, fact2, flagFact2))
        {
            if(!dividir(numero1, numero2, division))
            {
                *flagDiv = 1;
            }

            ret = 0;
        }
    }

    return ret;
}

void informarDivision(double division, int flagDiv)
{
    if(flagDiv == 0)
    {
    	printf("No se puede dividir por 0\n");
    }

    else
    {
    	printf("El resultado de la division es: %g\n", division);
    }
}

void informarFactorial(unsigned long int fact, char letra, int flagFact)
{
    if(flagFact == -1)
    {
        printf("No se puede calcular el factorial de un numero decimal\n");
    }

    else if(flagFact == 0)
    {
    	printf("No se puede calcular el factorial de un numero entero negativo\n");
    }

	else
	{
		printf("El resultado del factorial de %c es: %lu\n", letra, fact);
	}
}

void informarResultados(double suma, double resta, double division, double multiplicacion,
		                unsigned long int fact1, unsigned long int fact2,
                        int flagDiv, int flagFact1, int flagFact2)
{
    printf("\n\tRESULTADOS DE CALCULOS\n");

    printf("\nSUMA (A + B): ");
    printf("El resultado de la suma es: %g\n", suma);

    printf("\nRESTA (A - B): ");
    printf("El resultado de la resta es: %g\n", resta);

    printf("\nDIVISION (A / B): ");
    informarDivision(division, flagDiv);

    printf("\nMULTIPLICACION (A * B): ");
    printf("El resultado de la multiplicacion es: %g\n", multiplicacion);

    printf("\nFACTORIAL (A!): ");
    informarFactorial(fact1, 'A', flagFact1);

    printf("\nFACTORIAL (B!): ");
    informarFactorial(fact2, 'B', flagFact2);
}

int procesarOperacion(int opcion, double numero1, double numero2, double* suma, double* resta, double* division,
                      double* multiplicacion, unsigned long int* fact1, unsigned long int* fact2,
                      int* flagNum1, int* flagNum2, int* flagDiv, int* flagFact1, int* flagFact2)
{
    int ret = -1;

    if(suma != NULL && resta != NULL && division != NULL && multiplicacion != NULL && fact1 != NULL && fact2 != NULL &&
	   flagNum1 != NULL && flagNum2 != NULL && flagDiv != NULL && flagFact1 != NULL && flagFact2 != NULL)
    {
        switch(opcion)
        {
            case 3:

                if(!sumar(numero1, numero2, suma))
                {
                    printf("\nSUMA (A + B): ");
                    printf("El resultado de la suma es: %g\n", *suma);
                }

                break;

            case 4:

                if(!restar(numero1, numero2, resta))
                {
                    printf("\nRESTA (A - B): ");
                    printf("El resultado de la resta es: %g\n", *resta);
                }

                break;

            case 5:

                if(!dividir(numero1, numero2, division))
                {
                    *flagDiv = 1;
                }

                printf("\nDIVISION (A / B): ");
                informarDivision(*division, *flagDiv);

                break;

            case 6:

                if(!multiplicar(numero1, numero2, multiplicacion))
                {
                    printf("\nMULTIPLICACION (A * B): ");
                    printf("El resultado de la multiplicacion es: %g\n", *multiplicacion);
                }

                break;

            case 9:

                if(!realizarOperaciones(numero1, numero2, suma, resta, division, multiplicacion,
                                        fact1, fact2, flagDiv, flagFact1, flagFact2))
                {
                    printf("\nCalculos realizados correctamente\n");

                    informarResultados(*suma, *resta, *division, *multiplicacion, *fact1, *fact2,
                                       *flagDiv, *flagFact1, *flagFact2);

                    *flagNum1 = 0;
                    *flagNum2 = 0;
                    *flagDiv = 0;
                    *flagFact1 = 0;
                    *flagFact2 = 0;
                }

                else
                {
                    printf("\nNo se pudieron calcular las operaciones\n");
                }

                break;
        }

        ret = 0;
    }

    return ret;
}
