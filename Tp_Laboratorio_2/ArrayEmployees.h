#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[21];
    char apellido[21];
    float sueldo;
    int sector;
    int isEmpty;
}eEmpleado;



int initEmployees(eEmpleado[], int cant);

int idGenerado(int cant,int id);

int addEmployee(eEmpleado[], int cant, int id);

int buscarLibre(eEmpleado[], int );

int findEmployeeById(eEmpleado[], int cant,int id);

int removeEmployees(eEmpleado[] , int cant);

//int sortEmployees(Employee* list, int len, int order)    //falta modificar los parametros

void printEmployees(eEmpleado[], int cant);

void mostrarEmpleados(eEmpleado listaEmpleados[], int cant);







