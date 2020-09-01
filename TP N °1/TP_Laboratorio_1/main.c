#include <stdio.h>
#include <stdlib.h>

int sumarNumeros(int, int);
int restarNumeros(int, int);
int multiplicarNumeros(int, int);
float dividirNumeros(int, int);
int factorizarNumeros(int );
int main()
{
    int numeroA;
    int numeroB;
    int sumar;
    int restar;
    int multiplicar;
    float dividir;
    int factorizar;
    char operacionRealizada;

    printf("ingrese s(sumar), r(resta), m(multiplicacion), d(division): ");
    fflush(stdin);
    scanf("%c", &operacionRealizada);

    while(operacionRealizada!='s' && operacionRealizada!='r' && operacionRealizada!='m' && operacionRealizada!='d' && operacionRealizada!='f')
    {
        printf("error, reingrese s(sumar), r(resta), m(multiplicacion), d(division), f(factorizar) : ");
        fflush(stdin);
        scanf("%c", &operacionRealizada);
    }

    printf("ingrese un numero: ");
    scanf("%d", &numeroA);
    printf("ingrese otro numero: ");
    scanf("%d", &numeroB);

    if(operacionRealizada=='s')
    {
        sumar=sumarNumeros(numeroA, numeroB);
        printf("la suma de los numeros es: %d\n", sumar);
    }

    if(operacionRealizada=='r')
    {
        restar=restarNumeros(numeroA, numeroB);
        printf("la resta de los numeros es: %d\n", restar);
    }

    if(operacionRealizada=='m')
    {
        multiplicar=multiplicarNumeros(numeroA, numeroB);
        printf("la multiplicacion de los numeros da: %d\n", multiplicar);
    }

    if(operacionRealizada=='d')
    {
        dividir=dividirNumeros(numeroA, numeroB);
        printf("la division de los numeros da: %.2f\n", dividir);
    }

    return 0;
}
int sumarNumeros(int numeroA, int numeroB)
{
    int sumar;
    sumar = numeroA + numeroB;
    return sumar;
}
int restarNumeros(int numeroA, int numeroB)
{
    int restar;
    restar = numeroA - numeroB;
    return restar;
}
int multiplicarNumeros(int numeroA, int numeroB)
{
    int multiplicar;
    multiplicar = numeroA * numeroB;
    return multiplicar;
}
float dividirNumeros(int numeroA, int numeroB)
{
    float dividir;
    dividir = (float)numeroA/numeroB;
    return dividir;
}
/*int factorizarNumeros(int numeroA, int numeroB)
{
    int factorizar;
                                                          falta completar !!!
    return factorizar;
}*/
