#include "Employee.h"

Employee* employee_new()
{
    Employee* pEmpleado;

    pEmpleado = (Employee*)malloc(sizeof(Employee));
    if(pEmpleado!=NULL)
    {
        employee_setId(pEmpleado,0);
        employee_setNombre(pEmpleado,"0");
        employee_setHorasTrabajadas(pEmpleado,0);
        employee_setSueldo(pEmpleado,0);
    }
    return pEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado;

    pEmpleado = employee_new();

    if(pEmpleado!=NULL)
    {
    employee_setId(pEmpleado, atoi(idStr));
    employee_setNombre(pEmpleado, nombreStr);
    employee_setHorasTrabajadas(pEmpleado, atoi(horasTrabajadasStr));
    employee_setSueldo(pEmpleado, atoi(sueldoStr));
    }
    return pEmpleado;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this != NULL && id >0)
    {
        retorno = 1;
        this->id= id;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id !=NULL)
    {
        retorno= 1;
        *id = this->id;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this !=NULL && nombre !=NULL)
    {
        retorno = 1;
        strcpy(this->nombre ,nombre);
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this !=NULL && nombre !=NULL)
    {
        retorno= 1;
        strcpy(this->nombre ,nombre);
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        retorno = 1;
        this->horasTrabajadas=horasTrabajadas;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL && horasTrabajadas!=NULL)
    {
        retorno = 1;
        *horasTrabajadas=this->horasTrabajadas;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;
    if(this != NULL && sueldo > 0)
    {
        retorno = 1;
        this->sueldo= sueldo;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;
    if(this != NULL && sueldo != NULL)
    {
        retorno = 1;
        *sueldo = this->sueldo;
    }
    return retorno;
}

