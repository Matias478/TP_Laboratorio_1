#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;
    char id[5];
    char nombre[128];
    char horasTrabajadas[10];
    char sueldo[10];
    int retorno=0;
    int cant;
    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,horasTrabajadas,sueldo);
        while(!feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,horasTrabajadas,sueldo);
            if(cant==4)
            {
                auxEmp=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
                ll_add(pArrayListEmployee,auxEmp);
            }
        }
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;
    int retorno=0;
    int cant;
    if(pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            auxEmp=employee_new();
            if(auxEmp!=NULL)
            {
                cant=fread(auxEmp,sizeof(Employee),1,pFile);
                if(cant<1)
                {
                    break;
                }
                ll_add(pArrayListEmployee,auxEmp);
            }
        }
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}

