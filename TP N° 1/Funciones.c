#include "Funciones.h"

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

int factorizarNumeroA(int numeroA)
{
    int factorizar;

    if(numeroA== 0)
    {
        factorizar = 1;
    }else
    {
        factorizar= numeroA * factorizarNumeroA(numeroA - 1);
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
        factorizarB= numeroB * factorizarNumeroB(numeroB - 1);
    }
    return factorizarB;
}
