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
        printf("Ingrese\n1. Para ingresar el primer numero\n2. Para ingresar el segundo numero\n3. Para realizar toddas las operaciones\n4. Para mostrar los resultados\n5. Para salir\n");
        printf("Ingrese su opcion:\n ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese un numero: ");
                scanf("%d", &numeroA);
                printf("Numero A = %d\n",numeroA);
            break;
            case 2:
                printf("Ingrese otro numero: ");
                scanf("%d", &numeroB);
                printf("Numero B = %d\n",numeroB);
            break;
            case 3:
                sumar=sumarNumeros(numeroA, numeroB);

                restar=restarNumeros(numeroA, numeroB);

                multiplicar=multiplicarNumeros(numeroA, numeroB);

                dividir=dividirNumeros(numeroA, numeroB);

                factorizar=factorizarNumeroA(numeroA);

                factorizarB=factorizarNumeroB(numeroB);

            break;
            case 4:
                printf("\nLa suma de %d+%d es: %d\n",numeroA, numeroB, sumar);

                printf("\nLa resta de %d-%d es: %d\n",numeroA, numeroB, restar);

                printf("\nLa multiplicacion de %d*%d da: %d\n",numeroA, numeroB, multiplicar);

                if(numeroB==0)
                    {
                        printf("\nNo es posible dividir por 0\n");

                    }else
                    {
                        printf("\nLa division de %d/%d da: %.2f\n",numeroA, numeroB, dividir);
                    }

                printf("\nEl factorial de %d es: %d\n", numeroA, factorizar);
                printf("\nEl factorial de %d es: %d\n", numeroB, factorizarB);

            break;
            case 5:
                printf("Gracias por usar este programa, hasta luego\n");
            break;
        }

    }while(opcion!=5);


    return 0;
}

