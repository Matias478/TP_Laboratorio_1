#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define TAM 500

//No terminado, tratare de subirlo completo mas adelante. Mil disculpas

int main()
{
    eEmpleado listaEmpleados[TAM];
    int opcion;
    //int i;
    int retorno;
    int valorIdAdd;
    int retornoEliminar;

    valorIdAdd=1;
    do
    {
        printf("\n1.Altas\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

         switch(opcion)
        {
            case 1:
                retorno = addEmployee(listaEmpleados,TAM,valorIdAdd);

                if(retorno!=-1)
                {
                    valorIdAdd++;
                    printf("La carga del empleado ha sido exitosa!!!\n");
                }
                else
                {
                    printf("No hay mas espacio!!!\n");
                }

            break;
            case 2:

            break;
            case 3:
                retornoEliminar=removeEmployees(listaEmpleados,TAM);
                if(retornoEliminar==-1)
                {
                    printf("Se elimino correctamente\n");
                }else
                {
                    printf("No se pudo eliminar el empleado");
                }

            break;
            case 4:
                mostrarEmpleados(listaEmpleados, TAM);

            break;
            case 5:
                printf("\nHasta luego, gracias por usar este programa\n");
            break;
        }

    }while(opcion!=5);

    return 0;
}
