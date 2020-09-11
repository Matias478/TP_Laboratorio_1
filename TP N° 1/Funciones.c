#include "Funciones.h"

float sumarNumeros(float numeroA, float numeroB)
{
    float sumar;
    sumar = numeroA + numeroB;
    return sumar;
}

float restarNumeros(float numeroA, float numeroB)
{
    float restar;
    restar = numeroA - numeroB;
    return restar;
}

float multiplicarNumeros(float numeroA, float numeroB)
{
    float multiplicar;
    multiplicar = numeroA * numeroB;
    return multiplicar;
}

float dividirNumeros(float numeroA, float numeroB)
{
    float dividir;
    dividir = (float)numeroA/numeroB;
    return dividir;
}

int factorizarNumeroA(int numeroA)
{
    int factorizar;

    if(numeroA== 0)
    {
        factorizar = 1;
    }else
    {
        factorizar= (int)numeroA * factorizarNumeroA(numeroA - 1);
    }

    return factorizar;
}

int factorizarNumeroB(int numeroB)
{
    int factorizarB;
    if(numeroB==0)
    {
        factorizarB = 1;
    }else
    {
        factorizarB= (int)numeroB * factorizarNumeroB(numeroB - 1);
    }
    return factorizarB;
}
int menu()
{
    float numeroA;
    float numeroB;
    float sumar;
    float restar;
    float multiplicar;
    float dividir;
    int factorizar;
    int factorizarB;
    int opcion;
    int banderaPrimerNumero;
    int banderaSegundoNumero;

    banderaPrimerNumero=0;
    banderaSegundoNumero=0;

    do
    {
        printf("\nIngrese\n1. Para ingresar el primer numero\n2. Para ingresar el segundo numero\n3. Para realizar todas las operaciones\n4. Para mostrar los resultados\n5. Para salir\n");
        printf("Ingrese su opcion:\n ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer numero: ");
                scanf("%f", &numeroA);
                printf("Numero A = %.2f\n",numeroA);
                banderaPrimerNumero=1;
            break;
            case 2:
                printf("Ingrese segundo numero: ");
                scanf("%f", &numeroB);
                printf("Numero B = %.2f\n",numeroB);
                banderaSegundoNumero=1;
            break;
            case 3:
                if(banderaPrimerNumero==0 && banderaSegundoNumero==1)
                {
                    printf("Error, no ingreso el primer valor");
                    printf("\nIngrese el primer numero: ");
                    scanf("%f", &numeroA);
                    printf("Numero A = %.2f\n",numeroA);
                    banderaPrimerNumero=1;
                }
                else
                {
                    if(banderaPrimerNumero==1 && banderaSegundoNumero==0)
                    {
                        printf("Error, no ingreso el segundo valor");
                        printf("\nIngrese el segundo numero: ");
                        scanf("%f", &numeroB);
                        printf("Numero B = %.2f\n",numeroB);
                        banderaSegundoNumero=1;
                    }
                    if(banderaPrimerNumero==0 && banderaSegundoNumero==0)
                    {
                        printf("Error, no ingreso ningun valor");
                        printf("\nIngrese el primer numero: ");
                        scanf("%f", &numeroA);
                        printf("Numero A = %.2f\n",numeroA);
                        printf("\nIngrese el segundo numero: ");
                        scanf("%f", &numeroB);
                        printf("Numero B = %.2f\n",numeroB);
                        banderaSegundoNumero=1;
                        banderaPrimerNumero=1;
                    }

                    else
                    {
                        sumar=sumarNumeros(numeroA, numeroB);
                        printf("\nSe realizara la suma de (%.2f+%.2f) \n",numeroA, numeroB);

                        restar=restarNumeros(numeroA, numeroB);
                        printf("\nSe realizara la resta de (%.2f-%.2f) \n",numeroA, numeroB);

                        multiplicar=multiplicarNumeros(numeroA, numeroB);
                        printf("\nSe realizara la multiplicacion de (%.2f*%.2f)  \n",numeroA, numeroB);

                        dividir=dividirNumeros(numeroA, numeroB);

                        if(numeroB==0)
                        {
                            printf("\nNo es posible dividir por 0\n");

                        }else
                        {
                            printf("\nSe realizara la division entre (%.2f/%.2f) \n",numeroA, numeroB);
                        }

                        factorizar=factorizarNumeroA(numeroA);
                        printf("\nSe realizara el factorial de (%.2f) \n", numeroA );

                        factorizarB=factorizarNumeroB(numeroB);
                        printf("\nSe realizara el factorial de (%.2f) \n", numeroB );
                    }
                }
            break;
            case 4:
                if(banderaPrimerNumero==1 && banderaSegundoNumero==1)
                {
                printf("\nLa suma de %.2f+%.2f es: %.2f\n",numeroA, numeroB, sumar);

                printf("\nLa resta de %.2f-%.2f es: %.2f\n",numeroA, numeroB, restar);

                printf("\nLa multiplicacion de %.2f*%.2f da: %.2f\n",numeroA, numeroB, multiplicar);

                if(numeroB==0)
                    {
                        printf("\nNo es posible dividir por 0\n");

                    }else
                    {
                        printf("\nLa division de %.2f/%.2f da: %.2f\n",numeroA, numeroB, dividir);
                    }

                printf("\nEl factorial de %.2f, solo tomando su parte entera, es: %d\n", numeroA, factorizar);
                printf("\nEl factorial de %.2f, solo tomando su parte entera, es: %d\n", numeroB, factorizarB);
                }else
                {
                    printf("No se pueden realizar las operaciones porque no ingreso los dos valores");
                    printf("\nIngrese el primer numero: ");
                    scanf("%f", &numeroA);
                    printf("Numero A = %.2f\n",numeroA);
                    printf("\nIngrese el segundo numero: ");
                    scanf("%f", &numeroB);
                    printf("Numero B = %.2f\n",numeroB);
                    banderaSegundoNumero=1;
                    banderaPrimerNumero=1;

                }
            break;
            case 5:
                printf("Gracias por usar este programa, hasta luego\n");
            break;
        }

    }while(opcion!=5);

    return opcion;
}
