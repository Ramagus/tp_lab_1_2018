#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"
#include "Input.h"
#include "Menu.h"

int main()
{
    double numero_A;
    double numero_B;
    double suma;
    double resta;
    double division;
    double multiplicacion;
    unsigned long int fact_A;
    unsigned long int fact_B;
    int opcion;
    int flag_A = 0;
    int flag_B = 0;
    int flagDiv = 0;
    int flagFact_A = 0;
    int flagFact_B = 0;
    int flagExit = 0;

    do
    {
        if(!mostrarMenuOpciones(numero_A, numero_B, flag_A, flag_B, &opcion))
        {
            switch(opcion)
            {
                case 1:

                    if(!utn_getNumeroDouble(&numero_A, "\nIngrese el primer numero: ", "Error. Ingrese un numero flotante valido: "))
                    {
                        printf("\nPrimer numero cargado\n");

                        flag_A = 1;
                    }

                    else
                    {
                        printf("\nNo se pudo cargar el primer numero\n");
                    }

                    break;

                case 2:

                    if(!flag_A)
                    {
                        printf("\nError. Debe ingresar el primer numero\n");
                    }

                    else if(!utn_getNumeroDouble(&numero_B, "\nIngrese el segundo numero: ", "Error. Ingrese un numero flotante valido: "))
					{
						printf("\nSegundo numero cargado\n");

						flag_B = 1;
					}

					else
					{
						printf("\nNo se pudo cargar el segundo numero\n");
					}

                    break;

                case 3:
                case 4:
                case 5:
                case 6:
                case 9:

                    if(!flag_A && !flag_B)
                    {
                        printf("\nError. No hay ningun numero cargado\n");
                    }

                    else if(flag_A && !flag_B)
                    {
                        printf("\nError. El segundo numero no esta cargado\n");
                    }

                    else
                    {
                        procesarOperacion(opcion, numero_A, numero_B, &suma, &resta, &division, &multiplicacion,
                                          &fact_A, &fact_B, &flag_A, &flag_B, &flagDiv, &flagFact_A, &flagFact_B);
                    }

                    break;

                case 7:

                    if(!flag_A)
                    {
                        printf("\nError. El primer numero no esta cargado\n");
                    }

                    else
                    {
                        procesarFactorial(numero_A, &fact_A, &flagFact_A);

                        printf("\nFACTORIAL (A!): ");
                        informarFactorial(fact_A, 'A', flagFact_A);
                    }

                    break;

                case 8:

                    if(!flag_B)
                    {
                        printf("\nError. El segundo numero no esta cargado\n");
                    }

                    else
                    {
                        procesarFactorial(numero_B, &fact_B, &flagFact_B);

                        printf("\nFACTORIAL (B!): ");
                        informarFactorial(fact_B, 'B', flagFact_B);
                    }

                    break;

                case 10:

                    if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                    {
                        printf("\nUsted ha salido de la calculadora\n");

                        flagExit = 1;
                    }

                    break;

                default:

                    printf("\nError. Elija una opcion correcta\n");
            }

            printf("\n");
            system("pause");
            system("cls");
        }

        else
        {
            printf("No se pudo mostrar el menu\n");
            break;
        }

    } while(opcion != 10 || !flagExit);

    return 0;
}
