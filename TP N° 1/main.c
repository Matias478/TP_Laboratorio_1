#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    int numeroA;
    int numeroB;
    int sumar;
    int restar;
    int multiplicar;
    float dividir;
    int factorizar;
    int factorizarB;
    char operacionRealizada;
    int opcion;

    do
    {
        printf("ingrese\n1. Para ingresar el primer numero\n2. Para ingresar el segundo\n3. Para elegir las operaciones\n4. Para mostrar los resultados\n5. Para salir\n");
        printf("Ingrese su opcion:\n ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("ingrese un numero: ");
                scanf("%d", &numeroA);
            break;
            case 2:
                printf("ingrese otro numero: ");
                scanf("%d", &numeroB);
            break;
            case 3:
                printf("ingrese s(sumar), r(resta), m(multiplicacion), d(division), f(factorizar) : ");
                fflush(stdin);
                scanf("%c", &operacionRealizada);

                while(operacionRealizada!='s' && operacionRealizada!='r' && operacionRealizada!='m' && operacionRealizada!='d' && operacionRealizada!='f')
                {
                    printf("error, reingrese s(sumar), r(resta), m(multiplicacion), d(division), f(factorizar) : ");
                    fflush(stdin);
                    scanf("%c", &operacionRealizada);
                }
            break;
            case 4:
                if(operacionRealizada=='s')
                {
                    sumar=sumarNumeros(numeroA, numeroB);
                    printf("La suma de los numeros es: %d\n", sumar);
                }

                if(operacionRealizada=='r')
                {
                    restar=restarNumeros(numeroA, numeroB);
                    printf("La resta de los numeros es: %d\n", restar);
                }

                if(operacionRealizada=='m')
                {
                    multiplicar=multiplicarNumeros(numeroA, numeroB);
                    printf("La multiplicacion de los numeros da: %d\n", multiplicar);
                }

                if(operacionRealizada=='d')
                {
                    if(numeroB==0)
                    {
                        printf("No es posible dividir por 0\n");

                    }else
                    {
                        dividir=dividirNumeros(numeroA, numeroB);
                        printf("La division de los numeros da: %.2f\n", dividir);
                    }
                }

                if(operacionRealizada=='f')
                {
                    factorizar=factorizarNumeroA(numeroA);
                    printf("El factorial de %d es: %d\n", numeroA, factorizar);
                    factorizarB=factorizarNumeroB(numeroB);
                    printf("El factorial de %d es: %d\n", numeroB, factorizarB);
                }
            break;
            case 5:
                printf("Gracias por usar este programa, hasta luego\n");
            break;

        }


    }while(opcion!=5);


    return 0;
}

