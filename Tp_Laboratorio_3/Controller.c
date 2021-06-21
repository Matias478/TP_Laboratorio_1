#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* pArchivo = (FILE*)malloc(sizeof(FILE));
    if(path!=NULL)
    {
        pArchivo=fopen(path,"r");
        if(pArchivo!=NULL)
        {
            retorno=parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        }else{
            printf("Nose pudo abrir el archivo");
        }
    }
    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.bin  (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* pArchivo=(FILE*) malloc(sizeof(FILE));

    if(path!=NULL)
    {
        pArchivo=fopen(path,"rb");
        if(pArchivo!=NULL)
        {
            retorno=parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
            //parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        }else{
            printf("Nose pudo abrir el archivo");
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \param int* pId
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
    int retorno=0;
    Employee* auxEmp=NULL;

    system("cls");
    printf("  ***Alta Empleados***  \n");
    printf("\nId:%d \n", *pId);

    if(pArrayListEmployee!=NULL && pId!=NULL)
    {
        auxEmp=employee_new();
        if(auxEmp!=NULL)
        {
            TolowerToupperName("nombre", auxEmp->nombre);
            fflush(stdin);
            while(!employee_setNombre(auxEmp,auxEmp->nombre))
            {
                TolowerToupperName("Error.Reingrese su nombre", auxEmp->nombre);
            }

            printf("Ingrese las horas trabajadas: ");
            scanf("%d", &auxEmp->horasTrabajadas);
            while(!employee_setHorasTrabajadas(auxEmp,auxEmp->horasTrabajadas))
            {
                 printf("Error.Reingrese las horas trabajadas: ");
                scanf("%d", &auxEmp->horasTrabajadas);
            }

            printf("Ingrese el sueldo: ");
            scanf("%f", &auxEmp->sueldo);
            while(!employee_setSueldo(auxEmp,auxEmp->sueldo))
            {
                printf("Error.Reingrese las horas trabajadas: ");
                scanf("%f", &auxEmp->sueldo);
            }

            auxEmp->id=*pId;
            //(*pId)++;
            ll_add(pArrayListEmployee,auxEmp);
            retorno=1;

        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int auxID;
    int index=-1;
    int opcion;
    Employee* auxEmployee;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("Elije el empleado desea modificar?: ");
        scanf("%d",&auxID);
        index=employee_FindById(pArrayListEmployee,auxID);
        if(index != -1)
        {
            //controller_ListEmployee(pArrayListEmployee);
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,index);
            opcion=ModificarDatoPorId(auxEmployee);
            if(opcion==4)
            {
                printf("modicado con exito");
            }
            else
            {
                printf("No se pudo modificar");
            }
            retorno=1;
        }
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxID;
    int retorno=0;
    char confirma;
    int index;
    Employee* auxEmployee=NULL;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("Que empleado desea eliminar?");
        scanf("%d",&auxID);

        index=employee_FindById(pArrayListEmployee, auxID);
        if(index != -1)
        {
                auxEmployee=(Employee*)ll_get(pArrayListEmployee,index);
                printf("Empleado a dar de baja: \n");
                employee_listAnEmployee(auxEmployee);
        }

        printf("\nConfirmar Baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            ll_remove(pArrayListEmployee,index);
            //ll_pop(pArrayListEmployee,index);
            retorno=1;
        }
        printf("EMPLEADO ELIMINADO!!!\n");

    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* auxEmp=NULL;
    if(pArrayListEmployee!=NULL)
    {
        printf("ID\t   Nombre   Horas Trabajadas\t   Sueldo\n");
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
            employee_listAnEmployee(auxEmp);
        }
        printf("\n\n");
        retorno=1;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    criterioOrdenamiento(pArrayListEmployee);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmp;
    int len;
    int retorno=0;
    int id;
    char name[128];
    int hours;
    float salary;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {

            fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
            len=ll_len(pArrayListEmployee);

            for(int i=0; i<len; i++)
            {
                auxEmp=(Employee*)ll_get(pArrayListEmployee, i);
                if(employee_getId(auxEmp,&id)==1 &&
                   employee_getNombre(auxEmp,name)==1 &&
                   employee_getHorasTrabajadas(auxEmp,&hours)==1 &&
                   employee_getSueldo(auxEmp,&salary)==1)
                {
                    fprintf(pFile, " %d, %s, %d, %.2f\n",id,name,hours,salary);
                }
            }
        }
        fclose(pFile);
        retorno=1;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* auxEmp;
    int retorno=-1;
    int len;
    len=ll_len(pArrayListEmployee);
    if(path!=NULL&& pArrayListEmployee!=NULL&&ll_isEmpty(pArrayListEmployee)==0)
    {
        pArchivo=fopen(path,"wb");
        if(pArchivo!=NULL)
        {
             for(int i=0;i<len;i++)
            {
                auxEmp=(Employee*) ll_get(pArrayListEmployee,i);
                fwrite(auxEmp,sizeof(Employee),1,pArchivo);
            }
        }
        fclose(pArchivo);
        retorno=1;
    }

    return retorno;
}

