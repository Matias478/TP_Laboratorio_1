/*
 * ArrayEmployees.c
 *
 *  Created on: 14 may. 2021
 *      Author: MATIAS
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int initEmployees(eEmpleado lista[], int tam)
{
    int retorno=-1;
    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            lista[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
int buscarLibre(eEmpleado lista[], int tam)
{
    int index=-1;
     if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(lista[i].isEmpty)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}
int addEmployee(eEmpleado lista[], int tam, int* pId)
{
    eEmpleado unEmpleado;
    int todoOk=0;
    int indice;
    int auxSector;
    float auxSalary;
    char sector[51];
    char salary[51];

    system("cls");
    printf("      Alta de Empleados     \n");
    printf("\nId:%d \n", *pId);

    if(lista!=NULL && tam>0 && pId!=NULL)
    {
        indice = buscarLibre(lista,tam);

         if(indice !=-1)
        {
            TolowerToupperName(unEmpleado.nombre,"Nombre: ");
            TolowerToupperName(unEmpleado.apellido,"Apellido: ");

           do{
                printf("Ingrese su salario: ");
                fflush(stdin);
                gets(salary);
                auxSalary=validNumber(salary);
            }while(auxSalary==0);
            unEmpleado.sueldo=atof(salary);
            while (unEmpleado.sueldo < 0 )
            {
                printf("Reingrese el salario del empleado: \n");
                scanf("%f",&unEmpleado.sueldo);
            }

           do{
                printf("Ingrese sector(Entre 0 y 999): ");
                fflush(stdin);
                gets(sector);
                auxSector=validNumber(sector);
            }while(auxSector==0);
            unEmpleado.sector=atoi(sector);
            while(unEmpleado.sector<0 || unEmpleado.sector>999)
            {
                printf("Se ingreso un sector incorrecto!!!.Reingrese el sector(Entre 0 y 999): ");
                scanf("%d", &unEmpleado.sector);
            }

            unEmpleado.id=*pId;
            (*pId)++;
            unEmpleado.isEmpty=0;
            lista[indice]=unEmpleado;
            todoOk=1;
        }else
        {
            printf("No hay lugar en el sistema\n");
        }
    }
    return todoOk;//retorna 0 si hay algun error o no hay espacio y 1 si esta todo bien
}

int findEmployeeById(eEmpleado lista[], int tam,int id)
{
    int index=-1;

    for(int i=0; i<tam;i++)
    {
        if(lista[i].id==id && !lista[i].isEmpty)
        {
            index=i;
            break;
        }
    }
    return index;
}

void MostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%10s\t %10s\t %10.2f\t   %5d\t   %5d\n", unEmpleado.nombre
                                ,unEmpleado.apellido
                                ,unEmpleado.sueldo
                                ,unEmpleado.sector
                                ,unEmpleado.id);
}

void MostrarEmpleados(eEmpleado lista[], int tam)
{
    int flag=1;
    printf("*****************Lista de empleados*******************\n");
    printf(" Nombre \t  Apellido  \t  Sueldo\t    Sector  \t  ID\n");

   for(int i=0;i<tam;i++)
    {
        if(!lista[i].isEmpty)
        {
            MostrarEmpleado(lista[i]);
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("\tNo hay empleados que mostrar");
    }
    printf("\n\n");
}

int removeEmployees(eEmpleado lista[] , int tam)
{
    int todoOk=0;
    int id;
    int index;
    char confirma;

    system("cls");
    printf("       Baja de Empleado\n    ");
    MostrarEmpleados(lista,tam);
    printf("\nIngrese ID: ");
    scanf("%d", &id);


    index=findEmployeeById(lista,tam,id);
    if(index==-1)
    {
        printf("No existe un empleado con ese ID. Reingrse ID:\n");
        scanf("%d",&id);
        index=findEmployeeById(lista,tam,id);
    }
    if(index!=-1)
    {
        printf("Empleado a dar de baja: \n");
        MostrarEmpleado(lista[index]);
        printf("\nConfirmar Baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
         if(confirma == 's')
        {
            lista[index].isEmpty=1;
            todoOk=1;
        }else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }
    return todoOk;
}

int ModifyEmployees(eEmpleado lista[],int tam)
{
    int todoOk=0;
    int auxId;
    int index;
    int opcion;
    int auxSector;
    char sector[51];
    float auxSalary;
    char salary[51];
    system("cls");
    printf("       Modificar Empleado      \n");
    MostrarEmpleados(lista,tam);
    printf("Ingrese el ID del empleado: \n");
    scanf("%d", &auxId);

    index=findEmployeeById(lista,tam,auxId);
     if(index==-1)
    {
        printf("No existe un empleado con ese ID. Reingrse ID:\n");
        scanf("%d",&auxId);
        index=findEmployeeById(lista,tam,auxId);
    }
    if(index!=-1)
    {
         for(int i=0;i<tam;i++)
        {
            if(lista[i].id==auxId && lista[i].isEmpty==0)
            {
                do{
                        system("cls");
                        MostrarEmpleado(lista[index]);
                        printf("\nIngrese la opcion modificar: \n");
                        printf("\n1. Modificar el nombre\n");
                        printf("\n2. Modificar el Apellido\n");
                        printf("\n3. Modificar el sueldo\n");
                        printf("\n4. Modificar el sector\n");
                        printf("\n5. Salir de las modificaciones\n");
                        printf("\nOpcion a modificar: ");
                        scanf("%d", &opcion);

                        switch(opcion)
                        {
                            case 1:
                                TolowerToupperName(lista[i].nombre,"Nuevo Nombre: ");
                                system("pause");
                                break;
                            case 2:
                                TolowerToupperName(lista[i].apellido,"Nuevo Apellido: ");
                                system("pause");
                                break;
                            case 3:
                                do{
                                    printf("Ingrese el nuvo salario del empleado: ");
                                    fflush(stdin);
                                    gets(salary);
                                    auxSalary=validNumber(salary);
                                }while(auxSalary==0);
                                lista[i].sueldo=atof(salary);
                                while (lista[i].sueldo < 0 )
                                {
                                    printf("Reingrese el salario del empleado: \n");
                                    scanf("%f",&lista[i].sueldo);
                                }
                                system("pause");
                                break;
                            case 4:
                               do{
                                    printf("Ingrese el nuevo sector del empleado(Entre 0 y 999): ");
                                    fflush(stdin);
                                    gets(sector);
                                    auxSector=validNumber(sector);
                                }while(auxSector==0);
                                lista[i].sector=atoi(sector);
                                while(lista[i].sector<0 || lista[i].sector>999)
                                {
                                    printf("Se ingreso un sector incorrecto!!!.Reingrese el sector(Entre 0 y 999): ");
                                    scanf("%d", &lista[i].sector);
                                }
                                system("pause");
                                break;
                            case 5:
                                //printf("\nFin de las Modificaciones\n");
                                //system("pause");
                                break;
                        }

                }while(opcion!=5);
                 todoOk=1;
            }
        }
    }
    return todoOk;
}

int sortEmployees(eEmpleado lista[],int tam,int order)
{
    eEmpleado auxEmpleado;
    int todoOk=0;
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(order==1)//ascendente
            {
                if(lista[i].sector > lista[j].sector ||
                 (lista[i].sector==lista[j].sector && strcmp(lista[i].apellido,lista[j].apellido)>0))
                {
                    auxEmpleado=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxEmpleado;
                }
            }else if(order==0)//descendente
            {
                if(lista[i].sector < lista[j].sector ||
                 (lista[i].sector==lista[j].sector && strcmp(lista[i].apellido,lista[j].apellido)<0))
                {
                    auxEmpleado=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxEmpleado;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int TotalSalarios(eEmpleado lista[],int tam)
{
    int todoOk=0;
    float auxSalarios;
    float totalSalarios=0;
    float promediosSalarios;
    int contadorPromedios=0;
    int empleadosMayorAlPromedio=0;

    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            empleadosMayorAlPromedio=0;
            auxSalarios=0;
            if(lista[i].isEmpty==0)
            {
                auxSalarios+=lista[i].sueldo;
                contadorPromedios++;
            }
            totalSalarios+=auxSalarios;
            promediosSalarios=totalSalarios/contadorPromedios;
            for(int i=0;i<tam;i++)
            {
                if(lista[i].sueldo>promediosSalarios && lista[i].isEmpty==0)
                {
                    empleadosMayorAlPromedio++;
                }
            }
        }
        todoOk=1;
        printf("\nTotal Sueldos: $%.2f\n", totalSalarios);
        printf("\nEl promedio de los salarios es: %.2f\n", promediosSalarios);
        printf("\nCantidad de empleados que superan el salario promedio: %d\n",empleadosMayorAlPromedio);
    }
    return todoOk;
}

int printEmployees(eEmpleado lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {
        MostrarEmpleados(lista,tam);
        todoOk=1;
    }

    return todoOk;
}

int Informes(eEmpleado lista[],int tam)
{
    int todoOk=0;
    int opcion;
    int order;
    if(lista!=NULL && tam>0)
    {
        do{
            system("cls");
            printf("\n************Informes************\n");
            printf("\n1. Ordenar empleados Alfabeticamente");
            printf("\n2. Total, Promedio de salarios y Cantidad de empleados que superan el promedio");
            printf("\n3. Salir de Informes\n");
            printf("\nIngrese su opcion:");
            scanf("%d", &opcion);
            switch(opcion)
            {
                case 1:
                    printf("\nIngrese 1 si quiere el ordenamiento de forma ascendente o 0 de forma descendente:");
                    scanf("%d", &order);
                    sortEmployees(lista,tam,order);
                    printEmployees(lista,tam);
                    system("pause");
                    break;
                case 2:
                    TotalSalarios(lista,tam);
                    system("pause");
                    break;
                case 3:
                    printf("\nSaliendo de Informes\n");
                    break;
            }
        }while(opcion!=3);
        todoOk=1;
    }
    return todoOk;
}

void ActivarFlag(int* a)
{
    if(*a==0)
    {
        *a= *a+1;
    }
}
void TolowerToupperName(char name[],char* nombres)
{
    char nombre[51];//19
    char buffer[128];
    int len;
    int auxNombre;
    printf("Ingrese su %s ",nombres);
    fflush(stdin);
    gets(buffer);
    auxNombre=validarNombre(buffer);
    while(auxNombre==1)
    {
        printf("Error ingreso un nombre incorrecto.Reingrese su %s ",nombres);
        fflush(stdin);
        gets(buffer);
        auxNombre=validarNombre(buffer);
    }
    strcpy(nombre,buffer);
    strlwr(nombre);
    len = strlen(nombre);
    nombre[0]=toupper(nombre[0]);
    for(int i=0; i<len; i++)
    {
        if(isspace(nombre[i]))
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }
    strcpy(name,nombre);
}

int validNumber(char number[])
{
    for(int i=0; i<strlen(number); i++)
    {
        if(!(isdigit(number[i])))
        {
            printf("\nINGRESA SOLO NUMEROS\n");
            //getchar();
            return 0;
        }
    }

    return 1;
}
int validarNombre(char nombre[])
{
    int i=0;
    int sw=0;
    int j;

    j=strlen(nombre);

    while(i<j && sw==0)
    {
        if(isalpha(nombre[i])!=0)
        {
            i++;
        }
        else{
            sw=1;
        }
    }
    return sw;
}
