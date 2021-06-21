#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);


int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

void employee_delete(Employee* this);

int employee_listAnEmployee(Employee* this);

int employee_FindById(LinkedList* pArrayListEmployee, int id);
int ModificarDatoPorId(Employee* miEmpleado);

int BuscarMayorId(LinkedList* pArrayListEmployee,int* pId);

int employee_CompareById(void* e1, void* e2);
int employee_CompareByName(void* e1, void* e2);
int employee_CompareByHT(void* e1, void* e2);
int employee_CompareBySueldo(void* e1, void* e2);
void criterioOrdenamiento(LinkedList* pArrayListEmployee);

void TolowerToupperName(char name[],char* nombres);


#endif // employee_H_INCLUDED
