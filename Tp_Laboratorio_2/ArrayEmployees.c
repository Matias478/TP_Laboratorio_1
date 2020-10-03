#include "ArrayEmployees.h"




int initEmployees(eEmpleado listaEmpleados[], int cant)
{
    int i;
    int retorno=-1;

    for(i=0;i<cant;i++)    //   inicializar empleados
    {
        listaEmpleados[i].isEmpty=0;
        retorno=0;
    }
    return retorno;
}

int addEmployee(eEmpleado listaEmpleados[], int cant, int id)
{
        eEmpleado unEmpleado;

    int i;

    i = buscarLibre(listaEmpleados,cant);

         if(i!=-1)
        {
            listaEmpleados[i].id=idGenerado(0,id);
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

            listaEmpleados[i]=unEmpleado;

            listaEmpleados[i].isEmpty=1;
        }

    return 1;
}

int removeEmployees(eEmpleado listaEmpleados[] , int cant)
{
    int i;
    int retorno;
    int id;
    int control;
    retorno=0;

    mostrarEmpleados(listaEmpleados, cant);

    printf("Ingrese el id del empleado a remover: ");
    scanf("%d", &id);

    control=findEmployeeById(listaEmpleados, cant, id);
    if(control==1)
    {
        for(i=0;i<cant;i++)
        {
            if(listaEmpleados[i].id=id)
            {
                listaEmpleados[i].isEmpty=0;
                retorno=-1;
            }
        }
    }
    return retorno;
}

int buscarLibre(eEmpleado listaEmpleados[], int cant)
{
    int index=-1;
    int i;
    for(i=0; i<cant; i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
            index=i;
            break;
        }
    }
    return index;
}

int findEmployeeById(eEmpleado listaEmpleados[], int cant,int id)
{
    int index;
    int i;

    for(i=0; i<cant;i++)
    {
        if(listaEmpleados[i].id==id && listaEmpleados[i].isEmpty==-1)
        {
            index=1;
            break;
        }
    }
    return index;
}

void mostrarEmpleados(eEmpleado listaEmpleados[], int cant)
{
    int i;

    for(i=0;i<cant;i++)
    {
        if(listaEmpleados[i].isEmpty==1)
        {
            printf("%s %s %.2f %d %d\n", listaEmpleados[i].nombre, listaEmpleados[i].apellido, listaEmpleados[i].sueldo,
                    listaEmpleados[i].sector,
                    listaEmpleados[i].id);
        }
    }
}

int idGenerado(int cant,int id)
{
    int idGenerado;
    idGenerado=cant+id;
    return idGenerado;
}

