#include <stdio.h>
#include <stdlib.h>
#define TAM 500

typedef struct
{
    int id;
    char nombre[21];
    char apellido[21];
    float sueldo;
    int sector;
    int isEmpty;

}eEmpleado;

    //void cargarTodosEmpleados(eEmpleado[], int );
    void cargarEmpleado(eEmpleado[], int);
    int buscarLibre(eEmpleado[], int );
    void eliminarEmpleado(eEmpleado[], int);
    void mostrarEmpleados(eEmpleado[], int);

int main()
{
    eEmpleado listaEmpleados[TAM];
    //eEmpleado unEmpleado;
    int opcion;
    int i;

    for(i=0;i<TAM;i++)
    {
        listaEmpleados[i].isEmpty=1;
    }


    do
    {
        //system("cls");
        printf("\n1.Altas\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

         switch(opcion)
        {
            case 1:
                cargarEmpleado(listaEmpleados, TAM);
                //printf("Se ha completado la carga");
            break;
            case 2:

            break;
            case 3:
                eliminarEmpleado(listaEmpleados, TAM);
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

/*void cargarTodosEmpleados(eEmpleado listaEmpleados[], int cant)
{
    int i;
    for(i=0; i<TAM; i++)
    {
       listaEmpleados[i] = cargarEmpleado(eEmpleado[], int);
    }
}*/

void cargarEmpleado(eEmpleado listaEmpleados[], int cant)
{
    eEmpleado unEmpleado;

    int i;
    //int i;

    i = buscarLibre(listaEmpleados,cant);

         if(i!=-1)
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%[^\n]", unEmpleado.nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            scanf("%[^\n]", unEmpleado.apellido);
            printf("Ingrese sueldo: ");
            scanf("%f", &unEmpleado.sueldo);
            printf("Ingrese sector: ");
            scanf("%d", &unEmpleado.sector);

            printf("Se ha completado la carga!!!\n");

            listaEmpleados[i]=unEmpleado;
            for(i=0;i<cant; i++)
            {
                listaEmpleados[i].id++;
                break;
            }
            //listaEmpleados[i].id++;
            listaEmpleados[i].isEmpty=0;

        }else
        {
            printf("No hay mas espacio!!!\n");
        }

}

int buscarLibre(eEmpleado listaEmpleados[], int cant)
{
    int index=-1;
    int i;
    for(i=0; i<cant; i++)
    {
        if(listaEmpleados[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }
    return index;
}

void eliminarEmpleado(eEmpleado listaEmpleados[], int cant)
{
    int id;
    int i;

    printf("Ingrese el id del empleado: ");
    scanf("%d", &id);
    for(i=0;i<cant;i++)
    {
        if(listaEmpleados[i].id==id)
        {
            listaEmpleados[i].isEmpty=1;
            break;
        }
    }
}

void mostrarEmpleados(eEmpleado listaEmpleados[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
             printf("%s %s %.2f %d %d\n", listaEmpleados[i].nombre, listaEmpleados[i].apellido, listaEmpleados[i].sueldo, listaEmpleados[i].sector,
                     listaEmpleados[i].id);
        }
        //printf("%s %s %.2f %d", listaEmpleados[i].nombre, listaEmpleados[i].apellido, listaEmpleados[i].sueldo, listaEmpleados[i].sector);
    }
}

